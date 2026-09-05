//room /d/luoyang/密室大门
//Zine 11 Oct 2010
inherit ROOM;
#include <ansi.h>




void create()
{
	set("short", "密室大门");
	set("long", @LONG
这是一处暗门。门上有个拉环(huan)。
LONG
	);

	set("exits", ([
		
		"south" : __DIR__"datiepu",
		
	]));
    set("no_task",1);
    set("no_reset",1);
    set("no_cleanup",1);
    set("item_desc", ([
		"huan" : "一个铜环，异常干净。你可以试着转(zhuan)一下。\n", 
	]));

	
   setup();
}

void init()
{
    add_action("do_zhuan","zhuan"); 
    add_action("do_fang","fang"); 
    add_action("do_confirm","confirm"); 
}

int callkiller(object tj)
{
    if (!tj)
    {
        return 1;
    }
    else
    {
        environment(tj)->initkiller();
        if (this_object()->query("countkiller")<25)
        {
            this_object()->add("countkiller",1);
            call_out("callkiller",4,tj);
            return 1;
        }
    }
}

int checkhuan()
{
    object* all=all_inventory();
    int i;
    object keeper;
    object mishi=load_object(__DIR__"mishi1");
    for (i=0;i<sizeof(all);i++)
    {
        if (!all[i])
        {
            tell_room(this_object(),WHT"喀喀喀几声巨响，暗门关上了。\n"NOR);
            this_object()->delete("exits/enter", __DIR__"mishi1");
            if (mishi)
            {
                mishi->delete("exits/out", __DIR__"mishigate");
            }
            return 1;
        }
        if (all[i]->query_temp("tiejiangjob/opendoor"))
        {
            keeper=all[i];
        }
    }
    if (keeper)
    {
    
        if (present(keeper,this_object()))
        {
            call_out("checkhuan",1);
            return 1;
        }
        else
        {
            tell_room(this_object(),WHT"喀喀喀几声巨响，暗门关上了。\n"NOR);
            this_object()->delete("exits/enter", __DIR__"mishi1");
            if (mishi)
            {
                mishi->delete("exits/out", __DIR__"mishigate");
            }
            return 1;
        }
    }
    else
    {
            tell_room(this_object(),WHT"喀喀喀几声巨响，暗门关上了。\n"NOR);
            this_object()->delete("exits/enter", __DIR__"mishi1");
            if (mishi)
            {
                mishi->delete("exits/out", __DIR__"mishigate");
            }
            return 1;
    }
}

int do_zhuan(string arg)
{
    object me=this_player();
    object ob=this_object();
    object mishi=load_object(__DIR__"mishi1");
    object tj;
    if (!arg||(arg!="huan" && arg!="tonghuan" && arg!="tong huan" && arg!="铜环"))
	{
		return notify_fail("你要转什么？\n");
	}
	if(me->is_busy()|| me->is_fighting())
	{
		return notify_fail("你正忙着呢。\n");
	}
    if (ob->query("mishiopen"))
    {
        return notify_fail("密室的拉环坏了，现在无法打开。\n");
    }
    if (me->query_str()<100)
    {
        return notify_fail("你暗运内力一转，发现铜环竟纹丝不动。\n");
    }
    else
    {
        ob->set("exits/enter", __DIR__"mishi1");
        if (mishi)
        {
            mishi->set("exits/out", __DIR__"mishigate");
        }
        tj=new(__DIR__"npc/tiejiang2");
        tj->move(__DIR__"mishi"+(1+random(8)));
        ob->set("mishiopen",1);
        ob->set("countkiller",0);
        me->set_temp("tiejiangjob/opendoor",1);
        me->set("tiejiangjob_last_time",time());
        me->add("tiejiangjob_last_time",-8000);
        message_vision(HIG"$N拉开了密室的大门。\n"NOR,me);
        call_out("checkhuan",1);
        call_out("callkiller",6,tj);
        return 1;
    }
}

int do_confirm()
{
    object me=this_player();
    object ob=this_object();
    object mishi=load_object(__DIR__"mishi1");
    if (!me->query_temp("tiejiangjob/opendoor"))
    {
        return 0;
    }
    if (!me->query_temp("tiejiangjob/fangdoor"))
    {
        return 0;
    }
    else
    {
        ob->delete("exits/enter", __DIR__"mishi1");
        me->delete_temp("tiejiangjob/opendoor");
        if (mishi)
        {
            mishi->delete("exits/out", __DIR__"mishigate");
        }
        message_vision(RED"$N放开拉环，密室里所有人都被困住。\n"NOR,me);
        return 1;
    }
}

int do_fang()
{
    object me=this_player();
    if (!me->query_temp("tiejiangjob/opendoor"))
    {
        return 0;
    }
    else
    {
        tell_object(me,"如果你放开拉环，密室里所有人都再无法出来，如果你要放开请确定(confirm)一下。\n");
        me->set_temp("tiejiangjob/fangdoor",1);
        return 1;
    }
}


int valid_leave(object me, string dir)
{

	if (me->query_temp("tiejiangjob/opendoor"))
    return notify_fail("你拉着门环，并不能离开，如果你要离开，需要放(fang)开门环。\n");
    if (dir=="south")
    {
        me->delete_temp("tiejiangjob");
        return 1;
    }
	return ::valid_leave(me, dir);
}


