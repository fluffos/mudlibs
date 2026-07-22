/**╠╬нд╪Чси╨оЁио╣мЁвт╤╞иЗЁи**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;36mио╧еиЯ╠Ь[1;33mж╝[1;34m==>[1;35mя╔вс"NOR, ({"owen boots", "hecheng", "boots"}) );
	set("hcloth/name", "[1;36mио╧еиЯ╠Ь[1;33mж╝[1;34m==>[1;35mя╔вс"NOR);
	set("hcloth/id", "owen boots");
	set("long", "уБйгсихЙшЁй╝хЩ(owen)╨оЁи╣д[1;36mио╧еиЯ╠Ь[1;33mж╝[1;34m==>[1;35mя╔вс" + NOR + "║ё\n");
	set("armor_type", "boots");
	set_weight(5000);
	set("unit", "к╚");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 310);
	set("armor_prop/constitution", 690);
	set("armor_prop/dexerity", 831);
	set("armor_prop/intelligence", 729);
	set("armor_prop/strength", 746);
	set("wear_msg", me->name() + NOR "в╟╠╦" + name () + NOR "ё║\n");
	set("unwear_msg", me->name() + NOR "мяоб" + name () + NOR "ё║\n");

   setup();
}

