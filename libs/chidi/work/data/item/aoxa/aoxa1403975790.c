/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;31mÖí[1;32mÌã"NOR, ({"aoxa finger", "hecheng", "finger"}) );
	set("hcloth/name", "[1;31mÖí[1;32mÌã"NOR);
	set("hcloth/id", "aoxa finger");
	set("long", "ÕâÊÇÓÉÖíÍ·(aoxa)ºÏ³ÉµÄ[1;31mÖí[1;32mÌã" + NOR + "¡£\n");
	set("armor_type", "finger");
	set_weight(5000);
	set("unit", "Ë«");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 230);
	set("armor_prop/constitution", 787);
	set("armor_prop/dexerity", 674);
	set("armor_prop/intelligence", 848);
	set("armor_prop/strength", 694);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

