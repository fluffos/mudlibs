// override.c

// override destruct
// modify by mudring
nomask void destruct(object ob)
{
    if (ob)
    {
        if (previous_object())
		{
            ob->remove(geteuid(previous_object()));
		}
        else
		{
			ob->remove(0);
		}
		
	    efun::destruct(ob);
    }
}

// override living
nomask int living(object ob)
{
    if(!ob) return 0;
// added by mudring
    if (!ob->is_character() || ob->is_corpse()) return 0;
    if (ob && ob->query_temp("disabled") )
        return 0;
    return efun::living(ob);
}

// modify by mudring
// override efun:localtime
nomask mixed *localtime( int time )
{
    if (!intp(time) || ( time < 0 ))
        time = 0;

    return efun::localtime(time);
}

//override efun:ctime
nomask varargs string ctime(int time, int flag)
{
    string ctime;

    if (!intp(time))
        return "";
    if (time < 0)
        time = 0;

    ctime = efun::ctime(time);
    if (flag)
        return CHINESE_D->chinese_time(ctime);
    else
        return ctime;
}
// end

#define CMD_QUIT "/cmds/eld/quit"
#define CMD_UPDATE "/cmds/wiz/update"
// override efun:exec
nomask int exec(object target, object from)
{
    if (! from || ! target)
        return 0;

    if (! previous_object()) return 0;

// modify by mudring
    if (previous_object() != find_object(LOGIN_D) &&
        previous_object() != find_object(CMD_QUIT) &&
        previous_object() != find_object(CMD_UPDATE))
// end
    {
        log_file("static/security",
                 sprintf("%s  %s(%s) want to exec (%s)%s to (%s)%s on %s.\n",
                         ctime(time()),
                         (string)base_name(previous_object()),
                         (this_player(1) ? geteuid(this_player(1)) : "???"),
                         (string)from->name(),
                         (string)geteuid(from),
                         (string)target->name(),
                         (string)geteuid(target),
                         ctime(time())));
        return 0;
    }

    from->remove_interactive();
    return efun::exec(target, from);
}

// override efun:shutdown
nomask void shutdown(int how)
{
    if (! previous_object()) return;

    if (! is_root(previous_object()))
    {
        log_file("static/security",
                 sprintf("%s  %s(%s) want to shutdown mud.\n",
                         ctime(time()),
                         (string)base_name(previous_object()),
                         (this_player(1) ? geteuid(this_player(1)) : "???")));
        return 0;
    }

    return efun::shutdown(how);
}

// override efun:snoop
nomask varargs object snoop(object me, object ob)
{
    if (!previous_object()) return 0;
    if (!objectp(me)) return 0;

    if (!is_root(previous_object()))
    {
        log_file("static/security",
                 sprintf("%s  %s(%s) want to snoop %s with %s.\n",
                         ctime(time()),
                         (string)base_name(previous_object()),
                         (this_player(1) ? geteuid(this_player(1)) : "???"),
                         ob ? (string)geteuid(ob) : "null",
                         (string)geteuid(me)));
        return 0;
    }

    if (!objectp(ob))
        return efun::snoop(me);
// added by mudring
    if (wiz_level(me) < wiz_level(ob) && wizhood(me) != "(admin)" )
        return 0;
// end
    else
        return efun::snoop(me, ob);
}

// override efun:query_snooping
nomask object query_snooping(object ob)
{
        if (! previous_object()) return 0;

        if (! is_root(previous_object()))
        {
                log_file("static/security",
                         sprintf("%s  %s(%s) want to query_snooping of %s.\n",
                                 ctime(time()),
                                 (string)base_name(previous_object()),
                                 (this_player(1) ? geteuid(this_player(1)) : "???"),
                                 (string)geteuid(ob)));
                return 0;
        }

        return efun::query_snooping(ob);
}

// override efun:query_snoop
nomask object query_snoop(object ob)
{
        if (! previous_object()) return 0;

        if (! is_root(previous_object()))
        {
                log_file("static/security",
                         sprintf("%s  %s(%s) want to query_snoop of %s.\n",
                                 ctime(time()),
                                 (string)base_name(previous_object()),
                                 (this_player(1) ? geteuid(this_player(1)) : "???"),
                                 (string)geteuid(ob)));
                return 0;
        }

        return efun::query_snoop(ob);
}
