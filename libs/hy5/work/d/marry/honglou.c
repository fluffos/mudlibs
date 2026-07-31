// This is a room made by roommaker. 
inherit ROOM;
void create()
{ 
  set("short", "红娘庄");
  set("long", @LONG
这里就是神秘的红娘庄，有着很大的厅堂，布置的富丽堂皇。
正中是月老的神像，神像前面是大大的喜字。前厅摆着香案，上
面摆着香炉，炉里插着三柱檀香。炉边放着一对红烛，香案前放
着一对蒲团都锈着鸳鸯戏水的图案。中厅放着很多大圆桌，偶尔
有一两个丫鬟穿过来走过去。
LONG
); 
set("objects", ([ /* sizeof() == 1 */
"/d/marry/mafu.c" : 1,
]));
  set("no_fight",1);
  set("no_roar",1);
  set("no_beg",1);
  set("no_steal",1);

  setup();
  replace_program(ROOM); 
}
