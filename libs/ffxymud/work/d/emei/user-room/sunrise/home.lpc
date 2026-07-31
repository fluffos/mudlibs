// Room: home.c
#include "ansi.h"

inherit ROOM;
string short;
string long;

void create()
{
short=read_file(__DIR__"short.txt");
long =read_file(__DIR__"long.txt");
set("wiz_only",1);
            set("short",short);
set("long",long);

        set("valid_startroom",1);

        set("exits", ([
              "east":  "/d/emei/sroad2",
        ]));
        setup();
}

