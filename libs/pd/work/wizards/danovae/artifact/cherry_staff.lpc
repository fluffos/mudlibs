
#include <std.h>
inherit WEAPON;

void create() {
   ::create();
   set_id( ({ "chery staff","staff" }) );
   set_name("Cherry Staff");
   set_short("%^RESET%^%^MAGENTA%^Ch%^BOLD%^er%^WHITE%^ry S%^MAGENTA%^ta%^RESET%^%^MAGENTA%^ff%^RESET%^");
   set_long("A beautiful staff made from the wood of a cherry tree. It has an etched spiral body that arches up to the head where a unicorn's head is carved. In place of the horn is a curious spike made of %^BOLD%^%^MAGENTA%^rose-quartz%^RESET%^. at the foot of the staff is a steel ball. It looks as though it has been pounded into the ground many times.");
   set_mass(30);
   set_value(200);
   set_wc(8);
   set_ac(1);
   set_type("blunt");
}

void init() {
   ::init();
   add_action("slam","slam");
}

int slam(string str) {
   object *inv;
   int i;
   if(str != "staff")
   return notify_fail("Slam what?\n");
   if(!this_object()->query_wielded()) return 0;
   inv = all_inventory(environment(this_player()));
   write("You slam your staff into the ground, bringing order to chaos.\n");
   say(this_player()->query_cap_name()+" slams "
      +this_player()->query_possessive()+" staff into the ground.\n");
   for(i=0; i<sizeof(inv); i++) {
   if(!living(inv[i])) continue;
   inv[i]->cease_all_attacks();
   }
   return 1;
}

int unique(string str) {
   object *objec;
   string st;
   int i, a;
   string *warm, *arms;

   st = this_player()->query_name()+"cherry_staff";
   objec = filter(objects(), (: $1->is_weapon() :));
   i = sizeof(objec);
   while(i--) {
     if (clonep(objec[i])) 
     if (objec[i]->id(st))
   return 0;
}
}
int query_auto_load() { if(this_player()->query_level() >= 20) return 1; }



