// SN:H]X[Tmnk5El3o`Ke
// File(/data/room/depravity/key.c) of depravity's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "堕落天使家的钥匙" NOR, ({ "key", "2 of depravity" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启禁入魔界(devil)的钥匙。
这是堕落天使第二次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
