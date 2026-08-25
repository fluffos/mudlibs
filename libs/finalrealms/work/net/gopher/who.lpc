#include "gopher.h"

int query_type() { return '1'; }

string do_gopher() {
  object *obs;
  int i;
  string ret;

  obs = users();
  ret = "";
  for (i=0;i<sizeof(obs);i++) {
    if (!obs[i]->query_name() && !obs[i]->query_invis()) continue;
    ret += "0"+obs[i]->query_cap_name()+"\t0:exec:/finger_person:"+
           obs[i]->query_name()+"\t"+MACHINE_NAME+"\t"+GOPHER_PORT+"\n";
  }
  return ret;
  return (string)"/command/who"->who_string();
} /* do_gopher() */
