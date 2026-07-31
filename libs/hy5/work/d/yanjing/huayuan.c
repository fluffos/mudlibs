// Room: /d/yanjing/huayuan
inherit ROOM;

void create()
{
  set ("short", "小花园");
  set ("long", @LONG
几株腊梅从奇巧的太湖石边伸出来,枝头点点的积雪尚未融化,几点粉色
的花苞已微露春意.一条鹅卵石小道通向北边的画楼,南边的一带画廊如锦袍玉
带,在此园南边围了一小圈.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hualou",
  "south" : __DIR__"huilang1",
]));
  set("outdoors", "yanjing");
  setup();
  replace_program(ROOM);
}
