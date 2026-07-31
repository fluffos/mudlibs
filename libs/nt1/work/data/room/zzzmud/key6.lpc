// SN:XdYP6=YNk@G?a3BC
// File(/data/room/zzzmud/key.c) of zzzmud's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "月落无双家的钥匙" NOR, ({ "key", "6 of zzzmud" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启满天星(zzzmud)的钥匙。
这是月落无双第六次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
