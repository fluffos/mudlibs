//Create by Chui
//02.12.2

#include <ansi.h>
#include <msg.h>
#include <skill.h>
#include <combat.h>
#include <weapon.h>
inherit ROOM;
int do_lian();
int do_practice(object me);
int halt_practice(object me);
int k;

void create()
{
        set("short", "海中");
        set("long", @LONG
迎对着势不可挡的大海，你不禁有点害怕。相传当年“西狂”大侠杨过，
就在这里练（lianjian）就了玄铁剑法。
LONG
        );
        set("no_clean_up", 0);
        set("objects", ([
        ]));
        setup();
}

void init()
{
          add_action("do_lian","lianjian");
          add_action("do_jump","jump");
          add_action("do_none","dz");
          add_action("do_none","dazuo");
          add_action("do_none","exercise");
          add_action("do_none","du");
          add_action("do_none","study");
          add_action("do_none","lian");
          add_action("do_none","practice");

}

int do_none()
{
        return 1;
}

int do_lian()
{
        object me;
        object weapon ;
       
        me = this_player();
        weapon = me->query_temp("weapon");
  
        if (me->is_busy())
        return notify_fail("你现在正忙着呢。\n");
        if(!weapon || weapon->query("skill_type") != "sword")
        return notify_fail("你必须使用武器才能练习「玄铁剑法」！\n"); 

  if((int)me->query_skill("dodge",1)<150||(int)me->query("neili")<200)
        { 
         message_vision("$N感到潮水冲击力太大，胸口一阵发蒙，\n\n",me);
        me->set("neili",0);
        me->set("eff_qi",50);
        me->unconcious();
        me->move("/d/quanzhou/jiang");
        return 1;
        }
        message_vision("$N挥舞手中剑对抗汹涌的海潮。。。。。。\n\n",me);
        me->set_temp("practicing");
        me->set_temp("practice");
        me->set_temp("pending/practice",60);
        me->start_busy("do_practice","halt_practice");
        return 1;
}
int do_practice(object me)
{
        mixed action;
        object weapon ;
       int skill,i,point,k,mykar,myint,jibie;
        string msg,str1,str2,str,arg;
        arg=me->query_temp("practicing");
        point=me->query_temp("pending/practice");
        weapon=me->query_temp("weapon");
        if(!weapon || weapon->query("skill_type") != "sword")
	        return notify_fail("你必须使用武器才能练习「玄铁剑法」！\n"); 
        skill=me->query_skill("xuantie-jian",1);
        mykar = me->query("kar");
        myint = me->query("int");
          if( mykar/myint < 1 )
          jibie = 1;
          else jibie = mykar/myint;
        if((int)me->query_skill("xuantie-jian",1) > 300*jibie)
                   return notify_fail("你对抗着海潮，觉得非常轻松。\n");
        msg=HIG+"$N正在对抗着海潮习练"+to_chinese("xuantie-jian")+"的一些技巧......"+NOR;
        if(weapon) 
        me->set_temp("practice", (: call_other, SKILL_D("xuantie-jian"), "query_action", me, weapon :) );
        else
        me->set_temp("practice",(: call_other, SKILL_D("xuantie-jian"), "query_action" :) );
        action=me->query_temp("practice");
        msg=action["action"];
        if(!stringp(msg))  msg="$N正在认真地习练"+to_chinese("xuantie-jian")+"的一些技巧......";
        msg=HIG+"\n    "+msg+"\n"+NOR;
        msg = replace_string(msg, "$w", weapon->name());
        msg = replace_string(msg, "$n", "");
        if (me->query_skill("xuantie-jian",1)> 1)
        message_vision(msg,me);
        if ((string)me->query_temp("weapon")->query("id") != "xuantie sword")
        k = 1 ;
        else  k = 3;
        skill=skill*10/((10+3*SKILL_D("xuantie-jian")->query_eff_level(me)));
              if (random((int)me->query("con")/3)<1&& k <3)
                {      
               message_vision(HIW"\n只听“嚓”的一声，$N手中的$n已断成两截！\n"NOR,me,weapon);
                weapon->unequip();
                weapon->move(environment(me));
                weapon->set("name", "断掉的" + weapon->query("name"));
		destruct(weapon);
                me->reset_action();
          return 0;
                }
        if(!weapon || weapon->query("skill_type") != "sword")
        return notify_fail("你必须使用武器才能练习「玄铁剑法」！\n"); 
        if((string)me->query("family/family_name")!="古墓派")
               {
           if ((me->query_skill("xuantie-jian",1))<1)
                {
                if (random(10000)>9998)
                {
                me->improve_skill("xuantie-jian",2);
                message_vision(HIR+"$N突然领悟了玄铁剑法的入门之道！！！\n\n"+NOR,me);
                me->add("jing",-50);
                me->add("neili",-20);
                }
                else 
                {
                message_vision(HIR+"$N使用手中剑，对抗着大海汹涌的潮水！！！\n\n"+NOR,me);
                me->improve_skill("sword",(int)me->query("int")*2);
                me->add("jing",-50);
                me->add("neili",-20);
                }
                }
		else {
		if ((me->query_skill("xuantie-jian",1))>100)
		{
                me->improve_skill("xuantie-jian",k*(int)me->query_int()/2);
                message_vision(HIY+"$N感觉到「玄铁剑法」进步啦！！！\n\n"+NOR,me);
                me->add("jing",-20);
                me->add("neili",-20);
		}
		else{
                me->improve_skill("xuantie-jian",k*2*(int)me->query("int")/5);
                message_vision(HIY+"$N感觉到「玄铁剑法」进步啦！！！\n\n"+NOR,me);
                me->add("jing",-20);
                me->add("neili",-20);
		}
                }                
            }
        else
        {
        me->improve_skill("xuantie-jian",k*(int)me->query_int());
        me->add("jing",-25);
        me->add("neili",-20);
        }
        me->add_temp("pending/practice",-1);
        if(me->query("neili")<200
        ||me->query("jing")<100
        ||me->query_temp("pending/practice")<10) {
        msg = sprintf(HIG"\n$N见海潮退去，松了一口气,暂停了%s.\n"NOR, to_chinese("xuantie-jian"));
        message_vision(msg,me);
        me->delete_temp("practicing");
        me->delete_temp("practice");
        me->delete_temp("pending/practice");
        return 0;
        }
        return 1;
}
int halt_practice(object me)
{
        me->delete_temp("practicing");
        me->delete_temp("pending/practice");
        me->delete_temp("skillname");
        me->delete_temp("practice");
        if ((int)me->query("neili")<100)
        {
        me->set("neili",0);
        message_vision("$N猛地一收招，海潮铺天盖地而来，内力不支，被冲到了岸边。\n", me);
        me->unconcious();
        }
        else 
        me->add("neili",-100);
        message_vision("$N猛地一收招，停止了出招。\n", me);
        return 1;
}
int do_jump(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg == "" ) 
        return notify_fail("滔滔潮水，你傻乎乎地又蹦又跳起来。\n");
        if((int)me->query("neili",1)<150)
        return notify_fail("就凭你这点武功，小心被潮水卷跑了。\n");
        if(me->is_busy())
        return notify_fail("你现在动都动不了，怎么跳啊，别逗了。\n");
        if( arg == "out")
        {
        message_vision("$N如同浪里白龙，飞身而出，跳致江边，。。。。。。\n",me);
		if (me->query_temp("pfm_skip"))
		{
			me->delete_temp("pfm_skip");
		}

        me->move("/d/quanzhou/jiang");
        return 1;
        }
        else
        return notify_fail("你要干什么？\n");
}
