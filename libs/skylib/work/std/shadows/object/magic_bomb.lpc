/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: magic_bomb.c,v 1.1 1998/01/06 04:40:23 ceres Exp $
 * $Log: magic_bomb.c,v $
 * Revision 1.1  1998/01/06 04:40:23  ceres
 * Initial revision
 * 
*/
inherit "/std/effect_shadow";

void detonate_bomb() {
   mixed *args;
   args = arg();
   write( replace( args[ 2 ], ({
         "$ob_name$", (string)player->the_short(),
         "$tp_name$", "you",
         "$tp_poss$", "your"
   }) ) );
   say( replace( args[ 2 ], ({
         "$ob_name$", (string)player->the_short(),
         "$tp_name$", (string)this_player()->the_short(),
         "$tp_poss$", (string)this_player()->query_possessive()
   }) ) );
   args[ 0 ]->spell_succeeded( this_player(), ({ }), args[ 3 ] );
   player->move( "/room/rubbish" );
} /* detonate_bomb() */
