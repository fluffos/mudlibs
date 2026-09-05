/* Had to patch this to due to Earwax. Thanks. */

varargs int command(mixed str, mixed ob)
{
  int obLevel, thLevel;
  object th;

  if(ob && objectp(ob) && query_ip_number(ob) &&
     (obLevel = (int)ob->query_level()) >= 21)
  {
    if((th = this_player()) && (int)th->query_level() <= obLevel
       && th != ob)
    {
      tell_object(th, "Slick one, smart guy.\n");
      tell_object(ob, (string)th->query_real_name() + 
        " tried to force you to " + str + ".\n");
      return 0;
    }
    if(!th) return 0;
  }
  if(!ob) ob = previous_object();
  return efun::command(str, ob);
}
