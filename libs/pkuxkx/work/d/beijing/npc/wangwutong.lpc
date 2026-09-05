//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

#include <ansi.h>
inherit NPC;
inherit F_ESCORT;
mapping *escort_info=
({(["area":"/d/beijing/quanjude2", "short":"北京全聚德", "id":"wu liuqi", "name":"吴六奇"]),
  (["area":"/d/jinyang/xiaofu", "short":"晋阳萧府", "id":"xiao banhe", "name":"萧半和"]),
  (["area":"/d/saiwai/weststreet", "short":"张家口西市", "id":"pihuo shangren", "name":"皮货商人"]),
  (["area":"/d/changan/biaoju", "short":"长安飞马镖局", "id":"ma xingkong", "name":"马行空"]),
  (["area":"/d/xiangyang/dangpu", "short":"襄阳当铺", "id":"shi chunqiu", "name":"史春秋"]),
	(["area":"/d/lingzhou/jiuguan", "short":"灵州酒馆", "id":"xixia mingshang", "name":"西夏名商"]),
	(["area":"/d/village/smithy1", "short":"华山村铁匠铺", "id":"feng", "name":"冯铁匠"]),
	(["area":"/d/luoyang/qianzhuang", "short":"洛阳四海钱庄", "id":"hu xueyuan", "name":"胡雪源"]),
	(["area":"/d/wudang/biaoju", "short":"武当荆西镖局", "id":"zhang zhi", "name":"张志"]),
	(["area":"/d/quanzhen/tianzjt", "short":"全真天尊讲经堂", "id":"hao datong", "name":"郝大通"]),
  (["area":"/d/huashan/bieyuan", "short":"华山别院", "id":"feng buping", "name":"封不平"]),
  (["area":"/d/jinyang/xiaofu", "short":"晋阳萧府", "id":"xiao banhe", "name":"萧半和"]),
  (["area":"/d/city/zuixianlou2", "short":"扬州醉仙楼", "id":"xian laoban", "name":"冼老板"]),
  (["area":"/d/qufu/kongfu", "short":"曲阜孔府", "id":"kong qiao", "name":"孔翘"])});

string do_escort();
string do_give();
string do_fail();
int ask_title();

void create()
{
	set_name("王武通", ({
		"wang wutong",
		"wutong",
		"wang",
	}));
	set("title", "武胜镖局总镖头");
	set("nickname", "金枪无敌");
	set("long",
		"他是一个神态威猛的汉子，是京城最大镖局武胜镖局的总镖头。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 35);
	set("shen_type",0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 800);
	set("max_neili", 800);
	set("combat_exp", 200000);
	set("score", 100);
	

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("cuff", 100);
	set_skill("claw",100);
	set_skill("strike",100);
	set_skill("unarmed",100);
	set_skill("parry", 100);
	set_skill("spear",100);

	set("inquiry", ([
    "押镖": (:do_escort:),
    "job": (:do_escort:),
    "完成": (:do_give:),
    "finish": (:do_give:),
    "放弃":(:do_fail:),
    "fail":(:do_fail:),
    "头衔":(:ask_title:)
   ]) );
   	
/*
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "luohan-quan");
	map_skill("blade", "cibei-dao");
*/
	set("shen_type",1);set("score",500);setup();

	carry_object("/d/shaolin/obj/yaodai")->wear();
	carry_object("/clone/armor/jinzhuang")->wear();
	carry_object("/clone/weapon/changqiang")->wield();
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
  
  return get_dart_fb("beijing", this_player(), escort_info, sno);
}

int do_listesc()
{
	object ob;
	string msg;
	
	if ( !(ob=find_object("/quest/escort/escort_board")) )
		ob=load_object("/quest/escort/escort_board");
	
	msg=ob->show_list("beijing", escort_info);
	tell_object(this_player(), msg);
	return 1;
}

string do_escort()
{
//	if ( !wizardp(this_player()) )
//		return "本功能暂时只接受wizard级别的玩家。\n";
	
	return get_dart("beijing", this_player(), escort_info);
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
	return escort_rank("武胜镖局");
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