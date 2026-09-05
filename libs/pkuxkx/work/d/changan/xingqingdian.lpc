//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "兴庆殿");
        set("long", @LONG
兴庆宫内朝会的正殿兴庆殿，当皇帝移居兴庆宫的时候，
这里就是朝臣觐见皇帝和处理政务的地方，兴庆殿的东边就
是香薰殿。
LONG);
        set("exits", ([
           "west" : __DIR__"xingqingmen",
           "east" : __DIR__"nanxundian"
        ]));
        
        set("locate_level",2);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}