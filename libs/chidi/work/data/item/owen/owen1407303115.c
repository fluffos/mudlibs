/**╠╬нд╪Чси╨оЁио╣мЁвт╤╞иЗЁи**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;35mио╧еиЯ╠Ь[1;32mж╝[1;36mе╥нд[1;33mж╦лв"NOR, ({"owen finger", "hecheng", "finger"}) );
	set("hcloth/name", "[1;35mио╧еиЯ╠Ь[1;32mж╝[1;36mе╥нд[1;33mж╦лв"NOR);
	set("hcloth/id", "owen finger");
	set("long", "уБйгсие╥нд(owen)╨оЁи╣д[1;35mио╧еиЯ╠Ь[1;32mж╝[1;36mе╥нд[1;33mж╦лв" + NOR + "║ё\n");
	set("armor_type", "finger");
	set_weight(5000);
	set("unit", "к╚");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 1094);
	set("armor_prop/constitution", 1056);
	set("armor_prop/dexerity", 1380);
	set("armor_prop/intelligence", 1059);
	set("armor_prop/strength", 1138);
	set("wear_msg", me->name() + NOR "в╟╠╦" + name () + NOR "ё║\n");
	set("unwear_msg", me->name() + NOR "мяоб" + name () + NOR "ё║\n");

   setup();
}

