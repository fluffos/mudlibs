// Room: /d/jingzhou/road4.c
// netkill /98/8/13/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",GRN "青山" NOR);
        set("long", @LONG
山中树木茂密，花开万朵，这里风景秀美，小鸟在喳喳叫，阳
光从树页的缝隙中照进来，形成五彩的斑斓，你的心情不由的高兴
起来，跟着小鸟的歌声，向前走去。

LONG
        );
        set("exits", ([
  "southeast" : __DIR__"road3",
  "westup" : __DIR__"qingshan2",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

