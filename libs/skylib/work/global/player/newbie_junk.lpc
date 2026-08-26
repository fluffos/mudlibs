
#define TORCH "/obj/misc/torch"

/**
 * This method is called when a player first starts on the mud.  It gives
 * out all of the newbie equipment and stuff.
 */
void start_player() {
    int i;
    object ob;

    seteuid( getuid() );

    TP->add_currency( 15000, "calarien");

    for( i = 0; i < 3; i++ ) {
        ob = clone_object(TORCH);
        ob->move(TP);
    }

    // Wahoo!
    TP->add_skill_level("fighting", 5 );

    ob = ARMOURY_H->request_item("dagger", 100 );
    ob->move(TP);
    TP->set_hold(ob);

    if( TP->query_gender() == 2 )
        ob = ARMOURY_H->request_item("black cotton dress", 100 );
    else
        ob = ARMOURY_H->request_item("black hooded cloak", 100 );

    ob->move(TP);
    TP->wear_armour(ob);

    TP->add_property("no ambiguous", 1 );
    TP->set_monitor( 1 );

} /* start_player() */

/**
 * Gives out the login gifts and anything else that should be done on
 * a certain login number.
 * @param num the number of logins
 */
void logged_on_times( int num ) {
    switch( num ) {
      case 3 :
      break;
      case 10 :
      break;
      case 42 :
      break;
      case 100 :
      break;
      case 150 :
      break;
      case 200 :
      break;
      case 512 :
      break;
      case 990 :
      break;
      case 1000 :
      break;
      case 1010 :
      break;
      case 1020 :
      break;
    }
} /* no_login_times() */
