//无头尸体
//create by zine 29/3/2011
#include <ansi.h>

inherit ITEM;
void create()
{	
	set_name("无头尸体", ({ "corpse","shi ti"}));
	set_weight(50000);
	set("long", "这是一具无头的尸体。\n");
	set("material", "fresh");
	set("unit", "具");
	set("value", 1);
    set("no_give",1);
    set("no_drop",1);
    set("no_get","尸体泡了水，已经肿胀开了，还是别接触为妙。\n");
    set("no_put",1);
    set("no_store",1);
	setup();
    call_out("dest",360);
}

int dest()
{
    if (this_object())
    {
		destruct(this_object());
    }
}

void init()
{
	add_action("do_chakan","chakan");
}
int disappear(object ob)
{
	if (ob)
	{
		message_vision(YEL+"$N被触动后，迅速化作一摊黄水……\n"+NOR,ob);
		dest();
	}
}
int do_chakan()
{
	object me=this_player();
	string *wound=({"剑","刀","枪","锤","戟","斧","匕首","鞭","叉"});
	if (me->query_temp("songtasks/xingbu/2/finish"))
	{
		tell_object(me,"任务完成了，这具尸体就留着吧，你快回去复命吧。\n");
		return 1;
	}
	if (me->query_temp("songtasks/xingbu/task")!=2)
	{
		return 0;
	}
	message_vision("$N开始细心检查这具无头尸体。\n",me);
	tell_object(me,"你发现，这具尸体上似乎有些"+wound[random(sizeof(wound))]+"造成的创伤。\n");
	tell_object(me,"你将自己的发现写入了报告，你快回去复命吧。\n");
	me->set_temp("songtasks/xingbu/2/finish",1);
	remove_call_out("disappear");
	call_out("disappear",1,this_object());
	return 1;
}