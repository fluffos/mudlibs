/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;32mÕ½ÉñÑü´ø"NOR, ({"niuren waist", "hecheng", "waist"}) );
	set("hcloth/name", "[1;32mÕ½ÉñÑü´ø"NOR);
	set("hcloth/id", "niuren waist");
	set("long", "ÕâÊÇÓÉ±ØĞëµÄ±Ø(niuren)ºÏ³ÉµÄ[1;32mÕ½ÉñÑü´ø" + NOR + "¡£\n");
	set("armor_type", "waist");
	set_weight(5000);
	set("unit", "Ìõ");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 344);
	set("armor_prop/constitution", 826);
	set("armor_prop/dexerity", 741);
	set("armor_prop/intelligence", 785);
	set("armor_prop/strength", 875);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

