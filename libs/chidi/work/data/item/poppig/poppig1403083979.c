/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;36mº£ÑóÖ®ĞÄ"NOR, ({"poppig neck", "hecheng", "neck"}) );
	set("hcloth/name", "[1;36mº£ÑóÖ®ĞÄ"NOR);
	set("hcloth/id", "poppig neck");
	set("long", "ÕâÊÇÓÉÁ÷ĞĞÖí(poppig)ºÏ³ÉµÄ[1;36mº£ÑóÖ®ĞÄ" + NOR + "¡£\n");
	set("armor_type", "neck");
	set_weight(5000);
	set("unit", "¸ö");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 327);
	set("armor_prop/constitution", 705);
	set("armor_prop/dexerity", 622);
	set("armor_prop/intelligence", 839);
	set("armor_prop/strength", 706);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

