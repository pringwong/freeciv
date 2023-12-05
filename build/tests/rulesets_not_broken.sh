#!/bin/bash

# rulesets_not_broken.sh [ruleset]...
# Exits with 0 when each specified ruleset or, if no rulesets are specified,
# each ruleset that is developed with Freeciv, are able to load. Exits with
# 1 if any ruleset fails to load.

if test "$1" = "" ; then
  # Try to load all rulesets that are developed with Freeciv
  rulesets="$(cat /home/pring/freeciv-web/freeciv/freeciv/build/../tests/rs_test_res/ruleset_list_dist.txt)"
  optional="$(cat /home/pring/freeciv-web/freeciv/freeciv/build/../tests/rs_test_res/ruleset_list_opt.txt)"
  for opt in $optional ; do
    if test -d "/home/pring/freeciv-web/freeciv/freeciv/build/../data/$opt" ; then
      rulesets="$rulesets $opt"
    fi
  done
else
  # Try to load the specified ruleset(s)
  rulesets=$@
fi

for ruleset in $rulesets; do
  echo "Loading $ruleset"
  /home/pring/freeciv-web/freeciv/freeciv/build/tests/rs_test_res/ruleset_loads.sh $ruleset || exit 1
done

echo "No broken rulesets detected."

exit 0
