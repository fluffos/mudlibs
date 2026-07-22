// Room: /d/meizhuang/hall.c 大厅
// By Jpei

inherit ROOM;

string look_painting();

void create()
{
	set("short", "大厅");
	set("long", @LONG
这里是梅庄的大厅，大厅里很宽敞屋顶很高，大厅四面的墙差不多有十丈
以上。正面的墙上悬着一幅大中堂(zhongtang)。中堂下面放有一张八仙桌
南边是个大天井，东西两边各有一条穿廊。
LONG
	);

	set("item_desc", ([
		"painting" : (: look_painting :),
		"hua" : (: look_painting :),
		"zhongtang" : (: look_painting :),
	]) );

	set("exits", ([
		"north" : __DIR__"tianjing",
		"south" : __DIR__"huilang",
	]));

        set("objects", ([
                __DIR__"npc/shilingwei" : 1,
                __DIR__"npc/dingjian" : 1,
        ]));

	setup();
}

/*
void init()
{
	add_action("do_answer", ({"answer", "huida", "da"}));
}
*/

string look_painting()
{
	object me = this_player();
	object env = this_object();
	object shi;

	write("画中所绘是一个仙人的背面，墨意淋漓，笔力雄健，题款是：丹青生大醉后泼墨。\n");
	if (!present("danqing sheng", env) && me->query_skill("sword") > 150) {
		write("只见这八个字笔法森严，一笔笔便如长剑的刺划。\n");
		if (shi = present("shi lingwei", env)) {
			write("你对施令威说道：“我一见画下这个‘醉’字，便十分喜欢。这字中画中，便似乎蕴藏着一套极高明的剑法。”\n");
			tell_room(env, me->name() + "指着中堂，跟施令威说了些什么。\n", ({me}));
			write("施令威道：“这是四庄主一日大醉后绘的，无意中将剑法蓄蕴于内，那是他生平得意之作，酒醒之后再也绘不出来了。”\n");
			if (me->query_temp("pulmmanor/shi_friend") >= 18 && me->query_temp("plummanor/flag") == 4) {
				write("施令威道：“你居然能从此画中看出了剑意，四庄主定当引为知己。我进去告知。”\n");
				message_vision("$N对着$n一拱手，转身喜滋滋的走进去了。\n", shi, me);
				destruct(shi);
				call_out("danqing_out", 20, me);
			}
		}
	}
	return "";
}

void danqing_out(object me)
{
	object danqing, env = this_object();

	if (!objectp(me)) return;
	if (!(danqing = present("danqing sheng", env))) {
		danqing = new(__DIR__"npc/danqingsheng");
		danqing->move(env);
	}
	tell_room(env, "忽听得门外一人大声道：“从我画中看出了剑法？这人的眼光可了不起啊。”叫嚷声中，走进一个人来。\n", ({}));
	if (!present(me, env)) {
		tell_room(env, "那人看了半天，奇怪地道：“施令威说的是谁呀？”边说边转身回去了。\n", ({}));
		destruct(danqing);
		return;
	}
	me->set_temp("plummanor/flag", 5);
}
