inherit ARMY;
#include <ansi.h>
string *db_places=({"/d/song/pengriwei","/d/song/tianwuwei","/d/song/shenwei","/d/song/majun","/d/song/bujun","/d/song/dianqiansi"});
void create()
{	
	set_name("大宋军队", ({ "dasong jundui","jun dui","dui"}));
	set_weight(5000000);
	set("long", "这里是大宋的军队。\n");
	set("material", "steal");
	set("unit", "支");
	set("value", 0);
    set("no_give",1);
    set("no_drop",1);
    set("no_put",1);
    set("no_get",1);
    set("shiqi",50);//士气
    set("junji",50);//军纪
    set("train_degree",50);//训练度
    set("fighters",1000); //默认1000人队伍
    set("liang",100000);//默认100000粮，大约够吃30分钟
    set("xiang",100000);//默认100000军饷，大约够用30分钟
    set("side","song");//边
    set("weapon","刀");//武器
    slogans=({HIW"殿前都"NOR,HIR"步军都"NOR,HIC"马军都"NOR,HIB"天武卫"NOR,HIM"捧日卫"NOR,HIY"神卫"NOR,YEL"龙卫"NOR,});//番号，大明和其他部队最好不同
    slogan_ids=({"dianqian du","bujun du","majun du","tianwu wei","pengri wei","shen wei","long wei",});
	setup();
    call_out("check",1);
    call_out("set_army",1);
}
int mark(string place)
{
	object me;
	string *list=({}),*places=({"/d/hangzhou/palace/heningnei","/d/hangzhou/heningmen","/d/hangzhou/wall1","/d/hangzhou/wall2","/d/hangzhou/walla","/d/hangzhou/wallb","/d/hangzhou/lizhengmen"});
	if (!this_object()->query("follow")||!userp(this_object()->query("follow")))
	return 1;
	me=this_object()->query("follow");
	if (me->query_temp("songtasks/dianqian/task")==3)
	{
		if (arrayp(me->query_temp("songtasks/dianqian/place_escort")))
		list=me->query_temp("songtasks/dianqian/place_escort");
		if (member_array(place,places)!=-1)
		if (member_array(place,list)==-1)
		list+=({place});
		me->set_temp("songtasks/dianqian/place_escort",list);
		if (place=="/d/hangzhou/palace/heningnei")
		environment()->check_army(me);
		return 1;
	}
	if (member_array(place,db_places)!=-1)
	return environment()->check_army(me);
	return 1;
}
void init()
{
	string *places=({"/d/hangzhou/palace/heningnei","/d/hangzhou/heningmen","/d/hangzhou/wall1","/d/hangzhou/wall2","/d/hangzhou/walla","/d/hangzhou/wallb","/d/hangzhou/lizhengmen"});
	add_action("do_tingzhu","tingzhu");
	add_action("do_jixing","jixing");
	if (member_array(base_name(environment()),places)!=-1||member_array(base_name(environment()),db_places)!=-1)
	{
		mark(base_name(environment()));
	}
	::init();
}

int do_tingzhu()
{
	object army,me=this_player(),env;
	if (check_available_army(me)==-1)
	return 0;
	if (me->query_temp("songtasks/dianqian/task")!=3)
	return 0;
	army=me->query_temp("ARMY");
	env=environment(me);
	tell_room(env,me->name()+"传令下去，令"+army->query("name")+"在"+env->query("short")+"停驻休息。\n");
	if (!env->query_temp("songtasks/tingzhu/"+me->query("id"))&&me->query("songtasks/dianqian/task")==3&&!me->query_temp("songtasks/dianqian/tingzhu"))
	{
		tell_object(me,"你选错了停驻地点，任务失败。"+army->query("name")+"由营副带队回到驻地。\n");
		destruct(army);
	}
	me->set_temp("songtasks/dianqian/tingzhu",1);
	env->delete_temp("songtasks/tingzhu/"+me->query("id"));
	return 1;
}

int do_jixing()
{
	object army,me=this_player(),env;
	if (check_available_army(me)==-1)
	return 0;
	if (me->query_temp("songtasks/dianqian/task")!=3)
	return 0;
	army=me->query_temp("ARMY");
	env=environment(me);
	if (!present(army,env))
	return 0;
	if (army->query("jixing"))
	{
		tell_object(me,army->query("name")+"正处在疾行的状态。\n");
		return 1;
	}
	tell_room(env,me->name()+"传令下去，令"+army->query("name")+"在"+env->query("short")+"准备疾行军。\n");
	if (!env->query_temp("songtasks/jixing/"+me->query("id"))&&me->query("songtasks/dianqian/task")==3&&!me->query_temp("songtasks/dianqian/jixing"))
	{
		tell_object(me,"你选错了疾行军起点，任务失败。"+army->query("name")+"由营副带队回到驻地。\n");
		destruct(army);
	}
	army->set("jixing",1);
	army->add("move_ability",-(2+random(3)));
	me->set_temp("songtasks/dianqian/jixing",1);
	env->delete_temp("songtasks/jixing/"+me->query("id"));
	return 1;
}
int dest()
{
	tell_room(environment(),this_object()->query("name")+"回营休整了。\n");
	destruct(this_object());
	return 1;
}
int huanfang(string place)
{
	int n;
	string *hao=({"甲","乙","丙","丁","戊","己","庚","辛"});
	place=replace_string(place,"驻地","");
	for (int i=0;i<sizeof(slogans);i++)
	{
		if (strsrch(slogans[i],place)!=-1)
		{
			n=i;
			break;
		}
	}
	set_name(slogans[n]+hao[random(sizeof(hao))]+"营",({slogan_ids[n]+" ying","army","ying"}));
	tell_room(environment(),"换防完成，新军编成"+this_object()->query("name")+"。\n");
	call_out("dest",5+random(4));
}

int do_forward(object ob,object me,string arg)
{
	mixed *indexs;
	object rm;
	if (!me->query("song/pro"))
	return ::do_forward(ob,me,arg);
	if (environment()->query("dirs_to_song")&&mapp(environment()->query("dirs_to_song")))
	{
		indexs=values(environment()->query("dirs_to_song"));
		for (int i=0;i<sizeof(indexs);i++)
		{
			if (stringp(indexs[i][1])&&indexs[i][1]+"面"==arg&&rm=load_object("/d/song/"+indexs[i][0]))
			{
				tell_room(environment(),me->name()+"率领着"+this_object()->query("name")+"向"+rm->query("short")+"进发过去。\n");
				tell_room(rm,me->name()+"率领着"+this_object()->query("name")+"向这里进发过来。\n");
				me->move(rm);
				this_object()->move(rm);
				return 1;
			}
		}
	}
	return ::do_forward(ob,me,arg);
}