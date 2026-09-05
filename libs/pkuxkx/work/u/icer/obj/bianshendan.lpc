#include <ansi.h>
inherit ITEM;
void decay();

void create()
{
        set_name("变身丹", ({"bianshen dan", "dan" }));
        set("unit", "枚");
        set("long", "这是一枚神奇的丹药，据说可以使男变女，女变男，太监么......这是专门为那些性取向异于常人的人群设计的。\n");
        set("value", 20000);
        set("no_sell",1);
	setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();
	if (!id(arg))
        return notify_fail("你要吃什么？\n");

	if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");

	tell_object(me, MAG"你拿出变身丹，闻了闻，似乎没有什么特殊味道。你心道：为了我的远大理想，什么都顾不得了！\n于是心一横，眼一闭，嘴一张，咕噜一声吞了下肚。\n"NOR);
        message("vision", MAG + me->name() + "鬼鬼祟祟地掏出一颗丸药，放到鼻子边闻了闻，又停了一停，目间露出悲壮的神色，\n仿佛下了什么重大决心。然后眼一闭，一口将丸药吞了下去。\n"NOR,
			environment(me), ({me}));

	me->start_busy(10);

	remove_call_out("decay");
	call_out("decay",5);

	destruct(this_object());
	return 1;
}

void decay()
{
	object where = environment(this_object());
	object me = this_player();

	if (me->query("gender") == "男性")
	{
		tell_object(me, HIR"你但觉得下身一阵空虚，胸前却涨痛欲裂，不仅又惊又喜，『啊』的一声叫了出来，却是雌声！\n"NOR);
	        message("vision", HIR + me->name() + "神情奇异，身材也好像发生了变化，忽然他『啊』的叫了一声，音调高而尖利，听得你直冒冷汗！\n"NOR,
			environment(me), ({me}));
		me->set("gender","女性");
	}else if (me->query("gender") == "女性")
	{
		tell_object(me, HIG"你但觉得胸前一阵空虚，下身却涨痛欲裂，不仅又惊又喜，『啊』的一声叫了出来，却是雄声！\n"NOR);
	        message("vision", HIG + me->name() + "神情奇异，身材也好像发生了变化，忽然他『啊』的叫了一声，音调低而沉闷，忽然你发现她居然长出了胡子！\n"NOR,
			environment(me), ({me}));
		me->set("gender","男性");
	}else
	{
		tell_object(me, HIG"你但觉得胸前下身全都涨痛欲裂，不仅又惊又喜，『啊』的一声叫了出来，却是雄雌合声！\n"NOR);
	        message("vision", HIG + me->name() + "神情奇异，身材也好像发生了变化，忽然他『啊』的叫了一声，音调高低兼具，听得你直冒冷汗！\n"NOR,
			environment(me), ({me}));
		me->set("gender","双性");
	}
		
	message( "channel:" + "chat",HIM + "【谣言】听说" + me->query("name") + "因为取向与众不同，不顾一切服用了变身丹！\n"
               	NOR, users() );
	destruct(this_object());
}