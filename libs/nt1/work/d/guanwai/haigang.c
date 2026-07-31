inherit ROOM;
void create()
{
        set("short", "海港");
        set("long", @LONG
这是一望无际的大海，海中心隐隐约约能看见有一艘船。在西南面隐
约听见“哗，哗，哗．．．”的潮水声。这里是到冰火岛的唯一的路了。
LONG);
        set("exits", ([
                "west" : "/d/guanwai/baihe2",
        ]));
        set("objects", ([
                __DIR__"npc/chuanfu2" : 1,
        ]));
        set("outdoors", "guanwai");
        setup();
        replace_program(ROOM);
}
