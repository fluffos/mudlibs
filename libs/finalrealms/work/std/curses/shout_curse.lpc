#define NO_SHOUT "/std/curses/shadows/no_shout_sh"

void player_start(object target)
{
  object shad;
  if(target->noshout_on()) return;
  shad = clone_object(NO_SHOUT);
  shad->setup_noshout(target);
}

int prevent_remove(object target, object remover)
{
  if(!remover) return 0;
  return !remover->query_creator();
}

void player_quit(object target)
{
  target->destruct_noshout();
}
