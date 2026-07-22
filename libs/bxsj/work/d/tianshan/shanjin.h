void init()
{
        object me = this_player();
	int i,j;
        i=random(5)+2;
	j=random(4)+3;

	if ( me->query("quest/tonglao/quest") >= 3 && me->query("registered") < 3)
		return;
        if  (me->query("combat_exp") >= 1500000 
	 &&  me->query("shen") >= 10000
	 &&  me->query("max_neili") >= 5000  //考虑后面情节背个大布袋还跑的飞快，对内力有点要求。
	 &&  random(me->query("kar")) >= 20
	 &&  me->query("quest/tonglao/quest") <= me->query("combat_exp") / 1000000
	 &&  (time() - me->query("quest/tonglao/time")) > 86400
	 &&  !(me->query_temp("tonglao/pass1"))
	 &&  !(me->query("quest/tonglao/pass"))	//已经解开该quest
	 &&  random(200) > 100 ) {
		tell_object(me, YEL"你正在路上走着，忽见右首山谷中露出一点"HIY"灯火"YEL"！。\n\n"+
				"你不由得停下脚步，走过去看个究竟。\n"NOR);
	        me->add_busy(4 + random(4));
		me->move(__DIR__"shandao1",1);
		me->set_temp("tonglao/pass1",1);
		me->set_temp("tonglao/steps",j);
		me->set_temp("tonglao/step",-i);
		me->add("quest/tonglao/quest",1);
		me->set("quest/tonglao/time", time());
		log_file("quest/tonglao",sprintf("%8s%-10s通过童姥解迷第一步，经验：%d，福：%d，次数：%d。\n",
			me->name(),"("+me->query("id")+")", me->query("combat_exp"), 
			me->query("kar"), me->query("quest/tonglao/quest")), me);
		tell_room(environment(me), me->name()+"从山径走了过来。\n",  ({ me }));
		return;
        }
}
