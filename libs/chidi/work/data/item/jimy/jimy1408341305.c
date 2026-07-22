/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;37mÕæÎäÍ·¿ø"NOR, ({"jimy head", "hecheng", "head"}) );
	set("hcloth/name", "[1;37mÕæÎäÍ·¿ø"NOR);
	set("hcloth/id", "jimy head");
	set("long", "ÕâÊÇÓÉ¼ªÃ×(jimy)ºÏ³ÉµÄ[1;37mÕæÎäÍ·¿ø" + NOR + "¡£\n");
	set("armor_type", "head");
	set_weight(5000);
	set("unit", "Ë«");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 234);
	set("armor_prop/constitution", 763);
	set("armor_prop/dexerity", 801);
	set("armor_prop/intelligence", 754);
	set("armor_prop/strength", 820);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

