#include <std.h>
#include <amun.h>
inherit BARKEEP;
void create() {
    ::create();
    set_property("no bump", 1);
    set_name("Tinonia");
    set_id( ({ "tinonia", "monster" }) );
    set_short("%^BOLD%^%^WHITE%^T%^RED%^i%^WHITE%^non%^RED%^i%^WHITE%^a%^RESET%^");
    set_aggressive(0);
    set_level(500);
    set_long("%^BOLD%^%^WHITE%^T%^RED%^i%^WHITE%^non%^RED%^i%^WHITE%^a is a very slendor %^YELLOW%^Angel%^WHITE%^, and is also quite short. She has %^YELLOW%^curly blonde hair%^WHITE%^, that bounces as she moves, and beautiful %^GREEN%^green eyes %^WHITE%^that help brighten up her already gorgeous face. She is wearing a long, lacy pink dress that flows down to her ankles.%^RESET%^");
    set_gender("female");
    set_race("archangel");
    set_body_type("archangel");
    set_stats("charisma" , 200);
    set_hp(query_max_hp());
    set_sp(query_max_sp());
    set_mp(query_max_mp());
    set_alignment(1500);
    set_currency("gold");
    set_menu_header("The following items are always on special:");
    set_menu_footer("<buy food_name> gets you food.");
    set_menu( ([
	"carrot" : ([
	  "type" : "food",
	  "price" : 60, 
	  "strength" : 80, 
	  "short" : "A Carrot",
	  "long" : "%^ORANGE%^A crunchy carrot.%^RESET%^",
	  "my_mess" : "%^RESET%^%^ORANGE%^You crunch on the carrot and your body feels nourished.%^RESET%^",
	  "your_mess" : "%^RESET%^%^ORANGE%^crunches on the carrot and $P body feels nourished.%^RESET%^"
	]),
	"apple" : ([
	  "type" : "food",
	  "price" : 80, 
	  "strength" : 100,
	  "my_mess" : "%^BOLD%^%^RED%^The apple squirts juices on you as you bite into it.%^RESET%^",
	  "your_mess" : "%^BOLD%^%^RED%^bites into the apple and gets sprayed with it's juices.%^RESET%^",
	  "short" : "An Apple",
	  "long" : "%^BOLD%^%^RED%^A juicy red apple.%^RESET%^",
	]),
	"banana" : ([
	  "type" : "food",
	  "price" : 70, 
	  "strength" : 90,
	  "short" : "A Banana",
	  "long" : "%^BOLD%^%^YELLOW%^A soft banana.%^RESET%^",
	  "my_mess" : "%^BOLD%^%^YELLOW%^MMMMMM...banana!%^RESET%^",
	  "your_mess" : "%^BOLD%^%^YELLOW%^says MMMMMM...banana!%^RESET%^",
	])
      ]) );
}
