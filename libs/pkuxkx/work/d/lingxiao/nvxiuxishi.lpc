// File		: nvxiuxishi.c
// Created By	: iszt@pkuxkx, 2006-08-16

inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
这里是雪山派女弟子的休息室了。女孩子毕竟爱美，许多床铺上都装点了些
小饰物，与平日的英武各异其趣。屋子的一角，炉火烧得正旺，可也难将寒意彻
底驱逐出去。几名女弟子正在打坐，也有人正在睡觉，你不禁困意顿生。
LONG);

	set("indoors", "凌霄城");
	set("no_fight", 1);
	set("exits", ([
		"north" : __DIR__"stonen5",
	]));

        set("sleep_room",1);
	setup();
}

void init()
{
	object me;

	if( interactive(me = this_player()) && !me->is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
}

string* msg = ({
"$N，你无耻！！",
"$N你这条色狼，",
});

void greeting(object me)
{
	object* ob = all_inventory(this_object());
	string msg;
	int i;

	if(!me)
		return;
	if(me->query("gender") == "女性")
		return;

	for(i = sizeof(ob)-1; i>=0; i--)
	{
		if(ob[i]->query("gender") == "女性")
		{
			if(random(2))
				msg = me->name()+"，你无耻！！";
			else
				msg = me->name()+"你这条色狼，"
					+RANK_D->query_self(ob[i])+"跟你拼了！";
			CHANNEL_D->do_channel(ob[i], "chat", msg);
			if(environment(me) == environment(ob[i]))
				ob[i]->kill_ob(me);
			if(!me->is_busy())
				me->start_busy(2);
		}
	}
	if(!me->is_busy())
	{
		message_vision("$N闯了进来，还好，这里没有人。\n", me);
		return;
	}
}
