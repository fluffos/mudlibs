updateall () {
  object o, n;
  string name, *list;
  int gotone, isclone;
  int count, pass;
  int aborted;
  int stime;

  aborted = 0;
  list = ({});

  // The destruction process will reload objects/blueprints destructed
  // earlier, so they mustn't be considered again.
  stime = time();

  do {
    gotone = 0;
    for (o = debug_info(2); o; o = n)
    {
      if (get_eval_cost() < 3000) 
      {
        aborted = 1;
        break;
      }
      n = debug_info(2,o);
      name = file_name(o);
      if (   name[0..6] == "/secure"
          || interactive(o)
          || query_once_interactive(o)
          || o == this_object()
          || environment(o)
          || program_time(o) >= stime
         )
        continue;

      isclone = (0 <= member(name, '#'));

      catch(o->clean_up(2));
      if (o && (!first_inventory(o) || isclone))
        catch(o->remove());
      if (o && (!first_inventory(o) || isclone))
        destruct(o);
      if (!o) {
        count++;
        gotone = 1;
        tell_object(find_player("mateese"), "Destructed "+name+"\n");
      }
    }
    pass++;
  } while (gotone && !aborted);
  tell_object( find_player("mateese")
             , sprintf("Done: %d objects in %d passes.\n"
                      , count, pass-1));
  if (aborted)
    tell_object( find_player("mateese"), "Operation aborted.\n");
  else
    tell_object( find_player("mateese"), "Operation finished.\n");
}
