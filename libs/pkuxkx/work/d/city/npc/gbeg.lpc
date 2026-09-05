#include <localtime.h>
#include <ansi.h>
inherit NPC;
//string ask_skill();
string ask_times();

void create()
{
        set_name("老乞丐", ({"gbeg"}));
        set("title", HIR"道听途说"NOR);
        set("long",
                "他是一位低调的老人，风霜满面。\n"
        );

        set("no_get",1);
        set("gender", "男性");
        set("inquiry", ([
                //"启动技能" : (: ask_skill, "gift_skill" : ),
                "次数查询" : (: ask_times, "chktimes" : ),
                  ]));
        set("chat_msg", ({
               // "老乞丐说道： 提供新手启动资金服务。\n",
               // "老乞丐说道： 提供新手启动技能服务。\n",
                "老乞丐说道： 提供任务次数查询服务。\n",
                      }));
        set("attitude", "friendly");
		set("shen_type",1);
		setup();
}


/* string ask_skill()

{
         object me= this_player();
      if  (me->query("combat_exp")>3000000)
     {
         return "你的经验够高了。还不自己出去闯荡江湖。臭不要脸的! ";
        
     }

   if (me->query("gift/skill"))
     {
         return "你已经得到启动技能！贪得无厌小心我送去小黑屋反省!";
        
     }
         me->set_temp_skill("sword",100,36000,0)
         me->set_temp_skill("hero-jianfa",100,36000,0)
         me->set_temp("gift/skill",1);
         
         return 你已经得到北侠新手启动技能,请记得激发使用。";
     
    
}
*/


string ask_times()

{
	string lbl;
    object me= this_player();  
    if  (me->query("combat_exp")<3000000)
     {    
        tell_object(me, "老乞丐怒道：经验这么低，才做了几次任务就敢来问次数？丢不丢人！给我滚出去！\n");
		message_vision(HIC "只见$N飞起一脚，正中$n的屁股。$n咕噜噜地滚出门去了……\n" NOR, this_object(), me);
 		me->move("/d/city/beidajie1");
		return "真烦人！";
    }
    lbl =  HIY "    ★  %-10s★  " + HIW + "%s：" + HIC + " %s\n" NOR;
  tell_object(me, HIR"◎============================================================================◎\n");
  tell_object(me, sprintf(lbl,"萧    峰","次数", chinese_number( me->query("jobs/completed/xiaofeng") ) ));
  tell_object(me, sprintf(lbl,"韩 世 忠","次数", chinese_number( me->query("jobs/completed/hansz") ) ));
  tell_object(me, sprintf(lbl,"公 孙 止","次数", chinese_number( me->query("jobs/completed/gongsun") ) )); 
  tell_object(me, sprintf(lbl,"护    镖","次数", chinese_number( me->query("jobs/completed/hubiao") ) ));
  tell_object(me, sprintf(lbl,"慕容玉玺","次数", chinese_number( me->query("jobs/completed/murong") ) ));
  tell_object(me, sprintf(lbl,"胡 一 刀","次数", chinese_number( me->query("jobs/completed/huyidao") ) ));
  tell_object(me, sprintf(lbl,"韩 员 外","次数", chinese_number( me->query("newjobs/completed/hyw") ) ));
  tell_object(me, sprintf(lbl,"刺    杀","次数", chinese_number( me->query("jobs/completed/mzj") ) ));
  tell_object(me, sprintf(lbl,"万 安 塔","次数", chinese_number( me->query("newjobs/completed/wat") ) ));
  tell_object(me, sprintf(lbl,"T A S K ","次数", chinese_number( me->query("jobs/completed/task") ) ));  
  tell_object(me, sprintf(lbl,"鄱 阳 湖","次数", chinese_number( me->query("newjobs/completed/pyh") ) )); 
  tell_object(me, sprintf(lbl,"百 晓 生","次数", chinese_number( me->query("newjobs/completed/bxs") ) )); 
  tell_object(me, sprintf(lbl,"南海神尼","次数", chinese_number( me->query("newjobs/completed/shenni") ) )); 
  tell_object(me, HIR"◎============================================================================◎\n"NOR);

  return "多多努力！";
}

void unconcious()
{
    die();
}

void die()
{
    set("eff_qi",this_object()->query("max_qi"));
    set("qi",this_object()->query("max_qi"));
    set("eff_jing",this_object()->query("max_jing"));
    set("jing",this_object()->query("max_jing"));
    return;
}
