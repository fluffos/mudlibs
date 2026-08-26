/**
 * Replacement consider command. This one takes weapons, skills, armour and hit
 * points into account whereas the old one only compared their overall fighting
 * skill.
 * @changed Changed to be more skill vs skill.
 * Also added a check for just-cloned NPCs to reset their stats etc.,
 * if needed.
 * - Sandoz, June 2003.
 */

#include <combat.h>
#include <weapon.h>
#include <player.h>

inherit COMMAND_BASE;

private int hps;

int calc_danger( object ob, int melee, int defensive, int flag );
string do_compare( int dif, object o );

/**
 * @ignore yes
 * Right, this is why we do this.
 * Since NPCs skills and stats are properly set only after a
 * couple of seconds from cloning them, we want to know when
 * to call reset_all2() on them, which will force a reset on
 * their skills and stats, hopefully giving them the hps etc.,
 * that they are intended to have.
 * To know whether they have already reset their stats, we
 * compare their current hit points to those of the basic
 * NPC object's.  If they match, it is 99.9% likely that they
 * have not been reset. (At this point of time the NPC object
 * has 10000 hps by default).
 * - Sandoz.
 */
private void create() {
    hps = NPC_OBJ->query_hp();
} /* create() */

/** @ignore yes */
int cmd( object *obs ) {
    object ob, *weapons;
    int i, level, ok, dif, them, dskill, wskill;
    mixed data;

    if( TP->query_property("dead") ) {
        add_failed_mess("You're dead.  You could just about kill a "
            "conversation.\n");
        return 0;
    }

    if( sizeof(obs) > 1 )
        obs -= ({ TP });

    if( sizeof(obs) > 5 ) {
        add_failed_mess("You can only consider 5 things at once.\n");
        return 0;
    }

    switch( TP->check_dark( ENV(TP)->query_light() ) ) {
      case -2..-1 :
        add_failed_mess("It's too dark to consider anyone.\n");
        return 0;
      case 1..2 :
        add_failed_mess("It's too bright to consider anyone.\n");
        return 0;
      default :
    }

    // Decide which weapon to use for the consider.
    if( sizeof( weapons = TP->query_weapons() - ({ 0 }) ) ) {
        ob = choice( weapons );
        dskill = TP->query_skill_bonus("fighting.combat.parry.melee");
    } else {
        ob = TP;
        dskill = TP->query_skill_bonus("fighting.combat.special.unarmed");
    }

    // Count parry *and* dodge skill because they might change tactics
    // partway through any combat.
    dskill += TP->query_skill_bonus("fighting.combat.dodging.melee");

    // Make it the average of parry and dodge.
    dskill /= 2;

    // Our offensive skills.
    if( !sizeof( data = ob->query_attack_data() ) ) {
        wskill += TP->query_skill_bonus("fighting.combat.melee.unarmed");
    } else {
        for( i = 0; i < sizeof(data); i += W_ARRAY_SIZE )
            wskill += TP->query_skill_bonus( MELEE + data[ i + W_SKILL ] );
        wskill /= sizeof(data) / W_ARRAY_SIZE;
    }

    level = calc_danger( TP, 0, 0, 0 );

    foreach( ob in obs ) {
        if( !living(ob) )
            continue;

        if(ob->query_name() == "death"){
          tell_object(TP,"Look, be honest. What makes you think you can "
             "harm death?\n");
          continue; 
        }

        if( ob == TP ) {
            if( sizeof(obs) == 1 ) {
                write("You are exactly equal to yourself, you had better go "
                    "and arm yourself with more spikey things and try to not "
                    "arm your reflection at the same time.  No problems?\n");
                ok++;
            }
            continue;
        }

        ok++;
        them = calc_danger( ob, wskill, dskill, 1 );

        // Percentage difference.
        dif = ( level - them ) * 100 / level;

        write( do_compare( dif, ob )+"\n");

        if( userp(ob) )
            tell_object( ob, TP->the_short()+" looks you up and down "
                "carefully checking out your weapons and armour.\n");
    }

    if( !ok ) {
        add_failed_mess("You need to consider someone.\n");
        return 0;
    }

    return 1;

} /* cmd() */

/** @ignore yes */
string do_compare( int dif, object o ) {
    string ret;

    ret = "$C$$who$";

    if( dif > 320 ) {
        ret = "%^BOLD%^GREEN%^"+ret+" is too weak to bother attacking";
    } else {
        switch( dif ) {
          case 161..320:
            ret = "%^BOLD%^%^GREEN%^"+ret+" is someone you look down on";
          break;
          case 81..160:
            ret = "%^GREEN%^"+ret+" would be an easy target";
          break;
          case 41..80:
            ret = "%^GREEN%^"+ret+" is a lot weaker than you are";
          break;
          case 21..40:
            ret = "%^GREEN%^"+ret+" is weaker than you are";
          break;
          case 11..20:
            ret = "%^CYAN%^"+ret+" is slightly weaker than you are";
          break;
          case -10..10:
            ret = "%^CYAN%^"+ret+" is about equal with you";
          break;
          case -20..-11:
            ret = "%^CYAN%^"+ret+" is slightly tougher than you are";
          break;
          case -40..-21:
            ret = "%^RED%^"+ret+" is tougher than you";
          break;
          case -80..-41:
            ret = "%^RED%^"+ret+" is a lot tougher than you";
          break;
          case -160..-81:
            ret = "%^RED%^"+ret+" looks pretty nasty";
          break;
          case -320..-161:
            ret = "%^BOLD%^%^RED%^"+ret+" is into the don't-think-about-it "
                  "region";
          break;
          default:
            ret = "%^BOLD%^%^RED%^You would have to be utterly insane to "
                  "attack $who$";
        }
    }

    if( userp(o) && TP->query_property(PKER) && !o->query_property(PKER) )
        ret = replace_string( ret, "$who$", o->the_short()+" [not a killer]");
    else
        ret = replace_string( ret, "$who$", o->the_short() );

    return ret + ".%^RESET%^";

} /* do_compare() */

/** @ignore yes */
int calc_weapon_damage( object weapon ) {
    mixed *data;
    int wdam, *damage, i;

    if( sizeof( data = weapon->query_attack_data() ) ) {
        wdam = 0;

        for( i = 0; i < sizeof(data); i += W_ARRAY_SIZE ) {
            if( member_array( data[ i + W_TYPE ], ({"blunt", "unarmed",
                "sharp", "pierce"}) ) == -1 )
                continue;

            damage = data[i+W_DAMAGE];
            wdam += ( data[i+W_CHANCE] * ( damage[F_FIXED] +
                    ( damage[F_NUM] * damage[F_DIE] ) / 2 ) ) / 100;
            wdam += damage[F_FIXED] + damage[F_NUM] * damage[F_DIE];
        }
    }

    return wdam;

} /* calc_weapon_damage() */

/** @calc_value() */
int calc_value( mixed arr ) {
    if( intp(arr) )
        return arr;

    if( !pointerp(arr) )
        return 0;

    switch( sizeof(arr) ) {
      case 1 :
        return arr[F_FIXED];
      case 2 :
        return arr[F_FIXED] + arr[F_NUM];
      default :
        return arr[F_FIXED] + arr[F_NUM] * arr[F_DIE];
    }

} /* calc_value() */

/** @ignore yes */
int calc_armour_protection( object armour ) {
    int ac, i;
    mapping data;
    mixed stuff;

    if( !armour->query_armour() )
        return 0;

    data = armour->query_armour_class();
    if( !sizeof(data) )
        return 0;

    stuff = keys(data);
    for( i = 0; i < sizeof(stuff); i++ )
        ac += calc_value( data[stuff[i]][0] );

    return ac;

} /* calc_armour_protection() */

/**
 * @ignore yes
 * This method calculates how dangerous a creature is.
 * Factors used include: weapon damage, weapon skill, defensive skill,
 * armour worn and hit points.
 */
int calc_danger( object ob, int melee, int defensive, int flag ) {
    object weapon, *obs, armour, rider;
    int wdam, wskill, dskill, ac, hp, trans, i;
    mixed data;

    if( ob->query_hps() == hps )
        ob->reset_all2();

    if( ob->query_transport() )
        foreach( rider in ob->query_riders() )
            trans += calc_danger( rider, melee, defensive, flag );

    // Decide which weapon to use for the consider.
    if( sizeof( obs = ob->query_weapons() - ({ 0 }) ) ) {
        weapon = choice( obs );
        dskill = ob->query_skill_bonus("fighting.combat.parry.melee");
    } else {
        weapon = ob;
        dskill = ob->query_skill_bonus("fighting.combat.special.unarmed");
    }

    // Count parry *and* dodge skill because they might change tactics
    // partway through any combat.
    dskill += ob->query_skill_bonus("fighting.combat.dodging.melee");

    // Make it the average of parry and dodge.
    dskill /= 2;

    wdam = calc_weapon_damage(weapon);

    if( !sizeof( data = weapon->query_attack_data() ) ) {
        wskill += ob->query_skill_bonus("fighting.combat.melee.unarmed");
    } else {
        for( i = 0; i < sizeof(data); i += W_ARRAY_SIZE )
            wskill += ob->query_skill_bonus( MELEE + data[ i + W_SKILL ] );
        wskill /= sizeof(data) / W_ARRAY_SIZE;
    }

    // Test against the defensive of the considerer.
    if( flag )
        wskill += wskill - defensive;

    // Test against the melee skills of the considerer.
    if( flag )
        dskill += dskill - melee;

    hp = ob->query_hp();

    if( sizeof( obs = ob->query_wearing() - ({ 0 }) ) ) {
        foreach( armour in obs )
            ac += calc_armour_protection(armour);
        ac /= sizeof(obs);
    }

    // The weighting of the different statistics.
    wdam /= 3;
    hp /= 3;
    wskill = 2 * wskill;

    event( TP, "inform", sprintf("%s: wdam: %i, hp: %i, wskill: %i, "
        "dskill: %i, ac: %i, total: %i", ob->short(), wdam, hp, wskill,
        dskill, ac, wdam + wskill + dskill + ac + hp ), "debug");

    return trans + wdam + wskill + dskill + ac + hp;

} /* calc_danger() */

/** @ignore yes */
mixed query_patterns() {
    return ({"<indirect:living:here>", (: cmd($1) :) });
} /* query_patterns() */
