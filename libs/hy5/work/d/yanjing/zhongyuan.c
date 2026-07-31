// Room: /d/yanjing/zhongyuan
inherit ROOM;

void create()
{
  set ("short", "王府中院");
  set ("long", @LONG
一条暗红色的石板路通向北边的香雪厅,那是从大理附近山中开采的石料
铺就的.山石间几盏灯笼明灭不定,是巡逻的亲兵在通报情况,几个婢女托着白玉
盘在梅枝上扫雪,以备作茶水之用.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"road",
  "north" : __DIR__"xiangxue",
  "south" : __DIR__"qianting",
]));
  set("outdoors", "yanjing");
  setup();
  replace_program(ROOM);
}
