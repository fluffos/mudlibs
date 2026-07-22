/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;36mÉÏ¹ÅÉñ±ø[1;33mÖ®[1;34m==>[1;35mÑü´ø"NOR, ({"owen waist", "hecheng", "waist"}) );
	set("hcloth/name", "[1;36mÉÏ¹ÅÉñ±ø[1;33mÖ®[1;34m==>[1;35mÑü´ø"NOR);
	set("hcloth/id", "owen waist");
	set("long", "ÕâÊÇÓÉÈêÛ³Ê®Èı(owen)ºÏ³ÉµÄ[1;36mÉÏ¹ÅÉñ±ø[1;33mÖ®[1;34m==>[1;35mÑü´ø" + NOR + "¡£\n");
	set("armor_type", "waist");
	set_weight(5000);
	set("unit", "Ìõ");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 399);
	set("armor_prop/constitution", 710);
	set("armor_prop/dexerity", 754);
	set("armor_prop/intelligence", 830);
	set("armor_prop/strength", 853);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

