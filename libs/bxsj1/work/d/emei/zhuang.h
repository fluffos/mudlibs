// zhuang.h

void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "tiao");
}

int do_jump(string arg)
{
	object me;
	me = this_player();
	if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着哪！\n");
	
if( (int)me->query_skill("dodge", 1) > 101 || (int)me->query_skill("anying-fuxiang", 1) > 120)
	return notify_fail("这里已经不适合你练习轻功了。\n");

	if( arg == "right" || arg == "you" ) {
	me->add_temp("marks/you", 1);
	write("你跳到了右边的梅花桩。\n", me);
	me->move(__DIR__"muzhuang"); 
	me->receive_damage("jingli", ((int)me->query("dex")));  
	 }

	if( arg == "left" || arg == "zuo" ) {
	me->add_temp("marks/zuo", 1);
	write("你跳到了左边的梅花桩。\n", me);
	me->move(__DIR__"muzhuang"); 
	me->receive_damage("jingli", ((int)me->query("dex")));
	 }

	if( arg == "qian" ) {
	me->add_temp("marks/qian", 1); 
	write("你跳到了前边的梅花桩。\n", me);
	me->move(__DIR__"muzhuang"); 
	me->receive_damage("jingli", ((int)me->query("dex")));
	 }

	if( arg == "hou" ) {
	me->add_temp("marks/hou", 1); 
	write("你跳到了后边的梅花桩。\n", me);
	me->move(__DIR__"muzhuang"); 
	me->receive_damage("jingli", ((int)me->query("dex")));
	 }

	if (me->query_temp("marks/zuo") == 1  &&
	    me->query_temp("marks/you") == 2  &&
	    me->query_temp("marks/qian") == 3  &&
	    me->query_temp("marks/hou") == 4 ) {		
	me->improve_skill("dodge", (int)me->query("dex") * 10 );
	me->improve_skill("anying-fuxiang", (int)me->query("dex") * 10 );
	write("你在梅花桩上跳来跳去，对你的轻功大为有益。\n", me);
        me->delete_temp("marks/zuo");
        me->delete_temp("marks/you");
        me->delete_temp("marks/qian");
        me->delete_temp("marks/hou");
	}
	return 1;
}
