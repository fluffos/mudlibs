// kao.c

inherit ITEM;

void create()
{
        set_name("铁镣铐", ({ "liao kao","kao" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","对");
                set("material", "iron");
		set("long","这是一对专门用来锁(suo)犯人的铁镣铐。");
        }
        setup();
}

void init()
{
	add_action("do_kao","suo");
}

int do_kao(string arg)
{
	object who, me = this_player();

	if(!me || !arg)
		return 0;
	if(me->is_fighting())
		return notify_fail("你正在战斗，腾不出手来锁人。\n");

	if( !objectp(who = present(arg,environment(me))) || !who->is_character() )
		return notify_fail("你要用铁镣铐锁谁？\n");

	if( !who->is_fanren() )
		return notify_fail("铁镣铐只能用来锁犯人。\n");

	if( objectp(who->query_master()) )
		return notify_fail(who->name()+"已经被锁起来了。\n");

	if(living(who))
	{
		message_vision("$N朝着$n喊道：“回去也是个死，我这就和你拚啦！”\n",who,me);
		who->kill_ob(me);
		me->fight_ob(who);
		return 1;
	}

	else
	{
		message_vision("$N拿出铁镣铐“哐啷”一声把$n锁了起来。\n",me,who);
		who->set_master(me);
		this_object()->move(who);
		return 1;
	}
}
