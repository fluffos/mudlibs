inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "云来客栈");
        set("long", 
"这是一家客栈，一面招牌上写着“云来”二字，老板正招呼着客人。\n"

        );
        set("exits", ([
                
              
                //"south" : __DIR__"kezhan",
                "north" : __DIR__"xiaoxiang",
                //"west"  : __DIR__"yaopu",
                
        ]));
        set("valid_startroom", 1);
		set("sleep_room", "1");
		set("no_fight", "1");
		set("objects", ([
                __DIR__"npc/xiaoer" : 1,
	]));
        //set("outdoors", "yingtianfu");
        setup();
   
}

