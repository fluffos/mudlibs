#include <room_defs.h>
#include "../DEFS.h"
#include <areas.h>
#include <criminal.h>
#include <gender.h>

inherit "/lib/food_shop";

#define ROOM_EAST AREA_TRISTEZA "finnclub/hall"

void
init_foods()
{
    /* ids, short, strength, weight, cost, long desc, eat msg, said msg */
    foods = ({
      ({ "maemmiae", "maemmi", "rove", "tuohirove", "mammi" }),
      "Tuohirove Maemmiae",
      8, 1, 45,
      "This is a small box made of birch bark. It contains some \
horrible, black substance! It looks like it was made by a dysentery \
patient and coloured with black ink. Are you supposed to eat THIS?",
      "Slurps glumph ang mumh...tastes like (sweet) shit!",
      " scrapes some black, icky goo from a small box and EATS it!",

      ({ "piimaeae", "piimae", "sour milk", "milk" }),
      "Bottle of 'Piimaeae' (finnish sour milk)",
      -1, CITY_PATH + "finnclub/piimaeae", 50,
      "drink", 0, 0,

      ({ "piirakka", "karjalan", "pie", "karelian", "karelian pie" }),
      "Karjalanpiirakka ('karelian pie')",
      10, 2, 75,
      "A 'Karjalan piirakka' ('Karelian pie') is a pie made of rice and rye dough.",
      "Munch munch munch...good!",
      " eats a Karjalanpiirakka.",

      ({ "juustoleipa", "leipa", "cheesebread", "bread" }),
      "Kainuun Juustoleipa (cheese bread)",
      11, 1, 85,
      "Kainuun Juustoleipa is a round white 'bread' with brown spots, \
made of baked cheese.",
      "Munch munch munch...good!",
      " eats some Kainuun Juustoleipa.",

      ({ "pullat", "lihapullat", "lihapullat muussilla", "meatballs" }),
      "Lihapullat Muussilla (meatballs)", 12, 1, 90,
      "Meatballs with mashed potatoes with brown sauce.",
      "Salty, but good!",
      " devours meatballs on mashed potatoes, with brown sauce.",

      ({ "bar of suffeli chocolate", "bar", "suffeli", "chocolate", }),
      "Bar of Suffeli Chocolate",
      -1, AREA_TRISTEZA + "finnclub/suffeli", 100,
      "candy", 0, 0,

      ({ "keitto", "herne", "hernekeitto", "pea soup", "soup" }),
      "Hernekeitto (pea soup)", 13, 1, 100,
      "It's finnish pea soup. Icky green. Suspicious lumps \
float in the stuff.",
      "Sllurrpppp! Yeach! Tastes bad! It has some meat in it too, you \
think. You know, this stuff is noted for the amount of intestinal gasses \
it produces!",
      " eats (or drinks, rather) some 'Hernekeitto' (pea soup)",

      ({ "sima", "bottle of sima" }),
      "Bottle of 'Sima' (finnish mead)",
      -1, CITY_PATH + "finnclub/sima", 120,
      "drink", 0, 0,

      ({ "black", "makkara", "musta", "black sausage" }),
      "Musta makkara (black sausage)",
      15, 1, 110,
      "'Musta Makkara' ('Black Sausage') looks like shit. \
It is made of blood and barley!",
      "Munch munch munch...not bad!",
      " eats some shit (or is it Mustamakkara)?",

      ({ "sininen", "blue", "hk's blue", "sausage", }),
      "\"HK's Blue\" sausage",
      17, 1, 120,
      "HK's Blue sausage is a pair of thick, pale pigskin-coloured \
thick sausages (about 6 inches long, 1 inch in diameter). \
The 'Blue' comes from its wrapping, which is blue striped plastic.",
      "Munch munch...yuk, this sausage is bad!",
      " eats some \"HK's Blue\" sausage",

      ({ "kossu", "koskenkorva", "pullo", "pullo kossua" }),
      "Pullo Kossua (a bottle of 'Koskenkorva')",
      -1, CITY_PATH + "finnclub/kossu", 650,
      "drink", 0, 0,

      ({ "instr", "instructions", "scroll" }),
      "Instructions of how to make a 'vihta' (instr)",
      -1, CITY_PATH + "finnclub/instructions", 175,
      "scroll", 0, 0,

      ({ "salmiakkikossu", "salmiakki", "salmiac" }),
      "Pullo Salmiakkikossua (bottle of salmiac kossu)",
      -1, CITY_PATH + "finnclub/salmiakki_kossu", 700,
      "drink", 0, 0,
      ({ "paisti", "karjalan", "roast", "karjalanpaisti",
	"karelian roast" }),
      "Karjalanpaisti ('Karelian roast')",
      20, 1, 350,
      "'Karjalanpaisti' ('Karelian roast') is simply a dish of meat slowly \
roasted in an oven. It includes pork, cow and sometimes sheep meat.",
      "Chomp munch mum yum...yum! Tasty stuff!",
      " eats some Karjalanpaisti.",

      ({ "kontti", "tuohikontti", "backpack", "pack" }),
      "Tuohikontti (birch bark backpack)",
      -1, CITY_PATH + "finnclub/tuohikontti", 400,
      "backpack", 0, 0,

      ({ "kalakukko", "fishcock", "kukko" }),
      "Kalakukko ('Fish-Cock')",
      40, 1, 450,
      "Kalakukko ('Fish-Cock') is sort of a pie. Outside it looks like \
a dark brown bread. The crust is baked from sour rye dough. It is \
filled with pork fat and fish. The most common fish used for \
Kalakukko is whitefish, but the experts say the best Kalakukko \
is filled with perch. (Another version is Lihakukko ('Meat-Cock'), \
which is filled with meat. Traditionally, many kinds of meat are \
used, such as pork, mutton and venison. Sadly, you can't buy \
Lihakukko from here...)",
      "Chomp munch mum yum...yum! Tasty stuff!",
      " eats a Kalakukko.",

      ({ "bottle", "vodka", "koskenkorva vodka" }),
      "Bottle of Koskenkorva Vodka",
      -1, CITY_PATH + "finnclub/vodka", 500,
      "drink", 0, 0,

      ({ "paita", "verkkopaita", "shirt" }),
      "Verkkopaita (a shirt)",
      -1, CITY_PATH + "finnclub/verkkopaita", 600,
      "clothing", 0, 0,

      ({ "virsut", "tuohivirsut", "virsu", "pair of tuohivirsu",
	"shoes", "boots" }),
      "Pair of Tuohivirsu (shoes woven of birch bark)",
      -1, CITY_PATH + "finnclub/virsut", 1100,
      "boots", 0, 0,

      ({ "puukko", "knife", "finnish knife" }),
      "Puukko (traditional finnish knife)",
      -1, CITY_PATH + "finnclub/puukko", 1500,
      "weapon", 0, 0,

      ({ "kirves", "axe", "finnish axe", "battle axe",
	"finnish battle axe" }),
      "Kirves (traditional finnish battle axe)",
      -1, CITY_PATH + "finnclub/kirves", 2000,
      "weapon", 0, 0,

      ({ "verkkarit", "suomi-verkkarit" }),
      "Suomi-verkkarit (NOW CLOTHING)",
      -1, CITY_PATH + "finnclub/verkkarit", 5000,
      "clothing", 0, 0,

    });
}

void
reset_shop()
{
    if (!baker) {
	baker = clone_object(NPC_DIR+"shopkeeper");
	baker->set_name("K-Kaupan Vaeiski");
	baker->move_player("foo", this_object());
	baker->set_name("Vaeiski");
	baker->set_short("K-Kaupan Vaeiski");
	baker->set_race("human");
	baker->set_gender(G_MALE);
	baker->set_id(({ "vaeiski", "kauppias", "vaiski" }));
	baker->set_long(
	  "K-Kaupan Vaeiski (Vaeiski is his name) is a fat, old finnish man.");
	baker->set_random_pick(0);
	baker->load_chat(5, ({
	    "Vaeiski sings: Tule tule K-Kaupan pakkaspolkkaan, paljon on tavaroita tarjolla!!!",
	    "Vaeiski says: Hyv{ lihatiski on meill{ K-Kaupassa ihan kunnia-asia!",
	    "Vaeiski says: Nyt erikoistarjouksessa: Sika-nauta 56 markkaa kilo!",
	    "Vaeiski says: Huomenna meill{ on asiakkaille tarjolla oikein \
kunnon Sika-Mokka Kahvit!"
	  }));
    }
}

void
create_shop()
{
    set_short("K-Kauppa");
    set_long(
      "You are in \"K-Kauppa\", a traditional finnish shop which sells \
old food and poor tools. But at least the costs are of high international \
level! There is a list of products on the wall. You can 'buy' \
things, but also you can 'fill' a bag or other container with them \
(for example 'fill bag with kossu').");

    set_light_level(LT_DIM);
    set_wd(WD_INDOORS);

    add_exit("east", ROOM_EAST);
    reset_shop();
}

void
init_room()
{
    object o;

    if (!interactive(o = this_player()) && o && environment(o) == this_object()
      && o != baker && !this_player()->id("city_guard"))
	call_out("throw_out", 0, o);
    // Call out used since we don't want to throw it out before arrive msg gets
    // printed!!!

}

void
throw_out(object who)
{
    if (!baker || !who || environment(baker) != this_object() ||
      environment(who) != this_object()) return;

    // Coded this way so we get "Baker says... Baker throws Foobar out.",
    // and also, players in the other room get "Foobar arrives."

    tell_here("Vaeiski says: No monsters allowed!\n", who, 1);
    who->move_player("Vout"+ROOM_EAST);
}

int
shop_open()
{
    object ob;

    if (!baker || !present(baker))
	return notify_fail("The shopkeeper is not here.\n"), 0;

    if ((int)this_player()->query_crime_level() > CR_THEFT)
	return notify_fail("We do not trade with criminals!\n"), 0;

    return 1;
}
