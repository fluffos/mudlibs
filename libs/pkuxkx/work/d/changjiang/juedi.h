#include <ansi.h>
void init()
{
    add_action("do_zhili","zhili");
}

int zhilied(object me)
{
    tell_object(me,"渐渐地，这里的决口被堵住了。\n");
    tell_object(me,HIG"你可以回都水监复命了。\n"NOR);
    return 1;
}

int do_zhili()
{
    object me=this_player();
    if (me->query_temp("songtasks/dushui/task")!=1)
    {
        tell_object(me,"没有都水监的命令，任何人不得擅自接近江堤。\n");
        return 1;
    }
    if (!this_object()->query("juedi"))
    {
        tell_object(me,"这里的堤坝看起来好好的，不需要治理。\n");
        return 1;
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    message_vision("$N卷起袖子和河工们一起堆高江堤，疏导决堤的长江。\n",me);
    me->set_temp("songtasks/dushui/1/finish",1);
    this_object()->set("exits/"+this_object()->query("juedi_dir"), this_object()->query("juedi_connect"));
    this_object()->delete("juedi");
    me->add_busy(3);
    call_out("zhilied",3,me);
    return 1;
}

int rebuild()
{
    this_object()->set("exits/"+this_object()->query("juedi_dir"), this_object()->query("juedi_connect"));
    this_object()->delete("juedi");
}

int valid_leave(object me,string dir)
{  
    
	if (dir==this_object()->query("juedi_dir") && random(300)>289)
    {
        this_object()->delete("exits/"+this_object()->query("juedi_dir"));
        call_out("rebuild",60);
        return notify_fail("你刚要前行，忽然发现江水决堤，不由暗自庆幸，还好没过去。\n");
    }
    if (me->query_temp("songtasks/dushui/task")==1 && !me->query_temp("songtasks/dushui/1/finish") && random(10)>5)
    {
        this_object()->delete("exits/"+this_object()->query("juedi_dir"));
        this_object()->set("juedi",1);
        call_out("rebuild",60);
        return notify_fail("你刚要前行，忽然发现江水决堤，你赶紧开始治理吧。\n");
    }
	return ::valid_leave(me, dir);
}



