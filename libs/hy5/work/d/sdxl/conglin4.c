// Room: /d/xiangyang/conglin4.c
// by dubei
#include <ansi.h>
inherit ROOM;

string xiaowu(object);
string shanlu(object);
 

void create()
{
	set("short", "山路");
	set("long", @LONG
这里是山麓(shanlu)上的一块空地，路旁的杂草和树木被人
休整过了。路旁有一个用树木搭起的小屋，小屋(xiaowu)的门口
有一些猎人在休息。一些弓箭和绳索挂在路旁的树上。
LONG	);
	set("exits", ([  
        "eastdown" : __DIR__"conglin3",
          
        ]));
    set("item_desc", ([
                "xiaowu" : (: xiaowu :),
               "shanlu" : (: shanlu :),
    ]));
        set("objects",([
              __DIR__"npc/shijiqiang" : 1,
              __DIR__"npc/shibowei" : 1,
              __DIR__"npc/shimengjie" : 1,
              __DIR__"npc/shishugang" : 1,
              __DIR__"npc/shizhongmeng" : 1,
        ]));      
	 
        set("outdoors", "xiangyang");
	setup();
}
 
string xiaowu(object me)
{
            me = this_player();
            if(!me->query_temp("make/xtj_look1")){
            return "一间普通的小木屋。\n";
            }
            me->set_temp("make/xtj_enter",1);
            return "一间普通的小木屋，屋门半掩着，里面似乎堆积着一些杂物。\n";
}
string shanlu(object me)
{
            me = this_player();
            if (!me->query_temp("make/xtj_look1")){
            return "一座高耸的山麓。\n";
            }
            me->set_temp("make/xtj_shan",1);
          return "一座高耸的山麓，你似乎感觉到那里似乎有些什麽。\n";
}
void init()
{
    object ob = this_player();

    if(!userp(ob)) return;

 
    if(interactive(ob) && (int)ob->query_skill("force") > 100
    && random(20) < 5){
    write("你忽然听见北面的山后传来几声雕鸣。\n",this_player());
    ob->set_temp("make/xtj_look1",1);
        }
 
    add_action("do_enter", "enter");
    add_action("do_enter", "jin");
    add_action("do_climb", "climb");
}
int do_enter(string arg)
{
    object me=this_player(); 
       if (!me->query_temp("make/xtj_enter"))
       return 0;
      
    if((!arg) || (arg != "muwu"))
        return notify_fail("你要进那里？\n");
     message_vision("$N轻轻推开门，走进了木屋。\n", me);
    me->delete_temp("make/xtj_enter");
       me->move(__DIR__"muwu");
    message("vision", me->name() + "推门走了进来。\n", environment(me), ({me}) );
    return 1;
}
int do_climb(string arg)
{
    object me=this_player(); 
    if (!me->query_temp("make/xtj_shan"))
    return 0;
    if((!arg) || (arg != "shanlu"))
    return notify_fail("你向那里爬？\n");
    me->delete_temp("make/xtj_shan");
    message_vision("$N微微提气，纵身向北面的山麓爬去。\n", me);
    me->move(__DIR__"linhai1");
    message("vision", me->name() + "从下面爬了上来。\n", environment(me), ({me}) );
    return 1;
}

