// cart 

#include <ansi.h>
inherit ITEM;
mapping default_dirs = ([
        "north":        "北面",
        "south":        "南面",
        "east":         "东面",
        "west":         "西面",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":           "上面",
        "down":         "下面",
        "enter":        "里面",
        "out":          "外面",
]);
void create()
{       
        seteuid(getuid());
        set_name(HIW"车队"NOR, ({ "che dui","che"}) );
        set_weight(300000);
        set("no_get", "把车队捡起来？这个想法很有创意！");
		set("location",1);
		set("no_clean_up",1);
		set_max_encumbrance(800000);
        set("unit", "队");
        set("long", "这是一队押运大明物资的车队，你可以领(ling)队前行。\n");
        call_out("destroy",1500);
}

int set_long(object me)
{
	object from,to;
	if (!me)
	{
		return 1;
	}
	if (!userp(me)||!me->query("mingpin"))
	{
		return 1;
	}
	if (me->query_temp("mingtasks/gongbu/yuhen_from"))
	from=me->query_temp("mingtasks/gongbu/yuhen_from");
	if (me->query_temp("mingtasks/gongbu/yuhen_to"))
	to=me->query_temp("mingtasks/gongbu/yuhen_to");
	if (from->isroom()&&to->isroom())
	{
		set("long","这是一队由"+me->query("name")+"押运大明物资的车队，从"+TASK_D->place_belong(from)+"的"+from->query("short")+"押往"+TASK_D->place_belong(to)+"的"+to->query("short")+"，你可以领(ling)队前行。\n");
	}
}
int destroy()
{
	message_vision("$N的民伕见上官并不上心，立刻卷堂大散了。\n",this_object());
	destruct(this_object());
	return 1;
}
void init()
{ 
    add_action("do_ling","ling");
}
int do_ling(string arg)
{        
        object me,ob, env, obj;
        object* inv;
        int i;
        string dir, dest, target;
        mapping exit;
        me = this_player();
        ob = this_object();

        if(!arg) return notify_fail("你要把车队往哪里领？\n");

        if( me->query("id")!=ob->query("owner")) return 0;
        if (!me->query("mingpin")) return 0;
		if (!me->query_temp("mingtasks/gongbu/yuhen")) return 0;
        if( sscanf(arg, "%s",dir) != 1)
		return command(query_verb()+" "+arg);
		if( me->is_busy() )
		return notify_fail("你现在正忙着哩。\n");
        if ( me->is_fighting())
                return notify_fail("你还是先把对手解决了再说吧！\n");
 
        env = environment(me);
        if(!env) return notify_fail("你要把车队往哪里领？\n");
        
        if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) ) 
		{
			if( query_verb()=="ling")
			return notify_fail("这个方向过不去。\n");
			else
			return 0;
        }
        
        dest = exit[dir];
                        
        if( !(obj = find_object(dest)) )
                call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("前路受阻，无法通行。\n");

        if( !undefinedp(default_dirs[dir]) )
                target = default_dirs[dir];
        else
                target = obj->query("short");
        if(me->follow_path(dir)) 
		{
			message("vision", "\n" + me->name() +"领着车队往" + target + "驶去。\n" NOR, env);
			ob->move(environment(me));
			message_vision("$N领着车队向这里驶了过来。\n" NOR, me);
		}
		else
		{
            return notify_fail("这个方向过不去。\n");
		}
        if (environment()==me->query_temp("mingtasks/gongbu/yuhen_to") 
             ||(environment()->query("short")==me->query_temp("mingtasks/gongbu/yuhen_to_short")&&
				TASK_D->place_belong(environment())==me->query_temp("mingtasks/gongbu/yuhen_to_area")))
		{
			tell_object(me,"你历尽辛苦，终于完成了虞衡司的任务，快回去复命吧。\n");
			me->delete_temp("mingtasks/gongbu/yuhen");
			me->delete_temp("mingtasks/gongbu/yuhen_from");
			me->set_temp("mingtasks/gongbu/task3finish",1);
			destruct(ob);
            return 1;
	    }
		else
	    me->start_busy(1+random(2));
        return 1;
}

