
inherit COMMAND_BASE;

/** @ignore yes */
mixed cmd( object *indirect_obs, string direction ) {
    string owner, *words, word;
    object owner_ob;

    if ( TP->query_property( "dead" ) )
        return notify_fail( "You're dead.  You can't drag anything.\n" );

    if ( objectp( (object)TP->query_dragging() ) )
        return notify_fail( "You're already dragging something.\n" );

    if ( sizeof( indirect_obs ) > 1 )
        return notify_fail( "You can only drag one thing at a time.\n" );

    if ( living( indirect_obs[ 0 ] ) ) {
        /* For the moment, any living thing not passed out cannot be dragged. */
        if ( !indirect_obs[ 0 ]->query_property( PASSED_OUT )
          || pk_check( indirect_obs[ 0 ], TP ) )
            return notify_fail( (string)indirect_obs[ 0 ]->the_short() +
              " doesn't want to be dragged away, thank you very much.\n" );
    } else if(base_name(indirect_obs[0]) == "/obj/corpse") {
        owner = indirect_obs[ 0 ]->query_owner();
        words = explode( lower_case( owner ),  " " );
        words = filter(words, (: "/secure/login"->test_user($1) :));
        foreach (word in words) {
            owner_ob = find_player(lower_case(word));

            if(owner_ob && userp(owner_ob) &&
              pk_check( owner_ob, TP ) && member_array(
                TP->query_name(), indirect_obs[0]->query_permitted() ) == -1 )
                return notify_fail( "For some reason, you can't get hold of "+
                  (string)indirect_obs[ 0 ]->the_short() +".\n" );
        }
    }

    if ( ( environment( indirect_obs[ 0 ] ) != environment( TP ) ) ||
      indirect_obs[ 0 ]->get() )
        return notify_fail( "For some reason, you can't get hold of "+
          (string)indirect_obs[ 0 ]->the_short() +".\n" );

    write( "You get hold of "+ (string)indirect_obs[ 0 ]->the_short() +".\n" );
    say( (string)TP->one_short() +" gets hold of "+
      (string)indirect_obs[ 0 ]->a_short() +".\n" );

    if ( (int)indirect_obs[ 0 ]->query_complete_weight() +
      (int)TP->query_loc_weight() > 2 *
      (int)TP->query_max_weight() ) {
        write( "You struggle and strain, but you can't budge "+
          (string)indirect_obs[ 0 ]->query_pronoun() +".\n" );
        say( (string)TP->one_short() +" struggles and strains, but "+
          (string)TP->query_pronoun() +" can't budge "+
          (string)indirect_obs[ 0 ]->query_pronoun() +".\n" );
    } else {
        TP->set_dragging( indirect_obs[ 0 ] );
        if ( !TP->exit_command( direction ) )
            write( "You can't drag "+ (string)indirect_obs[ 0 ]->the_short() +
              " that way.\n" );
        TP->reset_dragging();
    }
    write( "You let go of "+ (string)indirect_obs[ 0 ]->the_short() +".\n" );
    say( (string)TP->the_short() +" releases "+
      (string)TP->query_possessive() +" hold of "+
      (string)indirect_obs[ 0 ]->the_short() +".\n" );
    return 1;
} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
  return ({ "<indirect:object:here> to <string'direction'>",
            (: cmd( $1, implode($4[1..], " ") ) :),
            "<indirect:object:here> <word'direction'>",
            (: cmd( $1, $4[1] ) :),
            });
} /* query_patterns() */
