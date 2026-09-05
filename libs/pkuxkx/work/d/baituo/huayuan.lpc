// Room: /d/baituo/huayuan.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "花园");
	set("long", @LONG
这是个美丽的大花园，园子里面种着鲜艳的红玫瑰。白衣少女常
来这里嬉戏。沿着弯弯曲曲的花径，可以通到山庄的许多地方。东边
是座假山，堆砌得颇有江南园林的那种秀丽的风格，出现在西域真是
难能可贵。西边是白驼山庄的少主人『欧阳克』的内室，门虚掩着，
不知主人在不在。
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ 
  __DIR__"npc/whitelady" : 2,
]));
	set("outdoors", "baituo");
	set("exits", ([ 
  "south" : __DIR__"menlang",
  "east" : __DIR__"xiaojing",
  "north" : __DIR__"zhailuo",
  "west" : __DIR__"neishi",
]));

	setup();
	replace_program(ROOM);
}
