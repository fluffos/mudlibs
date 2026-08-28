string *rumors = ({ });

create ()
{
  restore_object("/data/misc/rumors");
}

string
query_rumor ()
{
  return rumors[random(sizeof(rumors))];
}

add_rumor (string str)
{
  if (!rumors)
    rumors = ({ str });
  else
    rumors += ({ str });

  save_object("/data/misc/rumors");
}
