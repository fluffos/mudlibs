// Taken from Forbiden Forest
// Converted to Divided Sky By Shaydz 3/21/02 2:25PM

inherit COMMAND_BASE;

protected int cmd(string str) {
  object webster;
  object user;
  string *argv, comm;

  user = TP;

  if ((!str) || (str == ""))
    return 0;

  argv = explode(str, " ");
  comm = lower_case(argv[0]);

  switch (comm) {
    case "d":  comm = "define";  break;
    case "m":  comm = "match";   break;
    case "s":  comm = "show";    break;
  }

  if ((comm != "define") && (comm != "match") && (comm != "show"))
    return 0;

  if (comm == "define")
    if (sizeof(argv) == 2)
      argv = ({ argv[0], "wn", argv[1] });

  if (comm == "match")
    if (sizeof(argv) == 3)
      argv = ({ argv[0], "wn", argv[1], argv[2] });

  if (!(webster = load_object(WEBSTER_H)))
    return notify_fail("Webster handler could not be loaded.\n");

  comm += " " + implode(argv[1..], " ");
  webster -> protocol(comm, user);

  tell_object(user, "%^BOLD%^Issuing request: " + comm + "%^RESET%^\n\n");

  return 1;
} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({ "<string:'d*efine ([database]|[*]) <word>'>", (: cmd($4[0]) :),
              "<string:'m*atch ([database]|[*]) <strategy> <word>'>", (: cmd($4[0]) :),
              "<string:'s*how (db|databases|strat*egies)'>", (: cmd($4[0]) :), });
} /* query_patterns() */
