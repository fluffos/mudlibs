// SN:WH2?:gk_Ti5n^B7>
// File(/data/room/iaojian/key.c) of iaojian's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "药剑家的钥匙" NOR, ({ "key", "2 of iaojian" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启药府(iaofu)的钥匙。
这是药剑第二次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
