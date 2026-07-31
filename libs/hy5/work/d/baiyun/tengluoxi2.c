 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "藤萝溪");
        set("long", @LONG
拨开藤萝，里面竟有条裂隙，仅容一个人侧身而过。再往里走，就渐渐宽了。
山隙后仿佛有光，本已几乎听不见的流水声，又变得很清晰。一条更清澈的泉水便
在眼前，沿着流泉往上走，忽然发现—样东西从泉水中流了下来，却只不过是一柬
已枯萎了的兰花，仍可看出叶子上有经过人修剪的痕迹。
LONG
           );
        set("exits", 
           ([ 
       "northwest" : __DIR__"tengluoxi",
       "south" : __DIR__"qingbi",
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
