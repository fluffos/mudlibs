// SN:=E4d2R[=WDAPY13o
// File(/data/room/gold/key.c) of gold's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "蓝魔家的钥匙" NOR, ({ "key", "3 of gold" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启黄金岛(gold)的钥匙。
这是摇头丸第三次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
