/*      lantern.c
 *
 *        This file was constructed by Godot (Marshall Buhl).  If you
 *        make any changes to it, please leave comments in the code
 *        detailing the changes and let him know about them.  This file
 *        is not the original, so it is important that he be informed.
 *        If not, he may unknowingly throw away your changes by
 *        uploading an new version.
 *
 *        This is a modification of the standard torch.
 *
 *    Change log:
 *
 *        11/26/92 - Created by Godot.
 *        11/28/92 - Modified by Godot to add prototype for init_arg().
 *         2 May 93 - Modified by Pinkfish to use failed_mess and succeeded_mess.
 *        13 Apr 95 - Fixed by Ceres for bug reports
 *        15 Okt 96 - Mostly rewritten by Turrican to make it a bit nicer.
 *         5 Jun 97 - Rewritten for the fuel_handler
 *        30 Jun 01 - Changed to reduce value and weight as fuel burns out,
 *                    Added gradual fuel amount messages to extra look.
 *                    Added different shorts based on status.
 *                    Fixed verb pluralisation errors in add_failed_messages.
 *                    - Sandoz
 *        11 Jul 01 - The lantern will now be automatically extinguished if
 *                    moved into a container - Sandoz
 *        12 Feb 02 - Added the condition stuff - Sandoz
 */

#include <fuel_handler.h>
#include <move_failures.h>

inherit OBJECT_OBJ;
inherit "/std/basic/holdable";
inherit "/std/basic/condition";

#define MAX_FUEL      3600
#define BRIGHTNESS    60
#define FUEL_PER_TICK FUEL_TIME
#define BASE_COST     20
#define BASE_WEIGHT   30

int fuel_left, is_lit;

/** @ignore yes */
int do_not_sell() { return fuel_left < 1; }

/** @ignore yes */
void break_me() {
   object ob;

   if( ob = query_holder() ) {
       tell_object( ob, "%^RED%^Your "+short(0)+" breaks!%^RESET%^\n");
       tell_room( ENV(ob), (string)ob->the_short()+"'s "+
           short(0)+" breaks!\n", ob );
       ob->set_unhold( TO );
   }

   ::break_me();

} /* break_me() */

/** @ignore yes */
void setup_short();

/** @ignore yes */
void create() {
    condition::create();
    object::create();
    holdable::create();
    call_out("setup_short", 2 );
} /* create() */

/** @ignore yes */
void setup() {
    fuel_left = MAX_FUEL;

    is_lit = 0;

    set_name("lantern");
    setup_short();
    set_long( "This heavy camping lantern smells strongly of oil, "
              "and looks quite capable of providing lots of light, "
              "enough to banish the darkest shadows.\n" );

    add_extra_look(TO);
    set_weight(30);
    set_value(140);
    set_max_cond(4000);
    set_cond(4000);
    set_lowest_cond(4000);
    set_damage_chance(100);

} /* setup() */

/** @ignore yes */
string long( string word, int dark ) {
    return ::long() + ( !dark ? cond_string() : "" );
} /* long() */

/** @ignore yes */
int do_fill() {
    fuel_left = MAX_FUEL;
    return fuel_left;
} /* do_fill() */

/** @ignore yes */
void setup_short() {
    if ( is_lit && fuel_left ) {
        set_short( "lit lantern" );
        set_main_plural( "lit lanterns" );
        remove_adjective( ({ "empty" }) );
        add_adjective( "lit" );
    } else if ( fuel_left > 0 ) {
        set_short( "lantern" );
        set_main_plural( "lanterns" );
        remove_adjective( ({ "lit", "empty" }) );
    } else {
        set_short( "empty lantern" );
        set_main_plural( "empty lanterns" );
        remove_adjective( ({ "lit" }) );
        add_adjective( ({ "empty" }) );
    }
} /* setup_short() */

/** @ignore yes */
void do_unlight() {
    FUEL_HANDLER->remove_burner( TO );
    is_lit = 0;
    set_light( 0 );
} /* do_unlight() */

/** @ignore yes */
int do_extinguish() {
    if( !is_lit ) {
        add_failed_mess("You can't $V $D, because $V$0=it,they$V$ "
                        "$V$0=is,are$V$ not lit.\n");
        return 0;
    }
    do_unlight();
    call_out( "setup_short", 3 );
    return 1;
} /* do_extinguish() */

/** @ignore yes */
int do_dowse() { return do_extinguish(); }
/** @ignore yes */
int do_douse() { return do_extinguish(); }

/** @ignore yes */
int do_light() {
    if( is_lit ) {
        add_failed_mess("You can't $V $D, because $V$0=it,they$V$ "
                        "$V$0=is,are$V$ already lit.\n");
        return 0;
    }
    if( fuel_left <= 0 ) {
        add_failed_mess("You can't $V $D, because $V$0=it,they$V$ "
                        "$V$0=is,are$V$ out of fuel.\n");
        return 0;
    }
    FUEL_HANDLER->add_burner( TO );
    is_lit = 1;
    set_light( BRIGHTNESS );
    call_out("setup_short", 3 );
    return 1;
} /* do_light() */

/** @ignore yes */
void init() {
    add_command("light");
    add_command("extinguish");
    add_command("dowse");
    add_command("douse");
} /* init() */

/** @ignore yes */
void burn_out_mess() {
    object place, carrier;

    if( !place = ENV( TO ) )
        return;

    while( ENV( place ) ) {
        carrier = place;
        place = ENV( place );
    }

    if( !carrier ) {
        tell_room( place, one_short()+" burns out.\n" );
        return;
    }

    if( living( carrier ) && ( ENV( TO ) == carrier ) ) {
        tell_room( place, poss_short()+" burns out.\n" );
        return;
    }

    return;

} /* burn_out_mess() */

/** @ignore yes */
void out_of_fuel() {
    do_unlight();
    fuel_left = 0;
    burn_out_mess();
    call_out("setup_short", 2 );
} /* out_of_fuel() */

/** @ignore yes */
void consume_fuel() {
    fuel_left -= FUEL_PER_TICK;
    switch( fuel_left ) {
      case -10000 .. 0:
        out_of_fuel();
      break;
      default:
    }
} /* consume_fuel() */

/** @ignore yes */
void dest_me() {
    FUEL_HANDLER->remove_burner( TO );
    holdable::dest_me();
    object::dest_me();
} /* dest_me() */

/** @ignore yes */
mixed stats() {
    return object::stats() + condition::stats() + ({
      ({ "fuel" , fuel_left, }),
      ({ "is lit", is_lit, }),
      });
} /* stats() */

/** @ignore yes */
mapping query_dynamic_auto_load() {
   return ([ "::" : ::query_dynamic_auto_load(),
             "hold" : holdable::query_dynamic_auto_load(),
             "condition" : condition::query_dynamic_auto_load(),
             "fuel left" : fuel_left,
             "is lit" : is_lit,
             ]);
} /* query_dynamic_auto_load() */

/** @ignore yes */
void init_dynamic_arg( mapping arg ) {
    fuel_left = arg["fuel left"];

    if( arg[ "is lit" ] ) {
        FUEL_HANDLER->add_burner( TO );
        is_lit = 1;
        set_light(BRIGHTNESS);
    }

    if( arg["hold"] )
        holdable::init_dynamic_arg( arg["hold"], arg["is lit"] );

    if( arg["condition"] )
        condition::init_dynamic_arg( arg["condition"] );

    ::init_dynamic_arg( arg["::"] );

} /* init_dynamic_arg() */

/** @ignore yes */
void init_static_arg( mapping arg ) {
} /* init_static_arg() */

/** @ignore yes */
mapping query_static_auto_load() {
    return 0;
} /* query_static_auto_load() */

/** @ignore yes */
int query_lit() { return is_lit; }

/** @ignore yes */
void set_lit(int i) { is_lit = i; }

/** @ignore yes */
int query_fuel() { return fuel_left; }

/** @ignore yes */
int query_ethereal_light() { return 1; }

// Make the lantern cheaper if empty.
/** @ignore yes */
int query_value() {
    int val;

    if( fuel_left < 0 )
        return 0;

    val = ::query_value();
    val = fuel_left * val / MAX_FUEL;
    val += BASE_COST;

    return ( val * ( 10 + ( 90 * query_cond() ) /
                                 query_max_cond() ) ) / 100;

} /* query_value() */

// Make the lantern lighter if empty.
/** @ignore yes */
int query_weight() {
    int weight, bing;

    if( fuel_left < 0 )
        return BASE_WEIGHT;

    weight = ::query_weight();
    bing = fuel_left * weight / MAX_FUEL;
    bing += BASE_WEIGHT;

    return bing;

} /* query_value() */

/** @ignore yes */
string extra_look( object ob ) {
    string ret;
    int percent;

    // If for some reason this was in the extra look of another object,
    // we'd get some wierd descs.
    if( ob != TO )
        return "";

    ret = ( is_lit ? "It is burning with a bright yellow glow, " :
                     "It is currently not burning, " );

    if( fuel_left == 0 )
        return ret + "and seems to be quite empty.\n";

    percent = 100 * fuel_left / MAX_FUEL;

    switch( percent ) {
        case -1000..-1 : ret += "and is so empty that you should "
                                "probably contact a creator.\n";
        break;
        case 0..20 : ret += "and seems to be almost empty.\n";
        break;
        case 21..40 : ret += "and contains a bit of oil.\n";
        break;
        case 41..60 : ret += "and contains some oil.\n";
        break;
        case 61..80 : ret += "and contains quite a bit of oil.\n";
        break;
        case 81..100 : ret += "and is full of oil.\n";
        break;
        default : ret += "and is so full of oil that you should "
                         "probably contact a creator.\n";
    }

    return ret;

} /* extra_look() */

/** @ignore yes */
varargs int move( mixed ob, string mess1, string mess2 ) {
    int ret;

    ret = holdable::move(ob);

    if( ret != MOVE_OK )
        return ret;

    return object::move( ob, mess1, mess2 );

} /* move() */

/** @ignore yes */
void event_move_object( mixed from, mixed to ) {
    object burier;

    if( !is_lit || !from || !to )
        return;

    /* we're getting buried */
    if( to->query_property("burial object") ) {
        burier = filter( previous_object(-1), (: interactive($1) :) )[0];
        tell_object( burier, "You extinguish "+one_short()+".\n");
        tell_room( ENV(burier), burier->the_short()+" extinguishes "+
            one_short()+".\n", burier );
        do_unlight();
        setup_short();
        return;
    }

    /* destination is a living */
    if( !living(from) || living( to ) )
        return;

    /* destination is a room */
    if( !ENV(to) )
        return;

    /* moved to a container in a living */
    if( living(ENV(to)) ) {
        tell_object( from, "You extinguish "+one_short()+".\n");
        tell_room( ENV(from), from->the_short()+" extinguishes "+
                              poss_short()+".\n", from );
        do_unlight();
        setup_short();
        return;
    }

} /* event_move_object() */

void being_sold() {
  do_unlight();
  setup_short();
}
