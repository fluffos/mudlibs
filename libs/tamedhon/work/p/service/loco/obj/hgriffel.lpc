/* Eine Huelle fuer den Planeditor
 * Samtpfote@Tamedhon.at
 */

// Aenderungen:
// 19.04.2012  Rommy  Bug im init (direktes remove), Typo, Tabs->Leerzeichen

#include <properties.h>
#include <wizlevels.h>

inherit "/p/service/loco/obj/planedit";

void init()
{
    ::init();

    if(!this_player()) return;

    if(!this_player()->QueryProp(P_NPC) && (!IS_SEER(this_player())))
    {
      if (environment() && environment()==this_player())
        tell_object(this_player(),
          "Für Dich ist der Griffel noch nichts.\n");
      call_out("remove",0);
    }
}

void create()
{
    if(!clonep(this_object())) return 0;
    ::create();

    AddId("griffel"); AddId("holzgriffel");
    SetProp(P_NAME, "Holzgriffel");
    SetProp(P_LONG,
      "Das ist ein langer, hölzerner Griffel, mit dem man "+
      "seine Gedanken und Unternehmungen für die Zukunft "+
      "notieren kann. Er besteht aus hartem Eichenholz.");
    SetProp(P_SHORT, "Ein hölzerner Griffel");
    SetProp(P_INFO, break_string(
      "Damit kannst Du Deinen Plan und Projekt ändern, die bei "+
      "der 'fingerinfo' angezeigt werden. Das 'Projekt' ist ein "+
      "Einzeiler, den auch normale Spieler sehen und der 'Plan'"+
      "wird dann an Deiner Fingerinfo angehängt.")+"\n"+
      "  editplan [löschen]    -- Plan bearbeiten bzw löschen\n"+
      "  projekt  text|löschen -- Projekt setzen bzw löschen\n\n");

    SetProp(P_VALUE, 200);
    SetProp(P_WEIGHT, 120);
    SetProp(P_MATERIAL, ([MAT_OAK:100]));

}
