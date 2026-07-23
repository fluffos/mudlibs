inherit ROOM;

void create()
{
	set("short", "青岩镇");
	set("long", @LONG
青岩古镇历史悠久，自明洪武十一年(公元1378年)设青岩堡至
今已有600多年了。明初，中央王朝为了控制西南边陲，于洪武六年
(公元1373年)置贵州卫指挥使司，以控制川、滇、湘、桂驿道，因
青岩位于广西入贵阳门户的贵(阳)番(定番，今惠水县)主驿道之中
段，在驿道上设传递公文日"铺"和传递军情的"塘"。驻军于双狮峰
下驿道旁建屯，史称"青岩屯"。	
LONG );
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
	set("exits", ([
               "west"      : __DIR__"jinyong-cheng",
               "northwest"      : __DIR__"tulu4",
               "south"      : __DIR__"tulu5",		
	]));

 	set("outdoors", "guizhou");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



