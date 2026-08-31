inherit "/std/weapon";

 
create() {
    ::create();
   set_short("A leather paddle");
   set_name("A leather paddle");
   set_id( ({"paddle"}) );
   set_long ("A leather paddle");
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
   add_action("paddle","paddle");

}

int paddle(string str) {
   object ob;
   if(!str || str=="") {
   notify_fail("Whom needs to be paddled?\n");
   return 0;
   }
   ob = present(str, environment(this_player()));
   write("You paddle "+ob->query_cap_name()+"'s rosy rear.");
   say(this_player()->query_cap_name()+" paddles "+ob->query_cap_name()+"'s rosy rear.");
   message("info", "A resounding thwap echos around the room.", this_player());
   ob->force_me("say Thank you, Sir!");

   ob->force_me("moan");
   return 1;
}

