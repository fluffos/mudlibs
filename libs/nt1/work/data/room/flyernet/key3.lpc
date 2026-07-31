// SN:Ui]5Jj`5K2b:4Fg<
// File(/data/room/flyernet/key.c) of flyernet's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "大侠家的钥匙" NOR, ({ "key", "3 of flyernet" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启桃花源(dragon)的钥匙。
这是大侠第三次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
