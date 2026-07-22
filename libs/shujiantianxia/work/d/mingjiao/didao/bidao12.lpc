// /d/mingjiao/bidao12.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
// Modify By Looklove@SJ 2001/1

#include <room.h>
inherit ROOM;
void create()
{ 
       set("short","秘道");
       set("long", @LONG
这里是秘道的尽头。四周皆是石壁。石壁上有几处碎石脱落，露出的地方
好象是几块石砖(zhuan)。南边是一间藏兵器的地方。
LONG);    
       set("exits", ([
                "westup" : __DIR__"bidao11",
                "south" : __DIR__"bidao13",
       ]));             
       set("item_desc", ([
               "wall" : "石壁，还是石壁，四周皆为石壁。\n",
               "zhuan" : "石壁上露出的几块石砖。\n"
       ]));            
       setup();
}

void check_trigger()
{
        if((int)query("pull_trigger")==4){
           message("vision", "\n你慢慢的从石壁上取下四块石砖，露出了一个洞口，恰好能融入一人进入。\n", this_object());
           set("exits/enter", __DIR__"bidao14");
           delete("pull_trigger");
           remove_call_out("close_passage");
           call_out("close_passage", 15);
        }
}

void close_passage()
{
        if(!query("exits/enter")) return;
         message("vision", "石砖塌了下来，将入口处堵住了。\n", this_object());
         delete("exits/enter");
}

void init()
{
        add_action("do_pull",({"pull", "la"}));
}

int do_pull(string arg)
{
        if( !arg || arg=="" ) return 0;
        if( this_player()->is_busy() || this_player()->is_fighting())
                return notify_fail("你正忙着呢！\n");
        if (this_player()->query_skill("force", 1 ) < 140) 
                return notify_fail("你深深的吸了口气，用力的推，无奈内力不够，确实推不动！\n");
        if (arg=="zhuan")
               return notify_fail("你吸了一口气，对着石砖一拉，感觉这块砖可以上下左右活动。\n");
        if (arg=="石砖")
                return notify_fail("你吸了一口气，用力对着石砖一拉，结果毫天动静。\n");
        if (arg=="zhuan left")
                return notify_fail("你吸了一口气，用力对着石砖向左一拉，结果毫天动静。\n");
        if (arg=="zhuan right")
                return notify_fail("你吸了一口气，用力对着石砖向右一拉，结果毫天动静。\n");
        if (arg=="zhuan down"){
                message_vision("$N吸了口气，取下了一块石砖。\n",this_player());
                add("pull_trigger", 1);
                this_player()->start_busy(1);
                check_trigger();
                return 1;
        }
        else{
             write("你要干什么？\n");
             return 1;
        }
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int valid_leave(object me,string dir)
{          
       object *inv = deep_inventory(me);
       object *obj;   
       if( me->query("combat_exp") < 350000 && dir == "enter")
            return notify_fail("你不知道里面有什么，心生胆怯不由收回了迈出的步子。\n");  
       obj = filter_array(inv,(:get_object:));
       if( sizeof(obj) && dir =="enter")
         return notify_fail ("明教重地，不许带人进入了！\n");
       return ::valid_leave(me, dir);
}
