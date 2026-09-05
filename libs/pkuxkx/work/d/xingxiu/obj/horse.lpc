// item: /d/xingxiu/npc/obj/fire.c
// Jay 3/17/96

inherit ITEM;

void random_move();

void setup()
{}

void init()
{
        add_action("do_ride", "ride");
}

void create()
{
        set_name("伊犁马", ({"horse", "yili ma", "ma"}));
        set_weight(35000);
          set("no_put",1);
        set_max_encumbrance(50000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "匹");
                set("long", "一匹良种的伊犁马，可以骑(ride)，也可以驮东西。\n");
                 set("no_sell", 1);
                 set("no_pawn", 1);
                set("value", 1000);
        }
		remove_call_out("random_move");
		call_out("random_move",360);

}

void random_move()
{
    mapping exits;
    string *dirs;
    int i;
	object target;

    if(!environment()) return 0;
    if(sizeof(environment()->query("exits")) == 0) return 0;
    if( !mapp(exits = environment()->query("exits")) ) return 0;

	if(random(100) == 3)
	{
        dirs = keys(exits);
        i = random(sizeof(dirs));
        target = find_object(exits[dirs[i]]);
		if(objectp(target))
		{
			tell_room(environment(),query("name")+"不安的刨了刨前蹄，跑了。\n");
			this_object()->move(target);
			tell_room(target,"一匹"+query("name")+"跑了过来。\n");
		}
	}
	remove_call_out("random_move");
	call_out("random_move",360);

}

int do_ride(string arg)
{
	object me = this_player();
        if (!id(arg))
                return notify_fail("你要骑什么？\n");
        if (this_player()->query_temp("marks/骑") ) {
                       write("你已经骑在马上了。\n");
                        return 1;
        }
        else {
               message("vision",this_player()->name() + "翻身上马。\n",
                        environment(me), ({me}) );
               write("你战战兢兢爬上马背。还好，别人没看出来。\n");
                this_player()->set_temp("marks/骑", 1);
        return 1;
        }
}
