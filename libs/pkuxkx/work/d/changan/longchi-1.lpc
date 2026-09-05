//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "龙池湖畔");
        set("long", @LONG
这是美丽的龙池湖畔，湖边牡丹成片，绿树成荫，廊阁相映，
湖面荷花娇艳，画舫游弋，真是美不胜收。每当牡丹花盛开的时
候相传唐玄宗都会相携杨贵妃过来欣赏美景。龙池东北面就是沉
香亭，西南面是花萼相辉楼。
LONG);
        set("exits", ([
           "north" : __DIR__"nanxundian",
           "northeast" : __DIR__"chenxiangting",
           "southwest" : __DIR__"huaelou"
        ]));
        
        set("locate_level",2);

        set("outdoors", "changan");
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}