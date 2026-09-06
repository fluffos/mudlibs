/*
** A giant's cloak
**
** This cloak, made of animal hides, will give an extra point of AC
**   if worn by a giant
**
** Author: Analena@Nightfall, 10feb97
** Update:
** Cloned by: /d/archwiz/common/defence/example/npc/giant.c
*/

#include <properties.h>
#include <combat.h>

inherit "/std/armour";

void create()
{
  ::create();
  SetStandard(AT_CLOAK,1,PSIZE_LARGE);
    // don't forget to initialize your weapons and armours to the right
    //   size or else the npc might not be able to wield or wear them.

  SetShort("a giant's cloak");
  SetLong("This cloak is crudely made of animal hides. It looks like "
    "something giants like to wear.\n");
  AddId(({"hide","hides"}));
    // all descendants of /std/armour automatically have a class_id
    //   of "armour" as well as a standard id for the armourtype (in
    //   this case "cloak") so you never need to set these as ids
    //   (unless you manually removed them before)

  AddAdjective(({"giant","giant's"}));
  SetHelpMsg("This cloak looks like it was made especially to fit giants, "
    "and it will offer them a better protection than anybody else.\n");
    // armours automatically set a help message generated out of the
    //   short description and (in case of shields) the hands needed to
    //   wear them. This certainly is sufficient for standard armours,
    //   but if your armour offers any specialties you may think of
    //   setting your own message.
}

varargs int QueryAC()
{
    // all armours overloading QueryAC (and thereby manipulating the AC
    //   set for this armour) must be approved by the department of
    //   defence. The AC may not offend the AC-restrictions of any
    //   guild (e.g. an AC 3 body armour giving +1 if worn by a living
    //   with Dex>20, thus passing the vampire's limit of AC 3) or
    //   any other rules.

  return (::QueryAC())+(owner&&(owner->QueryRace()=="giant"));
    // this line is a bit cryptical I admit. What it does is simply
    //   querying the base-AC of the cloak (1, as set with SetStandard,
    //   the underlying AC should always be used as a base for any
    //   adjustments at runtime) and adding 1 point if the cloak is
    //   currently worn by a giant.
    //   "owner" is a public global variable defined by /std/armour
    //   holding the object currently wearing this armour or 0 if
    //   it isn't worn at the moment.
}
