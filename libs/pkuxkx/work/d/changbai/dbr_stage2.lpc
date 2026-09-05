//Zine 给盗宝人增加点麻烦

inherit ROOM;
#include <ansi.h>
int name();
string *shorts=({"荒地","山坡","溪间","草丛","树林","小道","废宅","破庙"});
string *colors=({HIR,RED,HIW,WHT,HIC,CYN,HIY,YEL,HIB,BLU,HIG,GRN,HIM,MAG,HBMAG,HBBLU,HBRED,HBRED,HBYEL,HBWHT,HBCYN});

void create()
{
	set("short", "荒地");
	set("long", "这里是一处荒地，人迹罕至，也不知道你怎么会来到这里的。\n");
    set("outdoors", "changbai");
    set("dbr_stage",1);
    set("no_task",1);
    set("real_dark",1);
    set("least_msg",1);
    setup();
    name();
}

void init()
{
    add_action("do_look","look");
}

int do_look(string arg)
{
    object me=this_player();
    if (arg=="out")
    {
        write(WHT"那边灰蒙蒙的，什么也看不清！\n"NOR);
        return 1;
    }
    return 0;
}

int name()
{
    int number=random(sizeof(shorts));
	set("short", colors[random(sizeof(colors))]+shorts[number]+NOR);
	set("long", "这里是一处"+shorts[number]+"，人迹罕至，也不知道你怎么会来到这里的。\n");
    if (this_object()->query("area"))
    {
        set("long", "这里是"+this_object()->query("area")+"附近的一处"+shorts[number]+"，人迹罕至，也不知道你怎么会来到这里的。\n");
    }
    return 1;
}

