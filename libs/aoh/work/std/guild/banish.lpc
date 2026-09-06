/*
** Banisher to banish someone from the guild
** by Thragor, 31oct94
*/

#include <guild.h>
#include <secure/wizlevels.h>
#include <config.h>

#define ME this_object()
#define STR "/obj/lib/string"

mapping banished;
// ([name:time of banish;banisher;reason])

/*
* ----------------------------------------------------------------------
* Helpfunctions
* ----------------------------------------------------------------------
*/

protected int check_banish(string whom,string who)
{
  if (IS_IMMORTAL(who)) return 1;
  return ({int})ME->is_leader(who);
}

public string find_savefile(mixed pl)
{
  string res;

  if (!pl) return 0;
  if (objectp(pl))
    pl = getuid(pl);
  res = "/" SAVEPATH+pl[0..0]+"/"+pl+".o";
  if (file_size(res)<1) return 0;
  return res;
}

/*
* ----------------------------------------------------------------------
* Banishing players from the guild
* ----------------------------------------------------------------------
*/

public mapping SetBanish(mapping b)
{
  if (!IS_WIZARD(this_interactive())) return banished;
  if (!mappingp(b)) return banished = 0;
  return banished = b;
}

public mapping QueryBanish() { return banished; }

public string AddBanish(string whom,string why)
{
  string who;
  who = getuid(this_interactive());
  if (!whom) return ERR_NONAME;
  whom = lower_case(whom);
  if (!find_savefile(whom)) return ERR_NOPLAYER;
  if (!check_banish(whom,who)) return ERR_NOALLOW;
  if (member(m_indices(banished||([])),whom)!=-1) return ERR_ALREADY;
  if (!banished) banished = m_allocate(0,3);
  log_file("GUILDBANISH",ctime()+" "+capitalize(who)+" banished "+
                         capitalize(whom)+" from "+({string})ME->QueryGuildname()+"\n"+
                         " Reason: "+(why?why:"<no reason given>")+"\n");
  banished[whom,BANISH_TIME] = time();
  banished[whom,BANISH_BANISHER] = who;
  banished[whom,BANISH_REASON] = why?why:"<no reason given>";
  return NO_ERR;
}

public string RemoveBanish(string whom)
{
  string who;
  who = getuid(this_interactive());
  if (!whom) return ERR_NONAME;
  whom = lower_case(whom);
  if (!check_banish(whom,who)) return ERR_NOALLOW;
  if (member(m_indices(banished),whom)==-1) return ERR_NOT_BANISHED;
  log_file("GUILDBANISH",ctime()+" "+capitalize(who)+" removed banish for "+
                         capitalize(whom)+" from "+({string})ME->QueryGuildname()+"\n");
  m_delete(banished,whom);
  return NO_ERR;
}

public string ListBanished()
{
  int i;
  string *m,result;

  m = sort_array(m_indices(banished||([])),#'> /*'*/);
  result = "Name        |Banisher    |Reason\n"
           "------------+------------+--------------------------------------\n";
  for (i=0;i<sizeof(m);i++)
    result+=({string})STR->ladjust(capitalize(m[i]),12)+"|"+
            ({string})STR->radjust(banished[m[i],BANISH_BANISHER],12)+"|"+
            banished[m[i],BANISH_REASON];
  return result;
}

public int IsBanished(string whom)
{
  return (member(m_values(banished||([])),whom)!=-1);
}

public string Banisher(string whom)
{
  return (banished||([]))[whom,BANISH_BANISHER];
}

