/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;36mÉÏ¹ÅÉñ±ø[1;33mÖ®[1;34m==>[1;35mÊÖÌ×"NOR, ({"owen hands", "hecheng", "hands"}) );
	set("hcloth/name", "[1;36mÉÏ¹ÅÉñ±ø[1;33mÖ®[1;34m==>[1;35mÊÖÌ×"NOR);
	set("hcloth/id", "owen hands");
	set("long", "ÕâÊÇÓÉÈêÛ³Ê®Èı(owen)ºÏ³ÉµÄ[1;36mÉÏ¹ÅÉñ±ø[1;33mÖ®[1;34m==>[1;35mÊÖÌ×" + NOR + "¡£\n");
	set("armor_type", "hands");
	set_weight(5000);
	set("unit", "Ë«");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 463);
	set("armor_prop/constitution", 681);
	set("armor_prop/dexerity", 727);
	set("armor_prop/intelligence", 688);
	set("armor_prop/strength", 732);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

