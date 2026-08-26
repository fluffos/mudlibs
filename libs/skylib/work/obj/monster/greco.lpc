/**
 * This is a different attempt by Ember to make an accountable
 * auto_loading system. It uses old system, but with a different front end.
 * 30-Oct-93 created by E
 * 24-Oct-96 Fiddled by Pinkfish to create the alter ego - Gumboot.
 * 05-Feb-97 Changed by Olorin to not trust find_call_out
 * 27-Jan-01 Changed by Shaydz to kill Grecco
 */

inherit NPC_OBJ;

object my_player;
mixed total_als;
object *save_obs;
object *unhandled_obs;
object *done_obs;

void setup() {
    seteuid("Root");
    set_short("Shaydz's Assistant");
    set_name("assistant");
    add_property("determinate", "");

    basic_setup("human", 30, 2 );

    set_long("This is Shaydz's Assistant, whose job it is to record all of "
        "the baggage of players so they can be restocked when they come "
        "back.  She is currently scribbling in her notebook furiously.\n");

} /* setup() */

void get_rid_of( object player ) {
    int i;

    my_player = player;
    unhandled_obs = save_obs = INV(player);
    total_als = ({ });
    done_obs = ({ });

    for( i = 0; i < sizeof(save_obs); i++ )
        call_out("get_ob_al", 1, save_obs[i] );

    call_out("finish_player", 2 );

} /* get_rid_of() */

/**
 * This method is called out for each object in the player's inventory.
 * It should add to the autoload array and the done_obs array.
 */
void get_ob_al( object ob ) {
    mixed als;

    unhandled_obs -= ({ ob });
    als = my_player->fragile_auto_str_ob(ob);
    done_obs += ({ ob });

    if( sizeof(als) == 0 )
        return;

    total_als += als;

} /* get_ob_all() */

void handle_dead_ob( object ob ) {
    int value;
    mixed als;
    string obname;

    catch( ob->move("/room/broken") );

    // Random anonymous replacement value.
    value = 1000;
    catch( value = ob->query_value() );

    obname = "unknown object";
    catch( obname = ob->short(1) );

    catch("/obj/misc/al_receipt"->set_object( file_name(ob) ) );
    "/obj/misc/al_receipt"->set_obname(obname);
    "/obj/misc/al_receipt"->set_value(value);

    als = "/global/player/auto_load"->fragile_auto_str_ob(
        find_object("/obj/misc/al_receipt") );

    als[0] = 1;

    // This is a bit of a hack.  It could easily break if the receipt
    // inheritance changes.
    if( !undefinedp(als[2][1]["::"]["cloned by"]) )
        als[2][1]["::"]["cloned by"] = "greco";

    log_file("GRECO", "%s: %s - Broken object at logout: %O\n", ctime(time()),
        my_player ? my_player->query_name() : "0", ob );

    total_als += als;

} /* handle_dead_ob() */

/**
 * This method is called after all of the auto_load call_outs are complete,
 * so it should check which objects failed to complete and write out
 * receipts for them.
 */
void finish_player() {
    int i, one_more;
    object *missing_obs;

    if( find_call_out("get_ob_al") != -1 ) {
        call_out("finish_player", 2 );
        return;
    }

    if( sizeof( unhandled_obs ) ) {
        call_out("finish_player", 2 );
        return;
    }

    missing_obs = save_obs - done_obs;

    if( sizeof(missing_obs) ) {
        one_more = sizeof(missing_obs);
        say( ( one_more == 1 ? "One" : "Some")+" of your objects "+
            ( one_more == 1 ? "is" : "are")+" broken and will not save "
            "properly, so I will give you "+( one_more == 1 ?
            "a receipt for it.  This" : "receipts for them.  These")+" can "
            "either be sold for something vaguely like the replacement value "
            "of the object or taken to a creator as proof of ownership so "
            "you can ask very nicely to have it replaced.");
        for( i = 0; i < sizeof(missing_obs); i++ )
            handle_dead_ob(missing_obs[i]);
    }

    my_player->save_with_auto_load(total_als);

    tell_object(my_player, "Thanks for Playing!\n");
    tell_object(my_player, "Do come again!\n");

    catch(done_obs->set_tracked_item_status_reason("PLAYER_QUIT"));
    catch(done_obs->dest_me());
    catch(done_obs->dwep());

    catch( ITEM_H->save_all_item_states_delete_cache( my_player->query_name() ));

    catch( my_player->effects_quiting() );
    catch( my_player->dest_me() );

    if( my_player )
        catch( my_player->dwep() );

    if( my_player )
        say(short(1) + " sighs deeply.\n");

    move("/room/rubbish", "$N appear$s.",
                          "$N disappear$s in a puff of smoke.");
} /* finish_player() */
