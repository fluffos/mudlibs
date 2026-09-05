// yizhan	驿站
// By bing

#include <ansi.h>
inherit ROOM;

void init();

void create()
{
        set("short", "驿站");
        set("long", @LONG
这是侠客行里唯一的一家驿站。据说它的邮递系统遍布了侠客行的每个
角落，以「方便、快捷、免费」为服务宗旨，乃是现在的润讯公司的前身。
院子里栓着几匹健马，有几个伙计正在进进出出地传送邮件，其中一个看见
你进来，正向你打招呼。
LONG
        );

        set("exits", ([
                  "north" : __DIR__"bieshuqu",
        ]));

        set("objects",([
                __DIR__"npc/huoji" : 1,
        ]));

        set("no_fight", 1);

        setup();
}

