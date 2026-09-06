/*
** A wooden stake
**
** This stake does extra damage if the enemy is of race or guildclass
**   vampire
**
** Author: Analena@Nightfall, 10feb97
** Update:
** Cloned by: /d/archwiz/common/defence/example/npc/elf.c
*/

#include <guild.h>
#include <properties.h>
#include <combat.h>

inherit "/std/weapon";

void create()
{
  ::create();
  SetStandard(WT_SPEAR,5,PSIZE_NORMAL);
    // if we had chosen a lower weaponclass we might have initialized
    //   this stake as WT_KNIFE instead of WT_SPEAR as both are piercing
    //   weapons, differing mainly in the maximum allowed weaponclass.
    //   Check out '/doc/concepts/wc' to find out about the guidelines
    //   for the different weapontypes.

  SetShort("a wooden stake");
  SetLong("This is a long stake made out of wood. One of its ends is "
    "pointed, allowing it to be used as a weapon.\n");
  RemoveId("spear");
    // since this stake clearly isn't a spear we remove the default id
    //   set by the weapontype.

  AddId("stake");
    // all decendants of /std/weapon automatically have a class_id of
    //   'weapon' as well as a default id for the weapontype (in this
    //   case it was 'spear') so you never need to set this as id (unless
    //   you manually removed it before).

  AddAdjective(({"long","pointed","wooden"}));
  SetHelpMsg("This wooden stake looks like a good weapon for fighting "
    "vampires.\n");
    // weapons automatically set a help message generated out of the short
    //   description and the hands needed to wield it. This certainly is
    //   sufficient for standard weapons, but if your weapon offers any
    //   specialties you may think of setting your own message.
}

int CalcDamage(object enemy)
{
    // all weapons overloading CalcDamage (the calculation of the actual
    //   damage done by the weapon on this attack) must be approved by
    //   the department of defence. The overloading may not exceed the
    //   WC-maximum of any guild (e.g. a WC 11 sword giving +2 on
    //   certain attacks, thus passing the spellcaster's limit of
    //   WC 12) or otherwise offend any rules.

  int damage;
  damage=::CalcDamage(enemy);
    // always call the underlying CalcDamage-routine first to get an
    //   impression of the standard damage this weapon would normally
    //   do.

  if( (!enemy) || (
    (enemy->QueryRace()!="vampire") && (enemy->QueryGuild()!=GC_VAMPIRE) ))
    return damage-1;
  else
    return damage+1;

    // the stake does one less than the 'regular' damage against anybody
    //   but vampires. Against vampires, it does one more damage than
    //   it would normally do.
}
