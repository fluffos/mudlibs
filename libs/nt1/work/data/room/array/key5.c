// SN:k`<JWmHi_lnYJPHC
// File(/data/room/array/key.c) of array's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "艾汀家的钥匙" NOR, ({ "key", "5 of array" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启天龙阵(array)的钥匙。
这是艾汀第五次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
