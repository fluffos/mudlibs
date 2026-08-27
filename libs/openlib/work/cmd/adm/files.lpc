#include <command.h>

int
main()
{
  string outp;

  outp = "username       file\n"
         "--------       ----\n";
  foreach(object ob in users()) {
    string tmp = in_edit(ob);
    tmp = (tmp ? "/" + tmp : "<not editing>");
    outp += sprintf("%:-10s     %:-60s\n", ob->query_cap_name(), tmp);
  }
  message("system", outp, this_player());
  return 1;
}
