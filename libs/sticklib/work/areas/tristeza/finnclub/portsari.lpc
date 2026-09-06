#include <equipped_npc.h>

void
create_monster()
{
    object foyer;
    int cost;

    foyer = find_object("/areas/tristeza/finnclub/foyer");
    if (foyer)
	cost = (int)foyer->query_cost();
    cost /= 5;
    set_name("portsari");
    set_race("human");
    set_id(({ "portier", "jorma" }));
    set_gender(G_MALE);
    set_short("Portsari of the Finnish Club");
    set_long("Portsari is a finnish version of the word 'portier'. He is\
 a huge, muscled man dressed in a very strange-looking suit. You can't detect\
 any weapons but a single punch from those fists could probably knock out a\
 dragon!");
    set_level(30 + cost); //higher level when killed
    set_hp(1500 + (cost * 10)); //more hp when killed
    set_money(random(200) + 210);
    set_alignment(AL_NASTY);
    set_spell_chance(10);
    set_spell_mess1("Portsari sprays poison gas!");
    set_spell_mess2("Portsari sprays poison gas on your face! IT HURTS!!!");
    set_spell_dam(40);
    load_chat(7, ({
	"The Portsari scans the room carefully.",
	"The Portsari asks: Onkos tullut otettua v{h{n pohjia, h{h?",
	"The Portsari says: Hei kaveri! Ik{raja on 25 vuotta!",
	"The Portsari says: Nude Painting and Karaoke tonight!",
	"The Portsari says: Estonian strip-tease and porno show tonight!",
	/* Huom: Mudissa ei ole tietenk{{n torstai-nimist{ viikonp{iv{{... :-D!! */
	"The Portsari says: Happy Hours on Torstai at 16-19 o'clock!",
	"The Portsari says: Finnish championship of Karaoke tonight!",
	"The Portsari says: Mud Wrestling tonight!",
	"The Portsari says: T| p|t. Hou du ju duu? Mai neim is Jorma.",
	"The Portsari sniffs at your breath. You wonder why..."
      }));

    set_ep(1200000);

    add_object("/areas/tristeza/finnclub/kauha", 0, 1);
    add_armour(0, "strange-looking suit", ({
	({ "set_name", "strange-looking suit" }),
	({ "set_id", ({ "suit" })}),
	({ "set_short", "strange-looking suit" }),
	({ "set_ac", 4 }),
	({ "set_weight", 10 }),
	({ "set_value", 2500 })
      }), 5,  "Portsari takes the strange-looking suit and wears it.");

    set_ac(30 + cost); //better ac when killed
    set_wc(40 + cost); //better wc when killed
    set_dead_ob(this_object());
}

status
monster_died(object monst)
{
    object foyer;

    foyer = find_object("/areas/tristeza/finnclub/foyer");
    if (foyer)
	foyer->raise_cost();
    environment(monst)->tell_here("Portsari croaks: You'll regret this!");
    return 0;
}

int
run_away()
{
    environment()->tell_here(
      "Portsari yells: PERKELE! TASTA EN LAHE KUN KILON PALOINA SAATANA!");
    return 1;
}
