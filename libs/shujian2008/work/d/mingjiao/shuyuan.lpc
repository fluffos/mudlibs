// shuyuan.c 书院
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short", HIC"书院"NOR);
       set("long", @LONG
这里是明教藏书之地，一排排的书架整齐的排列着，书架上放着各种各样
的书籍，院内经常有人打扫，书架上一尘不染。许多明教弟子正在此专心的研
读，彼此静悄悄的。东面是一条通向聚义堂的走廊。
LONG);    
       set("exits", ([
             "east" : __DIR__"wu1",		
       ]));             
       set("objects",([
	    "/d/baituo/obj/book1" : 1,
//          "/d/baituo/obj/book5" : 1,
	    "/d/shaolin/obj/fojing11" : 1,
            "/d/shaolin/obj/fojing21" : 1,
	    "/d/wudang/obj/ddj1" : 1,
            MEDICINE_D("m-book7") : 1,
            MEDICINE_D("m-book8") : 1,
            __DIR__"npc/yahuan" : 1,
        ]));
        set("no_fight", 1);
	setup();
}

int valid_leave(object ob, string dir)
{
	string* book = keys(query("objects"));
	object* shu = deep_inventory(ob);
	int i = sizeof(shu), count = 0;
	while (i--)
		if (member_array(base_name(shu[i]), book) != -1) count++;
	if (count > 1) return notify_fail("你一下子拿这么书，看得过来吗？\n");
        if (count) ob->set_temp("marks/院1", 1);
	return ::valid_leave(ob, dir);
}
