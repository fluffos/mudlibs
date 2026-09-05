// linzhennan.c 林震南
// modified by Jay 4/7/96
// Modified by iszt@pkuxkx, 2007-03-03
// Modified by whuan@pkuxkx 2007-8-20

#include <ansi.h>
inherit NPC;
inherit F_ESCORT;
mapping *escort_info=
({(["area":"/d/guiyunzhuang/taihujie2", "short":"归云庄太湖街", "id":"shang ren", "name":"商人"]),
	(["area":"/d/quanzhou/qianzhuang", "short":"嘉兴钱庄", "id":"bao fangyuan", "name":"包方圆"]),
	(["area":"/d/suzhou/jubaozhai", "short":"苏州聚宝斋", "id":"sun baopi", "name":"孙剥皮"]),
	(["area":"/d/quanzhou2/dangpu", "short":"泉州当铺", "id":"wang fugui", "name":"王福贵"]),
  (["area":"/d/zhenjiang/biaoju", "short":"镇江飞龙镖局", "id":"zhang jing", "name":"张经"]),
  (["area":"/d/yashan/wansouth3", "short":"牙山小荒地", "id":"huangmao gui", "name":"黄毛鬼"]),
  (["area":"/d/nanchang/biaoju", "short":"南昌飞虎镖局", "id":"chu daye", "name":"楚大业"]),
  (["area":"/d/yuewangmu/muqian", "short":"岳王墓墓前广场", "id":"bao dating", "name":"包打听"]),
  (["area":"/d/hangzhou/qianzhuang", "short":"临安府江南钱庄", "id":"jin qier", "name":"金乞儿"]),
  (["area":"/d/quanzhou/dating", "short":"嘉兴陆家庄大厅", "id":"lu liding", "name":"陆立鼎"])});

string do_escort();
string do_give();
string do_fail();
int ask_title();
int ask_query();

int ask_fuwei();
int ask_yuantu();
int ask_pixie();
int ask_tong();

void create()
{
	set_name("林震南", ({ "lin zhennan", "lin", "zhennan" }));
	set("gender", "男性");
	set("age", 45);
	set("long", "他就是「福威镖局」的总镖头－－林震南。\n");
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
		"向阳老宅" : "林震南说道：那是我从前在福建时住的家院，已经破败了。",
		"福威镖局" : (: ask_fuwei :),
		"远图公" : (: ask_yuantu :),
		"林远图" : "林震南大怒：小孩子这么没礼貌，直呼先人名讳！",
		"辟邪剑法" : (: ask_pixie:),
		"铜钱" : (: ask_tong:),
		"铜板" : (: ask_tong:),
    "押镖": (:do_escort:),
    "job": (:do_escort:),
    "query" : (: ask_query :),       
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
  
  return get_dart_fb("fuzhou", this_player(), escort_info, sno);
}

int do_listesc()
{
	object ob;
	string msg;
	
	if ( !(ob=find_object("/quest/escort/escort_board")) )
		ob=load_object("/quest/escort/escort_board");
	
	msg=ob->show_list("fuzhou", escort_info);
	tell_object(this_player(), msg);
	return 1;
}

int ask_fuwei()
{
	say("林震南炫耀地说：我们林家三代走镖，一来仗着先祖远图公当年闯下的威名，二\n"
	"来靠著我们林家家传的玩艺儿不算含糊，这才有今日的局面，成为大江以南首屈\n"
	"一指的大镖局。江湖上提到『福威镖局』四字，谁都要翘起大拇指，说一声：『\n"
	"好福气！好威风！』哈哈，哈哈！\n");
	this_player()->set_temp("marks/林1", 1);
	return 1;
}

int ask_yuantu()
{
	if ((int)this_player()->query_temp("marks/林1")) {
		say("林震南磕一磕烟斗，说道：远图公是我的祖父，福威镖局是他一手创办的。当年\n"
		"祖父以七十二路辟邪剑法开创镖局，当真是打遍黑道无敌手。其时白道上英雄见\n"
		"他太过威风，也有去找他比试武艺的，青城派掌门余观主的师父长青子少年之时\n"
		"便在他辟邪剑法下输了几招。\n");
		this_player()->set_temp("marks/林2", 1);
		return 1;
	}
	else {
		say("林震南说道：远图公是我的祖父。\n");
		return 1;
	}
}

int ask_pixie()
{
	int p1, p2, p3, p4;
	
	if ((int)this_player()->query("passwd"))
	{
		say("林震南不悦地说道：我不是都告诉你了吗？我的剑法不及先祖。\n");
	}
	else if ((int)this_player()->query_temp("marks/林2"))
	{
		say("林震南一惊，说道：你怎么知道的？噢，我刚才说露嘴了。嗨，在下的功夫外人\n"
		"不知底细，其实及不上先祖。。\n");
		write("林震南顿一顿，接着对你低声说：先祖去世前，曾给家父留下");
		p1=random(4)+1;
		p2=random(4)+1;
		p3=random(4)+1;
		p4=random(4)+1;
		this_player()->set("passwd",p1*1000+p2*100+p3*10+p4);
		write(CHINESE_D->chinese_number(p1)+"千"+CHINESE_D->chinese_number(p2)+
		"百"+CHINESE_D->chinese_number(p3)+"十"+CHINESE_D->chinese_number(p4));
		write("个\n铜钱，我一直未解其中奥秘。\n");
	}
	else {
		message("vision",HIY "林震南勃然大怒，喝道：你也窥视我们林家的辟邪剑谱？！我跟你拼了！\n"
		NOR, environment(), this_object() );
		kill_ob(this_player());
	}
	this_player()->delete_temp("marks/林1");
	this_player()->delete_temp("marks/林2");
	return 1;
}

int ask_tong()
{
	int p, p1, p2, p3, p4;
	
	if (!(p=(int)this_player()->query("passwd"))) {
		say("林震南一脸讥笑的样子，说：怎么混到这一步了到处要钱？\n");
	}
	else {
		write("林震南低声说：先祖去世前，曾给家父留下");
		p1=(int)p/1000;
		p2=(int)(p-p1*1000)/100;
		p3=(int)(p-p1*1000-p2*100)/10;
		p4=(int)(p-p1*1000-p2*100-p3*10);
		write(CHINESE_D->chinese_number(p1)+"千"+CHINESE_D->chinese_number(p2)+
		"百"+CHINESE_D->chinese_number(p3)+"十"+CHINESE_D->chinese_number(p4));
		write("个\n铜钱，我一直未解其中奥秘。\n");
	}
	
	return 1;
}

string do_escort()
{
//	if ( !wizardp(this_player()) )
//		return "本功能暂时只接受wizard级别的玩家。\n";
	
	return get_dart("fuzhou", this_player(), escort_info);
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
	return escort_rank("福威镖局");
}

int ask_query()
{	
	object ob=this_object();
	object me=this_player();
	int hbexp;
	hbexp=me->query("yunbiao/exp/lin zhennan");

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