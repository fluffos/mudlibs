
#define tp this_player()
#define E  environment


hold(caller,time)
{
  if (time > 4) return ::hold(caller,random(4));
     return ::hold(caller,time);
}

init()
{
  if (tp->query_player() && living(tp) && E(tp) == E() && !tp->query_invis())
      attack_object(tp);
  ::init();
}
