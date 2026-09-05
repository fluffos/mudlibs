inherit ROOM;
#include <ansi.h>
int isroom()
{
	return 0;
}
void init()
{
    object me=this_player();
    object prisoner;
    add_action("do_open","open");
	if (!userp(me))
	{
		return;
	}
	this_object()->set("no_die",1);
	me->listen_to_die(this_object());
    me->set_temp("revive_room",base_name(this_object()));
	me->set_temp("rynewbiejob/prison/lastroom",base_name(environment(me)));
    if (me->query("id")=="hao mao")
    {
        me->move("/d/riyuejiao/yading");
    }
    if (me->query_temp("rynewbiejob/prison/start")==2&&!me->query_temp("rynewbiejob/prison/prisoner_come"))
    {
        me->add_busy(2);
        me->add_temp("rynewbiejob/prison/xl_times",1);
        message_vision(HIB+"$N开始仔细巡视牢房的情况，警惕地注视着牢里的犯人。\n"+NOR,me);
    }
    if (time()-me->query_temp("rynewbiejob/prison/xl_time")>180&&me->query_temp("rynewbiejob/prison/xl_times")>85&&!me->query_temp("rynewbiejob/prison/prisoner_come"))
    {
        me->delete_temp("rynewbiejob/prison/start");
        me->delete_temp("rynewbiejob/prison/prisoner_come");
        me->delete_temp("rynewbiejob/prison/xl_time");
        me->delete_temp("rynewbiejob/prison/xl_times");
        me->add_temp("rynewbiejob/prison/degree",1);
        tell_object(me,"巡视完成了，你去看看狱头还有什么事。\n");
    }
    if (me->query_temp("rynewbiejob/prison/start")==2&&(random(30)==7||wizardp(me))&&!me->query_temp("rynewbiejob/prison/prisoner_come"))
    {
        prisoner=new(__DIR__"npc/prisoner");
        prisoner->do_copy(me);
        prisoner->move(this_object());
        me->set_temp("rynewbiejob/prison/prisoner_come",1);
        message_vision("一个犯人从牢房里逃了出来。\n",me);
        tell_object(me,"你可以选择打死或者打晕他。\n");
        me->start_busy(0);
    }
}

int valid_leave(object me,string dir)
{
    mapping exit=this_object()->query("exits");
    object ob=this_object();
    object nextroom;
	if (!exit)
    {
        return notify_fail("这个方向不通。\n");
    }
    if (!exit[dir])
    {
        return notify_fail("这个方向不通。\n");
    }
    if (load_object(exit[dir]))
    {
        nextroom=load_object(exit[dir]);
    }
	else
	{
		return notify_fail("这个方向不通。\n");
	}
    if (!nextroom->query("is_prison"))
    {
        me->set_temp("rynewbiejob/prison/lastdir",dir);
		me->remove_listen_to_die(this_object());
		me->delete_temp("revive_room");
        return ::valid_leave(me,dir);
    }
    else if (ob->query(dir)!="open")
    {
        return notify_fail("牢门没有被打开，你怎么进去？\n");
    }
	else
	{
		me->set_temp("rynewbiejob/prison/lastdir",dir);
		me->remove_listen_to_die(this_object());
		me->delete_temp("revive_room");
		return ::valid_leave(me,dir);
	}
}

int closing(string dir)
{
	if (stringp(dir))
	{
		this_object()->delete(dir);
		tell_room(this_object(),dir+"方向的牢门被缓缓关上。\n");
	}
    return 1;
}

int do_open(string arg)
{
    object me=this_player();
    object key;
    mapping exit=this_object()->query("exits");
    if (!present("laofang yaoshi",me))
    {
        tell_object(me,"你身上没有牢房钥匙，无法开启牢门。\n");
        return 1;
    }
    key=present("laofang yaoshi",me);
    if (!key->query("is_ry_key"))
    {
        tell_object(me,"你身上没有牢房钥匙，无法开启牢门。\n");
        return 1;
    }
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢，无法开启牢门。\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你要开启哪个方向的牢门？\n");
        return 1;
    }
    if (arg!="north"&&arg!="south"&&arg!="west"&&arg!="east")
    {
        tell_object(me,"你要开启哪个方向的牢门？\n");
        return 1;
    }
    if (!exit[arg])
    {
        tell_object(me,"这个方向没有牢房。\n");
        return 1;
    }
    if (find_object(exit[arg])&&(find_object(exit[arg]))->query("is_prison"))
    {
        tell_object(me,"你打开了"+arg+"方向的监狱大门。\n");
        this_object()->set(arg,"open");
        call_out("closing",60,arg);
        return 1;
    }
    else
    {
        tell_object(me,"你要开启哪个方向的牢门？\n");
        return 1;
    }
}