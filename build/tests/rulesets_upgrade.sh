#!/bin/bash

# rulesets_upgrade.sh
# Exits with 0 when each ruleset specified in upgrade_ruleset_list.txt can
# be saved using ruleup.
# Exits with 1 if not.
# If KEEP_RESULT_IN_DIR is set to a folder the saved result will be kept
# there for later inspection even if nothing fails.

FREECIV_DATA_PATH="/home/pring/freeciv-web/freeciv/freeciv/build/../tests/rs_test_res/upgrade_rulesets:$FREECIV_DATA_PATH" \
 ./tests/rulesets_save.sh `cat /home/pring/freeciv-web/freeciv/freeciv/build/../tests/rs_test_res/upgrade_ruleset_list.txt`
