/*
* Fixed verb pluralisation errors in add_failed_messages.
* Sandoz, 30 June 2001
*/

#include <fuel_handler.h>
#include <move_failures.h>
inherit OBJECT_OBJ;
inherit "/std/basic/holdable";

#define BRIGHTNESS 30
#define MAX_FUEL 2000
#define FUEL_PER_TICK ( FUEL_TIME * 2 )

private int amount_of_fuel;
private int is_lit;

void setup_shorts();

void create() {
    object::create();
    holdable::create();
} /* create() */

void setup() {
    amount_of_fuel = MAX_FUEL;
    set_name( "torch" );
    add_plural( "torches" );
    set_material("wood");
    setup_shorts();
    set_long( function() {
          string str;

          if ( is_lit && amount_of_fuel) {
              call_out( (: setup_shorts() :), 2 );
              str = "There is a fire burning out of control on the end "
              "of a stick of wood.  There is a lot of smoke coming "
              "off the fire, one of those ones that no matter which "
              "way you turn, it goes up your nose.";
              switch ( amount_of_fuel / ( MAX_FUEL / 10 ) ) {
              case 10 :
              case 9  :
                  return str+"  The torch looks brand new, it will burn for "
                  "ages yet.\n";
              case 8 :
              case 7 :
              case 6 :
                  return str+"  Not yet burning for very long, this torch is "
                  "pretty happy with itself, it does not seem "
                  "to care about its short life span.\n";
              case 5 :
              case 4 :
                  return str+"  The torch is happily burning.  It is in the "
                  "prime of its life.\n";
              case 3 :
                  return str+"  The torch has a little way to go yet.\n";
              case 2 :
                  return str+"  It looks like this torch will not "
                  "last much longer, buying a new one could "
                  "be a good investment.\n";
              case 1 :
              case 0 :
                  return str+"  The torch is spluttering, there is huge "
                  "amounts of smoke coming off it.  It looks like "
                  "it is about to go out.\n";
              }
          }
          if ( amount_of_fuel >= MAX_FUEL )
              return "The lump of what looks to be some sort of tree has a few "
              "dirty rags wrapped around the end of it, it appears as "
              "though it might be possible to light them.  The dirty rags "
              "have some sort of stuff covering them, you guess it is "
              "to make them burn better.\n";
          if ( amount_of_fuel > MAX_FUEL / 2 )
              return "Someone has cut down a tree, chopped it up into smaller "
              "chunks and then wrapped some rags around the end of it.  "
              "The rags are blackened and it looks like someone set "
              "fire to them, perhaps you can too?\n";
          str = "The lump of what looks to be some sort of tree has a few "
          "dirty rags wrapped around the end of it.  ";
          if ( !amount_of_fuel )
              return str +"The end is completely blackened.  You would "
              "have to be extremely clever to get this torch "
              "going again.\n";
          switch (amount_of_fuel/(MAX_FUEL/10)) {
          case 5 :
          case 4 :
              return str +"The end has been blackened quite a bit, "
              "but it looks like there is quite a bit of "
              "go left still.\n";
          case 3 :
          case 2 :
              return str +"A few rags here and there cling onto a meager "
              "existance.  You could set fire to them and "
              "make their life hell for a little while, but "
              "not very long.\n";
          case 1 :
          case 0 :
              return str +"You can just see the remains of some rags "
              "attached to the blackened and burnt end of "
              "the torch.  It will last for a short while "
              "longer.\n";
          }
          return "Whoops.  Tell a creator if you see this.\n";
      }
    );
    is_lit = 0;
    set_weight( 6 );
    set_value( 50 );
} /* setup() */

void set_fuel(int f) {
    amount_of_fuel = f;
    if(amount_of_fuel < 0)
        amount_of_fuel = 0;
    setup_shorts();
} /* set_fuel() */

void init() {
    TP->add_command( "light", TO );
    TP->add_command( "extinguish", TO );
    TP->add_command( "dowse", TO );
    TP->add_command( "douse", TO );
} /* init() */

void setup_shorts() {
    if ( is_lit && amount_of_fuel) {
        set_short( "lit torch" );
        set_main_plural( "lit torches" );
        remove_adjective( ({ "lightable", "burnt", "out" }) );
        add_adjective( "lit" );
    } else if ( amount_of_fuel > 0 ) {
        set_short( "lightable torch" );
        set_main_plural( "lightable torches" );
        remove_adjective( ({ "lit", "burnt", "out" }) );
        add_adjective( "lightable" );
    } else {
        set_short( "burnt torch" );
        set_main_plural( "burnt torches" );
        remove_adjective( ({ "lit", "lightable" }) );
        add_adjective( ({ "burnt", "out" }) );
    }
} /* setup_shorts() */

int do_light() {
    if ( ENV(TO) != TP ) {
        TP->add_failed_mess( TO, "You are not carrying $D.\n" );
        return 0;
    }

    if (amount_of_fuel <= 0) {
        TP->add_failed_mess( TO, "You can't $V $D, because $V$0=it,they$V$ "
                                 "$V$0=is,are$V$ burnt out.\n" );
        return 0;
    }
    if (is_lit) {
        TP->add_failed_mess( TO, "You can't $V $D, because $V$0=it,they$V$ "
                                 "$V$0=is,are$V$ already lit.\n" );
        return 0;
    }
    if (!query_holder() && !sizeof( TO->hold_item( TP, -1 ) ) ) {
        TP->add_failed_mess( TO, "You are unable to hold $D, because your "
            "arms are already full.\n" );
        return 0;
    }
    is_lit = 1;
    FUEL_HANDLER->add_burner( TO );
    set_light( BRIGHTNESS );
    call_out( "setup_shorts", 2);
    return 1;
} /* do_light() */

void out_of_fuel() {
    is_lit = amount_of_fuel = 0;
    set_light( 0 );
    set_value( 0 );
    FUEL_HANDLER->remove_burner( TO );
    tell_room( ENV(TO), poss_short() +" goes out.\n" );
    call_out( "setup_shorts", 2 );
} /* out_of_fuel() */

void do_warning() {
    tell_room( ENV(TO), poss_short()+" starts to sputter and smoke a lot.  It "
        "is on its last legs.\n");
    return;
} /* do_warning() */

void consume_fuel() {
    amount_of_fuel -= FUEL_PER_TICK;
    if(amount_of_fuel < 0)
        amount_of_fuel = 0;

    switch ( amount_of_fuel ) {
    case (200-FUEL_PER_TICK) .. 200:
        do_warning();
        break;
    case 0:
        out_of_fuel();
        break;
    default:
        /* do nothing */
    }
} /* consume_fuel() */

int do_extinguish() {
    if ( !is_lit && objectp( TP ) ) {
        TP->add_failed_mess( TO, "You can't $V $D, because $V$0=it,they$V$ "
                                 "$V$0=is,are$V$ not lit.\n" );
        return 0;
    } else if ( !is_lit ) {
        return 0;
    }
    FUEL_HANDLER->remove_burner( TO );
    is_lit = 0;
    set_light( 0 );
    call_out( "setup_shorts", 2);
    return 1;
} /* do_extinguish() */

int do_dowse() { return do_extinguish(); }
int do_douse() { return do_extinguish(); }

void dest_me() {
    FUEL_HANDLER->remove_burner( TO );
    set_light( 0 );
    holdable::dest_me();
    object::dest_me();
} /* dest_me() */

mixed *stats() {
    return ::stats() + ({
      ({ "fuel" , amount_of_fuel, }),
      ({ "is lit", is_lit, }),
    });
} /* stats() */

mixed query_dynamic_auto_load() {
    return ([ "::" : object::query_dynamic_auto_load(),
      "amount of fuel" : amount_of_fuel,
      "hold" : holdable::query_dynamic_auto_load(),
      "is lit" : is_lit,
    ]);
} /* query_dynamic_auto_load() */

int held_this_item(int type, object holder, mixed arg) {
    if (!type) {
        if (holder && is_lit) {
            tell_object( holder,
              "You extinguish the "+ short() +" as you put it down.\n");
            tell_room( ENV(holder ),
              holder->short() +" extinguishes the "+
              short() +" as "+ holder->query_pronoun()
              +" puts it down.\n", ({ holder }));
        }
        do_extinguish();
    } else if (type == 2) {
        if (arg && holder && amount_of_fuel > 0) {
            set_light( BRIGHTNESS );
            FUEL_HANDLER->add_burner( TO );
            is_lit = 1;
        } else {
            is_lit = 0;
        }
        setup_shorts();
    }
    return 1;
} /* held_this_item() */

void init_dynamic_arg( mapping arg, mixed dummy ) {
    amount_of_fuel = arg["amount of fuel"];
    is_lit = arg["is lit"];
    if( arg["hold"] )
        holdable::init_dynamic_arg( arg["hold"], arg["is lit"] );
    ::init_dynamic_arg(arg["::"]);
} /* init_dynamic_arg() */

void init_static_arg(mapping arg) { return; }
mapping query_static_auto_load() { return 0; }

varargs int move( mixed ob, string mess1, string mess2 ) {
    int ret;

    ret = holdable::move(ob);
    if (ret != MOVE_OK) {
        return ret;
    }
    return object::move( ob, mess1, mess2 );
} /* move() */

void self_light() {
    is_lit = 1;
    FUEL_HANDLER->add_burner( TO );
    set_light( BRIGHTNESS );
    setup_shorts();
    return;
}/*self_light*/

int query_amount_of_fuel() { return amount_of_fuel; }
