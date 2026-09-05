// std_armor.c 藏经阁标准装备
// by seagate@pkuxkx 2012.03.14

#include <ansi.h>
#include <armor.h>
inherit F_GEMS;
inherit EQUIP;
#include "cjg_armor.h"

void create()
{
	set_name("藏经阁装备",({"armor"}));
  set("value", 20000);
  set("material", "steel");
  set("rigidity", 300);
  set("max_rigidity", 300);
  set("forge/times_max",1);
  set("generation", 2);
  set("is_armor", 1);
  if ( query("cjg_armor") )
  	set_cjg_armor(query("cjg_armor"));
}