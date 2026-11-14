// SilberLand MUDlib
//
// /p/service/obj/planedit.c -- Planeditor fuer Seher
//
// $Date: 1997/03/16 03:42:21 $
/* $Revision: 1.1 $
 * $Log: planedit.c,v $
 * Revision 1.1  1997/03/16 03:42:21  Woody
 * prepared for revision control
 *
 */

inherit "/std/thing";
inherit "/mail/nedit";
inherit "/std/more";

#include <properties.h>
#include <language.h>
#include <wizlevels.h>

#define UA this_interactive()->_unparsed_args()

void create() {
  (::create());
  seteuid(getuid());
  SetProp(P_NAME, "Planeditor");
  SetProp(P_SHORT, "Ein Planeditor");
  SetProp(P_VALUE,499); 
  SetProp(P_WEIGHT, 0);               
  SetProp(P_GENDER, 1);
  SetProp(P_NODROP, 1);
  SetProp(P_NEVERDROP, 1);
  SetProp(P_NOBUY, 1);
  SetProp(P_IDS, ({"editor","planeditor","planedit"}));
  SetProp(P_AUTOLOADOBJ, 1);
}

varargs string long() {
  return "\
Ein Plan- und Projekteditor. Damit kannst Du Plan und Projekt ändern, die\n\
angezeigt werden, wenn Dich ein anderer Spieler \"fingert\".\n\
Das Projekt ist ein Einzeiler, und wird jedem Spieler angezeigt. Der Plan\n\
kann länger sein, und wird nur Sehern und Magiern angezeigt.\n\
Befehle:\n\
 projekt <text>\n\
 projekt löschen\n\
 editplan      [läd den vorhandenen Plan in den Editor bzw. legt neuen an]\n\
 editplan löschen\n\
";
}

void init() {
  (::init());
  if (IS_SEER(this_player())) {
    add_action("Projekt","projekt");
    add_action("Projekt","project");
    add_action("EditPlan","editplan");
    init_rescue();
  }
}

int Projekt(string str) {
  string old,name,filename;
  
  if (!(str=UA)) return notify_fail("Du solltest schon den Text angeben.\n");
  name=geteuid(this_player());
  filename="/p/service/loco/save/plans/"+name+".project";
  if (str=="loeschen" || str=="löschen") {
    if (!(old=read_file(filename)))
      return notify_fail("Da war nix zum Löschen!\n");
    rm(filename);
    write("Gelöscht. Alter Text war:\n"+old);
    return 1;
  }
  if (!(old=read_file(filename)))
    write("Kein altes Projekt vorhanden.\n");
  else {
    rm(filename);
    write("Alter Text war: "+old+"\n");
  }
  write_file(filename,str+"\n");
  write("Neuer Text ist: "+str+"\n");
  return 1;
}

int EditPlan(string str) {
  string old,name,filename;
  
  name=geteuid(this_player());
  filename="/p/service/loco/save/plans/"+name+".plan";
  if (str=="loeschen"|| str=="löschen") {
    if (!(old=read_file(filename)))
      return notify_fail("Da war nix zum Löschen!\n");
    rm(filename);
    write("Gelöscht. Alter Text war:\n"+old);
    return 1;
  }
  if (str) return notify_fail("Kein brauchbarer Parameter.\n");
  if (!(old=read_file(filename)))
    write("Kein alter Plan vorhanden.\n");
  else write("Bisheriger Text:\n"+old);
  write("Bitte Text bearbeiten (~h Hilfsseite, ~q Abbruch, . wenn fertig)!\n");
  nedit("SavePlan",old);
  return 1;
}

int SavePlan(string str) {
  string filename;
  filename="/p/service/loco/save/plans/"+geteuid(this_player())+".plan";
  if (!str) {
    write("Abbruch. Nichts gespeichert.\n");
    return 1;
  }
  rm(filename);
  write_file(filename,str);
  write("\
Neuer Plan ist:\n"+str);
  return 1;
}
  

