/* A runed elven sword              */
/* Cadra 22-3-1994                  */
/* last changes: Analena, 04-4-1997 */

#include <properties.h>
#include <guild.h>
#include <combat.h>

inherit "std/weapon";

void create()
{
  ::create();
  SetStandard(WT_SWORD,8,PSIZE_NORMAL);
  SetShort("a long sword");
  SetLong(
    "An elvish longsword of great antiquity. There are two engravings on it.\n");
  SetAds(({"long","golden","runed"}));
  SetResetQuality(100);
  SetReadMsg(
    "One engraving reads 'Made in Woodland'\n"
    "the other engraving says:\n"
    "Made for lightelves and magicians only.\n");
}

remove_me(object pl) {
  if (!pl) return;
  if (!this_object()) return;
  pl->Defend(5+random(20),DT_ZAP,this_object());
  tell_object(pl,"The sword explodes... you get hurt.\n");
  remove();
  if (this_object()) destruct(this_object());
}

ChkWield(object wielder)
{
    string race,guild;
    if (!wielder) return 0;
    race = wielder->QueryRace();
    guild = wielder->QueryGuild();
    if ((race=="elf")||(guild==GC_CONJURER) || (guild==GC_SORCERER))
        tell_object(wielder,"In the very moment you wrap your fingers "
            "around the hilt of your sword you feel a strong belonging "
            "to it.\n");
    else if ((race=="darkelf")||(guild==GC_WARRIOR) || (guild==GC_VAMPIRE))
    {
        tell_object(wielder,"You feel the sword vibrating...\n");
        call_out("remove_me",1,wielder);
        return EQ_FORBID;
    }
    return EQ_OK;
}

int QueryWC()
{
  object wielder;
  string race,guild;
  wielder = QueryWielded();
  if(!wielder) return 8;
  race = wielder->QueryRace();
  guild = wielder->QueryGuild();
  if ((race=="elf")||(guild==GC_CONJURER) ||
      (guild==GC_SORCERER)) return 8;
  if ((race=="darkelf")||(guild==GC_WARRIOR) ||
      (guild==GC_VAMPIRE)) return 0;
  return 6;
}
