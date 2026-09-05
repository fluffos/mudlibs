int dest()
{
	if (this_object())
	destruct(this_object());
}
void destroy_Fortress()
{
	object room=this_object(),*inv=all_inventory(room);
	inv=filter(inv,(:userp:));
	if (sizeof(inv)>0)
	{
		for (int i=0;i<sizeof(inv);i++)
		{
			tell_object(inv[i],HIR+"这时鸡笼山山寨突然燃起了大火，大家都撤出了山寨。\n"+NOR);
			inv[i]->move(__DIR__"jilong");
			inv[i]->delete_temp("OustBandit");
		}
	}
	if (query("NEXT_ROOM")&&objectp(query("NEXT_ROOM")))
	query("NEXT_ROOM")->destroy_Fortress();
	call_out("dest",1);
	return;
}
void Gen(object ob,int size)
{
	int size_Limit;
	object room,cur=this_object();
	string dir;
	mapping dirs=(["southup":"northdown","northup":"southdown","westup":"eastdown","eastup":"westdown"]);
	size_Limit=size*3+random(size);
	ob->set("NEXT_ROOM",cur);
	cur->set("room_id",ob->query("room_id")+1);
	if (cur->query("room_id")==1)
	call_out("destroy_Fortress",600);
	if (cur->query("room_id")>=size_Limit)
	{
		cur->set("finish_Line",1);
		cur->delete("max_user");
		return;
	}
	room=new(__DIR__"jilong_shijie");
	dir=keys(dirs)[random(4)];
	cur->set("exits/"+dir,room);
	room->set("exits/"+dirs[dir],cur);
	room->Gen(cur,size);
	return;
}
int gene_guard(object me)
{
	object guard,*ob,user;
	mapping party=([
	"shaolin":	"少林派",
	"wudang":	"武当派",
	"gaibang":	"丐帮",
	"baituo":	"白驼山",
	"xingxiu":	"星宿派",
	"huashan":	"华山派",
	"emei":		"峨嵋派",
	"mingjiao":	"明教",
	"riyue":	"日月神教",
	"gumu":		"古墓派",
	"lingjiu":	"灵鹫宫",
	"quanzhen":	"全真派",
	"tianlong":	"天龙寺",
	"taohua":	"桃花岛",
	"murong":	"姑苏慕容",
	"chaoting":	"朝廷",
	"tiandihui":	"天地会",
	"shenlong":	"神龙教",
	"dalunsi":	"大轮寺",
	"xueshan":	"雪山派",]);
	int num,leader=1;
	string *families=keys(party),family=families[random(sizeof(families))],family_name=party[family];
	object *Local_Users=me->query_temp("OustBandit/team");
	ob = filter_array(children(USER_OB), (: userp :));
	ob = filter_array(ob, (: environment :));
	ob = filter_array(ob, (: $1->query("family/family_name") == $2 :),family_name );
	if (Local_Users&&arrayp(Local_Users)&&sizeof(Local_Users)>0)
	{
		for (int i=0;i<sizeof(Local_Users);i++)
		if (environment(Local_Users[i])->query("OUST_FORTRESS")&&member_array(Local_Users[i],ob)!=-1)
			ob-=({Local_Users[i]});
	}
	if (this_object()->query("finish_Line"))
	num=6;
	else if (this_object()->query("room_id")<4)
	num=2;
	else if (this_object()->query("room_id")<8)
	num=3;
	else
	num=4;
	for (int i=0;i<num;i++)
	{
		guard=new(__DIR__"npc/guard");
		if (sizeof(ob)>1)
		{
			user=ob[random(sizeof(ob))];
			ob-=({user});
		}
		else
		user=0;
		if (this_object()->query("finish_Line")&&leader)
		{
			guard->set("Leader",1);
			leader=0;
		}
		guard->copy(me,user,family,this_object()->query("room_id"));
		guard->move(this_object());
		guard->attempt_kill(me);
	}
}
void init()
{
	object me=this_player(),ob=this_object();
	if (userp(me))
	{
		me->listen_to_die(ob);
		if (!ob->query("guard_generated"))
		{
			ob->set("guard_generated",1);
			gene_guard(me);
		}
	}
}

int valid_leave(object me,string dir)
{
	mixed *info;
	object ob=this_object();
	int size=me->query_temp("OustBandit/size")-1;
	if (ob->query("exits/"+dir))
	{
		if (size<2) size=2;
		if (ob->query("exits/"+dir)->query("max_user")&&ob->query("exits/"+dir)->query("challenger")&&
		ob->query("exits/"+dir)->query("challenger")!=me&&!ob->query("exits/"+dir)->query("finish_Line"))
		return notify_fail(RED"下一关必须被"+ob->query("exits/"+dir)->query("challenger")->query("name")+RED+"所破。\n"NOR);
		if (ob->query("max_user"))
		return notify_fail(RED"山寨中山贼还活着呢，你跑不了。\n"NOR);
		if (ob->query("exits/"+dir)->query("max_user")&&ob->query("exits/"+dir)->query("room_id")>ob->query("room_id")
		&&me->query_temp("OustBandit/challenge")&&me->query_temp("OustBandit/challenge")+size>=ob->query("exits/"+dir)->query("room_id")
		&&ob->query("exits/"+dir)->query("challenger")!=me&&!ob->query("exits/"+dir)->query("finish_Line"))
		return notify_fail(RED"清剿山寨任务最忌抢功，你让别人也出手试试。\n"NOR);
		if (ob->query("exits/"+dir)->query("max_user"))
		{
			me->set_temp("OustBandit/challenge",ob->query("exits/"+dir)->query("room_id"));
			ob->query("exits/"+dir)->set("challenger",me);
		}
		if (userp(me))
		me->remove_listen_to_die(this_object());  
		return ::valid_leave(me,dir);
	}
	return ::valid_leave(me,dir);
}
int die_notify(object victim)
{
    if(!objectp(victim) || !userp(victim)) return 0;
    if(!environment(victim)->query("OUST_FORTRESS"))
    {
        victim->remove_listen_to_die(this_object());        
    }
    else
    {
		victim->set("eff_qi",10);
		victim->set("qi",10);
		victim->set("eff_jing",10);
		victim->set("jing",10);
		victim->set("neili",victim->query("max_neili")>1000?1000:victim->query("max_neili"));
		victim->set("jingli",victim->query("max_jingli")>1000?1000:victim->query("max_jingli"));
		if (victim->query_temp("OustBandit/Origin")&&victim->query_temp("OustBandit/Origin")->isroom())
		victim->move(victim->query_temp("OustBandit/Origin"));
		else
		victim->move(__DIR__"fortress_entry");
		tell_object(victim,BLINK+HIR+"你受到了严重的伤害，被队友们送回了安全点，开始紧急治疗……\n"+NOR);
    }
    return 486;
}