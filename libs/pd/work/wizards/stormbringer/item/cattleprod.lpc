#include <std.h>
inherit WEAPON;
void create() {
 ::create();
   set_name("cattle prod");
   set_short("a cattle prod");
   set_long("a cool cattle prod");
   set_weight(1);
   set_id(({ "cattle prod" , "prod" }));
   set_wc(30);
   set_type("blunt");
}
int prod(string str) {
   object ob;
   ob = present(str, environment(this_player()));
   if (!ob) {
      write("You do not see that here.");
      return 1;
   }
   if (present("gag", ob)) present("gag", ob)->remove();
   if (present("pillow", ob)) present("pillow", ob)->remove();
   write("You shock "+ob->query_cap_name()+"!");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
         " shocks "+ob->query_cap_name()+"!", ({ ob, this_player() }));
   tell_object(ob, this_player()->query_cap_name()+" shocks you!");
   ob->force_me("restartheart");
   return 1;
}
void init() {
 ::init();
   add_action("prod", "prod");
}
