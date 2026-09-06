//---------------------------------------------------------------------------
// std/void.c
//
// Where players move to when their environment gets destructed.
//---------------------------------------------------------------------------

inherit "std/room";

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include <stdrooms.h>

#include <secure/wizlevels.h>

#define LOGFILE "VOID"

#define PREV previous_object()

public string windows(string window);
public int do_scream(string arg);

varargs void create() {
  ::create();
  SetIndoors(1);
  SetIntShort("The Void");
  SetIntLong(
             "Standing in the void, thick fog is wafting all around you. You can barely see "
             "more than an arm's length from where you stand now. "
             "Looking around you think you see some shadows hush "
             "all around you and after looking down you recognize that "
             "you are not standing but floating in midair with no ground in sight. "
             "A bit in the distance you see through an opening at something like a harbour.\n" );

  AddExit( "harbour", STARTROOM );

  SetTPort(TPORT_OUT);
  AddDetail(({"window","windows"}), #'windows);
  AddRoomCmd(({"shout", "scream"}), #'do_scream);
  Set(P_COORDINATES,({0,0,0}) );
}

public varargs int QueryIntLight() {
  if (this_player())
    return ({int})this_player()->QueryIVision();
  return ::QueryIntLight();
}

public void reset() {
  int j;
  object obj, tmp;

  for(j = 0, obj = first_inventory(); obj;) {
    tmp = obj;
    obj = next_inventory(obj);
    if(!query_once_interactive(tmp) && !({int})tmp->Query(P_IS_PET)) {
      tmp->remove();
      if (tmp)
        destruct(tmp);
      tell_room(this_object(), "Zzzzzzaaaaapp!\n");
      j++;
    }
  }
  if(j) {
    tell_room(this_object()
             , "Somehow, "+itoa(j)+ " object"+(j > 1 ? "s" : "")
               +" vanished ...\n");
    if(obj = find_object(RESTROOM))
      tell_room(obj
               , "Silent explosions of light shine through the windows.\n");
  }
}

public int do_scream(string arg) {
  write("In the void nobody can hear you "+query_verb()+".\n");
  return 1;
}

public string windows(string window) {
  return "Through the " + window +
    " you see The Restaurant in the Middle of Nowhere.\n" +
    ({string})RESTROOM->GetIntDesc();
}

public varargs int remove(int arg)
{
  object * ob;
  int i;

  ob = all_inventory(this_object());
  for (i = sizeof(ob); i-- ; ) {
    if (interactive(ob[i]) || query_once_interactive(ob[i])) {
      ob[i]->move(STARTROOM, M_SILENT);
      tell_object(ob[i], "Help! Everything dissolves...\n\
Luckily, you've been magically transferred to a harbour.\n");
    }
  }
  return ::remove(arg);
}

public void notify_enter(object oldenv, int method, mixed extra) {
  string msg;

  if (query_once_interactive(PREV) && !query_user_level(PREV))
  {
    msg = sprintf("%s %s from %O, method %O\n", ctime(), getuid(PREV), oldenv, method);
    if (this_interactive() != PREV)
      msg += sprintf("  interactive: %s, verb '%s'\n"
                    , this_interactive()?getuid(this_interactive()) : "<none>"
                    , query_verb() || "<none>");
    log_file(LOGFILE, msg);
  }
  ::notify_enter(oldenv, method, extra);
}
