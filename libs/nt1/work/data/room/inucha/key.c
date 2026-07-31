// SN:M4:D22lJ770@>7i\
// File(/data/room/inucha/key.c) of inucha's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "犬夜叉家的钥匙" NOR, ({ "key", "1 of inucha" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启犬夜叉(inucha)的钥匙。
这是原配钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
