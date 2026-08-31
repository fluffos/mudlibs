#include <std.h>

inherit MONSTER;

int is_invincible();
int transform(object obbo);

void create()
{
 ::create();

        set_name("shadow being");
        set_id(({"lesser shadow being", "being", "shadow", "shadow being" }));
        set_short("lesser shadow being");
        set_long("This being is created almost entirely out of dark "
        "mana.  It doesn't seem to have a stable form, instead shifting "
        "with the shadows of the environment.  It's ethereal presence "
        "hides its deadly and very tangible nature.");
        set_alignment(-200);
        set_race("shadow");
        set_property("transformed", 0);
        set_gender("neuter");
        set_body_type("human");
        set_level(30);

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
                meob->set_stats("strength", obbo->query_stats("strength")*4/5);
                meob->set_stats("intelligence", obbo->query_stats("intelligence")*4/5);
                meob->set_stats("charisma", obbo->query_stats("charisma")*4/5);
                meob->set_stats("dexterity", obbo->query_stats("dexterity")*4/5);
                meob->set_stats("wisdom", obbo->query_stats("wisdom")*4/5);
                meob->set_stats("constitution", obbo->query_stats("constitution")*4/5);
                meob->new_body();

                meob->set_property("transformed", 1);
        
                message("room", "The shadow being begins to transform!",environment(meob));
                message("you", "The shadow being takes your form!", obbo);
                return;

                }
        }
}
