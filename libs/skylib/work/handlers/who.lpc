/*
 * Who handler
 * @author Shaydz
 *
 */

#include <clubs.h>
#include <player.h>

/**
 * This is used by the other who commands to do the object mapping
 * to figure out who to include in the list.
 * @param tarr the array to get the filtered list from
 * @param name the name of the guilds to filter on
 * @param no_cres do not include any creators
 * @return the array of filtered objects
 */
object *filter_users( object *tarr, string name, int no_cres ) {
    string *guilds, guild, *domains, *projects, *friends;
    object *arr;

    name = lower_case(name);
    name = replace( name, ({
               "players",     "player",
               "creators",    "creator",
               "killers",     "killer",
               "helpers",     "helper",
               "playtesters", "playtester",
               "families",    "family",
               "friends",     "friend",
           }) );

    guilds = explode( replace( name, " and ", ","), "," ) - ({ "", 0 });
    guilds = uniq_array( guilds );
    domains = DOMAIN_H->query_domains();
    arr = ({ });

    foreach( guild in guilds ) {
        guild = replace( guild, " ", "", "\t", "");
        switch( guild ) {
        case "player" :
          arr += filter( tarr, (: !creatorp($1) :) );
        break;
        case "creator" :
          arr += filter( tarr, (: creatorp($1) && $1->query_visible(TP) :) );
        break;
        case "helper" :
          arr += filter( tarr, (: !creatorp($1) &&
                 $1->query_property("newbie helper") :) );
        break;
        case "killer" :
          arr += filter( tarr, (: $1->query_property(PKER) &&
                 ( !$(no_cres) || !creatorp($1) ) :) );
        break;
        case "family" :
          arr += filter( tarr, (: $1->query_family_name() :) );
        break;
        case "friend" :
          if( !sizeof( friends = TP->query_property("friends") ) )
              break;
          arr += filter( tarr, (: member_array(
                 $1->query_name(), $(friends) ) != -1 :) );
        break;
        case "playtester" :
          arr += filter( tarr, (: !creatorp($1) && playtesterp($1) :) );
        break;
        default :
          if( member_array( guild, domains ) != -1 )
              arr += filter( tarr, (: creatorp($1)  &&
                  DOMAIN_H->query_member( $(guild), $1->query_name() ) &&
                  $1->query_visible(TP) :) );
          else if( member_array( guild, projects ) != -1 )
              arr += filter( tarr, (: creatorp($1)  &&
                  PROJECT_H->query_member( $(guild), $1->query_name() ) &&
                  $1->query_visible(TP) :) );
          else if( CLUB_HANDLER->is_family(guild) )
              arr += filter( tarr, (:
                  CLUB_HANDLER->is_member_of( $(guild), $1 ) :) );
        }
    }

    return uniq_array( arr );

} /* filter_users() */

/**
 * This method returns the line used for each player in the who
 * command.
 * @return the who line
 * @param ob the player to show
 * @param cre are we a cre
 * @param width the width of the line
 */
string who_line( object ob, int cre, int width ) {
    string s, tmp, title;

    if( tmp = ob->query_player_title() )
        tmp += " ";
    else
        tmp = "";

    s = tmp + ob->query_cap_name();

    if( !s )
        return 0;

    if( tmp = ob->query_family_name() )
        s += " " + tmp;

    if( ob->query_property("guest") ) {
        s += " the Visitor";
    } else if( !creatorp(ob) ) {
        if( tmp = TITLE_H->query_title(ob) )
            s += " " + tmp;
        else
            s += " the Searcher";
    }

    if( !ob->query_property("afk_string") ) {
        if( !creatorp(ob) ) {
            if( tmp = (string)ob->query_property("player_title") )
                s += ", " + tmp;
            tmp = (string)ob->query_title();
            if( tmp && tmp != "")
                title = ", " + tmp;
        } else {
            tmp = (string)ob->query_creator_title();
            if( tmp && tmp != "")
                title = ", " + tmp;
        }
    }

    if( adminp(ob) )
        s += " (%^BLUE%^Admin%^RESET%^)";
    else if( lordp(ob) )
        s += " (%^GREEN%^Lord%^RESET%^)";
    else if( seniorp(ob) )
        s += " (%^RED%^Senior Creator%^RESET%^)";
    else if( liaisonp(ob) )
        s += " (%^YELLOW%^Liaison%^RESET%^)";
    else if( creatorp(ob) ) {
        if( DOMAIN_H->query_member("sage", ob->query_name() ) )
            s += " (%^CYAN%^Sage%^RESET%^)";
        else if( DOMAIN_H->query_member("learning", ob->query_name() ) )
            s += " (%^CYAN%^Apprentice%^RESET%^)";
        else
            s += " (%^CYAN%^Creator%^RESET%^)";
    } else if( !creatorp(ob) && playtesterp( ob->query_name() ) ) {
        if( PLAYTESTERS_H->query_senior_playtester( ob->query_name() ) )
            s += " (%^BOLD%^%^CYAN%^Senior Playtester%^RESET%^)";
        else
            s += " (%^CYAN%^Playtester%^RESET%^)";
    }

    switch( ob->query_invis() ) {
    case 0 :
        break;
    case 1:
        s += " (Invisible)";
        break;
    case 2:
        s += " (Lord Invisible)";
        break;
    default :
        s += " (Admin Invisible)";
    }

    if( cre && ( tmp = (string)ob->query_in_editor() ) )
        s += " (editing: " + tmp + ")";

    if( ob->query_property("afk") )
        if( tmp = ob->query_property("afk_string") )
            s += " %^ORANGE%^(AFK)%^RESET%^ Reason: "+tmp;
        else
            s += " %^ORANGE%^(AFK)%^RESET%^";

    // Stick the creator title here.
    if( title )
        s += title;

    if( interactive(ob) && query_idle(ob) > 120 )
        s += " (Idle: " + ( query_idle(ob) / 60 ) + ")";

    return s + "%^RESET%^";

} /* who_line() */

/** @ignore yes */
object *sort_creators( object *arr ) {
    object ob;
    object *admin, *lord, *senior, *apprentice, *creator, *sage;

    admin = lord = senior = creator = sage = apprentice = ({ });

    foreach( ob in arr ) {
        if( adminp(ob) ) {
            admin += ({ ob });
            continue;
        }
        if( lordp(ob) ) {
            lord += ({ ob });
            continue;
        }
        if( seniorp(ob) ) {
            senior += ({ ob });
            continue;
        }
        if( DOMAIN_H->query_member("sage", ob->query_name() ) ) {
            sage += ({ ob });
            continue;
        }
        if( DOMAIN_H->query_member("learning", ob->query_name() ) ) {
            apprentice += ({ ob });
            continue;
        }
        if( creatorp(ob) ) {
            creator += ({ ob });
            continue;
        }
    }

    return admin + lord + senior + creator + sage + apprentice;

} /* sort_creators() */

/**
 * This method returns the string used in the who command.
 * @return the line for the who line
 */
string who_string( int width, int cre, int verbose, string name ) {
    int num, i;
    string tmp, tmp2, prt;
    object *arr, *players, *creators, *pts, creator;

    arr = filter( users(), (: inherits("/std/container", $1 ) :) );

    if( name && sizeof(arr) )
        arr = filter_users( arr, name, 1 );

    if( !sizeof(arr) ) {
        if( name )
            return "There are no members of " + name + " online.\n";
        return "There is no one on "+mud_name()+"?\n";
    }

    prt = sprintf("%|*'-'s\n", width-1,
      "==========]  "+mud_name()+"  [===========");
    prt += sprintf( "%|*s\n", width-1, mudtime( time() ) );

    arr = sort_array( arr, (: strcmp( $1->query_name(), $2->query_name() ) :) );

    tmp2 = "";

    if( !name && !verbose ) {
        prt += sprintf("%|*'-'s\n", ( width + 25 ),
          "===]%^WHITE%^%^BOLD%^ Players%^RESET%^ [===");
        arr = filter( arr, (: $1->query_cap_name() :) );
        foreach( object person in arr ) {
            tmp = person->query_cap_name();
            if( adminp(person) ) {
                tmp2 += sprintf("%-30s ", tmp + " (%^BLUE%^Admin%^RESET%^)");
            } else if( liaisonp( person->query_name() ) ) {
                tmp2 += sprintf("%-33s ", tmp + " (%^YELLOW%^"+
                  ( seniorp(person) ? "S" : "" )+"l%^RESET%^)");
            } else if( creatorp(person) ) {
                if( lordp(person) ) {
                    tmp2 += sprintf("%-30s ", tmp + " (%^GREEN%^L%^RESET%^)");
                } else if( seniorp(person) ) {
                    tmp2 += sprintf("%-30s ", tmp + " (%^RED%^S%^RESET%^)");
                } else  {
                    if( DOMAIN_H->query_member("learning",
                        person->query_name() ) ) {
                        tmp2 += sprintf("%-30s ", tmp + " (%^CYAN%^A%^RESET%^)");
                    } else {
                        tmp2 += sprintf("%-30s ", tmp + " (%^CYAN%^C%^RESET%^)");
                    }
                }
            } else {
                tmp2 += sprintf("%-14s ", tmp );
            }

            if( ( i + 1 ) % ( width / 15 ) == 0  && tmp2 != "") {
                prt += TP->fix_string(" " + tmp2 + "\n", width, 10 );
                tmp2 = "";
            }
        }
        prt += TP->fix_string(" " + tmp2 + "\n", width, 10 );
    } else {
        creators = filter( arr, (: creatorp($1) :) );
        players = arr - creators;
        pts = filter( players, (: playtesterp($1) :) );
        players -= pts;
        creators = sort_creators( creators );
        if( sizeof(creators) ) {
            prt += sprintf("%|*'-'s\n", ( width + 25 ),
              "===]%^WHITE%^%^BOLD%^ Creators%^RESET%^ [===");
            foreach( creator in creators ) {
                if( tmp = who_line( creator, cre, width ) ) {
                    prt += TP->fix_string( tmp + "\n", width, 10 );
                    num++;
                }
            }
        }

        if( sizeof(pts) ) {
            prt += sprintf("%*'-'|s\n", ( width + 25 ),
              "===]%^WHITE%^%^BOLD%^ Playtesters%^RESET%^ [===");
            foreach( creator in pts ) {
                if( tmp = who_line( creator, cre, width ) ) {
                    prt += TP->fix_string( tmp + "\n", width, 10 );
                    num++;
                }
            }
        }

        if( sizeof(players) ) {
            prt += sprintf("%*'-'|s\n", ( width + 25 ),
              "===]%^WHITE%^%^BOLD%^ Players%^RESET%^ [===");
            foreach( creator in players ) {
                if( tmp = who_line( creator, cre, width ) ) {
                    prt += TP->fix_string( tmp + "\n", width, 10 );
                    num++;
                }
            }
        }
    }

    if( name )  {
        tmp = "> There "+( num > 1 ? "are " : "is ")+
        query_num( num, 150 ) + ( num > 1 ? " members of" :
          " member of");
        name = replace( name, " and ", "," );
        if( strsrch( name, ",") != -1 )
            name = query_multiple_short( uniq_array( map(
                  explode( name, "," ) - ({ "", 0 }), (:
                    replace( $1, " ", "", "\t", "") :) ) ) );
        tmp += " "+name+" on "+mud_name()+". <";
    } else if( num < 2 ) {
        tmp = "> You are all alone on "+mud_name()+". <";
    } else  {
        tmp = "> There are " + query_num( num, 150 ) +
        " mudders on "+mud_name()+". <";
    }

    prt += sprintf("%*'-'|s\n", width-1, tmp );
    return prt;

} /* who_string() */
