// Room: /d/sandboy/room1 
inherit ROOM; 
 
void create() 
{ 
  set ("short", "堂屋");
  set ("long", @LONG
正面北墙下一张破旧的长台,上面一只缺了口的破碗中放了几个馒头,旁
边一只泥香炉中还点着三根香烟,靠东的墙脚下放了几把镰刀.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room2",
  "south" : __DIR__"yuanzi",
]));
  setup();
}
