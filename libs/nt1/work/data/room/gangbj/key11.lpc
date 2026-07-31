// SN:2j3bW^Hc[jRlHGD3
// File(/data/room/gangbj/key.c) of gangbj's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "唐三藏家的钥匙" NOR, ({ "key", "11 of gangbj" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启三藏的庙(gangbj)的钥匙。
这是唐三藏第十一次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
