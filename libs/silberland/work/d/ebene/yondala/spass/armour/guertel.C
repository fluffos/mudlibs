inherit "/p/armour/armour_inh";

#include <properties.h>
#include <combat.h>
#include <language.h>
#include <armour.h>
#include <new_skills.h>
create()
{
  if( !is_clone(this_object()) ) return;
  ::create();

  SetProp(P_SHORT, "Ein lederner Guertel");
  SetProp(P_LONG, 
    "Ein schmaler, schwarzer Lederguertel mit einer Schnalle zum zumachen.");
  SetProp(P_NAME, "Guertel");
  SetProp(P_GENDER, MALE);
  AddId( ({"lederguertel", "guertel"}) );

  SetProp(P_ARMOUR_TYPE, AT_BELT );
  SetProp(P_AC, 1);
  SetProp(P_MATERIAL, ([MAT_LEATHER:95, MAT_BRASS:5 ]) );
  SetProp(P_WEIGHT, 80);
  SetProp(P_VALUE, 40);      
  SetProp (P_QUALITY_DECAY, 250);
  SetProp(P_AUTOLOADOBJ, 1);                                     
  SetProp(P_WEAR_RESTRICTIONS, ([SR_MAX_SIZE : 250]) );
}