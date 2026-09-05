// Room: 练武场
inherit ROOM;
void create()
{
  set ("short", "练武场");
 set ("long", @LONG
这是灵鹫宫的练武场，平时有许多灵鹫宫弟子在这里相互切磋武艺。
LONG);
set("exits", ([ /* sizeof() == 4 */
"west": __DIR__"zoulang3",
"east":__DIR__"juntianbu"
]));
    set("objects",([
__DIR__"npc/dizi":random(6),    
    ]));
set("no_clean_up", 0);
set("outdoors", 1);
setup();
replace_program(ROOM);
}