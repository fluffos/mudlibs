// Room: /d/new_taohua/liangongfang.c

inherit ROOM;

void create()
{
        set("short", "练功房");
        set("long", @LONG
这屋由不剥皮的松木搭成。屋外攀满香藤，进屋后顿感一阵清凉。
屋内非常空旷，只有几个蒲团。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wuqiku",
  "east": __DIR__"houhuayuan",

]));                               
	set("objects", ([
                
                __DIR__"npc/di-zi1" : 3,
	       
 ]));

        setup();
        replace_program(ROOM);
}
