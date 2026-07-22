/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	object me = this_player();

	set_name("[1;36mÃÔ»ÃÄ§Ó°"NOR, ({"banzhu cloth", "hecheng", "cloth"}) );
	set("hcloth/name", "[1;36mÃÔ»ÃÄ§Ó°"NOR);
	set("hcloth/id", "banzhu cloth");
	set("long", "ÕâÊÇÓÉ°çÖí(banzhu)ºÏ³ÉµÄ[1;36mÃÔ»ÃÄ§Ó°" + NOR + "¡£\n");
	set("armor_type", "cloth");
	set_weight(5000);
	set("unit", "¼ş");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 394);
	set("armor_prop/constitution", 751);
	set("armor_prop/dexerity", 912);
	set("armor_prop/intelligence", 734);
	set("armor_prop/strength", 687);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

