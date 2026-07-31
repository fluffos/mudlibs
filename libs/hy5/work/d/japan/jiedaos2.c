// Room: /d/japan/jiedaos2
inherit ROOM;

void create()
{
  set ("short", "街道");
  set ("long", @LONG
街道上来往的人很多,不过大多是穿着宽大和服的商人.街道两边的
商店高高低低的排满了街道.从此望去,你东面有间书屋,西面的门口站
着两个大胖子,不知道是干什么的.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"zhongxin",
  "south" : __DIR__"jiedaos",
  "west" : __DIR__"xiangpu",
  "east" : __DIR__"shuwu",
]));
  set("outdoors", "japan");
  setup();
}
