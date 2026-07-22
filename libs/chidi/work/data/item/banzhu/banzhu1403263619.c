/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;31m¹í¿ŞÀÇº¿Åû·ç"NOR, ({"banzhu pifeng", "hecheng", "pifeng"}) );
	set("hcloth/name", "[1;31m¹í¿ŞÀÇº¿Åû·ç"NOR);
	set("hcloth/id", "banzhu pifeng");
	set("long", "ÕâÊÇÓÉ°çÖí(banzhu)ºÏ³ÉµÄ[1;31m¹í¿ŞÀÇº¿Åû·ç" + NOR + "¡£\n");
	set("armor_type", "pifeng");
	set_weight(5000);
	set("unit", "¼ş");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 209);
	set("armor_prop/constitution", 682);
	set("armor_prop/dexerity", 652);
	set("armor_prop/intelligence", 699);
	set("armor_prop/strength", 645);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

