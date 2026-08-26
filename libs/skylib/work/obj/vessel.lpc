/*
 * Fixed vessels loading with 5 max_weight if max_weight was unset.
 * Max_weight defaults to 1/200th of max_volume.
 * Sandoz, 06th July 2001.
 */
/**
 * This is a container specifically for holding liquids.  The hope is
 * to reduce the memory requirements by taking all of the liquid stuff
 * out of /obj/container, since most of the containers are sacks and
 * chests.  Also, the reaction handler will replace the potion space.
 * <p>
 * Some additional notes:
 * <ol>
 *    <li>As is (hopefully) documented elsewhere, the base units of
 *        volume for most continuous media are drops and pinches, both of
 *        which are roughly 1/4 of a cc.  This means that water has
 *        200 drops per weight unit (1g/cc).  Non-continuous objects
 *        are assumed to be the same density as water.
 * </ol>
 * @author Jeremy
 */

#define REACTION_HANDLER ("/handlers/reaction")
#define TASTE_AMT 200

#include <tasks.h>
#include <move_failures.h>
#include <volumes.h>

inherit BAGGAGE_OBJ;

private int leak_rate;
private int hb_count;
private int sub_query_contents;
private int volume;
private int max_volume;
private int cont_volume;
private int is_liquid;
private nosave int* _fraction;

int drink_amount(int drinking, object player);
private int query_fighting(object player);

/**
 * This method sets the leak rate of the container.  The leak rate is how
 * fast stuff leaks out of the container.
 * @param i the new leak rate of the container
 * @see query_leak_rate()
 */
void set_leak_rate(int i) { leak_rate = i; }
/**
 * This method returns the leak rate of the container
 * @see set_leak_rate()
 * @return the current leak rate
 */
int query_leak_rate() { return leak_rate; }

/**
 * This method sets the maximum volume of the container.  This also
 * sets the maximum weight of the container to one tenth of the
 * volume (if there is no current maximum weight).
 * @param v the new maximum volume
 * @see add_volume()
 * @see query_max_volume()
 * @see set_max_weight()
 */
void set_max_volume(int v) {
  if (!max_weight && v) {
    max_weight = v/200;
  }
  max_volume = v;
} /* set_max_volume() */

/**
 * This method returns the current maxium volume associated with this
 * container.
 * @return the current maximum volume
 */
int query_max_volume() { return max_volume; }

string *leak_verb = ({ " drips slowly",
                       " drips",
                       " dribbles",
                       " trickles slowly",
                       " trickles",
                       " trickles rapidly",
                       " pours sluggishly",
                       " pours",
                       " streams",
                       " gushes",
                       " fountains"
                       });

string *drink_pat = ({ "[from] <direct:object>",
                       "<fraction> {of|from} <direct:object>"
                       });
string *splash_pat = ({ "[from] <direct:object> on[to] <indirect:living>",
                       "<fraction> {of|from} <direct:object> on[to] "
                       "<indirect:living>"
                       });
string *apply_pat = ({ "[from] <direct:object> {on|to} <indirect:living>",
                       "<fraction> {of|from} <direct:object> {on|to]} "
                       "<indirect:living>"
                       });
string *pour_pat = ({ "<direct:object> into <indirect:object>",
                      "<fraction> of <direct:object> into <indirect:object>"
                      });
string *fill_pat = ({ "<indirect:object> <fraction> full {from|into} <direct:object>",
                      "<indirect:object> <fraction> up {from|into} <direct:object>",
                      "<indirect:object> {from|into} <direct:object>"
                      });
void create() {
    do_setup++;
    ::create();
    do_setup--;
    if ( !do_setup ) {
      TO->setup();
    }
} /* create() */

/** @ignore yes */
void init() {
    ::init();
    add_command("drink", drink_pat);
    add_command("splash", splash_pat);
    add_command("rub", apply_pat);
    add_command("apply", apply_pat);
    add_command("pour", pour_pat);
    add_command("taste", "<direct:object>");
    add_command("sip", "<direct:object>");
    //add_command("smell",
    add_command("fill", fill_pat);
    add_command("empty", "<direct:object>");
} /* init() */

/**
 * This returns an adjective for how full the current object is with
 * liquid.  This is used in the parse command handling code.
 * @return the fullness adjective
 * @see query_max_volume()
 */
string *fullness_adjectives() {
   if (!max_volume) return ({ "totally", "empty" });
   switch (100 * volume / max_volume) {
   case 0..4: return ({ "totally", "empty" });
   case 5..13: return ({ "empty" });
   case 65..94: return ({ "full" });
   case 95..100: return ({ "totally", "full" });
   default: return ({ });
   }
} /* fullness_adjectives() */

/** @ingore yes */
string *parse_command_adjectiv_id_list() {
  return  fullness_adjectives() + ::parse_command_adjectiv_id_list();
} /* parse_command_adjectiv_id_list() */

/** @ingore yes */
mixed stats() {
  return ::stats() + ({
      ({ "leak_rate", leak_rate }),
      ({ "volume", volume }),
      ({ "cont_volume", cont_volume }),
      ({ "liquid", is_liquid }),
      ({ "max_volume", max_volume })
    });
} /* stats() */

int cmp_amount_r(object a, object b) {
    return ((int)b->query_amount() - (int)a->query_amount());
} /* cmp_amount() */

int cmp_weight_r(object a, object b) {
    if (a->query_weight() || b->query_weight())
      return ((int)b->query_weight() - (int)a->query_weight());
    return cmp_amount_r(a, b);
} /* cmp_weight() */

/**
 * This method returns the description of the liquid inside the vessel.
 * @return the current liquids description
 */
string query_liquid_desc() {
    object *contents, *liquids = ({}), *solids = ({});
    int i;
    string desc, *shorts;
    mixed *others;

    contents = all_inventory(TO);
    // I could use filter_array here, but I'd have to create 3 other
    // functions and search the whole array 3 times...
    for (i = 0; i < sizeof(contents); i++) {
        if (contents[i]->query_liquid()) {
            liquids += ({contents[i]});
        } else {
            solids += ({contents[i]});
        }
    }
    if (!sizeof(liquids)) {
//        TCRE("shaydz","returns 0");
        return 0;
    }
    liquids = sort_array(liquids, "cmp_amount_r", TO);
    others = unique_array(liquids->a_short(),
                          (: "/global/player/events"->convert_message($1) :));
    shorts = ({ });
    for (i = 0; i < sizeof(others); i++)
      shorts += ({ others[i][0] });
    desc = shorts[0];
    if (sizeof(shorts) > 1) {
        desc += ", mixed with ";
        if (sizeof(shorts) > 4) {
            desc += "other liquids";
        } else {
            desc += query_multiple_short(shorts[1..]);
        }
    }
    if (!sizeof(solids)) {
//        TCRE("shaydz",sprintf("desc1:%s",desc));
        return desc;
    }
    solids = sort_array(solids, "cmp_weight_r", TO);
    others = unique_array(solids,
                          (: $1->query_continuous()?
                           TP->convert_message($1->a_short()) :
                           $1 :) );
    for (i = 0; i < sizeof(others); i++)
      others[i] = others[i][0];
    //printf("others = %O\n", others);
    desc += ", with ";
    if (sizeof(others) > 10) {
        desc += "various undissolved substances";
    } else {
        desc += query_multiple_short(others);
    }
    desc += " floating in it";
//    TCRE("shaydz",sprintf("desc2:%s",desc));
    return desc;
} /* query_liquid_desc() */

/**
 * This method returns the fullness description of the vessel.
 * @return the fullness description of the vessel
 */
string query_fullness_desc() {
    int full;

    full = (100 * volume) / max_volume;
    switch (full) {
    case 0: return "";
    case 1..12: return "It is almost empty.";
    case 13..37: return "It is about one-quarter full.";
    case 38..62: return "It is about half full.";
    case 63..87: return "It is about three-quarters full.";
    case 88..95: return "It is almost full.";
    case 96..100: return "It is completely full.";
    default: return "Its capacity defies the laws of physics.  Please " +
                 "submit a bug report.";
    }
}

/* This is a bit of a kludge, but I need a way to inhibit query_contents()
** in long() of /obj/baggage.  It may be that I could permanently
** replace query_contents() with query_liquid_desc(), but I'm not sure...
*/
/** @ignore yes */
varargs string query_contents( string str, object *obs ) {
    string s, c;

    c = ( volume ? query_fullness_desc() + "\n" : "" );

    if( sub_query_contents ) {
        s = query_liquid_desc();
        return ( s ? str + CAP(s) + ".\n" + c :
                 ::query_contents( str, obs ) + c );
    }

    return ::query_contents( str, obs );

} /* query_contents */

/** @ignore yes */
string long(string str, int dark) {
    string ret;

    sub_query_contents = 1;
    ret = ::long( str, dark );
    sub_query_contents = 0;
    return ret;
} /* long() */

int query_cont_volume() { return cont_volume; }

/**
 * This method returns if this vessel is currenly a liquid.  This means
 * it has a liquid inside it.
 * @see calc_liquid()
 * @return 1 if it is a liquid, 0 if not
 */
int query_liquid() { return is_liquid; }

/**
 * This method determines if we have any liquids inside us at all.
 */
void calc_liquid() {
    is_liquid = ( sizeof( filter( INV(TO), (: $1->query_liquid() :) ) ) ? 1 : 0 );
} /* calc_liquid() */

/**
 * This method returns the current amount of liquid in the container.
 * @return the current amount of liquid in the container
 */
int query_volume() { return volume; }

/**
 * This method returns the amount of volume left for liquids to be
 * added into.
 * @return the amount of volume left
 * @see add_volume()
 * @see transfer_liquid_to()
 */
int query_volume_left() {
  if( !max_weight )
      return max_volume - volume;
  return max_volume - volume - ( max_volume * loc_weight ) / max_weight;
} /* query_volume_left() */

/**
 * This method returns the amount of volume left for liquids to be
 * added into.
 * @param vol the amount of volume added
 * @return 1 if the addition was successful, 0 if not
 * @see add_volume()
 */
int add_volume(int vol) {
    if( ( vol <= 0 ) || !max_volume || ( vol + volume <= max_volume ) ) {
        volume += vol;
        if( PO->query_continuous() )
            cont_volume += vol;
        return 1;
    }
    // Should spillage be handled here, or in the caller?
    return 0;
} /* add_volume() */

/** @ignore yes */
int add_weight(int n) {
    int v;

    if( PO->query_continuous() )
        return ::add_weight(n);
    v = n * 200;
    if( max_volume && ( v + volume > max_volume ) )
        return 0;
    if( ::add_weight(n) ) {
        volume += v;
        return 1;
    }
    return 0;
} /* add_weight() */

/**
 * This method removes some volume of liquid from the container.
 * Removes equal proportions of all continuous matter.
 * @param vol_lost the amount of volume removed
 * @see add_volume()
 * @see query_volume()
 */
int remove_volume( int vol_lost ) {
    int amt_lost, orig_cv;
    object *contents, thing;

    if( !cont_volume )
        return 0;

    orig_cv = cont_volume;
    contents = filter( INV(TO), (: $1->query_continuous() :) );
    foreach( thing in contents ) {
       amt_lost = -to_int( (int)thing->query_amount() *
                 ( to_float(vol_lost) / orig_cv ) );
       if( !amt_lost)
           amt_lost++;
       thing->adjust_amount( amt_lost );
    }
    return vol_lost;
} /* remove_volume() */

/**
 * This method transfers a given amount of a liquid to a new container.
 * @param dest the destination of the liquid
 * @param vol_xferred the amount of volume transfered
 */
int xfer_volume( int vol_xferred, object dest ) {
    // Transfers equal portions of all continuous matter to dest.
    // If successful, returns 0; if it failed for some reason, it returns
    // the volume not transferred (note that full checks should be done
    // by the caller).
    int vol_to_go, i, amt_xferred, tmp, orig_cv;
    object *contents, copy;
    string file_path;
    mapping map;

    vol_to_go = vol_xferred;
    if( !cont_volume )
        return 0;

    orig_cv = cont_volume;
    contents = filter( INV(TO), (: $1->query_continuous() :) );

    for( i = 0; i < sizeof(contents) && vol_to_go > 0; i++ ) {
        // This should prevent roundoff errors.
        if( i == sizeof(contents) - 1 ) {
            amt_xferred = vol_to_go;
        } else {
            amt_xferred = to_int( (int)contents[i]->query_amount() *
                        ( to_float(vol_xferred) / orig_cv ) );
        }
        if (!amt_xferred) {
            // Always take at least one unit
            amt_xferred++;
        }
        file_path = base_name(contents[i]);
        copy = clone_object(file_path);
        map = (mapping)contents[i]->query_dynamic_auto_load();
        copy->init_dynamic_arg( map );
        map = (mapping)contents[i]->query_static_auto_load();
        if( map )
            copy->init_static_arg( map );
        copy->set_amount(amt_xferred);
        contents[i]->adjust_amount(-amt_xferred);
        if( !tmp = copy->move(dest) ) {
            vol_to_go -= amt_xferred;
        } else {
            copy->dest_me();
        }
    }
    return vol_to_go;
} /* xfer_volume() */

/** @ignore yes */
void heart_beat() {
    // Note that having a leak rate can be expensive, so it should only
    // be done if it's important to the application (such as using it
    // to impose a time restriction).
    int lost, off;

    if( leak_rate == 0 || !is_liquid ) {
        set_heart_beat(0);
        return;
    }
    if( hb_count-- )
        return;
    hb_count = 10;
    lost = leak_rate;
    if( lost > cont_volume )
        lost = cont_volume;
    off = lost/100;
    if( off > 10 )
        off = 10;
    tell_room( ENV(TO), CAP( query_liquid_desc() ) + leak_verb[off]+" out "
               "of the "+short(1)+".\n");
    (void)remove_volume(lost);
    if( !cont_volume )
        set_heart_beat(0);
} /* heart_beat() */

/** @ignore yes */
int do_pour(object *to, mixed *args_b, mixed *args_a, mixed *args) {
    int m, n, volume_needed, their_volume, their_max, ovf;

    if( query_fighting(TP) ) {
        add_failed_mess("You cannot attempt to do this while in combat.\n");
        return 0;
    }
    
    if( ENV(TO) != TP ) {
        add_failed_mess("You aren't carrying $D.\n");
        return 0;
    }
   
    if( sizeof(args) == 5 ) {
        //m = args[1];
        //n = args[2];
        sscanf(args[0] + " " + args[1], "%d %d", m, n);
        if( ( m > n ) || ( m < 0 ) || ( n <= 0 ) ) {
            add_failed_mess("Interesting fraction you have there!\n");
            return 0;
        }
    } else {
        m = 1;
        n = 1;
    }
    
    if( sizeof(to) > 1 ) {
        add_failed_mess("You can only pour the contents of $D into one object "
        "at a time.\n");
        return 0;
    }
    
    if( to[0] == TO ) {
        add_failed_mess("You cannot pour the contents of $D into itself.\n");
        return 0;
    }    
    
    if( query_locked() ) {
        add_failed_mess("$D is locked!\n");
        return 0;
    }
    if( query_closed() ) {
        if( do_open() ) {
            write("You open the " + short(0) + ".\n");
        } else {
            add_failed_mess("You cannot open $D.\n");
            return 0;
        }
    }
    if( cont_volume <= 0 ) {
        add_failed_mess("$D has nothing to pour!\n");
        return 0;
    }
    
    their_volume = (int)to[0]->query_volume();
    their_max = (int)to[0]->query_max_volume();
    if( their_max <= 0 ) {
        TP->add_failed_mess(TO, "$I doesn't look like it can be filled!\n", to);
        return 0;
    }

    if( their_volume >= their_max ) {
        write("The " + to[0]->short(0) + " is full to the brim already.\n");
        their_volume = their_max;
    }
    if( ( m == 1 ) && ( n == 1 ) ) {
        volume_needed = volume;
    } else {
        volume_needed = max_volume * m / n;
    }
    if( volume < volume_needed ) {
        add_failed_mess("$D is less than " + m + "/" + n + " full.\n");
        return 0;
    }
    if( volume_needed > 120 ) {
        // +/- 1 ounce (could make this skill-dependent...)
        volume_needed += random(240) - 120;
    }
    if( volume_needed > ( their_max - their_volume ) ) {
        volume_needed = their_max - their_volume;
        ovf = 1;
    }

    if( volume_needed > cont_volume ) {
        write("You drain the " + short(0) + " into the "
              + to[0]->short(0) + " but it is not enough.\n");
        volume_needed = cont_volume;
        TP->add_succeeded(to[0]);
    } else {
        TP->add_succeeded(to[0]);
    }
    xfer_volume(volume_needed, to[0]);
    if( ovf ) {
        TP->add_succeeded_mess( TO, "$N $V $D into $I, spilling some in the "
            "process.\n", ({to[0]}));
    }
    return 1;
} /* do_pour() */

/** @ignore yes */
int do_fill(object *to, mixed *args_b, mixed *args_a, mixed *args) {
    int m, n, i, run_out, volume_needed, their_volume, their_max,
    amount_not_poured, ok;

    if( query_fighting(TP) ) {
        add_failed_mess("You cannot attempt to do this while in combat.\n");
        return 0;
    }

    // This is to fix an oddity in find_match, where a red bottle is
    // matched by "red bottle 1/2 full".  Otherwise, failed fractional
    // fills get called again as complete fills.
    if( sizeof( regexp(({args[0]}), "/") ) )
        return 0;

    if( sizeof(args) == 4 ) {
        //m = args[1];
        //n = args[2];
        sscanf( args[1] + " " + args[2], "%d %d", m, n );
        if( ( m > n ) || ( m < 0 ) || ( n <= 0 ) ) {
            add_failed_mess("Interesting fraction you have there!\n");
            return 0;
        }
    } else {
        m = 1;
        n = 1;
    }

    if( query_closed() &&  query_locked() ) {
        add_failed_mess("$D is locked!\n");
        return 0;
    }

    if( query_closed() ) {
        if( do_open() ) {
            write("You open the " + short(0) + ".\n");
        } else {
            add_failed_mess("You cannot open $D.\n");
            return 0;
        }
    }

    if( cont_volume <= 0 ) {
        add_failed_mess("$D has nothing to pour!\n");
        return 0;
    }

    run_out = 0;
    for( i = 0; i < sizeof(to) && !run_out; i++ ) {
        if( ENV(TO) != TP && ENV(to[i]) != TP ) {
            write("You're not carrying " + the_short() + " or " +
                  to[i]->the_short() + ".\n");
            continue;
        }

        if( to[i]->query_closed() ) {
            add_failed_mess("$I is closed.\n", to[i..i] );
            continue;
        }

        their_volume = (int)to[i]->query_volume();
        their_max = (int)to[i]->query_max_volume();
        if( their_max <= 0 ) {
            add_failed_mess("$I doesn't look like it can be filled!\n",
                            to[i..i]);
            continue;
        }

        if( their_volume >= their_max ) {
            add_failed_mess("$I is full to the brim already.\n", to[i..i]);
            continue;
        }

        volume_needed = their_max * m / n;
        if( their_volume >= volume_needed ) {
            add_failed_mess("$I is more than " + m + "/" + n +
                  " full already.\n", to[i..i]);
            continue;
        }
        if( volume_needed > 120 ) {
            // +/- 1 ounce (could make this skill-dependent...)
            volume_needed += random(240) - 120;
        }
        if( volume_needed > their_max ) {
            volume_needed = their_max;
        }
        ok++;
        volume_needed -= their_volume;

        if( volume_needed > cont_volume ) {
            write("You drain " + the_short() + " into " +
                  to[i]->the_short() + " but it is not enough.\n");
            volume_needed = cont_volume;
            run_out = 1;
            TP->add_succeeded(to[i]);
        } else {
            TP->add_succeeded(to[i]);
        }
        amount_not_poured = xfer_volume(volume_needed, to[i]);
        if( amount_not_poured ) {
            ok--;
        }
    }
    return ok;
} /* do_fill() */

/**
 * This method checks to see if they are fighting anyone and if anyone
 * (that can see them) is fighting them.
 * @param player the player to check
 */
private int query_fighting(object player) {
   object ob, *tmp;

   if( player->query_fighting() )
       return 1;

   foreach( ob in INV(ENV(player)) ) {
     if( living(ob) ) {
         if( ( tmp = ob->query_attacker_list() ) &&
             member_array( TP, tmp ) != -1 ) {
             return 1;
         }
     }
   }

   if( ENV(ob)->query_mirror_room() ) {
       foreach( ob in INV(ENV(player)->query_mirror_room() ) ) {
         if( living(ob) ) {
             if( ( tmp = ob->query_attacker_list() ) &&
                 member_array( TP, tmp ) != -1 ) {
                 return 1;
             }
         }
       }
   }
} /* query_fighting() */

/* @ignore yes */
void do_damage( string type, int amount ) {
    return ::do_damage( type, ( !query_property("fragile") ? amount :
                        amount * query_property("fragile") / 40 ) );
} /* do_damage() */

/**
 * This method checks to see if the person doing the drinking can hold onto
 * their bottle without loosing it while in combat.  Warning!  This code
 * may be used in other objects to deal with handling drinking while in
 * combat.
 * @return 1 if the bottle is stopped, 0 if it is not
 * @param player the player doing the drinking
 * @param me the object being drunk
 */
int is_fighting_bottle_smashed( object player, object me ) {
   object* fighting;
   object ob;
   object weapon;
   string skill;
   string my_skill;
   int bonus;
   int stopped;

   stopped = 0;

   // See if we are in combat and give a chance to drop the item if we
   // are.  Chance is higher if we have no free hands.
   if (query_fighting(player)) {
      // Ok, we are in combat.  Check out free hands.  The more people
      // we are fighting the harder it is.
      fighting = filter( player->query_attacker_list(),
                      (: ENV($1) == $2 :), ENV(player) );
      if( query_holder() ) {
          bonus = 0;
          bonus += -10 * player->query_free_limbs();
      } else {
          bonus = 20;
      }
      if( sizeof(fighting) )
          bonus += ( sizeof(fighting) - 1 ) * 20;
      if( player->query_free_limbs() < 2 && !query_holder() )
          bonus += 50 - player->query_free_limbs() * 25;

      // Check against the other persons fighting skill.
      foreach( ob in fighting ) {
         // If they are using a weapon use the weapon skill, otherwsie
         // unarmed.
         if( sizeof(ob->query_holding() - ({ 0 })) ) {
             weapon = (ob->query_holding() - ({ 0 }))[0];
             skill = weapon->query_weapon_type();
             if( skill == "mixed" || ( skill != "sharp" &&
                 skill != "blunt" && skill != "pierce" ) ) {
                 skill = ({ "sharp", "blunt", "pierce" })[random(3)];
             }
             skill = "fighting.combat.melee." + skill;
         } else {
             skill = "fighting.combat.melee.unarmed";
         }
         my_skill = "fighting.combat.special.unarmed";
         switch( player->query_combat_response() ) {
         case "parry" :
            my_skill = "fighting.combat.parry.melee";
            break;
         case "dodge" :
            my_skill = "fighting.combat.dodging.melee";
            break;
         case "neutral" :
            my_skill = "fighting.combat."+
                       (({ "parry", "dodging" })[random(2)]) + ".melee";
         }

         switch( TASKER->compare_skills( player, my_skill, ob, skill,
                                         -bonus, TM_FREE, TM_FREE ) ) {
         case OFFAWARD :
            if( player->query_combat_response() == "dodge" ) {
                tell_object( player, "%^YELLOW%^You nimbly dodge an attack "
                    "to avoid getting " + me->poss_short() + " smashed out "
                    "of your hand and feel better about attempting it next "
                    "time.\n%^RESET%^");
            } else {
                tell_object( player, "%^YELLOW%^You nimbly parry an attack "
                    "to avoid getting " + me->poss_short() + " smashed out "
                    "of your hand and feel better about attempting it next "
                    "time.\n%^RESET%^");
            }
         case OFFWIN :
            tell_room( ENV(player), player->the_short() + " avoids getting " +
                me->poss_short() + " smashed by " +
                query_multiple_short(({ ob })) + ".\n", ({ player }) );
            tell_object( player, "You avoid getting " + me->poss_short() +
                " smashed by " + query_multiple_short(({ ob })) + ".\n");
            break;
         case DEFAWARD :
            tell_object( ob, "%^YELLOW%^You feel more able to smash bottles "
                "out of peoples' hands than before.\n%^RESET%^");
         case DEFWIN :
            if( !query_holder() && me->move( ENV(player) ) == MOVE_OK ) {
                tell_room( ENV(player), ob->the_short() + " smashes " +
                    the_short() + " out of " + player->the_short() + "'s "
                    "hands onto the ground causing some of the liquid to "
                    "splash out.\n", ({ player, ob }) );
                /* added message to the attacker */
                tell_object( ob, "You smash " + the_short() + " out of " +
                    player->the_short() + "'s hands onto the ground causing "+
                    "some of the liquid to splash out.\n");
                tell_object( player, ob->the_short() + " smashes " +
                    the_short() + " out of your hands onto the ground "
                    "causing some of the liquid to splash out.\n");
            }
            else {
                tell_room( ENV(player), ob->the_short() + " smashes " +
                    the_short() + " away from " + player->the_short() + "'s "
                    "mouth causing some of the liquid to splash out.\n",
                    ({ player, ob }) );
                /* added message to the attacker */
                tell_object( ob, "You smash " + the_short() + " away from " +
                    player->the_short() + "'s mouth causing some of the " +
                    "liquid to splash out.\n");
                tell_object( player, ob->the_short() + " smashes " +
                    the_short() + " away from your mouth causing some of the "
                    "liquid to splash out.\n");
             }
             stopped = 1;
             break;
         }
         if( stopped )
             break;
      }
   }
   return stopped;
} /* is_fighting_bottle_smashed() */

/**
 * This method drinks a certain amount of the liquid in the container.
 * It will do all the fudging for being in combat and drinking too
 * much, as well as dropping the bottle and so on.
 * @param drinking the amount to drink
 */
int drink_amount( int drinking, object player ) {
   int cap_amount;
   int amt_to_drink;
   int amount_can_be_drunk;
   object* contents;
   object ob;
   int orig_cv;

   amt_to_drink = drinking;

   if( amt_to_drink > cont_volume )
       amt_to_drink = cont_volume;

   cap_amount = ( max_volume / 20 > VOLUME_WINE ? max_volume / 20 : VOLUME_WINE );

   // Ok, now fudge the values around if they are in combat or trying
   // to drink really small amounts.
   if( amt_to_drink < cap_amount ) {
       if( query_fighting(player) ) {
           amt_to_drink += random( 2 * ( cap_amount - amt_to_drink ) ) -
                           cap_amount - amt_to_drink;
           if( amt_to_drink < VOLUME_MINIMUM_DRINKABLE * 2 ) {
               amt_to_drink = VOLUME_MINIMUM_DRINKABLE * 2;
           }
      } else {
           amt_to_drink += random( ( cap_amount - amt_to_drink ) / 6 ) -
                           ( cap_amount - amt_to_drink ) / 12;
      }
   }

   if( amt_to_drink < VOLUME_MINIMUM_DRINKABLE )
       amt_to_drink = VOLUME_MINIMUM_DRINKABLE;

   if( amt_to_drink < (max_volume / 100) )
       amt_to_drink = max_volume / 100;

   amount_can_be_drunk = ( 8000 - (int)TP->query_volume(2) ) *
                                 (int)TP->query_con() / 12;

   /* should do some fudging to add +/- 5 mls or something */
   /* possibly skill/stat dependent */
   if( amt_to_drink > amount_can_be_drunk ) {
       write("You drink some of the liquid, but simply cannot fit it all in.\n");
       amt_to_drink = amount_can_be_drunk;
   }

   if( is_fighting_bottle_smashed( TP, TO ) ) {
      // Ok, now do the spilling if it has been done.
      // Throw out at least as much as they wanted to drink and up to
      // 10 times more.
      amt_to_drink *= ( 1 + random( 15 ) );
      if( amt_to_drink > volume )
          amt_to_drink = volume;

      orig_cv = cont_volume;
      foreach( ob in filter( INV(TO), (: $1->query_continuous() :) ) ) {
        ob->adjust_amount( -( amt_to_drink == cont_volume ? ob->query_amount() :
                              ob->query_amount() * amt_to_drink / orig_cv ) );
      }
      add_succeeded_mess("");
      do_damage( "crush", roll_MdN( 8, 8 ) );
      return 1;
   }

   add_succeeded_mess("$N $V " + query_liquid_desc() + " from $D.\n");

   if( amt_to_drink - drinking > ( max_volume / 40 ) &&
       amt_to_drink - drinking > VOLUME_MINIMUM_DRINKABLE ) {
       add_succeeded_mess( ({ "Whoops!  You seem to have gulped down too "
           "much.\n", "" }) );
   }

   // Call consume() on food objects, I guess ignore the others.
   contents = filter( INV(TO), (: $1->query_continuous() :) );
   orig_cv = cont_volume;
   foreach( ob in contents ) {
     ob->consume( TP, ( amt_to_drink == orig_cv ? ob->query_amount() :
                        ob->query_amount() * amt_to_drink / orig_cv ) );
   }

   return 1;
} /* drink_amount() */

/** @ignore yes */
int do_drink(object *dest, mixed me, mixed him, mixed args, string pattern) {
    int amt_to_drink, m, n;

    if( sizeof(dest) ) {
        add_failed_mess("Drinking is a very simple operation - "
            "please don't complicate matters.\n");
        return 0;
    }
    if( ENV(TO) != TP ) {
        add_failed_mess("You aren't carrying $D.\n");
        return 0;
    }
    if( !ensure_open() ) {
        return 0;
    }
    if( !is_liquid ) {
        add_failed_mess("$D is bone dry!\n");
        return 0;
    }
    // add_command() mucks around with the pattern strings...
    if( pattern == drink_pat[1] ) {
        m = to_int(args[0]);
        n = to_int(args[1]);
        //sscanf(args[0] + " " + args[1], "%d %d", m, n);
        /** Yes, its a kludge. T. **/
        if ( n > 100 ) {
          add_failed_mess( "You can't drink with that much precision!\n" );
          return 0;
        }
        if ((m > n) || (m < 0) || (n <= 0)) {
            add_failed_mess("Interesting fraction you have there!\n");
            return 0;
        }
    } else {
        m = 1;
        n = 1;
    }

    if (_fraction) {
        m = _fraction[0];
        n = _fraction[1];
    }

    if ((m == 1) && (n == 1)) {
        amt_to_drink = cont_volume;
    } else {
        amt_to_drink = (max_volume*m)/n;
        if (amt_to_drink > volume) {
            add_failed_mess("$D is less than " + m + "/" + n +
                  " full.\n");
            return 0;
        }

        if (amt_to_drink > cont_volume) {
            amt_to_drink = cont_volume;
        }
    }

    if (!drink_amount(amt_to_drink, TP)) {
       return 0;
    }

    switch ((TP->query_volume(2) + 100) / 200) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
        break;
      case 5:
        write("You feel mildly full of liquid.\n");
        break;
      case 6:
        write("You feel very full of liquid.\n");
        break;
      case 7:
        write("You feel pissed.\n");
        break;
      case 8:
        write("You are awash with liquid.\n");
        break;
      case 9:
        write("You are full to the brim with liquid.\n");
        break;
      default:
        write("You feel you would burst if you drank any more.\n");
        break;
    }
    return 1;
} /* do_drink() */

/** @ignore yes */
int do_empty(object *dest, string me, string him, string prep) {
   if( ENV(TO) != TP ) {
       add_failed_mess("You are not carrying $D.\n");
       return 0;
   }
   if( sizeof(dest) ) {
       write("Passing on to pour ... bad move.\n");
       //return do_pour(dest, me, him, prep);
   }
   /* this completely fails to work :( ^^^ */

   if (!ensure_open()) {
      add_failed_mess("$D is not open.\n");
      return 0;
   }

   if( cont_volume == 0 && !sizeof(all_inventory() ) ) {
       add_failed_mess("$D is already empty.\n");
       return 0;
   }

   (void)remove_volume(cont_volume);

   // Remove the inventory too.
   INV(TO)->move(ENV(TP));

   /* should check spillage */
   return 1;
} /* do_empty */

/** @ignore yes */
int check_splashable(object ob, object splasher, object splashee) {
    return ob->query_splashable(splasher, splashee);
}

/** @ignore yes */
int do_splash(object *dest, mixed me, mixed him, mixed args, string pattern) {
    int amt_to_splash, i, m, n, orig_cv;
    object *contents;

    if (!sizeof(dest)) {
        add_failed_mess("Splash it on who?\n");
        return 0;
    }
    if(sizeof(dest) >1){
        add_failed_mess("You may only splash one person at a time.\n");
        return 0;
    }
    if (environment(TO) != TP) {
        write("You aren't carrying the " + short(0) + ".\n");
        return 0;
    }
    if (!ensure_open())
        return 0;
    if (!is_liquid) {
        write("The " + short(0) + " is bone dry!\n");
        return 0;
    }

    // add_command() mucks around with the pattern strings...
    if (pattern == splash_pat[1]) {
        m = to_int(args[0]);
        n = to_int(args[1]);
        if ((m > n) || (m < 0) || (n <= 0)) {
            notify_fail("Interesting fraction you have there!\n");
            return 0;
        }
    } else {
        m = 1;
        n = 1;
    }
    contents = filter( INV(TO), (:check_splashable:), TP, dest[0] );
    if( !sizeof(contents) ){
       add_failed_mess("You can't splash anything in $D.\n");
    }
    orig_cv = cont_volume;
    if ( m == n ){
        amt_to_splash = cont_volume;
    } else {
        amt_to_splash = (max_volume*m)/n;
        if (amt_to_splash > volume) {
            write("The " + short(0) + " is less than " + m + "/" + n +
                  " full.\n");
            return 0;
        }
        if (amt_to_splash > cont_volume) {
            amt_to_splash = cont_volume;
        }
    }
    if(TP == dest[0]){
       TP->add_succeeded_mess(TO,
                     "$N $V " + query_multiple_short(contents) +
                     " from $D onto "+TP->query_objective()+"self.\n", ({}));
    }else{
       TP->add_succeeded_mess(TO,
                     "$N $V " + query_multiple_short(contents) +
                     " from $D onto $I.\n", dest);
    }
    // Call consume() on food objects, I guess ignore the others.
    for (i = 0; i < sizeof(contents); i++) {
        if (amt_to_splash == cont_volume) {
           contents[i]->consume(dest[0],
           contents[i]->query_amount(), "splash");
        } else {
           // Consume proportionate amounts of all food.
           contents[i]->consume(dest[0],
              (int)contents[i]->query_amount()
              * amt_to_splash / orig_cv, "splash");
        }
    }
    return 1;
} /* do_splash() */

/**
 * @ignore yes
 */
int check_applicable(object ob, object applier, object appliee) {
  return ob->query_applicable(applier, appliee);
}


/** @ignore yes */
int do_rub(object *dest, mixed me, mixed him, mixed args, string pattern) {
    int amt_to_apply, i, m, n, orig_cv;
    object *contents;

    if (!sizeof(dest)) {
        add_failed_mess("Rub it on who?\n");
        return 0;
    }
    if(sizeof(dest) >1){
        add_failed_mess("You may only rub stuff on one person at a time.\n");
        return 0;
    }
    if (environment(TO) != TP) {
        write("You aren't carrying the " + short(0) + ".\n");
        return 0;
    }
    if (!ensure_open()) return 0;
    if (!is_liquid) {
        write("The " + short(0) + " is bone dry!\n");
        return 0;
    }

    // add_command() mucks around with the pattern strings...
    if (pattern == apply_pat[1]) {
        m = to_int(args[0]);
        n = to_int(args[1]);
        if ((m > n) || (m < 0) || (n <= 0)) {
            notify_fail("Interesting fraction you have there!\n");
            return 0;
        }
    } else {
        m = 1;
        n = 1;
    }
    contents = filter( all_inventory(TO), (:check_applicable:),
        TP, dest[0]);
    if( !sizeof(contents) ){
       add_failed_mess("You can't rub anything in $D on $I.\n",dest);
    }
    orig_cv = cont_volume;
    if ( m == n ){
        amt_to_apply = cont_volume;
    } else {
        amt_to_apply = (max_volume*m)/n;
        if (amt_to_apply > volume) {
            write("The " + short(0) + " is less than " + m + "/" + n +
                  " full.\n");
            return 0;
        }
        if (amt_to_apply > cont_volume) {
            amt_to_apply = cont_volume;
        }
    }
    if(TP == dest[0]){
       TP->add_succeeded_mess(TO,
                     "$N $V " + query_multiple_short(contents) +
                     " from $D onto "+TP->query_objective()+"self.\n", ({}));
    }else{
       TP->add_succeeded_mess(TO,
                     "$N $V " + query_multiple_short(contents) +
                     " from $D onto $I.\n", dest);
    }
    // Call consume() on food objects, I guess ignore the others.
    for (i = 0; i < sizeof(contents); i++) {
        if (amt_to_apply == cont_volume) {
           contents[i]->consume(dest[0],
                          contents[i]->query_amount(),"apply");
        } else {
           // Consume proportionate amounts of all food.
           contents[i]->consume(dest[0],
              (int)contents[i]->query_amount()
              * amt_to_apply / orig_cv, "apply");
        }
    }
    return 1;
} /* do_rub() */

/** @ignore yes */
int do_apply(object *dest, mixed me, mixed him, mixed args, string pattern){
   return do_rub(dest, me, him, args, pattern);
} /* do_apply() */

/** @ignore yes */
int do_taste() {
    int amount_tasted;
    /* be kind to tasters! */

    if (environment(TO) != TP) {
        write("You aren't carrying the " + short(0) + ".\n");
        return 0;
    }
    if (!ensure_open()) {
       return 0;
    }
    if (!cont_volume || !is_liquid) {
        write("The " + short(0) + " is bone dry!\n");
        return 0;
    }

    //
    // Put code here to give description of contents' taste.
    //
    amount_tasted = VOLUME_SHOT;
    if (cont_volume < amount_tasted) {
        amount_tasted = cont_volume;
    }

    if (amount_tasted < max_volume / 100) {
       amount_tasted = max_volume / 100;
    }

    return drink_amount(amount_tasted, TP);
} /* do_taste() */

/** @ignore yes */
int do_sip() {
    int amount_tasted;
    /* be kind to tasters! */

    if (environment(TO) != TP) {
        write("You aren't carrying the " + short(0) + ".\n");
        return 0;
    }
    if (!ensure_open()) {
       return 0;
    }
    if (!cont_volume || !is_liquid) {
        write("The " + short(0) + " is bone dry!\n");
        return 0;
    }

    //
    // Put code here to give description of contents' taste.
    //
    amount_tasted = VOLUME_SHOT * 2;
    if (cont_volume < amount_tasted) {
        amount_tasted = cont_volume;
    }

    if (amount_tasted < max_volume / 70) {
       amount_tasted = max_volume / 70;
    }

    return drink_amount(amount_tasted, TP);
} /* do_sip() */

/** @ignore yes */
int do_smell() {
    /* be kind to smellers! */

    if (!ensure_open()) {
       return 0;
    }

    // Put code here to give description of contents' smell.
    write("Smelling isn't implemented yet.  Sorry.\n");

    // Put code here to handle effects of smelling contents.
    return 1;
} /* do_smell() */

/** @ignore yes */
mapping int_query_static_auto_load() {
  mapping tmp;

  tmp = ::int_query_static_auto_load();
  return ([ "::" : tmp, "leak rate" : leak_rate,
           "max volume" : max_volume,
          ]);
} /* int_query_static_auto_load() */

/** @ignore yes */
mapping query_static_auto_load() {
  if ( !query_name() || ( query_name() == "object" ) ) {
    return 0;
  }
  if ( explode( file_name( TO ), "#" )[ 0 ] == "/obj/vessel" ) {
    return int_query_static_auto_load();
  }
  return ([ ]);
} /* query_static_auto_load() */

/** @ignore yes */
void init_static_arg(mapping args) {
  if (args["::"])
    ::init_static_arg(args["::"]);
  if (!undefinedp(args["leak rate"]))
    leak_rate = args["leak rate"];
  if (!undefinedp(args["max volume"]))
    max_volume = args["max volume"];
} /* init_static_arg() */

/*
 * Added so you cant get things in or out of a close container.
 */
/** @ignore yes */
int test_add(object ob, int flag) {
    int new_vol;

    if ( !::test_add( ob, flag ) )
        return 0;
    if (ob->query_continuous()) {
        new_vol = ob->query_amount();
    } else if (ob->query_property("density")) {
        // A hook for later use (maybe :)
        new_vol = (int)ob->query_weight()*(int)ob->query_property("density");
    } else {
        // Density is nominally that of water
        //new_vol = (int)ob->query_weight()*200;
        // The above is essentially correct.  However, through some odd
        // sequence of events, the weight (and hence, the calculated volume)
        // get added before this function.  So new_vol should be 0 here.
        new_vol = 0;
    }
    if ((new_vol + volume) > max_volume) {
        //write("Failed: new_vol = " + new_vol + ", volume = " + volume +
        //      ", max_volume = " + max_volume + "\n");
        return 0;
    }
    return 1;
} /* test_add() */

/** @ignore yes */
void event_enter(object ob, string message, object from) {
    int ob_vol, ob_cont;

    if (environment(ob) == TO) {
        // Adjust volume
        if (ob->query_continuous()) {
            ob_vol = ob->query_amount();
            ob_cont = 1;
            is_liquid = is_liquid || ob->query_liquid();
        } else if (ob->query_property("density")) {
            // A hook for later use (maybe :)
            ob_vol = (int)ob->query_weight()*
              (int)ob->query_property("density");
        } else {
            // Density is nominally that of water
            //ob_vol = (int)ob->query_weight()*200;
            // The above is essentially correct.  However, through some odd
            // sequence of events, the weight (and hence the calculated volume)
            // get added before this function.  So ob_vol should be 0 here.
            ob_vol = 0;
        }
        //write("Increasing volume by " + ob_vol + "(event_enter)\n");
        volume += ob_vol;
        if (ob_cont) cont_volume += ob_vol;
        // Check for reactions
        REACTION_HANDLER->check_reaction(ob);
        if (leak_rate > 0) {
            set_heart_beat(1);
        }
    }
} /* event_enter() */

/** @ignore yes */
void event_exit(object ob, string mess, object to) {
    int ob_vol, ob_cont;

    if (environment(ob) == TO) {
        // Adjust volume
        if (ob->query_continuous()) {
            ob_vol = ob->query_amount();
            ob_cont = 1;
        } else if (ob->query_property("density")) {
            // A hook for later use (maybe :)
            ob_vol = (int)ob->query_weight()*
              (int)ob->query_property("density");
        } else {
            // Density is nominally that of water
            //ob_vol = (int)ob->query_weight()*200;
            // The above is essentially correct.  However, through some odd
            // sequence of events, the weight (and hence the calculated volume)
            // get added before this function.  So ob_vol should be 0 here.
            ob_vol = 0;
        }
        volume -= ob_vol;
        if (ob_cont) cont_volume -= ob_vol;
        if (volume <= 0) is_liquid = 0;
    }
} /* event_exit() */

/** @ignore yes */
void break_me() {
  object *liquid, liv;

  // Dest all the liquid...
  liquid = filter( INV(TO), (: $1->query_liquid() :) );
  if( sizeof(liquid) ) {
      if( living( liv = ENV(TO) ) ) {
          tell_object( liv, query_multiple_short(liquid) + " splashes "
              "all over the place as your " + short(0)+" breaks!\n");
          tell_room( ENV(liv), query_multiple_short(liquid) + " splashes "
              "all over the place as " + (string)liv->the_short()+"'s " +
              short(0) + " breaks!\n", liv );
      } else {
          tell_room( ENV(TO), query_multiple_short(liquid) + " splashes "
              "all over the place as " + the_short()+" breaks!\n");
      }
      liquid->move("/room/rubbish");
  }
  ::break_me();
} /* break_me() */

/** @ignore yes */
mixed* parse_match_object(string* input, object player,
                          class obj_match_context context) {
   int result;

   result = ::is_matching_object(input, player, context);
   if( result ) {
       _fraction = context->fraction;
       if( update_parse_match_context( context, 1, result ) )
           return ({ result, ({ TO }) });
   }
   return 0;
} /* parse_match_object() */
