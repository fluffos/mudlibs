/*
** File: images.c  (Level 2 wizard illusion spell)
** Cost: 12 Spellpoints
** Credits:
**   09 Feb 98   Cyanide created the spell.
*/

#define COST 12

#include <mudlib.h>
#include <m_spells.h>

inherit SPELL;

int cast_images (string str, int obj) {
   object images;

   seteuid(getuid());

   write("You begin casting Mirror Image.\n");
   say(TPN + " begins to chant an arcane verse...\n");

   images = clone_object(M_OBJ(images_ob));
   if (!images) {
     write("Spell failed. Please notify Cyanide.\n");
     return 0;
   }

   if (present("#IMAGES#", TP)) {
      write("You already have a Mirror Image spell active.\n");
      return 0;
   }

   if (!obj) {
      obj = query_caster_level(TP, "wizard");
      if (!cast_spell(TP, COST)) return 0;
   }

   images->move(TP);
   images->begin_spell(TP, obj);

   return 1;
}

string spellcraft() {
   return (@EndCraft
Mirror Image (Wizard  Level II  Illusion/Phantasm)

Area of Effect: Caster		Saving Throw: None
Cost: 20 SP
Duration: 1 minute per level

    When a mirror image spell is invoked, the spellcaster causes from 
two to eight exact duplicates of himself to come into being around him.
These images do exactly what the wizard does. Since the spell causes 
a blurring and slight distortion when it is cast, it is impossible for 
opponents to be certain which are the illusions and which is the actual
wizard. When an image is struck by an attack, magical or otherwise, it 
disappears, but any other existing images remainintact until struck. At 
the end of the spell duration, all surviving images wink out.
EndCraft
   );
}

/* EOF */
