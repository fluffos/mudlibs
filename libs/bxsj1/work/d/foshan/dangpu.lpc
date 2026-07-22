//Room: dangpu.c

inherit ROOM;

void create()
{
	set("short", "当铺");
	set("long", @LONG
绕过高墙，当铺里一张高高的柜台，柜台后面坐着当铺的朝奉。这家
当铺是凤天南开的，十多年来从没人敢来胡混。朝奉们懒洋洋地爬在柜台
上。柜台上摆着一个牌子(paizi)。
LONG
	);
	set("exits", ([
            "north" : __DIR__"dongjie3",
]));
	set("no_fight", 1);
        set("no_sleep_room",1);
        set("no_clean_up", 0);
  

	set("item_desc", ([
	    "paizi" : "公平交易\n",
]));
	set("objects", ([
            __DIR__"npc/yu-chaofeng" : 1,
]));

	set("coor/x",30);
  set("coor/y",-540);
   set("coor/z",0);
   setup();
}

