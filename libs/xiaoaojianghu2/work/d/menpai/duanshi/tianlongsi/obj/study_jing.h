// study_jing.h writen by cry 9.18.98

void init()
{
	add_action("do_study","study");
}

int do_study(string arg)
{
	object me=this_player(),obj=present(arg,me);

	if( obj!=this_object() )
		return 0;
        if ( me->query("gin") == me->query("max_gin") )
		me->set("gin",2);
        else
        {
                tell_object(me, "你的精神太差了。\n");
                return 1;
        }
	return 0;
}