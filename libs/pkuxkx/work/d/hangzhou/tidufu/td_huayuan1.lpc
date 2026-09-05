// Room: /hangzhou/td_huayuan1.c
// hubo 2008/4/19

inherit "/d/hangzhou/song_room";
#include <ansi.h>
#include "/d/hangzhou/huayuan.h"
void create()
{
        set("short", "花园");
        set("long", @LONG
杭州提督府的花园，种着五颜六色的鲜花，香味扑鼻，另人陶醉。提督大人的千斤
经常在这里赏花。西边是个大花园，据说花园深处有个地牢，囚禁一些重要的罪犯，轻易
不要进入。
LONG);
        set("outdoors", "hangzhou");
        set("exits", ([     
                "east" : __DIR__"td_neizhai",
                "west" : __DIR__"td_huayuan2",       
]));
  	set("no_newbie_task",1);  
   setup();
}

