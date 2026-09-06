/* A Black Wolf Rose by Joan 09/14/1998 */
/* For The Man In Black */
/* Last update 06/02/99 by Joan */


#include <properties.h>
#include <rooms.h>
#include <stdrooms.h>
#include <string.h>
#include <macros.h>
inherit "/std/thing";
inherit "/lib/string";

string check_thorn();

void create()
  {
  ::create();

  Set(P_AUTOOBJECT,1);
  SetShort("a black rose");
  SetIds(({"rose"}));
  SetValue(100);
  SetWeight(5);
  SetLong(({"A Black Wolf Rose. You should examine it more closely. Be "
"very careful of the nasty thorns.","It is a velvetly midnight black "
"rose. The petals curl gently at the tips. The leaves are dark green and "
"glossy with a blood red blush on the underside. This rose was especially "
"grown for The Man In Black. It still has thorns. Perhaps you should "
"examine them. It is perfect and beautiful.\n"}));

  SetSmell(
"You close your eyes as you inhale its delicately light but heady almost "
"narcotic fragrance!\n");

  AddSubDetail("leaves",({"Each delicate leaf is perfectly shaped and "
  "richly colored. Delicate veins are etched deeply into each leaf.\n",
  "There are four leaves all perfectly shaped. They are deep green "
  "with a deep red edge. The lighter green underside gently tapers "
  "to a blood red.\n"}));

  AddSubDetail("stem",({"The stem almost 45 cm long. It is the darkest "
  "green you have ever seen.\n","The thorns are still on this rose. "
  "Becareful they could prick your finger.\n"}));

  AddSubDetail("petals",({"The petals are perfectly shaped and together "
  "form a perfect cup shaped rose. The richness of the color is "
  "breathtaking.\n","Each petal is midnight black and curls at "
  "it's tip.\n"}));

  AddSubDetail(({"thorn","thorns"}),#'check_thorn /*'*/);


}

string check_thorn()
{
  if(({string})TP->QueryRealName() != "cadderly") {
    TP->DoDamage(1);

    show(NAME(TP)+" examines a beautiful black rose. EEEEEKS! "
    +NAME(TP)+" pricked a finger on a nasty looking thorn. A drop "
    "of blood runs down "+HISHER(TP)+" finger.\n");

    return

      "As you touch the rose, one of the thorns prick you. "
      "A drop of blood runs down your finger.\n";

  } else {

    show(NAME(TP)+" examines a beautiful black rose. EEEEEKS! "
    +NAME(TP)+" is The Man In Black. The rose draws no blood and "
    "you better run for your life. ACK! Its The Man In Black!\n");

    return

      "You are The Man in Black. It is your rose and "
      "the thorns can't hurt you.\n";
  }
  return 0;
}

