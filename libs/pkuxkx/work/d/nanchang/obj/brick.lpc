//create by zine Aug 28 2010
#include <ansi.h>


inherit ITEM;

void create()
{	
	set_name(CYN"青砖"NOR, ({ "qing zhuan","zhuan", "brick"}));
	set_weight(5000);
	set("long", "这是一块青砖。\n");
	set("material", "wood");
	set("unit", "块");
	set("value", 0);
    set("no_drop",1);
    set("no_put",1);
	setup();
}

void init()
{
    add_action("do_follow","follow");
}

int do_follow()
{
    tell_object(this_player(),"叫你搬砖头，没事跟着别人干嘛？\n");
    return 1;
}