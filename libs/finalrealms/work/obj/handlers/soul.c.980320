inherit "std/object";
#define HOME "/obj/handlers/weather_room"

/*
 * ok format...
 * name ({ your st, everyone st })
 * or (one arg version ie sigh)
 * name ({ your st, their st, everyone st })
 * or (two only arg version.)
 * name ({ your st, everyone st, arg st, their arg, everyone arg })
 * or (one or two arg version)
 * name ({ ({ as above }), ({ as above }) })
 * for cases where the male and female versions are different.
 * works on targets gender. should really be the two arg only version.
 * hmmm going to need some actual processing.
 *
 * 0 == search for living name
 * 1 == search for living name and change thingy
 * 2 == search for change thingy and living name
 * 3 == search for change thingy
 */

mapping soul_data;
string  lastarg, calc_long, global_adj;

mapping query_soul_data() { return soul_data + ([ ]); }

create() 
{
    ::create();
    set_name("soul");
    set_short(0);
    calc_long = 0;
    lastarg = "";

    // Taniwha 1995, move it here, players can't pick it up
    catch(load_object(HOME));
    call_out("move",2,HOME);

#include "/table/soul_data.c"
}

string query_long() 
{
    int i;
    string s, s1, s2, bit;
    string *cmds;
    mixed  *values;


    s = "Here are the current soul commands in this hoopy soul.\n"
    "The # before a soul command means it has strange arguments.\n"
    "The * after a soul command means you can only use it at someone.\n"
    "Total number of soul data is "+m_sizeof(soul_data)+"\n"
    "The + after a soul command means you can use it both at someone and "
    "not.\n";

    if (stringp(calc_long)) 
    {
        s += sprintf("%#-*s\n", this_player()->query_cols(), calc_long);
        s += "\nShare and enjoy.\nPlease use the \"soul\" command "
        "to report errors and additions.\n";
        return s; 
    }

    cmds   = m_indices(soul_data);
    values = m_values(soul_data);
    calc_long = "";
    cmds = sort_array(cmds, 1);

    for (i = 0; i < sizeof(cmds);i ++) 
    {
        bit = cmds[i];
        values = soul_data[bit];
        if (sizeof(values[1]) == 3) 
            bit += "*";
        else if (sizeof(values[1]) == 5) 
            bit += "+";
        if (sscanf(values[1][0],"%s$arg:%s",s1,s2) == 2)
            bit = "#"+bit;
        calc_long += bit+"\n";
    }


    s += sprintf("%#-*s\n", this_player()->query_cols(), calc_long);

    s += "\nShare and enjoy.\nPlease use the \"soul\" command "
    "to report errors and additions.\n";

    return s;
}

int soul_sort(string s1, string s2) 
{
    return s1 > s2;
}

string long(string str, int dark) 
{
    return query_long();
}

//string parse_string(string s, object me, object ob, string arg, int uhn)
string parse_string(string s, object me, mixed ob, string arg, int uhn)
{
    string s1, s2, s3, s4, str, s5, arr;
    int i;

    str=s;
    s4 = "";
    while (sscanf(str,"%s$%s$%s",s1,s2,s3) == 3)
        switch (s2) 
    {
    case "mcname" :
        str = s1+me->query_cap_name()+s3;
        break;
    case "mname" :
        str = s1+me->query_name()+s3;
        break;
    case "mpronoun" :
        str = s1+me->query_pronoun()+s3;
        break;
    case "hpronoun" :
        str = s1+ob->query_pronoun()+s3;
        break;
    case "mobj" :
        str = s1+me->query_objective()+s3;
        break;
    case "hobj" :
        str = s1+ob->query_objective()+s3;
        break;
    case "mposs" :
        str = s1+me->query_possessive()+s3;
        break;
    case "hposs" :
        str = s1+ob->query_possessive()+s3;
        break;
    case "lastarg" :
        str = s1+lastarg+s3;
        break;
    case "mhcname" :
        if (uhn) 
        {
            str = s1+ob->query_cap_name()+"'s"+s3;
            break;
        }
    case "hcname" :
        if (uhn) 
        {
            str = s1+ob->query_cap_name()+s3;
            break;
        }
    case "hname" :
        if (uhn) 
        {
            str = s1+ob->query_name()+s3;
            break;
        }
    default :
        s4 += s1+"$"+s2;
        if (!s3)
            str = "$";
        else
            str = "$"+s3;
        break;
    }

    str = s4+str;

    while (sscanf(str,"%s$force#%s#%d$%s",s1,s2,i,s3)==4) 
    {
        call_out("do_force", i, ({s2, ob}));
        str = s1+s3;
    }

    while (sscanf(str,"%s$arg:%s$%s",s1,s2,s3)==3) 
        if (arg == "?") 
        {
            string *yellow;

            yellow = explode(s2, ",");
            lastarg = yellow[random(sizeof(yellow))];
            str = s1+lastarg+s3;
            lastarg = replace(lastarg, "your", me->query_possessive());
        } 
        else if (s2 == "#") 
        {
            lastarg = replace(arg, "your", me->query_possessive());
            str = s1+arg+s3;
        } 
        else if (sscanf(","+s2+global_adj+",", "%s,"+arg+"%s,%s", s2, s4, s5) == 3) 
        {
            str = s1+arg+s4+s3;
            lastarg = replace(arg+s4, "your", me->query_possessive());
        } 
        else if (sscanf(","+s2+",", "%s,#,%s", s2, s4) == 2) 
        {
            str = s1+arg+s3;
            lastarg = replace(arg, "your", me->query_possessive());
        } 
        else 
        {
            // Cadogan by hand of Radix...
            write("You cannot do that.  Type \"help <soul>\" for "
              "available options.\n");
            //    write("You cannot do that. Available options are "+
            //      replace(s2, ",", ", ")+"\n");
            return 0;
        }

    while (sscanf(str,"%s$ifarg:%s~$%s",s1,s2,s3)==3) 
    {
        string estr;

        sscanf(s2,"%s$else$%s",s2,estr);
        if (arg && arg != "")
            str = s1+parse_string(s2,me,ob,arg, 1)+s3;
        else if (estr)
            str = s1+parse_string(estr,me,ob,arg, 1)+s3;
        else
            str = s1+s3;
    }

    return str;
}

object* find_all_liv(string str, object me) 
{
    mixed ob; 
    object *ret;
    int i;

    ret = ({ });
    str = lower_case(str);

    /* Wonder how the players will like this one, the thieves surely will..
     * removing the pssibility to soul all in a room
     * Baldrick, jan '95 (Hmm.. this years first change..:=)
     */
    if (str == "all" || str[0..0] == "0")
    {
        notify_fail("Sorry, you don't know all.\n");
        return 0;
    } 

    /* Used for spamming anyway - why do you always undo what I do Wonderflug?
        if (str == "someone") 
        {
            // Radix was, was a random() return of users() array
            // Wonderflug, it is again.  But we filter invisibles
            ret = users();
            for (i=0;i<sizeof(ret);i++)
                if ( ret[i]->query_invis() )
                    ret = delete(ret, i--, 1);

            return ({ ret[random(sizeof(ret))] });
        }
    */

    ob = find_match(str, environment(me), 1);
    for (i=0;i<sizeof(ob);i++)
        if ( living(ob[i]) && ob[i] != me
          && member_array(ob[i], ret) == -1)
            ret += ({ ob[i] });

    if (sizeof(ret)) 
        return ret;

    /* Will add an attemt to hide invis people in the room 
     * Baldrick, dec '94
     * Fixed above attempt, Wonderflug oct '95
     */
    if ( (ob = find_living(str)) && ob != me
      && ( !ob->query_invis() || me->query_creator() )
    )
        ret = ({ ob });

    return ret;
} /* find_all_liv() */

string get_name(object ob) 
{
    return (string)ob->query_cap_name();
}

int soul_command(string verb, string str, object m)
{
    int i, j, lvl;
    //object *ob, *tmp_ob;
    mixed ob, tmp_ob;
    object me;
    string tmp, nick, last, liv, other, s1, s2, livfail;
    mixed  *data;

    /* set up whoever is doing this soul */
    if ( m )
        me = m;
    else if ( previous_object() )
        me = previous_object();
    else 
        me = this_player();

    lastarg = "";
    ob = ({ });
    if ( !verb )
        return 0;
    data = soul_data[verb];
    if (!data) 
        return 0;

    if (str && sizeof(data[1]) == 2 && data[1][0] != '#') 
        notify_fail("No matter how hard you try, you fail to manage this.\n");

    /* this if/else/for/switch parses the string passed by the player into 
     * object bits and string bits, according to how the specific soul
     * expects the string.  each pair of elements in data[0] represents
     * a different way of parsing things
     */
    if (!data[0] || !str) 
    {
        liv = 0;
        other = "";
    } 
    else 
        for (j = 0; j < sizeof(data[0]); j += 2)
            switch (data[0][j]) 
        {
        case 0 :
            if (lvl > 1)
                break;
            if (sscanf(str, data[0][j+1], s1)==1
              && (sizeof((tmp_ob=find_all_liv(s1, me))))) 
            {
                lvl = 1;
                other = "";
                liv = s1;
                ob = tmp_ob;
            } 
            else
                livfail = s1;
            break;
        case 1 :
            if (lvl > 2)
                break;
            if (sscanf(str, data[0][j+1], s1, s2)==2
              && (sizeof((tmp_ob=find_all_liv(s2, me))))) 
            {
                lvl = 2;
                liv = s2;
                other = s1;
                if (data[0][j+1] != "%s %s")
                    lvl++;
                ob = tmp_ob;
            } 
            else
                livfail = s2;
            break;
        case 2 :
            if (lvl > 2)
                break;
            if (sscanf(str, data[0][j+1], s1, s2) ==2
              && (sizeof((tmp_ob=find_all_liv(s1, me))))) 
            {
                lvl = 2;
                liv = s1;
                other = s2;
                if (data[0][j+1] != "%s %s")
                    lvl++;
                ob = tmp_ob;
            } 
            else
                livfail = s2;
            break;
        case 3 :
            if (lvl > 0)
                break;
            if (sscanf(str, data[0][j+1], s1) == 1) 
            {
                other = s1;
                liv = 0;
                ob = ({ });
            }
            break;
        }

    if (liv) 
    {
        /* The soul has been directed at someone.  The string of someone's
         * is now in liv; ob may be an array of objects corresponding to them.
         * Extra stuff they typed is in other.
         */
        string mine, his, every;

        str = other;
        if (!sizeof(ob)) 
        {
            notify_fail("Sorry, but '"+liv+"' is not logged in.\n");
            return 0;
        }

        /* Get the strings that will be parsed. */
        if (sizeof(data[1])==3) 
        {
            mine = data[1][0];
            his = data[1][1];
            every = data[1][2];
        } 
        else if (sizeof(data[1])==5) 
        {
            mine = data[1][2];
            his = data[1][3];
            every = data[1][4];
        } 
        else 
        {
            notify_fail("You cannot use that soul command in two thingy mode.\n");
            return 0;
        }
        if (sizeof(ob) == 1) 
        {
            tmp = parse_string(mine, me, ob[0], str, 1);
            if (!tmp)
                return 1;
            s2 = parse_string(every, me, ob[0], str, 1);

            /* Now do various events. */

            /* To me */
            me->event_soul(me, tmp+".\n");

            /* To him */
            if(ob[0]->query_blocking() == me->query_name())
            {
                tell_object(ob[0],me->query_cap_name()+" is "
                  "blocking your souls.\n");
                return 1;
            }
            ob[0]->event_soul(me, 
              parse_string(his, me, ob[0], str, 1)+".\n");
            if(ob[0]->query_npc())
                ob[0]->soul_act(me, verb);

            /* This is undefined by almost everything.  I fail to see any use. 
             * So it goes.  Wonderflug
             * ob[0]->event_soul_command(this_object(), verb, me, liv, other);
             */

            /* To everyone in the room. */
            event(environment(me), "soul", s2+".\n",
              ({ ob[0], me }), verb, last, ob[0]);

            /* To everyone if its a far-soul AND target is not hidden */
            if (environment(ob[0]) && environment(ob[0]) != environment(me)
              && !ob[0]->query_invis() && !ob[0]->query_hide_shadow() )
                event(environment(ob[0]), "soul", s2+".\n",
                  ({ ob[0], me }), verb, last, ob[0]);
        } 
        else 
        {
            tmp = parse_string(mine, me, ob, str, 0);
            if (!tmp)
                return 1;
            parse_string(his, me, ob, str, 0); /* To get the forces */
            s2 = parse_string(every, me, ob, str, 0);
            tmp_ob = map_array(ob, "get_name", this_object());

            s1 = implode(tmp_ob[1..1000], ", ")+" and "+tmp_ob[0];
            s1 = replace(s2, ({ "$hcname$", s1, "$mhcname$", s1+"'s" }));
            me->event_soul(me, s1+".\n");

            /* This goes away, Wonderflug
             *if ((int)this_player()->query_social_points() < sizeof(ob)*3) 
             *{
             *  notify_fail("Not enough social points.\n");
             *  return 0;
             *}
             *this_player()->adjust_social_points(-sizeof(ob)*3);
             */

            event(environment(ob[0]), "soul", s1+".\n", 
              ({ me })+ob, verb, last, ob);
            for (i=0;i<sizeof(ob);i++)
                ob[i]->event_soul(me, 
                  replace(s2, 
                    ({ "$hcname$", 
                      implode(tmp_ob - ({ get_name(ob[i])}),", ")+" and you",
                      "$mhcname$", 
                      implode(tmp_ob - ({ get_name(ob[i])}),", ")+" and your",
                    }))+ ".\n" );

        } /* else .. sizeof(ob) != 1 */

        return 1;

    } /* if (liv) */
    else if (sizeof(data[1])==3) 
    {
        if (!livfail)
            notify_fail("You don't have the courage to do that.\n");
        else
            notify_fail("Cannot find '"+livfail+"'.\n");
        return 0;
    }

    if (!other)
        other = "";

    tmp = parse_string(data[1][0], me, ob, other, 0);

    if (!tmp)
        return 1;

    me->event_soul(me, tmp+".\n");
    event(environment(me), "soul",
      parse_string(data[1][1], me, me, other, 0)+".\n",
      ({ me }), verb, last, 0);
    return 1;
}

void do_force(mixed* str)
{
    int i;

    if (pointerp(str[1]))
        for (i=0;i<sizeof(str[1]);i++)
            str[1][i]->soul_com_force(str[0]);
    else
        str[1]->soul_com_force(str[0]);
}

void add_soul_command(string name, mixed format, mixed thingo) 
{
    if (soul_data[name]) 
        return;

    if (format && !pointerp(format))
        return ;
    if (!stringp(name) || !pointerp(thingo)
      || member_array( sizeof(thingo), ({ 2, 3, 5 }) ) == -1 )
        return ;
    soul_data[name] = ({ format, thingo });
}

void delete_soul_command(string name) 
{
    soul_data = m_delete(soul_data, name);
}

string help_soul(string str) 
{
    int j;
    int i, off;
    string s1, s2, s3, s4, ret, *bit;
    object ob;
    mixed *data;

    data = soul_data[str];
    if (!data) 
        return 0;

    ret = "";
    if (!pointerp(data[0])) 
        return "The soul command "+str+" has no optional parameters at all.\n";

    for (j = 0; j < sizeof(data[0]);j += 2) 
    {
        bit = explode(" " + data[0][j+1]+" ","%s");
        switch (data[0][j]) 
        {
        case 0: 
            ret += str+bit[0]+"<person>"+bit[1];
            break;
        case 2:
            ret += str+bit[0]+"<person>"+bit[1]+"<argument>"+bit[2];
            break;
        case 1:
            ret += str+bit[0]+"<argument>"+bit[1]+"<person>"+bit[2];
            break;
        case 3:
            ret += str+bit[0]+"<argument>"+bit[1];
            break;
        }
        ret += "\n";
    }

    ret += "Usage of the soul command "+str+"\n"+
    sprintf("%-#*s\n\n\n", this_player()->query_cols(), ret);

    if (sizeof(data[1]) == 2 || sizeof(data[1]) == 5) 
    {
        ret += "In no living object mode.\n";
        bit = ({ });
        if (sscanf(data[1][0], "%s$arg:%s$%s", s1,s2,s3) == 3)
            bit = explode(s2,",");
        if (sscanf(data[1][0], "%s$ifarg:%s~$%s", s1, s2, s3) == 3) 
            ret += "Has a different no arguments command.\n"
            "The arguments are selected from "+implode(bit,", ")+"\n";
        else if (!sizeof(bit))
            ret += "Has no cute arguments\n";
        else
            ret += "Has cute arguments of "+implode(bit,", ")+"\n";
        ret += "\n\n";
        off = 2;
    }

    if (sizeof(data[1]) == 3 || sizeof(data[1]) == 5) 
    {
        ret += "In living object mode\n";
        bit = ({ });
        if (sscanf(data[1][off+0], "%s$arg:%s$%s", s1,s2,s3) == 3)
            bit = explode(s2,",");
        if (sscanf(data[1][off+0], "%s$ifarg:%s~$%s", s1, s2, s3) == 3) 
            ret += "Has a different no arguments command.\n"
            "The arguments are selected from "+implode(bit,", ")+"\n";
        else if (!sizeof(bit))
            ret += "Has no cute arguments\n";
        else
            ret += "Has cute arguments of "+implode(bit,", ")+"\n";
        off = 2;
    }

    return ret;
}
