/**╠╬нд╪Чси╨оЁио╣мЁвт╤╞иЗЁи**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;36mио╧еиЯ╠Ь[1;33mж╝[1;37m==>[1;35mоНа╢"NOR, ({"owen neck", "hecheng", "neck"}) );
	set("hcloth/name", "[1;36mио╧еиЯ╠Ь[1;33mж╝[1;37m==>[1;35mоНа╢"NOR);
	set("hcloth/id", "owen neck");
	set("long", "уБйгсие╥нд(owen)╨оЁи╣д[1;36mио╧еиЯ╠Ь[1;33mж╝[1;37m==>[1;35mоНа╢" + NOR + "║ё\n");
	set("armor_type", "neck");
	set_weight(5000);
	set("unit", "╦Ж");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 337);
	set("armor_prop/constitution", 902);
	set("armor_prop/dexerity", 743);
	set("armor_prop/intelligence", 794);
	set("armor_prop/strength", 736);
	set("wear_msg", me->name() + NOR "в╟╠╦" + name () + NOR "ё║\n");
	set("unwear_msg", me->name() + NOR "мяоб" + name () + NOR "ё║\n");

   setup();
}

