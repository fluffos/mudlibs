/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;35mÁ÷ĞĞ[1;37mÍ·¿ø"NOR, ({"flygods waist", "hecheng", "waist"}) );
	set("hcloth/name", "[1;35mÁ÷ĞĞ[1;37mÍ·¿ø"NOR);
	set("hcloth/id", "flygods waist");
	set("long", "ÕâÊÇÓÉÌìÌì(flygods)ºÏ³ÉµÄ[1;35mÁ÷ĞĞ[1;37mÍ·¿ø" + NOR + "¡£\n");
	set("armor_type", "waist");
	set_weight(5000);
	set("unit", "Ìõ");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 417);
	set("armor_prop/constitution", 679);
	set("armor_prop/dexerity", 775);
	set("armor_prop/intelligence", 752);
	set("armor_prop/strength", 716);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

