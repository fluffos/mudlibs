#include <std.h>
#include <discastle.h>
inherit MONSTER;
object all;
int i;
void create() 
{
        ::create();
        set_name("brigand");
        set("short", "A Brigand");
        set("long", "A rather scary looking thug. He looks you over for a moment and then suddenly pulls something from behind his back.");
        set("id", 
                ({"monster","brigand","thug"})
        );
        set("race", "raknid");
        set_body_type("raknid");
        set_gender("male");
                set_class("rogue");
        set_subclass("thug");
        set_spell_chance(40);
        set_spells( ({"stab", "circle"}) );
        new(WEAP"blackjack")->move(this_object());
        this_object()->force_me("wield blackjack");
        new(WEAP"poisondagger")->move(this_object());
        this_object()->force_me("wield knife");
        new(WEAP"poisondagger")->move(this_object());
        this_object()->force_me("wield knife");
        new(WEAP"poisondagger")->move(this_object());
        this_object()->force_me("wield knife");
        add_money("gold", 5000);     
        set_level(50);
                set_exp(175000);
}                                            
void bash(object ob) {
  
  this_object()->force_me("backstab "+ob->query_name());
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
