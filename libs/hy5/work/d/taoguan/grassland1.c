 inherit ROOM;
void create()
{
        set("short", "草地");
        set("long", @LONG
地上长着各式个样的花草，其中有在哪里都很难见到的珍
贵药草，在这里就象没人要一样。这里左面是陡峭的山崖，右
面是一个大湖。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"lake1",
  "north" : __DIR__"grassland2",
  "south" : __DIR__"hole4",
]));
        set("outdoors", "taoguan");
        set("coor/x",-20);
        set("coor/y",2070);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}      
