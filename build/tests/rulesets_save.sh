#!/bin/bash

# rulesets_save.sh [ruleset]...
# Exits with 0 when each specified ruleset or, if no rulesets are specified,
# each ruleset that is developed with Freeciv, can be saved using ruleup.
# Exits with 1 if not.
# If KEEP_RESULT_IN_DIR is set to a folder the saved result will be kept
# there for later inspection even if nothing fails.

if test "$1" = "" ; then
  # Try to save all rulesets that are developed with Freeciv
  rulesets="$(cat /home/pring/freeciv-web/freeciv/freeciv/build/../tests/rs_test_res/ruleset_list_dist.txt)"
  optional="$(cat /home/pring/freeciv-web/freeciv/freeciv/build/../tests/rs_test_res/ruleset_list_opt.txt)"
  for opt in $optional ; do
    if test -d "/home/pring/freeciv-web/freeciv/freeciv/build/../data/$opt" ; then
      rulesets="$rulesets $opt"
    fi
  done
else
  # Try to save the specified ruleset(s)
  rulesets=$@
fi

if test "$KEEP_RESULT_IN_DIR" = "" ; then
  # Put upgrade results in a temporary folder.
  tmpdir=`mktemp -d`
else
  # Save the upgrade result to the specified folder
  tmpdir=$KEEP_RESULT_IN_DIR
fi

if [ -d "${tmpdir}" ] ; then
  cp -R /home/pring/freeciv-web/freeciv/freeciv/build/../data/ruledit/ "${tmpdir}" || exit 1
  cp -R /home/pring/freeciv-web/freeciv/freeciv/build/../data/default/ "${tmpdir}" || exit 1
else
  echo "Unable to create folder for temporary files: \"${tmpdir}\""
  exit 1
fi

for ruleset in $rulesets; do
  resaved="rs_${ruleset}_resaved"
  resaved_path="${tmpdir}/${resaved}"
  reresaved="resaved_rs_${ruleset}"
  reresaved_path="${tmpdir}/${reresaved}"

  echo "Loading $ruleset and saving it as $resaved"
  /home/pring/freeciv-web/freeciv/freeciv/build/fcruleup -F -c -r $ruleset \
      --output "$resaved_path" \
    || exit 1

  echo "Trying to load $ruleset saved as $resaved"
  FREECIV_DATA_PATH=$tmpdir \
      /home/pring/freeciv-web/freeciv/freeciv/build/tests/rs_test_res/ruleset_loads.sh "$resaved" \
    || exit 1

  echo "Checking ruleset saving stability for $ruleset"

  echo "Resaving resaved $ruleset"
  FREECIV_DATA_PATH=$tmpdir /home/pring/freeciv-web/freeciv/freeciv/build/fcruleup -F -c -r "$resaved" \
      --output "$reresaved_path" \
    || exit 1
  if [ ! -d "$reresaved_path" ] ; then
    echo "Missing $reresaved_path means that resaving must have failed."
    exit 1
  fi
  result="`diff -u \"${resaved_path}\" \"${reresaved_path}\"`"
  if test "x$result" != "x" ; then
    echo "$result"
    echo "Unstable ruleset saving."
    exit 1
  fi
done

if test "$KEEP_RESULT_IN_DIR" = "" ; then
  # Should not be kept
  rm -rf "${tmpdir}"
fi

echo "No resaving problems detected."

exit 0
