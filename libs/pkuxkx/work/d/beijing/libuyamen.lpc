// Room: /d/beijing/libu.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", RED"礼部府衙大门"NOR);
        set("long",
CYN"礼部衙门这几天里，白天车水马龙，夜里灯烛辉煌，满汉尚书、侍郎
、各司主事忙得团团转，据说皇上要出巡，所以这帮大小官员一个个累得
力尽神疲，衙门前就见这班官员不停的进进出出，热闹极了。\n"NOR
        );

        set("exits", ([
                 "north": __DIR__"guloudajie_e",
                 "south": __DIR__"libuyamen2",
        ]));
	set("objects", ([
	    "/d/beijing/npc/shiwei":4,
	]));
        setup();

}
int valid_leave(object me, string dir)
{
    int i;
    object *ob;
    if( dir !="south" || me->query("class") == "officer")
        return ::valid_leave(me, dir);
    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++) 
    {
        if( living(ob[i]) && ob[i]->query("id") == "shi wei" )
            return notify_fail("侍卫伸手拦住你朗声说道：里面没什么好看的，马上离开这里....！\n");
    }            
    return ::valid_leave(me, dir);
}

