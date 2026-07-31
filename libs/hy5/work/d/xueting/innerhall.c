// Room: /d/snow/innerhall.c
inherit ROOM;
void create()
{
        set("short", "武馆内院");
        set("long", @LONG
这里是淳风武馆的内院，平常武馆弟子没有馆主的允许是不敢
到这里来的，往东是柳家的祠堂，馆主和家眷的卧房分别位於往北
一条走道的两旁，厨房以及柴房、仆役的卧房都在往南的走道两旁，
往西则是天井。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"inneryard",
  "north" : __DIR__"mingren",
//  "east" : "/d/zwei/secret1",
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
