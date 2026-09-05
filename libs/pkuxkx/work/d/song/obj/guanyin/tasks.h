//大宋任务辅助
#include <ansi.h>
int do_zheng()
{
	object me=this_player();
    object env=environment(me);
	string *tax=({"夏","秋"});
    if (!env||me->query_temp("songtasks/sansishi/task")!=4)
	return 0;
	if (me->query_temp("songtasks/sansishi/4/finish"))
	return notify_fail("你不是征税过赋税了吗？\n");
    if (me->is_busy()||me->is_fighting())
    return notify_fail("你正忙着呢。\n");
	if (env!=me->query_temp("songtasks/sansishi/task4_where"))
	return notify_fail("这里不是三司使通知的征收赋税地点啊。\n");
	me->set_temp("songtasks/sansishi/4/finish",1);
	write("你累计收到"+tax[random(2)]+"税共计"+chinese_number(10000+random(20000))+"贯，可以会三司使复命了。\n");
	return 1;
}
int do_zhao()
{
    object me=this_player();
    object env=environment(me);
    if (!env||me->query_temp("songtasks/hubu/task")!=1)
	return 0;
    if (me->is_busy()||me->is_fighting())
    return notify_fail("你正忙着呢。\n");
    if (!env->query("zhao"))
    return notify_fail("你开始仔细搜寻失落的残图，却一无所获。\n");
	if (me->query_temp("songtasks/hubu/1/finish"))
	return notify_fail("你已经找到了失落的残图，快回去复命吧。\n");
    else
    {
        tell_object(me,"你找到失落于此地的残图，仔细注释后，觉得自己可以回户部交差了。\n");
        me->set_temp("songtasks/hubu/1/finish",1);
        return 1;
    }
}
int do_qing(string arg)
{
    object me=this_player();
    object target;
    if (!me->query_temp("songtasks/libu/target"))
    return 0;
    if (me->query_temp("songtasks/libu/qinged")>2)
    return notify_fail("你已经尝试过请"+me->query_temp("songtasks/libu/targetname")+"出山了。\n");
    if (me->is_busy()||me->is_fighting())
    return notify_fail("你正忙着呢。\n");
    target=find_player(me->query_temp("songtasks/libu/target"));
    if (!target||!living(target)||base_name(environment(target))!=base_name(environment(me)))
    return notify_fail("你要请的贤士不在这里。\n");
    else
    {
        message_vision("$N对着$n深深一揖：先生可愿出山复兴我大宋？\n",me,target);
        me->set_temp("songtasks/libu/1/finish",1);
        me->add_temp("songtasks/libu/qinged",1);
        target->set_temp("songtasks/libu/theone",1);
        target->set_temp("songtasks/libu/introducer",me->query("id"));
        tell_object(me,"只要"+target->query("name")+"跟你回到临安府吏部尚书值房，必得大功一件。\n");
        tell_object(target,"看来"+me->query("name")+"真心诚意邀请你出山，如果愿意，可以随他回"+BLINK+HIC+"吏部尚书值房"+NOR+"答应(daying)大宋的邀约。\n");
        return 1;
    }
}
int do_tongzhi(string arg)
{
    object me=this_player();
    object target;
    if (!me->query_temp("songtasks/libu2/find_officer"))
    return 0;
    if (me->query_temp("songtasks/libu2/3/finish"))
    return notify_fail("你已经通知了该官员，可以回礼部复命了。\n");
    if (me->is_busy()||me->is_fighting())
    return notify_fail("你正忙着呢。\n");
    if (!arg||arg!=me->query_temp("songtasks/libu2/find_officer"))
    return notify_fail("你要通知的官员是"+me->query_temp("songtasks/libu2/find_officer")+"。请输入 tongzhi "+me->query_temp("songtasks/libu2/find_officer")+"。\n");
    if (!target=present(arg,environment(me)))
    return notify_fail(arg+"不在这里。\n");
    else
    {
        message_vision("$N对着$n拱了拱手，道：“大人该去觐见陛下了，先去礼部点个卯吧。”\n",me,target);
		message_vision("$N道：“兄弟话带到了，还有要事在身，先告辞了。”\n",me);
        me->set_temp("songtasks/libu2/3/finish",1);
        target->set_temp("song_libu2_jinjian",time());
        tell_object(target,"在五分钟内赶回礼部侍郎处，你将获得额外大宋功勋度奖励。\n");
        return 1;
    }
}
int do_yayun()
{
	object me=this_player(),env,cart;
	if (this_object()->query_temp("songtasks/gongbu/yuhen_owner")!=me)
	return 0;
	if (!this_object()->query_temp("songtasks/gongbu/yuhen_from"))
	return 0;
	if (this_object()->query_temp("songtasks/gongbu/yuhen_cart_obtain"))
	return 0;
	env=environment(me);
	if (env==this_object()->query_temp("songtasks/gongbu/yuhen_from")||(TASK_D->place_belong(env)==this_object()->query_temp("songtasks/gongbu/yuhen_from_area")&&env->query("short")==this_object()->query_temp("songtasks/gongbu/yuhen_from_short")))
	{
		cart=new("/d/song/obj/cart");
		cart->set_long(me,this_object());
		cart->move(environment(me));
		this_object()->set_temp("songtasks/gongbu/yuhen_cart_obtain",1);
		message_vision("$N来到预定的地点，发现民伕们早围在$n旁等候自己，只等自己领队(ling)前行了。\n",me,cart);
		return 1;
	}
	return 0;
}
int do_xiu()
{
	object me=this_player();
	object env=environment(me);
	if (!this_object()->query_temp("songtasks/gongbu/yingshan")||me!=this_object()->query_temp("songtasks/gongbu/yingshan_owner"))
	return 0;
	if (env->query("short")==this_object()->query_temp("songtasks/gongbu/yingshan")&&MAP_D->place_belong(env)=="临安府")
	{
		message_vision("$N指挥起随从，修缮了"+env->query("short")+"。\n",me);
		tell_object(me,HIG+"这里已经被修好了，你可以回去复命了。\n"+NOR);
		me->set_temp("songtasks/gongbu/3/finish",1);
		this_object()->delete_temp("songtasks");
	}
	else
	{
		tell_object(me,"这里似乎并不是工部尚书告诉你需要修缮的地方啊。\n");
	}
	return 1;
}

int do_look(string arg)
{
	object me=this_player();
	if (environment(me)->query("short")==this_object()->query_temp("songtasks/gongbu/yingshan")&&MAP_D->place_belong(environment(me))=="临安府")
	write(HIW+"这里似乎就是需要你修缮(xiushan)的地方了。\n\n"+NOR);
	return 0;
}
int recruit(object me)
{
	object army,env;
	if (!me||!living(me))
	return 1;
	env=environment(me);
	army=new("/d/song/obj/army_new");
	army->set_leader(me,-1,"营","刀");
	army->move(env);
	tell_room(env,"不多时，一支不算少的队伍已经招募成功。\n");
	tell_object(me,"你可以带领(lead)他们，前进(forward)回城北兵站了。\n");
	DASONG_D->multi_record(me,1,"招募新军",2);
	return 1;
}
int do_recruit()
{
	object me=this_player(),env=environment(me);
	if (me->query_temp("songtasks/"+me->query_temp("songtasks/general_recruit")+"/task")!=2)
	return 0;
	if (me->query_temp("songtasks/recruited"))
	{
		tell_object(me,"你已经开始过募兵了。\n");
		return 1;
	}
	tell_room(env,HIR+me->query("name")+HIR+"开始在这里代表大宋募兵。\n"NOR,({me}));
	tell_object(me,"你开始在这里募兵。\n");
	if (env->query("main_dir")!=me->query_temp("songtasks/"+me->query_temp("songtasks/general_recruit")+"/recruit_place"))
	{
		tell_object(me,"这里并不是让你募兵的地点，你已经延误了军机。\n");
		tell_object(me,RED"大宋任务失败！\n"NOR);
		DASONG_D->task_finish(me,-3);
		return 1;
	}
	me->add_busy(3);
	tell_object(me,"稍等等，一会可能就会有人来投军了。\n");
	me->set_temp("songtasks/recruited",1);
	call_out("recruit",2,me);
	return 1;
}
int give_substitute(object me)
{
	object pl=new("/d/song/npc/substitute");
	pl->set("owner",me);
	pl->move("/d/hangzhou/lizhengmen");
	me->set_temp("songtasks/juntou/target_type","npc");
	me->set_temp("songtasks/juntou/target",pl);
	return 1;
}
int waiting(object me)
{
	if (!me||!living(me))
	return 1;
	if (!me->query_temp("songtasks/juntou/jiejian"))
	{
		return give_substitute(me);
	}
	return 1;
}
int do_jiejian(string arg)
{
	object me=this_player(),env=environment(me),pl;
	if (me->query_temp("songtasks/juntou/target_type")!="user")
	return 0;
	if (base_name(env)!="/d/hangzhou/lizhengmen")
	{
		tell_object(me,"引见官员只能在丽正门开始。\n");
		return 1;
	}
	if (me->query_temp("songtasks/juntou/jiejian"))
	{
		tell_object(me,"你引见的官员已经出现了。\n");
		return 1;
	}
	if (!pl=me->query_temp("songtasks/juntou/target"))
	{
		return give_substitute(me);
	}
	if (!arg||arg!=pl->query("id"))
	{
		tell_object(me,"你要引见谁？\n");
		return 1;
	}
	if (!present(pl,env))
	{
		tell_object(me,pl->query("name")+"还没有到呢。\n");
		return 1;
	}
	message_vision("$N上前和$n见礼，准备一起入见官家。\n",me,pl);
	pl->set_temp("songtasks/pass_palace",1);
	pl->set_temp("songtasks/see_emperor",1);
	me->set_temp("songtasks/juntou/jiejian",1);
	return 1;
}
int do_wait()
{
	object me=this_player(),env=environment(me),pl;
	if (me->query_temp("songtasks/juntou/task")!=1)
	return 0;
	if (!objectp(me->query_temp("songtasks/juntou/target")))
	{
		tell_object(me,"你要等的人今天可能是不会来了。\n");
		return 1;
	}
	if (me->query_temp("songtasks/juntou/start_waiting"))
	{
		tell_object(me,"再等等吧。\n");
		return 1;
	}
	if (pl=present(me->query_temp("songtasks/juntou/target"),env))
	{
		if (userp(pl))
		{
			me->set_temp("songtasks/juntou/jiejian",1);
			pl->set_temp("song/pass_palace",1);
			message_vision("$N上前和$n见礼，准备一起入见官家。\n",me,pl);
			return 1;
		}
	}
	if (me->query_temp("songtasks/juntou/target_type")=="user")
	{
		me->set_temp("songtasks/juntou/start_waiting",1);
		remove_call_out("waiting");
		call_out("waiting",110,me);
	}
	return 1;
}
int prepare_yuhen(object me)
{
	object from,destination;
	int i,j,*pool=({0,1,2,3,4,5,6,7,8,9});
	string* local_c=({"扬州","镇江","苏州","福州","泉州","南昌","岳阳","江州","成都","牙山"});
	string* local_path=({"/d/city/","/d/zhenjiang/","/d/suzhou/","/d/fuzhou/","/d/quanzhou2/","/d/nanchang/","/d/yueyang/","/d/jiangzhou/","/d/chengdu/","/d/yashan/"});
	i=random(10);
	pool-=({i});
	j=pool[random(sizeof(pool))];
	while (!objectp(from) || 
          !from->isroom()||
          TASK_D->place_belong(from)=="不明区域"||
          base_name(from) == "/adm/daemons/taskd")
	{from=TASK_D->random_room(local_path[i]);}
	while (!objectp(destination) || 
          !destination->isroom()||
          TASK_D->place_belong(destination)=="不明区域"||
          base_name(destination) == "/adm/daemons/taskd")
	{destination=TASK_D->random_room(local_path[j]);}
	if (!from||!destination)
	return -1;
	this_object()->delete_temp("songtasks");
	this_object()->set_temp("songtasks/gongbu/yuhen_owner",me);
	this_object()->set_temp("songtasks/gongbu/yuhen_from",from);
	this_object()->set_temp("songtasks/gongbu/yuhen_from_area",local_c[i]);
	this_object()->set_temp("songtasks/gongbu/yuhen_from_short",from->query("short"));
	this_object()->set_temp("songtasks/gongbu/yuhen_to",destination);
	this_object()->set_temp("songtasks/gongbu/yuhen_to_area",local_c[j]);
	this_object()->set_temp("songtasks/gongbu/yuhen_to_short",destination->query("short"));
	return 1;
}

int prepare_yingshan(object me)
{
	object where=MAP_D->random_room("/d/hangzhou/");
	if (!objectp(where))
	return -1;
	this_object()->set_temp("songtasks/gongbu/yingshan_owner",me);
	this_object()->set_temp("songtasks/gongbu/yingshan",where->query("short"));
	return 1;
}

int prepare_xiongan(object me)
{
	object corpse,where=MAP_D->random_room("/d/hangzhou/");
	if (!objectp(where))
	return -1;
	corpse=new("/d/song/obj/corpse");
	corpse->set("owner",me);
	corpse->move(where);
	this_object()->set_temp("songtasks/gongbu/xiongan_where",where);
	return 1;
}

int prepare_zhuicha(object me)
{
	string* local_path=({"/d/city/","/d/zhenjiang/","/d/suzhou/","/d/fuzhou/","/d/quanzhou2/","/d/nanchang/","/d/yueyang/","/d/jiangzhou/","/d/chengdu/","/d/yashan/"});
	object where,corpse;
	while (!objectp(where) || 
	!where->isroom()||
	TASK_D->place_belong(where)=="不明区域"||
	base_name(where) == "/adm/daemons/taskd")
	where=TASK_D->random_room(local_path[random(10)]);
	if (!objectp(where))
	return -1;
	corpse=new("/d/song/npc/taofan");
	corpse->set("uni_target",me);
	corpse->set("owner",me);
	corpse->move(where);
	if (!living(corpse))
	return -1;
	this_object()->set_temp("songtasks/xingbu/taofan_area",TASK_D->place_belong(where));
	this_object()->set_temp("songtasks/xingbu/taofan_short",where->query("short"));
	corpse->info_spread();
	return 1;
}
int zhishou_over(object me)
{
	if (!me||!environment(me))
	return 1;
	if (me->query_temp("songtasks/dianqian/gate")!=environment(me)->query("short"))
	return 1;
	me->set_temp("songtasks/dianqian/2/finish",1);
	message_vision("$N值守"+environment(me)->query("short")+"完毕，和别的武将完成交接。\n",me);
	return 1;
}
int do_zhishou()
{
	object me=this_player();
	if (me->query_temp("songtasks/dianqian/task")!=2)
	return 0;
	if (!environment(me))
	return 0;
	if (me->query_temp("songtasks/dianqian/gate")!=environment(me)->query("short"))
	{
		tell_object(me,"你要在这里干什么？\n");
		return 1;
	}
	if (me->query_temp("songtasks/dianqian/gate_time"))
	{
		tell_object(me,"你已经开始值守"+me->query_temp("songtasks/dianqian/gate")+"了。\n");
		return 1;
	}
	message_vision("$N和周围的禁军将士打上招呼，开始认真守卫"+me->query_temp("songtasks/dianqian/gate")+"。\n",me);
	me->set_temp("songtasks/dianqian/gate_time",time()+30+random(30));
	call_out("zhishou_over",60,me);
	return 1;
}

int prop_target(object me,string depart)
{
	mapping the_depart,*all_depart=({
		(["depart":"tianwu","depart_name":"天武卫"]),
		(["depart":"shenwei","depart_name":"神卫"]),
		(["depart":"majun","depart_name":"马军都"]),
		(["depart":"bujun","depart_name":"步军都"]),
	});
	for (int i=0;i<sizeof(all_depart);i++)
	{
		if (all_depart[i]["depart"]==depart)
		all_depart-=({all_depart[i]});
	}
	the_depart=all_depart[random(sizeof(all_depart))];
	me->set_temp("songtasks/"+depart+"/huanfang_target",the_depart["depart"]);
	me->set_temp("songtasks/"+depart+"/huanfang_target_name",the_depart["depart_name"]);
	me->set_temp("songtasks/"+depart+"/huanfang_from",environment(me)->query("songtasks/task_myself"));
	me->set_temp("songtasks/"+depart+"/huanfang_from_name",environment(me)->query("songtasks/task_myid"));
	return 1;
}

int prop_recruit(object me,string depart)
{
	string* local_c=({"扬州","镇江","苏州","福州","泉州","南昌","岳阳","江州","成都","牙山"});
	string* local_path=({"/d/city/","/d/zhenjiang/","/d/suzhou/","/d/fuzhou/","/d/quanzhou2/","/d/nanchang/","/d/yueyang/","/d/jiangzhou/","/d/chengdu/","/d/yashan/"});
	int n;
	n=random(sizeof(local_c));
	me->set_temp("songtasks/"+depart+"/recruit_place",local_path[n]);
	me->set_temp("songtasks/"+depart+"/recruit_place_c",local_c[n]);
	me->set_temp("songtasks/general_recruit",depart);
	return 1;
}

int prop_war(object me,string depart)
{
	string *east=({"road1","shanlu1","shanlu2","shanlu3"}),
		*west1=({"xihu/duanjiaqiao","xihu/baochuta","xihu/duanqiao","xihu/gushan1"}),
		*west2=({"xihu/changqiao","xihu/baoensi","hubian","damen"}),
		*north=({"guandaon1","guandaon2",}),
		*south=({"shanlu4"}),*places=east,loc;
	object room,army;
	//bujun e majun w1 tianwu e pengri n shenwei w2 longwei s
	me->set_temp("songtasks/general_war",depart);
	if (depart=="bujun"||depart=="tianwu")
	{
		loc="东";
		places=east;
	}
	if (depart=="majun")
	{
		loc="西";
		places=west1;
	}
	if (depart=="shenwei")
	{
		loc="西";
		places=west2;
	}
	if (depart=="pengri")
	{
		loc="北";
		places=north;
	}
	if (depart=="longwei")
	{
		loc="南";
		places=south;
	}
	me->set_temp("songtasks/"+depart+"/loc",loc);
	room=load_object("/d/hangzhou/"+places[random(sizeof(places))]);
	army=new("/d/song/obj/army_robber");
	army->set("opposite_leader",me);
	army->move(room);
	me->set_temp("songtasks/"+depart+"/enemy_name",army->query("name"));
	return 1;
}

int prop_horse(object me)
{
	object horse=new("/d/song/npc/horse");
	horse->set("potential_owner",me);
	horse->move("/d/song/majun2");
	return 1;
}

int prepare_juntou(object me)
{
	object *pls,pl;
	pls=DASONG_D->song_all();
	for (int i=0;i<sizeof(pls);i++)
	{
		if (!pls[i]->get_title(TITLE_SONG1))
		{
			continue;
			pls-=({pls[i]});
		}
		if (pls[i]->query("song/pro")!="武")
		{
			continue;
			pls-=({pls[i]});
		}
		if (!sizeof(pls))
		break;
		if (strsrch(pls[i]->get_title(TITLE_SONG1),"殿前")==-1
			&&strsrch(pls[i]->get_title(TITLE_SONG1),"马军")==-1
			&&strsrch(pls[i]->get_title(TITLE_SONG1),"步军")==-1
			&&strsrch(pls[i]->get_title(TITLE_SONG1),"捧日")==-1
			&&strsrch(pls[i]->get_title(TITLE_SONG1),"天武")==-1
			&&strsrch(pls[i]->get_title(TITLE_SONG1),"神卫")==-1
			&&strsrch(pls[i]->get_title(TITLE_SONG1),"龙卫")==-1)
		pls-=({pls[i]});
	}
	if (!sizeof(pls))
	{
		return give_substitute(me);
	}
	else
	{
		pl=pls[random(sizeof(pls))];
		tell_object(pl,BLINK+HIW+"官家要接见你，速去丽正门等候吧。\n"+NOR);
		tell_object(pl,"如果两分钟内无法赶到，接见将取消。\n");
		me->set_temp("songtasks/juntou/target",pl);
		me->set_temp("songtasks/juntou/target_type","user");
	}
	return 1;
}
