#include <const.h>
#include <emote.h>

int seeking_food, seeking_drink;

// Beasts do not talk, nor do they understand speech.

varargs void on_soul( int type, object actor, object target, string text ) {
   // Beasts are only interested in souls that touch and are directed at them.
   if( !(type | ATT_PHYSICAL) || target != this_object() )
      return 0;
}

varargs void on_offer( object *offer, object giver ) {
   object ob;

   foreach( ob : offer )
   if( ob->query_edible() ) {
      command("accept");
      return;
   }
   command("reject");
}

varargs void on_hunger() {
   // I'm hungry! Look for food.
}

varargs void on_thirst() {
   // I'm thirsty! Look for water.
}

void on_tick() {
}