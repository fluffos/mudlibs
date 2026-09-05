/*
 * inherit this version for Invasion mobs..
 * Dune & Vertebraker
 */

inherit "/players/vertebraker/closed/std/monster";

#define I_DAEMON    "/obj/invasion/i-daemon"
#define AGGRO_LEV   15    /* players less than this level are not auto-attacked */
string invasion_type;     /* assigns this monster to an invasion */

void reset(int x) {
  ::reset(x);
  if(x) return;
  set_dead_ob(this_object());
  set_wander(2, 0, ({ }));
}

void init()
{
  ::init();

  /* only be aggressive against higher level players */
  if(this_player() && 
     !call_other(this_player(),"query_npc") &&
     aggressive == 1)
  {
    if (this_player()->query_level() < AGGRO_LEV)
    {
      kill_ob = 0;
    }
  }
}

void set_invasion_type(string x) { invasion_type = x; }

status monster_died()
{
  if(attacker_ob && (attacker_ob->is_player()))
  {
    if((string)I_DAEMON->query_monster_type() == invasion_type)
    {
      I_DAEMON->add_kill((string)attacker_ob->query_real_name());
      if(I_DAEMON->query_total_monsters())
        write("\n\tYou have slain the "+invasion_type+", on with the carnage!\n\n");
      else
        write("\tThe "+invasion_type+" Invasion is now Over.\n\n");
    }
  }
  return 0;
}
