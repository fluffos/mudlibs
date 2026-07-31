inherit ROOM;

void create()
{
	set("short", "贵阳北门");
	set("long", @LONG
此间是贵阳城的北门，是为贵州重镇。城墙由石块和土垒成，高二
丈五，厚达二丈。城下三两个盔甲鲜明的军士瞪大了眼睛观察着来来往
往的行人，偶尔盘问几个形迹可疑份子。
LONG );

	set("exits", ([
                          "north"      : __DIR__"dadao1",
                         "south"      : __DIR__"beishi",
	                  "northwest":__DIR__"qingshilu4",	
	]));
          set("objects",([
           __DIR__"npc/bing":2,
           __DIR__"npc/wujiang":1,
           ]));

 	set("outdoors", "guizhou");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



