// Room: /d/chengdu/baidicheng
// netkill /98/8/16/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "白帝城" NOR );
        set("long", @LONG
朝辞白帝彩云间，千里江陵一日还。两岸猿声啼不住，千舟以过万重山。
这里就是有名的白帝城了，遥看四周，只见青山绿水，一片大好风景。庙内
塑有刘备，孔明等一干人的像，凭栏怀古，心潮汹涌，令人神怡。
LONG
        );
        set("exits", ([
  "southdown" :  __DIR__"shudao10",
	"east" : __DIR__"shudao9",
  "north": "/d/jiangling/baidicheng",	
   ]));
        set("no_fight",1);

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

