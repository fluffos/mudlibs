// Room: /d/japan/jiedaoe3
inherit ROOM;

void create()
{
  set ("short", "街道");
  set ("long", @LONG
一条宽阔的街道,在街道的南面是一栋府第,看来是有钱人家的住所.
门口的台阶挺高.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"liushengfu",
    "east" : __DIR__"dongmen",
  "west" : __DIR__"jiedaoe2",
]));
  set("outdoors", "japan");
  setup();
        replace_program(ROOM);
}
