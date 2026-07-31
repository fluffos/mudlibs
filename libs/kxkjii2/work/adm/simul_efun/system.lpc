// system.c

void shutdown(int code)
{
  object me = previous_object(1);
  object mob = previous_object(0);

  if( wiz_level(me) >= 5
  ||  strcmp(file_name(mob), "/obj/npc/demogorgon") != -1 )
    efun::shutdown(code);
}

/*
int save_object(string name, int flag)
{
  return 1;
}
*/
