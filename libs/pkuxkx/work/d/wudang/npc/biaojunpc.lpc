// bj

inherit NPC;
#include <ansi.h>
inherit F_ESCORT;
mapping *escort_info=
({(["area":"/d/xiangyang/dangpu", "short":"襄阳当铺", "id":"shi chunqiu", "name":"史春秋"]),
	(["area":"/d/village/smithy1", "short":"华山村铁匠铺", "id":"feng", "name":"冯铁匠"]),
	(["area":"/d/luoyang/qianzhuang", "short":"洛阳四海钱庄", "id":"hu xueyuan", "name":"胡雪源"]),
	(["area":"/d/wudang/sanqing", "short":"武当三清殿", "id":"guxu daozhang", "name":"谷虚道长"]),
	(["area":"/d/quanzhen/tianzjt", "short":"全真天尊讲经堂", "id":"hao datong", "name":"郝大通"]),
  (["area":"/d/huashan/bieyuan", "short":"华山别院", "id":"feng buping", "name":"封不平"]),
  (["area":"/d/changan/biaoju", "short":"长安飞马镖局", "id":"ma xingkong", "name":"马行空"]),
  (["area":"/d/city/zuixianlou2", "short":"扬州醉仙楼", "id":"xian laoban", "name":"冼老板"]),
  (["area":"/d/qufu/kongfu", "short":"曲阜孔府", "id":"kong qiao", "name":"孔翘"]),
  (["area":"/d/shaolin/fxjing", "short":"少林佛心井", "id":"jueyuan dashi", "name":"觉远大师"])});

string do_escort();
string do_give();
string do_fail();
int ask_title();
int ask_query();

void create()
{
        set_name("张志",({ "zhang zhi", "zhang", "zhi" }) );
        set("gender", "男性" );
        set("title",HIC"荆西镖局 "+NOR+"署理总镖头"+NOR);
        set("age", 20+random(10));
        set("long", "这是个内家高手，一看就不好惹。\n");
		set("str", 10);
        set("dex", 1);
        set("con", 1);
        set("int", 1);
		set("shen_type", 1);
        set_temp("apply/defense", 10);
        set("combat_exp", 1);
        set("attitude", "peaceful");
        set_skill("sword", 250);
        set_skill("parry",250);
        set_skill("dodge", 250);
        set_skill("force",250);
        set_skill("literate",250);
        set_skill("taiyi-zhang",250);
        set_skill("strike",250);
        set_skill("taiyi-jian",250);
        set_skill("taiyi-shengong",250);
        set_skill("taiyi-you",250);
        

        map_skill("parry","taiyi-zhang");
        map_skill("sword","taiyi-jian");
        map_skill("force","taiyi-shengong");
        map_skill("dodge","taiyi-you");
        map_skill("strike","taiyi-zhang");

	set("inquiry", ([
    "押镖": (:do_escort:),
    "job": (:do_escort:),
    "完成": (:do_give:),
    "query" : (: ask_query :),       
    "finish": (:do_give:),
    "放弃":(:do_fail:),
    "fail":(:do_fail:),
    "头衔":(:ask_title:)
   ]) );
        
        prepare_skill("strike","taiyi-zhang");
        setup();
        add_money("silver", 20+random(8)*10);
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_getesc","getesc");
	add_action("do_listesc", "listesc");
}

int do_getesc(string serial)
{
	int sno;
	
  if ( !serial||!sscanf(serial,"%d",sno) )
  {
  	write("输入命令格式：getesc 任务序号。\n");
  	return 1;
  }
  
  return get_dart_fb("wudang", this_player(), escort_info, sno);
}

int do_listesc()
{
	object ob;
	string msg;
	
	if ( !(ob=find_object("/quest/escort/escort_board")) )
		ob=load_object("/quest/escort/escort_board");
	
	msg=ob->show_list("wudang", escort_info);
	tell_object(this_player(), msg);
	return 1;
}

string do_escort()
{
//	if ( !wizardp(this_player()) )
//		return "本功能暂时只接受wizard级别的玩家。\n";
	
	return get_dart("wudang", this_player(), escort_info);
}

string do_give()
{
//	if ( !wizardp(this_player()) )
//		return "本功能暂时只接受wizard级别的玩家。\n";
	
  return give_reward(this_player());
}

string do_fail()
{
//	if ( !wizardp(this_player()) )
//		return "本功能暂时只接受wizard级别的玩家。\n";
	
  return quest_fail(this_player()); 
}

int ask_title()
{
	return escort_rank("荆西镖局");
}

int ask_query()
{	
	object ob=this_object();
	object me=this_player();
	int hbexp;
	hbexp=me->query("yunbiao/exp/zhang zhi");

	if (!hbexp)
	        command("whisper "+me->query("id")+" 你没有在本镖局完成过护镖任务。");
    	else
    	        command("whisper "+me->query("id")+" 你在本镖局护镖任务中已获得了"+sprintf("%d",hbexp)+"点经验。");
	return 1;
}

int accept_object(object me, object caiwu)
{
  object ob=this_object();

	if( caiwu->query("letterback")==5&&caiwu->query("owner")==me->query("id"))
  {
    call_out("destletter", 1, caiwu);
    message_vision("$N接过$n手里的家信，感动的热泪盈眶：这是老婆写给我的信，我，我不会亏待你的！",this_object(),me);
	  me->set_temp("extrajob/"+ob->query("id"),1);
    return 1;
  }
  
  if ( check_add_quest(me,caiwu) )
  	return 1;

  if (ob->is_busy())
  	return notify_fail(ob->query("name")+"正忙着呢！\n");

  if (caiwu->query("id")=="mixin" &&
  	  caiwu->query("owner")==me->query("id") &&
  	  caiwu->query("from_id")==ob->query("id") )
  {
    return restart_add_quest(me,caiwu);
  }
  else
  {
    return notify_fail(ob->query("name")+"一言不发，默默看着你。\n");
  }
}

void unconcious()
{
  die();
}

void die()
{
	object ob=this_object();
	ob->remove_all_killer();
	ob->set("eff_qi",100);
	ob->set("qi",100);
	ob->set("eff_jing",100);
	ob->set("jing",100);
}