 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "藤萝溪");
        set("long", @LONG
蜿蜒盘旋的藤萝伴着一条更清澈的泉水潺潺而流，沿着流泉往上走，忽然发现
一样东西从泉水中流了下来，却只不过是一柬已枯萎了的兰花，仍可看出叶子上有
经过人修剪的痕迹，—口气再往前走了半个时辰，山势竟真的豁然开朗，山谷里芬
芳翠绿，就像是个好大好大的花园，其间还点缀着一片亭台楼阁。
LONG
           );
        set("exits", 
           ([ 
       "northeast" : __DIR__"huajin1",
       "southeast" : __DIR__"tengluoxi2",
        ]));
    set("objects", 
       ([ 
//           __DIR__"obj/sand" : 1, 
        ]));
        set("outdoors", "baiyun");
        set("coor/x",10);
    set("coor/y",-1680);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
} 
