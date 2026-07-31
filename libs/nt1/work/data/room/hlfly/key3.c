// SN:@09ES4fBJi5NY;cH
// File(/data/room/hlfly/key.c) of hlfly's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "胡乱飞家的钥匙" NOR, ({ "key", "3 of hlfly" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启胡乱居(hlfly)的钥匙。
这是胡乱飞第三次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
