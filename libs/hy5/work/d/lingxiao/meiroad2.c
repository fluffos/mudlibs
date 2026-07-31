//LUCAS 2000-6-18
// Room: meiroad2.c

inherit ROOM;
#include <ansi.h> 
void init();
int pick(string);
void create()
{
        set("short","梅道");
        set("long",@LONG 
这也是一条充满梅花清香的小道。与殿外不同的是，这儿种
满了梅树，而且全是如鲜血般灿烂的红梅，花瓣片片飘落，落到
洁白的雪地上，就如一个温婉和顺的美人，在给自己的心上人刺
绣时，不小心刺破了手指而流出的一滴血，浸到了白绢上一样。
一只通体雪白的雪鹤在地上翩然起舞，逍遥自得。
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "west"  : __DIR__"stone",
            "east"  : __DIR__"meiroad1",
        ]));
        set("objects", ([
                __DIR__"npc/xuehe" : 1,
                __DIR__"obj/ban" : 1,
        ]));
        setup();
}

void init()
{
 add_action("do_pick","pick");
}

int do_pick(string arg)
{
 object me=this_player();
 object ob;
 if (!arg||arg!="hua")
  return notify_fail("你要摘什么？\n");
 ob=new(__DIR__"obj/mei");
 ob->move(me);
 message_vision("$N从路旁的树上摘了一朵梅花。\n" , me);
 return 1;
}

