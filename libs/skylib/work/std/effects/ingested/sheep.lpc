#include <effect.h>
mixed determ;
string query_classification() { return "misc.transforming.sheep"; }

string query_shadow_ob() { return "/std/shadows/ingested/ensheep"; }

int beginning( object player, int time ) {
   tell_object( player, "Your hair turns white and spreads "
               "throughout your body! Uh-oh...  You believe "
               "you have turned into a sheep!\n");
   tell_room(environment(player), capitalize(player->query_name())+ 
              "'s hair suddenly turns white and grows longer and fluffier "
              "as transmogrification into a sheep occurs!\n",
              player);
   player->submit_ee("fluff_worry", ({ 10, 20 }), EE_CONTINUOUS);
   player->submit_ee( 0, time, EE_REMOVE );
   player->add_alias("sheep");
   return time;

}

int merge_effect( object player, int time1, int time2 ) {
   int duration;

   duration = time2 + player->expected_tt();
   player->submit_ee( 0, duration, EE_REMOVE );
   return duration;
} /* merge_effect() */
 
void end( object player, int time ) {
   tell_object( player, "Finally your unnatural "
             "fluffiness abates!\n");
   tell_room(environment(player), "All of the "
              "cute fluffy sheep's wool suddenly falls out, leaving "+
              capitalize(player->query_name())+ " crouching "
              "down, spitting out the grass formerly being "
              "munched.\n", player);
   if(player->query_name() !="sheep")
    player->remove_alias("sheep");
} /* end() */

void fluff_worry( object player, mixed a, int id ) {
   switch (random(5)) {
    case 0:
      player->new_parse("'BAAAAAAA!!!!!");
      break;
    case 1:
      tell_object( player, "You are feeling VERY worried.\n");
      tell_room( environment( player ), capitalize(player->the_short())+
           " looks worried about something.\n",
           ({ player }) );
     break;
    case 2:
      tell_object( player, "You look around- sheep-shaggers "
                 "everywhere! Flee!\n");
      tell_room( environment( player ), capitalize(player->the_short())+
           " looks at you with a wild look in its eye.\n",
           ({ player }) );
      break;
    case 3:
      tell_object( player, "You bleat.\n");
      tell_room( environment( player ),  capitalize(player->the_short())+
           " bleats.\n",
           ({ player }) );

      break;
    case 4:
      tell_object( player, "You munch on some grass you've found.\n");
      tell_room( environment( player ),  capitalize(player->the_short())+
           " finds a bit of grass and begins munching.\n",
           ({ player }) );
      break;
    default:
      player->new_parse("BAAAAAAA!!!!!");
      break;

   }
}