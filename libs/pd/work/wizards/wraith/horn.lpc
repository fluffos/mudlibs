#include <dquest.h>
#include <std.h>
inherit OBJECT;
int blows;
void init() {
  ::init();
  add_action("blow_horn", "blow");
}
void create() {
    ::create();
set_name("horn");
set_short("a Horn of Blasting");
set_long("A horn made of brass and etched with several intracate patters.  It looks slightly worn from time and weathering. <blow horn> to use.");
set_id(({"horn", "horn of blasting", "Horn of Blasting"}));
set_weight(10);
set_curr_value("gold",100);
 blows=0;
}
int blow_horn(string what) {
   int dmg, i, x;
   object *ob, tp, env;
   tp = this_player();
   if(environment(tp)->query_property("no magic"))
     return notify_fail("You cannot use that here.\n");
   blows = blows+1;
   env = environment(tp);
   ob = all_inventory(env);
   x=0;
   for (i=1;i-1 < sizeof(ob);i++) {
if (what!="horn") return 0;
if (blows >= 4)
   {
    write("The horn plays but doesn't seem to produce the booming sound it once did.");
    return 1;
}
if (ob[i-1]->is_living() && ob[i-1] != tp && !wizardp(ob[i-1]) &&
          ob[i-1]->query_level() >= 3) {
         x = 1;
write("%^BOLD%^BLUE%^The blare of the horn stuns "+ob[i-1]->query_cap_name()+"!%^RESET%^");
  dmg = ob[i-1]->set_paralyzed(random(7)+2);
}
}
return 1;
}
