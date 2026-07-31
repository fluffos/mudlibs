// SN:RiKOjW_YMFi0D^d8
// File(/data/room/cper/key.c) of cper's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "段笑笑家的钥匙" NOR, ({ "key", "2 of cper" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启笑笑居(xiaoju)的钥匙。
这是段笑笑第二次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
