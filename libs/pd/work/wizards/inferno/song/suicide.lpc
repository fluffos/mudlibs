#include <std.h>
inherit SONG;

void create() {
 ::create();
   set_verses(({
     "Comming quickly, true is lore,",
     "Quicker now than e'er before,",
     "Shadows gather, Take my soul;",
     "A sleep eternal, Black as coal."
   }));
   set_type("other");
   set_song_name("chaunt du cygne");
}

int check_sing(object o) {
   if (o->query_subclass() == "bard" && o->query_skill("euphony") >= 230)
       return 1;
}

void finish_song() {
   object ob, tp;
   tp = this_object()->query_caster();
   ob = this_object()->query_target();
   if (!ob || !present(ob, environment(ob)) ||
	ob->query_race() == "vampire") {
      message("info", "Nothing happens.", environment(ob));
      return;
   }
   if (wizardp(ob) && !wizardp(tp)) {
      message("info", "Nothing happens.", environment(ob));
      return;
   }
   message("info", "%^BOLD%^Your body shimmers out of existance and you "
	"become an etheral presence.", ob);
   message("info", "%^BOLD%^"+ob->query_cap_name()+"'s body shimmers out "
	"of existance and "+ob->query_subjective()+" becomes an etheral "
	"presence.", environment(ob), ob);
   ob->stop_hunting();
   ob->cease_all_attacks();
   ob->set_ghost(1);
   if (ob->is_monster()) {
	all_inventory(ob)->remove();
	all_inventory(ob)->remove();
	ob->remove(); } else
   ob->force_me("save");
}
