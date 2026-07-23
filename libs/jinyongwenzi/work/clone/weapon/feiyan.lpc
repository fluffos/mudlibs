// /clone/weapon/feiyan.c
// by leontt 2000/10/26

inherit COMBINED_ITEM;
#include <ansi.h>
#include "/inherit/item/embed.h"

void create()
{
	set_name(CYN"飞燕"NOR, ({ "fei yan","yan"}) );
	set_weight(200);
	if( clonep() )
		 set_default_object(__FILE__);
	else {
		set("long", CYN"这是一个酷似燕子形状的阴毒暗器，燕尾上长满了倒刺。\n"NOR);
		set("unit", "个");
		set("damage", 15);
		set("base_value",400);
		set("base_unit", "个");
		set("base_weight", 100);
		set("throw_msg",
		     HIR"$N左手暗藏袖中，食指一弹，飞燕划出一道黑色的弧线射向$n！\n"NOR);
		set("material", "steel");
		set("embed", 1);
	}
	set_amount(1);
}
