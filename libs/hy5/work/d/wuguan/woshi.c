inherit ROOM;

void create()
{
    set("short","卧室");
    set("long", @LONG
这里是武馆馆主的卧室，房子并不大，很整洁简朴，被子叠的整整
齐齐，帐子挂了起来，靠窗边摆了一盆盆景，一张小桌，放着几本书。
LONG);
	set("exits", ([
	    "south" : __DIR__"lang5",
	    ]));
        set("objects", ([
           __DIR__"npc/furen" : 1,
        ]));
	setup();
        replace_program(ROOM);
}
