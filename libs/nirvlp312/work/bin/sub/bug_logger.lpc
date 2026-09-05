// This object is used from /global/commands/misc.c for the bug/typo/idea
// commands

string path, result, verb;
object about;
int counter;
mapping file = ([]);

void
bug_log_loop (string input)
{
  string castle;
  if (!sizeof(m_indices(file))) 
    file += (["typo":"TYPO", "bug":"BUG", "idea":"IDEA", "praise":"PRAISE"]);
  if (input == "~q") {
    message("Ok, report aborted.\n");
    destruct(this_object());
    return;
  }
  if (input == "**") 
  {
    if (!counter)
    {
      write ("Aborted.\n");
      destruct (this_object ());
      return;
    }
    if (path)
      write_file(path, result);
    log_file(file[verb], result);
    // Ugh Oct-15-1996 -- if somebody wants to be notified or wants
    // to log to a different file or something
    if (about)
      catch(about->log_player_report(verb,result));
    if ((castle = castle_file(about)) && find_object(castle))
      catch(castle->notify_player_report(about,verb,result));
    write ("Thanks for your help.\n");
    destruct (this_object ());
    return;
  }
  result += input + "\n";
  counter++;
  write ("]");
  input_to ("bug_log_loop");
}

void
initialize (string v, object ob, string p, string id)
{
  path = p;
  verb = v;
  about = ob;
  result = ctime (time ()) + " " + this_player ()->query_vis_name () + ": " +
                capitalize (v) + " in " + load_name (ob) + 
                (id?  " ("+id+")" : "") +":\n";
  input_to ("bug_log_loop");
}
