// 密室
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include <ansi.h>

void create()
{
	set("short", "密室");
	set("long", @LONG
这里星宿派制作兵器的密室。外人不得入内。地上散落着一些打造失败的兵
器(weapons)。
LONG
	);
    set("normaldesc", @LONG
这里星宿派制作兵器的密室。外人不得入内。地上散落着一些打造失败的兵
器(weapons)。
LONG
	);
	set("exits", ([ 
		"out" : __DIR__"huoranxuan",
        "west" : __DIR__"mishi3",
        "east" : __DIR__"mishi4",
		
    ]));
    set("item_desc", ([ 
        "weapons" : "地上很多打造失败的冰魄杖，你可以捡(jian)起来。\n",  
   
    ])); 
	//set("objects", ([(__DIR__"npc/qinjun") : 1,
    //]));
	setup();
	::create();
}

void init()
{
	add_action("do_jian", ({ "jian" }));
	::init();
}

int do_jian()
{
    object me = this_player();
    object zhang;
    if (me->query("family/family_name")!="星宿派")
    {
        return 0;
    }
    if (present("po zhang", me))
    {		
        return notify_fail("你要捡那么多破烂干嘛？\n");
    }
    
    if (me->is_busy() || me->is_fighting())
	{
		return notify_fail("你正忙着呐！\n");
    }
    
    else
    {
        zhang=new(__DIR__"obj/zhang2");
        tell_object(me,WHT"你捡起了一根打造失败的冰魄杖。\n"NOR);
        zhang->set("owner",me->query("id"));
        zhang->move(me);
        return 1;
    }
}