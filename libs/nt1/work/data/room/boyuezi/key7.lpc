// SN:8;k_2fm2Y5FVWLYF
// File(/data/room/boyuezi/key.c) of boyuezi's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "伯约家的钥匙" NOR, ({ "key", "7 of boyuezi" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启蓬莱仙山(plge)的钥匙。
这是伯约第七次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
