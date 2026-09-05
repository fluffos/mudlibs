// 问津亭
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include <ansi.h>

void create()
{
	set("short", HIW"问津亭"NOR);
	set("long", @LONG
这是一座六角形的亭台，古意妙趣横生。坐在亭中，微风吹过，心旷神怡。
LONG
	);
    set("normaldesc", @LONG
这是一座六角形的亭台，古意妙趣横生。坐在亭中，微风吹过，心旷神怡。
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"grass7",
        "south" : __DIR__"riyuedong",
		
    ]));
    set("outdoors", "xingxiuhai");

	//set("objects", ([(__DIR__"npc/qinjun") : 1,
    //]));
	setup();
	::create();
}

void init()
{
    this_player()->save();
    ::init();
    return;
}

int valid_leave(object me,string dir)
{  
    int i;
    object *all=deep_inventory(me);
	if (dir=="south") 
    {
        if (me->query("combat_exp")<100000&&me->query("family/family_name")=="星宿派")
        {
            return notify_fail("你这么菜就准备去闯荡江湖了？\n");
        }
        for (i=0;i<sizeof(all);i++)
        {
            if (userp(all[i])&&all[i]->query("family/family_name")=="星宿派"&&all[i]->query("combat_exp")<100000)
            {
                return notify_fail("把星宿年轻弟子背出去？亏你想的出来！\n");
            }
        }
		me->remove_listen_to_die(this_object());
		me->delete_temp("revive_room");
		return ::valid_leave(me, dir);
        
    }
	return ::valid_leave(me, dir);
}
