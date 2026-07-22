/**±¾ÎÄ¼şÓÉºÏ³ÉÏµÍ³×Ô¶¯Éú³É**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;35mÓ¢ĞÛÅû·ç"NOR, ({"niuren pifeng", "hecheng", "pifeng"}) );
	set("hcloth/name", "[1;35mÓ¢ĞÛÅû·ç"NOR);
	set("hcloth/id", "niuren pifeng");
	set("long", "ÕâÊÇÓÉ±ØĞëµÄ±Ø(niuren)ºÏ³ÉµÄ[1;35mÓ¢ĞÛÅû·ç" + NOR + "¡£\n");
	set("armor_type", "pifeng");
	set_weight(5000);
	set("unit", "¼ş");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 322);
	set("armor_prop/constitution", 692);
	set("armor_prop/dexerity", 717);
	set("armor_prop/intelligence", 676);
	set("armor_prop/strength", 716);
	set("wear_msg", me->name() + NOR "×°±¸" + name () + NOR "£¡\n");
	set("unwear_msg", me->name() + NOR "ÍÑÏÂ" + name () + NOR "£¡\n");

   setup();
}

