#include <std.h>
#include <roston.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("Pyromancer");
    set_short("%^BOLD%^%^BLACK%^Evil %^RED%^P%^YELLOW%^y%^RED%^r%^YELLOW%^o%^RED%^m%^YELLOW%^a%^RED%^n"
      "%^YELLOW%^a%^RED%^n%^YELLOW%^c%^RED%^e%^YELLOW%^r%^RESET%^");
    set_long("This man was sent on the jounery to Roston with the drows "
      "just in case they failed to take over the lands of Roston, he would "
     "be able to destory the town with a lift of his finger. He is well "
     "known to all the people of this world, he has taken out more towns "
     "then whole races have. He lives to obey the drows because they killed "
     "his greatest ememy the Great Fire Dragon. He used to be a very shy "
     "and lonely man, now he does the work of armys in a matter of seconds "
     "some belive its because of the power the helmet he wears, is unbeliveable. "); 
    set_id(({"pyromancer", "evil pyromancer","evil","saint"}));
    set_race("saint");
    set_class("mage");
    set_subclass("pyromancer");
    set_spell_chance(40);
    set_spells( ({"firebomb with big firebreather","shroud","inferno"}) );
    set("aggressive", 35);
    set_skill("magic attack", 300);
    set_skill("conjuring", 300);
    set_level(70);
    set_exp(1100000);
    set_body_type("human");
    set_gender("male");
    new(DROWOBJ"helmet")->move(this_object());
    new("/wizards/detach/drink")->move(this_object());
    new("/wizards/detach/drink")->move(this_object()); 
    new("/wizards/detach/drink")->move(this_object());
    new("/wizards/detach/drink")->move(this_object());
    new("/wizards/detach/drink")->move(this_object());
    new("/wizards/detach/drink")->move(this_object());
    new("/wizards/detach/drink")->move(this_object());
    new("/wizards/detach/drink")->move(this_object());
    new("/wizards/detach/drink")->move(this_object());
    new("/wizards/detach/drink")->move(this_object());

    set_heart_beat(1);
}                                             
void init()   
{
 ::init();
}

void catch_tell(string str) {
   string person;
   if (!sscanf(lower_case(str), "%s dies a horrible death.", person)) return;
   if (!find_player(person)) return;
   message("info", "%^BOLD%^%^BLUE%^Pyromancer shouts:%^RESET%^ Let the "
     "life of "+capitalize(person)+" be a lesson to those who try to oppose me!", users());
}

void heart_beat()
{
 ::heart_beat();
 if (!wielded_sword)
   {
    this_object()->force_me("wear helmet");
    wielded_sword = 1;
   }
}


