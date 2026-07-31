// Room: /d/japan/lvdian
inherit ROOM;

void create ()
{
  set ("short", "旅店");
  set ("long", @LONG
几乎每个旅人到了一个城市之后,最先的一件事就是住店.这里是神
户唯一的一家提供住宿服务的旅店.由于人多,你经常能在这儿听到一些
传闻.而且几乎都是正确的.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"sleeproom",
  "west" : __DIR__"jiedao",
]));
        set("objects", ([ /* sizeof() == 1 */
             __DIR__"npc/daxiong" : 1,
]));

  setup();
        replace_program(ROOM);
}
