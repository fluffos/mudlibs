 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "菊花园");
        set("long", @LONG
菊花园很大，旁边是梅花园还有牡丹，蔷薇．芍药，茶花，甚至还有竹园。谁
也不知道究竟占了多少地，只知道一个人就是走得很快也难在一天内绕着这片地走
一圈。园中至少有十七栋单独的屋子，老伯和律香川的屋子在东侧。
LONG
        );
        set("exits", ([ 
                "east" :        __DIR__"groom1",
                "north" :       __DIR__"groom3",
                "southwest":    __DIR__"garden1",
        ]));
        set("objects", ([
        
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}      
