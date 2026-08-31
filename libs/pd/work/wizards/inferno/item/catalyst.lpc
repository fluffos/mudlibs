#include <std.h>
inherit OBJECT;

string env, name;

void create() {
 ::create();
   set_name("catalyst");
   set_short("%^RESET%^%^CYAN%^a power%^BOLD%^%^WHITE%^ful crys"
	"%^RESET%^%^CYAN%^tal catalyst%^RESET%^");
   set_long("A talisman of increadible power, civilizations, kingdoms "
	"and entire races have been distroyed by a single person using "
	"the power within the catalyst.");
   set_weight(-10);
   set_value(0);
   restore_object("/wizards/inferno/catalyst");
}

int invoke(string st) {
   int str, wis, chr, con, ine, dex;
   if (!st || st == "" || st != "catalyst") return 0;
   this_player()->add_stat_bonus("strength", -(
        this_player()->query_stat_bonus("strength")));
   this_player()->add_stat_bonus("wisdom", -(
        this_player()->query_stat_bonus("wisdom")));
   this_player()->add_stat_bonus("charisma", -(
        this_player()->query_stat_bonus("charisma")));

   this_player()->add_stat_bonus("constitution", -(
        this_player()->query_stat_bonus("constitution")));

   this_player()->add_stat_bonus("intelligence", -(
        this_player()->query_stat_bonus("intelligence")));
   this_player()->add_stat_bonus("dexterity", -(
        this_player()->query_stat_bonus("dexterity")));
   str = this_player()->query_stats("strength");
   wis = this_player()->query_stats("wisdom");
   chr = this_player()->query_stats("charisma");
   con = this_player()->query_stats("constitution");
   ine = this_player()->query_stats("intelligence");
   dex = this_player()->query_stats("dexterity");
   this_player()->add_stat_bonus("strength", str);
   this_player()->add_stat_bonus("wisdom", wis);
   this_player()->add_stat_bonus("charisma", chr);
   this_player()->add_stat_bonus("constitution", con);
   this_player()->add_stat_bonus("intelligence", ine);
   this_player()->add_stat_bonus("dexterity", dex);
   write("%^BOLD%^%^YELLOW%^You invoke the power of the %^WHITE%^catalyst "
	"%^YELLOW%^into your body.");
   say("%^BOLD%^%^YELLOW%^"+this_player()->query_cap_name()+
	"invokes the power of the %^WHITE%^catalyst%^YELLOW%^ into "+
	this_player()->query_title_gender()+" body.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("invoke", "invoke");
}

void move(object ob) {
   ::move(ob);
   env = file_name(environment(this_object()));
   name = file_name(environment(this_object()))->query_name();
   save_object("/wizards/inferno/catalyst");
}
