// File(/data/room/luoyuna/key.c) of luoyuna's key
// Create by LUBAN written by Doing Lu

#include <ansi.h>

inherit ITEM;

string query_autoload() { return "1"; }

void create()
{
	set_name(YEL "大白家的钥匙" NOR, ({ "key", "1 of luoyuna" }));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", @LONG
一把用来开启小白居(xiaobai)的钥匙。
这是原配钥匙。
LONG );
		set("unit", "把");
		set("no_pawn", 1);
		set("no_sell", 1);
		set("item_make", 1);
		set("value", 1);
	}
}
