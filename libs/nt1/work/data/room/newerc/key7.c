// SN:T;b^P4TZU\8hYHA6
// File(/data/room/newerc/key.c) of newerc's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "小乞丐家的钥匙" NOR, ({ "key", "7 of newerc" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启小乞丐(newerc)的钥匙。
这是空小第七次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
