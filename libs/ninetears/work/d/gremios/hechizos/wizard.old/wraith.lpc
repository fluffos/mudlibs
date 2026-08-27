inherit "/obj/monster";

#define TO this_object()
void setup()
{
  set_name("wraith");
  set_short("Wraith");
  set_long("A floating, shadowy wraith.  It looks vicious.\n");
  set_gender(1);

  set_race("unknown");
  set_guild("warrior");
  set_level(roll(15,20));
  set_al(100);
  set_wimpy(0);
  load_chat(10, ({
	1, ":glides around restlessly, looking for life to drain.",
	1, ":lets out a howl of unliving sorrow.",
	1, ":whispers a curse for everything living."
	}));
  load_a_chat(10, ({
	1, ":rasps: I'll have your soul!",
	1, ":reaches out towards you and you feel the chill of the grave.",
	1, ":screams in rage and claws viciously at you.",
	1, "'I shall make you endure an eternity of unliving death!"
	}));
  TO->add_property("undead");

}

void give_caster_stats(object ob)
{
  TO->set_level(ob->query_level());
  TO->set_max_hp(ob->query_max_hp());
  TO->set_hp(ob->query_max_hp());
  TO->set_gp(ob->query_max_gp());
  TO->set_max_gp(ob->query_max_gp());
  TO->set_str(30);
  TO->set_int(25);
  TO->set_con(25);
  TO->set_dex(20);
  TO->set_wis(25);
  TO->set_cha(5);
  TO->set_long("This is a shadowy wraith, bearing a striking resemblance to "+
	ob->query_cap_name()+".  It looks ready to suck out your soul.\n");
}
