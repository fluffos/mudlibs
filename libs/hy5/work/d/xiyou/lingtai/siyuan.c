// Room: 有些功能还没加上，被黑了嘛又得从来 by koker2001/04/29
// siyuan.c

inherit ROOM;

void create ()
{
  set ("short", "思源堂");
  set ("long", @LONG

这里是三星洞的思源堂，是小天师云阳真人面壁思源的地方。
屋里的陈设也十分的简单，你连坐的东西都找不到。在石砌
的墙上好象刻着一些字，你不仔细看还不能看到。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jingtang.c",
 
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiao" : 1,
  __DIR__"npc/yunyang" : 1,
]));
  set("valid_startroom", 1);

  setup();
}


