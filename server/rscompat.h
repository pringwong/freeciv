/***********************************************************************
 Freeciv - Copyright (C) 1996 - A Kjeldberg, L Gregersen, P Unold
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
***********************************************************************/
#ifndef FC__RSCOMPAT_H
#define FC__RSCOMPAT_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* utility */
#include "support.h"

/* server */
#include "ruleset.h"

#define RULESET_COMPAT_CAP "+Freeciv-ruleset-3.1-Devel-2021.May.03"

struct rscompat_info
{
  bool compat_mode;
  rs_conversion_logger log_cb;
  int ver_buildings;
  int ver_cities;
  int ver_effects;
  int ver_game;
  int ver_governments;
  int ver_nations;
  int ver_styles;
  int ver_techs;
  int ver_terrain;
  int ver_units;
};

void rscompat_init_info(struct rscompat_info *info);

int rscompat_check_capabilities(struct section_file *file, const char *filename,
                                struct rscompat_info *info);

bool rscompat_names(struct rscompat_info *info);

void rscompat_postprocess(struct rscompat_info *info);

/* General upgrade functions that should be kept to avoid regressions in
 * corner case handling. */
void rscompat_enablers_add_obligatory_hard_reqs(void);

/* Functions from ruleset.c made visible to rscompat.c */
struct requirement_vector *lookup_req_list(struct section_file *file,
                                           struct rscompat_info *compat,
                                           const char *sec,
                                           const char *sub,
                                           const char *rfor);

/* Functions specific to 3.1 -> 3.2 transition */
enum impr_genus_id rscompat_genus_3_2(struct rscompat_info *compat,
                                      const bv_impr_flags flags,
                                      enum impr_genus_id old_genus);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif  /* FC__RSCOMPAT_H */
