/*
 * This effect is written to describe vomiting due to revulsion with
 * something someone has eaten.  Work in progress -- Comments welcome.
 * i.e. the vomiting is not due to food poisoning -- which would be a
 * delayed effect.
 *
 * This effect causes someone to vomit once and then feel rough for a bit.
 *
 * Begun Furcifer 6/2/2000.
 *
 * Changed to use one_short() instead of query_short() in messages given
 * to the room - Sandoz 22th June 2001
 */

#include <effect.h>

#define ROOMVOMIT "/std/effects/room/vomit"

string query_classification () { return "disease.revulsion.vomiting" ; }

void beginning ( object player , int duration ) {
    player->submit_ee( "start" , 10 , EE_ONCE );
    player->submit_ee( "vomiting" , ({ 30 , 60 }) , EE_ONCE );
    player->submit_ee( "feel_rough" , ({ 15 , 30 }) , EE_CONTINUOUS );
    player->submit_ee( 0 , duration , EE_REMOVE );
} /* beginning */

int merge_effect ( object player , int old_arg , int new_arg ) {
    int duration ;
    duration = player -> expected_tt()  + new_arg ;
    player->submit_ee( "feel_rough" , ({ 15 , 30 }) , EE_CONTINUOUS ) ;
    player->submit_ee( "new_vomit" , 5 , EE_ONCE ) ;
    player->submit_ee( 0 , duration , EE_REMOVE ) ;
    return duration;
} /* merge_effect */

void end( object player ) {
    if ( ! player -> query_property( "dead" ) )
        tell_object( player , "You feel more like yourself again.\n" );
    player->remove_extra_look( TO ) ;
} /* end */

void restart ( object player ) {
    tell_object( player , "You feel somewhat nauseous.\n" );
    player->submid_ee( "vomiting" , ({ 30, 60 }) , EE_ONCE );
    player->submit_ee( "feel_rough" , ({ 15, 30 }) , EE_CONTINUOUS );
    player->add_extra_look( TO );
} /* restart */

string extra_look ( object player ) {
    string pronoun, Pronoun, possessive, objective, *look;
    pronoun = player->HE;
    Pronoun = capitalize ( pronoun ) ;
    possessive = player ->HIS;
    objective = player->HIM;
    look = ({ Pronoun+" appears pale and queasy.\n",
        Pronoun+" looks as though "+pronoun+" is about to orally redecorate "+
            possessive+" surroundings.\n",
        Pronoun+" looks as though "+pronoun+" has eaten something that does "+
            "not agree with "+objective+".\n"  }) ;
    return look [ random ( sizeof ( look ) ) ] ;
} /* extra_look */

void vomiting ( object player ) {
    tell_object( player , "You spew your stomach contents into your " +
        "surroundings.\n" );
    tell_room( ENV( player ), player->one_short() + " is violently " +
        "sick.\n", ({ player }) );
    ENV( player )->add_effect( ROOMVOMIT , ({ 300 , 1 }) );
} /* vomiting */

void feel_rough ( object player ) {
    int i;
    string *rough = ({
        "You feel really grotty.\n",
        "You feel light-headed and have a slight ringing in your ears.\n",
        "Your head is spinning.\n",
        "You feel like rubbish.\n"
        }) ;

    i = random ( 2 ); /* 50% chance of you feel really grotty being the chat */
    if (i) i = random ( sizeof ( rough ) ); /* for some variety. */

    tell_object( player , rough[i] );
    tell_room( ENV( player ), player->one_short()+" looks as though " +
        player->HE + " is about to puke.\n" , ({ player }) );

} /* feel_rough */

void new_vomit ( object player ) {
    tell_object( player , "Your realise yet again that you have eaten " +
        "something you should not have done.  Already feeling slightly " +
        "queasy, you now feel rather worse.\n");
    tell_object( player , "You can hold it in no longer, and proceed to " +
        "orally redecorate your surroundings.\n" ) ;
    tell_room( ENV( player ), player->one_short()+" empties the contents " +
        "of his stomach in front of your eyes.\n", ({ player }) );
    ENV( player )->add_effect( ROOMVOMIT , ({ 300 , 1 }) );
} /* new_vomit */

void start ( object player ) {
    tell_object( player , "You realise that what you are eating is truly " +
        "and utterly revolting and that you want to puke.\n" ) ;
    tell_room( ENV( player ), player ->one_short()+" looks as though " +
        player->HE + " is trying hard to keep something down and is " +
        "losing the battle.\n", ({ player }) );
    player->add_extra_look( TO );
} /* start */
