//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "南薰殿");
        set("long", @LONG
南薰殿是皇帝皇后的寝宫所在，西面是朝会正殿兴庆殿，
北面是侧门跃龙门，南面是美丽的龙池。
LONG);
        set("exits", ([
           "west" : __DIR__"xingqingdian",
           "north" : __DIR__"yuelongmen",
           "south" : __DIR__"longchi-1"
        ]));
        
        set("locate_level",2);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}