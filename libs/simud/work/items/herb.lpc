#include <const.h>
inherit "/obj/food";

string colour;

TASTE( "It tastes groovy, man." )

string query_look() {
   int x = this_player()->query_skill("herbalism");
   if (x == 0)
      return "A small bunch of "+colour+" herbs.";
   else if (x < 5)
      this_player()->practice_skill("herbalism");
   switch (colour) {
      case "yellow":
         return "A small bunch of yellow herbs. These little guys are "+
                "a mage's best friend. Eating them will reattune you "+
                "to the plane of mana and will slowly restore your "+
                "personal stores of magical energy.";
      case "black":;
         return "A small bunch of black herbs. Despite their bitter "+
                "taste, these herbs do wonders for restoring a person's "+
                "endurance.";
      case "green":
         return "A small bunch of green herbs. Eating these herbs will "+
                "cause your body to begin healing itself at an increased "+
                "rate. There is a lot of energy in one of these things, "+
                "so you would be best served if you waited until you were "+
                "quite injured before using it.";
   }
   return 0;
}

create() {
   ::create();
   colour = ({"yellow","black","green","green"})[random(4)];
   set_edible( 1 );
   set_use_msg( "~Name ~verbchew the "+colour+" herbs." );
   set_gettable( 1 );
   set_droppable( 1 );
   set_weight( 5 );
   set_value( 1000 );
   set_distant( "a bundle of "+colour+" herbs" );
   set_specific( "the bundle of "+colour+" herbs" );
   set_plural( "bundles of "+colour+" herbs" );
   set_name( "herbs" );
   set_alt_name( ({"herb", colour+" herb", colour+" herbs",
                   "bundle of herbs", "bundle of "+colour+" herbs"}) );
   set_type( "food" );
}

int on_consume( int max ) {
   object ob = clone_object("/obj/regen");
   ob->set_size(20);
   ob->set_speed(2);
   switch (colour) {
      case "yellow": ob->set_type("mana"); break;
      case "black":  ob->set_type("endurance"); break;
   }
   ob->start(this_player());
   return ::on_consume( max );
}
mapping query_aspects() {
   return ([ C_HERB, C_FOOD ]);
}
