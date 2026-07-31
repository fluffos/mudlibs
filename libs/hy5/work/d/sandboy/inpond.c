// Room: /d/sandboy/inpond 
inherit ROOM; 
 
void create ()
{
  set ("short", "池塘中");
  set ("long", @LONG
池塘并不深,水波在你的胸口微微荡漾,浅绿色的浮萍就在眼前,一层淡
白色的雾气从那片绿色上升起,脚下松软的淤泥没过了脚踝.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/fuping.c" : 2,
]));
  set("outdoors", "/d/sandboy");
  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"pond",
]));

  setup();
}
