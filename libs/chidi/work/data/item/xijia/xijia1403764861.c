/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;36mĞı·ç[1;31mÊÖÌ×"NOR, ({"xijia hands", "hecheng", "hands"}) );
	set("hcloth/name", "[1;36mĞı·ç[1;31mÊÖÌ×"NOR);
	set("hcloth/id", "xijia hands");
	set("long", "ÕâÊÇÓÉĞı·ç(xijia)ºÏ³ÉµÄ[1;36mĞı·ç[1;31mÊÖÌ×" + NOR + "¡£\n");
	set("armor_type", "hands");
	set_weight(5000);
	set("unit", "Ë«");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 322);
	set("armor_prop/constitution", 787);
	set("armor_prop/dexerity", 709);
	set("armor_prop/intelligence", 687);
	set("armor_prop/strength", 787);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

