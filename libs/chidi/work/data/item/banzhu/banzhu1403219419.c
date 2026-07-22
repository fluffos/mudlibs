/**╠╬нд╪Чси╨оЁио╣мЁвт╤╞иЗЁи**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("[1;32mюквс╩╓мС"NOR, ({"banzhu finger", "hecheng", "finger"}) );
	set("hcloth/name", "[1;32mюквс╩╓мС"NOR);
	set("hcloth/id", "banzhu finger");
	set("long", "уБйгси╟ГжМ(banzhu)╨оЁи╣д[1;32mюквс╩╓мС" + NOR + "║ё\n");
	set("armor_type", "finger");
	set_weight(5000);
	set("unit", "к╚");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 223);
	set("armor_prop/constitution", 628);
	set("armor_prop/dexerity", 649);
	set("armor_prop/intelligence", 651);
	set("armor_prop/strength", 640);
	set("wear_msg", me->name() + NOR "в╟╠╦" + name () + NOR "ё║\n");
	set("unwear_msg", me->name() + NOR "мяоб" + name () + NOR "ё║\n");

   setup();
}

