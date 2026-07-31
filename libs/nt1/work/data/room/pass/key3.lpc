// SN:VB[X<3o06V?VTM8M
// File(/data/room/pass/key.c) of pass's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "大白鲨家的钥匙" NOR, ({ "key", "3 of pass" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启海阔天空(pass)的钥匙。
这是大白鲨第三次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
