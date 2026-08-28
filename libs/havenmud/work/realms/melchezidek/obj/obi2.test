#include <lib.h>
#include <armour_class.h>
inherit LIB_WORN_STORAGE;
#include <armour_types.h>
#include <size.h>
#include <vendor_types.h>

mixed CanPutInto(object who, object item);
static void create() {
  ::create();
  SetKeyName("black obi");
  SetId( ({ "obi","belt" }) );
  SetAdjectives( ({ "black" }) );
  SetShort("a black obi");
  SetLong("This black obi is a long, broad sash tied about the waist. "
          "It has small pouches sewn on the inside of the sash which "
          "would be able to hide the tools for a master of the Shinobi,"
          " such as lockpicks and shuriken.");
  SetMass(50);
  SetValue(150);
  SetArmourType(A_BELT);
  SetVendorType(VT_CLOTHING);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(500);
  SetMaterial( ({ "textile" }) );
  SetWarmth(10);
  SetRepairSkills( ([ "textile" : 1,]) );
  SetRepairDifficulty(20);
  SetCanClose(0);
  SetMaxCarry(250);
  }
  


mixed CanPutInto(object who, object item) {
    object env;
    
    if( item == this_object() ) {
        return "#You cannot change the laws of physics.";
    }
    if( (item->GetKeyName() != "shuriken") && (item->GetKeyName() != "lockpicks")  ) {
                  return capitalize(item->GetShort()) + " cannot be put into "
                  + GetShort() + ".";
                } 
    env = environment();
    if( env != this_player() && env != environment(this_player()) ) {
        return "It is not within reach.";
    }
    return ::eventReceiveObject();
}
