// SN:=@FQhi_?bJ3EJPX[
// File(/data/room/lingling/key.c) of lingling's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "慕容翎家的钥匙" NOR, ({ "key", "4 of lingling" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启翎卿居(ling)的钥匙。
这是慕容翎第四次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
