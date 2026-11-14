// SilberLand MUDlib
//
// std/room/doors.c -- new doors, managed by doormaster
//
// $Date: 1997/10/15 19:10:04 $
/* $Revision: 3.1 $
 * $Log: doors.c,v $
 * Revision 3.1  1997/10/15 19:10:04  Woody
 * In NewDoor() auch _MakePath() verwenden
 *
 * Revision 3.0  1997/03/13 02:01:16  Woody
 * prepared for revision control
 *
 * Revision 1.8  1997/01/20  Woody
 * Doorcommands werden nur hinzugefuegt, wenn noch nicht definiert
 *
 * Revision 1.7  1996/03/11  02:12:00  Mupfel
 * Prototypen fuer Add*Exit jetzt aus /sys/room/exits.h
 * /sys/doorroom.h ersetzt durch /sys/room/doors.h
 *
 * Revision 1.6  1994/08/22  17:57:05  Kirk
 * return type of AddSpecialExit is now void
 *
 * Revision 1.5  1994/07/19  16:14:08  Kirk
 * *** empty log message ***
 *
 * Revision 1.4  1994/07/12  00:09:10  Kirk
 * clean up
 *
 * Revision 1.3  1994/06/29  17:30:27  Rochus
 * add_action statt AddCmd
 *
 * Revision 1.2  1994/06/29  13:44:14  Kirk
 * Removed old AddDoor/AddDoor2 stuff
 *
 * Revision 1.1  1994/05/24  19:13:56  Kirk
 * Initial revision
 *
 * Revision 1.7  1994/05/11  17:32:56  Rochus
 * Noch einen falschen Kommentar verbessert.
 *
 * Revision 1.6  1994/05/11  17:27:18  Rochus
 * Fehler im Kommentar behoben
 *
 * Revision 1.5  1994/03/21  16:48:13  Jof
 * Reindented files using emacs - once again
 *
 * Revision 1.4  1994/02/23  11:36:51  Rochus
 * Ich war davon ausgegangen, dass jeder Zugriff auf P_EXITS mit
 * QueryProp erfolgt... das war falsch, also musste ich auch
 * noch GetExits ueberschreiben *grummel*
 *
 * Revision 1.3  1994/02/22  19:57:50  Kirk
 * *** empty log message ***
 *
 */

#pragma strong_types

#define NEED_PROTOTYPES

#include <config.h>
#include <thing/properties.h>
#include <room/exits.h>
#include <room/doors.h>
#include <properties.h>
#include <language.h>
#include <defines.h>

// external prototypes
varargs void AddCmd(mixed cmd, mixed func, int flag);

void create()
{
  SetProp(P_DOOR_INFOS,0);
}

varargs int NewDoor(mixed cmds, string dest, mixed ids, mixed props)
{
/*
  cmds: Befehl(e), um durch die Tuer zu gehen (String oder Array von Strings)
  dest: Zielraum
  ids:  Id(s) der Tuer, default "tuer" (String, Array von Strings oder 0)
  props: besondere Eigenschaften der Tuer (optional)
  Array mit Paaren Nummer der Eigenschaft, Inhalt
  definierte Properties sind:
  D_FLAGS:  Flags wie bei Sir's Tueren
  default: DOOR_CLOSED | DOOR_RESET_CL
  Bei Schluesseln wird getestet, ob der String, den
  QueryDoorKey zurueckliefert, gleich
  "raumname1:raumname2" ist, wobei raumname1,2 die
  kompletten Filenamen der beiden Raeume in sortierter
  Reihenfolge sind.
  D_LONG:   lange Beschreibung der Tuer
  default: "Eine Tuer.\n"
  D_SHORT:  kurze Beschreibung der Tuer, wird an die Raumbeschreibung
  angefuegt, wobei %s durch geoeffnet bzw. geschlossen
  ersetzt wird.
  default: "Eine %se Tuer. "
  D_NAME:   Name, der beim Oeffnen/Schliessen und bei Fehlermeldungen
  angezeigt wird.
  default: "Tuer"
  D_GENDER: default: FEMALE
  D_FUNC:   Funktion, die im Raum aufgerufen werden soll, wenn die
  Tuer erfolgreich durchschritten wird.
  default: 0
  D_MSGS:   Falls String: ausgegebene Richtung fuer move
  Falls Array: ({direction, textout, textin}) fuer move
  default: 0

  Beispiel:
  NewDoor("norden","/players/rochus/room/test2","portal",
  ({D_NAME,"Portal",
  D_GENDER,NEUTER,
  D_SHORT,"Im Norden siehst Du ein %ses Portal. ",
  D_LONG,"Das Portal ist einfach nur gigantisch.\n"
  }));

*/

  if (!cmds || !dest) return 0;
  dest=ME->_MakePath(dest) || dest;
  return call_other(DOOR_MASTER,"NewDoor",cmds,dest,ids,props);
}

void init()
{
  mixed *info;
  string *cmds;
  int i,j;
  if (!pointerp(info=({mixed *})QueryProp(P_DOOR_INFOS))) return;
  add_action("_open_door","oeffne");
  add_action("_close_door","schliesse");
  add_action("_close_door","schliess");
  add_action("_open_door","öffne");
  add_action("_close_door","schließe");
  add_action("_close_door","schließ");
  for (i=sizeof(info)-1;i>=0;i--) {
    cmds=({string *})(info[i][D_CMDS]);
    for (j=sizeof(cmds)-1;j>=0;j--)
      if (member(query_actions(this_player()), cmds[j])==-1)
        add_action("go_door",cmds[j]);
    // Befehle IMMER anfuegen, gechecked wird sowieso erst beim Durchgehen.
  }
}

void reset()
{
  if (object_name(this_object())!="/std/room/doors"&&QueryProp(P_DOOR_INFOS))
    call_other(DOOR_MASTER,"reset_doors");
}

int _open_door (string str)
{
  if (!str || !QueryProp(P_DOOR_INFOS))
    return 0;
  return ({int}) call_other(DOOR_MASTER,"oeffnen",str);
}

int _close_door (string str)
{
  if (!str || !QueryProp(P_DOOR_INFOS))
    return 0;
  return ({int}) call_other(DOOR_MASTER,"schliessen",str);
}

varargs int
go_door (string str)
{
  if (!QueryProp(P_DOOR_INFOS))
    return 0;
  if (call_other(DOOR_MASTER,"go_door",query_verb()))
    return 1;
  return 0;
}

int set_doors(string *cmds,int open)
{
  int j;
  
  if (!previous_object())
    return 0;
  if (object_name(previous_object())!=DOOR_MASTER)
    return 0;
  // Andere sollen nicht rumpfuschen.
  if (!this_player()) return 0;
  if (environment(this_player())!=this_object())
    return 0;
  // Ist sowieso keiner da...
  if (!pointerp(cmds))
    return 0;
  if (open)
    AddSpecialExit(cmds,"go_door");
  else
    RemoveSpecialExit(cmds);
  for (j=sizeof(cmds)-1;j>=0;j--)
    if (member(query_actions(this_player()), cmds[j])==-1)
      add_action("go_door",cmds[j]);
  return 1;
}
