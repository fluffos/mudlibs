// paper.c 图纸
// Written by Doing Lu 1998/11/17
//   这是用来建造房间时使用的，玩家从鲁班处获得这个道具，然后在上面描绘建房地点的风景，
//   必须有30级以上的drawing才能作画。drawing可以向鲁班学。
//   作完画后：draw记录了作画的水平，position记录了作画的地点。

inherit ITEM;

void create()
{
        set_name("图纸", ({ "paper" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("material", "paper");
		set("long", "这是一张白纸，你可以在它上面画些东西。\n");
		set("图纸", 1);			// 鉴别标志
		set("position", "");		// 作画的地点
		set("draw", 0);			// 作画的水平 -- 0 表示没有
		set("value", 0);
        }
        setup();
}

void init()
{
	add_action("do_draw", "draw");
	add_action("do_draw", "画");
	add_action("do_draw", "绘画");
}

int do_draw()
{
	object me;
	int skl;
	me = this_player();
	if (me->is_busy()) return notify_fail("你现在正忙，没时间作画！\n");
	if (me->is_fighting())
	{
		return notify_fail("边打架边作画，亏你想得出？\n");
	}
	if (query("draw") > 0)
	{
		message_vision("$N轻轻的将白纸上的痕迹擦掉。\n", me);
		set("long", "这是一张白纸，你可以在它上面画些东西。\n");
		set("draw", 0);	
	}
	message("vision", me->query("name") + "拿出一支笔，看了看周围，又想了想，在纸上不知画了些什么东西。\n",
		environment(me), ({me}));
	skl = me->query_skill("drawing", 1);
	if (! skl) skl = 1;
	set("draw", skl);	
	set("position", base_name(environment(me)));
	if (skl < 10)
	{
		write("你拿起笔，却不知道怎么下手，只好胡乱画了一些东西。\n");
		set("long", "这是一张纸，上面画了一些乱七八糟的东西。\n");
		me->start_busy(4);
	} else
	if (skl < 30)
	{
		write("你拿起笔的画了起来，不一会就画完了。\n");
		set("long", "这是一张纸，上面歪歪扭扭的画了一些东西，辨认不出来究竟是什么东西。\n");
		me->start_busy(8);
	} else
	if (skl < 80)
	{
		write("你拿起笔来，看了看四周的风景，仔细的画了起了，很快就画好了。\n");
		set("long", "这是一张纸，上面画的是" + environment(me)->query("short") + "的风景，相当不错。\n");
		me->start_busy(6);
	} else
	{
		write("你拿起笔，随意挥洒，转眼间四周的风景就跃然纸上。\n");
		set("long", "这是一张纸，画的是" + environment(me)->query("short") + "的风景，很是逼真。\n");
		me->start_busy(2);
	}
	return 1;
}