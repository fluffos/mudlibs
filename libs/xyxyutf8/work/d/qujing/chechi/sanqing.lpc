// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/sanqing.c

inherit ROOM;

void create ()
{
  set ("short", "三清殿");
  set ("long", @LONG

殿内左有大鼓右有铜钟，中间是一石案，上面是五色花瓶和青
石烛台，供有不少丰盛斋宴。四壁功德悬挂，殿心分别是元始
天尊，灵宝道君和太上老君。

LONG);

  set("exits", ([
        "south"        : __DIR__"dianmen",
        "north"        : __DIR__"houdian",
        "northeast"    : __DIR__"xiang1",
      ]));
  set("objects",([
        __DIR__"npc/yuanshi" : 1,
        __DIR__"npc/lingbao" : 1,
        __DIR__"npc/taishang" : 1,
        __DIR__"obj/zhengsu" : 1,
      ]));
  setup();
}