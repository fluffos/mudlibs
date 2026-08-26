
#include <language.h>

inherit COMMAND_BASE;

/** @ignore yes */
int cmd( object *things ) {
    string gendstr, text, read, reader, r_short;
    string *others;
    object thing;
    mapping hide_invis;
    int dark;

    if( !TP->query_property("dead") )
        dark = (int)TP->check_dark( (int)ENV(TP)->query_light() );

    if( dark > 0 ) {
        add_failed_mess("It is way too bright to read anything at all.\n");
        return 0;
    }

    if( dark < 0 ) {
        add_failed_mess("It is way too dark to read anything at all.\n");
        return 0;
    }

    reader = "";
    others = ({ });

    foreach( thing in things ) {
       if( !is_in_me_or_environment( thing, TP ) ) {
           add_failed_mess("You cannot read $I.\n", ({ thing }) );
           continue;
       }

       read = thing->query_read_short() || "$name$";

       if( !text = thing->query_readable_message(TP) ) {
           if( living(thing) )
               gendstr = thing->query_objective();
           else
               gendstr = ( ( dark = query_group(thing) ) ? "them" : "it");

           r_short = thing->query_read_short() || "$name$";

           if( !thing->command_control("read") ) {
               if( thing != TP ) {
                   reader += "$C$"+replace_string( r_short,
                       "$name$", thing->the_short() )+" "+( dark ? "do" :
                       "does")+" not have anything written on "+gendstr+".\n";
              } else {
                   reader += "You cannot read yourself.\n";
              }
           } else {
                others += ({ replace( read, "$name$", (string)thing->a_short() ) });
                reader += "";
           }
           continue;
       }

       reader += "You read "+replace_string( read, "$name$",
             (string)thing->the_short() )+":\n"+ text;

       if( read == "$name$" )
           others += ({ thing });
       else
           others += ({ replace( read, "$name$", (string)thing->a_short() ) });
    }

    if( !sizeof( others ) ) {
        add_failed_mess(reader);
        return 0;
    }

    write("$P$Read$P$"+reader );
    hide_invis = TP->query_hide_invis();

    if( !hide_invis["hiding"] )
        add_succeeded_mess( ({"", "$N read$s "+
            query_multiple_short(others)+".\n"}) );

    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() { return ({"<indirect:object>", (: cmd($1) :) }); }
