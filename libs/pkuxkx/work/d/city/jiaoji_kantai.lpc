// Room: /city/shanzhuang.c
// YZC 1998/3/22
// --by kuer-- 

#include <room.h>
#include <ansi.h>
inherit ROOM;

int do_lock();
int do_unlock();
int do_look(string arg);

void create()
{
	set("short", GRN"看台"NOR);
	set("long", @LONG
这是一座竹子搭建的看台，从这里可以清楚的看到较技场里发生的一切。
LONG);

	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");


	set("exits", ([
		"west": __DIR__"jiaojichang",
        "east": __DIR__"shanzhuang",		    
	]));
	setup();	
}

void init()
{
    add_action("do_lock","lock");
    add_action("do_unlock","unlock");
    add_action("do_look","look");
}

int do_lock()
{
    object me = this_player();
    object ob = this_object();
    
    if(wizardp(me) && ob->query("locked") != 1)
    {
        ob->set("locked",1);
        message_vision("$N把通向较技场的大门锁上了.\n",me);
        return 1;
    }
    return 0;
}

int do_unlock()
{
    object me = this_player();
    object ob = this_object();
    
    if(wizardp(me) && ob->query("locked") == 1)
    {
        ob->set("locked",0);
        message_vision("$N把通向较技场的大门打开了.\n",me);
        return 1;
    }
    return 0;
}

int valid_leave(object me, string dir)
{
	if ( dir =="west" && !wizardp(me) && query("locked") == 1)
		return notify_fail("通向较技场的大门锁上了\n");
	return ::valid_leave(me, dir);
}

int do_look(string arg)
{
	if(arg=="west")
	{
	    if(query("locked") == 1)
	    {
		    tell_object(this_player(), "通向较技场的大门锁上了\n");	
		    return 1;
		}        
	}
	return 0;
}