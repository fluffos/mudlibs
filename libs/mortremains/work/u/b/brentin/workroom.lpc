
inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set( "short", "A workroom" );
  // NB: "@EndText" should not have spaces after it.
  // "EndText" should be on a line of its own (no indentation, tabs or spaces)
  set( "long", @EndText
This is where Lord Brentin thinks up ideas to code, it
is lacking in character, a and bland in apperance, allowing no
distractions.
EndText
  );
  set( "exits", ([
  ]) );
}
