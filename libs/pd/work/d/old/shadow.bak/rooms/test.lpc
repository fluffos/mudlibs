int check_skill(string str) {
   object ob;
   if (!str) return 0;
   ob = present(str, this_player());
   if (!ob) return 0;
   if (ob != this_object()) return 0;
   if (this_player()->query_paralyzed()) return 0;
   if (this_player()->query_skill("blade") < 20) {
     write("You are not skilled enough to wield this blade.");
     return 1;
   }
   return 0;
}

void init() {
 ::init();
   add_action("check_skill", "wield");
}
