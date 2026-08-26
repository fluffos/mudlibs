/*
** File: dispel.c  (Dispel Magic)
** Purpose: The 3rd level Universal spell for mages and priests.
** Cost: 20 SP or TP
** Credits:
**   23 Nov 97   Cyanide created the file.
*/

#include <magic.h>
#include <mudlib.h>

#define COST 20
#define SYNTAX "Syntax: cast dispel at <target|\"here\">\n"  

// Prototypes:
int do_dispel(object, int);

inherit SPELL;

int invoke_dispel(string str, int obj) {
   object *inventory, target, thing;
   int x, num, lvl;

   if (!str) str = "NONE";
   if (str=="NONE") target = TP->query_current_attacker();
   if (str=="here") target = environment(TP);
   if (str=="me") target = TP;
   if (!target) target = present(str, environment(TP));
   if (!target) {
      write(SYNTAX);
      return NO_TARGET;
   }     
   
   if (living(target) && target!=TP)
      if (!check_valid_targ(TP, target)) return INVALID_TARGET;

   if (!obj) {
      if (invoke_spell(TP, COST)) return NO_STRENGTH;

      lvl = query_caster_level(TP, "priest");
      obj = lvl;
      write("You begin invoking Dispel Magic...\n");
      say(TPN+" begins mumbling prayers...\n");
      if (living(target))
         str = target->query("cap_name");
      else
         str= "the room";

      tell_room(environment(TP), TPN+" points a finger at "+
         str+"!\n", ({ TP, target }) );
      write("You successfully cast dispel magic at "+str+".\n");
      tell_object(target, TPN+" points a finger at you!\n");
   } else {
     lvl = obj;
   }

   if (!check_magic_resist(lvl,target,COST,0)) return MAGIC_RESISTANCE;  
   
   num = 0;

   thing = present("#ANTIMAGIC_SHELL#", target);
   if (thing) {
      tell_object(target, "Your anti-magic shell protects you from the "+
       "dispel.\n");
      return 0;
   } else {  
      inventory = all_inventory(target);

      for (x=sizeof(inventory)-1; x>=0; x--)
         num += do_dispel(inventory[x], lvl);
   }

   switch (num) {
       case 0 : str = "You dispelled nothing.\n"; break;
       case 1 : str = "You dispelled a single enchantment\n"; break;
       default : str = "You dispelled "+num+" enchantments.\n"; break;
   }

   write(str);
   return SPELL_CAST;
}


int do_dispel(object ob, int dispel_lvl) {
   string creator;
   int ob_lvl, chance_d;

   if (!ob) return 0;

   // If it's not enchanted, we ignore it.
   if (!ob->query("enchantment")) return 0;

   creator = ob->query("caster");
   if (!creator) creator="_nobody";
   creator = lower_case(creator);

   // We only dispel potions and enchantments (which have no short).
   if (!ob->id("potion") && ob->query("short")) return 0;

   ob_lvl = ob->query("level");
   if (!ob_lvl) ob_lvl = 12;

   // The percentage to dispel is the dispel level - caster level...
   chance_d = dispel_lvl - ob_lvl;

   // Times 5...
   chance_d *= 5;

   // Plus 50 (in percent.)
   chance_d += 50;

   // A caster automatically dispels his/her own spells.
   if (creator == TP->query("name")) chance_d = 1000;

   if ( (random(100)+1) < chance_d) {
      ob->remove();
      return 1;
   } else {
      return 0;
   }

}
