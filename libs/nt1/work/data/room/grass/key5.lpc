// SN:BZdR;dP^Nh4g9bAj
// File(/data/room/grass/key.c) of grass's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "小草家的钥匙" NOR, ({ "key", "5 of grass" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启草堂(grass)的钥匙。
这是小草第五次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
