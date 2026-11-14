/* made by magictcs - 8 jul 1997
 * a special staff
 * if you 'release' its energy - it will affect any lving in the room
 *    except the player itself,
 * the energy is released even if there is no living to affect
 */

// TODO: coding of cmd_release and refrehing the power
// TODO: add the refreshing item
// TODO: put the refresh command to the refresh-item

#include <properties.h>
#include <sykorath.h>

inherit "/std/weapon";

create() {
  ::create();
  SetStandard(WT_STAFF,8,PSIZE_LARGE);
  SetShort("a staff of power");
  SetInfo(
    "This staff is a dangerous weapon. Be careful with it if you want to\n"
    "release the energy of it?!\n");
  SetLong(
    "You see a long staff, made of wood. It has a special feature.\n");
  SetHelpMsg("Use: release energy\n");
  SetWeight(1201);
  SetValue(3400);
  AddId("staff of power");
  Set(P_VERSION,"(C) Magictcs - V1.0");
  AddAdjective(({"long"}));
}

init() {
  ::init();
  add_action("cmd_release","release");
}

//****************
// attack function
//****************
void DoAttack(object wolf) 
{
  int dam;
  if (wolf && living(wolf) && wolf->QueryIsNPC()) 
  {
/*
    if (Repulse(wolf, this_player())) return;
    dam=random(230)+20;

    Message( ({
    "Rays of frozen white fire coil and twist as they shoot at "+
      wolf->QueryName()+".\n",
    "Rays of frozen white fire coil and twist as they shoot at "+
      wolf->QueryName()+".\n"}) );
    dam=wolf->Defend(ModifyMagic(dam), DT_FIRE, 0);
    if (wolf) Message(QueryCastDamage(dam,wolf));
*/
  }
}

int cmd_release(string str) {
  notify_fail("Release what?\n");
  if (!str) return 0;
  if (str=="energy") {
    filter(all_inventory(environment(TP)),#'DoAttack);
    return 1;
  }
  return 0;
}

