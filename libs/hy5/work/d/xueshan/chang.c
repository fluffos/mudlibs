//      chang.c 练武场
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","练武场");
        set("long",@LONG
这里是雪山寺练武场，树着好多木桩和沙袋，僧人们
日常均在此习武。东边是广场，西边有个小库房，南边一
大片开阔地，就是雪山闻名海内的祭坛了。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "east" : __DIR__"guangchang",
                "west" : __DIR__"kufang",
                "north" : __DIR__"houyuan",
                "south" : __DIR__"jitan",
        ]));
        set("objects", ([
//                CLASS_D("xueshan")+"/gelunbu" :1,
		__DIR__"npc/x_lama" : 1 ,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

