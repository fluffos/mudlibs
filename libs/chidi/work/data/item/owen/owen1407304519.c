/**╠╬нд╪Чси╨оЁио╣мЁвт╤╞иЗЁи**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;35mио╧еиЯ╠Ь[1;32mж╝[1;36mе╥нд[1;33mяЭ╢Ь"NOR, ({"owen waist", "hecheng", "waist"}) );
	set("hcloth/name", "[1;35mио╧еиЯ╠Ь[1;32mж╝[1;36mе╥нд[1;33mяЭ╢Ь"NOR);
	set("hcloth/id", "owen waist");
	set("long", "уБйгсие╥нд(owen)╨оЁи╣д[1;35mио╧еиЯ╠Ь[1;32mж╝[1;36mе╥нд[1;33mяЭ╢Ь" + NOR + "║ё\n");
	set("armor_type", "waist");
	set_weight(5000);
	set("unit", "лУ");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 1056);
	set("armor_prop/constitution", 1048);
	set("armor_prop/dexerity", 1091);
	set("armor_prop/intelligence", 1337);
	set("armor_prop/strength", 1119);
	set("wear_msg", me->name() + NOR "в╟╠╦" + name () + NOR "ё║\n");
	set("unwear_msg", me->name() + NOR "мяоб" + name () + NOR "ё║\n");

   setup();
}

