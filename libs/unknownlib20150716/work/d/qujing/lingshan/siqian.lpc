//Cracked by Roath
// create by snowcat.c 12/8/1997
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "寺前");
  set ("long", @LONG

只见万年雷音寺前为一广场，一路铺着明亮的玛瑙花砖，广场
的正面可见无数殿宇蕊宫珠阙紫气瑞瑞。东边有仙猿摘果入桃
林，西边有白鹤栖松立枝头；场南有彩凤双双，向日一鸣天下
瑞，场北是青鸾对对，迎风耀舞世间稀。

LONG);

  set("exits", ([
        "north"   : __DIR__"shandian",
        "south"   : __DIR__"yimen",
      ]));
  set("objects", ([
        __DIR__"npc/anuo" : 1,
        __DIR__"npc/jiaye" : 1,
     ]));
  set("outdoors", __DIR__);

  setup();
}