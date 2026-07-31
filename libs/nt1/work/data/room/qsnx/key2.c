// SN:P_CIkB7Jic3g9CVZ
// File(/data/room/qsnx/key.c) of qsnx's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "胡老头家的钥匙" NOR, ({ "key", "2 of qsnx" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启老年俱乐部(ltj)的钥匙。
这是胡老头第二次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
