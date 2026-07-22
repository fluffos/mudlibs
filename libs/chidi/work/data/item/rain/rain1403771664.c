/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;35mÌìÊ¹[1;32mÏîÁ´"NOR, ({"rain neck", "hecheng", "neck"}) );
	set("hcloth/name", "[1;35mÌìÊ¹[1;32mÏîÁ´"NOR);
	set("hcloth/id", "rain neck");
	set("long", "ÕâÊÇÓÉĞ¡Óêµã(rain)ºÏ³ÉµÄ[1;35mÌìÊ¹[1;32mÏîÁ´" + NOR + "¡£\n");
	set("armor_type", "neck");
	set_weight(5000);
	set("unit", "¸ö");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 342);
	set("armor_prop/constitution", 756);
	set("armor_prop/dexerity", 832);
	set("armor_prop/intelligence", 683);
	set("armor_prop/strength", 753);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

