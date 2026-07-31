// Room: /d/sandboy/pigroom 
inherit ROOM; 
 
void create ()
{
  set ("short", "猪圈");
  set ("long", @LONG
这间小茅屋中养着一头大肥猪,旁边屋角堆着一堆干草,一股腥骚味直
扑口鼻,一圈猪栏把猪隔在墙角落中.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/pig.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yuanzi",
]));

  setup();
}
