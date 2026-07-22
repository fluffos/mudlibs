//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit ROOM;

void create()
{
        set("short", "后山");
        set("long", @LONG
        一条小路通往后山禁地。
LONG
        );

        set("exits", ([
                "north" : __DIR__"bamboo",
                "southwest" : __DIR__"houdian",
                "eastup" : __DIR__"feipu",
        ]));
        set("objects", ([
                __DIR__"npc/guard" : 2,
                __DIR__"npc/qingqi" : 1,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
	object guard;
	if( !userp(me) )
		return 0;
	if( dir!="north" )
		return ::valid_leave(me,dir);
	if( objectp(guard=present("guard")) 
	 && !userp(guard) )
	{		
		if( me->query("family/family_name")!="蜀山派")		
			return notify_fail(guard->name()+"客气地说：“后山乃本派禁地，还是请回吧！”\n");
		if( !me->query_temp("shushan/tower_go") )
			return notify_fail(guard->name()+"说道：擅闯本派禁地，不怕被重罚吗！？\n");
	}
	if( objectp(guard=present("qing qi")) 
	 && !userp(guard) )
	{		
		if( me->query("family/family_name")!="蜀山派")		
			return notify_fail(guard->name()+"说道：后山乃蜀山剑派禁地，还是请回吧！\n");
		if( !me->query_temp("shushan/tower_go") )
			return notify_fail(guard->name()+"说道：擅闯本派禁地，你不怕重罚吗！？\n");
	}	
        return ::valid_leave(me, dir);
}

