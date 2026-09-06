int main() {
   object ob;

   foreach( ob : all_inventory(environment(this_player())) ) {
      if( ob->query_is_ocean() ) {
         clone_object("/world/game/fishing")->move(this_player());
         return 1;
      }
   }

   notify_fail("You can't fish here.\n");
   return 0;
}
