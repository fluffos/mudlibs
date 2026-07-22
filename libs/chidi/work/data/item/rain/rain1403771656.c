/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	object me = this_player();

	set_name("[1;35mÌìÊ¹[1;32mîø¼×"NOR, ({"rain cloth", "hecheng", "cloth"}) );
	set("hcloth/name", "[1;35mÌìÊ¹[1;32mîø¼×"NOR);
	set("hcloth/id", "rain cloth");
	set("long", "ÕâÊÇÓÉĞ¡Óêµã(rain)ºÏ³ÉµÄ[1;35mÌìÊ¹[1;32mîø¼×" + NOR + "¡£\n");
	set("armor_type", "cloth");
	set_weight(5000);
	set("unit", "¼ş");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 301);
	set("armor_prop/constitution", 764);
	set("armor_prop/dexerity", 743);
	set("armor_prop/intelligence", 737);
	set("armor_prop/strength", 781);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

