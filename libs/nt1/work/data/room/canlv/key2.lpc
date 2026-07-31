// SN:H_VB>lc91=2H;X2^
// File(/data/room/canlv/key.c) of canlv's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "残旅家的钥匙" NOR, ({ "key", "2 of canlv" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启无魂居(canlv)的钥匙。
这是残旅第二次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
