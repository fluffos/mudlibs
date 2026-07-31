// trees2.c
// 树林南2
inherit ROOM;
void create()
{
	set("short","树林");
	set("long",@long
这里的树长得都又高有大，粗大的树枝伸出来互相交叉在一起遮住了
阳光，地上是茂密的杂草，间杂着许多不知名的野花，散发出阵阵很好闻
的香气，在树上和杂草里有许多蛇在发出嘶嘶的声音。北边隐隐约约地好
象有几间竹屋。
long);
	set("exits",([
//	    "north" : __DIR__"kongdi",
          "northeast" : __DIR__"treee1",
          "northwest" : __DIR__"treew1",
          "south" : __DIR__"trees1",
]));
set("objects",([
__DIR__"npc/dushe" : 2,
]));
	set("outdoors", "神龙岛");
       set("canfindsnake",1);
        setup();
	replace_program(ROOM);
}
	    	
