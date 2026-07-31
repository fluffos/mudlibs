inherit ROOM;

#include <ansi.h>
void create()
{
  set("short",HIG"北斗大阵"NOR);
  set("long",@LONG
江湖上几乎是人人都曾耳闻过着北斗阵的厉害，却很少有人真的曾经亲眼见识过此阵。 
敌人来攻时,正面首当其冲者不用出力招架,却由身旁道侣侧击反攻,犹如一人身兼数人功力,
的确威不可当。若陷入天罡北斗阵,除非将七人中打倒一人,否则决然无法逃出.阵中七人以
静制动,击首则尾应,击尾则首应,击腰则首尾皆应,牢牢将敌人困于阵中。
LONG);

     set("outdoors", "xiaoyao");
     set("exits",([
           "east" : __DIR__"jianzhen",
           "west" : __DIR__"jianzhen",
           "north" : __DIR__"jianzhen",
           "south" : __DIR__"jianzhen",
     ]));
 	set("objects", ([
		__DIR__"npc/qiwushi" : 3,
	]));
     setup();
}
int valid_leave(object me, string dir)
{
object fang;



	if ( objectp(present("qz dizi", environment(me))) )
		return notify_fail("全真弟子拦住了你的去路。\n");




        if ((int)me->query_temp("marks/steps") == -12 && (int)me->query_temp("marks/step") == 18)
         {
            me->move(__DIR__"damen");
     	fang = load_object("/kungfu/class/xueshan/huodu");
	fang->move(environment(me));	
        fang->kill_ob(me);    
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("你正在绝望时,走着走着，破了这个北斗大阵。\n");
         }  

        if ((int)me->query_temp("marks/steps") == -13 && (int)me->query_temp("marks/step") == 19)
         {
            me->move(__DIR__"damen");
     	fang = load_object("/kungfu/class/xueshan/huodu");
	fang->move(environment(me));	
        fang->kill_ob(me);    
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("你正在绝望时,走着走着，破了这个北斗大阵。\n");
         }  
         

        if ((int)me->query_temp("marks/steps") == 13 && (int)me->query_temp("marks/step") == -19)
         {
            me->move(__DIR__"damen");
     	fang = load_object("/kungfu/class/xueshan/huodu");
	fang->move(environment(me));	
        fang->kill_ob(me);    
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("你正在绝望时,走着走着，破了这个北斗大阵。\n");
         }  
         
        if ((int)me->query_temp("marks/steps") == 12 && (int)me->query_temp("marks/step") == -18)
         {
            me->move(__DIR__"damen");
     	fang = load_object("/kungfu/class/xueshan/huodu");
	fang->move(environment(me));	
        fang->kill_ob(me);    
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("你正在绝望时,走着走着，破了这个北斗大阵。\n");
         }  


        if ((int)me->query_temp("marks/steps") >= 99 && (int)me->query_temp("marks/step") <= -99)
         {
            me->move(__DIR__"damen");
     	fang = load_object("/kungfu/class/xueshan/huodu");
	fang->move(environment(me));	
        fang->kill_ob(me);    
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("你正在绝望时,走着走着，破了这个北斗大阵。\n");
         }  

        if ((int)me->query_temp("marks/steps") >= 99 && (int)me->query_temp("marks/step") >= 99)
         {
            me->move(__DIR__"damen");
     	fang = load_object("/kungfu/class/xueshan/huodu");
	fang->move(environment(me));	
        fang->kill_ob(me);    
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("你正在绝望时,走着走着，破了这个北斗大阵。\n");
         }  


        if ((int)me->query_temp("marks/steps") <= -99 && (int)me->query_temp("marks/step") >= 99)
         {
            me->move(__DIR__"damen");
     	fang = load_object("/kungfu/class/xueshan/huodu");
	fang->move(environment(me));	
        fang->kill_ob(me);    
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("你正在绝望时,走着走着，破了这个北斗大阵。\n");
         }  


 if ( (int)me->query_temp("marks/steps")> 13 )
 tell_object(me, "看来你向南走的超出范围了。\n");
 
 if ( (int)me->query_temp("marks/steps")< -13 )
 tell_object(me, "看来你向北走的超出范围了。\n");
                  
 if ((int)me->query_temp("marks/step")>19 )
 tell_object(me, "看来你向东走的超出范围了。\n");

 if ((int)me->query_temp("marks/step")<-19 )
 tell_object(me, "看来你向西走的超出范围了。\n");

 



 if ( (int)me->query_temp("marks/steps")> 0 && (int)me->query_temp("marks/step")>0 )
 tell_object(me, "看来你向东走太多了。\n");

if ( (int)me->query_temp("marks/steps")< 0 && (int)me->query_temp("marks/step")<0 )
 tell_object(me, "看来你向西走太多了。\n");

 if ( (int)me->query_temp("marks/steps")> 0 && (int)me->query_temp("marks/step")>0 )
 tell_object(me, "看来你向南走太多了。\n");

if ( (int)me->query_temp("marks/steps")< 0 && (int)me->query_temp("marks/step")<0 )
 tell_object(me, "看来你向北走太多了。\n");


         
if (userp(me) && random(5)==0)
{
     	fang = load_object(__DIR__"npc/qiwushi");
	fang->move(environment(me));	
	fang->kill_ob(me);
		return notify_fail("突然北斗大阵发生了变化，出现一个全真弟子拦住了你的去路。\n");	
	
}
if (wizardp(me))
{
 tell_object(me, "marks/steps" + me->query_temp("marks/step") + "。\n");
 tell_object(me, "marks/step" + me->query_temp("marks/steps") + "。\n");
}
                   if (dir == "east")
         me->add_temp("marks/step",1);

        if (dir == "west")
          me->add_temp("marks/step",-1); 


        if (dir == "south")
          me->add_temp("marks/steps",1);
        if (dir == "north")
          me->add_temp("marks/steps",-1);
        return ::valid_leave(me, dir);
}

