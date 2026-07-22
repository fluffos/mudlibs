/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;36mÇ¬À¤È¦"NOR, ({"niuren neck", "hecheng", "neck"}) );
	set("hcloth/name", "[1;36mÇ¬À¤È¦"NOR);
	set("hcloth/id", "niuren neck");
	set("long", "ÕâÊÇÓÉ±ØĞëµÄ±Ø(niuren)ºÏ³ÉµÄ[1;36mÇ¬À¤È¦" + NOR + "¡£\n");
	set("armor_type", "neck");
	set_weight(5000);
	set("unit", "¸ö");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 282);
	set("armor_prop/constitution", 778);
	set("armor_prop/dexerity", 735);
	set("armor_prop/intelligence", 784);
	set("armor_prop/strength", 703);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

