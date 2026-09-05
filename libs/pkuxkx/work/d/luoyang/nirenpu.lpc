// 泥人铺
// edit: by zine Oct 16 2010

inherit ROOM;
#include <ansi.h>
#include <random_name.h>



void create()
{
	set("short", HIC"阿希泥人"NOR);
	set("long", @LONG
这里是一家店铺，专替客人制作泥人。一块招牌(zhaopai)挂在门前。一个老
掌柜在忙前忙后。
LONG
	);
	set("exits", ([ 
        "south" : __DIR__"hutong6",
        "north" : __DIR__"yanhuapu", 
	]));
    set("no_task",1);
    set("item_desc", ([
		"zhaopai" : "巧手泥人希，专业捏泥人。定制(ding)从速。\n", 
	]));
    set("no_fight",1);
    set("objects", ([
	    __DIR__"npc/figurehuoji" : 1,
        ]));
	setup();
	
}

void init()
{
   
   add_action("do_ding",({"ding"}));
   add_action("do_qu",({"qu"}));
   this_object()->set("short",get_rndname()+"泥人");
}

int do_qu()
{
    object niren;
    object me=this_player();
    if (!me->query_temp("figurefinish"))
    {
        tell_object(me,"你有在小号定制过泥人吗？我怎么没你的记录？\n");
        return 1;
    }
    if (time()-(me->query_temp("figuretime"))<random(600))
    {
        tell_object(me,"叫你过一刻再来，现在着色还没晾干呢。\n");
        return 1;
    }
    else
    {
        tell_object(me,"伙计高兴地告诉，一切都完成了，你看看吧。\n");
        tell_object(me,"伙计小心翼翼地递给你一个泥捏的小人。\n");
        me->delete_temp("figurefinish");
        me->delete_temp("figuretime");
        niren=new(__DIR__"obj/figure");
        if (niren)
        niren->set("long",me->query("long"));
        niren->set("owner",me->query("id"));
        niren->set("name",me->query("name"));
        niren->move(me);
        return 1;
    }
}

int finish(object me)
{
    if (!me->is_busy())
    {
        return notify_fail("伙计生气地说：叫你别乱动，害我没做好！\n");
    }
    else
    {
        me->delete_temp("figureding");
        this_object()->delete("doing");
        me->set_temp("figuretime",time());
        me->set_temp("figurefinish",1);
        tell_object(me,"伙计高兴地告诉，我捏好了，马上给你着色，你一刻后来取吧。\n");
        return 1;
    }
}

int do_ding()
{
    object me=this_player();
    if (this_object()->query("doing"))
    {
        tell_object(me,"伙计正忙着呢，没空理你。\n");
        return 1;
    }
    if (me->is_busy() || me->is_fighting())
	{
		return notify_fail("你正忙着哪！\n");
    }
    if (!me->query_temp("figureding"))
    {
        tell_object(me,"你去问问伙计怎么定制吧。\n");
        return 1;
    }
    if (me->query("balance")<80000)
    {
        tell_object(me,"伙计对你摇摇头，虽然我们开业酬宾，成本也需要八两黄金，我看你的存款还不够。");
        return 1;  
    }
    else
    {   
        tell_object(me,"伙计说，好吧，那我帮你照你的样子捏个泥人，你不要动喔。\n");
        me->start_busy(8);
        this_object()->set("doing",1);
        tell_object(me,HIG"你老老实实地按伙计说的坐下来，一动不动。\n"NOR);
        me->add("balance",-1000000);
        remove_call_out("finish");
        call_out("finish",6,me);
        return 1;
    }    
}

