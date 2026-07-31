// Room: /d/taiwan/huayuan.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "小花园");
	set("long", @LONG
你的眼前是一个小花园,因为已经很久没人打扫,到处都是残枝败叶. 
你刚才出来的那座假山就摆在花园中间,北面有一座小楼. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/taiwan");
	set("exits", ([ /* sizeof() == 3 */
  "in" : __DIR__"midao2.c",
  "north" : __DIR__"xiaolou",
  "west" : __DIR__"caiyuan",
]));

	setup();
	replace_program(ROOM);
}
