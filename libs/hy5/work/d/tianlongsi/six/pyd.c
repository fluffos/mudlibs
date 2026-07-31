//普云阁
//cool@SJ,990605

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIY"普云洞"NOR);
         set("long",
"原来这普云阁乃是一个小山洞，一进洞，门就无声无息的关闭了，洞内一尘不染，非常干净，
光线来自洞顶，似乎有块非常大的宝石，四周墙壁依此挂着六张图谱(tupu)，地上放着几个蒲团，
你随便找了个地方坐了下来。\n"
);
         
         set("item_desc", ([
             "tupu" : "图谱上绘着经脉穴位图，分别是六路神剑的运气法门。\n",
]));

set("exits", ([
	       "out" : __DIR__"lsy",
        ]));
      
//         create_door("out", "石门", "enter", DOOR_CLOSED);
setup();
}

int init()
{
        add_action("do_kan","kan");  
        add_action("do_kan","du");
        add_action("do_kan","yandu");
        add_action("do_kan","lingwu");
        add_action("do_kan","study");
}

int do_kan(string arg)
{         object me;
        me = this_player();
        if ( !living(this_player()) || arg != "tupu" )
                 return 0;
//        if (me->query("family/master_name")!="枯荣大师" )  
//        return 0;
        if ( (int)me->query_skill("literate", 1) < 1)
                 return notify_fail("你是个文盲，先学点文化(literate)再领悟六脉神剑吧。\n");
	if ( (int)me->query_skill("yiyang-zhi", 1) < 160 )
                 return notify_fail("凭你现在的一阳指修为，无法领悟六脉神剑这么高深的武功。\n");
        if ((int)me->query_skill("six-finger", 1) > 200)
                 return notify_fail("你思索了很久，似乎有些地方总是无法明白！\n");
        if ( (int)me->query("max_neili")<2500 && (int)me->query_skill("six-finger",1)>=30)
                 return notify_fail("你只觉内力似乎不够，总是无法运气成束。\n");
        if ( (int)me->query("max_neili")<3000 && (int)me->query_skill("six-finger",1)>=60)
                 return notify_fail("你只觉内力似乎不够，总是无法运气成束。\n");
        if ( (int)me->query("max_neili")<3200 && (int)me->query_skill("six-finger",1)>=90)
                  return notify_fail("你只觉内力似乎不够，总是无法运气成束。\n");
        if ( (int)me->query("max_neili")<3500 && (int)me->query_skill("six-finger",1)>=120)
                  return notify_fail("你只觉内力似乎不够，总是无法运气成束。\n");
        if ( (int)me->query("max_neili")<4500 && (int)me->query_skill("six-finger",1)>=150)
                  return notify_fail("你只觉内力似乎不够，总是无法运气成束。\n");
         
        if ( (int)me->query("jing")<100) {
                 write("你太累了，已经没有精神来领悟了！\n");              
                 return 1;
        }
	me->receive_damage("jing", random(me->query_skill("six-finger",1))/2+10);
        message_vision("$N正在仔细的看着图谱。\n", me);
        if (me->query_skill("six-finger",1)<50)  
        write("你仔细琢磨少泽剑谱，终于有了一点体会。\n");
        if (me->query_skill("six-finger",1)>=70 && me->query_skill("six-finger",1)<60 )  
        write("你仔细琢磨关冲剑谱，终于有了一点体会。\n");
        if (me->query_skill("six-finger",1)>=90 && me->query_skill("six-finger",1)<90 )  
        write("你仔细琢磨商阳剑谱，终于有了一点体会。\n");
        if (me->query_skill("six-finger",1)>=120 && me->query_skill("six-finger",1)<120 )  
        write("你仔细琢磨中冲剑谱，终于有了一点体会。\n");
        if (me->query_skill("six-finger",1)>=150 && me->query_skill("six-finger",1)<150 )  
        write("你仔细琢磨少冲剑谱，终于有了一点体会。\n");
        if (me->query_skill("six-finger",1)>=180)  
        write("你仔细琢磨少商剑谱，终于有了一点体会。\n");
        me->improve_skill("six-finger", me->query_skill("finger")/10);
         return 1;
}
