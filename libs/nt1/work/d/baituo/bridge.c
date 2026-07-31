//bridge.c

inherit ROOM;

void create()
{
        set("short", "小桥");
        set("long", @LONG
这是一座小竹桥，『白驼山』上的冰雪融化形成一条清澈的小溪，从
桥下缓缓流过。不时有顽皮的小鱼跃出水面，在阳光下划出一条银白色的
弧线。
LONG );
        set("outdoors", "baituo");
//        set("no_clean_up", 0);
        set("exits", ([
                "northwest" : __DIR__"guangchang",
                "east" : __DIR__"xijie",
        ]));
        set("objects",([
                __DIR__"npc/cungu" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
