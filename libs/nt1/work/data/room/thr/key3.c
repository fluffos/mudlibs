// SN:>nBf1KRNO?A`J8ci
// File(/data/room/thr/key.c) of thr's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "阿二家的钥匙" NOR, ({ "key", "3 of thr" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启二班(erban)的钥匙。
这是阿二第三次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
