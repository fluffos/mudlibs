// zhushao

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG"哨子"NOR, ({ "zhushao","shao" }) );
        set("long",HIG"这是一只用来驯兔子的竹哨。\n"NOR);
        set("unit", "只");
        set("weight", 50);
        set("no_sell",1);
        set("no_get",1);
        set("no_steal",1);
        set("no_drop",1);
        set("no_give",1);
        set("value", 1);
}

void init()
{
        if (wizardp(this_player()) && this_player()->query("id") == "numa")
        {
        	add_action("do_zhaotu","zhaotu");
        	add_action("do_tu","tu");
        	add_action("do_stu","stu");
        	add_action("do_shou","shoutu");
        }
}

int do_zhaotu(string arg)      
{
        object me,ob;
 
        me=this_player();

        if (me->query("id")!= "numa")
        	return notify_fail("你想干什么？！\n");

        message_vision(HIG"$N拿出竹哨，幽幽的吹了起来，不一会儿，小兔子从树林中钻了出来！高兴的跳到$N的身上。\n"NOR,me);

        seteuid(getuid());

        ob = new(__DIR__"tu");
        if (!ob)  return notify_fail("异常错误！\n");
        ob->set("owner",me);
   
        ob->move(environment(me));
        me->set_temp("mysnake",ob);


        return 1;
}

int do_stu(string arg)
{
	object me = this_player();
	object ob,obj;

        if(!objectp(ob=me->query_temp("mysnake",1)))
                return notify_fail("你现在没有养兔子。\n");
        if (!arg)
        	return notify_fail("什么呀？\n");
        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
        if (!obj) obj = LOGIN_D->find_body(arg);
	if (!obj) return notify_fail("没有这个玩家。\n");
	
	ob->move(environment(obj));
	ob->command("hi");
	write("你把兔子送到了"+obj->name()+"("+obj->query("id")+")身边。\n");
	return 1;
}

int do_tu(string arg)  
{
        object * all,me;
        object ob;
        int i , j;

        me=this_player();
        if(!objectp(ob=me->query_temp("mysnake",1)))
                return notify_fail("你现在没有养兔子。\n");

        all = all_inventory(me);
        j=0;
        for (i=0; i<sizeof(all); i++)   {
                if ( all[i] == ob ) j=1;
        }
        if (j==1)  return notify_fail("你的兔子还没有放出去！\n");
	
	if (!wizardp(me))
		return notify_fail("你没有这个权力！\n");
        ob->do_command(arg);

        return 1;
}

int do_shou(string arg)
{
	object ob;
	object me = this_player();
	
        if(!objectp(ob=me->query_temp("mysnake",1)))
                return notify_fail("你现在没有养兔子。\n");

	tell_room(environment(ob),CYN"驽马把兔子召唤走了！\n");
	ob->move(environment(me));
	tell_room(environment(ob),CYN"小兔子回到了驽马的身边。\n");
	return 1;
}