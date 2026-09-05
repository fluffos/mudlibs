varargs string query_ip_name(object player)
{
  if(!player)
    return efun::query_ip_name();
  else
  {
    object x;
    string qip;
    qip = efun::query_ip_name(player);
    if((x=this_player()) && (x != player) &&
      x->is_player() &&
      ((int)x->query_level() < 60) &&
      ((int)x->query_level() > 19))
    {
      if(qip != query_ip_name())
      {
        return "???";
      }
    }
    return qip;
  }
}

varargs string query_ip_number(object player)
{
  if(!player)
    return efun::query_ip_number();
  else
  {
    object x;
    string qip;
    qip = efun::query_ip_number(player);
    if((x=this_player()) && (x != player) &&
      x->is_player() &&
      ((int)x->query_level() < 60) &&
      ((int)x->query_level() > 19))
    {
      if(qip != query_ip_number())
      {
        return "???";
      }
    }
    return qip;
  }
}
