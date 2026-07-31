// SN:F`i4]V3CG`kL>B01
// File(/data/room/zhulihua/key.c) of zhulihua's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "朱丽花家的钥匙" NOR, ({ "key", "2 of zhulihua" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启桃花阁(zhulihua)的钥匙。
这是朱丽花第二次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
