// /d/heifeng/cookrm.c

inherit ROOM;

void create()
{
        set("short", "厨房");
        set("long", @LONG
这里是山寨的厨房。所有人的吃喝都是由这里的老李头儿做
的。由于人手少，老李头儿经常忙不过来。老李人缘不错，这里
人人和他交好。
LONG
        );
        set("exits", ([ 
            "west"   : __DIR__"corr02",
]));
        setup();
        replace_program(ROOM);
}