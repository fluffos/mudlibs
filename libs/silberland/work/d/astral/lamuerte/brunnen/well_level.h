
varargs int well_level(object ob)
{
  string roomname;

  if (!ob) 
    ob = this_object();
  if (!environment(ob)) 
    return 0;
  roomname = file_name(environment(ob));
  if(roomname[0..37] != ROOMS "level") 
    return 0;
  if(roomname[39..39] == "/")
   return to_int(roomname[38..38]);
  else
   return to_int(roomname[38..39]);
}

