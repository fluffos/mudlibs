// Room: /u/cloud/wood.c

inherit ROOM;
int do_cut(string arg);

int i;
void create()
{
        set("short", "西山树林");
        set("long",
"这里是西山树林。四周是参天古树，浓密的树叶盖住了天空。你发现这里有许多人在砍柴，\n"
"一捆捆的往家里背。\n"
);
        set("exits", ([ /* sizeof() == 1 */
            "eastdown" : __DIR__"nroad3",
            ]) );

        set("outdoors", "cloud");

        setup();
}

