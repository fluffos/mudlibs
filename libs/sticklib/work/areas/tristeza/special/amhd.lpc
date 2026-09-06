/* Fixed, controllable AMHD //Graah */
// Updated attack stuff a bit.  1-apr-96 -=Germ=-
// Players killed it too easily, so I made it somewhat better - Chopin

#include <npc.h>
#include <room_defs.h>
#include <conditions.h>

/* spell_chance per spell */
#define SPELL_CHANCE 33
#define SPELL_MESS1(x) "Dragon "+({"breathes fire","breathes acid","breathes cold","casts a powerful spell","casts a meteor swarm"})[x]
#define SPELL_MESS2(x) SPELL_MESS1(x)+" at you"
#define SPELL_MESS3 ({"Breathing fire","Breathing acid","Breathing cold","Casting a powerful spell","Casting a meteor swarm"})
#define SPELL_DAM(x) ({ 100,100,100,120,160 })[x]
#define HURRICANE_CHANCE 33
#define HURRICANE_DAM 80

int spell_no; /* which spell is in turn */

void
create_monster()
{
    spell_no = 0;


    set_name("Ancient Multi-Hued Dragon");
    set_living_name("amhd");
    set_id(({
	"ancient multi-hued dragon", "multi-hued dragon", "dragon"
      }));
    set_race("dragon");
    set_short("Ancient Multi-Hued Dragon");
    set_long(
      "This is the MOST ENORMOUS dragon you have ever seen. In fact, \
every other dragon looks like a tiny lizard compared to this one! \
The Ancient Multi-Hued Dragon (AMHD) is covered from head to tail with \
TWO FEET \
thick, extremely hard multi-hued scales. It gazes hypnotically at you \
with its multi-hued eyes. You notice that it has about six feet long \
multi-hued claws and two feet long, very sharp multi-hued fangs.");
    set_level(80);
    set_ep(4000000);
    set_hp(5500);
    // set(NPC_NOT_AGGRESSIVE);
    set_alignment(random(- AL_EVIL) + AL_NICE);

    //  set_ac(45, 1); // hmm... why make it this low?
    set_condition(RESISTANCE(C_STUNNED),-1);
    set_keep_hb(1);
}

hit_player(dam, dtype, hc, enemy)
{
    object attacker;
    /* If we are attacked by a player and a monster, let's make the player
       the number one attacker */
    attacker=query_attack();
    if (this_player() && attacker 
      && present(this_player(),environment())
      && present(attacker,environment()))
    {
	if (interactive(this_player()) && !interactive(attacker))
	{
	    attacker->stop_fight(this_object());
	    stop_fight(attacker);
	    attack_object(this_player());
	    this_player()->attack_object(this_object()); 
	}
    }
    else
    if(this_player() && attacker=query_alt_attack()
      && present(this_player(),environment())
      && present(attacker,environment()))
	if (interactive(this_player()) && !interactive(attacker))
	{
	    attacker->stop_fight(this_object());
	    stop_fight(attacker);
	    attack_object(this_player());
	    this_player()->attack_object(this_object());
	}

	/* Monsters do not damage us! */
    if (this_player() && !interactive(this_player()))
	dam=0;

    if (this_player())
	last_attacker=this_player();
    return ::hit_player(dam, dtype, hc, enemy);
}

heart_beat()
{
    object attacker, *envlist;
    int i;

    ::heart_beat();

    envlist=all_inventory(environment());

    for(i=sizeof(envlist)-1;i>=0;i--)
	/* Let's make little players (non-lords) and City Guards flee */
	if(living(envlist[i]) && envlist[i]->query_level() < 20 &&
	  !envlist[i]->query_coder_level() &&
	  (!envlist[i]->query_npc() || envlist[i]->id("city_guard"))) {
	    envlist[i]->tell_me("Ancient Multi-Hued Dragon looks at you!");
	    envlist[i]->run_away();
	}
    attacker=query_attack();
    if ( !attacker) return;
    if ( present(attacker,environment()) &&
      SPELL_CHANCE > random(100))
    {
	if (HURRICANE_CHANCE > random(100) &&
	  environment()->query(ROOM_WD)==WD_OUTDOORS)
	{
	    envlist = all_inventory(environment());
	    for(i = sizeof(envlist) - 1; i >= 0; i--)
		if (living(envlist[i]) &&
		  !envlist[i]->query_coder_level() &&
		  envlist[i]->query_level() > 19 &&
		  !envlist[i]->query_npc())
		    envlist[i]->hit_player(random(HURRICANE_DAM));
	    environment()->tell_here(
	      "The Ancient Multi-Hued Dragon summons a hurricane! \
SSWWWOOOOOOOOOOOOSSSSSSSHHHHHHHHHHHHHHHHHHHHHHHHH!!!",({ this_object() }));
	    tell_me("Summoning hurricane.");
	}
	else
	{
	    if (spell_no == 4 &&
	      environment()->query(WD_OUTDOORS) != WD_OUTDOORS)
		spell_no = 0;
	    environment()->tell_here(SPELL_MESS1(spell_no) + "!",
	      ({ attacker, this_object() }));
	    attacker->tell_me(SPELL_MESS2(spell_no)+"!");
	    tell_me(SPELL_MESS3[spell_no] + " at " +
	      capitalize(attacker->query_real_name())+".");
	    attacker->hit_player(random(SPELL_DAM(spell_no)));
	    spell_no++;
	    if (spell_no > 4)
		spell_no = 0;
	}
    }
}
int query_ctrl() { return 1; }
