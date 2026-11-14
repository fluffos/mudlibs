#include <moving.h>
#include <properties.h>
#include <language.h>

inherit "std/thing";

void start_death();

void create()
{
  ::create();
  SetProp( P_NAME, "Stempel des Todes" );
  SetProp( P_GENDER, MALE );
  SetProp( P_SHORT,0);
  SetProp( P_INVIS,1);
  AddId( "\ndeath_mark" );
}

void reset()
{
  if (environment() && !query_once_interactive(environment()))
    remove();
}

void init()
{
  ::init();
  start_death();
}

/*
 * Function name: start_death
 * Description:   Start the death sequence.
 */
void start_death()
{
	
  object ned, my_host;

  my_host = environment();

  if (!my_host||!living(my_host)) return;
  if(!my_host->QueryProp(P_GHOST))
  {
      destruct(this_object());
      return;
  }

  say("Du siehst eine dunkle Gestalt, die etwas Dunst einsammelt ... oder vielleicht\n"+
      "bildest du Dir das auch nur ein ...\n");
  my_host->move("/room/death/death_room",M_GO|M_NOCHECK|M_SILENT|M_NO_SHOW);

}

varargs int move(mixed dest,int method)
{	
  if (!method & M_NOCHECK) return 0;
  return ::move(dest,method);
}

int _query_autoloadobj() { return 1; }
