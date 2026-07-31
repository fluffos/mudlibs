inherit ROOM;
void create()
{
	set("short", "隘口");
	set("long", @LONG
这里是长城的一个隘口，秦朝连接长城，每隔数十里建造一个隘口
用来驻扎军队，这里是这里的隘口平常是有官兵来到这里巡逻，现在突
厥控制了这里，也没有什么人来了。
LONG
	);
set("outdoors", "mayi");
set("valid_startroom", 1);
set("exits", ([
	        "northeast" : __DIR__"changcheng21",
	        "southwest" : __DIR__"changcheng19",

	]));
set("objects",([

  __DIR__"npc/bing":2,

  __DIR__"npc/wujiang":1,

  ]));
	
       setup();
	replace_program(ROOM);
}
