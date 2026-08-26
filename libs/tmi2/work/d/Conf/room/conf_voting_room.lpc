/*
// File:          /d/Conf/room/voting.c
// Purpose:       The Conf voting room - inherits the generic voting_room.c
// Credits:
// 93-06-28       Douglas Reay (Pallando @TMI and other muds) wrote this file.
// Comments:      Written as part of TMI's conference centre.
//                Not part of TMI's distribution, but may be used on same terms.
*/

inherit "/d/Conf/voting_room";

void room_create()
{
  set( "light", 1 );
  set( "short", "Conference voting room" );
  set( "long",
"The voting room.  Representatives come here to vote on proposals.\n"+
"Typing \"help room\" gives aid on the facilities available.\n"+
"The central meeting point is to the west.\n"+
  "" );
  set( "exits", ([
    "west" : "/d/Conf/room/centre",
  ]) );
}

void create()
{
  save_file = "/d/Conf/data/votes";
  default_options = ({ "endorse", "reject", "abstain" });
  ::create();
}

int is_convener()
{
  return member_group( geteuid( this_player() ), "conveners" );
}

string is_voter()
{
  object badge;
  string ret;

  badge = present( "conference_badge", this_player() );
  if( !badge || ( geteuid( badge ) != getuid() ) ) return 0;
  if( ret = badge-> query_rep() ) ret = " " + ret;
  else ret = "";
  return capitalize( geteuid( this_player() ) ) + ret;
}
