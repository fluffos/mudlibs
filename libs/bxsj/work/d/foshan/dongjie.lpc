// Room: dongjie.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "佛山东街");
	set("long", @LONG
这里就是佛山东街，北面有一家杂货铺，向西走就是佛山广场了。由
于西面就是佛山广场，很多人都往西去，所以人来人往看起来比较热闹。
LONG
	);
        set("outdoors","佛山");
	set("exits", ([ 
            "east" : __DIR__"dongjie2",
            "north" : __DIR__"grocer",
            "west" : __DIR__"guangchang",
]));

	set("no_clean_up", 0);
	set("coor/x",10);
  set("coor/y",-530);
   set("coor/z",0);
   setup();
}
