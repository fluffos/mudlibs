// linzhennan.c 都大锦
// modified by Jay 4/7/96
// Modified by iszt@pkuxkx, 2007-03-03
// Modified by whuan@pkuxkx 2007-8-20

#include <ansi.h>

inherit NPC;
inherit F_ESCORT;
mapping *escort_info=
({(["area":"/d/xiangyang/dangpu", "short":"襄阳当铺", "id":"shi chunqiu", "name":"史春秋"]),
	(["area":"/d/lingzhou/jiuguan", "short":"灵州酒馆", "id":"xixia mingshang", "name":"西夏名商"]),
	(["area":"/d/village/smithy1", "short":"华山村铁匠铺", "id":"feng", "name":"冯铁匠"]),
	(["area":"/d/luoyang/qianzhuang", "short":"洛阳四海钱庄", "id":"hu xueyuan", "name":"胡雪源"]),
	(["area":"/d/wudang/biaoju", "short":"武当荆西镖局", "id":"zhang zhi", "name":"张志"]),
	(["area":"/d/quanzhen/tianzjt", "short":"全真天尊讲经堂", "id":"hao datong", "name":"郝大通"]),
  (["area":"/d/huashan/bieyuan", "short":"华山别院", "id":"feng buping", "name":"封不平"]),
  (["area":"/d/jinyang/xiaofu", "short":"晋阳萧府", "id":"xiao banhe", "name":"萧半和"]),
  (["area":"/d/dalunsi/laifu", "short":"赞普来福杂货", "id":"jiang laifu", "name":"江来福"]),
  (["area":"/d/chengdu/dangpu", "short":"成都当铺", "id":"shen qiongyue", "name":"申琼月"]),
  (["area":"/d/dalicheng/dalicheng11", "short":"大理太和居", "id":"song laoban", "name":"宋老板"]),
  (["area":"/d/kunming/biaoju", "short":"昆明神威镖局", "id":"zhang chongwei", "name":"张崇威"]),
  (["area":"/d/yueyang/machehang", "short":"岳阳车马行", "id":"wu yu", "name":"武雨"]),
  (["area":"/d/changan/dangpu", "short":"长安当铺", "id":"hao baliu", "name":"郝八六"])});

string do_escort();
string do_give();
string do_fail();
int ask_title();

void create()
{
	set_name("马行空", ({ "ma xingkong", "ma", "xingkong" }));
	set("gender", "男性");
	set("age", 45);
  set("title", HIY+"飞马镖局"+NOR+" 总镖头"+HIW+" 百胜神拳"+NOR);
	set("long", "他就是「飞马镖局」的总镖头－－马行空。\n");
	set("no_get", 1);

	set("combat_exp", 30000);
	set("shen_type", 1);

	set("max_neili", 500);
	set("neili", 500);
	set("jiali", 10);

	set_skill("force", 40);
	set_skill("sword", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);

	set("inquiry", ([
    "押镖": (:do_escort:),
    "job": (:do_escort:),
    "完成": (:do_give:),
    "finish": (:do_give:),
    "放弃":(:do_fail:),
    "fail":(:do_fail:),
    "头衔":(:ask_title:)
   ]) );


	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);

	setup();
	//carry_object("/clone/weapon/changjian")->wield();
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
  
  return get_dart_fb("changan", this_player(), escort_info, sno);
}

int do_listesc()
{
	object ob;
	string msg;
	
	if ( !(ob=find_object("/quest/escort/escort_board")) )
		ob=load_object("/quest/escort/escort_board");
	
	msg=ob->show_list("changan", escort_info);
	tell_object(this_player(), msg);
	return 1;
}

string do_escort()
{
//	if ( !wizardp(this_player()) )
//		return "本功能暂时只接受wizard级别的玩家。\n";
	
	return get_dart("changan", this_player(), escort_info);
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
	return escort_rank("飞马镖局");
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