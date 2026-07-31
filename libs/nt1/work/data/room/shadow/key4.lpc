// SN:kU8jjCIaHUcOfHYo
// File(/data/room/shadow/key.c) of shadow's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "影子无敌家的钥匙" NOR, ({ "key", "4 of shadow" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启神影之穴(lightroom)的钥匙。
这是影子无敌第四次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
