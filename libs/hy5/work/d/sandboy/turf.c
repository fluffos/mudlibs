// Room: /d/sandboy/turf 
inherit ROOM; 
 
void create() 
{ 
  set ("short", "青草地");
  set ("long", @LONG
清晨淡淡的白色雾气还在草地上空弥漫,但那一片逼人的绿还是吸引了
你,此处地势低洼,向北看,一片高高的茅草遮住你的眼,西面是高高低低
的一片杂树林,向东有个小池塘.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"trees1",
  "north" : __DIR__"inturf",
  "east" : __DIR__"pond",
]));
set("outdoors","/d/jiangnan");
  setup();
}
