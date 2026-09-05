// bj

inherit __DIR__"ask_ning";
inherit F_ESCORT;
//#include "/d/yingtianfu/neicheng/npc/obj/askmap.h"
#include <ansi.h>

mapping *escort_info=
({(["area":"/d/lingzhou/jiuguan", "short":"灵州酒馆", "id":"xixia mingshang", "name":"西夏名商"]),
	(["area":"/d/village/smithy1", "short":"华山村铁匠铺", "id":"feng", "name":"冯铁匠"]),
	(["area":"/d/wudang/biaoju", "short":"武当荆西镖局", "id":"zhang zhi", "name":"张志"]),
	(["area":"/d/quanzhen/tianzjt", "short":"全真天尊讲经堂", "id":"hao datong", "name":"郝大通"]),
  (["area":"/d/qufu/kongfu", "short":"曲阜孔府", "id":"kong qiao", "name":"孔翘"]),
  (["area":"/d/jinyang/xiaofu", "short":"晋阳萧府", "id":"xiao banhe", "name":"萧半和"]),
  (["area":"/d/dalunsi/laifu", "short":"赞普来福杂货", "id":"jiang laifu", "name":"江来福"]),
  (["area":"/d/chengdu/dangpu", "short":"成都当铺", "id":"shen qiongyue", "name":"申琼月"]),
  (["area":"/d/dalicheng/dalicheng11", "short":"大理太和居", "id":"song laoban", "name":"宋老板"]),
  (["area":"/d/emei/dian1", "short":"峨嵋毗卢殿", "id":"jingdao shitai", "name":"静道师太"]),
  (["area":"/d/kunming/biaoju", "short":"昆明神威镖局", "id":"zhang chongwei", "name":"张崇威"]),
  (["area":"/d/saiwai/weststreet", "short":"张家口西市", "id":"pihuo shangren", "name":"皮货商人"]),
  (["area":"/d/beijing/quanjude2", "short":"北京全聚德", "id":"wu liuqi", "name":"吴六奇"])});

string do_escort();
string do_give();
string do_fail();
int ask_title();

void create()
{
        set_name("楚大业",({ "chu daye", "chu", "daye" }) );
        set("gender", "男性" );
        set("title",HIM"飞虎镖局 "+NOR+"总镖头"+NOR);
        set("age", 40+random(20));
        set("long", "这是个外家高手，一看就不好惹。\n");
		    set("str", 30);
        set("dex", 30);
        set("con", 30);
        set("int", 30);
		    set("shen_type", 1);
        set_temp("apply/defense", 10);
        set("combat_exp", 1000000);
        set("loc","南昌");
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
    add_action("do_dating","dating");
	//楚大业镖局npc的命令 
	//seagate镖局命令直接加在楚大业的文件里，否则使用这个头文件的所有npc都出错，Zine
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
  
  return get_dart_fb("nanchang", this_player(), escort_info, sno);
}

int do_listesc()
{
	object ob;
	string msg;
	
	if ( !(ob=find_object("/quest/escort/escort_board")) )
		ob=load_object("/quest/escort/escort_board");
	
	msg=ob->show_list("nanchang", escort_info);
	tell_object(this_player(), msg);
	return 1;
}

string do_escort()
{
//	if ( !wizardp(this_player()) )
//		return "本功能暂时只接受wizard级别的玩家。\n";
	
	return get_dart("nanchang", this_player(), escort_info);
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
	return escort_rank("飞虎镖局");
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

int removezhao(object where)
{
    if (where)
    {
        where->delete("zhao");
        return 1;
    }
}

int do_dating()
{
    object me=this_player();
    object ob=this_object();
    string loc;
	string *taskwhere=({"镇江","苏州","扬州","江州","岳阳","南昌","泉州","闽南"});
	string *taskloc=({"/d/zhenjiang/","/d/suzhou/","/d/city/","/d/jiangzhou/","/d/yueyang/","/d/nanchang/","/d/quanzhou2/","/d/fuzhou/"});
    object where;
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("songtasks/hubu/task_where")!=ob->query("loc"))
    {
        tell_object(me,"无可奉告！\n");
        return 1;
    }
    if (me->query_temp("songtasks/hubu/task1ask"))
    {
        tell_object(me,"你不是打听过了吗？\n");
        return 1;
    }
    else
    {
		loc=taskloc[member_array(me->query_temp("songtasks/hubu/task_where"),taskwhere)];
        where=TASK_D->random_room(loc);
        message_vision("$N紧紧抓住$n的手：朝廷没有忘记我们呀！\n",ob,me);
        message_vision("$N道：要画这里的地图，最好是去"+where->query("short")+"找一下，好像有前人遗落的残图。\n",ob);
        tell_object(me,RED"你心中暗想，要抓紧时间也许去晚了就找不到了！\n"NOR);
        me->set_temp("songtasks/hubu/task1ask",1);
        where->set("zhao",1);
        call_out("removezhao",120,where);
        return 1;
    }
}