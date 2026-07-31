// SN:]L7Q@iV1A_11Xl=L
// File(/data/room/moppet/key.c) of moppet's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "琉璃娃娃家的钥匙" NOR, ({ "key", "2 of moppet" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启烟竹小筑(moppet)的钥匙。
这是琉璃娃娃第二次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
