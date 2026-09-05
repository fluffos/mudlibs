//出行队伍
//create by zine 29/3/2011
#include <ansi.h>


inherit ITEM;

void create()
{	
	set_name(HIY"出行队伍"NOR, ({ "chuxing duiwu","duiwu","team"}));
	set_weight(5000000);
	set("long", "这里是皇帝出行的队伍。\n");
	set("material", "steal");
	set("unit", "只");
	set("value", 0);
    set("no_give",1);
    set("no_drop",1);
    set("no_put",1);
    set("no_get",1);
    
	setup();
    call_out("moving",10);
}

void init()
{
    add_action("do_join","join"); 
    add_action("do_da","da");
}

int do_da()
{
    object me=this_player();
    if (!me->query_temp("mingtasks/sishe/dayizhang"))
    {
        return 0;
    }
    if (this_object()->query("daed"))
    {
        tell_object(me,"皇家的仪仗已经打出。\n");
        return 1;
    }
    if (me->query_temp("mingtasks/sishe/task")!=1)
    {
        tell_object(me,"你想混入皇上出行队伍吗？当心被人当刺客斩了。\n");
        return 1;
    }
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    else
    {
        message_vision("$N打出皇家的仪仗，好不威风。\n",me);
        me->add_temp("mingtasks/sishe/yizhang_finish",1);
        this_object()->set("daed",1);
        return 1;
    }
    
}

void gogogo()
{
    mapping exits;
    string *dirs;
    int i;
	object target;

    if(!environment()) return 0;
    if(sizeof(environment()->query("exits")) == 0) return 0;
    if( !mapp(exits = environment()->query("exits")) ) return 0;

	dirs = keys(exits);
        i = random(sizeof(dirs));
        target = find_object(exits[dirs[i]]);
		if(objectp(target)&&!target->query("no_yizhang"))
		{
			tell_room(environment(),"皇上"+this_object()->query("name")+"的仪仗向"+dirs[i]+"开了过去。\n");
			this_object()->move(target);
			tell_room(target,"皇上"+this_object()->query("name")+"的仪仗开了过来。\n");
		}
	
	return;

}

int moving()
{
    if (this_object()->query("count")>10)
    {
        message_vision("皇上巡视各处完毕，启驾回宫。\n",this_object());
        destruct(this_object());
        return 1;
    }
    if (this_object())
    {
        this_object()->delete("daed");
        this_object()->gogogo();
    }
    this_object()->add("count",1);
    remove_call_out("moving");
    call_out("moving",15);
    return 1;
}

int do_join()
{
    object me=this_player();
    if (me->query_temp("mingtasks/sishe/task")!=1)
    {
        tell_object(me,"你想混入皇上出行队伍吗？当心被人当刺客斩了。\n");
        return 1;
    }
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    else
    {
        tell_object(me,HIW"你加入了皇上出行的仪仗。\n"NOR);
        tell_object(me,HIW"跟紧点，别掉队了，到新的地方打(da)出仪仗就可以了。\n"NOR);
        me->set_temp("mingtasks/sishe/dayizhang",1);
        return 1;
    }
}

