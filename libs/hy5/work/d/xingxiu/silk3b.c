// /d/xingxiu/silk3.c
inherit ROOM;

void create()
{
        set("short", "万象洞");
        set("long", @LONG
这是一个深邃的洞穴，洞内钟乳石绚丽多姿，美妙神奇。有犀牛望月、五
岳朝天、卧龙坪、炼丹井、仙人灶、上天梯、独木桥等，景象万千，耐人寻味。
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "east" : __DIR__"silk3a",
                "northwest" : __DIR__"silk3c",
        ]));

        setup();
//        replace_program(ROOM);
}

