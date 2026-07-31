// SN:O?3D1V5bk]mTA9cS
// File(/data/room/eee/key.c) of eee's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "恶恶恶家的钥匙" NOR, ({ "key", "3 of eee" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启恶人谷(eee)的钥匙。
这是恶恶恶第三次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
