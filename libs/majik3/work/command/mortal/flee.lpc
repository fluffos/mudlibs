int
main ()
{
  string *dir, *dest;
  int i;

  if (THIS->query_position() < POS_FIGHTING)
    {
      write ("You are in pretty bad shape, unable to flee!\n");
      return 1;
    }

  dir = ENV(THIS)->query_exit_dir();
  dest = ENV(THIS)->query_exit_dest();

  if (!dir || sizeof(dir) == 0)
    {
      act (THIS, "$n tries to flee miserably!");
      write ("You can't flee since there is no exits!\n");
      return 1;
    }

  if (!random (THIS->query_agi()))
    {
      act (THIS, "$n tries to flee, but can't!");
      write ("PANIC! You couldn't escape!\n");
      return 1;
    }
 
  write ("You flee head over heels.\n");
  act (THIS, "$n flees head over heels!");
  i = random(sizeof(dir));
  THIS->move_player (dest[i], dir[i]);
  return 1;
}

query_help ()
{
  return "Using this command you can flee away from combat.";
}

query_author ()
{
  return "namhas";
}

query_position ()
{
  return POS_STANDING;
}
