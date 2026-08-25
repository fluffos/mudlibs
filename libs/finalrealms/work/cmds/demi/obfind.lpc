/* Alterations by Hamlet, Jan 1996 */
#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup() {
  position = 1;
}
string query_short_help()
{
   return "\"obfind name\" will return a (unique) list of objects "
   "matching the id \"name\". Very useful for finding those "
   "hard to locate items players lose.\n";
}

protected int cmd(string str, object me) {

  object *obs = objects();
  int i;
  string *names = ({ });
  obs = filter(obs, "check_id", this_object(), str);
  for(i=0;i<sizeof(obs);i++) {
    names += ({ base_name(obs[i]) });
  }
  printf("%O", uniq_array(names));
  return 1;
}

int check_id(object ob, string str) {
  return (int)ob->id(str);
}
