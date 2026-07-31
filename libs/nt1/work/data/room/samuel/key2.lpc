// SN:^VnT5a^E\=Z`2]\@
// File(/data/room/samuel/key.c) of samuel's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "门托萨拉家的钥匙" NOR, ({ "key", "2 of samuel" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启国王的家(samuel)的钥匙。
这是门托萨拉第二次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
