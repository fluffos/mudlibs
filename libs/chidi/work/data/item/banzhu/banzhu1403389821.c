/**╠╬нд╪Чси╨оЁио╣мЁвт╤╞иЗЁи**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;34mгО╥ГоЧтбаИ"NOR, ({"banzhu neck", "hecheng", "neck"}) );
	set("hcloth/name", "[1;34mгО╥ГоЧтбаИ"NOR);
	set("hcloth/id", "banzhu neck");
	set("long", "уБйгси╟ГжМ(banzhu)╨оЁи╣д[1;34mгО╥ГоЧтбаИ" + NOR + "║ё\n");
	set("armor_type", "neck");
	set_weight(5000);
	set("unit", "╦Ж");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 462);
	set("armor_prop/constitution", 838);
	set("armor_prop/dexerity", 796);
	set("armor_prop/intelligence", 881);
	set("armor_prop/strength", 805);
	set("wear_msg", me->name() + NOR "в╟╠╦" + name () + NOR "ё║\n");
	set("unwear_msg", me->name() + NOR "мяоб" + name () + NOR "ё║\n");

   setup();
}

