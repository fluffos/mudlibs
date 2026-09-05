// ring
//rewritten by bibi
#include <ansi.h>


#include <armor.h>


inherit F_SAVE;
inherit F_AUTOLOAD;

inherit NECK;

void create()
{
	set_name(RED"钻石戒指(柳残阳送的结婚礼物)"NOR, ({ "finger ring", "ring" }));
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","金灿灿的一枚戒指，上边还有一颗璀璨的钻石！\n");
		set("unit", "枚");
		set("value", 1000);
		set("material", "gold");
		set("armor_prop/armor", 10);
	}
	setup();
}	

int query_autoload()
{
    return 1;
}

