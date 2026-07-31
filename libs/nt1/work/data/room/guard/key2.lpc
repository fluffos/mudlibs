// SN:C2BiBBQ1j4;:a2G_
// File(/data/room/guard/key.c) of guard's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "慕容卫家的钥匙" NOR, ({ "key", "2 of guard" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启护卫室(hws)的钥匙。
这是慕容卫第二次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
