#!/bin/bash

# Freeciv - Copyright (C) 2022 - The Freeciv Team
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2, or (at your option)
#  any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.

FCVER=$(../../fc_version)

# On a git clone, regenerate configure with autogen.sh
if test -f ../../.git && test -x ../../autogen.sh ; then
  if ! ( cd ../.. && ./autogen.sh --no-configure-run ) ; then
    echo "Autogen.sh FAILED" >&2
    exit 1
  fi
fi

if ! flatpak-builder --user --repo=repo --force-clean build org.freeciv.gtk4.yml ||
   ! flatpak-builder --user --repo=repo --force-clean build org.freeciv.gtk322.yml ||
   ! flatpak-builder --user --repo=repo --force-clean build org.freeciv.mp.gtk4.yml ||
   ! flatpak-builder --user --repo=repo --force-clean build org.freeciv.mp.gtk3.yml ||
   ! flatpak-builder --user --repo=repo --force-clean build org.freeciv.qt.yml ||
   ! flatpak-builder --user --repo=repo --force-clean build org.freeciv.sdl2.yml ||
   ! flatpak-builder --user --repo=repo --force-clean build org.freeciv.ruledit.yml ||
   ! flatpak build-update-repo repo ||
   ! flatpak build-bundle repo "freeciv-gtk4-${FCVER}.flatpak" org.freeciv.gtk4 ||
   ! flatpak build-bundle repo "freeciv-gtk3.22-${FCVER}.flatpak" org.freeciv.gtk322 ||
   ! flatpak build-bundle repo "freeciv-mp-gtk4-${FCVER}.flatpak" org.freeciv.mp.gtk4 ||
   ! flatpak build-bundle repo "freeciv-mp-gtk3-${FCVER}.flatpak" org.freeciv.mp.gtk3 ||
   ! flatpak build-bundle repo "freeciv-qt-${FCVER}.flatpak" org.freeciv.qt ||
   ! flatpak build-bundle repo "freeciv-sdl2-${FCVER}.flatpak" org.freeciv.sdl2 ||
   ! flatpak build-bundle repo "freeciv-ruledit-${FCVER}.flatpak" org.freeciv.ruledit
then
  echo "FAILURE" >&2
  exit 1
fi
