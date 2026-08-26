
inherit COMMAND_BASE;

string *normal_types, *cre_types, player_format, cre_format;

/** @ignore yes */
void create() {
    ::create();
    normal_types = ({"shout", "newbie", "remote-soul", "multiple-soul",
        "multiple-tell",  "teach", "tell", "remote", "multiple-remote"});
    cre_types = ({"remote-spam"});
    player_format = "{"+implode( normal_types, "|")+"}";
    cre_format = "{"+implode( normal_types + cre_types, "|")+"}";
} /* create() */

/** @ignore yes */
int check_earmuffs() {
    string *on, *types;

    if( !on = TP->query_property("earmuffs") )
        on = ({ });
    else if( !sizeof(on) )
        TP->remove_property("earmuffs");

    types = normal_types;

    if( creatorp(TP) )
        types += cre_types;

    write("Your earmuffs are "+( TP->query_earmuffs() ? "on" : "off")+".\n");

    if( !sizeof(on) ) {
        write("You have nothing set to be earmuffed.\n");
        write("$I$5=Earmuffable events are "+query_multiple_short(types)+
              ".\n");
    } else {
        write("$I$5=You have "+query_multiple_short(on)+" events earmuffed.\n");
        types -= on;
        if( sizeof(types) )
            write("$I$5=You are not currently earmuffing "+
                query_multiple_short(types)+ " events.\n");
    }

    return 1;

} /* check_earmuffs() */

/** @ignore yes */
int do_earmuff_control( string str ) {
    string *types, *on;

    types = normal_types;

    if( creatorp(TP) )
        types += cre_types;

    if( !on = TP->query_property("earmuffs") )
        on = ({ });

    switch( str ) {
      case "on" :
        if( !TP->query_earmuffs() ) {
            TP->toggle_earmuffs();
            write("Earmuffs turned on.\n");
            break;
        }
        write("Your earmuffs are already on.\n");
      break;
      case "off" :
        if( TP->query_earmuffs() ) {
            TP->toggle_earmuffs();
            write("Earmuffs turned off.\n");
            break;
        }
        write("Your earmuffs are already off.\n");
      break;
      case "all" :
        on = types;
        if( sizeof(on) )
            write("$I$5=Your "+query_multiple_short(on)+" events will now be "
                   "earmuffed.\n");
      break;
      case "none" :
        if( !sizeof(on) ) {
            write("You are not earmuffing anything already.\n");
        } else {
            write("Nothing will be earmuffed any more.  "
                  "(No news is good news?)\n");
            on = ({ });
        }
        break;
    }

    if( sizeof(on) )
        TP->add_property("earmuffs", on );
    else
        TP->remove_property("earmuffs");

    return 1;

} /* do_earmuff_control() */

/** @ignore yes */
int do_earmuff( string str, string onOff ) {
    string *types, *on, *off;

    types = normal_types;

    if( creatorp(TP) )
        types += cre_types;


    if( !on = TP->query_property("earmuffs") )
        on = ({ });

    off = ({ });

    switch( onOff ) {
      case "on" :
        if( member_array( str, on ) == -1 ) {
            on += ({ str });
            write("You are now earmuffing " + str + " events.\n");
            break;
        }
        write("You are already earmuffing " + str + " events.\n");
      break;
      case "off" :
        if( member_array( str, on ) != -1 ) {
            off += ({ str });
            write("You are not earmuffing " + str + " events anymore.\n");
            break;
        }
        write("You are not earmuffing " + str + " events already.\n");
      break;
      default :
        if( member_array( str, on ) == -1 ) {
            on += ({ str });
            write("You are now earmuffing " + str + " events.\n");
        } else {
            off += ({ str });
            write("You are not earmuffing " + str + " events anymore.\n");
        }
      break;
    }

    on -= off;

    if( sizeof(on) )
        TP->add_property("earmuffs", on );
    else
        TP->remove_property("earmuffs");

    return 1;

} /* do_earmuff() */

/** @ignore yes */
mixed query_patterns() {
   if( creatorp(TP) )
       return ({"", (: check_earmuffs() :),
                "{on|off|all|none}", (: do_earmuff_control($4[0]) :),
                cre_format, (: do_earmuff($4[0], "") :),
                cre_format + " {on|off}", (: do_earmuff($4[0], $4[1]) :) });

   return ({"", (: check_earmuffs() :),
            "{on|off|all|none}", (: do_earmuff_control($4[0]) :),
            player_format, (: do_earmuff($4[0], "") :) ,
            player_format + " {on|off}", (: do_earmuff($4[0], $4[1]) :) });

} /* query_patterns() */
