// senlin-2.c 紫杉林
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",MAG"紫杉林"NOR);
       set("long", @LONG
这里是明教光明顶上的一片紫杉林。周围全是几十丈高的紫杉，密实的枝
叶象一蓬蓬巨伞般伸向天空，把阳光遮得丝毫也无。你一走进这阴阴的森林，
直觉便提醒你得赶快离开。
LONG);    
	set("exits", ([
		"north" : __DIR__"senlin-"+(1+random(5)),
		"south" : __DIR__"senlin-"+(1+random(5)),
                "east" : __DIR__"senlin-"+(1+random(5)),
                "west" : __DIR__"senlin-"+(1+random(5)),
	]));
        set("outdoors", "明教光明顶");
        set("coor/x",-260);
  set("coor/y",200);
   set("coor/z",120);
   set("coor/x",-260);
 set("coor/y",200);
   set("coor/z",120);
   setup();
}

void init()
{
       set("exits/east", __DIR__"senlin-"+(1+random(5)) );
       set("exits/south", __DIR__"senlin-"+(1+random(5)) );
       set("exits/west",  __DIR__"senlin-"+(1+random(5)) );
       set("exits/north",  __DIR__"senlin-"+(1+random(5)));
}
