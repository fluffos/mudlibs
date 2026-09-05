// 密室
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include <ansi.h>

void create()
{
	set("short", "密室");
	set("long", @LONG
这里星宿派给兵器淬毒的密室。外人不得入内。
LONG
	);
    set("normaldesc", @LONG
这里星宿派给兵器淬毒的密室。外人不得入内。
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"mishi2",
		
    ]));
	//set("objects", ([(__DIR__"npc/qinjun") : 1,
    //]));
	setup();
	::create();
}

void init()
{
	add_action("do_cui", ({ "cui" }));
    add_action("do_getback", ({ "finish" }));
	::init();
}

int do_getback()
{
    object me = this_player();
    object zhang;
    object xd,xd2;
    if (!(me->query_temp("xxnewbiejob/bpz5")))
    {		
        return 0;
    }
    
    if (me->is_busy() || me->is_fighting())
	{
		return notify_fail("你正忙着呐！\n");
    }
    if (time()-me->query("xxnewbiejob/bpztime2")<30)
    {
        return notify_fail("冰魄杖还没有完全吸收毒性！\n");
    }
    else
    {
        zhang=new(__DIR__"obj/bingpozhang");
        tell_object(me,HIB"冰魄杖终于做好了。\n"NOR);
        message_vision("$N仔细打量着冰魄杖，爱不释手。\n",me);
        zhang->set("owner",me->query("id"));
        zhang->move(me);
        if (random(100)>95)
        {
            if(present("xin de", me))
            {
                xd=(present("xin de", me));
                xd2=new("/d/xingxiu/obj/xinde2");
                tell_object(me,RED"你突然福至心灵，在之前誊抄的心得上记录些东西。\n"NOR);
                if (xd->query("owner")==me->query("id"))
                {
                    destruct(xd);
                    xd2->set("owner",me->query("id"));
                    xd2->move(me);
                }
                else
                {
                    destruct(xd);
                    xd2->move(me);
                }
            }
            else
            {
                xd=new("/d/xingxiu/obj/xinde1");
                tell_object(me,RED"你突然福至心灵，把之前打造过程中所学记录了下来。\n"NOR);
                xd->set("owner",me->query("id"));
                xd->move(me);
            }
        }
        me->delete_temp("xxnewbiejob/bpz5");
        me->set_temp("xxnewbiejob/bpz6",1);
        return 1;
    }
}

int do_cui(string arg)
{
	object me = this_player();
	object zhang=present("bing zhang",me);
    object duye=present("du ye",me);
    if (!arg||(arg!="bing zhang"&& arg!="zhang" && arg!="冰杖"))
    {
        return notify_fail("你只能给冰杖淬毒！\n");
    }
    if (!(me->query_temp("xxnewbiejob/bpz4")))
		return notify_fail("我踏月色而来又没让你帮助制作冰魄杖，你想干吗？\n");
   
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着呐！\n");
        }
    
	if(!present("bing zhang", me))
		{
			return notify_fail("你身上有冰杖吗？\n");
		}
    if (zhang->query("owner")!=me->query("id"))
    {
        return notify_fail("这根冰杖又不是你做的，你想不劳而获嘛？\n");
    }
    if(!present("du ye", me))
		{
			return notify_fail("你没有毒液，怎么给冰杖淬毒？\n");
		}
	else
		{
			destruct(zhang);
            destruct(duye);
			message_vision(HIB"$N小心翼翼地将毒液渗入冰杖。\n"NOR, me);
            me->delete_temp("xxnewbiejob/bpz4");
            me->set_temp("xxnewbiejob/bpz5",1);
            me->set("xxnewbiejob/bpztime2",time());
            tell_object(me,"过一会，待毒液和冰杖完全融合，冰魄杖就大功告成了。可用(finish)完成淬毒的过程。\n");
            return 1;
        }
}