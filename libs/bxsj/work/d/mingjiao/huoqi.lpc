// buoqi.c 烈火旗
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
           set("short",HIR"烈火旗"NOR);
       set("long", @LONG
你一到这里就闻到一股股强烈的硫簧气味。这里就是烈火旗。这里放置着
各种各样的喷火枪，十多个旗下弟子正在小心翼翼制造硫簧弹，他们个个不但
是暗器名家，而且是火器名家。由此可以看出明教是多么的强大。北边是练武
场，东面是一条走廊，往南走就是兵器库了。
LONG);    
	set("exits", ([
		"east" : __DIR__"cl1",	
                "west" : __DIR__"didao/senlin-7",			
		"north" : __DIR__"wu2",
                "south" : __DIR__"bingqi",
	]));             
	set("objects",([
		__DIR__"npc/dizi3" : 3,
                CLASS_D("mingjiao") + "/xin" : 1,
	]));
        set("outdoors", "明教光明顶");
        set("coor/x",-250);
  set("coor/y",230);
   set("coor/z",120);
   setup();
}
