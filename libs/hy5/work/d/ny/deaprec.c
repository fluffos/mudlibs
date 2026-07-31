
// Room: /d/snow/deaprec.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("coor",({-20,5040,20}));
        set("short", CYN"æ¯«Èπ»"NOR);
        set("long",
"[36mΩ®…Ë÷–£°ÕÊº“¡Ù≤Ω°£°£°£°£°£°£°£[2;37;0m\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"droad2",
]));
        set("item_desc",([
                        "tablet":@TEXT
!!!!!!!!!…√»Î¥Àπ»’ﬂ£¨…±Œﬁ…‚!!!!!!!!!!
TEXT])); 
	setup();
}
