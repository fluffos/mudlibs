// neiting.c	休息室
// by bing

inherit ROOM;

string* names = ({
        "/d/shaolin/obj/mala-doufu",
        "/d/shaolin/obj/bocai-fentiao",
        "/d/shaolin/obj/shanhu-baicai",
        "/d/shaolin/obj/liuli-qiezi",
});


void create()
{
	set("short", "厨房");
	set("long", 
@LONG  
这是一间厨房，几个低级弟子正在忙碌的准备着饭菜。日月神
教等级森严，入门弟子几乎都要经过这些做杂役的过程。
LONG
	);
	set("exits", ([
		"west" : __DIR__"neiting",
        
	]));
    
        set("objects",([
                __DIR__"obj/zaotai" : 1,
                __DIR__"npc/chushi" : 1,
                __DIR__"obj/fire" : 2,
        ]));
    
	setup();
	
}

void init()
{
    add_action("do_get","get");
}

int do_get(string arg)
{
    object me=this_player();
    if (arg=="all")
    {
        tell_object(me,"这里只能一件一件拿东西。\n");
        return 1;
    }
    if (arg=="fire")
    {
        if (!me->query("rynewbiejob/chufang/start"))
        {
            tell_object(me,"一支火折也偷，真是辱没你在江湖的威名啊。\n");
            return 1;
        }
        if (present("fire",me))
        {
            tell_object(me,"你身上不是有一只火折了吗？\n");
            return 1;
        }
    }
}

int valid_leave(object me,string dir)
{
    object fire;
    if (present("fire",me))
    {
        fire=present("fire",me);
    }
    if (fire&&fire->query("is_fire")&&dir=="west")
    {
        return notify_fail("你把大师傅的火折带走干嘛？别人还要用呢。\n");
    }
    return ::valid_leave(me,dir);
}