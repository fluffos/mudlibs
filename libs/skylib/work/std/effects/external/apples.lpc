/**
 * This effect has a classification
 * of "exploded.apples".
 * <p>
 * @author mooples
 * @classification exploded.apples
 * @see help::effects
 * @changes Rewritten by Terano, 7 April, 1998
 */
#include <effect.h>

/** @ignore yes */
void beginning( object player, int time ) {
    if (time > 1800)
        time = 1800;

    tell_object( player, "Pieces of apple start to drip off you.\n" );
    tell_room( environment( player ), (string)player->the_short() + " starts to drip apple " 
      "pieces.\n", player);
    player->submit_ee( "do_spam", ({ 40, 40 }), EE_CONTINUOUS );
    player->submit_ee( 0, time, EE_REMOVE );
    player->add_extra_look( this_object() );

} /* beginning() */

/** @ignore yes */
int merge_effect( object player, int time1, int time2 ) {
    int newtime;
     newtime = (time1 > time2 ) ? time1 : time2; 
     newtime = ( newtime > 1800 ) ? 1800 : newtime; 
    player->submit_ee( 0, newtime, EE_REMOVE );
    return newtime;
} /* merge_effect() */

/** @ignore yes */
void end( object player, int time ) {
    if ( !player->query_property( "dead" ) )
        tell_object( player, "You finally manage to shake off the last "
          "piece of apple.\n" );
    player->remove_extra_look( this_object() );
} /* end() */

void do_spam( object player ) {

    switch ( random( 10 ) ) {
    case 0 :
        player->new_parser( "cough" );
        break;
    case 1 :
        tell_object( player, "You reach up and pull a bit of apple "
          "from your left ear.\n" );
        tell_room( environment( player ), (string)player->the_short()
          +" pulls a piece of apple from "+ 
          player->query_possessive() +" left ear.\n", player);
        break;
    case 2 :
        tell_object( player, "You sniff loudly and choke as apple "
          "pulp get sucked up your nose.\n" );
        tell_room( environment( player ), (string)player->the_short() 
          +" sniffs loudly and chokes as "+ 
          player->query_pronoun() +" inhales something "
          "squishy.\n", player);
        break;
    case 3 :
        tell_object( player, "You shake your head spraying apple "
          "everywhere.\n" );
        tell_room( environment( player ), (string)player->the_short() 
          +" shakes "+player->query_possessive()+" head "
          "spraying you with apple pieces.\n", player);
        break;
    case 4 :
        tell_object( player, "You squeeze some of the apple juice "
          "from your clothes.\n" );
        tell_room( environment( player ), (string)player->the_short()
          +" squeezes "+player->query_possessive()+" clothes "
          "dripping apple juice everywhere.\n", player);
        break;
    case 5 :
        player->new_parser( "sigh" );
        break;
    case 6 :
        tell_object( player, "You sigh as a lone drop of apple juice "
          "hangs from your nose.\n" );
        tell_room( environment( player ), (string)player->the_short() 
          +" sighs and stares at a drip hanging from "
          +player->query_possessive()+" nose.\n", player);
        break;
    case 7 :
        tell_object( player, "You cough and pieces of apple spray "
          "everywhere.\n" );
        tell_room( environment( player ), (string)player->the_short() 
          +" coughs small pieces of apple everywhere.\n", 
          player);
        break;
    case 8 :
        tell_object( player, "You take off your shoes and scoop the "
          "apple bits out.\n" );
        tell_room( environment( player ), (string)player->the_short()
          +" takes off "+ player->query_possessive()+" shoes "
          "and scoops out apple pieces.\n", player);
        break;
    default :
        tell_object( player, "You put your finger in your ear and "
          "scoop out some apple pulp.\n" );
        tell_room( environment( player ), (string)player->the_short() 
          +" sticks "+ player->query_possessive()+" finger " 
          "in "+player->query_possessive()+" ear and scoops "
          "out some squishy apple bits.\n", player);
    }

} /* do_spam() */

/** @ignore yes */
string query_classification() { return "exploded.apples"; }
/** @ignore yes */
string extra_look( object player ) {
    return capitalize( player->query_pronoun()+" looks "
      "like "+player->query_pronoun()+" was just ambushed by an "
      "apple tree.\n" );
}/* end query_extra_look() */
