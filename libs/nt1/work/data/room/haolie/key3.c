// SN:I_jjQ0IhlEK_QK0[
// File(/data/room/haolie/key.c) of haolie's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
        set_name(YEL "段星家的钥匙" NOR, ({ "key", "3 of haolie" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一把用来开启小马虎(haolie)的钥匙。
这是段星第三次配的钥匙。
LONG );
                set("unit", "把");
                set("no_pawn", 1);
                set("no_sell", 1);
                set("item_make", 1);
                set("value", 1);
        }
}
