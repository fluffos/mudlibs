// /std/equip/clothing.c
// Basic clothing object
//
// Created:     2024/03/02: Gesslar
// Last Change: 2024/03/02: Gesslar
//
// 2024/03/02: Gesslar - Created

#include <armour.h>

inherit STD_EQUIP;

void set_id(mixed ids) {
  ::set_id(ids);

  if(!function_exists("is_armour"))
    add_id(({ "clothing" }));
}

int is_clothing() { return 1; }
