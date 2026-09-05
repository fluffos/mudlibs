//Create by Chui
//02.12.2

inherit ROOM;

void create()
{
	set("short", "钱塘江口");
set("outdoors","qiantangjiang");
	set("long", @LONG
随着阵阵海风，你来到了钱塘江口，一眼望去宽广的钱塘江面，汹涌彭湃的钱
塘江潮，就是从这而来，恶浪滔天，势不可挡。尤其是八月十五之日，钱塘江
涨潮之时，不小心就会被潮水卷跑的。相传当年“西狂”大侠杨过，跳进(jump)
江中（jiang），练就了玄铁剑法。
LONG
	);
	set("no_clean_up", 0);
    set("exits", ([
        "west" : __DIR__"nanhu",
    ]));
	set("objects", ([
	]));
	setup();
}

void init()
{
	add_action("do_jump","jump");
	add_action("do_jump","tiao");
}

int do_jump(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg == "" ) 
	return notify_fail("你观看滔滔潮水，傻乎乎地又蹦又跳起来。\n");
	if((int)me->query_skill("dodge",1)<150)
	return notify_fail("就凭你这点武功，最好不要瞅热闹了，小心被潮水卷跑了。\n");
        if(me->is_busy())
        return notify_fail("你现在动都动不了，怎么跳啊，别逗了。\n");
	if( arg == "jiang")
	{
        message_vision("$N走向江边，纵身一跳，……\n\n"+
        "滔滔江水立即就将其淹没。\n",me);
		me->set_temp("pfm_skip",1);
		me->move("/d/quanzhou/sea");
	return 1;
	}
	else
	return notify_fail("你要干什么？\n");
}



