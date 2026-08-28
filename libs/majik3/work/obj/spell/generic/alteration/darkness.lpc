inherit SPELL;

create_spell ()
{
  set_level (1);
  set_casting_time (1);
  set_components (1, 0, "bat fur");
}

perform_spell (object caster, mixed target, int result)
{
  ENV(caster)->set_light (ENV(caster)->query_light()-1);
  emote ("Lights flickers as a cloud of darkness is sent to room.\n",
    caster, 0, ENV(THIS));

  return 1;
}

query_help ()
{
  return "Use of this spell summons a magical darkness to the room. The darkness is permanent.";
}
