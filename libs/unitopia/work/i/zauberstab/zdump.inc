// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/i/zauberstab/zdump.inc
// Description:	Geht die gesammte Objektliste durch
// Author:	Freaky (1998)
// Modified by:	Freaky (20.09.2000) in den Zauberstab integriert
//
// $Log: zdump.inc,v $
// Revision 1.17  2015/08/26 21:40:29  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.16  2015/07/09 18:03:17  gnomi
// Algorithmus korrigiert.
// #'print_size eingebaut.
//
// Revision 1.15  2013-04-01 09:12:29  gnomi
// zdump #'count_inventory eingebaut.
//
// Revision 1.14  2008/01/16 09:37:23  gnomi
// zdump #'clean: Fehlerhafte Objektzeit-Ueberpruefung.
//
// Revision 1.13  2007/05/26 22:54:29  gnomi
// #'clean wartet wie die SEfun 4 Minuten, bevor es meckert.
//
// Revision 1.12  2003/08/16 22:07:19  gnomi
// static add_actions entfernt.
//
// Revision 1.11  2003/08/15 03:16:43  gnomi
// #'clean: shadow_creator angeben, falls vorhanden.
//
// Revision 1.10  2002/11/20 14:04:42  freaky
// creator mit ausgeben.
//
// Revision 1.9  2002/01/15 03:38:29  gnomi
// query_short umgestellt.
//
// Revision 1.8  2001/08/25 13:32:13  freaky
// Evals angepasst
//
// Revision 1.7  2001/06/14 16:25:56  freaky
// Bessere Ausgaben
//
// Revision 1.6  2001/03/06 01:40:16  gnomi
// Bei dump_clean einen Fehler am Erschaffer des Objektes absetzen, sofern
// bekannt.
//
// Revision 1.5  2001/02/11 02:24:19  sissi
// Anpassung an neues Levelsystem.
//
// Revision 1.4  2001/01/14 13:41:36  freaky
// dump_size() eingefuehrt.
//
// Revision 1.3  2001/01/13 01:23:03  gnomi
// Raumtypen "repraesentant" und "umgebung" beim dump_clean beachten.
//
// Revision 1.2  2000/09/23 00:34:59  freaky
// Level angepasst.
//
// Revision 1.1  2000/09/20 12:10:37  freaky
// in den Zauberstab eingebaut
//

#pragma strict_types

#define DUMP_EVALS 500000
#define DUMP_USAGE "usage: " + query_verb() + " [#'<fun>] [<file-name-pattern>]\n"

// Gibt einfach nur den Objekt-Namen aus.
static mixed dump_print(object ob, object tp, mixed ret)
{
    tell_object(tp,object_name(ob) + "\n");
    return ret + 1;
}

// Gibt den Namen und die Große des Objektes aus.
static mixed dump_print_size(object ob, object tp, mixed ret)
{
#if __EFUN_DEFINED__(driver_info)
    mixed size = efun::object_info(ob, OI_DATA_SIZE);
#else
    mixed size = efun::object_info(ob, OINFO_MEMORY, OIM_DATA_SIZE);
#endif
    string prog = program_name(ob);
    string key = implode(explode(prog, "/")[1..2], "/");

    tell_object(tp, sprintf("%d %s\n", size, object_name(ob)));

    return ret + size;
}

// Zeigt alle count-objecte an
static mixed dump_countob(object ob, object tp, mixed ret)
{
    if (function_exists("query_count",ob))
	tell_object(tp,object_name(ob) + "\n");
    return ret + 1;
}

// Zaehlt einfach nur die Objekte
static mixed dump_count(object ob, object tp, mixed ret)
{
    return ret + 1;
}

static mixed dump_size(object ob, object tp, mixed ret)
{
    if (efun::clonep(ob))
    {
	object tmp;

	tmp = find_object(program_name(ob));
	if (tmp && program_time(ob) <= program_time(tmp))
	{
#if __EFUN_DEFINED__(driver_info)
	    return ret + efun::object_info(ob, OI_DATA_SIZE);
#else
	    return ret + object_info(ob,2)[OIM_DATA_SIZE];
#endif
	}
    }
#if __EFUN_DEFINED__(driver_info)
    return ret + efun::object_info(ob, OI_DATA_SIZE)
               + efun::object_info(ob, OI_PROG_SIZE_TOTAL);
#else
    return ret + object_info(ob,2)[OIM_DATA_SIZE] +
       	object_info(ob,2)[OIM_TOTAL_SIZE];
#endif
}

// Cleaned alle Objekte aus /w/
static mixed dump_clean_w(object ob, object tp, mixed ret)
{
    string msg;

    if (strstr(object_name(ob),"/w/"))
	return ret;
    if (!player_present(ob) && !playerp(environment(ob)) &&
	    !query_shadowing(ob))
    {
	tell_object(tp,object_name(ob) + "\n");
	msg = catch(ob->remove());
	if (msg)
	    tell_object(tp,"Remove: " + msg);
	if (ob)
	{
	    msg = catch(destruct(ob));
	    if (msg)
		tell_object(tp,"Destruct: " + msg);
	}
	ret++;
    }
    else
    {
	if (query_shadowing(ob))
	{
	    object p, p1;
	    
	    p = query_shadowing(ob);
	    while(p1 = query_shadowing(p))
		p = p1;
	    if (!wizp(p))
		tell_object(tp,sprintf("Shadowing ob ist kein Wiz: %O\n",ob));
	}
	else if (playerp(environment(ob)))
	{
	    if (!wizp(environment(ob)))
		tell_object(tp,sprintf("Env ist kein Wiz: %O\n",ob));
	}
	else if (!wizp(player_present(ob)))
	{
	    tell_object(tp,sprintf("Kein Wiz dabei: %O\n",ob));
	}
    }
    return ret;
}

// Ruft in allen Objekten die Funktion clean_up(-1) auf.
static mixed dump_clean_up(object ob, object tp, mixed ret)
{
    string tmp;

    tmp = object_name(ob);
    if (strstr(tmp,"/i/") == 0 || strstr(tmp,"/obj/") == 0)
	return ret;
    ob->clean_up(-1);
    if (!ob)
    {
	tell_object(tp,tmp + "\n");
	ret++;
    }
    return ret;
}

// Zaehlt die v-items in den Objekten
static mixed dump_count_v_items(object ob, object tp, mixed ret)
{
    return ret + sizeof(({mapping *})ob->query_all_v_items());
}

// zerstoert die Objekte (VORSICHT!)
static mixed dump_remove(object ob, object tp, mixed ret)
{
    string msg, name, fn;

    fn = object_name(ob);
    if (msg = catch(name = ({string})ob->query_short(this_player())))
	tell_object(tp,"ERR: (query_short) " + fn + " " + msg);
    if (!stringp(name) || !strlen(name))
	if (msg = catch(name = Name(ob)))
	    tell_object(tp,"ERR: (Name) " + fn + " " + msg);
    name = to_string(name);
    if (msg = catch(ob->remove()))
	tell_object(tp,"ERR: (remove) " + fn + " " + name + ": " + msg);
    if (ob)
	if (msg = catch(destruct(ob)))
	    tell_object(tp,"ERR: (destruct) " + fn + " " + name + ": " + msg);
    tell_object(tp,fn + " (" + name + ")\n");
    return ret + 1;
}

// Ruft reset() in den Objekten auf, und misst die Zeit
static mixed dump_reset(object ob, object tp, mixed ret)
{
    int *us1, *us2, eval, us;
    string tmp;

    if (function_exists("reset",ob))
    {
	us1 = rusage();
	eval = get_eval_cost();
	tmp = catch(ob->reset());
	eval = eval-get_eval_cost();
	us2 = rusage();
	us = us2[0] + us2[1]-us1[0]-us1[1];
	if (tmp)
	    tell_object(tp,(ob?object_name(ob):"0") + ": " + tmp);
	if (eval>1000 || us>100)
	    tell_object(tp,sprintf("%-60s %6d %6dms\n",
			   ob?object_name(ob):"0",eval,us));
    }
    return ret + us;
}

// zerstoert alle nicht referenzierten Objekte
static mixed dump_clean(object ob, object tp, mixed ret)
{
    string name, file, msg, fn, creator;
    int nocleanup;
    mixed env;

    if (time() - object_time(ob) > 240 && // macht die SEfun
        !environment(ob) && clonep(ob) && !query_shadowing(ob) &&
		!interactive(ob) && !player_present(ob))
    {
	fn = object_name(ob);
	if (msg = catch(name = ({string})ob->query_short(this_player())))
	    tell_object(tp,"ERR: (query_short) " + fn + " " + msg);
	if (!stringp(name) || !strlen(name))
	    if (msg = catch(name = Name(ob)))
		tell_object(tp,"ERR: (Name) " + fn + " " + msg);
	name = to_string(name);
	if (msg = catch(nocleanup = ({int})ob->query_type("nocleanup")))
	    tell_object(tp,"ERR: (query_type) " + fn + " " + msg);
	if (nocleanup)
	{
	    tell_object(tp,sprintf("NOCLEANUP: %s\n  %s\n  %s\n",
				fn,getuid(ob),name));
	    if (!strstr(fn,"/w/"))
	    {
		tell_object(tp,"Zerstoere es aber trotzdem (da aus /w/)\n");
		if (msg = catch(ob->remove()))
		    tell_object(tp,"ERR: (remove) " + fn + " " + msg);
		if (ob)
		    if (msg = catch(destruct(ob)))
			tell_object(tp,"ERR: (destruct) " + fn + " " + msg);
		ret++;
	    }
	}
	else
	{
	    if (msg = catch(env = ({mixed}) ob->query_type("repraesentant")))
		tell_object(tp,"ERR: (query_type(\"repraesentant\")) " + fn +
		       	" " + msg);
	    if (env)
	    {
		if(mappingp(env))
		    env = 0;
		else if(!objectp(env))
		{
		    tell_object(tp,fn + " query_type(\"repreasentant\") "
			    "liefert falschen Typ.\n");
		    env = 0;
        	}
		else if(env==ob)
		{
		    tell_object(tp,fn + " query_type(\"repreasentant\") "
			    "ist Objekt selber.\n");
		    env = 0;
		}
		else if(!environment(env))
		{
		    tell_object(tp,fn + " query_type(\"repreasentant\") "
			    "hat keine Umgebung.\n");
		    env = 0;
		}
	    }
	    if(!env)
	    {
		if (msg = catch(env = ({object})ob->query_type("umgebung")))
		    tell_object(tp,"ERR: (query_type\"umgebung\")) " + fn +
			    " " + msg);
		if(env)
		{
		    if(!objectp(env))
		    {
			tell_object(tp,fn + " query_type(\"umgebung\") "
				"liefert falschen Typ.\n");
			env = 0;
		    }
		    else if(env==ob)
		    {
			tell_object(tp,fn + " query_type(\"umgebung\") "
				"ist Objekt selber.\n");
			env = 0;
		    }
		}
	    }
	    if(!env)
	    {
		tell_object(tp,sprintf("%s\n  %s\n  %s\n",
			fn,getuid(ob),name));
	        file = explode(fn,"#")[0];
		if (msg = catch(creator = ({string}) ob->query_creator()))
		    tell_object(tp,"ERR: (query_creator) " + fn + " " + msg);
		if (!creator && msg = catch(creator = ({string}) ob->query_shadow_creator(ob)))
		    tell_object(tp,"ERR: (query_shadow_creator) " + fn + " " + msg);
		if(stringp(creator))
		{
		    tell_object(tp,sprintf("  Creator: %s\n",creator));
		    do_error2("Das Objekt '" + file + "#<nr>' UID: " + getuid(ob) +
		        " Name: '" + name + "' wurde nicht referenziert.\n",
			file, explode(creator," (")[0],0);
		}
		else
		    do_error3("Das Objekt '" + file + "#<nr>' UID: " + getuid(ob) +
		        " Name: '" + name + "' wurde nicht referenziert.\n",
			file,file + "#<nr>",0,explode(getuid(ob),":") +
			({ getuid(ob) }));
		if (msg = catch(ob->remove()))
		    tell_object(tp,"ERR: (remove) " + fn + " " + msg);
		if (ob)
		    if (msg = catch(destruct(ob)))
			tell_object(tp,"ERR: (destruct) " + fn + " " + msg);
		ret++;
	    }
	}
    }
    return ret;
}

// Zaehlt Sachen, die Rumliegen. Warnt bei > 200 Items im Container.
static mixed dump_count_inventory(object ob, object tp, mixed ret)
{
    int count = sizeof(all_inventory(ob));

    if(count > 200)
        tell_object(tp, sprintf("%s: %d Items.\n", object_name(ob), count));

    return ret + count;
}

// holt die naechsten Objekte aus der Objekt-Liste
private object *get_next_obs(object *obs, object tp)
{
    int i;

    if (member(obs = obs[1..],0) >= 0)
    {
	tell_object(tp,"Es waren Nuller dabei.\n");
	obs -= ({0});
    }
    if (!(i=sizeof(obs)))
	return 0;

#if __EFUN_DEFINED__(objects)
    object *next = efun::objects(obs[<1], 30-i);
    if (sizeof(next) < 30-i) /* wrap around */
        next += efun::objects(0, 30-i-sizeof(next));
    i = member(next, this_object());
    if (i>=0)
        next = next[0..i-1];
    obs += next;
#else
    object ob = obs[<1];

    for (; i<30; i++)
    {
	if (!(ob = efun::debug_info(DINFO_OBJLIST,ob)))
	    ob = efun::debug_info(DINFO_OBJLIST,0);

	if(ob == this_object())
	    break;

	obs += ({ob});
    }
#endif
    return obs;
}

// Die call-out-Funktion fuer dump
static void do_dump(object *obs, object tp, closure cfun, string ob, mixed ret)
{
    if (!tp)
	return;

    if (!ob)
    {
	while((obs = get_next_obs(obs,tp)) && get_eval_cost() > DUMP_EVALS)
	{
	    ret = funcall(cfun,obs[0],tp,ret);
	}
    }
    else
    {
	while((obs = get_next_obs(obs,tp)) && get_eval_cost() > DUMP_EVALS)
	{
	    //if (!strstr(object_name(obs[0]),ob))
	    if (sizeof(regexp(({object_name(obs[0])}),ob)))
		ret = funcall(cfun,obs[0],tp,ret);
	}
    }
    tell_object(tp,sprintf("EVAL:%d\n",get_eval_cost()));
    if (obs)
	call_out("do_dump",1,obs,tp,cfun,ob,ret);
    else
	tell_object(tp,"DUMP fertig.\n" + sprintf("RET:%O\n",ret));
}

int z_dump(string str)
{
    string fun, ob;
    closure cfun;

    SECURE;
    SECURE_ADMIN;
    HELP("zdump");

    if (!str)
	FAIL(DUMP_USAGE);

    if (sscanf(str,"%s %s",fun,ob) != 2)
    {
	if (sscanf(str,"#'%s",fun) != 1)
	    ob = str;
    }
    else
	if (sscanf(fun,"#'%s",fun) != 1)
	    FAIL(DUMP_USAGE);

    if (!fun)
	fun = "dump_print";
    else
	fun = "dump_" + fun;

    cfun = symbol_function(fun,this_object());
    if (!cfun)
    {
	write("Die Funktion '" + fun + "' ist nicht definiert.\n");
	return 1;
    }

    // Diese zwei Zeilen sind nichts anderes als ein set_this_player(0)
    enable_commands();
    disable_commands();

    do_dump(({0,this_object()}),owner,cfun,ob,0);
    return 1;
}
