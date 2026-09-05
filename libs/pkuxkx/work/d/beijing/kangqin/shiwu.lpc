// Room: /d/beijing/kangqin/shiwu.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"石屋"NOR);
	set("long",
MAG"这是一座孤零零的石屋，里面甚是阴暗。门口有几个
侍卫在来回巡逻。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"garden",
  	"south" : __DIR__"xiaotang",
]));
        set("objects", ([
                "/d/beijing/npc/weishi" : 3,
                "/d/beijing/npc/weishishouling" : 1,
        ]));

	setup();
}
int valid_leave(object me, string dir)
{
    int i;
    object *ob;
    if(dir=="south")
    {
        if (me->query("class") == "officer" && me->query("pin") < 6)
            return ::valid_leave(me, dir);
        
        ob = all_inventory( environment( me ));
        for(i=0; i<sizeof(ob); i++) 
        {
            if( living(ob[i]) && (ob[i]->query("id") == "shi wei" 
                || ob[i]->query("id") == "shiwei shouling"))
                return notify_fail( "侍卫伸手拦住你说道：里面没什么好看的，马上离开这里....！\n");
        }
        return ::valid_leave(me, dir);
    }
    return ::valid_leave(me, dir);
}
