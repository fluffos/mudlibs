#include <wiz.h>
inherit OBJECT;

int squish;
private int squish_level;

void set_squish_level(int squish){ squish_level=squish; }
int squish_level(){ return squish_level; }

string query_type(){ return "alcoholic"; }
int query_strength(){ return random((this_player()->query_level())/3*2*squish_level())+1; }

void init(){::init(); add_action("drinkie","drink"); }

void make_cup(object tp) {
   object cup;
   cup = new(OBJECT);
   cup->set_short("An empty sippie cup"); 
   cup->set_long("An empty sippiecup which once contained a killer squishie.");
   cup->set_id(({ "cup", "sippie cup", "empty cup" }));
   cup->set_value(15);
   cup->set_weight(1);
   cup->set_destroy(1);
   cup->move(tp);
}
int drinkie(string str) { 
   if(!id(str))return 0;
   if(environment(this_object()) != this_player()) {
      notify_fail("The squishie is on the ground, pick it up.\n");
      return 0;
   }
      if(!this_player()->add_quenched(squish_level()*this_player()->query_level())) {
         notify_fail("You brain is toonumb!\n");
         return 0;
      }
      if(!this_player()->add_intox(squish_level()*this_player()->query_level())) {
         notify_fail("You will pass out if you drink that!\n");
         return 0;
      }
   this_player()->heal(squish_level()*(this_player()->query_level()));
   write("As you chug down the squishie...\n"
         "you feel...\n\n%^WHITE%^%^BOLD%^BRAIN FREEZE!!%^RESET%^\n");
   say(this_player()->query_cap_name()+" almost passes out from brain freeze.",
        this_player());
   make_cup(this_player());
   remove();
   return 1;
}
