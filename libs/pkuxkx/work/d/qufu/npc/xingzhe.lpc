// xingzhe.c 原this_object()->query("name")+"功能一分为三，抄经交给xingzhe，this_object()->query("name")+"理学大师，没道理派人抄写佛经 ZINE

inherit NPC;

#include <ansi.h>

string RandomDigtal();
int ask_job();
int ask_code();
int ask_done();

void create()
{
	set_name("云游僧人", ({ "yunyou sengren", "sengren", "ren"}));
	set("long", "这是一位云游僧人，曾发下大宏愿重修佛经。\n");
	set("gender", "男性");
	set("age", 40);
	set_skill("literate", 100);
    set_skill("buddhism", 300);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);

	set("combat_exp", 1000000);
	set("shen_type", 1);
	set("inquiry", ([
		
    /*"工号" : (: ask_code :),
    "口令" : (: ask_code :),*/
    "job" : (: ask_job :),
    "工作" : (: ask_job :),
    "done" : (: ask_done :),
    "完成" : (: ask_done :),		
/*
    "礼物" : (: ask_gift :),
    "gift" : (: ask_gift :),
*/
	       ]) );
	setup();
    carry_object("/d/changan/npc/obj/m-cloth")->wear();
}

void init()
{
    ::init();
    add_action("do_report", "report"); //报告工号   
}

string RandomDigtal()
{
   string *ABC=({"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"});
   string *DIG=({"0","1","2","3","4","5","6","7","8","9"});
   string MyCode;
   MyCode =  ABC[random(sizeof(ABC))]+ABC[random(sizeof(ABC))];
   MyCode += DIG[random(sizeof(DIG))]+DIG[random(sizeof(DIG))]+DIG[random(sizeof(DIG))];
   return MyCode;
}
int ask_job()
{
   string* info;
   int val = 0;

   object me=this_player();
   if (me->query_temp("chaojing/can_write"))
   {
     command("hmm");
     command("say 你已经领了任务，直接去泰山石经峪抄经(write jing)就可以了。");
     return 1;
   }
   me->set_temp("chaojing/can_write",1);
   tell_object(me,this_object()->query("name")+"说道：很好，你直接去泰山石经峪抄经（write jing）吧，工作完成后问我要奖励（ask zhu about done）。\n");
   tell_object(me,this_object()->query("name")+"说道：记住你的工号：\n");
   info = ANTIROBOT_D->mxpantirobot(me);
   me->set_temp("chaojing/code",info[0]);
   tell_object(me,this_object()->query("name")+"说道："+HIY"请注意，三分钟后查询系统自动清除你的工号！\n"NOR);
   me->set_temp("can_ask_again",10);
   return 1;
}

/*int ask_code()
{ 
   object me=this_player();
   if (!me->query_temp("can_ask_again"))
   {
     command("goaway");
     command("say 你问过了好几次了，我可没空理你。");
     return 1;
   }   
   if (!me->query_temp("chaojing/can_write"))
   {
     command("hmm");
     command("say 你又不抄经，有你啥事儿，该干嘛干嘛去。");
     return 1;
   }
   me->add_temp("can_ask_again",-1);
   tell_object(me,"this_object()->query("name")+"说道：请到如下网址查询你的工号：\n");
   write(HIR+"http://pkuxkx.net/antirobot/robot.php?filename="+me->query_temp("chaojing/filename")+NOR"\n");   
   return 1;
}*/  //暂时不允许再次ask,mxp图片生成增加服务器负担 By Zine 2010 Nov 13

int ask_done()
{
        object me=this_player();
        if (!me->query_temp("chaojing/finished")) 
            return 0; 
        command("look "+me->query("id"));
        command("say 报上你的口令！report 口令！\n");
        me->set_temp("chaojing/report",1);
        return 1;    
}
int do_report(string arg)
{
        object me=this_player();
        if (!me->query_temp("chaojing/report")) return 0;
        if (!arg || arg=="")
        {
           command("say 请报上口令！");
           return 1;
        }
        message_vision("$N大声回答道："+arg+"!\n",me);
        if (arg==me->query_temp("chaojing/code"))
           {
           command("say 很好！我已经吩咐人存了100两银子到您的帐号，欢迎下次再来抄经。");  
           me->add("balance",10000);
           } 
        else
          {
           command("say 口令不对，本次工作不能领取工钱。");
          }
        me->delete_temp("chaojing"); 
        return 1;
}
