#include <std.h>
#include <zexor.h>
inherit WEAPON;
int weapon_hit(object atk);

create() {
   ::create();
   set_name("club");
   set_short("A spiked two-handed club");
   set_long("This is a large wooden club with large spikes "
       "jutting out from random places, all sharp.");
   set_weight(25);
   set_value(225);
   set_wc(7);
   set_type("blunt");
   set_id(({"club", "spiked club", "two-handed club", "two handed club"
       "spiked two-handed club", "spiked two handed club", "weapon"}));
   set_hands(2);
   set_hit((:weapon_hit:));
}
int query_auto_load() { return 1; }

int weapon_hit(object atk) {
int result;
if(random(100) < 25) {
write("You leave a gash in your opponent's gut with a spike from your club");
say(""+ this_player()->query_cap_name() +" cuts their opponent with a spike on their club.");
result = (random(50))+((this_player()->query_level()));
return result;
   }
}
