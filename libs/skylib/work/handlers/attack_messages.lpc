/**
 * This handles the standard messages for the given damage types:
 *    blunt, sharp, pierce, fire.
 *
 * There are also subtypes:
 *    blunt - hands, feet, tail, hoof, wrestle, bash (pommel), pound.
 *    sharp - claws, chew, slice, chop.
 *    pierce - bite, beak, stab, horns, tusks.
 * @author pinkfish
 * @changed Changed to use the new format.
 * - Sandoz, 04th August 2001.
 */

#define __MESSAGE_DATA_CLASS__
#include <combat.h>

mapping weapon_mess;

/** @ignore yes */
mapping query_weapon_mess() { return copy(weapon_mess); }

/** @ignore */
void create() {
    weapon_mess = ([
      "blunt" : ({
         25, "$N tap$s $I with $D",
         75, "$N hit$s $I with $D",
        125, "$N bruise$s $I with $D",
        200, "$N hit$s $I hard with $D",
        275, "$N smash$s $D into $I",
        350, "$N crush$s $I with $D",
          0, "$N mash$s $I with $D",
        }),
      "blunt-pound" : ({
         25, "$N tap$s $I with $D",
         75, "$N hit$s $I with $D",
        125, "$N crunch$s $I with $D",
        200, "$N fracture$s $I with $D",
        275, "$N mangle$s $I with $D",
        350, "$N shatter$s $I with $D",
          0, "$N obliterate$s $I with $D",
        }),
      "blunt-tail" : ({
         25, "$N tap$s $I with $p tail",
         75, "$N slap$s $I with $p tail",
        125, "$N bruise$s $I with $p tail",
        200, "$N hit$s $I hard with $p tail",
        275, "$N bash$s $I with $p tail",
        350, "$N smash$s $p tail into $I",
          0, "$N send$s $I reeling with a powerful blow to the $P from $p tail",
        }),
      "blunt-hoof" : ({
         25, "$N tap$s $I with $p hoof",
         75, "$N kick$s $I with $p hoof",
        125, "$N bruise$s $I with $p hoof",
        200, "$N hit$s $I hard with $p hoof",
        275, "$N smash$s $I with $p hoof",
        350, "$N crush$s $I with $p hoof",
          0, "$N mash$s $I with $p hoof",
        }),
      "blunt-wrestle" : ({ // These ones are broken.
         25, "$N grapple$s with $I",
         50, "$N catch$s $I in an arm lock",
         75, "$N grab$s $I around the neck",
        100, "$N poke$s $I in the face",
        125, "$N throw$s $I to the ground",
        150, "$N fling$s $I over $p shoulder",
        175, "$N punch$s $I in the stomach",
        200, "$N twist$s $I's arm painfully",
        225, "$N thump$s $I's head hard",
        250, "$N kick$s $I in the back",
        275, "$N jump$s up and down on $I",
          0, "$N slam$s $I's head against the ground",
        }),
      "blunt-hands" : ({
         25, "$N poke$s $I in the $P",
         75, "$N tickle$s $I",
        125, "$N punch$s $I in the $P",
        200, "$N elbow$s $I in the $P",
        275, "$N jab$s $I in the $P",
        350, "$N viciously hook$s $I in the $P",
          0, "$N beat$s $I to a pulp",
        }),
      "blunt-feet" : ({
         25, "$N poke$s $I in the $P with $p toes",
         75, "$N tickle$s $I with $p toes",
        125, "$N kick$s $I in the $P lightly",
        200, "$N kick$s $I in the $P",
        275, "$N viciously boot$s $I in the $P",
        350, "$N viciously kick$s $I in the $P",
          0, "$N kick$s $I into a bloody mess",
        }),
      "blunt-bash": ({
         25, "$N tap$s $I with the $H of $D",
         75, "$N knock$s $I with the $H of $D",
        125, "$N bruise$s $I with the $H of $D",
        200, "$N beat$s $I hard with the $H of $D",
        275, "$N bash$s $I with the $H of $D",
        350, "$N smash$s the $H of $D into $I",
          0, "$N mash$s $I with the $H of $D",
        }),
      "sharp" : ({
         25, "$N snick$s $I with $D",
         75, "$N scratch$s $I with $D",
        125, "$N hack$s lightly into $I with $D",
        200, "$N cut$s $I with $D",
        275, "$N hack$s deeply into $I with $D",
        350, "$N mount$s $D in $I with a mighty hack",
          0, "$N cut$s $I into small pieces with $D",
        }),
      "sharp-chop": ({
         25, "$N just manage$s to chop $D into $I",
         75, "$N nick$s $I with $D",
        125, "$N chop$s $D lightly into $I",
        200, "$N chop$s $D into $I",
        275, "$N chop$s $D deeply into $I",
        350, "$N mount$s $D in $I with a mighty chop",
          0, "$N chop$s $I into pieces with $D",
        }),
      "sharp-slash" : ({
         25, "$N snick$s $I with $D",
         75, "$N scratch$s $I with $D",
        125, "$N nick$s $I with $D",
        200, "$N cut$s $I with $D",
        275, "$N slash$s $I with $D",
        350, "$N slash$s a long wound into $I with $D",
          0, "$N cut$s $I open with a mighty slash from $D",
        }),
      "sharp-slice": ({
         25, "$N just manage$s to slice $I with $D",
         75, "$N slice$s $D across $I",
        125, "$N shred$s $I with $D",
        200, "$N slice$s $D into $I",
        275, "$N take$s a sliver off $I with $D",
        350, "$N slice$s $D deeply into $I",
          0, "$N neatly fillet$s $I with $D",
        }),
      "sharp-claws" : ({
         25, "$N snick$s $I with $p claws",
         75, "$N scratch$s $I with $p claws",
        125, "$N nick$s $I with $p claws",
        200, "$N claw$s $I",
        275, "$N slice$s $I up with $p claws",
        350, "$N hack$s $I up with $p claws",
          0, "$N cut$s $I into small pieces with $p claws",
        }),
      "sharp-chew" : ({
         25, "$N nip$s $I lightly",
         75, "$N bite$s $I",
        125, "$N gash$s $I with $p teeth",
        200, "$N rip$s flesh off of $I",
        275, "$N tear$s deep into $I with $p teeth",
        350, "$N rip$s $I to pieces with $p teeth",
          0, "$N crunch$s $I with $p teeth and splatter$s blood everywhere",
        }),
      "pierce": ({
         25, "$N barely hit$s $I with $D",
         75, "$N jab$s $D into $I",
        125, "$N pierce$s $I with $D",
        200, "$N impale$s $I on $D",
        275, "$N skewer$s $I with $D",
        350, "$N run$s $I through the $P with $D",
          0, "$N make$s a kebab of $I with $D",
        }),
      "pierce-beak" : ({
         25, "$N snick$s $I",
         75, "$N scratch$s $I with $p beak",
        125, "$N peck$s $I",
        200, "$N viciously peck$s $I",
        275, "$N gouge$s a hole in $I with $p beak",
        350, "$N slice$s $I up with $p beak",
          0, "$N slice$s $I into small bits with $p beak",
        }),
      "pierce-stab": ({
         25, "$N barely stab$s $I in the $P with $D",
         75, "$N stab$s $I in the $P with $D",
        125, "$N messily stab$s $I in the $P with $D",
        200, "$N stab$s $I deeply in the $P with $D",
        275, "$N perforate$s $I with $D",
        350, "$N stab$s $I again and again with $D",
          0, "$N stab$s $D right through $I",
        }),
      "pierce-horns": ({
         25, "$N prod$s $I with $p horns",
         75, "$N poke$s $I with $p horns",
        125, "$N butt$s $I with $p horns",
        200, "$N pierce$s $I deeply with $p horns",
        275, "$N ram$s $I with $p horns",
        350, "$N gore$s $I with $p horns",
          0, "$N impale$s $I on $p horns",
        }),
      "pierce-tusks": ({
         25, "$N prod$s $I with $p tusks",
         75, "$N poke$s $I with $p tusks",
        125, "$N jab$s $p tusks into $I",
        200, "$N pierce$s $I with $p tusks",
        275, "$N stab$s $p tusks deeply into $I",
        350, "$N gore$s $I with $p tusks",
          0, "$N impale$s $I on $p tusks",
        }),
      "pierce-bite" : ({
         25, "$N nip$s $I",
         75, "$N nibble$s at $I",
        125, "$N bite$s $I",
        200, "$N sink$s $p teeth into $I",
        275, "$N bite$s through $I",
        350, "$N sink$s $p teeth deep into $I",
          0, "$N bite$s deep into $I and splinter$s the bones",
        }),
      "fire" : ({
         20, "$N smoke$s $I",
         60, "$N toast$s $I",
        100, "$N scorch$s $I",
        140, "$N crisp$s $I",
        180, "$N singe$s $I",
        220, "$N fry$s $I",
        260, "$N roast$s $I",
        300, "$N melt$s $I",
        340, "$N char$s $I",
        380, "$N burn$s $I",
        420, "$N incinerate$s $I",
        460, "$N cremate$s $I",
          0, "$N vapourise$s $I",
        })
    ]);

} /* create() */

/** @ignore yes */
string parse_verb( string message, int me ) {
    string stuff, part1, verb, part2;

    stuff = "";

    while( sscanf( message, "%s %s$s%s", part1, verb, part2 ) == 3 ) {
        stuff += part1+" "+( me ? verb : pluralize( verb ) );
        message = part2;
    }

    return stuff + message;

} /* parse_verb() */

/**
 * This method gets the attack messages for the weapon attacks.
 * If an attack with the specified name doesn't exist in the
 * weapon, it will look for the message in the handler.
 * @param dam the damage of the attack
 * @param type the attack type ( either sharp, pierce or blunt )
 * @param him the target of the attack
 * @param me the attacker
 * @param name the attack name
 * @param wep the weapon attacked with
 * @return a class of three elements - attacker, defender and others
 */
class message_data query_message( int dam, string type, object him, object me,
                                  string name, object wep, string area ) {
    int i, sz;
    mixed ind;
    class message_data ret;

    if( !( ind = wep->query_attack_message( name, type ) ) &&
        !( ind = weapon_mess[type+"-"+name] ) &&
        !( ind = weapon_mess[type] ) )
        return 0;

    sz = sizeof(ind);

    // Find the correct message.
    while( i < sz && dam > ind[i] )
        i += 2;

    if( i >= sz )
        i = sz - 2;

    ind = ind[i+1];

    ret = new( class message_data );

    if( stringp(ind) ) {
        string pre, post;
        int flag;

        // Right, if $P is used, then use just one/the_short() for $I, if not,
        // then $I will be poss_short()+" "+area.
        // Have to use sscanf here, methinks.
        // Assume there is only one $P.
        // - Sandoz.
        if( sscanf( ind, "%s$P%s", pre, post ) == 2 ) {
            ind = pre + area + post;
            flag = 1;
        } else {
            area = him->poss_short()+" "+area;
        }

        ind = replace( ind, ({
            "$N", me->one_short(),
            "$D", wep->poss_short(),
            "$H", wep->query_hilt(),
        }) );

        ret->attacker = replace( parse_verb( ind, 1 ), ({
            "$p ", "your ",
            "$r",  "you",
            "$o ", "your ",
            "$I",  flag ? him->the_short() : area,
            }) );

        ret->defender = ret->others = replace( parse_verb( ind, 0 ), ({
            "$p ", me->HIS+" ",
            "$r",  me->HE,
            "$o ", me->HIM+" ",
            "$I",  flag ? him->one_short() : area,
            }) );

        return ret;
    }

    ret->attacker = ret->defender = ret->others = wep->poss_short()+" seems "
        "to have bad attack messages, please report it";

    return ret;

} /* query_message() */
