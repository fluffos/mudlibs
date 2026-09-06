inherit "/ai/memory";

int wander_tick;

string query_module_name() { return "hunter"; }

void on_death(object who) {
   if( who->query_product_aspect() ) {
       //command("say on_death: "+who->query_name()+" is butcherable", environment());
      command("unhold spear",environment());
      command("hold knife",environment());
      delay_command("butcher corpse",4);
   }
}

void on_hunger() {
   object ob;
   command("say on_hunger", environment());
   foreach( ob : all_inventory(environment()) )
      if( ob->query_is_edible() ) {
         //command("say on_hunger: eating "+as_lpc(ob));
         command("eat "+ob->query_name());
         return;
      }
   // didn't have any food, cry
   command("grumble",environment());
   environment()->wander();
}

void on_thirst() {
   object ob;
   command("say on_thirst", environment());
   // look for drinkables in the room
   foreach( ob : all_inventory(environment(environment())) )
      if( ob->query_is_drinkable() ) {
         //command("say on_thirst: drinking "+as_lpc(ob));
         command("drink "+ob->query_name());
         return;
      }
   // wasn't near a river, gasp
   command("pant",environment());
   environment()->wander();
}

void on_sight(object ob, object source) {
   if( ob->query_dead() )
      on_death(ob);
   else
      ::on_sight(ob, source);
}

void on_tick() {
   wander_tick++;
   object ob;

   if ( environment()->query_is_player() ) {
      command( "emote coughs out an AI module.", environment());
      destruct(this_object());
      return;
   }
   if ( member( (["Butcher","Cut"]), environment()->query_action_name() ) ) {
      //command("say on_tick: butchering/cutting", environment());
      return;
   } else if ( ob = single_present("corpse", environment(environment())) ) {
      //command("say on_tick: noticed corpse", environment());
      on_death(ob);
   } else if ( ob = single_present("skin", environment()) ) {
      //command("say on_tick: noticed i have an uncut skin", environment());
      command("unhold spear",environment());
      command("hold knife",environment());
      command("cut skin",environment());
   } else if ( wander_tick % 4 == 0 ) {
      //command("say on_tick: wandering", environment());
      environment()->wander();
   } else if ( environment()->query_form() != "polearm" ) {
      //command("say on_tick: noticed i'm not wielding spear", environment());
      command("unhold all",environment());
      command("hold spear",environment());
   } else if ( ob = single_present("all", environment(environment()), (: $1->query_product_aspect() && $1->query_is_living() :) ) ) {
      //command("say on_tick: spotted prey >> "+ob->query_name(),environment());
      command("kill "+ob->query_name(), environment());
   } else {
      //command("say on_tick: nothing interesting to do",environment());
   }
}
