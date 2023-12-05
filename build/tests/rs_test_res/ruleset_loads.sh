#!/bin/bash

# ruleset_loads.sh ruleset
# Exits with 0 when the specified ruleset is able to load. Exits with 1 if
# it fails to load.

(echo "lua unsafe-file /home/pring/freeciv-web/freeciv/freeciv/build/../tests/rs_test_res/ruleset_is.lua" \
 | (EXPECTED_RULESET=$1 /home/pring/freeciv-web/freeciv/freeciv/build/fcser \
      -F --Announce none --ruleset $1)) \
|| exit 1

# The ruleset was able to load.
exit 0
