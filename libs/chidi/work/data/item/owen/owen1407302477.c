/**╠╬нд╪Чси╨оЁио╣мЁвт╤╞иЗЁи**/

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	object me = this_player();

	set_name("[1;35mио╧еиЯ╠Ь[1;32mж╝[1;36mе╥нд[1;33m©Ь╪в"NOR, ({"owen cloth", "hecheng", "cloth"}) );
	set("hcloth/name", "[1;35mио╧еиЯ╠Ь[1;32mж╝[1;36mе╥нд[1;33m©Ь╪в"NOR);
	set("hcloth/id", "owen cloth");
	set("long", "уБйгсие╥нд(owen)╨оЁи╣д[1;35mио╧еиЯ╠Ь[1;32mж╝[1;36mе╥нд[1;33m©Ь╪в" + NOR + "║ё\n");
	set("armor_type", "cloth");
	set_weight(5000);
	set("unit", "╪Ч");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 1195);
	set("armor_prop/constitution", 1322);
	set("armor_prop/dexerity", 1185);
	set("armor_prop/intelligence", 1318);
	set("armor_prop/strength", 1384);
	set("wear_msg", me->name() + NOR "в╟╠╦" + name () + NOR "ё║\n");
	set("unwear_msg", me->name() + NOR "мяоб" + name () + NOR "ё║\n");

   setup();
}

