inherit "/std/thing";

#include <properties.h>
#include <language.h>
#include <moving.h>
#include <defines.h>

create()
{
	::create();
	SetProp(P_SHORT,"Ein Handbuch fuer Anfaenger");
	SetProp(P_LONG,"Ein Handbuch fuer Anfaenger.\n");
	SetProp(P_NAME,"Buch");
	AddId(({"handbuch","buch","anfaengerbuch"}));
	SetProp(P_GENDER,NEUTER);
	SetProp(P_ARTICLE,1);
}

init()
{
	add_action("nimm","nimm");
}

nimm(str)
{
  string was;
  notify_fail("Was willst Du nehmen ? Syntax: NIMM <ETWAS>.\n");
  if(!str || !id(str)) return 0;
  if(sscanf(str,"%s",was)!=1) return 0;
  if(member(QueryProp(P_IDS),was)<0) return 0;
  if(present("erste schritte",this_player()))
  {
    write("Du hast doch schon ein Buch...\n");
    return 1;
  }
  say(this_player()->name() + " nimmt ein Buch.\n",this_player());
  write("Du nimmst ein Buch. Sofort erscheint auf unerklaerliche Weise ein neues.\n");
  clone_object("/obj/anfaengerbuch")->move(this_player());
  return 1;
}

move(target, method)
{
  if (method&M_GET&&living(target))
    return get(target);
  else
    return ::move(target,method);
}

get(targ)
{
  if (!targ || !interactive(targ) || targ != this_player())
    return 0;
  if (present("erste schritte", this_player()))
  {
    write("Du hast doch schon ein Buch...\n");
    return 0;
  }
  clone_object("/obj/anfaengerbuch")->move(targ,M_GET);
  write("Du nimmst ein Buch. Sofort erscheint auf unerklaerliche Weise ein neues.\n");
  say(targ->name(WER)+" nimmt ein Buch.\n",targ);
  return 1;
}
