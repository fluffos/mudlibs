// sigma the trick or treater
#include <std.h>
#include <halloween.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("sigmatt");
   set_short("Sigma, the trick or treater");
   set_long("Sigma goes door to door collecting candy.");
   set_gender("male");
   set_moving(1);
   set_speed(9);
   set_level(2);
   set_race("mascot");
   set_body_type("fowl");
   set_id(({ "bird", "mascot", "dodo", "sigma" }));
   set_max_hp(999999999);
   set_hp(query_max_hp());   
   new(OBJS "bag")->move(this_object());
   this_object()->force_me("wield bag");   
}

void heart_beat()
{
 ::heart_beat();
 if (random(1000) > 950)
   {
    message("info", "Candy leaks out of Sigmas trick or treating bag.", environment(this_object()));
    new(OBJS "candy")->move(environment(this_object()));
   }
}
   
