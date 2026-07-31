// treen1.c
// 树林北1
inherit ROOM;
void create()
{
	set("short","树林");
	set("long",@long
这里的树长得都又高有大，粗大的树枝伸出来互相交叉在一起，遮住了阳
光，地上是茂密的杂草，间杂着许多不知名的野花，散发出了阵阵很好闻的香
气，在树上和杂草里有许多蛇在发出嘶嘶的声音。
long);
	set("exits",([
	    "southeast" : __DIR__"treee1",
          "southwest" : __DIR__"treew1",
          "south" : __DIR__"treen2", 
          "north" : __DIR__"haitan",
]));
set("objects",([
__DIR__"npc/dushe" : 2,
]));
	set("outdoors", "神龙岛");
       set("canfindsnake",1);
        setup();
	replace_program(ROOM);
}
	    	
