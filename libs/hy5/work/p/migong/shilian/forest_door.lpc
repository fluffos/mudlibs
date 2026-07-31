#include <ansi.h>
inherit ITEM;

void create()
{
                
        set_name(HIG"试炼之森入口"NOR, ({ "forest door","door"}) );
        set_weight(5);
        set("no_get",1);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", GRN"从这个入口可以进入试炼之森迷宫。(enter door)\n"NOR); 
                set("unit", "个");
                set("lore",1);
                set("value", 20);
        }
        setup();
}
void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg) {
        int time;
string dest,dest2;
object obj,obj2,me,room,room2;
	mapping exits;
me=this_player();        
        if (arg!="door")
                return 0;
        if (this_player()->query("combat_exp",1) > 6000000 && !wizardp(this_player()))
                return notify_fail("你已经不是新人了，还是不要进去了！\n");

        this_player()->delete_temp("maze");
        time = this_player()->query_temp("maze/time")+180-time();
        if(time>0)
                return notify_fail("你还需要等"+CHINESE_D->chinese_period(time)+"才能进入原始森林迷宫副本。\n");

dest="/p/migong/shilian/maze/entry";
dest2="/p/migong/shilian/maze2/entry";

if(! find_object(dest))
{
	load_object(dest);
}
if(! find_object(dest2))
{
	load_object(dest2);
}


        if(room = find_object(dest)
        	 && room2 = find_object(dest2)
        	)
{
	room= find_object(dest);
me->move(room);
tell_object(me,"传送成功......\n");
}
else
	{
tell_object(me,"迷官未开放......\n");
}		

        return 1;
}

