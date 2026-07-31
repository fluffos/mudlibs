//Room:/d/lingshedao/chuan.c
inherit ROOM;
void create()
{
        set("short", "战船");
        set("long", @LONG
这是一艘巨大的战船,船上战旗飘扬,四周都是火炮.
LONG );
 //       set("exits", ([
 //               "out"    : __DIR__"xiaowuout",
 //       ]));
        set("objects",([
                __DIR__"npc/liuyun" : 1,
                __DIR__"npc/huiyue" : 1,
                __DIR__"npc/miaofeng" : 1,               
        ]));
        set("no_clean_up",0);
 //       set("outdoors","lingshedao");
        setup();
        replace_program(ROOM);
}
