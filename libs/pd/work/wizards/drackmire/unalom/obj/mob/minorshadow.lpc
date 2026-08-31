#include <std.h>

inherit MONSTER;

int is_invincible();
int transform(object obbo);

void create()
{
 ::create();

        set_name("shadow being");
        set_id(({"minor shadow being", "being", "shadow", "shadow being" }));
        set_short("minor shadow being");
        set_long("This being is created almost entirely out of dark "
        "mana.  It doesn't seem to have a stable form, instead shifting "
        "with the shadows of the environment.");
        set_alignment(-200);
        set_race("shadow");
        set_property("transformed", 0);
        set_gender("neuter");
        set_body_type("human");
        set_level(20);

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
                meob->set_level(obbo->query_level()*4/7);
                meob->set_short(obbo->query_short());
                meob->set_long(obbo->query_long());
                meob->set_body_type(obbo->query_body_type());

                meob->new_body();

                meob->set_property("transformed", 1);
        
                message("room", "The shadow being begins to transform!",environment(meob));
                message("you", "The shadow being takes your form!", obbo);
                return;

                }
        }
}
