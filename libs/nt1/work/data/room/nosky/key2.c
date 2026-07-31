// SN:9J0>2>h`?HSKH;3a
// File(/data/room/nosky/key.c) of nosky's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "笑红尘家的钥匙" NOR, ({ "key", "2 of nosky" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启逍遥宫(nosky)的钥匙。
这是笑红尘第二次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
