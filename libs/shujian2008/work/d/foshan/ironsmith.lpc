// Room: ironsmith.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "铁匠铺");
	set("long", @LONG
这是一家简陋的打铁铺，中心摆着一个火炉，炉火把四周照得一片通
红，你一走进去就感到浑身火热。墙角堆满了已完工和未完工的菜刀、铁
锤、铁棍、匕首、盔甲等物。一位铁匠满头大汗挥舞着铁锤，专心致志地
在打铁。 
LONG
	);
	set("exits", ([ 
            "north" : __DIR__"dongjie2",
                     ]));
	set("objects", ([
                __DIR__"npc/smith": 1,
                       ]));
        
	set("coor/x",20);
  set("coor/y",-540);
   set("coor/z",0);
   setup();
}
