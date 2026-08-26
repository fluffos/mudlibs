/**
 * This is the health handler.
 * Spits out health strings for livings and a bit fancier
 * strings for the health command.  Also deals with
 * attacking checks and prints the monitor.
 * @author Sandoz
 */

#include <player.h>

#define RED  "%^RED%^"
#define CYAN "%^CYAN%^"
#define YELL "%^YELLOW%^"
#define RES  "%^RESET%^"

#define H_NAME "$who$ "

private mapping monitor_queue;
private int flush_id;

private void flush_monitor_queue();

/** @ignore yes */
void create() {
    monitor_queue = ([ ]);
} /* create() */

/** @ignore yes */
void dest_me() {
    destruct(TO);
} /* dest_me() */

/**
 * This method does all the checks required for any
 * aggressive commands.  If the attack argument is 0,
 * then combat will not be initiated, if 1, then the
 * targets will be attacked.
 * @param things the things to test
 * @param attack if this is 0, then combat will not be
 * initiated, if 1, then the things that pass the checks
 * will be attacked
 */
object *do_attack_checks( object *things, int attack ) {
    object thing;
    int dark;

    if( !ENV(TP) ) {
        add_failed_mess("You are in limbo...\n");
        return 0;
    }

    if( TP->no_offense() ) {
        add_failed_mess("You cannot attack anyone at the moment.\n");
        return 0;
    }

    things -= ({ TP });

    if( !sizeof( things ) ) {
        add_failed_mess("You cannot attack yourself!\n");
        return 0;
    }

    dark = TP->check_dark( ENV(TP)->query_light() );

    if( dark > 1 ) {
        add_failed_mess("It is way too bright to attack anyone.\n");
        return 0;
    }

    if( dark < -1 ) {
        add_failed_mess("It is way too dark to attack anyone.\n");
        return 0;
    }

    foreach( thing in things ) {
        if( thing->query_property( PASSED_OUT ) ) {
            write("You cannot attack "+thing->the_short()+" since "+
                thing->HE+" is passed out.\n");
            things -= ({ thing });
            continue;
        }

        if( !userp( thing ) ) {
            if( userp( TP ) || !thing->query_property("no attack") ) {
                switch( dark ) {
                  case -1:
                    if( !random( 2 ) ) {
                        write("You peer into the darkness, but fail to "
                            "find "+thing->the_short()+".\n");
                        things -= ({ thing });
                        continue;
                    }
                    write("You just manage to make out "+
                        thing->the_short()+".\n");
                  break;
                  case 1:
                    if( !random(2) ) {
                        write("You squint as hard as you can, but fail to "
                            "find "+thing->the_short() +".\n");
                        things -= ({ thing });
                        continue;
                    }
                    write("You just manage to make out "+
                        thing->the_short()+".\n");
                  default:
                }
                if( attack ){
                    TP->attack_ob( thing );
                }
            }
            continue;
        }

        if( !interactive( thing ) ) {
            write( thing->the_short()+" is net-dead.\n");
            things -= ({ thing });
            continue;
        }

        if( thing->query_property( "guest" ) ) {
            write("You cannot attack "+thing->the_short()+" since "+
                thing->HE+" is a guest.\n");
            things -= ({ thing });
            continue;
        }

        if( thing->query_auto_loading() ) {
            write("Be sporting; "+thing->the_short()+" doesn't have "+
                thing->HIS+" equipment yet.\n");
            things -= ({ thing });
            continue;
        }

        if( userp( TP ) && !TP->query_property( PKER ) ) {
            write("You cannot summon the courage to attack "+
                thing->the_short() +".\n");
            things -= ({ thing });
            continue;
        }

        if( userp( TP ) && pk_check( TP, thing ) ) {
            write("Something tells you that it would be wrong to attack "+
                thing->the_short() +".\n");
            things -= ({ thing });
            continue;
        }

        switch( dark ) {
          case -1:
            if( !random( 2 ) ) {
                write("You peer into the darkness, but fail to "
                    "find "+thing->the_short()+".\n");
                things -= ({ thing });
                continue;
            }
            write("You just manage to make out "+thing->the_short()+".\n");
          break;
          case 1:
            if( !random( 2 ) ) {
                write("You squint as hard as you can, but fail to "
                    "find "+thing->the_short()+".\n");
                things -= ({ thing });
                continue;
            }
            write("You just manage to make out "+thing->the_short()+".\n");
          default:
        }
        if( attack ){
            TP->attack_ob( thing );
        }
    }

    return things;

} /* do_attack_checks() */

/**
 * This method returns the health string of the creature.
 * It is used in extra_look in living creatures and in the 'health' command.
 * @param who the creature to get the health string for
 * @param full whether or not to returns the full (coloured) health string
 * @return the health string
 */
varargs string health_string( object who, int full ) {
    int per, current;
    string msg;

    if( !objectp(who) )
        return 0;

    if( who->query_property( "dead" ) ) {
        msg = "appears to be dead";
        return ( full ? H_NAME+msg+"." : msg );
    }

    current = ( who->query_name() == "death" ? 1 : who->query_hp() );
    per = 100 * current / ( who->query_max_hp() || 1 );

    switch( per ) {
      case -100..10:
           msg = "is in very bad shape";
           return ( full ? RED+H_NAME+msg+"."+RES : msg );
      case 11..30:
           msg = "is in bad shape";
           return ( full ? RED+H_NAME+msg+"."+RES : msg );
      case 31..60:
           msg = "is not in good shape";
           return ( full ? YELL+H_NAME+msg+"."+RES : msg );
      case 61..95:
           msg = "is slightly hurt";
           return ( full ? CYAN+H_NAME+msg+"."+RES : msg );
      case 96..100:
           msg = "is in good shape";
           return ( full ? H_NAME+msg+"." : msg );
      default:
           msg = "is rather buggy and you should probably contact a creator";
           return ( full ? H_NAME+msg+"." : msg );
    }

} /* health_string() */

/**
 * This method prints out the health and gp points during combat,
 * if the player so desires. Moved to here from the combat effect.
 * @param player the object recieving the monitor message
 * @param charge non-zero to charge the player gp points for the message
 * @see query_monitor
 */
void monitor_points( object player, int charge ) {
   int hp, max;
   string colour;

   if( charge && player->adjust_gp( -1 ) < 0 )
       return;

   hp = player->query_hp();
   max = player->query_max_hp();

   switch( ( hp * 100 ) / max ) {
     case 61..100:
       colour = "%^GREEN%^";
     break;
     case 31..60:
       colour = "%^YELLOW%^";
     break;
     default :
       colour = "%^RED%^";
   }

   tell_object( player, colour + "Hp: " + hp + " (" + max + ") "
       "Ep: "+player->query_gp()+" ("+player->query_max_gp()+") "
       "Xp: "+player->query_xp()+"%^RESET%^\n");

} /* monitor_points() */

/**
 * This method is used by combat to display the monitor after
 * all heartbeats have finished.
 * @param ob the object to print the monitor to
 * @param charge non-zero to charge the player gp points for the message
 */
void register_monitor( object ob, int charge ) {
    if( !userp(ob) )
        return;

    if( undefinedp( monitor_queue[ob] ) || charge )
        monitor_queue[ob] = charge;

    if( !flush_id )
        flush_id = call_out( (: flush_monitor_queue :), 1 );

} /* register_monitor() */

/** @ignore yes */
private void flush_monitor_queue() {
    flush_id = 0;

    foreach( object ob, int charge in monitor_queue ) {
        if( ob )
            monitor_points( ob, charge );
    }

    monitor_queue = ([ ]);

} /* flush_monitor_queue() */
