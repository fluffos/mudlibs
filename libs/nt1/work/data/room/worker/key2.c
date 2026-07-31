// SN:HnVAkj_4b_BgMSAN
// File(/data/room/worker/key.c) of worker's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "桃花工人家的钥匙" NOR, ({ "key", "2 of worker" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启泥潭丹药制造(wkone)的钥匙。
这是桃花工人第二次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
