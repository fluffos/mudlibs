// Room: /d/quanzhou/haigang.c
// cgii 96.10.02

inherit ROOM;

void create()
{
    set("short", "泉州港");
    set("long", @LONG
这里是泉州的海港，只见这里堆满了各种各样的货物，还有
一些相貌奇特，商人打扮的人在叽哩咕噜指手划脚和港口的船夫
不知在说啥，看样子象是在讨价还价。再往东去一点，是有名的
泉州码头。
LONG
    );
    set("outdoors", "quanzhou");
    set("objects", ([ /* sizeof() == 2 */
          __DIR__"npc/boy" : 2,
          __DIR__"npc/girl" : 1,
        ]));
    set("exits", ([ /* sizeof() == 3 */
          "north" : __DIR__"dangpu",
          "south" : "/d/diaoyudao/xiaodao/dazhang",
          "west" : __DIR__"zhongxin",
          "eastdown" : "/d/diaoyudao/matou0",
          "northeast" : "/d/fuzhou/shanlub",
        ]));
    set("main_dir", __DIR__"");
    set("no_clean_up", 1);
        setup();
        replace_program(ROOM);
}

