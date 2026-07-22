/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	object me = this_player();

	set_name("[1;36mĞı·ç[1;31m¼×"NOR, ({"xijia cloth", "hecheng", "cloth"}) );
	set("hcloth/name", "[1;36mĞı·ç[1;31m¼×"NOR);
	set("hcloth/id", "xijia cloth");
	set("long", "ÕâÊÇÓÉĞı·ç(xijia)ºÏ³ÉµÄ[1;36mĞı·ç[1;31m¼×" + NOR + "¡£\n");
	set("armor_type", "cloth");
	set_weight(5000);
	set("unit", "¼ş");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 285);
	set("armor_prop/constitution", 791);
	set("armor_prop/dexerity", 666);
	set("armor_prop/intelligence", 731);
	set("armor_prop/strength", 702);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

