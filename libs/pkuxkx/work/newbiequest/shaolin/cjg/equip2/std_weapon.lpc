// std_weapon.c 藏经阁标准武器
// by seagate@pkuxkx 2012.03.14

#include <ansi.h>
#include <weapon.h>
inherit F_GEMS;
inherit EQUIP;
#include "cjg_weapon.h"

void create()
{
	set_name("藏经阁武器",({"weapon"}));
  set("value", 20000);
  set("material", "steel");
  set("rigidity", 300);
  set("max_rigidity", 300);
  set("forge/times_max",1);
  set("generation", 2);
  set("is_weapon", 1);
  if ( query("cjg_weapon") )
  	set_cjg_weapon(query("cjg_weapon"));
}