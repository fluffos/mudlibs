// SN:Em5;a?A`9h0co>@W
// File(/data/room/vivian/key.c) of vivian's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "北天舞家的钥匙" NOR, ({ "key", "3 of vivian" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启听涛小筑(palace)的钥匙。
这是北天舞第三次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
