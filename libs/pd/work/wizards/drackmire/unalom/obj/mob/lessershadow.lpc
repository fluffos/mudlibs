#include <std.h>

inherit MONSTER;

int is_invincible();
int transform(object obbo);
void shadow_aggression();

void create()
{
 ::create();

        set_name("shadow being");
        set_id(({"lesser shadow being", "being", "shadow", "shadow being" }));
        set_short("lesser shadow being");
        set_long("This being is created almost entirely out of dark "
        "mana.  It doesn't seem to have a stable form, instead it shifts "
        "with the shadows of the environment.  Its ethereal presence "
        "hides its deadly and very tangible nature.");
        set_alignment(-200);
        set_race("shadow");
        set_property("transformed", 0);
        set_gender("neuter");
        set_body_type("human");
        set_aggressive("shadow_aggression");
        set_level(30);

}

void shadow_aggression(){
  if(this_player()->query_level()>20){
    transform(this_player());
    kill_ob(this_player());
  }
}

int is_invincible(){
 
if(this_object()->query_hp()>=this_object()->query_max_hp()&&!sizeof(this_object()->query_attackers())){
  transform(this_player());
  return 0;
  } 
}


int transform(object obbo){
        object meob;

        if(!sizeof(this_object()->query_attackers())){
        meob = this_object();
        
if(meob->query_property("transformed")==1||meob->query_name()!="shadow being") { return 0; }
                else {

                meob->set_class(obbo->query_class());
                meob->set_subclass(obbo->query_subclass());
                meob->set_level(obbo->query_level()*3/5);
                meob->set_short(obbo->query_short());
                meob->set_long(obbo->query_long());
                meob->set_body_type(obbo->query_body_type());
                meob->set_stats("strength", meob->query_stats("strength")+obbo->query_stats("strength")/10);
                meob->set_stats("intelligence",meob->query_stats("intelligence")+obbo->query_stats("intelligence")/10);
                meob->set_stats("charisma", meob->query_stats("charisma")+obbo->query_stats("charisma")/10);
                meob->set_stats("dexterity",meob->query_stats("dexterity")+obbo->query_stats("dexterity")/10);
                meob->set_stats("wisdom", meob->query_stats("wisdom")+obbo->query_stats("wisdom")/10);
                meob->set_stats("constitution",meob->query_stats("constitution")+obbo->query_stats("constitution")/10);
                meob->new_body();

                meob->set_property("transformed", 1);
        
                message("room", "%^BOLD%^BLACK%^The shadow being begins to transform!%^RESET%^",environment(meob));
                message("you", "%^BOLD%^RED%^The shadow being takes your form!%^RESET%^", obbo);
                return;

                }
        }
}
