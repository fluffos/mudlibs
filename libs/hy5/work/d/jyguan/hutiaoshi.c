// /d/dali/hutiao8
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "虎跳石南岸" NOR );
        set("long", @LONG
金沙江横摆在前面，拦住了去路，江面约宽三四丈江中有一块大石头，约
可以站两三人，江水冲激下来，遇到了巨石的阻碍，溅起无数的水沫，发出震
耳欲聋的声音，传说曾有一只老虎纵身一跳，跳在大石上，再一跳，就到了对
岸，所以人门把这里称为虎跳峡，这块石头称为虎跳石。
LONG
        );
        set("outdoors", "jyguan");

//        set("exits", ([
//               "up" :__DIR__"hutiao7",
//                      ]));

             
        setup();
       
}


void init()
{
	add_action("do_jump", "jump");
}


int do_jump(string arg)

  {
       
        object me, killer;
	int i, idodge, i_qi;

              me=this_player();
              i_qi = 500 / (int)me->query("int");
              idodge = (int)me->query_skill("dodge");
                                               
              if ( !arg || (arg != "stone"))
                     return notify_fail("你要跳河自杀呀！别傻了！\n");
              
              if ( idodge < 30 )  return notify_fail("你的轻功太差了，赶快去练练吧！\n");

              if ( (int)me->query("qi") < i_qi) 
                message("vinson","你太累了，恐怕跳不过去吧。\n", me);    

               else
                  { message("vision",
			me->name() + "一纵身，向江面上跳去。\n",
			environment(me),  );

                    me->move(__DIR__"hutiaoshi");

                        message("vision",
			"只见人影一闪"+me->name() + "从岸上跳了上来。\n",
			environment(me), ({me}) );
                message("vinson","你纵身一跳，嗖的一声，稳稳的落在了虎跳石上。\n", me);    
                me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
                me->receive_damage("qi", i_qi );
               
                 }                              
                return 1;
             }          