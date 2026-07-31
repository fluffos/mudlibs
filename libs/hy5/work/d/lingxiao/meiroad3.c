//LUCAS 2000-6-18
// Room: meiroad3.c

inherit ROOM;
#include <ansi.h> 
void init();
int pick(string);
void create()
{
        set("short","梅道");
        set("long",@LONG
这里种满了绿梅。站在这里，似乎看到了在凌霄城永远不可
能看到的春天一样。一阵微风吹来，在绿梅的海洋中荡起一阵涟
漪，同时将那股浸人心脾的素香，送到每个人的心中。东边就是
凌霄城的观景胜地戏梅亭了。
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "west"  : __DIR__"meiroad1",
            "east"  : __DIR__"ting",
        ]));
        set("objects", ([ 
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

