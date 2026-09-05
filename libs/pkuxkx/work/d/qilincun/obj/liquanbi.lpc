// Created by iszt@pkuxkx, 2007-02-12

#include <weapon.h>
#include <ansi.h>
#include "liquan.h"

inherit DAGGER;

void create()
{
	set_name(HIR "沥泉神匕" NOR, ({ "liquan bi", "bi" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", HIW"此匕乃是沥泉中大蛇所化。沥泉原是神物，这匕自也是非比凡间兵器。\n"NOR);
		set("value", 200000);
		set("material", "steel");
		set("rigidity",400);
		set("wield_msg", HIY"$N暗运内力一把将$n"+HIY"紧紧的握在手中，顿时周身弥漫着一股豪气！\n"NOR);
		set("unwield_msg", HIY"$N一反手，将$n"+HIY"背在身后。\n"NOR);
		set("no_store", 1);
		set("no_sell", 1);
		set("no_pawn", 1);
	}
	init_dagger(200+random(50));
	setup();
}
