/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;31mÖí[1;32mÑü"NOR, ({"aoxa waist", "hecheng", "waist"}) );
	set("hcloth/name", "[1;31mÖí[1;32mÑü"NOR);
	set("hcloth/id", "aoxa waist");
	set("long", "ÕâÊÇÓÉÖíÍ·(aoxa)ºÏ³ÉµÄ[1;31mÖí[1;32mÑü" + NOR + "¡£\n");
	set("armor_type", "waist");
	set_weight(5000);
	set("unit", "Ìõ");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 316);
	set("armor_prop/constitution", 669);
	set("armor_prop/dexerity", 718);
	set("armor_prop/intelligence", 704);
	set("armor_prop/strength", 775);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

