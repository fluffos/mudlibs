// treen2.c
// 树林北2
inherit ROOM;
void create()
{
	set("short","树林");
	set("long",@long
这里的树长得都又高有大，粗大的树枝伸出来互相交叉在一起，遮住了阳
光，地上是茂密的杂草，间杂着许多不知名的野花，散发出了阵阵很好闻的香
气，在树上和杂草里有许多蛇在发出嘶嘶的声音。南边隐隐约约地好象有几间
竹屋。
long);
	set("exits",([
	    "north" : __DIR__"treen1",
          "southeast" : __DIR__"treee1",
          "southwest" : __DIR__"treew1",
          "eastup" : __DIR__"sanpo7",
]));
set("objects",([
__DIR__"npc/dushe" : 2,
]));
	set("outdoors", "神龙岛");
       set("canfindsnake",1);
        setup();
}
	    	
