/**╠╬нд╪Чси╨оЁио╣мЁвт╤╞иЗЁи**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;35mио╧еиЯ╠Ь[1;32mж╝[1;36mе╥нд[1;33mя╔вс"NOR, ({"owen boots", "hecheng", "boots"}) );
	set("hcloth/name", "[1;35mио╧еиЯ╠Ь[1;32mж╝[1;36mе╥нд[1;33mя╔вс"NOR);
	set("hcloth/id", "owen boots");
	set("long", "уБйгсие╥нд(owen)╨оЁи╣д[1;35mио╧еиЯ╠Ь[1;32mж╝[1;36mе╥нд[1;33mя╔вс" + NOR + "║ё\n");
	set("armor_type", "boots");
	set_weight(5000);
	set("unit", "к╚");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 981);
	set("armor_prop/constitution", 1173);
	set("armor_prop/dexerity", 1214);
	set("armor_prop/intelligence", 917);
	set("armor_prop/strength", 902);
	set("wear_msg", me->name() + NOR "в╟╠╦" + name () + NOR "ё║\n");
	set("unwear_msg", me->name() + NOR "мяоб" + name () + NOR "ё║\n");

   setup();
}

