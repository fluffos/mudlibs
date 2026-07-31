// SN:4dL`H`G4LHi`CV;Y
// File(/data/room/alert/key.c) of alert's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "朱云家的钥匙" NOR, ({ "key", "2 of alert" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启猪猪山中别墅(piggm)的钥匙。
这是朱云第二次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
