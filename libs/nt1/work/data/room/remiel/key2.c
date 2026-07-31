// SN:G?cYfj3_mLl[hUSG
// File(/data/room/remiel/key.c) of remiel's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "雷米尔家的钥匙" NOR, ({ "key", "2 of remiel" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启天使禁猎区(angelcage)的钥匙。
这是雷米尔第二次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
