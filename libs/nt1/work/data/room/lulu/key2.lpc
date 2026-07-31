// SN:^Eb;7^a9kB97O4oO
// File(/data/room/lulu/key.c) of lulu's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "唐绣家的钥匙" NOR, ({ "key", "2 of lulu" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启神剑山庄(lulu)的钥匙。
这是唐绣第二次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
