// Room: /d/huashan/chaoyang.c
// Date: Look 99/03/25

inherit ROOM;
#include <ansi.h>
int do_kan(string arg);
void create()
{
       set("short", "朝阳峰");
       set("long", @LONG
这里就是华山的东峰—朝阳峰，於此俯瞰，黄河隐显东迤如带，南望小孤
峰背倚山河。东壁悬崖上，更有一个巨型掌印，相传为「河神巨灵」劈山时所
留下的。西面有一片树林，灌木丛生，让人不敢深入。
LONG
        );
       set("exits", ([ 
                  "westdown" : __DIR__"zhenyue",
        ]));

        set("objects", ([ 
                __DIR__"npc/daoke" : 1,
        ]));
 
       set("outdoors", "华山" );

  
     set("coor/x",80);
  set("coor/y",40);
   set("coor/z",60);
   setup();
}

void init()
{
        object me = this_player();
        object weapon = me->query_temp("weapon");
        if (me->query("family/family_name") == "华山派" 
        &&  me->query_int() >= 32 
        &&  !me->query("hs/getchongling")
       &&  weapon 
        &&  weapon->query("skill_type") == "sword"
       &&  me->query_skill_mapped("sword") == "huashan-jianfa"
        &&  me->query("kar") <= 20 
        &&  me->query_skill("sword") > 70
        &&  me->query_skill("huashan-jianfa") > 70
        &&  me->query("neili") > 1000
        &&  me->query_skill("zixia-gong") > 70 
        &&  random(10) <= 7 ) {
        tell_object(me, YEL"你站在朝阳峰顶上象下俯望华山美丽的风景，突然看到一对人形正在舞剑。\n"NOR);
        me->set("hs/getchongling", 1);
       me->start_busy(random(15));
        call_out("do_wujian", 4, me);
        }
//      add_action("do_toukui","bihua");
        add_action("do_kan","kan");
} 

void do_wujian(object me)
{
//      object weapon = me->query("weapon");
//      object name = weapon->query("name");
        if (me && present(me, this_object())) tell_object(me, YEL"你禁不住也跟着比划起来。\n"NOR);
}

int do_kan(string arg)
{
        object me,ob;
        int i,j;
        
        me = this_player();
        ob = me->query_temp("weapon");

        if ( !arg || arg != "柴" )
                return notify_fail("你要砍什么？\n");
        if (me->is_busy())
                return notify_fail("你现在正忙着呢!\n");
        if( !ob || ob->query("id") != "chai dao")
                return notify_fail("你要用什么砍？用手么？\n");
        if ( !me->query_temp("hs/kc_job"))
                return notify_fail("你无聊地挥起柴刀，胡乱砍倒了些灌木。\n");
        if ( me->query("jing")< 100) return notify_fail ("你现在太累了。\n");
         if ( me->query_temp("kc_job/ok")) return notify_fail ("回去通知仆人来取柴禾吧。\n");

        i = random((int)me->query("con")/3);
        j = random((int)me->query("str")/3);
        if((int)me->query("jingli") < i
         ||(int)me->query("qi") < j){
                message_vision(HIR"$N一不小心，刀砍在自己手上。\n"NOR,me);
                me->unconcious();
                return 1;
        }        
        
        me->receive_damage("jingli", i);
        me->add("qi", -j);       
        
        if(((int)me->query_temp("kc_job/kan") > 15 + random(5))){
                me->set_temp("kc_job/ok",1);
                tell_object(me, "你把地上的柴禾捆成一捆，看来该回去了。\n");
                return 1;
        }
        message_vision("$N挥起柴刀，砍倒一片灌木，回身放在一旁。\n",me);
        me->start_busy(1);
        me->add_temp("kc_job/kan",1);
        
        if((int)me->query_skill("blade", 1) < 31
         && random(10) > 6 ){
          write(HIM"在砍柴的过程中，你对于刀的基本用法渐渐有了些体会。\n"NOR);
          me->improve_skill("blade", (int)(me->query("int") / 10));
        }
        return 1;
}
