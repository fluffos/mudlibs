#include <ansi.h>

inherit ITEM;
void create()
{	
	set_name(WHT"武器架"NOR, ({ "shelf","jia"}));
	set_weight(500000000);
	set("long", "这是一块武器架，架上放置着各种武器和装备。你可以拿(na)来使用。\n");
	set("material", "jade");
	set("unit", "块");
	set("value", 0);
    set("no_give",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_put",1);
    set("no_store",1);
    set("is_shibei",1);
	setup();
    call_out("checkme",1);
}

void init()
{
	add_action("do_na","na");
}

int do_na(string arg)
{
	object me=this_player(),ob;
	if (!arg||member_array(arg,({"sword","blade","spear","halberd","axe","hammer","whip","dagger","throwing","staff","armor"}))==-1)
	return notify_fail("你可以拿的装备名称应为sword,blade,spear,halberd,axe,hammer,whip,dagger,throwing,staff,armor中的一种。\n");
	ob=new("/d/song/wuchang/obj/"+arg);
	ob->move(me);
	message_vision("$N从武器架上取下了$n。\n",me,ob);
	return 1;
}