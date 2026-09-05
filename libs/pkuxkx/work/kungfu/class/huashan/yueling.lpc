// yueling.c 岳灵珊
#include <ansi.h>
#include <title.h>
#include "bonus.h"
inherit NPC;
inherit F_MASTER;
int ask_linghu();
int ask_siguo();
void do_answer(string);
int ask_job();
int ask_fail();
void create()
{
        set_name("岳灵珊",({"yue lingshan","lingshan","yue"}));
	set("title",GRN "华山派" NOR + YEL +"女剑侠" NOR);
        set("long",
                "华山派掌门岳不群的爱女。\n"
                "她容貌秀丽，虽不是绝代美人，也别有一番可人之处。\n");
        set("gender", "女性");
        set("age", 19);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 18);
        set("int", 22);
        set("con", 26);
        set("dex", 26);

        set("max_qi",  500);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 20);
        set("combat_exp", 10000);
        set("score", 5000);
        set("per",34);
        set_skill("force", 60);
        set_skill("huashan-neigong", 40);
	set_skill("strike", 50);
	set_skill("hunyuan-zhang", 50);
        set_skill("poyu-quan", 30);
        set_skill("dodge", 60);
        set_skill("huashan-shenfa", 60);
//      set_skill("tianpo-quan", 70);
        set_skill("parry", 55);
        set_skill("sword", 60);
        set_skill("huashan-jianfa", 45);
//      set_skill("taoism", 80);

        map_skill("force", "huashan-neigong");
	map_skill("strike", "hunyuan-zhang");
        map_skill("dodge", "huashan_shenfa");
//      map_skill("unarmed", "taiji-quan");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");

	prepare_skill("strike", "hunyuan-zhang");

        create_family("华山派" , 19, "弟子");
        set("inquiry", ([
                "岳不群" : "岳灵珊说：他老人家是我的父亲。\n",
                "宁中则" : "岳灵珊说：她老人家是我的母亲。\n",
                "令狐冲" : (: ask_linghu :),
                "思过崖" : (: ask_siguo :),
                "job" : (: ask_job :),
                "任务" : (: ask_job :),
                "fail" : (: ask_fail :),
                "失败" : (: ask_fail :),
        ]) );



        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/greenrobe")->wear();
}


int ask_linghu()
{ mapping myfam;
        if (!(myfam = this_player()->query("family"))
            || myfam["family_name"] != "华山派")
   {
      say("岳灵珊说：他是我的大师兄，你问他干什么？\n");
      return 1;
   }
  else
   {
if ((int)this_player()->query("score") < 100)
        {
          command("say 你刚入本门，问那么多干什么?");
        return 1;
        }
      say("岳灵珊说：他是我的大师兄，现在正在思过崖思过。\n");
      this_player()->set_temp("marks/令1", 1);
    return 1;
   }
}

int ask_siguo()
{
  if ((int)this_player()->query_temp("marks/令1")) {
     say("岳灵珊说：思过崖在华山后山。从练武场往西北的小路可以通向思过崖。\n");
     this_player()->set_temp("marks/思1", 1);
     return 1;
  }
  else {
     say("岳灵珊说：思过崖是华山重地，你怎么知道的？\n");
     return 1;
  }
}
void attempt_apprentice(object ob)
{
  
	      if( !ob->query("family") &&
	          ob->query("combat_exp")>5000 && 
	          !ob->query("reborn/chushi") ) 
	      {
		      command ("say 本派不收经验太高的普通百姓！\n");
		      return;
	      }
  
        if((string)ob->query("gender")=="女性")
          {
		if ((string)ob->query("family/family_name") == "灵鹫宫" 
			&& ob->query("lingjiu/xiulian"))
		{
        		command("say "+RANK_D->query_respect(ob)+"，你现在拜我似乎会有很大损失，你能拿定主意吗？(answer)");
			
		}
		else
		{
        		command("say 好吧，"+RANK_D->query_respect(ob)+"，我就收下你了！");
	        	command("recruit "+ob->query("id"));
		}
           }
        else {
          command("say 我不收男弟子。"+RANK_D->query_respect(ob)+"你还是去拜我师兄吧！\n");
            }
return;
}

void do_answer(string arg)
{
	object me=this_player();
	if (!arg || (arg != "是" && arg != "能" && arg != "yes"))
        	command("say 你说的什么乱七八糟的，看来你是没有诚心，算了！");
	else
	{
        	command("say 好吧，"+RANK_D->query_respect(me)+"，我就收下你了！");
		me->set("mud_age",me->query("lingjiu/mud_age"));
		me->set("age",14+me->query("mud_age")/3600/24);
		me->delete("lingjiu/skill_status");
		me->delete("lingjiu/qi");
		me->delete("lingjiu/eff_qi");
		me->delete("lingjiu/max_qi");
		me->delete("lingjiu/jing");
		me->delete("lingjiu/eff_jing");
		me->delete("lingjiu/max_jing");
		me->delete("lingjiu/jingli");
		me->delete("lingjiu/neili");
		me->delete("lingjiu/max_jingli");
		me->delete("lingjiu/max_neili");
		me->delete("lingjiu/combat_exp");
		me->delete("lingjiu/need_xiulian");
		me->delete("lingjiu/mud_age");
		me->delete("lingjiu/xiulian");
		me->delete("lingjiu/last_xiulian_time");
	        command("recruit "+me->query("id"));
	}
return;
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
	        if (this_player()->query("age")<20)
           	ob->set("title",GRN "华山派" NOR + YEL +"女剑童" NOR);
        	else 
   	        ob->set("title",GRN "华山派" NOR + YEL +"女剑士" NOR);
//title系统记录玩家title by seagate@pkuxkx
	        ob->set_title(TITLE_RANK, ob->query("title"));
	      }
}

void re_rank(object student)
{
	      if (this_player()->query("age")<20)
         	student->set("title",GRN "华山派" NOR + YEL +"女剑童" NOR);
        else 
   	      student->set("title",GRN "华山派" NOR + YEL +"女剑士" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      student->set_title(TITLE_RANK, student->query("title"));
}

int show_map(object me)
{
    int i;
    string *shorts=({"练武场","玉女峰","玉女祠","后山小路","小院","镇岳宫","朝阳峰","苍龙岭","舍身崖",
        "猢狲愁","老君沟","华山别院","百尺峡","千尺幢","青柯坪","莎萝坪","华山脚下","玉泉院"});
    string file;
    file = read_file(__DIR__"map-huashan");
    for (i=0;i<sizeof(shorts);i++)
    {
        file = replace_string(file, shorts[i], HBRED+shorts[i]+NOR);
    }
    file = file+"\n";
    tell_object(me,file);
    return 1;
}

int ask_job()
{
    object me=this_player();
    object ob=this_object();
    object ling;
    object *all=all_inventory(me);
    int i,count=0;
    
    if (me->query("family/family_name")!="华山派")
    {
        command("say 阁下不是我派弟子，这是何意？");
        return 1;
    }
    if (me->query("combat_exp")>30000)
    {
        command("say 你的功夫不错了，找我娘看看有什么任务交给你。");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        command("say 等你忙完再来找我吧。");
        return 1;
    }
    if (!me->query("hsnewbiejob/intro"))
    {
        me->set("hsnewbiejob/intro",1);
        tell_object(me,HIR"华山入门任务帮助请在游戏中使用命令help task-huashan获得。\n"NOR);
    }
    if (me->query("hsnewbiejob/start"))
    {
        command("say 你上次任务还没有完成呢！");
        return 1;
    }
    if (time()-me->query("hsnewbiejob/lasttime")<120)
    {
        command("say 你刚刚做过任务，先去休息一会吧。");
        return 1;
    }
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("is_ling"))
        {
            count=1;
        }
    }
    if (count)
    {
        me->set("hsnewbiejob/start",1);
        me->set("hsnewbiejob/lasttime",time());
        me->set_temp("hsnewbiejob/xunshan/start",1);
        message_vision("$N对$n说道：最近华山颇不安宁，你带着身上的令牌去巡逻一下吧。\n",ob,me);
        
        show_map(me);
        message_vision("$N拿出一张地图，把华山需要巡逻的区域用不同颜色标注出来，并和$n说了一遍。\n",ob,me);
        return 1;
    }
    else
    {
        me->set("hsnewbiejob/start",1);
        me->set("hsnewbiejob/lasttime",time());
        me->set_temp("hsnewbiejob/xunshan/start",1);
        ling=new("/d/huashan/obj/lingpai");
        ling->move(me);
        message_vision("$N对$n说道：最近华山颇不安宁，你带着这块令牌去巡逻一下吧。\n",ob,me);
        
        show_map(me);
        message_vision("$N拿出一张地图，把华山需要巡逻的区域用不同颜色标注出来，并和$n说了一遍。\n",ob,me);
        return 1;
    }
}

int dest(object ob)
{
	if(ob)
	destruct(ob);
	return 1;
}

int accept_object(object me, object ob)
{
	if (!ob->query("is_ling"))
    {
        return notify_fail("这是什么东西？\n");
    }
    if (!me->query_temp("hsnewbiejob/xunshan/rooms/room1")
        ||!me->query_temp("hsnewbiejob/xunshan/rooms/room2")
        ||!me->query_temp("hsnewbiejob/xunshan/rooms/room3")
        ||!me->query_temp("hsnewbiejob/xunshan/rooms/room4")
        ||!me->query_temp("hsnewbiejob/xunshan/rooms/room5")
        ||!me->query_temp("hsnewbiejob/xunshan/rooms/room6")
        ||!me->query_temp("hsnewbiejob/xunshan/rooms/room7")
        ||!me->query_temp("hsnewbiejob/xunshan/rooms/room8")
        ||!me->query_temp("hsnewbiejob/xunshan/rooms/room9")
        ||!me->query_temp("hsnewbiejob/xunshan/rooms/room10")
        ||!me->query_temp("hsnewbiejob/xunshan/rooms/room11")
        ||!me->query_temp("hsnewbiejob/xunshan/rooms/room12")
        ||!me->query_temp("hsnewbiejob/xunshan/rooms/room13")
        ||!me->query_temp("hsnewbiejob/xunshan/rooms/room14")
        ||!me->query_temp("hsnewbiejob/xunshan/rooms/room15")
        ||!me->query_temp("hsnewbiejob/xunshan/rooms/room16")
        ||!me->query_temp("hsnewbiejob/xunshan/rooms/room17")
        ||!me->query_temp("hsnewbiejob/xunshan/rooms/room18")
        ||!me->query_temp("hsnewbiejob/xunshan/rooms/room19"))
    {
        return notify_fail("你是不是漏了什么地方没有去？\n");
    }
    if (time()-me->query("hsnewbiejob/lasttime")<60)
    {
        return notify_fail("这么快就回来了？肯定偷懒了吧？\n");
    }
    this_object()->add_busy(1);
    remove_call_out("dest");
    call_out("dest",1,ob);
    bonus(me);
    return 1;
}


int ask_fail()
{
    object me=this_player();
    object ob=this_object();
    object *all=all_inventory(me);
    int i,count=0;
    if (me->query("family/family_name")!="华山派")
    {
        command("say 阁下不是我派弟子，这是何意？");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        command("say 等你忙完再来找我吧。");
        return 1;
    }
    if (!me->query("hsnewbiejob/start"))
    {
        command("say 你没接过任务啊！");
        return 1;
    }
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("is_ling"))
        {
            count=1;
        }
    }
    if (count)
    {
        command("say 你再去看看嘛，巡山是我派弟子必做的任务啊。");
        return 1;
    }
    
    command("say 令牌丢了？你去领罚吧！");
    punish(me);
    return 1;
}