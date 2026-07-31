
//#include <room.h>

inherit ROOM;
void create()
{
	set("short", "黄河崖边");
	set("long", @long	
山崖下正是黄河。黄河流淌到这里，已经泥沙浑浊了。黄色的河水
在河床里翻滚着，咆哮着，卷起一个个巨大的漩窝，正是「秋风卷起千
层浪，晚日迎来万丈红」。
long );
	set("exits", ([
  
  "westup" : __DIR__"road1",
  "eastup" : __DIR__"huanghe2",
  
	]));
	set("objects", ([
		//__DIR__"npc/hou" : 1,
	]));
//	set("no_clean_up", 0);
	        set("outdoors", "shanxi");
        set("coor/x",-480);
        set("coor/y",-400);
        set("coor/z",100);
	setup();
	//replace_program(ROOM);
}

