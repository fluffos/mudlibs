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
    slogans=({"新兵营",});//番号，大明和其他部队最好不同
    slogan_ids=({"xinbing",});
	setup();
    call_out("check",1);
    call_out("set_army",1);
}
int mark(string place)
{
	object me;
	if (!this_object()->query("follow")||!userp(this_object()->query("follow")))
	return 1;
	me=this_object()->query("follow");
	if (me->query_temp("songtasks/"+me->query_temp("songtasks/general_recruit")+"/task")==2&&me->query_temp("songtasks/recruited"))
	{
		me->set_temp("songtasks/"+me->query_temp("songtasks/general_recruit")+"/2/finish",1);
		tell_object(me,"新兵在你的率领下回到城北军营，你也可以回去复命了。\n");
		call_out("dest",2);
	}
	return 1;
}
void init()
{
	string *places=({"/d/song/bingzhan"});
	if (member_array(base_name(environment()),places)!=-1)
	{
		mark(base_name(environment()));
	}
	::init();
}

int dest()
{
	tell_room(environment(),this_object()->query("name")+"回营休整了。\n");
	destruct(this_object());
	return 1;
}

int do_forward(object ob,object me,string arg)
{
	mixed *indexs;
	object rm;
	this_object()->set("move_ability",-(5+random(2)));
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