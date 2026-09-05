//by whuan
#include <ansi.h>
#include <localtime.h>
inherit NPC;
#include "/d/wizard/npc/equip_manage.h"
int do_compensate();
string ask_reset();
void create()
{
        object oba,obb,obc;
        set_name(""HIY"无 欢"NOR"", ({ "whuan npc","wu huan","zongguan"}));
        set("long", "这就是无欢，北侠的菜鸟巫师。他是随机装备的大总管，嘿嘿～～～\n");
        set("gender", "男性");
        set("age", 28);
        set("per", 100);
        set("title",""HIG"装备总管");
        set_skill("literate", 2000);
        set_skill("dodge", 2000);
        set_skill("unarmed", 2000);
        set_skill("parry", 2000);
        set("combat_exp",500000000);
        set("chat_chance",3);
        set("chat_msg", ({
         "无 欢叹了一口气道：“现在的玩家可没有我这么牛的了！”\n",             
         "无 欢两眼深情看着远方，似乎想起了她的心上人。\n",
         "无 欢嘿嘿奸笑了两声：“大浩这个死太监，居然想跟我一较长短，真是自不量力。”\n",                  
        }));
         set("inquiry",([
                "补偿":"输入compensate命令即可在重启后十分钟内取消常规任务的惩罚。",
                "当机补偿":"输入compensate命令即可在重启后十分钟内取消常规任务的惩罚。",
                "重置补偿" : (: ask_reset :),
             ]));
        set("shen_type",1);set("score",500000);setup();          
  carry_object("/d/pker/npc/obj/pifeng")->wear();       
}

void init()
{
          ::init();
          add_action("do_autoload","autoload"); 
          add_action("do_disload","disload");
          add_action("do_compensate","compensate");
          add_action("do_compensate","buchang");
          add_action("do_rename","rename");
//          add_action("do_fix","fix");
          add_action("do_reload","reload");
}   

string ask_reset()
{
  object me=this_player();
  
  if ( !wizardp(me) )
    return "只有巫师才有权限手动重新开放系统异常补偿！每次开启补偿30分钟。\n";
  
  set("compensate", time()+1800);
  CHANNEL_D->do_channel(this_object(), "xingmu", "巫师「"+me->name()+"」手动开启30分钟系统异常补偿，在之前系统异常期间产生损失的玩家可以到无欢处获取补偿。\n");
  return "你开启了系统异常补偿。";
}

int do_fix(string arg)
{
        object ob,who;
        int i;
        who = this_player();	
        if(!arg)
                return notify_fail("你要修什么装备？\n");
        if(!ob=present(arg,who))
                return notify_fail("你要修什么装备？\n");
        if(!ob->is_gems())
                return notify_fail("这玩意儿我可修不了！\n");
        if(ob->query("gem_ob_autoloaded"))
                return notify_fail("这件东西取消自动加载之后方能修复！\n");
        ob->set("old_sockets",ob->query("sockets"));
        if (ob->query("armor_type")=="shield" && ob->query("armor/armor")<400)
          {
          ob->add("armor/armor",400);
          ob->add("armor_prop/armor",400);
          }
        if(ob->query("forge") && ob->query("sockets"))
        	{
        	if (ob->query("forge/max") > ob->query("sockets/max"))
        		ob->set("sockets/max",ob->query("forge/max"));
        	ob->delete("forge");
          }
        if(ob->query("forge"))
        	{
        		generate_newitem(ob,0,2);
            message_vision("$n把身上的"+ob->query("name")+"交给了$N，"
	          +"$N拿起一把榔头叮叮当当敲了一会儿，说道：好了！\n",this_object(),who); 
        	  return 1;	
        	}
	      ob->set("forge/max",ob->query("sockets/max"));
	      ob->set("forge/times_max",1);
	      if (ob->query("sockets/filled"))
	      	{
	      	if (ob->query("sockets/max") != ob->query("sockets/filled"))
	      		return notify_fail("这件装备上宝石没有镶满，现在转换的话会有损失，先让虫子给你抠出来吧。\n");
	      	ob->set("forge/times",1);
	      	ob->set("forge/capacity",ob->query("sockets/filled"));
	      	if (stringp(ob->query("sockets/socket1"))) ob->set("forge/material1", ob->query("sockets/socket1"));
	      	if (stringp(ob->query("sockets/socket2"))) ob->set("forge/material2", ob->query("sockets/socket2"));
	      	if (stringp(ob->query("sockets/socket3"))) ob->set("forge/material3", ob->query("sockets/socket3"));
	      	if (ob->query("sockets/socket1_level")) ob->set("forge/material1_level", ob->query("sockets/socket1_level"));
	      	if (ob->query("sockets/socket2_level")) ob->set("forge/material2_level", ob->query("sockets/socket2_level"));
	      	if (ob->query("sockets/socket3_level")) ob->set("forge/material3_level", ob->query("sockets/socket3_level"));
	        
	      //旧宝石转换
	      for (i = 1; i <4; i++)
	      {
	      if (ob->query(sprintf("forge/material%d",i)) == "skull")
	      	ob->set(sprintf("forge/material%d",i), "ri");
        if (ob->query(sprintf("forge/material%d",i)) == "sapphire")
	      	ob->set(sprintf("forge/material%d",i), "yue");
	      if (ob->query(sprintf("forge/material%d",i)) == "amethyst")
	      	ob->set(sprintf("forge/material%d",i), "jin");
	      if (ob->query(sprintf("forge/material%d",i)) == "diamond")
	      	ob->set(sprintf("forge/material%d",i), "mu");
	      if (ob->query(sprintf("forge/material%d",i)) == "emerald")
	      	ob->set(sprintf("forge/material%d",i), "bing");
	      if (ob->query(sprintf("forge/material%d",i)) == "ruby")
	      	ob->set(sprintf("forge/material%d",i), "yan");
	      if (ob->query(sprintf("forge/material%d",i)) == "topaz")
	      	ob->set(sprintf("forge/material%d",i), "sui");
	      }
	      //修正精金dam bug
	      if (ob->query("sockets/filled") && ob->query("weapon_prop"))
	      	{
	      		if(ob->query("sockets/socket1") == "jin" || ob->query("sockets/socket1") == "amethyst")
	      			{
	      				ob->add("weapon/damage",-6*ob->query("sockets/socket1_level"));
	      			}
	      		if(ob->query("sockets/socket2") == "jin" || ob->query("sockets/socket2") == "amethyst")
	      			{
	      				ob->add("weapon/damage",-6*ob->query("sockets/socket2_level"));
	      			}
	      		if(ob->query("sockets/socket3") == "jin" || ob->query("sockets/socket3") == "amethyst")
	      			{
	      				ob->add("weapon/damage",-6*ob->query("sockets/socket3_level"));
	      			}
	      	}
	        }
	      ob->delete("armor/magic");
	      ob->delete("sockets");
	      generate_newitem(ob,0,2);
        message_vision("$n把身上的"+ob->query("name")+"交给了$N，"
	          +"$N拿起一把锤子叮叮当当敲了一会儿，说道：好了！\n",this_object(),who);      	                             
        return 1;
}            
int die()
{
        this_object()->command("ghost");
        return 1;
}
int do_compensate()  //此任务作为当机十分钟内的补偿，取消任务惩罚
{
        object me=this_player();
		mixed *tm=localtime(time());
        if ( ( uptime()>7200 &&
               query("compensate")<time() )  && 
             !wizardp(me))
        {
                tell_object(me,"你现在才来，黄花菜都凉了。\n");
                return 1;
        }
        
        if ((int)me->query("compensate")>0 && time()-(int)me->query("compensate")<=1800)
        {
           tell_object(me,"你刚才不是补偿过了吗？怎么又来要？\n");
           return 1;
        }
        me->set("compensate",time());
        //护镖任务
        if(me->query("in_dart"))
            {
                me->set_temp("yunbiao/lianxunum",0);
                me->delete("in_dart");
                me->delete("yunbiao"); 
                me->apply_condition("dart_limit",0);
            }
        //萧峰任务
        if(me->query("xiaofeng/on_job"))    
            {
                me->delete_temp("xiaofeng");
                me->delete("xiaofeng/on_job");
                me->set("xiaofeng/last_fail", time());    
            }
        //胡一刀
        if ( me->query("yidao/on_job"))
               me->delete("yidao/on_job"); 
        //华山送信
        if(me->query("huashan/on_songxin"))          
           {
               me->set("huashan/last_fail", time());
               me->delete_temp("huashan/songxin");
               me->delete("huashan/on_songxin");
               me->delete_temp("huashan/on_songxin");
           }
        //慕容玉玺        
        if (me->query("murong/yuxi"))       
           {
               me->delete("murong/yuxi");
               me->delete("murong/lianxu");   
           }
		//韩员外
		if (me->query("hyw/gogogo"))
		{
			me->delete("hyw/gogogo");
			me->delete("hyw/lianxu");
			me->delete("hyw/pin");
			me->delete("hyw_busy");
		}
		//萧半和
		if (me->query("banhejob_20")!=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]))//当日已完成20环的不补偿
		{
			me->delete("banhejob_lasttime/mday");
			me->delete("xiaobanheaskexp");
		}
		if (me->query("pyh/start"))
		{
			me->delete("pyh/start");
			me->add("pyh_suc/number",-1);
			if (time()-me->query("pyh/starttime")<1800)
			me->delete("pyh/starttime");
		}
		
/*		if ( me->query("max_neili")<me->query("hist_max_neili") )
		  me->set("max_neili", me->query("hist_max_neili") );
		
		if ( me->query("max_jingli")<me->query("hist_max_jingli") )
		  me->set("max_jingli", me->query("hist_max_jingli") );*/
    
    me->save();  
    command("gaoding "+me->query("id"));
    return 1;
}
