// shanlu10.c By River 98/09

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIY"断肠崖"NOR);
    set("long", @LONG
那悬崖下临深谷，上面山峰笔立，峰顶深入云雾之中，不知尽头。“断肠
崖”前后风景清幽，只因地势实在太险，山石滑溜溜，极易掉入深渊，人们轻
易不敢来此。
LONG
     );

    set("exits", ([ 
	"westdown"  : __DIR__"shanlu9",        	
    ]));
    set("outdoors", "绝情谷");
    setup();    
}

void init()
{
        add_action("do_look", "look");
        add_action("do_jump", "jump");
}

int do_look(string arg)
{
       if( !arg || arg == "" || arg !=  "ya") return 0;
       write("你仔细打量四周。发现在不远处有一块突出来的峭壁，可以勉强容身。\n");
       this_player()->set_temp("jqg_look1", 1);
       return 1;     
}

int do_jump(string arg)
{
       object me,*ob;
       int i;
       me = this_player(); 
       if (arg != "qiaobi" ) return 0;
       if ( !arg ) return 0;
       if (!me->query_temp("jqg_look1"))
          return notify_fail("你要往那里跳？\n");
       ob = deep_inventory(me);
       i = sizeof(ob);
       while (i--)
       if (ob[i]->is_character())
         return notify_fail("你身上背负一个人，无法轻松跳过去。\n");      
       if (!living(me)) return 0; 
       if((int)me->query_skill("dodge",1) < 100 )  
           return notify_fail("以你目前的轻功修为，无法跳过去。\n"); 
       message_vision("$N纵身向前面的峭壁跳了过去。\n", me);
       me->move(__DIR__"duanchang");
       tell_room(environment(me), me->name() + "从断肠崖跳了过来。\n", ({ me }));
       me->delete_temp("jqg_look1");
       return 1;
}
