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
     if (random(me->query("kar")) <10 && me->query_con() < 30)
            {
     me->set_temp("last_damage_from", "在森林里筋疲力尽累");
             me->add("qi", -30);
             me->add("jing", -10);
             me->receive_wound("jing", 20);
             }else{
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

/**for 营救段誉 ***/
         if (me->query_temp("mark/steps") 
           && me->query_temp("mark/step")  
           && random(me->query("kar")) > 20
           && me->query_temp("duanyu/find2")
            ){
	call_out("kicking1", 0, me);
//            me->move(__DIR__"gaoshan");
            me->set("dali/pass", 1);
            me->delete_temp("mark/steps");
            me->delete_temp("mark/step");
              return notify_fail("你走到了一个高山上。\n");
         }
// Modify By River 关于不能太简单获得 lbwb ，只给四次机会 
         if (me->query_temp("mark/steps") < -8 || me->query_temp("mark/step") < -8 ){
           if(me->query_temp("duanyu/find2")){
             if(!me->query("dali/fail"))
               me->set("dali/fail", 1);
             else {
               me->add("dali/fail", 1);
               if( me->query("dali/fail") > 8)
                me->set("dali/fail", 8);
             }
           }
	call_out("kicking", 0, me);
//           me->move(__DIR__"xiaoxi");
           me->delete_temp("mark/steps");
           me->delete_temp("mark/step");
           if(me->query_temp("duanyu/find2") && me->query("dali/fail") > 4){
//           me->delete_temp("duanyu/find2");
              return notify_fail(HIW"\n你筋疲力尽地走出这段山路，沮丧地发现自己怎么也找不到四大恶人的行踪。\n"NOR);
           }
           else 
              return notify_fail("你筋疲力尽，终于走出了这段山路。\n");
        }           
        return ::valid_leave(me, dir);
}
void kicking(object me)
{
           me->move(__DIR__"xiaoxi");
}
void kicking1(object me)
{
            me->move(__DIR__"gaoshan");
}