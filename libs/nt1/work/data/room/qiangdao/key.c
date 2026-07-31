// SN:?Fi8mJ7@Hd^Mg_7Y
// File(/data/room/qiangdao/key.c) of qiangdao's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "强盗家的钥匙" NOR, ({ "key", "1 of qiangdao" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启强盗团(qiangdao)的钥匙。
这是原配钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
