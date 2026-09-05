// linzhennan.c 都大锦
// modified by Jay 4/7/96
// Modified by iszt@pkuxkx, 2007-03-03
// Modified by whuan@pkuxkx 2007-8-20

#include <ansi.h>

inherit NPC;
inherit F_ESCORT;
mapping *escort_info=
({(["area":"/d/beijing/biaoju", "short":"北京武胜镖局", "id":"wang wutong", "name":"王武通"]),
  (["area":"/d/dalunsi/laifu", "short":"赞普来福杂货", "id":"jiang laifu", "name":"江来福"]),
  (["area":"/d/emei/dian1", "short":"峨嵋毗卢殿", "id":"jingdao shitai", "name":"静道师太"]),
  (["area":"/d/dalicheng/dalicheng11", "short":"大理太和居", "id":"song laoban", "name":"宋老板"]),
  (["area":"/d/kunming/biaoju", "short":"昆明神威镖局", "id":"zhang chongwei", "name":"张崇威"]),
  (["area":"/d/guiyunzhuang/taihujie2", "short":"归云庄太湖街", "id":"shang ren", "name":"商人"]),
	(["area":"/d/quanzhou/qianzhuang", "short":"嘉兴钱庄", "id":"bao fangyuan", "name":"包方圆"]),
	(["area":"/d/suzhou/jubaozhai", "short":"苏州聚宝斋", "id":"sun baopi", "name":"孙剥皮"]),
	(["area":"/d/quanzhou2/dangpu", "short":"泉州当铺", "id":"wang fugui", "name":"王福贵"]),
  (["area":"/d/zhenjiang/biaoju", "short":"镇江飞龙镖局", "id":"zhang jing", "name":"张经"]),
  (["area":"/d/yashan/wansouth3", "short":"牙山小荒地", "id":"huangmao gui", "name":"黄毛鬼"]),
  (["area":"/d/nanchang/biaoju", "short":"南昌飞虎镖局", "id":"chu daye", "name":"楚大业"]),
  (["area":"/d/jiangzhou/biaoju", "short":"江州天福镖局", "id":"wang xiaoyue", "name":"王小月"]),
  (["area":"/d/yuewangmu/muqian", "short":"岳王墓墓前广场", "id":"bao dating", "name":"包打听"]),
  (["area":"/d/yueyang/machehang", "short":"岳阳车马行", "id":"wu yu", "name":"武雨"]),
  (["area":"/d/hangzhou/qianzhuang", "short":"临安府江南钱庄", "id":"jin qier", "name":"金乞儿"])});

string do_escort();
string do_give();
string do_fail();
int ask_title();

void create()
{
	set_name("都大锦", ({ "du dajin", "du", "dajin" }));
	set("gender", "男性");
	set("age", 45);
    set("title", HIY+"龙门镖局"+NOR+" 总镖头"+HIW+" 多臂熊"+NOR);
	set("long", "他就是「龙门镖局」的总镖头－－都大锦。\n");
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
	carry_object("/clone/weapon/changjian")->wield();
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
  
  return get_dart_fb("luoyang", this_player(), escort_info, sno);
}

int do_listesc()
{
	object ob;
	string msg;
	
	if ( !(ob=find_object("/quest/escort/escort_board")) )
		ob=load_object("/quest/escort/escort_board");
	
	msg=ob->show_list("luoyang", escort_info);
	tell_object(this_player(), msg);
	return 1;
}

string do_escort()
{
//	if ( !wizardp(this_player()) )
//		return "本功能暂时只接受wizard级别的玩家。\n";
	
	return get_dart("luoyang", this_player(), escort_info);
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
	return escort_rank("龙门镖局");
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