// Room: 朱天部
inherit ROOM;
void create()
{
  set ("short", "朱天部");
 set ("long", @LONG
这是朱天部的所在地。
LONG);
set("exits", ([ /* sizeof() == 4 */
"north": __DIR__"zoulang3",
"east":__DIR__"yangtianbu"
]));
        set("objects",([
//        CLASS_D("lingjiu")+"/shisao" : 1,
      __DIR__"npc/dizi" : random(5), 	
                ]));
set("no_clean_up", 0);
set("outdoors", 1);
setup();
replace_program(ROOM);
}
