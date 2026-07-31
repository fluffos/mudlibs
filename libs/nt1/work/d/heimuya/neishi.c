//ROOM neishi.c
inherit ROOM;
void create()
{
        set("short", "小舍内室");
        set("long", @LONG
这里是小舍内室。收拾得精细异常。你一进去，就发现床沿
坐着一个打扮妖艳的人。那人也诧异地抬头，你发现他居然是个
男人，手里执着一枚绣花针！
LONG    );
        set("exits", ([
             "west" : __DIR__"xiaoshe",
        ]));
        set("objects", ([
             __DIR__"npc/dongfang": 1,
        ]));
//        set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
