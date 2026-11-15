// feng.h 
// by Marz 



int look_feng(string arg);

mixed look_feng(string arg)
{
	int lucky;
	object me;

	if( !arg || arg!="feng" ) 
	return popup_comb("这是一座高耸入云的山峰，传说是武当山的主峰，叫天柱峰。山峰直插云霄，云雾缭绕，看不清山峰的真面目。\n\n", "看:look_x feng");
// 	write(popup_comb("
// 		      ^
// 		     ^ ^
// 		   @@@__^    
// 		    ^ @@@__
// 		   ^   ^  ^

// 抬眼望去，流云片片，烟雾缭绕，天柱峰若隐若现，似遥不可既…\n\n", "看:look_x feng"));

	me = this_player();
	lucky = random(me->query_dex() + me->query_kar()) + me->query_dex();

	if (lucky > 58)
	{
		write("突然间，有个黑点在云雾中一掠而过，好象是一只大雕！\n"
			+"可是那么高的地方，怎么可能呢？ｈｍｍ．．．也许是一时花了眼。\n\n");
	
	}else if(lucky >= 45)
	{
		// do nothing here
	}else if(lucky >= 30)
	{
		message_vision(HIY"$N光顾着看天，一不留神脚下踏了个空，... 啊...！\n"NOR"\n", me);
		message_vision(HIY"$N一个趔趄摔了一跤！还好，只伤了些皮骨，没有滚下去。\n"NOR"\n", me);
		me->receive_damage("qi", 30+4*random((int)me->query("age")));
		me->receive_damage("jing", 50);
	}else // bad luck 
	{
		message_vision(HIR"$N光顾着抬头看天，一不留神脚下踏了个空，... 啊...！\n"NOR"\n", me);
		tell_object(me, HIR"你控制不住地直往山下滚，只觉得浑身无处不疼，痛得要晕死过去。\n"NOR"\n");
		me->move(__DIR__"tyroad8");
		message("vision", HIR"只见" + me->query("name")
			+ "从山上骨碌碌地滚了下来，躺在地上半天爬不起来！\n"NOR"\n",
			environment(me), me);
		me->unconcious();
	}
	
	return "";
}
