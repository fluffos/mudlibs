/*
 * Force an object to become 'this_player'
 * Only callable by valid player objects
 */

varargs object set_this_player(object ob) {
  if (!ob) ob = previous_object();
  if (!MASTER->valid_player_call(previous_object())) {
    log_file("ILLEGAL", "Call set_this_player() by " +
             file_name(previous_object()) + "\n");
    return 0;
  }
  funcall(bind_lambda(#'enable_commands, ob));
  return ob;
}


/* Restrict usage of 'command' */

varargs status command(string str, object ob) {
  if (!ob) ob = previous_object();
  if (ob != this_player() && this_player()) {
    if ((int)this_player()->query_security_level() <
        (int)ob->query_security_level()) {
      return 0;
    }
  }
  return efun::command(str, ob);
}

