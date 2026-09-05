int cmd_wait(string str)
{
  object obj;
  if(!str) {
    write("You wait impatiently.\n");
    say((string)this_player()->query_name()+" waits impatiently.\n");
    return 1;
  }
  if(!(obj = find_player(str)) || (obj->query_invis((int)this_player()->query_level(),(int)this_player()->query_extra_level()) >= 1)) {
    write("You don't see "+capitalize(str)+" on Nirvana.\n");
    return 1;
  }
#if 0 /* Rumplemintz - 06/08/2011 */
  write("You wait impatiently for "+(string)obj->query_name()+" from afar.\n");
#else
  write("You wait impatiently for "+(string)obj->query_name() +
  (present(obj, environment(this_player())) ? "" : ", from afar") + ".\n");
#endif
  tell_object(obj, (string)this_player()->query_name()+" is waiting for you at: "+(string)environment(this_player())->short()+".\n");
  return 1;
}
