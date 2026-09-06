#include <equipped_npc.h>
#include <areas.h>
#include <daemons.h>
#include <quests.h>

void
create_monster()
{
    set_name("bum");
    set_race("human");
    set_level(2);
    set_alignment(20);
    set_long(
      "A really filthy looking smelly bum. You guess that he's a Finn.");
    set_hp(50);
    set_gender(G_MALE);
    set_money(10 + random(15));
    load_chat(2, ({"Bum falls asleep.",
	"Bum says: Mgbllllrghhh",
	"Bum drinks some wine from a hidden bottle." }));
    load_a_chat(10, ({"Bum says: Hey, you ba-bashtard! Shtop that!",
	"Bum yells: I ish gonna break your n-n-noshe!",
	"Bum shouts: Heelppp! Guardsh!"}));
    add_object(AREA_TRISTEZA+"obj/navelfluff","fluff",0,3,
      "Bum takes the fluff and puts it in his navel.");
}

void
give_object_by(object who, object what) {
    environment() -> tell_here("Bum says: Gee, thanksh!", this_object());

    if (!objectp(what) || !what -> id("beer")) return;

    init_command("drink beer");

    if (who->query_invis()) {
	environment() -> tell_here("Bum says: I wondersh who thhat s-shomeone wash??", this_object());
	return;
    }

    if (!interactive(who)) return;
    QUEST_D->add_quest(who,QUEST_M2);
    who -> tell_me("You have solved a very minor quest! Well done.");
}
