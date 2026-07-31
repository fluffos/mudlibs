//Cracked by Roath
// jingu.c 紧箍咒

#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name(HIR"紧箍咒"NOR, ({ "jingu zhou" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "篇");
        set("long",
        "紧箍咒，又唤做“定心真言”。撞见神通广大的妖魔，只依所用的咒语念一念，管教他入我门来。\n");
        set("material", "paper");       
        }
	setup();
}

