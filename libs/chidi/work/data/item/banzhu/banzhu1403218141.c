/**╠╬нд╪Чси╨оЁио╣мЁвт╤╞иЗЁи**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;31m╠ля╙м╥╫М"NOR, ({"banzhu head", "hecheng", "head"}) );
	set("hcloth/name", "[1;31m╠ля╙м╥╫М"NOR);
	set("hcloth/id", "banzhu head");
	set("long", "уБйгси╟ГжМ(banzhu)╨оЁи╣д[1;31m╠ля╙м╥╫М" + NOR + "║ё\n");
	set("armor_type", "head");
	set_weight(5000);
	set("unit", "к╚");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 161);
	set("armor_prop/constitution", 671);
	set("armor_prop/dexerity", 640);
	set("armor_prop/intelligence", 646);
	set("armor_prop/strength", 662);
	set("wear_msg", me->name() + NOR "в╟╠╦" + name () + NOR "ё║\n");
	set("unwear_msg", me->name() + NOR "мяоб" + name () + NOR "ё║\n");

   setup();
}

