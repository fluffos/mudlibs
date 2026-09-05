//dahu4.c
//by hehe
//2003.3.5

#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "太湖");
        set("long",@LONG
如此曲曲折折的划了两个多时辰，遥遥望见远处绿柳丛中，
露出一角飞檐。
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
