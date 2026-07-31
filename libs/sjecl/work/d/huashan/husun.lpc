// Room: /d/huashan/husun.c
// Date: Look 99/03/25

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "猢狲愁");
        set("long", @LONG
前面又是一处十分陡峭的山岭，上面有四只铁猿，盘踞台畔，据说以前从
华山水帘洞出来的猿猴，每到这里就要返回去，连它们也感到难于超越，此岭
因而得名。
LONG
        );
	set("objects",([
	  __DIR__"npc/monkey" : 1,
]));
        set("exits", ([ 
	  "northdown" : __DIR__"laojun",
	  "southup" : __DIR__"canglong",
]));
        set("outdoors", "华山" );

        set("coor/x",70);
  set("coor/y",60);
   set("coor/z",50);
   setup();
     
}
void init()
{
        add_action("do_look", "look");
        add_action("do_pa", ({ "climb", "pa" }));
} 
int do_look(string arg)
{
       if( !arg || arg == "" || arg !=  "tieyuan") return 0;
             write(
             "你仰头仔细观看上面的铁猿，忽然发现山崖的顶部似乎有些什麽东西。\n"
             );
             this_player()->set_temp("marks/look", 1);
             return 1;
}
int do_pa(string arg)
{
       object me;
       me = this_player(); 
        if (arg != "ya" ) return 0;
         if ( !arg ) return 0;

        if (!me->query_temp("marks/look"))
        return notify_fail("你要往那里爬？\n");
        
        if (!living(me)) return 0;
        if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 10) {
                message_vision("$N气喘嘘嘘，感到无法爬上去，摔了下来！\n", me);
                me->unconcious();
                return 1;
        } 
        if( (int)me->query_skill("dodge",1) < 80 ) {  
        message_vision(HIR"$N想要爬上山顶，无奈轻功不够，摔了下来！\n"NOR, me);
        me->unconcious();
        return 1;     
        }  
        message_vision("$N扒住突出的岩石，施展轻功爬了上去。\n", me);
        me->move(__DIR__"jinshe/biding");
        tell_room(environment(me), me->name() + "从下面爬了上来。\n", ({ me }));
        me->delete_temp("marks/look");
        return 1;
}
