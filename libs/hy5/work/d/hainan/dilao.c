// Room: /d/hainan/dilao
inherit ROOM;

void create ()
{
  set ("short", "地牢");
  set ("long", @LONG
黑暗的地牢,用粗糙的花岗岩堆砌而成.在一边的墙角上挂了一盏油 
灯,发出暗蒙蒙的光.靠近牢顶的石壁开了个小天窗,上面还加了粗大铁条. 
整个地牢发出一股霉味,想逃出去是不可能的. 
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mengyun.c" : 1,
]));
  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"road2",
]));

  setup();
}
int valid_leave(object me,string dir)
{
  if (dir=="out"&&present("meng yun",this_object())) 
   return notify_fail("蒙云道:除非把我给杀了,你就别想出去了.\n");
 return ::valid_leave(me,dir);
}

