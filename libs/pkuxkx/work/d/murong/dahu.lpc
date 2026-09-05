//dahu.c
//by hehe
//2003.3.5

#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "太湖");
        set("long",@LONG
这边水面上全是菱叶和红菱，清波之中，红菱绿叶，鲜艳非凡。
LONG); 
        
        set("no_task",1);
		setup();
}
void init()
{       
        object ob=this_player();
        if(!userp(ob)){
        ob->move("/d/murong/hubian1");
        return;
        }
}
