// SN:8SCAU:W14BPQ4TP]
// File(/data/room/yangs/key.c) of yangs's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "胡挖泥家的钥匙" NOR, ({ "key", "1 of yangs" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启小杨居(xyj)的钥匙。
这是原配钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
