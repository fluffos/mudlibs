/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;37mÕæÎäÅû·ç"NOR, ({"jimy pifeng", "hecheng", "pifeng"}) );
	set("hcloth/name", "[1;37mÕæÎäÅû·ç"NOR);
	set("hcloth/id", "jimy pifeng");
	set("long", "ÕâÊÇÓÉ¼ªÃ×(jimy)ºÏ³ÉµÄ[1;37mÕæÎäÅû·ç" + NOR + "¡£\n");
	set("armor_type", "pifeng");
	set_weight(5000);
	set("unit", "¼ş");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 376);
	set("armor_prop/constitution", 745);
	set("armor_prop/dexerity", 829);
	set("armor_prop/intelligence", 811);
	set("armor_prop/strength", 747);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

