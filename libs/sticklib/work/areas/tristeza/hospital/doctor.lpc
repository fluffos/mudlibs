// (Mad) Doctor Mengele of <Main Town> Sanatorium 
// Note: The real Mengele was a "doctor" at a Nazi death camp,
// who performed so-called "experiments" on prisoners.
// For those without a sense of humour: this is a joke. Add a smiley.
// Plant or tree. Or something.

#include <group_npc.h>

void
create_monster()
{
    string n;
    set_name("doctor mengele");
    set_race("human");
    set_group("hospital");
    set_id(({ "doctor", "mengele", "Mengele" }));
    set_short("Doctor Mengele");
    set_gender(G_MALE);
    set_long("This is Dr Mengele, the boss of Tristeza Sanatorium.");
    set_spell_chance(7);
    set_spell_dam(80);
    set_spell_mess1("Dr Mengele is holding something shiny and sharp!");
    set_spell_mess2(
      "Dr Mengele slices you with his scalpel. That really HURTS!");
    set_level(14);
    set_hp(3000);
    set_wander(0);
    set_money(random(20) + 20);
    set_alignment(AL_NASTY);
    set_wc(18,1);
    set_ac(16,1);
    n = "Mengele states: ";
    /* Thanks to newsgroup sci.med for lots of talk :-) */
    load_chat(7, ({
	n+"Hello.",
	n+"There has been lots of typhoid fever cases lately.",
	n+"Did you know that I had the sewers disinfected?",
	/*
		n+"They should really disinfect those sewers..."
	*/
	n+"Unfortunately, tacrine is no levodopa.",
	n+"I read sci.med, do you?",
	n+"I'm a firm believer in euthanasia and legalised suicide.",
	n+"Warts are commonly removed by freezing with liquid nitrogen.",
	n+"Fungus in the tonails re-infects the foot area with athelete's foot continuously.",
	n+"Hmm...grade II astrocytoma with some anaplastic astrocytes...",
	n+"Perhaps some farmorubicin (epirubicin hydrochloride)...",
	n+"Some male human homosexuals show a hypothalamic response more characteristic of genetic females...",
	n+"30 mg of dextromethorphan, 650 mg of acetaminophen..."
      }));

    load_a_chat(12, ({
	n+"Hey! Watch it! I might get angry!",
	n+"How DARE you attack a doctor!",
	n+"Do you think you will ever get any healing here after this?",
	n+"Stop that now, or..."
      }));
}
