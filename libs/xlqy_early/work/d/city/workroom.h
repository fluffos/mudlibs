void init()
{
	add_action("do_work", "work");
    add_action("stop_working", "stop");
}

int halt_working(object me)
{
    message_vision(HIY "$N" HIY "把手中的活一甩，嚷嚷道：不干了，不干了！\n" NOR, me);
    me->delete_temp("job/work");

    return 1;
}

int stop_working()
{
    object me = this_player();

    me->interrupt_me(me);

    return 1;
}

void finish_work(object who)
{
	who->delete_temp("job/work");

    message_vision("$N辛苦的工作终于结束了，可人也累的半死。\n", who);
    message_vision("老板冷冷地对$N说：这是你的工钱。\n", who);

    if ( !userp(who) || who->query("combat_exp") < 200000000 )
    {
        who->add("combat_exp", 9000);
        who->add("daoxing", 9000);
        who->add("potential", 2000);
    }

    if ( userp(who) )
    {
        who->add_gold(10 + random(60));
    }

	return;
}

int working(object me)
{
    if ( !living(me) )
    {
        me->delete_temp("job/work");
        return 0;
    }

    if ( !me->query_temp("job/work/working") || !me->query_temp("job/work/time") )
    {
        me->delete_temp("job/work");
        return 0;
    }

    if ( time() >= me->query_temp("job/work/time") )
    {
        finish_work(me);
        return 0;
    }

    if ( !random(3) )
    {
        tell_object(me, "你擦了把身上的汗水！\n");
    }

    return 1;
}

int do_work()
{
    object me = this_player();

    if ( me->query_temp("job/work/working") )
    {
        tell_object(me, "你已经在工作了!\n");
    }
    else
    {
        me->set_temp("job/work/working", 1);
        me->set_temp("job/work/time", time() + 10 + random(6));
        if ( userp(me) && me->query("combat_exp") >= 200000000 )
        {
            tell_object(me, "老板嘿嘿一笑：我这里人手已经够了，做义工可没工钱的哟！\n");
        }
        message_vision("$N开始辛苦地工作......\n", me);
        // __FILE__ is a preprocessor macro that expands to whatever file
        // is textually being scanned at that point -- since this is a
        // #include'd fragment (shared by workroom1/2/3.lpc), it always
        // expands to this header's own path ("/d/city/workroom.h", never
        // loadable as a real object), not whichever room actually
        // included it. file_name(this_object()) resolves at runtime to
        // the real including object instead, exactly what's intended.
        me->start_busy( (: call_other, file_name(this_object()), "working", me :),
            (: call_other, file_name(this_object()), "halt_working", me :) );
    }

    return 1;
}

int valid_leave()
{
    object me = this_player();

    me->interrupt_me(me);
    return ::valid_leave();
}

