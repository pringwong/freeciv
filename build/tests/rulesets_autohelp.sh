#!/bin/bash

# rulesets_autohelp.sh [ruleset]...
# Exits with 0 when each specified ruleset or, if no rulesets are specified,
# each ruleset that is developed with Freeciv, are able to automatically
# generate help texts. Exits with 1 if autohelp fails for any ruleset.

if test "$1" = "" ; then
  # Try to load all rulesets that are developed with Freeciv
  rulesets="$(cat /home/pring/13v/freeciv-web/freeciv/freeciv/build/../tests/rs_test_res/ruleset_list_dist.txt)"
  optional="$(cat /home/pring/13v/freeciv-web/freeciv/freeciv/build/../tests/rs_test_res/ruleset_list_opt.txt)"
  for opt in $optional ; do
    if test -d "/home/pring/13v/freeciv-web/freeciv/freeciv/build/../data/$opt" ; then
      rulesets="$rulesets $opt"
    fi
  done
else
  # Try to load the specified ruleset(s)
  rulesets=$@
fi

if test "$FREECIV_DATA_PATH" = "" ; then
  FREECIV_DATA_PATH=".:data"
fi
FREECIV_DATA_PATH="${FREECIV_DATA_PATH}:/home/pring/13v/freeciv-web/freeciv/freeciv/build/data:/home/pring/13v/freeciv-web/freeciv/freeciv/build/../data"
export FREECIV_DATA_PATH

for ruleset in $rulesets; do
  echo "Loading $ruleset"
  /home/pring/13v/freeciv-web/freeciv/freeciv/build/tools/freeciv-manual -r $ruleset || exit 1
done

echo "The automatic help text generation works for all tested rulesets."

exit 0
