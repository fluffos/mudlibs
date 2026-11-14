
/* Dieses Ist der Rumpf fuer den Workroom aller Magier, es fehlt noch
 * die Zeile #define WIZNAME "Merlin".
 * 16.7.92 Rumata
 */
/* Bug gefixt: Man befindet sich nun nicht mehr im ed wenn man im Jail war.
 * Hier wurde input_to im init aufgerufen->darf nicht gemacht werden!!
 * 13.11.96 Eros
 *
 * Miloggen, wer einen spieler ins jail transt
 * Eigenes sage kommando.
 */



inherit "std/room";

#include <properties.h>
#include <wizlevels.h>
#include <language.h>
#include <moving.h>
#include <player.h>

void create()
{
  ::create();
  SetProp(P_LIGHT, 1 );
  SetProp(P_INT_SHORT, "Das Kittchen");
  SetProp(P_INT_LONG, "Das Kittchen, in dem Du stehst.\n"
      "Hier geht nur noch sag, nicke, und nein.\n");
  SetProp(P_INDOORS,1);
  AddCmd("", "abc", 1);
}

void init()
{
  ::init();
  if(objectp(this_interactive())&&objectp(this_player()))
    write_file("/log/JAIL",
      sprintf("%s steckt %s ins Jail %s\n", 
          capitalize(this_interactive()->name()),
          this_player()->name(),dtime(time())));
}

int abc(string str)
{
  string verb;
  
  if (IS_ELDER(this_player())) return 0;
 
  verb=query_verb();
  str=this_player()->_unparsed_args()+"       ";
  if( verb=="sag" || verb=="sage" )
  {
    write(break_string(str, 78, "Du sagst: "));
    say(break_string(str, 78, this_player()->Name()+" sagt: "));
  }
  else if(verb=="ja" || verb=="nicke" || verb=="nick")
  {
    write("Du nickst zustimmend.\n");
    say(this_player()->Name()+ " nickt zustimmend.\n");
  }
  else if(verb=="nein" || verb=="schuet" || verb=="schüt")
  {
    write("Du schüttelst den Kopf.\n");
    say(this_player()->Name()+ " schüttelt den Kopf.\n");
  }
  else
    write("Nix da.\n");
  return 1;
}


