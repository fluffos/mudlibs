// bj

inherit NPC;
#include <ansi.h>
inherit F_ESCORT;
mapping *escort_info=
({(["area":"/d/dalunsi/laifu", "short":"赞普来福杂货", "id":"jiang laifu", "name":"江来福"]),
  (["area":"/d/emei/dian1", "short":"峨嵋毗卢殿", "id":"jingdao shitai", "name":"静道师太"]),
  (["area":"/d/changan/biaoju", "short":"长安飞马镖局", "id":"ma xingkong", "name":"马行空"]),
  (["area":"/d/xiangyang/dangpu", "short":"襄阳当铺", "id":"shi chunqiu", "name":"史春秋"]),
	(["area":"/d/luoyang/qianzhuang", "short":"洛阳四海钱庄", "id":"hu xueyuan", "name":"胡雪源"]),
	(["area":"/d/wudang/biaoju", "short":"武当荆西镖局", "id":"zhang zhi", "name":"张志"]),
  (["area":"/d/guiyunzhuang/taihujie2", "short":"归云庄太湖街", "id":"shang ren", "name":"商人"]),
	(["area":"/d/quanzhou/qianzhuang", "short":"嘉兴钱庄", "id":"bao fangyuan", "name":"包方圆"]),
	(["area":"/d/suzhou/jubaozhai", "short":"苏州聚宝斋", "id":"sun baopi", "name":"孙剥皮"]),
	(["area":"/d/quanzhou2/dangpu", "short":"泉州当铺", "id":"wang fugui", "name":"王福贵"]),
  (["area":"/d/zhenjiang/biaoju", "short":"镇江飞龙镖局", "id":"zhang jing", "name":"张经"]),
  (["area":"/d/yashan/wansouth3", "short":"牙山小荒地", "id":"huangmao gui", "name":"黄毛鬼"]),
  (["area":"/d/nanchang/biaoju", "short":"南昌飞虎镖局", "id":"chu daye", "name":"楚大业"]),
  (["area":"/d/yuewangmu/muqian", "short":"岳王墓墓前广场", "id":"bao dating", "name":"包打听"]),
  (["area":"/d/yueyang/machehang", "short":"岳阳车马行", "id":"wu yu", "name":"武雨"]),
  (["area":"/d/hangzhou/qianzhuang", "short":"临安府江南钱庄", "id":"jin qier", "name":"金乞儿"])});

string do_escort();
string do_give();
string do_fail();
int ask_title();

void create()
{
        set_name("王小月",({ "wang xiaoyue", "wang", "xiaoyue" }) );
        set("gender", "女性" );
        set("title",MAG"天福镖局 "+NOR+"署理总镖头"+NOR);
        set("age", 20+random(10));
        set("long", "这是个内家高手，一看就不好惹。\n");
		set("str", 1);
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

        prepare_skill("strike","taiyi-zhang");

	set("inquiry", ([
    "押镖": (:do_escort:),
    "job": (:do_escort:),
    "完成": (:do_give:),
    "finish": (:do_give:),
    "放弃":(:do_fail:),
    "fail":(:do_fail:),
    "头衔":(:ask_title:)
   ]) );
   
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
  
  return get_dart_fb("jiangzhou", this_player(), escort_info, sno);
}

int do_listesc()
{
	object ob;
	string msg;
	
	if ( !(ob=find_object("/quest/escort/escort_board")) )
		ob=load_object("/quest/escort/escort_board");
	
	msg=ob->show_list("jiangzhou", escort_info);
	tell_object(this_player(), msg);
	return 1;
}

string do_escort()
{
//	if ( !wizardp(this_player()) )
//		return "本功能暂时只接受wizard级别的玩家。\n";
	
	return get_dart("jiangzhou", this_player(), escort_info);
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
	return escort_rank("天福镖局");
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