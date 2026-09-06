/* a god? anyone want to fight a god? */
#include <npc.h>
#include <areas.h>

void
create_monster()
{
    set_name("skert");
    set_id(({ "avatar", "skert", "god", "god of thieves" }));
    set_race("god");
    set_short("The Avatar of Skert");
    set_level(80);
    set_ep(2000000);
    set_money(2200 + random(3500) + random(2000));
    set_hp(25000);
}

/* Someone threw cow shit on our face! How stupid! */
void
cow_shit_thrown_on_face(object who)
{
    who->tell_me("Uh-oh...Skert seems to get very angry! Now you've done it!");
    call_out("grrr", 3, who);
}

void
grrr(object who)
{
    object gr;

    if (!who) return;
    who->tell_me("Skert tells you: I THINK YOU SHOULD VISIT DEATH!\n");
    who->move_player("X#"+AREA_TRISTEZA+"death/death_room");
}
