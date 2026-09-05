// jiashan.c
// By Pingpang 
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "假山");
    set("long", @LONG
这是桃花林中的一座假山，上面怪石林立，千姿百态.
假山底下有一个洞,一个猴子在此把守。
LONG
    );
     set("exits", ([
	"south": __DIR__"chitang",
	"east" : __DIR__"taolin2",
	"enter": __DIR__"jiashandong",
 	"west" : __DIR__"taolin1", 
	  ]));
     set("objects",([__DIR__"npc/monkey1":1,]));                         
     set("no_fight",1);
    setup();
}
void init()
{
	object ob=this_player();
	message_vision(YEL"东面传来一股浓郁的桃花香，$N有点感到昏昏然了。\n"NOR,ob);
	ob->add("qi",-30);
	ob->add("jing",-30);
	ob->add("neili",-30);
	return;
}
int valid_leave(object me,string dir)
{
	if(dir=="enter"&&objectp(present("monkey",environment(me)))
	    && living(present("monkey",environment(me))))
		return notify_fail("猴子拦住你，说道:那是我们猴子的住地.\n");

  if (dir=="east" && !userp(me))
    return notify_fail("你老兄哪能出去呀？\n");

	return ::valid_leave(me,dir);
}
	
	
