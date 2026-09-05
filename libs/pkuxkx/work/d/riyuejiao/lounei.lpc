//lounei.c	竹篓内
//by bing
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","竹篓内");
	set("long",@LONG 
这是大竹篓的内部。竹篓正在缓缓升高，抬头上望，只见头顶有数点火星，
俯视篓底，但见黑沉沉的一片，连灯火也望不到了。可见到一片片白云从头顶飘过。
LONG
	);
	set("number",0);
    set("no_dbr_stage",1);
	set("hsz_no_task",1);    
	set("no_task",1);
    set("ry_lou_1",1);
	setup();

}

void init()
{
        object ob=this_player();
        if(!userp(ob)){
        ob->move("/d/riyuejiao/yaxia");
        return;
        }

}


