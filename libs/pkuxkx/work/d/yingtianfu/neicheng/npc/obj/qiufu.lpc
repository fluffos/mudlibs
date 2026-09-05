void to_rob(object me);

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
        set_name(HIW"大车"NOR, ({ "da che", "cart", "che"}) );
        set_weight(300000);
        set("no_get", 1);
 
	    set("location",1);
	    set("no_clean_up",1);

        set_max_encumbrance(80000000);
        set("unit", "辆");
        set("long", "一辆刑部运送囚服的大车。\n你可以drive(gan) che to exit来推动它前进\n");
        set("closed", 1);
        set("value", 2000);
        call_out("destroy3",900 + random(300),this_object());
}

void init()
{
    add_action("do_gan","drive");
    add_action("do_gan","gan");
}


int do_gan(string arg)
{        
        object me,ob, env, obj;
        object* inv;
        int i;
        string item, dir, dest, target;
        mapping exit;
        me = this_player();
        ob = this_object();

        if(!arg) return notify_fail("你要赶什么？\n");

        if( me->query("id")!=ob->query("owner")) return 0;
        
        if( sscanf(arg, "%s to %s", item, dir) != 2 ||
                item != "cart" && item != "che")
                return command(query_verb()+" "+arg);
                        
        if( me->is_busy() )
                return notify_fail("你现在正忙着哩。\n");
        

        if ( this_player()->is_fighting())
                return notify_fail("你还是先把对手解决了再说吧！\n");
 
        env = environment(me);
        if(!env) return notify_fail("你要去那里？\n");
        
        if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) ) {
                if( query_verb()=="gan")
                        return notify_fail("这个方向过不去。\n");
                else
                        return 0;
        }
        
        dest = exit[dir];
                        
        if( !(obj = find_object(dest)) )
                call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("没法赶。\n");

        if( !undefinedp(default_dirs[dir]) )
                target = default_dirs[dir];
        else
                target = obj->query("short");

        if(me->follow_path(dir)) 
    {
        message("vision", HIW "\n" + me->name() + "赶着大车往" + target + "驶去。\n" NOR, env);
        message("vision", HIW "大车隆隆向"+ target + "驶去。\n" NOR, env);  
                ob->move(environment(me));
        message_vision(HIG "$N赶着大车驶了过来。\n" NOR, me);
        message_vision(HIG "大车隆隆驶了过来。\n" NOR,me); 
       
		}
		else
		{
            return notify_fail("这个方向过不去。\n");
		}
        //到地方了就不出劫匪了
        remove_call_out("check1");
        call_out("check1",1,ob,me);
        if (base_name(environment())=="/d/yingtianfu/neicheng/xing-prison" )
            return 1;
        
		remove_call_out("to_rob");
		call_out("to_rob",1,me);
        me->start_busy(2+random(2));
        return 1;
}
int check1(object ob, object me)
{
	object env=environment(ob);
    if (!env)
    {
        destruct(ob);
        return 1;
    }
    if (base_name(env)=="/d/yingtianfu/neicheng/xing-prison")
    {
        message_vision("$N终于把这一车物资押送到刑部大牢了。\n",me);
        tell_object(me,HIC"你可以会刑部复命了！\n"NOR);
        me->set_temp("mingtasks/xingbu/task1finish",1);
        destruct(ob);
        return 1;
    }
        
}

void destroy3(object me)
{
        if(!objectp(me)) return; //iszt@pkuxkx, 2007-02-03, 这里me应该是this_object()啊，怎么会没有呢……
     message_vision(HIR"$N磨损太大，哗啦一声散了架。\n"NOR,me);
     destruct(me);
     return;
}
void to_moveaway(object me)
{
	mapping exits;
	string *dirs;
	object dest;
	string dir;
	object *inv;
	int i;

	if(!environment()) return 0;
	if(sizeof(environment()->query("exits")) == 0) return 0;
	if( !mapp(exits = environment()->query("exits")) ) return 0;
	if (!me) return 0;
	if (!me->is_fighting()) return 0;
	inv = all_inventory(environment(me));
	dirs = keys(exits);
	dir = dirs[random(sizeof(dirs))];
	dest = exits[dir];
	message_vision("拉车的骡子惊了，拉着大车就跑，$N赶紧追了上去。\n",me);
	for (i=sizeof(inv)-1;i>=0;i--)
	{
		if ((inv[i]->query("id") == (me->query("id")+"'s robber")) && inv[i]->query("uni_target")==me)
			inv[i]->move(dest);
		if (userp(inv[i]) && inv[i]->query_leader()==me)
			{			
				inv[i]->move(dest);
				tell_object(inv[i],"你看到骡子拉着"+me->query("name")+"的大车就跑，赶忙也跟了上去。\n");
			}
	}
	tell_room(dest,"一只受惊的骡子拉着一辆大车冲了过来，后面" + me->query("name") + "穷追不舍。\n");
	this_object()->move(dest);
	me->move(dest);
	if(!random(20))
	{
		remove_call_out("to_moveaway");
		call_out("to_moveaway",5,me);
	}	
	return;
}

void to_rob(object me)
{
    if (!random(20))
    {
    
        remove_call_out("to_moveaway");
        call_out("to_moveaway",random(30),me);
    }
    return;
}

