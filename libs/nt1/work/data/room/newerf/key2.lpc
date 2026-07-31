// SN:AP_kKiKJck4GJMXB
// File(/data/room/newerf/key.c) of newerf's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "丹玉磨家的钥匙" NOR, ({ "key", "2 of newerf" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启丹玉磨(newerf)的钥匙。
这是丹玉磨第二次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
