// SN:1;MUPY7^1bmda2jn
// File(/data/room/microfox/key.c) of microfox's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "段儿家的钥匙" NOR, ({ "key", "3 of microfox" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启清心居(microfox)的钥匙。
这是段儿第三次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
