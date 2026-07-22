/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	object me = this_player();

	set_name("[1;35mÁ÷ĞĞ[1;37m¿ø¼×"NOR, ({"flygods cloth", "hecheng", "cloth"}) );
	set("hcloth/name", "[1;35mÁ÷ĞĞ[1;37m¿ø¼×"NOR);
	set("hcloth/id", "flygods cloth");
	set("long", "ÕâÊÇÓÉÌìÌì(flygods)ºÏ³ÉµÄ[1;35mÁ÷ĞĞ[1;37m¿ø¼×" + NOR + "¡£\n");
	set("armor_type", "cloth");
	set_weight(5000);
	set("unit", "¼ş");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 352);
	set("armor_prop/constitution", 749);
	set("armor_prop/dexerity", 651);
	set("armor_prop/intelligence", 651);
	set("armor_prop/strength", 821);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

