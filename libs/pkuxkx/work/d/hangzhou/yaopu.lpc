inherit "/d/hangzhou/song_room";
#include <ansi.h>
string look_xiang();
void create()
{
	set("short", "药铺");
	set("long", @LONG
这里是新近开的一家药铺，一进门左侧放了一座药王菩萨像(xiang)。
LONG);
        set("outdoors", "hangzhou");

	set("exits", ([
		"enter" : __DIR__"yaopu2",
		//"east" : __DIR__"yaopu",
		"west" : __DIR__"beijie3",
		//"north" : __DIR__"beijie3",
	]));
	set("item_desc", ([
                "xiang" : (:look_xiang:),
        ]));
	set("no_task",1);
	set("objects", ([
		__DIR__"npc/yaolaoban" : 1,
        ])); 
	setup();
}
int check_yaopu()
{
	object *rooms;
	rooms=children("/d/hangzhou/yaopu2");
	write("共有"+chinese_number(sizeof(rooms)-1)+"个隔间被使用。\n");
	if (sizeof(rooms)>1)
	{
		write("以下玩家使用：");
		for (int i=0;i<(sizeof(rooms)>30?30:sizeof(rooms));i++)
		if (rooms[i]->query("user"))
		write(rooms[i]->query("user")+" ");
	}
	write("\n");
	return 1;
}
string look_xiang()
{
	object me=this_player();
	tell_object(me,"药王菩萨，与人良药，救治众生身、心两种病苦的菩萨，乃二十五大菩萨之一。\n");
	if (me->query_skill("alchemy",1)>=50)
	{
		tell_object(me,"拜了(mobai)药王菩萨，等同加入药师一门，对于只要将有帮助，但对于武学修为将有"+HIR+"阻碍"+NOR+"，世上没有后悔药，一定要下定决心再试。\n");
		me->set_temp("MobaiAlchemy",1);
	}
	return "";
}

void init()
{
	add_action("do_mobai","mobai");
}
int do_mobai()
{
	object me=this_player();
	if (me->query("ProfessionalClass/alchemy"))
	{
		tell_object(me,"你又想起了当年初次拜入药师门下的事。");
		message_vision("$N对着药王菩萨像，俯身拜了三拜。\n",me);
		return 1;
	}
	if (!me->query_temp("MobaiAlchemy"))
	return 0;
	message_vision("$N对着药王菩萨像，恭恭敬敬地拜倒下去，叩了三次头。\n",me);
	F_PRO->register_me(me,"alchemy");//set职业就是核心职业技能,skills有的,注意小写
	return 1;
}

int valid_leave(object me,string dir)
{
	object rm;
	if (dir=="enter")
	{
		if (me->is_busy()||me->is_fighting())
		return notify_fail("你正忙着呢。\n");
		if(userp(me)&&time() - me->query("killer/time") < 900)
		return notify_fail("你刚刚杀了人，别想躲进药铺隔间里。\n");
		if (time()>=me->query_temp("PermitAlchemy")&&time()>=me->query_temp("PermitAlchemy2"))
		return notify_fail("你要租药炉需要跟药铺老板打招呼了。\n");
		if (time()<me->query_temp("PermitAlchemy2"))
		rm=new(__DIR__"yaopu3");
		else if (time()<me->query_temp("PermitAlchemy"))
		rm=new(__DIR__"yaopu2");
		message_vision("$N和老板打过招呼后，向药铺后堂的小隔间离去。\n",me);
		me->move(rm);
		rm->set("user",me->query("id"));
		return notify_fail("你来到了药铺的小隔间。\n");
	}
	return ::valid_leave(me,dir);
}