// Room: /d/taohua/wuqiku.c

inherit ROOM;

void create()
{
        set("short", "武器库");
        set("long", @LONG
这屋由不剥皮的松木搭成。屋外攀满香藤，进屋后顿感一阵清凉。
壁上挂有几柄长剑，屋内另一书案，案上斜放着一支玉箫。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yaopinfang",
  "east": __DIR__"liangongfang",

]));

	   set("objects", ([
                "/obj/weapon/zhujian" : 3]));

        setup();
        replace_program(ROOM);
}

   
