// SN:[CIF0G8;X13kNYRf
// File(/data/room/tian/key.c) of tian's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "美人多情家的钥匙" NOR, ({ "key", "2 of tian" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启往事如烟(tianya)的钥匙。
这是美人多情第二次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
