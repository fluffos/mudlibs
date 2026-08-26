/*
 * A thingy to deal with obsolete PT stuff.
 * - Sandoz 2001.
 */

#include <login.h>
#include <deity.h>
#include <board.h>

inherit COMMAND_BASE;

private void do_check_rituals( object player );
private void do_check_posts( object player );

void do_login_calls( mixed player, string type ) {
    if( type != LOGIN || !( player = find_player(player) ) )
        return;
    call_out( (: do_check_rituals :), 10, player );
    call_out( (: do_check_posts :), 4, player );
} /* do_login_calls() */

/**
 * We're doing other stuff here as well.
 */
private void do_check_rituals( object player ) {
    string ritual, ritob, old_rit;

    if( !player )
        return;

    PLAYTESTERS_H->do_application_notify( player );

    foreach( old_rit in REPLACE ) {
      if( player->query_spell(old_rit) ) {
          ritob = player->query_spell(old_rit)[0];
          ritual = ritob->query_name();
          if( ritual == old_rit )
              continue;
          player->remove_spell(old_rit);
          player->add_spell( ritual, ritob );
          tell_object( player, "Your ritual '"+old_rit+"' has been changed "
              "to '"+ritual+"'.\n" );
      }
    }

} /* do_check_rituals() */

/**
 * Are there any posts they havn't read?
 */
private void do_check_posts( object player ) {
  mapping news_rc;
  mixed *stuff;
  string ret;

  if(!playtesterp(player) || creatorp(player)) return;
  news_rc = BOARD_H->query_newsrc(player->query_name());
  if( !news_rc ) news_rc = ([ ]); //Theoretically possible under some conditions.

  stuff = (mixed *)BOARD_H->get_subjects("playtesting", player->query_name());
  if( !sizeof( stuff ) ) return;

  stuff = filter_array( stuff, (: ( $1[B_TIME] > $2 ) &&
    (lower_case( $1[B_NAME] ) != $3) :), news_rc["playtesting"],
    player->query_name());
  stuff = stuff[(sizeof(stuff)-5)..];
  if(sizeof(stuff)) {
    ret = "\nThere are posts to the playtesting board you have not read.\nThe "
        +sizeof(stuff)+" most recent posts are ";
    foreach(mixed thing in stuff) {
      ret += "\"" + thing[B_SUBJECT] + "\" posted by " + thing[B_NAME] + ", ";
    }
    ret = ret[0..(strlen(ret)-3)];
    ret += ".\n";
    tell_object(player, ret);
  }
} /* do_check_posts() */
