/**╠╬нд╪Чси╨оЁио╣мЁвт╤╞иЗЁи**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;31mаряФ[1;36mсю╨Ц"NOR, ({"banzhu hands", "hecheng", "hands"}) );
	set("hcloth/name", "[1;31mаряФ[1;36mсю╨Ц"NOR);
	set("hcloth/id", "banzhu hands");
	set("long", "уБйгси╟ГжМ(banzhu)╨оЁи╣д[1;31mаряФ[1;36mсю╨Ц" + NOR + "║ё\n");
	set("armor_type", "hands");
	set_weight(5000);
	set("unit", "к╚");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 272);
	set("armor_prop/constitution", 648);
	set("armor_prop/dexerity", 640);
	set("armor_prop/intelligence", 660);
	set("armor_prop/strength", 661);
	set("wear_msg", me->name() + NOR "в╟╠╦" + name () + NOR "ё║\n");
	set("unwear_msg", me->name() + NOR "мяоб" + name () + NOR "ё║\n");

   setup();
}

