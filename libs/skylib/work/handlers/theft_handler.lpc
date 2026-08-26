/**
 * Theft Handler
 * @author Shaydz
 * Started - 7/05/2001 7:35PM
 * @change Added some Calarien specific things - Sandoz, May 2002.
 */

#include <crime.h>

/** @ignore yes */
void make_guard( object thief, object shop ) {
    object guard;

    if( !objectp( thief ) || !objectp( shop ) )
        return;

    guard = "/d/calarien/inherits/hospital"->make_monster("city_guard");
    guard->add_move_zone(({ "Calarien", "guardhouse" }) );
    guard->stop_wander();
    guard->move( shop, "$N charge$s in.");
    guard->init_command("emote looks around worriedly.", 2 );

    if( ENV( thief ) == shop ) {
        guard->init_command("sayto "+thief->query_name()+" You!", 3 );
        guard->init_command("follow "+thief->query_name(), 4 );
    } else {
        guard->init_command("'Where's the villain?", 3 );
        guard->init_command("shake", 4 );
    }

    call_out("do_arrest", 4, guard, thief, shop );

} /* make_guard() */

/** @ignore yes */
void kill_guard( object guard ) {
    if( !objectp( guard ) )
        return;

    guard->move("/room/rubbish", "$N desire$s to be dested.",
                "$N hurry$s back towards the guardhouse.");

} /* kill_guard() */

/** @ignore yes */
void do_arrest( object guard, object thief, object shop ) {
    if( !objectp( guard ) )
        return;

// Why the hell would the guard not arrest you just because you have left the shop.

/*    if( objectp(thief) && objectp(shop) &&
        ENV(thief) == shop && ENV(guard) == shop ) {
        guard->do_arrest( thief );
        return;
    }
*/
    if( objectp(thief)) {
        guard->do_arrest( thief );
        return;
    }
    guard->do_wander();

    return;
//    kill_guard( guard );

} /* do_arrest() */

/** @ignore yes */
object create_mercenary() {
    object ob;
    int i;

    ob = clone_object(NPC_OBJ);
    ob->set_name("mercenary");
    ob->set_short("mercenary");
    i = random(100) + 1;
    ob->basic_setup("human", 400 + i, 1 );
    ob->set_death_xp(0);
    ob->set_long("This is a large, brutish looking mercenary.  He looks "
        "quite competent and capable of mashing you with or without a "
        "weapon.\n");

    ob->set_str( 18 + random( 4 ) );
    ob->set_dex( 14 + random( 4 ) );
    ob->set_con( 14 + random( 4 ) );
    ob->set_int( 8 + random( 4 ) );
    ob->set_wis( 8 + random( 4 ) );

    ob->add_skill_level("fighting", 400 + i );
    ob->add_skill_level("general.health", 200 + i );
    ob->add_skill_level("general.perception", 200 + i );

    ob->get_item("spiked club", 80 + random(10) );
    ob->init_equip();

    return ob;

} /* create_mercenary() */

/** @ignore yes */
void summon_guards( object thief, object shop ) {
    object ob;
    int i;

    if( ENV( thief ) != shop )
        return;

    if( !ob = create_mercenary() )
        return;

    ob->move( shop, "$N charge$s in to protect the shop!");
    ob->attack_ob( thief );

    for( i = 0; i < random(4); i++ ) {
        ob = create_mercenary();
        ob->move( shop, "$N charge$s in to protect the shop!");
        ob->attack_ob( thief );
    }

} /* summon_guards() */

/** @ignore yes */
void handle_shoplift( object thief, object shop ) {
    call_out("do_handle_shoplift", 2 + random( 4 ), thief, shop );
} /* handle_shoplift() */

/** @ignore yes */
void do_handle_shoplift( object thief, object shop ) {
    if( random(3) )
        return;

    if( !shop || !objectp( thief ) )
        return;

    // This will only work in Calarien.
    if( strsrch( file_name(shop), "/calarien/" ) != -1 ) {
        CRIME_H->add_criminal("calarien", thief, SHOPLIFT );
        tell_room( shop, "The shopkeeper notices "+
            thief->poss_short()+" sneaky ways and calls for guards!\n");
        call_out("make_guard", 2 + random( 4 ), thief, shop );
    } else {
        summon_guards( thief, shop );
    }

} /* do_handle_shoplift() */

/** @ignore yes */
void handle_theft( object place, object command_ob, object thief,
  object victim, object *stolen ) {
} /* handle_theft() */
