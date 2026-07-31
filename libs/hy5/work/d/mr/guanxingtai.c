// /u/beyond/mr/guanxingtai.c
// Written by Jpei

inherit ROOM;

int do_look(string arg);
int do_jump(string arg);

void create()
{
	set("short","观星台");
	set("long",@LONG
这里是小径旁树丛中央的一个大平台。平台呈圆形，地上按二十八宿的方
位排布着一些木桩，其中一根最北边的木桩(zhuang)显得格外的粗壮。平台四
周树丛掩映，阳光透过树叶的缝隙在平台上留下了班驳的树影。
LONG
);
	set("exits",([
		"south" : __DIR__"xiaojing1-4",
	]) );
	set("outdoors","mr");
	set("no_clean_up",0);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_look", "look");
	add_action("do_look", "lookold");
	add_action("do_look", "l");
}

int do_jump(string arg)
{
	object me = this_player();
	int level, jinglicost;

	level = me->query_skill("dodge");
	if (arg == "zhuang") {
		if (me->query_temp("guanxing_zhuang")) {
			write("你已经在桩上了，别是站久了头昏吧？\n");
			return 1;
		}
		jinglicost = level / 3 + random(level / 4);
		if (me->query("jing") <= jinglicost) {
			write("你太累了，先歇歇吧！\n");
			return 1;
		}
		if (level < 250) {
			write("你耸身作势，向桩上跃去，可惜的是脚尖还差一些才能够到。\n");
			return 1;
		}
		me->receive_damage("jing", jinglicost);
		message_vision("$N脚下微一运劲，轻轻地一纵就上了木桩。\n", me);
		me->set_temp("guanxing_zhuang", 1);
		return 1;
	}
	if (arg == "down") {
		if (!me->query_temp("guanxing_zhuang")) {
			message_vision("$N想挖个坑跳进去，对着平台四处比划了一番，却忽然想到这种行为属于破坏公物，不由得脸红了起来。\n", me);
			return 1;
		}
		jinglicost = level / 4 + random(level / 5);
		if (me->query("jing") <= jinglicost) {
			write("你太累了，先歇歇吧！\n");
			return 1;
		}
		me->receive_damage("jing", jinglicost);
		if (level < 300)
			message_vision("$N笨手笨脚地从桩上跌了下来，发现这很象是一招屁股向下“流星赶月”式。\n", me);
		else
			message_vision("$N轻轻一纵落到了地上，觉得这根木桩也太矮了。\n", me);
		me->delete_temp("guanxing_zhuang");
		return 1;
	}
	return notify_fail("你要往哪里跳？\n");
}

int do_look(string arg)
{
	object me = this_player();
	mixed *local;
	int i, night, level;

	if (arg == "zhuang") {
		if (me->query_temp("guanxing_zhuang"))
			write("你往脚下的木桩看去，觉得有点晕眩，刚才在地上看时好象没有这么高！\n");
		else
			write("这是地上按星宿排列的木桩中最粗壮的一根，比别的木桩都高，离它们也比较远，显得有些孤零零的。\n");
		return 1;
	}
	night = 0;
	local = localtime(time() * 60);
	if (local[2] < 5 || local[2] >= 19) night = 1;

	if (!arg) {
		if (me->query_temp("guanxing_zhuang")) {
			if (local[2] < 3 || local[2] > 22)
				set("long", @LONG
你站在木桩上向四处张望，此时夜色如水，万籁俱寂，四周的树丛里黑压
压的看不清楚。仰头看去，夜空(sky)里繁星点点， 一闪一闪地似乎在向你倾
诉着什么秘密。月正中天，你惊讶地发现整个台子上只有这里才能清楚地看到
天顶各星的移动。
LONG
);
			else if (local[2] < 5)
				set("long", @LONG
你站在木桩上向四处张望，此时已是后半夜了，除了偶尔传来的几声虫鸣
外听不到任何声音，四周的树丛里黑压压的看不清楚。仰头看去，夜空(sky)
里繁星点点，一闪一闪地似乎在向你倾诉着什么秘密。月落星移，你惊讶地发
现整个台子上只有这里才能清楚地看到天顶各星的移动。
LONG
);
			else if (local[2] > 19)
				set("long", @LONG
你站在木桩上向四处张望，刚入夜，月亮已经升起来了，远处传来一阵阵
的喧闹声，四周的树丛里黑压压的看不清楚。仰头看去，夜空(sky) 里繁星点
点，一闪一闪地似乎在向你倾诉着什么秘密。玉兔东升，你惊讶地发现整个台
子上只有这里才能清楚地看到天顶各星的移动。
LONG
);
			else if (local[2] < 10)
				set("long", @LONG
你站在木桩上向四处张望，正是清晨，四周的树丛里黑影班驳，似乎有些
小鸟在其中蹿来蹿去。仰头看去，苍穹(sky)恍如一个巨碗， 倒扣在大地上。
日出的朝霞映红了天边，你惊讶地发现整个台子上只有这里才能清楚地看到远
方的天际。
LONG
);
			else if (local[2] < 15)
				set("long", @LONG
你站在木桩上向四处张望，已是正午时分，在明亮的阳光照射下，你大致
可以看清四周的树丛，一些小鸟在其中蹿来蹿去。仰头看去，苍穹(sky) 恍如
一个巨碗，倒扣在大地上。阳光直直地洒下来，你惊讶地发现整个台子上只有
这里才能清楚地看到远方的天际。
LONG
);
			else if (local[2] < 18)
				set("long", @LONG
你站在木桩上向四处张望，已经下午了，在明亮的阳光照射下，你大致可
以看清四周的树丛，一些小鸟在其中蹿来蹿去。仰头看去，苍穹(sky) 恍如一
个巨碗，倒扣在大地上。阳光西斜，你惊讶地发现整个台子上只有这里才能清
楚地看到远方的天际。
LONG
);
			else
				set("long", @LONG
你站在木桩上向四处张望，远处有些许炊烟，四周的树丛里黑影班驳，似
乎有些小鸟在其中蹿来蹿去。仰头看去，苍穹(sky)恍如一个巨碗， 倒扣在大
地上。傍晚的云彩绚丽而又凄美，你惊讶地发现整个台子上只有这里才能清楚
地看到远方的天际。
LONG
);
		}
		else {
			if (local[2] < 3 || local[2] > 22)
				set("long", @LONG
这里是小径旁树丛中央的一个大平台。平台呈圆形，地上按二十八宿的方
位排布着一些木桩，其中一根最北边的木桩(zhuang)显得格外的粗壮。夜色如
水，月正中天，平台四周树丛掩映，在夜幕下显得格外阴森。
LONG
);
			else if (local[2] < 5)
				set("long", @LONG
这里是小径旁树丛中央的一个大平台。平台呈圆形，地上按二十八宿的方
位排布着一些木桩，其中一根最北边的木桩(zhuang)显得格外的粗壮。后半夜
的空气又凄冷又清新，平台四周的树丛里偶尔传来几声虫鸣，在夜幕下显得有
些阴森。
LONG
);
			else if (local[2] > 19)
				set("long", @LONG
这里是小径旁树丛中央的一个大平台。平台呈圆形，地上按二十八宿的方
位排布着一些木桩，其中一根最北边的木桩(zhuang)显得格外的粗壮。刚刚入
夜，远处赏月行歌的人群传来阵阵的喧闹声，平台四周的树丛里逐渐寂静，在
夜幕下显得有些阴森。
LONG
);
			else if (local[2] < 10)
				set("long",@LONG
这里是小径旁树丛中央的一个大平台。平台呈圆形，地上按二十八宿的方
位排布着一些木桩，其中一根最北边的木桩(zhuang)显得格外的粗壮。清晨的
空气混有一股泥土的清香，平台四周树丛掩映，阳光浅浅地透进去，里面一片
灰蒙蒙的。
LONG
);
			else if (local[2] < 15)
				set("long",@LONG
这里是小径旁树丛中央的一个大平台。平台呈圆形，地上按二十八宿的方
位排布着一些木桩，其中一根最北边的木桩(zhuang)显得格外的粗壮。平台四
周树丛掩映，正午的阳光透过树叶的缝隙在平台上留下了班驳的树影。
LONG
);
			else if (local[2] < 18)
				set("long",@LONG
这里是小径旁树丛中央的一个大平台。平台呈圆形，地上按二十八宿的方
位排布着一些木桩，其中一根最北边的木桩(zhuang)显得格外的粗壮。平台四
周树丛掩映，下午的阳光洒进树丛，可以看到里面有些小鸟在窜来窜去，平台
上的树影逐渐拉长，日渐西山了。
LONG
);
			else
				set("long",@LONG
这里是小径旁树丛中央的一个大平台。平台呈圆形，地上按二十八宿的方
位排布着一些木桩，其中一根最北边的木桩(zhuang)显得格外的粗壮。平台四
周树丛掩映，傍晚的阳光难以穿透树叶的缝隙，使树丛看起来有些阴森。远处
不知谁家的炊烟正在袅袅升起，是晚餐时分了。
LONG
);
		}
		return 0;
	}
	if (arg == "sky") {
		if (!me->query_temp("guanxing_zhuang")) {
			if (night)
				write("你仰首望天，天上繁星点点，你顺着银河的方向看去，却发现部分的夜空被周围的树冠挡住了。\n");
			else
				write("你仰首望天，太阳挂在天空中，白云朵朵，阳光顺着云层的边缘洒下来，你觉得有些刺眼。\n");
			return 1;
		}
		if (!night) {
			write("你仰首望天，太阳挂在天空中，白云朵朵，阳光顺着云层的边缘洒下来，你觉得有些刺眼。\n");
			return 1;
		}
		level = me->query_skill("douzhuan-xingyi", 1);
		if (level < 200) {
			write("你仰首望天，天上繁星点点，你似乎觉得星斗的移动与你所学的“斗转星移”有莫大的联系，却无法领会。\n");
			return 1;
		}
		if (level * level * level / 10 > me->query("combat_exp")) {
			write("你仰首望天，天上繁星点点，你体会出了星斗的移动与你所学的“斗转星移”有莫大的联系，却苦于实战经验不足，无法将你看到的东西与实际作战联系到一起。\n");
			return 1;
		}
		write("你仰首望天，天上繁星点点，你体会出了星斗的移动与你所学的“斗转星移”有莫大的联系！\n");
		if (me->is_busy()) {
			write("可惜你现在正忙着做别的事，无法专心研究夜空中的星斗。\n");
			return 1;
		}

		if (me->is_fighting() ) {
			write("可惜你现在正在战斗中，无法专心研究夜空中的星斗。\n");
			return 1;
		}
		if (me->query("jing") < level / 7) {
			write("可惜你太累了，无法集中精神来研究夜空中的星斗。\n");
			return 1;
		}
		me->receive_damage("jing", level / 7);
		me->improve_skill("douzhuan-xingyi", (me->query("int")*2));

		write("你又掌握了一些在实战中运用斗转星移的技巧。\n");
		if (!random(5))
			tell_room(this_object(), me->name() + "站在木桩上仰首望天，嘴里呢喃着什么。\n", ({me}));
		return 1;
	}
	return 0;
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("guanxing_zhuang"))
		return notify_fail("先从木桩上跳下来(down)再说吧！\n");

	return ::valid_leave(me, dir);
}

