// menlang.c
// By River@SJ

inherit ROOM;

void create()
{
	set("short", "武馆大门");
	set("long", @LONG
武馆进大门后要往里走，必须穿过一个门廊。廊顶描绘着江南秀美的风景。
每两根翠绿色的柱子间相隔也就两三尺的距离，朱红色的琉璃瓦，嫩黄色的地
砖。门廊正中站着一个少年，看见你来了，他笑嘻嘻地迎了上来。往北走就进
入武馆的前院了。
LONG);
	set("exits", ([
		"north" : __DIR__"qianting",
		"south" : "/d/city/xidajie2",
	]));

	set("no_fight",1);
	set("objects", ([
		__DIR__"npc/dizi4" : 1,
	]));
	setup();
}

int get_object(object ob)
{
	if(userp(ob))
		return 1;
	return 0;
}

int valid_leave(object me, string dir)
{
 

	if( dir != "north" && !wizardp(me)){
//		if( me->query("combat_exp") < 3000 )
//			return notify_fail("孙均上前把手一伸：江湖险恶，你还是在武馆学点东西再出去吧。\n");
/*
		if ( me->query("enter_wuguan"))
			return notify_fail("孙均把手一伸，拦住你的去路：没有馆主老人家的同意，不得私自离馆。\n");

		if (!me->query_temp("marks/离馆") )
			return notify_fail("孙均伸手一拦：你总得和我打声招呼才能走啊。\n");

		obj = filter_array(deep_inventory(me), (: get_object($1) :));

		if( sizeof(obj) > 0 )
			return notify_fail("孙均朝你嘿嘿一笑：想偷偷带谁出去？\n");
		me->delete("enter_wuguan");
		*/
	}

	return ::valid_leave(me, dir);
}