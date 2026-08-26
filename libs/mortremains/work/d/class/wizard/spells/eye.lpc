/*
** File: eye.c
** Purpose: A floating eye spell. Allows the user to float around and see
**      through eye without getting slaughtered. The eye is a monster with 
**      only a handful of HP's and no storage capacity.
** Cost: 44 (5th level mage divination spell)
** Credits:
**     27 Aug 96   Chronos@AtFoD wrote the original of this spell.
**     23 Nov 97   Cyanide overhauled and twisted the spell to his own
**                 selfish ends. Little original code remains.
*/

#define COST 44

#include <m_spells.h>
#include <magic.h>

inherit SPELL;

int cast_eye(string str, int obj) {
   object eye;

   seteuid(getuid());
   eye = clone_object(M_OBJ(eye_ob.c));
   if (!eye) {
      write("Your spell fizzles. Please notify Cyanide.\n");
      return SPELL_CAST;
   }

   if (!obj) {
      if (!cast_spell(TP, COST)) return NO_STRENGTH;
      obj = query_caster_level(TP, "wizard");
  
      write("You summon a floating eye with a quick incantation.\n");
      say(TPN+" chants a mystical incantation.\n");
   }

   tell_room(environment(TP), 
    "A floating eyes appears in the center of the room.\n");
   eye->move(environment(TP));

   eye->start_spell(TP, obj);
   return SPELL_CAST;
}
string spellcraft() {
    return (@EndSpell
Wizard Eye (Level V Wizard Spell - Divination)

Cost: 44 Spell Points

When this spell is employed, the wizard creates
an invisible sensory organ that sends him visual
information. It can be directed by the wizard as
if it was his own body.
EndSpell
    );
}
/* EOF */
