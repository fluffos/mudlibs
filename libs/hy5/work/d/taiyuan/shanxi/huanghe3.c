// Room: /huanghe/huanghe2.c
// Java. Sep 21 1998
inherit ROOM;
void create()
{
	set("short", "黄河崖边");
	set("long", @long
山崖下正是黄河。黄河流淌到这里，已经泥沙浑浊了。黄色的河水
在河床里翻滚着，咆哮着，卷起一个个巨大的漩窝，千峰竟秀，万壑争
奇，松涛云海，飞瀑流泉，荟萃了太行山的壮美风光。
long );
	set("exits", ([
  
  "westup" : __DIR__"wutai",
  "eastdown" : __DIR__"huanghe4",
  
  
	]));
	set("objects", ([
		//__DIR__"npc/hou" : 1,
	]));
//	set("no_clean_up", 0);
	        set("outdoors", "shanxi");
        set("coor/x",-500);
        set("coor/y",-400);
        set("coor/z",100);
	setup();
	//replace_program(ROOM);
}
