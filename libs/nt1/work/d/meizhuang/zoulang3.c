// zoulang3.c
inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
走廊到了这里似乎就到了尽头，从走廊的那一头传来阵阵的烧饭
的香味，饥肠漉漉的你，走到这里，再也忍受不了那种扑面而来的香
气的诱惑，只有加快脚步，去看个究竟。 
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "north" : __DIR__"chufang",
            "south" : __DIR__"zoulang2",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

