// design by 发现号(find) . all right reserved.

// grand_li.c

#include <ansi.h>

inherit NPC;

string *make_msg = ({
	HIC "大营的石阵是上一任军师带着我们修造起来的，那时我还是个小伙子，\n" NOR,
	HIC "石阵是个乌龟的形状，象征我们边关大营铁打的营盘，万年不坏。\n" NOR,
	HIC "乌龟尾巴就是阵的入口，四条腿是阵内的路线，走法嘛，是右左？是左右？\n" NOR,
	HIC "年纪大了，也记不清了，不过乌龟的右爪子好象很重要。\n" NOR,
});

string ask_zhen(object who);

void create()
{
	set_name("李大爷", ({ "grand li","li"}) );
	set("gender", "男性" );
	set("age", 68);
	set("long",
		"李大爷是这一带有名的工匠，听说还擅长机关埋伏。\n");
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("inquiry", ([
		"石阵" : (: ask_zhen :),
	]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int relay_say(object who,string arg)
{
	object env,*inv;
	int i;
	string name,gender;

	if(who->name() == "小孙孙" && arg == "爷爷！刘家姐姐送我的小鸟跑了，爷爷再给我弄一只！")
	{
	command("sigh");
	command("say 爷爷都这个岁数了，到哪去给你抓小鸟呀。");
	}
	else if(who->name() == "小孙孙" && arg == "哎呀，这真是一只小鸟呀！太好了！咯咯...")
	{
	env = environment(this_object());
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++)
		{
		if(inv[i]->query_temp("gongjiang/bird")) {
			name = inv[i]->name();
			if(inv[i]->query("gender") == "男性")
			gender = (inv[i]->query("age")<=29)? "大哥哥" : "叔叔";
			else gender = (inv[i]->query("age")<=29)? "大姐姐" : "阿姨";
			}
		}
	command("say 快谢谢这位"+name+gender+"。");
	tell_object(env,CYN "小孙孙说道：谢谢！\n" NOR);
	}
	return 1;
}

string ask_zhen(object who)
{
	object me = this_player();
	if(!me->query_temp("gongjiang/bird")) return "没听说过。";
	else
	{
	call_out( "make_stage", 1, me, 0 );
	me->delete_temp("gongjiang");
	return "那是很早以前的事了。";
	}
}

void make_stage(object me, int stage)
{
     tell_object(me, make_msg[stage]);
     if( ++stage < sizeof(make_msg) ) {
         call_out( "make_stage", 1, me, stage );
         return;
     } else
    return;
}