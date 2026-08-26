/**
 * The soul handler for Discworld.  Handles the soul definitions and
 * the mangling needed to print the output for the players.
 *
 * @author Pinkfish
 */

#include <player.h>
#include <soul.h>
#include <user_parser.h>

#define SAVE_FILE "/save/soul"

#define SOUL_DATA_DIR "/save/new_soul/data/"

#define POS_SELF   0
#define POS_TARGET 1
#define POS_REST   2

#define PCACHE_MAX_SIZE 30
#define SCACHE_MAX_SIZE 100
#define CLEAN_UP_DELAY 300

/*
 * The soul driver itself...
 */
mixed soul_commands;
mapping soul_command_names;

nosave mapping pattern_cache;
nosave mapping soul_cache;
nosave string *pcache_order, *scache_order;
nosave int scache_hits, scache_reads, pcache_hits, pcache_reads, cache_callout;

void load_it();
void save_it();
void print_messages(string verb, mixed obs, string arg, string self,
  string rest, string target, string force, mapping position);
protected void save_soul_command(string name, mixed data);

void create() {
    soul_commands = 0;
    soul_command_names = ([ ]);
    pattern_cache = ([ "" : NO_ARGUMENT ]);
    pcache_order = ({ });
    scache_order = ({ });
    soul_cache = ([ ]);
    seteuid("Room");
    load_it();
} /* create() */

void clean_cache() {
    int i;

    for( i = 0; i < ( sizeof(pcache_order) - PCACHE_MAX_SIZE ); i++ )
        map_delete( pattern_cache, pcache_order[i] );

    pcache_order = pcache_order[i..];


    for( i = 0; i < ( sizeof(scache_order) - SCACHE_MAX_SIZE ); i++ )
        map_delete( soul_cache, scache_order[i] );

    scache_order = scache_order[i..];
    cache_callout = 0;

} /* clean_cache() */

/**
 * Adds in a soul command.  Only allows additions from
 * the soul compiler.
 *
 * @see /handlers/soul_compiler.c
 * @param name the name of the soul command
 * @param data the data associated with the soul command
 */
void add_soul_command(string name, mixed data) {
    if( file_name(PO) != SOUL_COMPILER )
        return;
    save_soul_command(name, data);
    map_delete(soul_cache, name);
    save_it();
} /* add_soul_command() */

/**
 * Deletes the soul command.  This is used to remove soul commands
 * that are no longer used.
 *
 * @param name the soul command name to delete
 */
void delete_soul_command( string name ) {
    map_delete( soul_cache, name );
    map_delete( soul_command_names, name );
    unguarded( (: rm, SOUL_DATA_DIR + name +".os" :) );
    save_it();
} /* delete_soul_command() */

/**
 * The name of all the soul commands.
 *
 * @return an array containing the names of all the soul commands
 */
string *query_soul_commands() {
    return keys(soul_command_names);
} /* query_soul_commands() */

/**
 * Used internally to get the soul command data.
 *
 * @param str the soul command to get data for
 * @return the soul command data
 * @see query_soul_command_stuff()
 */
protected mixed query_soul_command_data(string str) {
    scache_reads++;
    /* This function will load in the rubbish from the disk. */
    if( !soul_cache[str] && soul_command_names[str] ) {
        string tmp;

        tmp = unguarded( (: read_file, SOUL_DATA_DIR+str+".os" :) );
        soul_cache[str] = restore_variable(tmp);

        if( !cache_callout && ( sizeof(scache_order) > SCACHE_MAX_SIZE ) )
            cache_callout = call_out("clean_cache", CLEAN_UP_DELAY);
    } else {
        scache_order -= ({ str });
        scache_hits++;
    }

    scache_order += ({ str });
    return soul_cache[str];

} /* query_soul_command_data() */

/**
 * Returns the data associated with soul command.
 * Probably not very useful, but useful for debugging.
 *
 * @param str the soul command to get the data for
 * @return the data associated with the soul command
 */
mixed query_soul_command_stuff(string str) {
    return query_soul_command_data(str) + ({ });
} /* query_soul_command_stuff() */

/** @ignore yes */
protected void save_soul_command(string name, mixed data) {
    string str;

    str = save_variable(data);
    unguarded( (: rm, SOUL_DATA_DIR+name+".os" :) );
    unguarded( (: write_file, SOUL_DATA_DIR+name+".os", str :) );
    soul_command_names[name] = 1;
} /* save_soul_command() */

/**
 * Saves the current state of the soul object.
 */
void save_it() {
    unguarded((: save_object, SAVE_FILE :));
} /* save_it() */

/**
 * Loads the previous state of the soul object off the disc.
 */
void load_it() {
    string *names;
    int i;

    unguarded( (: restore_object, SAVE_FILE :) );
    if( mappingp(soul_commands) ) {
        /* Ok, we convert it to the new format... */
        soul_command_names = ([ ]);
        names = keys(soul_commands);
        for( i = 0; i < sizeof(names); i++ ) {
            reset_eval_cost();
            save_soul_command(names[i], soul_commands[names[i]]);
        }
        soul_commands = 0;
        save_it();
    }
} /* load_it() */

private mixed create_pattern_cache(string pattern) {
    mixed bing, ret;
    string s1, s2;

    bing = explode("#"+pattern, "<indirect:");
    if( sizeof(bing) == 1 )
        if( sscanf( bing[0], "%s<word>%s", s1, s2 ) ||
            sscanf( bing[0], "%s<string>%s", s1, s2 ) )
            ret = ONLY_ARGUMENT;
        else
            ret = NO_ARGUMENT;
    else if( sscanf( bing[0], "%s<word>%s", s1, s2 ) ||
        sscanf( bing[0], "%s<string>%s", s1, s2 ) )
        ret = ARGUMENT_FIRST;
    else if( sscanf( bing[1], "%s<word>%s", s1, s2 ) ||
        sscanf( bing[1], "%s<string>%s", s1, s2 ) )
        ret = ARGUMENT_SECOND;
    else
        ret = ONLY_TARGET;
    return ret;
} /* create_pattern_cache() */

/**
 * This returns the arrays that are used by the pattern
 * matcher in the player object. Called from inside add_command interface.
 *
 * @param name the souul command name to find
 * @return 0 if no command found, otherwise an array of patterns
 * @see /global/new_parse->add_command()
 */
mixed query_soul_command(string name) {
    mixed data, ret;
    string pat;

    if( !soul_command_names[name] )
        return 0;

    if( !data = query_soul_command_data(name) )
        return 0;

    ret = ({ ({ ({ }), "", 0, TO, 0 }) });
    foreach( pat in data[PATTERNS] ) {
        pcache_reads++;
        if( !pattern_cache[pat] ) {
            pattern_cache[pat] = create_pattern_cache(pat);
            if(!cache_callout && sizeof(pcache_order) > PCACHE_MAX_SIZE)
                cache_callout = call_out("clean_cache", CLEAN_UP_DELAY);
        } else {
            pcache_hits++;
            pcache_order -= ({ pat });
        }
        pcache_order += ({ pat });

        ret += ({ ({ ((mixed)PATTERN_OB->query_pattern(pat))[1],
               pat, 0, TO, 0 }) });
    }
    return ret;
} /* query_soul_command() */

/**
 * The main soul handling bit.  This is called by the add_command code
 * when a soul command is matched.
 *
 * @param verb the verb matched
 * @param obs the objects to do the soul command on
 * @param in_dir_match the name which was matched for the peoples names
 * @param args the values of the string and stuff
 * @param pattern the pattern which was matched.
 * @return 1 if the command succeeded, 0 if it failed
 */
int command_control( string verb, object *obs, string,
                     string in_dir_match, string *args, string pattern ) {
    int i, j;
    string arg;
    mixed stuff, data;
    object *wom, *rem;

    if( !soul_command_names[verb] )
        return 0;
    if( pattern != "" ) {
        stuff = PATTERN_OB->query_pattern(pattern);
        for( i = 1; i < sizeof(stuff); i++ ) {
            switch (stuff[i]) {
            case INDIRECT_OBJECT :
                // Ok, in here we check for remote and multiple
                // soul earmuffs...
                i += 2;
                wom = obs;
#ifdef 0
                if( PO->query_invis() ) {
                    PO->add_failed_mess( TO, "You cannot do a directed soul "
                        "whilst invisible.\n", ({ }) );
                    return 0;
                }
#endif
                if( PO->query_property("no soul") ) {
                    PO->add_failed_mess( TO, "You cannot use directed "
                        "souls.\n", ({ }) );
                    return 0;
                }

                // check for ignoring people
                if( ( sizeof(obs) == 1 ) && !creatorp(PO) &&
                    obs[0]->query_property("ignoring") &&
                    member_array( (string)PO->query_name(),
                    (string *)obs[0]->query_property("ignoring") ) != -1 ) {
                    return 0;
                }

                // prevent multiple souls to people with multiple-soul
                // earmuffed or people we can't see
                if( sizeof(obs) > 1 ) {
                    obs = filter( obs, (: !$1->check_earmuffs("multiple-soul") &&
                          $1->query_visible(previous_object(1)) :) );
                    if( !sizeof(obs) ) {
                        PO->add_failed_mess( TO, "Everyone seems to have "
                            "their multiple souls earmuffed.  I'm depressed, "
                            "are you depressed?\n", ({ }) );
                        return 0;
                    }
                }

                // prevent remote souls to npcs or to people you can't see
                rem = filter( obs, (: ( !interactive($1) && ENV(previous_object(1)) != ENV($1) ) ||
                              !$1->query_visible(previous_object(1)) :) );
                obs = obs - rem;

                obs -= PO->query_ignoring(obs);

                if( !sizeof(obs) )
                    return 0;

                if( PO->check_earmuffs("remote-soul") ) {
                    rem = filter( obs, (: ENV(PO) != ENV($1) :) );
                    if( sizeof(rem) == sizeof(obs) ) {
                        PO->add_failed_mess(TO, "You cannot do a remote soul "
                            "when you have remote souls earmuffed.\n", ({ }) );
                        return 0;
                    }
                    obs = obs - rem;
                } else {
                    obs = filter( obs, (: !$1->check_earmuffs("remote-soul") ||
                                  ENV(PO) == ENV($1) :) );
                    if( !sizeof(obs) ) {
                        PO->add_failed_mess( TO, "Remote soul earmuffs "
                            "enabled for $I.\n", wom );
                        return 0;
                    }
                }
                j++;
            break;
            case STRING :
            case SINGLE_WORD :
            case SHORT_STRING :
                arg = args[j++];
            break;
            case NUMBER :
                j++;
            break;
            case FRACTION :
                j += 2;
            break;
            case OPTIONAL :
            case OPTIONAL_SPACES :
                i++;
            break;
            case WORD_LIST :
            case WORD_LIST_SPACES :
                i++;
                if( pointerp(stuff[i]) && sizeof(stuff[i] ) > 1 )
                    j++;
            break;
            }
        }
    }
    /*
     * Ok.  We have this soul command.  Lets find out what sort of
     * pattern we have
     */
    if( !pattern_cache[pattern] )
        return 0;
    if( !creatorp(PO) )
        if( (int)PO->adjust_sp( -SOUL_COST * ( 1 + sizeof( obs ) ) ) < 0 ) {
            PO->add_failed_mess( TO, NO_POWER, ({ }) );
            return 0;
        }

    data = query_soul_command_data(verb);
    switch( pattern_cache[pattern] ) {
    case NO_ARGUMENT :
        /*
         * This case.  Means we try the no_argument thing first.  Otherwise
         * we pick the first argument one and use that.
         */
        if( data[SINGLE] )
            if( data[SINGLE][NO_ARGUMENTS] ) {
                if( sizeof(data[SINGLE][NO_ARGUMENTS]) > POSITION_SINGLE ) {
                    print_messages( verb, 0, "", data[SINGLE][NO_ARGUMENTS][SELF],
                        data[SINGLE][NO_ARGUMENTS][REST], 0, 0,
                        data[SINGLE][NO_ARGUMENTS][POSITION_SINGLE] );
                } else {
                    print_messages( verb, 0, "", data[SINGLE][NO_ARGUMENTS][SELF],
                        data[SINGLE][NO_ARGUMENTS][REST], 0, 0, 0 );
                }
                return 1;
            } else {
                if( !data[SINGLE][ARGUMENTS] )
                    return 0;
                arg =  data[SINGLE][ARGUMENTS][ARGS][0];
            } else
                return 0;
    case ONLY_ARGUMENT :
        if( arg == "?" ) {
            /* Find a random argument... */
            j = 0;
            for( i = 0; i < sizeof(data[SINGLE][ARGUMENTS]); i+= SMALL_ARG_SIZE )
                j += sizeof(data[SINGLE][ARGUMENTS][i+ARGS]);
            j = random(j);
            for( i = 0; i < sizeof(data[SINGLE][ARGUMENTS]); i += SMALL_ARG_SIZE )
                if( j < sizeof(data[SINGLE][ARGUMENTS][i+ARGS]) ) {
                    if( data[SINGLE][ARGUMENTS][i+ARGS][j] == "#" ) {
                        if( j > 0 )
                            j--;
                        else {
                            j++;
                            if( j >= sizeof (data[SINGLE][ARGUMENTS][i + ARGS]) ) {
                                j -= sizeof(data[SINGLE][ARGUMENTS][i + ARGS]);
                                continue;
                            }
                        }
                    }
                    print_messages( verb, 0,
                        data[SINGLE][ARGUMENTS][i+ARGS][j],
                        data[SINGLE][ARGUMENTS][i+SELF],
                        data[SINGLE][ARGUMENTS][i+REST], 0, 0,
                        data[SINGLE][ARGUMENTS][i+POSITION_SINGLE] );
                    return 1;
                } else {
                    j -= sizeof(data[SINGLE][ARGUMENTS][i+ARGS]);
                }
        }
        /* Ok, now to find the argument... */
        for( i = 0; i < sizeof(data[SINGLE][ARGUMENTS]); i += SMALL_ARG_SIZE ) {
            if( ( j = member_array( arg, data[SINGLE][ARGUMENTS][i+ARGS],
                0, 1 ) ) != -1 ) {
                /* Found... */
                print_messages( verb, 0,
                    data[SINGLE][ARGUMENTS][i+ARGS][j],
                    data[SINGLE][ARGUMENTS][i+SELF],
                    data[SINGLE][ARGUMENTS][i+REST], 0, 0,
                    data[SINGLE][ARGUMENTS][i+POSITION_SINGLE] );
                return 1;
            }
        }
        /* No argument.  So we check for a wildcard */
        for( i = 0; i < sizeof(data[SINGLE][ARGUMENTS]); i += SMALL_ARG_SIZE )
          if(living(PO)){
            if(PO->query_skill("general.language.common.spoken")>80){
              if( ( j = member_array( "#", data[SINGLE][ARGUMENTS][i+ARGS],
                  0, 1 ) ) != -1 ) {
                /* Found... */
                  print_messages( verb, 0, arg,
                      data[SINGLE][ARGUMENTS][i+SELF],
                      data[SINGLE][ARGUMENTS][i+REST], 0, 0,
                      data[SINGLE][ARGUMENTS][i+POSITION_SINGLE] );
                  return 1;
              }
            }
          }

            /* No argument found... */
        PO->add_failed_mess( TO, arg+" is not a valid argument to the soul "
            "command \""+verb+"\".\n", ({ }) );
        return 0;
    case ARGUMENT_FIRST :
    case ARGUMENT_SECOND :
    break;
    case ONLY_TARGET :
        if( data[TARGET][NO_ARGUMENTS] ) {
            obs->event_soul_command( TO, verb, PO, in_dir_match, 0 );
            print_messages( verb, obs, "",
                data[TARGET][NO_ARGUMENTS][SELF],
                data[TARGET][NO_ARGUMENTS][REST],
                data[TARGET][NO_ARGUMENTS][TARGET],
                data[TARGET][NO_ARGUMENTS][FORCE],
                data[TARGET][NO_ARGUMENTS][POSITION] );
            return 1;
        }
        /* Ok.  Now, we return 0 if there is no argument one */
        if( !data[TARGET][ARGUMENTS] )
            return 0;
        arg = data[TARGET][ARGUMENTS][ARGS][0];
        break;
    }
    if( arg == "?" ) {
        /* Find a random argument... */
        j = 0;
        for( i = 0; i < sizeof(data[TARGET][ARGUMENTS]); i += ARG_SIZE )
            j += sizeof(data[TARGET][ARGUMENTS][i+ARGS]);
        j = random(j);
        for( i = 0; i < sizeof(data[TARGET][ARGUMENTS]); i += ARG_SIZE )
            if( j < sizeof(data[TARGET][ARGUMENTS][i+ARGS]) ) {
                if( data[TARGET][ARGUMENTS][i+ARGS][j] == "#" ) {
                    if( j > 0 )
                        j--;
                    else {
                        j++;
                        if( j >= sizeof (data[TARGET][ARGUMENTS][i + ARGS]) ) {
                            j -= sizeof(data[TARGET][ARGUMENTS][i + ARGS]);
                            continue;
                        }
                    }
                }
                obs->event_soul_command( TO, verb, PO, in_dir_match, arg );
                print_messages( verb, obs, data[TARGET][ARGUMENTS][i+ARGS][j],
                    data[TARGET][ARGUMENTS][i+SELF],
                    data[TARGET][ARGUMENTS][i+REST],
                    data[TARGET][ARGUMENTS][i+TARGET],
                    data[TARGET][ARGUMENTS][i+FORCE],
                    data[TARGET][ARGUMENTS][i+POSITION]);
                return 1;
            } else
                j -= sizeof(data[TARGET][ARGUMENTS][i+ARGS]);
    }
    for( i = 0; i < sizeof(data[TARGET][ARGUMENTS]); i += ARG_SIZE ) {
        if( ( j = member_array( arg, data[TARGET][ARGUMENTS][i+ARGS],
            0, 1 ) ) != -1 ) {
            /* Found... */
            obs->event_soul_command( TO, verb, PO, in_dir_match, arg );
            print_messages( verb, obs,
                data[TARGET][ARGUMENTS][i+ARGS][j],
                data[TARGET][ARGUMENTS][i+SELF],
                data[TARGET][ARGUMENTS][i+REST],
                data[TARGET][ARGUMENTS][i+TARGET],
                data[TARGET][ARGUMENTS][i+FORCE],
                data[TARGET][ARGUMENTS][i+POSITION] );
            return 1;
        }
    }
    /* No argument found.  Check for wildcard */
    if(living(PO)){
      if(PO->query_skill("general.language.common.spoken")>80){
        for( i = 0; i < sizeof(data[TARGET][ARGUMENTS]); i += ARG_SIZE )
            if( ( j = member_array( "#", data[TARGET][ARGUMENTS][i+ARGS],
                0, 1 ) ) != -1 ) {
              /* Found... */
                obs->event_soul_command( TO, verb, PO, in_dir_match, arg );
                print_messages( verb, obs, arg,
                    data[TARGET][ARGUMENTS][i+SELF],
                    data[TARGET][ARGUMENTS][i+REST],
                    data[TARGET][ARGUMENTS][i+TARGET],
                    data[TARGET][ARGUMENTS][i+FORCE],
                    data[TARGET][ARGUMENTS][i+POSITION]);
                return 1;
            }
          /* No argument found... */
      }
    }

    return 0;

} /* command_control() */

private string create_message( mixed targets, string args, string pattern,
                               int type, string verb, string position,
                               string actor_position, object me ) {
    string *bits, *rabbit;
    int i;


    if( stringp( verb ) && type && ( sizeof( explode( pattern, "$V$" ) ) < 2 ) ) {
        if( pointerp( targets ) && sizeof(targets) > 0 ) {
            pattern = replace_string( pattern, pluralize( verb ),
                      "$V$1="+pluralize( verb )+","+verb+"$V$" );
        } else {
            pattern = replace_string( pattern, pluralize( verb ),
                      "$V$0="+pluralize( verb )+","+verb+"$V$" );
        }
    }

    pattern = replace_string( pattern, "$V$", "VERBFROG" );
    bits = explode( "%" + replace_string( pattern, "$arg$", args ), "$" );

    if( !me )
        me = PO;

    for( i = 1; i < sizeof(bits); i += 2 ) {
        switch( bits[i] ) {
        case "hcname" :
            if( stringp( targets ) ) {
                bits[ i ] = targets;
                break;
            }
            if( objectp( targets ) ) {
                if( targets == me )
                    if( type )
                        bits[ i ] = targets->query_objective()+"self";
                    else
                        bits[ i ] = "yourself";
                else
                    bits[ i ] = targets->one_short();
                break;
            }
            bits[ i ] = targets[ 0 ];
        break;
        case "mhcname" :
            /* Stoopid stuff could be revised at some point, if done nicely. */
            if( stringp( targets ) ) {
                /* This will look really stoopid. */
                bits[ i ] = targets +"'s";
                break;
            }

            if( objectp( targets ) ) {
                if( targets == me )
                    if( type )
                        bits[ i ] = targets->query_possessive();
                    else
                        bits[ i ] = "your";
                else
                    bits[ i ] = targets->one_short()+"'s";
                break;
            }
            /* This will look really stoopid. */
            bits[ i ] = targets[ 0 ] +"'s";
        break;
        case "hposs" :
            if( objectp( targets ) ) {
                // Added this - Sandoz.
                if( targets == me )
                    if( type )
                        bits[ i ] = targets->query_possessive();
                    else
                        bits[ i ] = "your";
                else
                    bits[ i ] = targets->query_possessive();
            } else {
                // Changed from simply "their" - Sandoz.
                if( sizeof(targets) > 1 )
                    bits[ i ] = "their";
                else if( type )
                    bits[ i ] = me->query_possessive();
                else
                    bits[ i ] = "your";
            }
        break;
        case "hpronoun" :
            if( objectp( targets ) ) {
                // Added this - Sandoz.
                if( targets == me )
                    if( type )
                        bits[ i ] = targets->query_pronoun();
                    else
                        bits[ i ] = "you";
                else
                    bits[ i ] = targets->query_pronoun();
            } else {
                // Changed from simply "they" - Sandoz.
//                if( sizeof(targets) > 1 )
                    bits[ i ] = "they";
//                else if( type )
//                    bits[ i ] = me->query_pronoun();
//                else
//                    bits[ i ] = "you";
            }
        break;
        case "hobj" :
            if( objectp( targets ) ) {
                // Added this - Sandoz.
                if( targets == me ) {
                    if( type )
                        bits[ i ] = targets->query_objective();
                    else
                        bits[ i ] = "you";
                } else {
                    bits[ i ] = targets->query_objective();
                }
            } else {
                // Changed from simply "them" - Sandoz.
//                if( sizeof(targets) > 1 )
                    bits[ i ] = "them";
//                else if( type )
//                    bits[ i ] = me->query_objective();
//                else
//                    bits[ i ] = "you";
            }
        break;
        case "mcname" :
            if( me != PO ) // Must be from the help.
                bits[ i ] = (string)me->short();
            else { // Let's see how this goes.
                if( ( objectp(targets) && ENV(me) == ENV(targets) ) ||
                    !targets )
                    bits[ i ] = (string)me->one_short();
                else
                    bits[ i ] = (string)me->one_short(1);
            }
        break;
        case "mposs" :
            if( type )
                bits[ i ] = (string)me->query_possessive();
            else
                bits[ i ] = "your";
            break;
        case "mpronoun" :
            bits[ i ] = (string)me->query_pronoun();
            break;
        case "mobj" :
            bits[ i ] = (string)me->query_objective();
            break;
        case "position" :
            if( position ) {
                rabbit = explode("%" + position, "$");
                rabbit[0] = rabbit[0][1..];
                /* Make sure the size is even... */
                if( ( sizeof(rabbit) % 2 ) == 1 )
                    rabbit += ({""});
                bits = bits[0..i] + rabbit + bits[i+1..];
            }
            bits[ i ] = "";
            break;
        case "aposition" :
            if( actor_position ) {
                rabbit = explode( "%" + actor_position, "$" );
                rabbit[0] = rabbit[0][1..];
                /* Make sure the size is even... */
                if( ( sizeof(rabbit) % 2 ) == 1 )
                    rabbit += ({""});
                bits = bits[0..i] + rabbit + bits[i+1..];
            }
            bits[ i ] = "";
            break;
        }
    }

    pattern = implode( bits, "" )[1..]+"\n";
    pattern = replace_string( pattern, "VERBFROG", "$V$" );
    return pattern;

} /* create_message() */

private string position_command( mixed bing ) {
    if( stringp(bing) )
        return bing;
    if( mapp(bing) )
        return bing["cmd"];
    return 0;
} /* position_command() */

private void do_position_stuff( object ob, mapping position ) {
    string cur_pos, new_pos;

    /* Ok, the position stuff... */
    if( position ) {
        cur_pos = ob->query_position();
        if( position[cur_pos] ) {
            /* Ok, do it... */
            new_pos = position_command(position[cur_pos]);
        } else if( position["default"] ) {
            new_pos = position_command(position["default"]);
        }
        if( new_pos && new_pos != "ignore" &&
            !ob->query_cannot_change_position() &&
            ("/cmds/living/" + new_pos)->query_position_command() ) {
            ("/cmds/living/" + new_pos)->position( ob, position["silent"] );
        }
    }
} /* do_position_stuff() */

private string *position_string( object ob, mapping position, int ) {
    string *str, cur_pos;
    mixed new_pos;

    str = ({ 0, 0, 0 });

    if( position ) {
        cur_pos = ob->query_position();

        if( position[cur_pos] )
            new_pos = position[cur_pos];
        else if( position["default"] )
            new_pos = position["default"];

        if( mapp(new_pos) )
            return ({ new_pos["self"], new_pos["target"], new_pos["rest"] });

        if( new_pos && new_pos != "ignore" &&
            !ob->query_cannot_change_position() &&
            ("/cmds/living/" + new_pos)->query_position_command() ) {
            str = ({ " making $hobj$ " + new_pos + " " +
                  ("/cmds/living/" + new_pos)->query_up_down(),
                  " making you " + new_pos + " " +
                  ("/cmds/living/" + new_pos)->query_up_down(),
                  " making $hobj$ " + new_pos + " " +
                  ("/cmds/living/" + new_pos)->query_up_down()
                  });
        }
    }

    return str;

} /* position_string() */

private string position_of( object ob, mapping position ) {
    string tmp;

    tmp = ob->query_position();

    if( position[tmp] ) {
        if( tmp = position_command(position[tmp]) )
            return tmp;
    }

    if( position["default"] ) {
        if( tmp = position_command(position["default"]) )
            return tmp;
    }

    return "";

} /* position_of() */

private string env_position_of( object ob, mapping position ) {
    return file_name( ob->query_current_room() ) + position_of( ob, position );
} /* env_position_of() */

private void print_messages( string verb, mixed obs, string arg, string self,
                             string rest, string target, string force,
                             mapping position ) {
    int i;
    mixed locs, pos_spread;
    string *pos_stuff, *actor_pos_stuff;
    object *people, person;

    if( !obs || !sizeof(obs) ) {
        PO->remove_hide_invis();
        /* This makes it easy :) */
        pos_stuff = position_string( PO, position, 0 );
        PO->event_soul( PO, create_message( 0, arg, self, 0, 0,
            pos_stuff[ POS_SELF ], 0, 0 ), ({ }), verb, arg, 0, 0 );
        if( arg ) {
            arg = replace( arg, ({"yourself", PO->query_objective()+"self",
                  "your", PO->query_possessive() }));
        }
        if( ENV(PO) ) {
            event( ENV(PO), "soul", create_message( 0, arg, rest, 1, verb,
                   pos_stuff[ POS_REST ], 0, 0 ), ({ PO }), verb, arg, 0, 0 );
        }
        do_position_stuff( PO, position );
        return ;
    }

    if( !target )
        target = rest;

    if( sizeof(obs) == 1 ) {
        /*
         * Not quite so easy.  But still.  It could be worse.
         * It used to be a lot worse...
         */
        pos_stuff = position_string( obs[ 0 ], position, 0 );
        if( position )
            actor_pos_stuff = position_string( PO, position["actor"], 0 );
        else
            actor_pos_stuff = position_string( PO, 0, 0 );
        PO->event_soul( PO, create_message( obs[ 0 ], arg, self, 0, 0,
            pos_stuff[POS_SELF], actor_pos_stuff[POS_SELF], 0 ), ({ }),
            verb, arg, obs[0], 0 );
        if( arg )
            arg = replace( arg, ({"yourself", PO->query_objective()+"self",
                  "your", PO->query_possessive() }) );
        if( stringp(force) ) {
            call_out("do_force", 2, ({ obs[ 0 ], replace( force, "$mcname$",
                  (string)PO->query_name() ) }) );
        }

        if( obs[ 0 ] != PO ) {
            // convert the message.
            obs[ 0 ]->add_property("doing_soul", 1 );
            obs[ 0 ]->event_soul( PO, obs[ 0 ]->convert_message(
                create_message( obs[0], arg, target, 2, verb,
                pos_stuff[POS_TARGET], actor_pos_stuff[POS_TARGET], 0 ) ),
                ({ }), verb, arg, obs[0] );
            obs[ 0 ]->remove_property("doing_soul");
            if( ENV( PO ) != ENV( obs[ 0 ] ) && ENV( obs[ 0 ] ) )
                event( ENV( obs[ 0 ] ), "soul", create_message( obs[ 0 ], arg,
                       rest, 1, verb, pos_stuff[POS_REST],
                       actor_pos_stuff[POS_REST], 0 ), ({ PO, obs[ 0 ] }),
                       verb, arg, 0 );
        }

        if( ENV(PO) )
            event( ENV(PO), "soul", create_message( obs[ 0 ], arg, rest, 1,
                   verb, pos_stuff[POS_REST], actor_pos_stuff[POS_REST], 0 ),
                   ({ PO, obs[0] }), verb, arg, 0 );

        do_position_stuff( obs[0], position );

        if( position && position["actor"] )
            do_position_stuff( PO, position["actor"] );

        return;
    }

    /* Multiple of us... */
    obs -= ({ PO });
    if( stringp(force) )
        force = replace( force, "$mcname$", (string)PO->query_name() );

    /* Get the us based position stuff... */
    if( position )
        actor_pos_stuff = position_string( PO, position["actor"], 0 );
    else
        actor_pos_stuff = position_string( PO, 0, 0 );

    if( strsrch( self, "$position$" ) == -1 || !position ) {
        locs = unique_array( obs, "query_current_room" );
        if( sizeof( locs ) > 2 ) {
            PO->event_soul( PO, create_message( query_multiple_short(
                obs, "the" ), arg, self, 1, 0, 0, actor_pos_stuff[POS_SELF], 0 ),
                ({ }), verb, arg, locs );
            if( ENV( PO ) )
                event( ENV( PO ), "soul", create_message(
                    query_multiple_short( obs, "the" ), arg, rest, 1, verb, 0,
                    actor_pos_stuff[POS_REST], 0 ), ({ PO }) + obs, verb,
                    arg, locs );
        } else {
            PO->event_soul( PO, create_message( ({
                query_multiple_short( obs ) }), arg, self, 1, 0, 0,
                actor_pos_stuff[POS_SELF], 0 ), ({ }), verb, arg, locs );
            if( ENV( PO ) )
                event( ENV( PO ), "soul", create_message( ({
                    query_multiple_short( obs ) }), arg, rest, 1, verb, 0,
                    actor_pos_stuff[POS_REST], 0 ), ({ PO }) + obs,
                    verb, arg, locs );
        }
        if( arg )
            arg = replace(arg, ({ "yourself", PO->query_objective() + "self",
                  "your", PO->query_possessive() }) );
        foreach( people in locs ) {
            if( stringp(force) )
                call_out("do_force", 2, ({ people, force }) );
            if( ENV( PO ) != ENV( people[ 0 ] ) && ENV( people[ 0 ] ) )
                if( sizeof( locs ) > 2 )
                    event( ENV( people[ 0 ] ), "soul",
                        create_message( query_multiple_short( obs, "the" ),
                        arg, rest, 1, verb, 0, actor_pos_stuff[POS_REST], 0 ),
                        ({ PO }) + obs, verb, arg, people );
                else
                    event( ENV( people[ 0 ] ), "soul", create_message( ({
                        query_multiple_short( obs ) }), arg, rest, 1, verb, 0,
                        actor_pos_stuff[POS_REST], 0 ), ({ PO }) + obs,
                        verb, arg, people );
            foreach( person in people ) {
                person->add_property("doing_soul", 1 );
                if( sizeof( locs ) > 2 ) {
                    person->event_soul( PO, person->convert_message(
                    create_message( query_multiple_short( obs - ({ person }) +
                    ({ "you" }), "the" ), arg, rest, 1, verb, 0,
                    actor_pos_stuff[POS_REST], 0 ) ), ({ }), verb, arg, people );
                } else {
                    person->event_soul( PO, person->convert_message(
                    create_message( ({ query_multiple_short( obs ) }), arg,
                    rest, 1, verb, 0, actor_pos_stuff[POS_REST], 0 ) ), ({ }),
                    verb, arg, people );
                }
                person->remove_property("doing_soul");
                do_position_stuff( person, position );
            }
        }
    } else { /* We have position stuff! */
        pos_spread = unique_array( obs, (: position_of( $1, $(position) ) :) );
        for( i = 0; i < sizeof(pos_spread); i++ ) {
            pos_stuff = position_string( pos_spread[i][0], position,
                        sizeof( pos_spread[i] ) > 1 );
            PO->event_soul( PO, create_message( query_multiple_short(
                pos_spread[i], "the" ), arg, self, 1, 0, pos_stuff[ POS_SELF ],
                actor_pos_stuff[ POS_SELF ], 0 ), ({ }), verb, arg, locs );
            if( ENV( PO ) ) {
                event( ENV( PO ), "soul", create_message(
                    query_multiple_short( pos_spread[i], "the" ),
                    arg, rest, 1, verb, pos_stuff[ POS_REST ],
                    actor_pos_stuff[POS_REST], 0 ), ({ PO }) + obs,
                    verb, arg, locs );
            }
            locs = unique_array( pos_spread[i], "query_current_room" );
            foreach( people in locs ) {
                if( stringp(force) )
                    call_out("do_force", 2, ({ people, force }) );
                if( ENV( PO ) != ENV( people[ 0 ] ) && ENV( people[ 0 ] ) ) {
                    event( ENV( people[ 0 ] ), "soul",
                        create_message( query_multiple_short( obs, "the" ),
                        arg, rest, 1, verb, pos_stuff[ POS_REST ],
                        actor_pos_stuff[POS_REST], 0 ), ({ PO }) + obs,
                        verb, arg, people );
                }
                foreach( person in people ) {
                    person->add_property("doing_soul", 1 );
                    person->event_soul( PO, person->convert_message(
                    create_message( query_multiple_short( obs - ({ person })+
                    ({ "you" }), "the" ), arg, rest, 1, verb,
                    pos_stuff[ POS_REST ], actor_pos_stuff[POS_REST], 0 ) ),
                    ({ }), verb, arg, people );
                    person->remove_property("doing_soul");
                    do_position_stuff( person, position );
                }
            }
        }
    }

    if( position && position["actor"] )
        do_position_stuff( PO, position["actor"] );

    return;

} /* print_messages() */

/**
 * @ignore yes
 */
string add_start(string pat, string verb) {
    return verb+" "+pat;
} /* add_start() */

/**
 * The list of soul comands in the look at soul function.
 *
 * @return the list of all the soul commands formated for the screen
 */
string help_list() {
    return "$P$Soul$P$The number of soul commands currently available is "+
           sizeof( soul_command_names )+".\nHere is a nice list of them.\n"
           "Good luck!\n"+sprintf( "%-#*s\n\n", (int)TP->query_cols(),
           implode( sort_array( keys( soul_command_names ), 1 ), "\n" ) );
} /* help_list() */

/**
 * Returns the help string for the soul ocmmand.  Creates a nice helkp
 * message for the passed soul command.
 *
 * @param verb the soul command to get help on
 * @return the soul command help string
 */
string help_string( string verb ) {
    string ret, arg;
    int i;
    mixed target, *data;

    if( !soul_command_names[ verb ] )
        return 0;
    data = query_soul_command_data(verb);
    ret = sprintf("Allowed command patterns:\n%-#*s\n\n",
          (int)TP->query_cols(), implode( map_array( data[PATTERNS],
          "add_start", TO, verb ), "\n") );
    if( data[SINGLE] ) {
        if( data[SINGLE][NO_ARGUMENTS] ) {
            ret += "Has a no arguments mode.\nSelf:   "+
            create_message(
                0, "", data[SINGLE][NO_ARGUMENTS][SELF], 0, 0, 0, 0, TP)+
                "Others: "+create_message(
                0, "", data[SINGLE][NO_ARGUMENTS][REST], 1, 0, 0, 0, TP)+"\n";
        }
        if( data[SINGLE][ARGUMENTS] ) {
            for( i = 0; i < sizeof(data[SINGLE][ARGUMENTS]); i += SMALL_ARG_SIZE ) {
                arg = data[SINGLE][ARGUMENTS][i+ARGS][0];
                ret += sprintf("For the arguments: [%-=*s",
                    (int)TP->query_cols() - 20, implode(
                    data[SINGLE][ARGUMENTS][i+ARGS], ", ")+"]")+
                    "\nSelf:   "+create_message(
                    0, arg, data[SINGLE][ARGUMENTS][i+SELF], 0, 0, 0, 0, TP)+
                    "Others: "+create_message(
                    0, arg, data[SINGLE][ARGUMENTS][i+REST], 1, 0, 0, 0, TP)+"\n";
            }
        }
    }
    if( data[TARGET] ) {
        target = query_multiple_short(({ "Womble", "Cabbage" }));
        if( data[TARGET][NO_ARGUMENTS] ) {
            ret += "Has a no arguments, targeted mode.\nSelf:   " +
                create_message( target, "", data[TARGET][NO_ARGUMENTS][SELF],
                0, 0, 0, 0, TP)+"Target: "+( data[TARGET][NO_ARGUMENTS][TARGET] ?
                create_message( target, "", data[TARGET][NO_ARGUMENTS][TARGET],
                2, 0, 0, 0, TP) : create_message( target, "",
                data[TARGET][NO_ARGUMENTS][REST], 1, 0, 0, 0, TP ) ) +
                "Others: "+create_message( target, "",
                data[TARGET][NO_ARGUMENTS][REST], 1, 0, 0, 0, TP)+"\n";
        }
        if( data[TARGET][ARGUMENTS] ) {
            for( i = 0; i < sizeof(data[TARGET][ARGUMENTS]); i += ARG_SIZE ) {
                arg = data[TARGET][ARGUMENTS][i+ARGS][0];
                ret += sprintf("For the arguments: [%-=*s",
                    (int)TP->query_cols() - 20, implode(
                    data[TARGET][ARGUMENTS][i+ARGS], ", ")+"]")+"\nSelf:   "+
                    create_message( target, arg, data[TARGET][ARGUMENTS][i+SELF],
                    0, 0, 0, 0, TP)+"Target: "+( data[TARGET][ARGUMENTS][TARGET+i] ?
                    create_message( target, arg, data[TARGET][ARGUMENTS][i+TARGET],
                    2, 0, 0, 0, TP) : create_message( target, arg,
                    data[TARGET][ARGUMENTS][i+REST], 1, 0, 0, 0, TP ) )+
                    "Others: "+create_message( target, arg,
                    data[TARGET][ARGUMENTS][i+REST], 1, 0, 0, 0, TP );
            }
        }
    }
    return TP->convert_message(ret);
} /* help_string() */

/**
 * Attempts to do the force on the player.
 * @param arr the args used to force
 */
void do_force( mixed arr ) {
    string cmd;

    cmd = explode(arr[1], " ")[0];
    /* Only allow them to use soul commands on the force... */
    if( soul_command_names[cmd] && !arr[0]->query_property("dead") )
        arr[0]->eventForce(arr[1]);
} /* do_force() */

int query_pcache_size() { return sizeof(keys(pattern_cache)); }

int query_scache_size() { return sizeof(keys(soul_cache)); }

mixed stats() {
    return  ({
      ({ "souls read", scache_reads, }),
      ({ "soul cache hit percent", (scache_hits * 100) / scache_reads, }),
      ({ "souls in cache", sizeof(keys(soul_cache)), }),
      ({ "patterns read", pcache_reads, }),
      ({ "pattern cache hit percent", (pcache_hits * 100) / pcache_reads, }),
      ({ "patterns in cache", sizeof(keys(pattern_cache))-1, }),
    });
} /* stats() */
