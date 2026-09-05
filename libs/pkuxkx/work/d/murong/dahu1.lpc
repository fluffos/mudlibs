//dahu1.c
//by hehe
//2003.3.5

#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "太湖");
        set("long",@LONG
舟行湖上，几个转折，便转入了太湖之中，极目望去，但见烟波浩渺，远水接天。
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
