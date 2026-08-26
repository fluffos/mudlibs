/**
 * Finger Handler - Started by Shaydz, 7/04/2001 11:29AM
 * A couple of functions taken from Discworld's finger handler.
 * @change Changed by Shiannar slightly 18/08/01.
 * @change Rewritten partly to work more closely with the player handler
 * - Sandoz, May 2002.
 */

#include <alias.h>
#include <clubs.h>
#include <finger.h>

inherit "/std/basic/club_listing";

/** @ignore yes */
void create() {
    seteuid("Root");
} /* create() */

/**
 * This method creates a nice string from the input player alias.
 * @param al the alias to create a string from
 * @param brief whether or not we are in brief/colourless mode
 * @return the input player alias in a nice string
 */
string make_string( mixed al, int brief ) {
    string str;
    int i, lines;

    str = ALIAS_CMD->alias_string(al);
    sscanf( str, "%s $*$", str );
    str = replace( str, sprintf("%c", 7 ), "^G");

    if( brief ) {
        str = strip_colours(str);
        str = replace( str, ({"@@", "@ @ ", "%^", ""}) );
        for( i = lines = 0; i < sizeof(str) && i < 3*80 && lines < 3; i++ ) {
            if( str[i] == '\n' || str[i] == ';')
                lines++;
        }
        return str[0..i-1];
    }

    return str;

} /* make_string() */

/**
 * This method returns the finger info for banished players/names.
 * @param name the name to get the finger for
 * @return the banished finger info
 */
string banish_finger( string name ) {
    string ret, *file;

    file = explode( read_file("/banish/"+name[0..0]+"/"+name+".o"), "\n");
    ret =  sprintf("%35-s%35-s\n",
        "Login name : "+name,
        "Real name : "+"Banished");

    if( objectp(TP) && creatorp(TP) )
        if( sizeof(file) == 3 )
            ret += implode( file, "\n")+"\n";
        else
            ret += "Banish info not in the correct format.\n";

    return replace( ret, "@@", "@ @ ");

} /* banish_finger() */

/** @ignore yes */
mixed remote_banish_finger( string name ) {
    mixed ret;

    ret = allocate(9);
    ret[0] = name;
    ret[1] = "The titleless";
    ret[2] = "Banished";
    ret[3] = "none";
    ret[4] = "";
    ret[5] = -1;
    ret[6] = 0;
    ret[7] = 0;
    ret[8] = 0;

    return ret;

} /* remote_banish_finger() */

/**
 * This method returns the finger info for the specified domain.
 * @param name the domain to get finger info for
 * @return the domain's finger info
 */
string domain_finger( string name ) {
    string s, info, *leaders, *seniors, *members, tmp;
    int cols,i;
    mapping projects;
    
    leaders = DOMAIN_H->query_leaders(name);
    seniors = DOMAIN_H->query_seniors(name);
    projects = PROJECT_H->query_projects(name);
    
    members = map( DOMAIN_H->query_members(name) -
              uniq_array( seniors + leaders ), (: CAP($1) :) );

    seniors = map( seniors - leaders, (: CAP($1) :) );
    leaders = map( leaders, (: CAP($1) :) );

    cols = (int)TP->query_cols() -2;

    s = "Name:    "+DOMAIN_H->query_short(name)+"\n";
    s += ( !sizeof(leaders) ? "Lords:   None" : sprintf("%s%-=*s",
           "Lords:   ", cols - strlen("Lords: "),
           query_multiple_short( asort(leaders) ) ) )+".\n";
    s += ( !sizeof(seniors) ? "Seniors: None" : sprintf("%s%-=*s",
           "Seniors: ", cols - strlen("Seniors: "),
            query_multiple_short( asort(seniors) ) ) )+".\n";
    s += ( !sizeof(members) ? "Members: None" : sprintf("%s%-=*s",
           "Members: ", cols - strlen("Members: "),
           query_multiple_short( asort(members) ) ) )+".\n\n";

    if( name == "playtesters")
        s += sprintf("%s%-=*s", "Playtesters: ",
             cols - strlen("Playtesters: "), query_multiple_short(
             asort( map( PLAYTESTERS_H->query_playtesters(),
             (: CAP($1) :) ) ) ) )+".\n\n";

    if( info = DOMAIN_H->query_long(name) )
        s += sprintf("%s%-=*s\n", "Domain Info: ",
             cols - strlen("Domain Info: "), info );
    if(sizeof(projects)){
       tmp = "%^BOLD%^Projects:%^RESET%^\n";
       tmp += sprintf( "  %-*s%-*s\n", 33, "%^WHITE%^Creator%^RESET%^", 46,
                     "%^WHITE%^Project%^RESET%^");
       foreach(string cre in keys(projects)){
          for ( i = 0; i < sizeof( projects[cre] ); i++ ) {
               tmp += sprintf( "  %-*s%-=*s\n", 15, CAP(cre), cols-20,
               projects[cre][i]);
          }
       }
       s += tmp;
    }
    return s;

} /* domain_finger() */

/**
 * This method returns the finger info for the specified project.
 * @param name the project to get finger info for
 * @return the project's finger info
 */
string project_finger( string name ) {
    string s, info, *leaders, *members;
    int cols;

    leaders = PROJECT_H->query_leaders(name);

    members = map( PROJECT_H->query_members(name) - leaders,
        (: CAP($1) :) );
    leaders = map( leaders, (: CAP($1) :) );

    cols = (int)TP->query_cols() - 2;

    s = "Name:    "+ PROJECT_H->query_short(name)+"\n";
    s += ( !sizeof(leaders) ? "Leaders: None" : sprintf("%s%-=*s",
           "Leaders: ", cols - strlen("Leaders: "),
           query_multiple_short( asort(leaders) ) ) )+".\n";
    s += ( !sizeof(members) ? "Members: None" : sprintf("%s%-=*s",
           "Members: ", cols - strlen("Members: "),
           query_multiple_short( asort(members) ) ) )+".\n\n";

    if( info = PROJECT_H->query_long(name) )
        s += sprintf("%s%-=*s", "Project Info: ",
             cols - strlen("Project Info: "), info );

    return s;

} /* project_finger() */

/**
 * This method returns the finger info for lords and their
 * domain belongings.
 * @return lords' finger info
 */
string lord_finger() {
    mapping lord;
    string  ret, domain, leader, *leaders, *domains, *dleaders, *domainless;
    int cols;

    leaders = ({ });
    lord    = ([ ]);
    domains = DOMAIN_H->query_domains();

    cols = (int)TP->query_cols();

    ret = sprintf("%|*'-'s\n", cols,
        "=======[ Lords of "+mud_name()+" ]=======");

    foreach( domain in domains ) {
        dleaders = DOMAIN_H->query_leaders(domain);
        foreach( leader in dleaders ) {
            if( member_array( leader, leaders ) == -1 )
                leaders += ({ leader });
            if( !lord[leader] )
                lord[leader] = ({ CAP(domain) });
            else
                lord[leader] += ({ CAP(domain) });
        }
    }

    leaders = asort(leaders);

    foreach( leader in leaders ) {
        if( lord[leader] )
            ret += CAP(leader)+" is the lord of the "+
                 ( sizeof(lord[leader]) > 1 ?
                   query_multiple_short(lord[leader])+" domains" :
                   lord[leader][0]+" domain")+".\n";
        else
            domainless += ({ CAP(leader) });
    }

    if( sizeof(domainless) == 1 )
        ret += domainless[0]+" is a domainless lord.\n";
    else if( sizeof(domainless) > 1 )
        ret += query_multiple_short(domainless)+" are domainless lords.\n";

    ret += sprintf("%|*'-'s\n", cols, "[ There are "+
        query_num(sizeof(leaders))+" lords and "+
        query_num(sizeof(domains))+" domains ]");

    return ret;

} /* lord_finger() */

/**
 * This method returns the finger for creators.
 * @return creators' finger
 */
string creator_finger() {
    string ret, *creatorList, *sageList, *fadedList;
    int cols;

    cols = (int)TP->query_cols();

    creatorList = DOMAIN_H->query_creators();
    creatorList = asort(creatorList);

    fadedList = filter( creatorList, (:
        DOMAIN_H->query_member("afterlife", $1 ) :) );
    creatorList -= fadedList;

    sageList = filter( creatorList, (: DOMAIN_H->query_member("sage", $1 ) &&
        !DOMAIN_H->query_leader("sage", $1 ) :) );
    creatorList -= sageList;

    creatorList = map( creatorList, (: CAP($1) :) );
    creatorList = map( creatorList,
        (: DOMAIN_H->query_member("idle", lower_case($1) ) ?
        "["+$1+"]" : $1 :) );

    fadedList = map( fadedList, (: CAP($1) :) );
    sageList = map( sageList, (: CAP($1) :) );

    ret =  sprintf("%|*'-'s\n", cols,
           "=======[ Creators of "+mud_name()+" ]=======");
    ret += sprintf("%#-*s\n", cols, implode( creatorList, "\n") );

    if( sizeof(fadedList) ) {
        ret += sprintf("%|*'-'s\n", cols,
               "=======[ Faded Creators ]=======");
        ret += sprintf("%#-*s\n", cols, implode( fadedList, "\n") );
    }

    if( sizeof( sageList ) ) {
        ret += sprintf("%|*'-'s\n", cols,
               "=======[ Visiting Creators ]=======");
        ret += sprintf("%#-*s\n", cols, implode( sageList, "\n") );
    }

    ret += sprintf("%|*'-'s\n", cols,
           "[ There are "+query_num(sizeof(creatorList))+" creators ]");

    return ret;

} /* creator_finger()*/

/**
 * This method returns the information about the specified club.
 * @param name the name of the club to finger
 * @return the club information
 */
string club_finger( string name ) {
    return club_info_string( name, 0, "gumball lord");
} /* club_finger() */

/**
 * This method returns the information about the specified family.
 * @param name the name of the family to finger
 * @return the family information
 */
string family_finger( string name ) {
    return family_info_string( name, "gumball lord");
} /* family_finger() */

/**
 * This method returns finger info for the specified player/name.
 * This is the main entry point of the finger command.
 * @param name the name to get the finger info for
 * @param no_colour whether or not we want it in colour
 * @return the finger info
 */
string finger_info( string name, int no_colour ) {
    string ret, *bing, *lords, *seniors, tmp;
    int i, lines, width, cre;
    class finger_info data;
    mixed deleting;
    object ob;

    width = 78;

    if( TP ) {
        if( tmp = (string)TP->expand_nickname(name) )
            name = tmp;
        width = TP->query_cols() - 2;
    }

    if( DOMAIN_H->query_domain(name) )
        return domain_finger(name);

    if( PROJECT_H->query_project(name) )
        return project_finger(name);

    if( lower_case(name) == "lords")
        return lord_finger();

    if( lower_case(name) == "creators")
        return creator_finger();

    if( lower_case(name) == "domains")
        return create_table(({ "Domains", "domain"}),
               DOMAIN_H->query_domains(), 1 );

//    if( lower_case(name) == "projects")
//        return create_table(({ "Projects", "project" }),
//               PROJECT_H->query_projects(), 1 );

    if( tmp = DEITY_H->query_deity_finger(name) )
        return tmp;

    if( file_size("/banish/"+name[0..0]+"/"+name+".o") > 0 )
        return banish_finger(name);

    ob = find_player(name);

    if( !ob && !PLAYER_H->test_user( name ) ) {
        // Only print the family stuff if there is not a user with that name.
        if( name[0..4] == "club ") {
            if( CLUB_HANDLER->is_club(name[5..]) &&
                !CLUB_HANDLER->is_family(name[5..]) )
                return club_finger(name[5..]);
        } else if( name[0..6] == "family " ) {
            if( CLUB_HANDLER->is_family(name[7..]) )
                return family_finger(name[7..]);
        } else if( CLUB_HANDLER->is_club(name) ) {
            return ( CLUB_HANDLER->is_family(name) ?
                     family_finger(name) : club_finger(name) );
        }
        return 0;
    }

    if( !ob ) {
        if( !unguarded( (: file_exists,
            LOGIN_OBJ->query_player_file_name(name)+".o" :) ) ) {
            if( !unguarded( (: file_exists,
                LOGIN_OBJ->query_delete_player_file_name(name)+".o" :) ) ) {
                return CAP(name)+" doesn't have a character on "+mud_name()+".\n";
            }
            deleting = unguarded( (: stat,
                LOGIN_OBJ->query_delete_player_file_name(name)+".o" :) );
        }
    }

    if( !classp( data = PLAYER_H->query_finger_info(name) ) )
        return "Failed to get finger data for "+CAP(name)+".\n";

    cre = creatorp(name);

    data->real_name = ( !sizeof(data->real_name) ? "Not Known" :
        CAP(data->real_name) );

    data->location = ( !sizeof(data->location) ? "Not Known" :
        CAP(data->location) );

    if( !sizeof(data->birthday) )
        data->birthday = "Not Known";

    if( !sizeof(data->icq) )
        data->icq = "(none)";

    if( !sizeof(data->email) )
        data->email = "(none)";

    if( data->email[0] == ':' )
        data->email = ( !lordp(TP) ? "Not Disclosed" : data->email[1..] );

    if( !sizeof(data->homepage) )
        data->homepage = "(none)";

    if( cre && !sizeof(data->home_dir) )
        data->home_dir = "/w/"+name;

    ret = ( no_colour ? "" : "%^BOLD%^");

    lines = width / 2;
    i = width / 2 - 6;

    ret += sprintf("%*-s%*-=s\n", lines,
           "Login name: "+strip_colours( CAP(name) ), i,
           "Real name:  "+strip_colours( data->real_name ) );

    ret += sprintf("%*-s%*-=s\n", lines,
           "Birthday:   "+strip_colours( data->birthday ), i,
           "Location:   "+strip_colours( data->location ) );

    if( sizeof(data->email) < i - 6 ) {
        ret += sprintf("%*-s%*-=s\n", lines,
           "E-Mail:     "+strip_colours( data->email ), i,
           "ICQ:        "+strip_colours( data->icq ) );
    } else {
        ret += sprintf("%*-s\n", width,
           "E-Mail:     "+strip_colours( data->email ) );
        ret += sprintf("%*-s\n", width,
           "ICQ:        "+strip_colours( data->icq ) );
    }

    ret += sprintf("%*-s\n", width,
           "Home Page:  "+strip_colours( data->homepage ) );

    if( cre )
        ret += sprintf("%*-s\n", width,
           "Home Dir:   "+( data->home_dir == "/" ? "Root Directory" :
           strip_colours( data->home_dir ) ) );

    if( deleting ) {
        ret += ( no_colour ? "" : "%^RED%^")+"This character is marked to be "
                 "deleted in ";
        ret += ( time() - deleting[1] > (10*60*60*24) ? "1 day" :
               ( 10 - ( ( time() - deleting[1] ) / (60*60*24) ) )+" days")+
                 ".\n";
        if( !no_colour )
            ret += "%^WHITE%^";
    }

    if( !no_colour )
        ret += "%^RESET%^";

    if( cre ) {
        ret += CAP(name)+" is ";
        if( adminp(name) )
            ret += "an %^BOLD%^%^BLUE%^Admin%^RESET%^";
        else if( lordp(name) )
            ret += "a %^ORANGE%^Lord%^RESET%^";
        else if( seniorp(name) )
            ret += "a %^RED%^Senior Creator%^RESET%^";
        else if( PROJECT_H->query_leader(name) )
            ret += "a %^GREEN%^Project Leader%^RESET%^";
        else if( liaisonp(name) )
            ret += "a %^YELLOW%^Liaison%^RESET%^";
        else if( DOMAIN_H->query_member("sage", name ) )
            ret += "a %^CYAN%^Sage%^RESET%^";
        else if( DOMAIN_H->query_member("learning", name ) )
            ret += "an %^CYAN%^Apprentice%^RESET%^";
        else
            ret += "a %^CYAN%^Creator%^RESET%^";
        ret += ".\n";

        bing = DOMAIN_H->query_domains();
        lords = ({ });
        seniors = ({ });

        foreach( tmp in bing ) {
            if( DOMAIN_H->query_leader( tmp, name ) )
                lords += ({ CAP(tmp) });
            else if( DOMAIN_H->query_senior( tmp, name ) )
                seniors += ({ CAP(tmp) });
            if( !DOMAIN_H->query_member( tmp, name ) )
                bing -= ({ tmp });
        }

        bing = map( bing, (: CAP($1) :) );

        if( sizeof(lords) )
            ret += "Lord of the "+query_multiple_short(lords)+" domain"+
                ( sizeof(lords) > 1 ? "s" : "")+".\n";

        if( sizeof(seniors) )
            ret += "Senior member of the "+
                query_multiple_short(seniors)+" domain"+
                ( sizeof(seniors) > 1 ? "s" : "")+".\n";

        bing -= lords + seniors;

        if( !sizeof(bing) && !sizeof(lords) && !sizeof(seniors) )
            ret += "Not a member of any domain.\n";
        else if( sizeof(bing) )
            ret += "Member of the "+query_multiple_short(bing)+" domain"+
                ( sizeof(bing) > 1 ? "s" : "")+".\n";

//        bing = PROJECT_H->query_projects();
//        leaders = ({ });

//        foreach( tmp in bing ) {
//            if( PROJECT_H->query_leader( tmp, name ) )
//                leaders += ({ CAP(tmp) });
//            if( !PROJECT_H->query_member( tmp, name ) )
//                bing -= ({ tmp });
//        }

//        bing = map( bing, (: CAP($1) :) );

//        if( sizeof(leaders) )
//            ret += "Leader of the "+
//                query_multiple_short(leaders)+" project"+
//                ( sizeof(leaders) > 1 ? "s" : "")+".\n";

//        bing -= leaders;

//        if( !sizeof(bing) && !sizeof(leaders) )
//            ret += "Not a member of any project.\n";
//        else if( sizeof(bing) )
//            ret += "Member of the "+query_multiple_short(bing)+" project"+
//                ( sizeof(bing) > 1 ? "s" : "")+".\n";
    } else if( playtesterp( name ) ) {
        ret += CAP(name)+" is a "+(
            PLAYTESTERS_H->query_senior_playtester(name) ?
            "%^BOLD%^%^CYAN%^Senior Playtester%^RESET%^" :
            "%^CYAN%^Playtester%^RESET%^")+".\n";
    } else if( ob && ob->query_property("guest") ) {
        ret += CAP(name)+" is a %^MAGENTA%^Guest%^RESET%^.\n";
    }

    ret += "First logged on "+ctime( data->start_time )+".\n";
    ret += time_string( -data->age, 2 )+" old.\n";

    tmp = time_string( time() - data->last, 2 );
    ret += ( ob ? "On since "+ctime(data->last)+" ("+tmp+").\n"+
           ( interactive(ob) ? "Idle for "+( query_idle(ob) ?
           ( query_idle(ob) / 60 )+" minutes and "+
           ( query_idle(ob) % 60 )+" seconds" : "no time at all") :
           "Net dead")+".\n" : "Last logged on "+tmp+" ago.\n");

    if( lordp(TP) && data->last_on_from )
        ret += data->last_on_from+"\n";

    if( ( tmp = (string)MAIL_H->finger_mail(name) ) != "No mail.\n" )
        ret += "Mail: ";
    ret += tmp;

    if( data->project ) {
        tmp = "Project:\n"+data->project+"\n";
        for( i = lines = 0; i < sizeof( tmp ) && lines < 14; i++ )
            if( tmp[i] == '\n')
                lines++;
        ret += tmp[0..i-1];
    } else {
        ret += "No project.\n";
    }

    if( data->plan ) {
        tmp = "Plan:\n"+data->plan+"\n";
        for( i = lines = 0; i < sizeof( tmp ) && lines < 14; i++ )
            if( tmp[i] == '\n')
                lines++;
        ret += tmp[0..i-1];
    } else {
        ret += "No plan.\n";
    }

    return replace( ret, "@@", "@ @ " );

} /* finger_info() */
