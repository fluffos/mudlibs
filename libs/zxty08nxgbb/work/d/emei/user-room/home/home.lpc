// Room: home.c
#include "ansi.h"

inherit ROOM;
string short;
string long;

void create()
{
short=read_file(__DIR__"short.txt");
long =read_file(__DIR__"long.txt");
            set("short",short);
set("long",long);

//        set("no_die", 1);
        set("valid_startroom",1);

        set("exits", ([
              "west":  "/d/emei/sroad1",
        ]));
        setup();
}
