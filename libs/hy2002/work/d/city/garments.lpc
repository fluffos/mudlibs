// Room: /city/garments.c

inherit ROOM;

void create ()
{
  set ("short", "成衣店");
  set ("long", @LONG
这里是扬州名媛贵妇常到之处，现在也挤得凄凄惨惨，脂粉横飞。因为
这里卖的时尚，一直是她们最热衷的装扮。店主是个很可人的小女孩，你认
真一看，顿时发现满个店堂里的女人加在一起，还不如她靓丽。
    店门口横横歪歪地写着几个大字(zi)。想来出自小宝手笔。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"zahuopu",
  "southdown" : __DIR__"fengreiroom",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "zi" : "list 看，buy 买。
",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zeng" : 1,
]));

  setup();
  replace_program(ROOM);
}
