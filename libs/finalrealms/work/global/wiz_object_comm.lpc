// Radix added logging of "update <player>"   Dec 15, 1995

#define MASTER "/secure/master"
#define PEOPLER "/obj/handlers/peopler"

varargs object *wiz_present(string str, object onobj, int nogoout);
string desc_object(mixed o);
string desc_f_object(object o);

protected void wiz_commands() {
    add_action("function2","call");
    //add_action("parse_frogs", ";");
    add_action("parse_frogs", ";");
} /* wiz_commands() */

/*
** commands in the app_commands will go to all players with
** level >= 20. This includes players who have opted to
** remain players rather than advancing to wizard. As such
** we must be careful in what we place here
*/


/* This is for querying about objects who don't want to be destructed */
nosave object discard_obj;

int affirmative(string s) /* returns true if s is a 'yes' equiv response */
{
    s = lower_case(s);
    return (s == "y" || s == "yes" || s == "ok" || s == "please");
} /* affirmative() */

/* is there an error?  print it */
void handle_error(string erm, string desc) {
    if (erm) {
	write(desc + " failed : " + erm);
    }
} /* handle_error() */


nosave object *dest_obj; 
nosave int objn, majd;

string desc_object(mixed o){
    string str;

    if (!o) return "** Null-space **";
    if (!catch(str = (string)o->short()) && str) return str;
    if (!catch(str = (string)o->query_name()) && str) return str;
   return file_name(o);
} /* desc_object() */

string desc_f_object(object o){
    string created;
    string str = desc_object(o);
    if (o && str != file_name(o)) {
      // Access check - Radix
      if(!master()->valid_read(file_name(o),NAME,0))
          return str;
    }
    str += "("+file_name(o)+")";
    // Added create_me id - Radix
    if(master()->query_lord(NAME) ||
       master()->query_high_programmer(NAME))
    {
        created = o->query_create_me();
        if(created && created != "Object" && created != "Root")
            str += "["+created+"]";
    }
    return str;
} /* desc_f_object() */

object *wzpresent2(string str, mixed onobj) {
    int i;
    object *obs, obj, *obs2;
    string s1, s2;

    if (pointerp(onobj)) {
	obs = ({ });
	for(i = 0; i < sizeof(onobj); i++)
	    obs += wzpresent2(str,onobj[i]);
	return obs;
    }

    if (str == "all")
	return all_inventory(onobj);

    /* every fish */

    if (sscanf(str,"every %s",s1) == 1) {
	obs2 = all_inventory(onobj); 
	obs = ({ });
	for (i=0;i<sizeof(obs2);i++)
	    if (obs2[i]->id(s1)) obs += ({ obs2[i] });
	return obs;
    }

    obs2 = find_match(str,onobj);
    if(sizeof(obs2)) {
	return obs2;
    }

    if (obj = present(str,onobj)) return ({ obj });
    for (obj = first_inventory(onobj); obj; obj = next_inventory(obj)) {
	s2 = file_name(obj);
	if (sscanf(s2, "%s"+str+"#%d", s1, i)
	  || sscanf(s2, "%s#"+str, s1)) {
	    return ({ obj });
	}
    }
    return ({ });
} /* wiz_present2() */

varargs object *wiz_present(string str, object onobj, int nogoout) {
    /* nogoout is so that it WON'T check the environment of onobj */
    int i,j;
    object ob, *obs, *obs2;
    string s1, s2, *sts;

    if (!str || !onobj) {
	return ({ });
    }

    /* all the simple ones first */

    if(str[0] == '@') {
	if (ob = find_living(
	    (string)this_player()->expand_nickname(extract(str, 1))))
	    return ({ ob });
	notify_fail("Unable to find living object: "+extract(str,1)+".\n");
	return ({ });
    }

    if (str == "me") return ({ this_player() });

    if (str == "here") return ({ environment(this_player()) });

    if (str == "everyone") return users();

    if(str[0] == '/') {
	if (ob = find_object(str)) return ({ ob });
	if (sizeof((sts = (string *)this_object()->get_cfiles(str))))  {
	    obs = ({ });
	    for (i=0;i<sizeof(obs);i++)
		if ((ob = find_object(sts[i])))
		    obs += ({ ob });
	    return obs;
	}
	notify_fail("No loaded object: "+str+".\n");
	return ({ });
    }

    /* (fish) == environment of fish */

    if (str[0] == '(' && str[strlen(str) - 1] == ')') {
	obs = wiz_present(extract(str,1,strlen(str) - 2),onobj);
	if (!sizeof(obs)) return obs;
	for (i = 0; i < sizeof(obs); i++) obs[i] = environment(obs[i]);
	return obs;
    }

    /* handle "fish on fish2" */

    if (sscanf(str,"%s on %s",s1,s2) == 2 ||
      sscanf(str,"%s in %s",s1,s2) == 2) {
	obs = wiz_present(s2, onobj);
	if (!sizeof(obs)) return obs;
	obs2 = ({ });
	for (i = 0; i < sizeof(obs); i++) 
	    obs2 += wiz_present(s1,obs[i],1);
	return obs2;
    }

    /* fish and fish2 */

    if (sscanf(str,"%s and %s",s1,s2) == 2) {
	obs = wiz_present(s1, onobj);
	obs2= wiz_present(s2, onobj);
	for (i=0;i<sizeof(obs);i++)  /* remove duplicates ... */
	    if (member_array(obs[i], obs2) < 0) obs2 += ({ obs[i] });
	return obs2;
    }

    /* fish except fish2 */

    if (sscanf(str,"%s except %s",s1,s2) == 2 ||
      sscanf(str,"%s but %s",s1,s2) == 2) {
	obs = wiz_present(s1, onobj);
	obs2= wiz_present(s2, onobj);
	for (i=0;i<sizeof(obs2);i++)
	    while ((j=member_array(obs2[i], obs)) > -1)
		obs = delete(obs,j--,1);
	return obs;
    }

    if (sscanf(str,"player %s",s1)) return ({ find_player(s1) });

    if (!sizeof(obs2 = wzpresent2(str,onobj)) && !nogoout) {
	obs2 = wzpresent2(str, environment(onobj));
    }

    if (sizeof(obs2)) return obs2;

    /* check for a find_match locally */

    obs2 = find_match(str,onobj);
    if (sizeof(obs2) > 0) return obs2;

    /* default to return find_living ...  */

    if (ob = find_living((string)this_player()->expand_nickname(str)))
	return ({ ob });

    return ({ });
} /* wiz_present() */

protected mixed *parse_args(string str, string close) {
    mixed *args, *m, *m2;
    object *obs;
    string s1, s2, s3, s4, s5, s6, s7;
    int i;
    mapping map;

    args = ({ });
    while (strlen(str)) {
	while (strlen(str) && str[0] == ' ') str = str[1..1000];
	if (!strlen(str) || str[0..0] == close) return ({ args, str[1..1000] });
	switch (str[0]) {
	case '\'' :
	    if (sscanf(str, "'%s'%s", s1, s2) != 2) {
		write("Unterminated string.\n");
		return 0;
	    }
	    args += ({ replace(s1, "\\n", "\n") });
	    str = s2;
	    break;
	case '`' :
	    if (sscanf(str, "`%s`%s", s1, s2) != 2) {
		write("Unterminated string.\n");
		return 0;
	    }
	    args += ({ replace(s1, "\\n", "\n") });
	    str = s2;
	    break;
	case '"' :
	    if (sscanf(str, "\"%s\"%s", s1, s2) != 2) {
		write("Unterminated string.\n");
		return 0;
	    }
	    args += ({ replace(s1, "\\n", "\n") });
	    str = s2;
	    break;
	case '{' :
	    m = parse_args(str[1..1000], "}");
	    if (!m)
		return 0;
	    args += ({ m[0] });
	    str = m[1];
	    break;
	case '[' :
	    str = str[1..1000];
	    map = ([ ]);
	    while (1) {
		m = parse_args(str, ":");
		/* Ok...  if we cannot find another : maybe we are at the end? */
		if (!m) {
		    while (strlen(str) && str[0] == ' ') str = str[1..1000];
		    if (str[0] == ']')
			break;
		}
		if (!(m2 = parse_args(str, ","))) {
		    if (!(m2 = parse_args(str, "]")))
			return 0;
		    if (sizeof(m[0]))
			map[m[0][0]] = (sizeof(m2[0])?m2[0][0]:0);
		    break;
		}
		if (sizeof(m[0]))
		    map[m[0][0]] = (sizeof(m2[0])?m2[0][0]:0);
	    }
	    args += ({ map });
	    break;
	case '|' :
	    if (sscanf(str, "|%s|%s", s1, s2) != 2) {
		write("Unmatched |\n");
		return 0;
	    }
	    obs = wiz_present(str, this_player());
	    if (!sizeof(obs))
		args += ({ this_player() });
	    else if (sizeof(obs) == 1)
		args += ({ obs[0] });
	    else
		args += ({ obs });
	    str = s2;
	    break;
	case '0'..'9' :
	case '-' :
	    if (sscanf(str, "%d%s", i, str) != 2) {
		write("Number expected.\n");
		return 0;
	    }
	    args += ({ i });
	    break;
	default :
	    s2 = s3 = 0;
	    sscanf(str, "%s,%s", s4, s2);
	    sscanf(str, "%s"+close+"%s", s5, s3);
	    if (sscanf(str, "%s->%s", s6, s7) == 2 &&
	      (!s3 || strlen(s5) > strlen(s6)) &&
	      (!s2 || strlen(s4) > strlen(s6))) {
		/* Now we do something trully revolting.... */
		while (s7[0] == ' ') s7 = s7[1..1000];
		if (sscanf(s7, "%s(%s", s1, s7) != 2) {
		    write("'(' expected.\nLine left unprocessed"+s7+"\n");
		    return 0;
		}
		obs = wiz_present(s6, this_player());
		if (!sizeof(obs)) {
		    write("The object "+s6+" needs to exist.\n");
		    return 0;
		}
		m = parse_args(s7, ")");
		if (!m) return 0;
		if (sizeof(m[0]) < 6) m[0] += allocate(6-sizeof(m[0]));
		obs = map_array(obs, "mapped_call", this_object(), ({ s1 })+m[0]);
		if (sizeof(obs) == 1)
		    args += obs;
		else
		    args += ({ obs });
		str = m[1];
		break;
	    } else if (s2 && s3)
		if (strlen(s4) < strlen(s5)) {
		    s1 = ",";
		    str = s4;
		} else {
		    s1 = close;
		    s2 = s3;
		    str = s5;
		} else if (s2) {
		s1 = ",";
		str = s4;
	    } else if (s3) {
		s1 = close;
		s2 = s3;
		str = s5;
	    } else {
		s1 = "";
		s2 = "";
	    }
	    obs = wiz_present(str, this_player());
	    if (!sizeof(obs)) {
		if (str[0] >= '0' && str[0] <= '9' || str[0] == '-') {
		    sscanf(str, "%d%s", i, str);
		    args += ({ i });
		} else 
		    args += ({ replace(str, "\\n", "\n") });
	    } else if (sizeof(obs) == 1)
		args += ({ obs[0] });
	    else
		args += ({ obs });
	    str = s1+s2;
	    break;
	}
	/* Skip rubbish and if we dont have a comma we have finished. */
	while (strlen(str) && str[0] == ' ') str = str[1..1000];
	if (!strlen(str))
	    return ({ args, str });
	if (str[0..0] == close)
	    return ({ args, str[1..1000] });
	if (str[0] != ',') {
	    write("Parse error reading arguments, ',' or '"+close+"' expected.\n");
	    write("Line left unprocessed "+str+"\n");
	    return 0;
	}
	str = str[1..1000];
    }
    return ({ args, str });
} /* parse_args() */

void inform_of_call(object ob, mixed *argv) {
    string str;
    int i;
   if(!ob) return;

    str = this_object()->query_cap_name() + " calls " + argv[0] + "(";
    for (i=1; i<sizeof(argv); ) {
	str += replace(sprintf("%O", argv[i]), "\n", " ");
	if (++i < sizeof(argv)) str += ",";
    }
    /* Arggghhh!  This is annoying me.
      ob->event_inform(this_object(), str + ") on you", "call");
     */
} /* inform_of_call() */

protected mixed mapped_call(object ob, mixed *argv) {
    inform_of_call(ob, argv);
    return call_other(ob, argv[0], argv[1],argv[2],argv[3],
      argv[4],argv[5],argv[6]);
} /* mapped_call() */

/* Free form parse_args code */
protected int parse_frogs(string str) {
    mixed junk;

    if ( this_player()->query_current_action_forced() )
      return 0;
    /* We are not as such looking for an end thingy of any sort... */
    junk = parse_args(str, ";");
    /* It has already printed an error, so we return 1... */
    if (!junk) return 1;
    log_file("EXECS",(string)this_player(1)->query_cap_name()+" exec'd "+str+"\n");
    write("The line "+str+" Returns: \n");
    printf("%O\n", junk[0]);
    this_object()->set_trivial_action();
    return 1;
} /* parse_forgs() */

protected int function2(string str) {
    /* call fish(x,y,z) object */
    mixed *args;
    string *s, s1, s2;
    string fn,os;
    string *argv;
    object *ov,retobj;
     // Hack, should be object not mixed. Baldrick jan'97.
    //object fish, shad, f, file;
    mixed fish, shad, f, file;
    int i;

    if ( this_player()->query_current_action_forced() )
      return 0;
    if (!str) {
	notify_fail("USAGE : call lfun(arg[,arg[,arg...]]) object[s]\n");
	return 0;
    }
    log_file("CALLS",(string)this_player()->query_cap_name()+" CALLS "+str+"\n");
    s = explode("&"+str+"&", ")");
    if (sizeof(s) < 2 || sscanf(s[0], "%s(%s", s1, s2) != 2) {
	notify_fail("USAGE : call lfun(arg[,arg[,arg...]]) object[s]\n");
	return 0;
    }
    fn = replace(s1[1..1000], " ", "");
    s[0] = s2;
    args = parse_args(implode(s, ")"), ")");
    if (!args) return 1;
    argv = args[0];
    os = args[1][0..strlen(args[1])-2];
    while (strlen(os) && os[0] == ' ') os = os[1..1000];
    notify_fail("Can't find object "+os+".\n");
    ov = wiz_present(os,this_object());

    if (!sizeof(ov)) return 0;

    if (sizeof(argv) < 6) argv += allocate(6 - sizeof(argv));
    for (i=0; i < sizeof(ov); i++) {
	fish = ov[i];
	while (shad = shadow(fish, 0)) {
	    fish = shad;
	    if (f = function_exists(fn, fish)) 
              file = f;
	}
	if (!file) file = function_exists(fn, ov[i]);
	if (file) {
	    retobj = call_other(ov[i],fn,argv[0],argv[1],argv[2],
	      argv[3],argv[4],argv[5]);
	    inform_of_call(ov[i], ({ fn }) + argv);
	    if ( ov[i] && interactive(ov[i]) && !ov[i]->query_creator() )
		log_file("CALLP",ctime(time())+": "+(string)this_player()->query_cap_name()+" CALLS "+str+" -- player "+(string)ov[i]->query_name()+"\n");
	    write("*** function on '"+ desc_object(ov[i])+"' found in "+
	      file+" ***\n");
	    write("Returned: ");
	    printf("%O\n", retobj);
	} else
	    write("*** function on '"+desc_object(ov[i])+"' Not found ***\n");
	file = 0;
    }
    this_object()->set_trivial_action();
    return 1;
} /* function2() */

