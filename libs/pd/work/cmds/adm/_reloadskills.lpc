//  _reloadskills

#include <daemons.h>

string sub;
mapping classes=([ "fighter":({"berserker","paladin","ranger","warrior"}), 
                 "mage":({"necromancer","pyromancer","sorcerer","wizard"}), 
                 "clergy":({"cleric","druid","kataan","monk"}), 
                 "rogue":({"assassin","scout","thief","thug"}), 
                 "wanderer":({"bard","gypsy","jester","swashbuckler"}), 
               ]);
string *base_skills=({"melee","attack","defense","double wielding","knife","blunt","projectile","flail","blade","axe","ranged","murder","perception","bargaining","stealth"});

string query_subclass() { return sub; }

int cmd_reloadskills(string s) {
   mapping sk, sk_complete;
   string *sk_key;
   string *cl, *sc;
   int i, x, y;
   write("Reloading skills table...");
   sk=([]);
   sk_complete=([]);
   i=sizeof(cl=keys(classes));
   while(i--) {
     x=sizeof(classes[cl[i]]);
     while(x--) {
       sub=classes[cl[i]][x];
       sk=SKILLS_D->init_skills(cl[i]);
       y=sizeof(sk_key=keys(sk));
       while(y--) {
         if(!sk_complete[sk_key[y]]) sk_complete[sk_key[y]]=(["classes":({}), "subclasses":({})]);
         sk_complete[sk_key[y]]["classes"] += ({ cl[i] });
         sk_complete[sk_key[y]]["subclasses"] += ({ sub });
       }
     }
   }
   i=sizeof(cl=keys(sk_complete));
   
   while(i--)
     SKILLS_D->add_skill(sk_complete[cl[i]]["classes"], sk_complete[cl[i]]["subclasses"], cl[i]);
   i=sizeof(base_skills);
   while(i--)
     SKILLS_D->add_skill("all","all",base_skills[i]);
   write("Complete.");
   return 1;
}

