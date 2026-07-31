// SN:bD7l9MKmMV1ik^=g
// File(/data/room/fante/key.c) of fante's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "飞云家的钥匙" NOR, ({ "key", "2 of fante" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启飞云堡(fante)的钥匙。
这是飞云第二次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
