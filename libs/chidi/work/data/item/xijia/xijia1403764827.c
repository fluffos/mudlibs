/**╠╬нд╪Чси╨оЁио╣мЁвт╤╞иЗЁи**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;36mпЩ╥Г[1;31mп╛вс"NOR, ({"xijia boots", "hecheng", "boots"}) );
	set("hcloth/name", "[1;36mпЩ╥Г[1;31mп╛вс"NOR);
	set("hcloth/id", "xijia boots");
	set("long", "уБйгсипЩ╥Г(xijia)╨оЁи╣д[1;36mпЩ╥Г[1;31mп╛вс" + NOR + "║ё\n");
	set("armor_type", "boots");
	set_weight(5000);
	set("unit", "к╚");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 285);
	set("armor_prop/constitution", 700);
	set("armor_prop/dexerity", 850);
	set("armor_prop/intelligence", 725);
	set("armor_prop/strength", 712);
	set("wear_msg", me->name() + NOR "в╟╠╦" + name () + NOR "ё║\n");
	set("unwear_msg", me->name() + NOR "мяоб" + name () + NOR "ё║\n");

   setup();
}

