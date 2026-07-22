/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	object me = this_player();

	set_name("[1;31mÊ´[1;32mÈÕ[1;33m±£[1;35m¼×"NOR, ({"maxpker cloth", "hecheng", "cloth"}) );
	set("hcloth/name", "[1;31mÊ´[1;32mÈÕ[1;33m±£[1;35m¼×"NOR);
	set("hcloth/id", "maxpker cloth");
	set("long", "ÕâÊÇÓÉÉ±ÊÖÖ®Íõ(maxpker)ºÏ³ÉµÄ[1;31mÊ´[1;32mÈÕ[1;33m±£[1;35m¼×" + NOR + "¡£\n");
	set("armor_type", "cloth");
	set_weight(5000);
	set("unit", "¼ş");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 429);
	set("armor_prop/constitution", 715);
	set("armor_prop/dexerity", 815);
	set("armor_prop/intelligence", 731);
	set("armor_prop/strength", 724);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

