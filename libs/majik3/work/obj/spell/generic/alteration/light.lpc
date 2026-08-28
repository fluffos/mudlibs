inherit SPELL;

create_spell ()
{
  set_level (1);
  set_casting_time (1);
  set_components (1, 0, "phosphorescent moss");
}

perform_spell (object caster, string target_name, int result)
{
  ENV(caster)->set_light (ENV(caster)->query_light()+1);
  emote ("Suddenly the room seem to bright up a bit.\n",
    caster, 0, ENV(THIS));

  return 1;
}

query_help ()
{
  return "Use of this spell summons a magical light to the room. The light is permanent.";
}
