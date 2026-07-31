// Room: /d/huizhu/shamo
inherit ROOM;

void create()
{
  set ("short", "沙漠");
  set ("long", @LONG
淡黄色的沙堆连绵，在这死寂一片的世界中，天上不见飞鸟，地上不
见走兽。只有沙漠中倒毙的骆驼尸骨提醒你，曾经有过生命的痕迹。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east":__DIR__"huanglu2",
  "west":__DIR__"huanglu3",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
