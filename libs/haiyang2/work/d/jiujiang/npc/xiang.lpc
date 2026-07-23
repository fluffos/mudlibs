
inherit NPC;
#include <ansi.h>

string give_job();
int do_ok(string arg);
void create()
{
   set_name("香玉山",({ "xiang yushan","xiang","yushan" }) );
        set("gender", "男性" );
        set("age", 25);
   set("long", "他是[巴陵帮]的香玉山。\n");
       
   set("combat_exp", 80000);
   set("str", 10);
   set("per", 25);
   set_skill("parry",30);
   set_skill("unarmed",30);
   set_skill("dodge",30);
   set("force",200);
   set("max_neili",200);
   set_skill("force",30);
   set("attitude", "peaceful");
   set("inquiry",([
	   "贩卖人口":(:give_job:),
	   ]));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
}

void init()
{
	add_action("do_ok","jiaochai");
}

string give_job()
{
	object me;
	me=this_player();
	if(me->query("gender")=="女性")
		return "这种工作女人做不来的！\n";
	if(me->query_temp("fanmai_job"))
		return "这种事还是一件一件做吧！\n";
	if(time()-me->query("task_time")<=130+random(5))
		return "你先歇歇吧！\n";
	me->set_temp("fanmai_job",1);
	return "好吧,既然"+RANK_D->query_respect(me)+"愿意，你就找一个漂亮的姑娘来(jiaochai)给我\n，我不会亏待你的！\n";
}

int do_ok(string arg)
{
	object me,ob,money;
	int exp,pot,sil,famous;int i,per;
	me=this_player();i=0;
	if(!arg) return notify_fail("你拿什么来交差？\n");
	if(!me->query_temp("fanmai_job")&&me->query("vocation")!="人贩子")
		return notify_fail("这话从何说起？\n");
	if(!objectp(ob=present(arg,environment(me))))
		return notify_fail("这里没有这个人！\n");
	if(ob->query("gender")=="男性")
		return notify_fail("男人可不要！\n");

	if(userp(ob))
		return notify_fail("玩家可不要！\n");

    if(ob->query("per")<=25&&me->query("vocation")!="人贩子")
		return notify_fail("这个人的姿色不够我的要求，你还是换一个吧！\n");
	per=ob->query("per");
	i=per;

	exp=random(1888);
    while(exp>10)
	{ exp=exp/10; i++;}
	exp=exp+i*10;
	pot=exp*2/3;
	sil=exp/3;
	per=ob->query("per");
    tell_object(environment(me),"香玉山回头道：来人，把这位姑娘领进去！\n");
	tell_object(environment(me),"立刻出来一个人，把"+ob->name()+"领进去了。\n");
	destruct(ob);
	if(me->query_temp("fanmai_job"))
	{
        sil=random(888)+(i*20);
	me->add("deposit",sil);
	me->add("combat_exp",exp);
	me->add("potential",pot);
	me->start_busy(8);
	me->delete_temp("fanmai_job");
	me->set("task_time",time());
	tell_object(me,"在这次行动中你得到了"+
                ""HIW""+chinese_number(exp)+""NOR""+"点经验值"+
                ""HIW""+chinese_number(pot)+""NOR""+"点潜能"+
                "香玉山奖励了你"+""HIW""+chinese_number(sil)+""NOR""+"文铜钱。\n");
        tell_object(me,"你钱庄的存款增加了！\n");
	tell_object(me,"由于贩卖人口，你的江湖声望降低了！\n");
	}
	else
	{
		tell_object(me,"香玉山笑道：好，你继续努力吧！\n");
	}
	return 1;
}
