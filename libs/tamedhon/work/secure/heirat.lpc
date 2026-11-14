/* Tamedhon MUDlib
 * Querolin
 *
 * $Date: 2000/08/26 $
 * $Revision: 1.0 $
 *
 */

#pragma strong_types

#include "/secure/master.h"
#define RUBRIK "allgemein"
#define PROVIDER "TDP"
#define ADMIN "querolin"


int _bekanntgabe(string frau, string mann, string zeuge)
{
  mixed *art;
  string text;
  int i;

  text ="Es freut mich euch bekanntgeben zu dürfen, dass soeben\n";
  text+="      "+capitalize(frau)+" und "+capitalize(mann);
  text+="\nin den heiligen Stand der Ehe getreten sind.\n";
  text+="Als ihr Trauzeuge war "+capitalize(zeuge);
  text+=" bei der Zeremonie anwesend.\n\n";
  text+="Ich wünsche den beiden hiermit alles Gute und eine\n";
  text+="glückliche Zukunft.\n\n";
  text+="Der Pfarrer\n";  

  art = ({ RUBRIK, PROVIDER, 0, 0,
      sprintf("%s und %s geben bekannt...",capitalize(frau),
       capitalize(mann)), text });

//    NEWSSERVER->WriteNote(art,1);

    if ( (NEWSSERVER->WriteNote(art,1) > 0) ||
         ( (NEWSSERVER->RemoveNote(RUBRIK,0) > 0) &&
           (NEWSSERVER->WriteNote(art,1) > 0) ) )
    { }
    else if (find_player(ADMIN))
      tell_object(find_player(ADMIN),
          "[Heirat:] Fehler bei Posten eines Artikels, bitte prüfen!\n");



  call_other("/obj/infomaster", "InfoMsg",
      frau+" und "+mann+" haben soeben geheiratet.");

//  log_file("HEIRAT",sprintf("%s   %s13 und %s13   %s13",
//    ctime(time()),
//    capitalize(frau), capitalize(mann), capitalize(zeuge)));
//  tell_object(find_player("querolin"),break_string(i+":"+text));
  return 1;
}
