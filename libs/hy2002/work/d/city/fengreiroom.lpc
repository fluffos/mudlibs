// Room: /d/city/fengreiroom
inherit ROOM;

void create ()
{
  set ("short", "缝纫店");
  set ("long", @LONG
这儿是扬州知名的赵氏缝纫店，是由一个可怜的女子赵军蓉开的小店。
听说当年赵军蓉家破人亡，幸得一名为叶欢的大侠路过收容，后来又出钱为
她建了这个小小缝纫店，让她衣食住行有了作落。才有了她今日的生活。店
中立了一个小小招牌。（paizi）
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"garments",
  "south" : __DIR__"kufang",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "请问我关于[工作]的事。
",
]));
  set("no_fight", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhaojunrong" : 1,
]));
  set("no_magic", 1);

  setup();
  replace_program(ROOM);
}
