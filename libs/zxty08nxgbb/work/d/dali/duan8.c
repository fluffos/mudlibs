// Room: /d/dali/duan8.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月18日，北京时间：20时44分13秒。

inherit ROOM;

void create()
{
        set("short", "书房");
        set("long", @LONG
书房中琳琅满目，全是诗书典籍，几上桌上摆着许多铜器玉器，
看来尽是古物。壁上挂着一幅水墨画，画的却是一位宫装少女，甚是
逼真传神。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"duan6",
]));

        set("objects", ([
                __DIR__"npc/duanzc" : 1,
                __DIR__"npc/suicong" : 2,
        ]));

        setup();
}

