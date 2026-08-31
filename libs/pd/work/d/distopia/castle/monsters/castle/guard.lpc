#include <std.h>
#include <discastle.h>
inherit MONSTER;
void create() 
{
        ::create();
        
        set_name("guard");
        set("short", "A caravan guard");
        set("long", "Hired to guard the merchant, he will fight anyone that he sees as a threat.");
        set("id", 
                ({"monster","guard"})
        );
        set("race", "elf");
        set_body_type("elf");
        set_gender("male");
		set_class("fighter");
        set_subclass("warrior");
        set_spell_chance(60);
        set_spells( ({"slash", "parry"}) );
        new(WEAP"halberdier")->move(this_object());
      new(ARM"steelchainmail")->move(this_object());
 		  new(ARM"ironplate")->move(this_object());
       new(ARM"steelbracers")->move(this_object());
        new(ARM"ironboots")->move(this_object());
        set_skill("projectile", 500);
        add_money("gold", 200);     
        this_object()->force_me("wield halberdier");
        this_object()->force_me("wear all");
        set_level(40);
}                                            
void bash(object ob) {
  
  this_object()->force_me("kill brigand");
  this_object()->force_me("kill brigand 2");
    this_object()->force_me("kill bandit");
      this_object()->force_me("kill bandit 2");
}
void init() {
   object *all;
   int i;
   ::init();
   all = all_inventory(environment(this_object()));
   i = sizeof(all);
   while (i--) {
     if (!all[i]->is_player()) continue;
     if (all[i]->is_player())
        call_out("bash", 3, all[i]);
   return;
   }
}		
