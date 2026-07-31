// /u/beyond/hz/yuewangmiao.c 岳王庙
#include <ansi.h>
 
 inherit ROOM;
void create()
{
set("short",RED"岳王庙"NOR);
        set("long", @LONG
你走进岳王庙，只见正殿内岳飞塑像，红樱帅盔，紫甲金袍，右手握拳，
左手按剑，正气凛然。座像上端挂着岳飞亲笔手书的四字横匾(bian)。大殿
内两侧挂有“精忠报国”四个大字。令人对这位民族英雄的气壮山河的一生
不禁钦佩不已。
LONG
         );
set("no_fight",1);
        set("item_desc",([
        "bian" : "    还        我        河        山\n"
]));
        set("exits", ([
          "northwest" : __DIR__"baidi",
 "enter" : __DIR__"yuanmen",
"west" : __DIR__"hubian3",
"east" : __DIR__"tianxiang",
          "southeast" : __DIR__"qsddao2",  
]));
set("coor/x",90);
  set("coor/y",-350);
   set("coor/z",0);
   setup();
}
