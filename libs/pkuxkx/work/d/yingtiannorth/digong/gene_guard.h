int test()
{
	return 1;
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
	int num;
	string *families=keys(party),family=families[random(sizeof(families))],family_name=party[family];
	string *id_list=load_object(__DIR__"level1entry")->query("id_list");
	ob = filter_array(children(USER_OB), (: userp :));
	ob = filter_array(ob, (: environment :));
	ob = filter_array(ob, (: $1->query("family/family_name") == $2 :),family_name );
	if (sizeof(id_list)>0)
	{
		for (int i=0;i<sizeof(id_list);i++)
		if (user=find_player(id_list[i]))
		{
			if (environment(user)->query("level")&&member_array(user,ob)!=-1)
			ob-=({user});
		}
	}
	if (this_object()->query("path")<4)
	num=2;
	else if (this_object()->query("path")<8)
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
		guard->copy(me,user,family);
		guard->move(this_object());
		guard->attempt_kill(me);
	}
	this_object()->set("guard_generated",1);
}
void init()
{
	if (!this_object()->query("guard_generated")&&userp(this_player()))
	gene_guard(this_player());
	::init();
}
int transferCreditToBonus(object me)
{
	int basic_folds,folds=1,exp,pot,rep;
	if (me->query("karma/credit")<1) return 1;
	ANTIROBOT_D->same_as_fullme(me);
	me->fullme();
	tell_object(me,HIG+"你精神突然一振，全身体力像是全部恢复了。\n"+NOR);
	if (me->query("combat_exp")<50000000) basic_folds=5;
	else if (me->query("combat_exp")<100000000) basic_folds=7;
	else if (me->query("combat_exp")<400000000) basic_folds=9;
	else basic_folds=12;
	exp=me->query("karma/credit")*basic_folds*folds;
	exp=exp*4/5+random(exp/5);
	pot=exp/2+random(exp/5);
	rep=pot/2+random(pot/5);
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->add("repute",rep);
	me->add("story_credit",1);
	me->set("karma/credit",0);
	me->add_temp("karma/exp_gained",exp);
	me->add_temp("karma/pot_gained",pot);
	me->add_temp("karma/rep_gained",rep);
	tell_object(me,BCYN+HIW+"此次倒浮屠闯关，对你的武学修为颇有助益。\n你获得了："+exp+"点经验，"+pot+"点潜能，"+rep+"点声望以及1点江湖历练。\n"+NOR);
	me->delete_temp("karma");
	return 1;
}
int valid_leave(object me,string dir)
{
	mixed *info;
	object ob=this_object();
	if (ob->query("exits/"+dir))
	{
		if (load_object(ob->query("exits/"+dir))->query("max_user")&&load_object(ob->query("exits/"+dir))->query("challenger")&&
		load_object(ob->query("exits/"+dir))->query("challenger")!=me)
		return notify_fail(WHT"下一关必须被"+load_object(ob->query("exits/"+dir))->query("challenger")->query("name")+"所破。\n"NOR);
		if (ob->query("max_user"))
		return notify_fail(WHT"地宫守卫还在呢，你跑不掉的。\n"NOR);
		if (dir=="out"&&ob->query("level")==7)
		{
			info=filter_array(call_out_info(), (: $1[1]==$2 :), "clear_all_rooms");
			if (sizeof(info)<1)
			load_object("/d/yingtiannorth/qlsi2")->Over_Karma(me);
			transferCreditToBonus(me);
			return ::valid_leave(me,dir);
		}
		if (load_object(ob->query("exits/"+dir))->query("max_user")&&load_object(ob->query("exits/"+dir))->query("path")>ob->query("path")
		&&me->query_temp("karma/level7/challenge")&&me->query_temp("karma/level7/challenge")+3>=load_object(ob->query("exits/"+dir))->query("path")&&
		load_object(ob->query("exits/"+dir))->query("challenger")!=me)
		return notify_fail(WHT"第七层你也不能包打天下啊，让别人也出手试试。\n"NOR);
		if (load_object(ob->query("exits/"+dir))->query("max_user"))
		{
			me->set_temp("karma/level7/challenge",load_object(ob->query("exits/"+dir))->query("path"));
			load_object(ob->query("exits/"+dir))->set("challenger",me);
		}
		return ::valid_leave(me,dir);
	}
	return ::valid_leave(me,dir);
}