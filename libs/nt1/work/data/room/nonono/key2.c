// SN:]cLRi1fmIWO=o>R9
// File(/data/room/nonono/key.c) of nonono's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "罪不至死家的钥匙" NOR, ({ "key", "2 of nonono" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启天之亭(nonono)的钥匙。
这是澄罪第二次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
