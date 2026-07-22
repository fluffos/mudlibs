/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;35m×Ïè¯Åû·ç"NOR, ({"poppig pifeng", "hecheng", "pifeng"}) );
	set("hcloth/name", "[1;35m×Ïè¯Åû·ç"NOR);
	set("hcloth/id", "poppig pifeng");
	set("long", "ÕâÊÇÓÉÁ÷ĞĞÖí(poppig)ºÏ³ÉµÄ[1;35m×Ïè¯Åû·ç" + NOR + "¡£\n");
	set("armor_type", "pifeng");
	set_weight(5000);
	set("unit", "¼ş");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 380);
	set("armor_prop/constitution", 765);
	set("armor_prop/dexerity", 692);
	set("armor_prop/intelligence", 858);
	set("armor_prop/strength", 768);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

