/*  -*- LPC -*-  */
#include <command.h>
#include <daemons.h>

int
main(string str)
{
  string name, priv;
  object ob, conn;

  if(str && str != "") {
    if(strsrch(str, '/') != -1) 
      ob = find_object(RESOLVE_PATH(str));
    else {
      ob = find_player(str);
      if(!ob)
	ob = present(str, environment(this_player()));
      if(!ob)
	ob = present(str, this_player());
    }

    if(!ob) {
      printf("No such object found\n");
      return 1;
    }
  } else {
    ob = this_player();
  }

  conn = ob->query_connection();
  priv = sprint_priv(query_privs(ob));
  name = ob->query_name();

  if( !name ) name = priv;

  printf("%s: priv=%s oid=%d coid=%d hb=%s domains=%s\n",
	 base_name(ob),
	 priv,
	 getoid(ob),
	 (conn ? getoid(conn) : -1 ),
	 (query_heart_beat(ob) ? "on" : "off"),
	 implode((string *)SECURITY_D->get_domain_memberships(name), ","));
  
  return 1;
}

