inherit "/std/weapon";

 
create() {
    ::create();
   set_short("A cat-of-nine-tails");
   set_name("A cat-of-nine-tails");
   set_id( ({"whip"}) );
   set_long ("A cat-of-nine-tails");
   set_weight(90);
   set_curr_value("gold", 0);
   set_wc(10);
   set_ac(2);
   set("skill level", 75);
   set_type("blunt");

   set_wield("ohhh");
   set_unwield("ahhh");
}
void init() {
   ::init();
   add_action("whip","whip");

}

int whip(string str) {
   object ob;
   if(!str || str=="") {
   notify_fail("Whom needs to be whipped?\n");
   return 0;
   }
   ob = present(str, environment(this_player()));
   write("You whip "+ob->query_cap_name()+"'s tenatious thighs.");
   say(this_player()->query_cap_name()+" whip "+ob->query_cap_name()+"'s tenatious thighs.");


   ob->force_me("say Oh my God, Sir!");
   ob->force_me("groan");
   return 1;
}
