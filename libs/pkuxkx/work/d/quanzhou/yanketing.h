void init()
{
    add_action("do_luozuo","luozuo");
}

int do_luozuo()
{
    object me=this_player();
    object ob=this_object();
    object food;
    string *foods=({"/d/city/npc/obj/ncfood1","/d/city/npc/obj/ncfood2","/d/city/npc/obj/ncfood3",
        "/d/city/npc/obj/kmfood1","/d/city/npc/obj/kmfood2","/d/city/npc/obj/kmfood3",
        "/d/city/npc/obj/jzfood1","/d/city/npc/obj/jzfood2","/d/city/npc/obj/jzfood3",
        "/d/city/npc/obj/zjfood1","/d/city/npc/obj/zjfood2","/d/city/npc/obj/zjfood3",
        "/d/city/npc/obj/yyfood2","/d/city/npc/obj/yyfood3"});
    if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
    if (time()-(int)me->query(ob->query("yanke_no")+"/eaten")<7200)
    {
        return notify_fail("刚吃过一次，还想打包吗？\n");
    }
    message_vision("$N找了个空置的座位，坐了下来，小厮忙端上酒菜。\n",me);
    food=new(foods[random(sizeof(foods))]);
    if (food)
    {
        food->move(me);
        tell_object(me,"侍者给你端上一盘"+food->query("name")+"。\n");
    }
    food=new(foods[random(sizeof(foods))]);
    if (food)
    {
        food->move(me);
        tell_object(me,"侍者给你端上一盘"+food->query("name")+"。\n");
    }
    food=new("/d/city/npc/obj/jiudai-s");
    food->move(me);
    tell_object(me,"侍者给你端上一份"+food->query("name")+"。\n");
    me->set(ob->query("yanke_no")+"/eaten",time());
    return 1;
}

int valid_leave(object me,string dir)
{  
    object ob=this_object();
	if (dir==ob->query("leave_path"))
    {
        if (!userp(me))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
        if (!me->query(ob->query("yanke_no")+"/recover"))
        {
            tell_object(me,"你参加完"+ob->query("palace")+"的宴席，立刻神清气爽，精力十足。\n");
            me->set(ob->query("yanke_no")+"/recover",1);
            me->fullme();
        }
    }
	return ::valid_leave(me, dir);
}