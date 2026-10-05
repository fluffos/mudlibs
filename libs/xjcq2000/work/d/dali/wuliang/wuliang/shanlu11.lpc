#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
你信步而行，举步踏到的尽是矮树长草，这里没有路,每走一步，荆棘都
钩刺到小腿,划破你的身体。
LONG
        );
        set("outdoors", "dali");

        set("exits", ([
           "south" : __DIR__"shanlu11",
           "north" : __DIR__"shanlu11",
           "west" : __DIR__"shanlu11",
           "east" : __DIR__"shanlu11",
        ]));

        setup();
}


void init()
{    
        object me = this_player();
        if( me->query("dali/pass") && me->query("dali/fail") < 3 && me->query_skill("lingbo-weibu", 1) < 140){
           me->move(__DIR__"gaoshan");
           message_vision("$N熟悉地绕过森林，来到一个高山上。\n", me);
        }
        if (random(me->query("kar")) <10 && me->query_con() < 30){
           me->set_temp("last_damage_from", "在森林里筋疲力尽累");
           me->add("qi", -30);
           me->add("jingli", -10);
           me->receive_wound("jing", 20);
        }
        else{
             me->add("qi", -20);
        }    
        add_action("do_look", "look");               
}

int do_look()
{
        object me = this_player();
        mixed *local;
        local = localtime(time() * 60);
        if((local[2] < 3 || local[2] >= 21)&&random(6)<2) {
        message("vision",BLU"天黑了,这里黑黝黝一片，伸手不见五指,你四处乱走着,心里充满恐惧.\n"
                           "突然传来几声野兽的嚎叫,你吓的哭了起来.\n"NOR, me);
        }
}

int valid_leave(object me, string dir)
{
        mixed *local;
        local = localtime(time() * 60);
        if (dir == "west")
          me->add_temp("mark/steps",1);
        if (dir == "south")
          me->add_temp("mark/step",-1);
       if (dir == "east")
          me->add_temp("mark/steps",-1); 
        if (dir == "north")
          me->add_temp("mark/step",1);
/**for 一灯,will be written later***
        if (me->query_temp("mark/steps") == -7 && me->query_temp("mark/step") == -4
            && random(me->query("kar"))>15
            && (local[2] < 3 || local[2] >= 21)){
            me->move(__DIR__"senlin-1");
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
             return notify_fail("你正走着，突然发现前面好象有了一点灯光。\n");
         }  
*/
/**for 营救段誉 ***/
         if (me->query_temp("mark/steps") == me->query_temp("duanyu/steps") 
           && me->query_temp("mark/step") == me->query_temp("duanyu/step")  
           && random(me->query("kar")) > 20
           &&(local[2] < 6 || local[2] >= 3)
           && me->query_temp("duanyu/find2")
           && me->query("dali/fail") < 3 ){
            me->move(__DIR__"gaoshan");
            log_file("quest/lbwb",sprintf("%s %s(%s)顺利通过山路，走上寻找凌波微步之路。\n",
                ctime(time())[4..19],me->name(1), capitalize(getuid(me))));
            me->set("dali/pass", 1);
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
              return notify_fail("你走到了一个高山上。\n");
         }
// Modify By River 关于不能太简单获得 lbwb ，只给三次机会 
         if (me->query_temp("mark/steps") < -8 || me->query_temp("mark/step") < -8 ){
           if(me->query_temp("duanyu/find2")){
               me->add("dali/fail", 1);
               log_file("quest/lbwb",sprintf("%s %s(%s)第%d次机会没有掌握，未能顺利通过山路。\n",
                ctime(time())[4..19],me->name(1), capitalize(getuid(me)),me->query("dali/fail") ));
               if( me->query("dali/fail") >= 3)
                me->set("dali/fail", 3);
           }
           me->move(__DIR__"xiaoxi");
           me->delete_temp("mark/steps");
           me->delete_temp("mark/step");
           if(me->query_temp("duanyu/find2") && me->query("dali/fail") >= 3){
              me->delete_temp("duanyu/find2");
              log_file("quest/lbwb",sprintf("%s %s(%s)三次机会没有掌握，失去寻找凌波微步的机会。\n",
                ctime(time())[4..19],me->name(1), capitalize(getuid(me))));
              return notify_fail(HIW"\n你筋疲力尽地走出这段山路，沮丧地发现自己怎么也找不到四大恶人的行踪。\n"NOR);
           }
           else 
              return notify_fail("你筋疲力尽，终于走出了这段山路。\n");
        }           
        return ::valid_leave(me, dir);
}
