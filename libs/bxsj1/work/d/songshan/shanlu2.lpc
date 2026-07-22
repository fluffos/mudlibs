// Room: /u/swl/songshan/shanlu2.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
行路似乎越来越难了，沿着道路西行山路出现了岔道，你向路边望
去发现一个路标(sign)指引你的方向。一阵清风袭来，松涛阵阵。而向
东的路则趋向平坦了。
LONG);
	set("item_desc", ([ 
            "sign" : "
       西北：嵩山剑派
       东南：嵩山少林寺\n\n",
       ]));
	set("exits", ([ 
            "east" : __DIR__"shanlu1",
            "northwest" : __DIR__"gsfxia",
        ]));
        set("objects", ([ 
            NPC_D("youke") : 2,
        ]));
	set("outdoors", "嵩山");
	set("coor/x",70);
  set("coor/y",150);
   set("coor/z",60);
   setup();
}
