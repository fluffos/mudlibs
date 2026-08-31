#include <std.h>
#include <common_fun.h>
inherit SONG;

object pyr;
object room;

void create() {
    ::create();
    set_verses(({
	"The great cleanser kisses the land",
	"Sweeping away evil with it's glowing hand!",
      }));
    set_type("attack");
    set_song_name("Canticle of Flame");
}

int check_sing(object o) {
    if (o->query_subclass() == "bard" && o->query_skill("euphony") >= 100)
	return 1;
    if (o->query_subclass() == "gypsy" && o->query_skill("euphony") >= 150)
	return 1;
    if (o->query_subclass() == "red" && o->query_level("flame") >= 150)
	return 1;
}

void finish_song() {

    object a;
    int i;
    int result;
    pyr = (object)this_player();
    room = environment(pyr);
    a = all_inventory(room);

    message("info", "%^RED%^A roaring wall of flame bursts from "+this_player()->query_cap_name()+"'s body.",room, this_player());
    message("info", "%^RED%^A roaring wall of flame bursts from your body.",this_player());

    for(i=0; i<sizeof(a); i++) {

	result = BALANCE_D->get_damage(this_player(), a[i], 1,({ "euphony", "entertainment"}),({"intelligence"});

	  if (a[i]->query_name() != this_player()->query_name() && a[i]->is_living())
	  {
	      if (a[i]->query_race() == "dragon")
	      {
		  if (a[i]->query_subclass() == "red")
		  {
		      message("info", "%^CYAN%^The fire barely touches your scales.%^RESET%^",a[i]);
		      message("info", "%^CYAN%^The fire barely touches "+a[i]->query_cap_name()+" scales.%^RESET%^",room, a[i]);
		      result = result / 4;
		  }
		  else
		  {
		      message("info", "%^RED%^The fire envelopes %^BOLD%^you%^RESET%^%^RED%^, scorching your scales.%^RESET%^",a[i]);
		      message("info", "%^RED%^The fire envelopes %^BOLD%^"+a[i]->query_cap_name()+"%^RESET%^%^RED%^, scorching "+a[i]->query_possessive()+" scales.%^RESET%^",a[i]);
		  }
	      }
	      else if (a[i]->query_race() == "bastet" || a[i]->query_race() == "weimic" && a[i]->query_subclass() != "pyromancer")
	      {
		  message("info", "%^RED%^The fire envelopes %^BOLD%^you%^RESET%^%^RED%^, burning your fur.%^RESET%^",a[i]);
		  message("info", "%^RED%^The fire envelopes %^BOLD%^"+a[i]->query_cap_name()+"%^RESET%^%^RED%^, burning "+a[i]->query_possessive()+" fur.%^RESET%^",a[i]);
	      }
	      if (a[i]->query_subclass() == "pyromancer")
	      {
		  message("info", "%^YELLOW%^You reduce the heat with your own magic!%^RESET%^",a[i]);
		  result = result / 2;
	      }

	      result = (result / 3)*2

	      this_player()->kill_ob(a[i]);

	      a[i]->damage(result);
	  }
      }
    }
