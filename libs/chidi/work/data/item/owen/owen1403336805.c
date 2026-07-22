/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	object me = this_player();

	set_name("[1;36mÉÏ¹ÅÉñ±ø[1;33mÖ®[1;34m==>[1;35m¿ø¼×"NOR, ({"owen cloth", "hecheng", "cloth"}) );
	set("hcloth/name", "[1;36mÉÏ¹ÅÉñ±ø[1;33mÖ®[1;34m==>[1;35m¿ø¼×"NOR);
	set("hcloth/id", "owen cloth");
	set("long", "ÕâÊÇÓÉÈêÛ³Ê®Èı(owen)ºÏ³ÉµÄ[1;36mÉÏ¹ÅÉñ±ø[1;33mÖ®[1;34m==>[1;35m¿ø¼×" + NOR + "¡£\n");
	set("armor_type", "cloth");
	set_weight(5000);
	set("unit", "¼ş");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 439);
	set("armor_prop/constitution", 727);
	set("armor_prop/dexerity", 732);
	set("armor_prop/intelligence", 743);
	set("armor_prop/strength", 680);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

