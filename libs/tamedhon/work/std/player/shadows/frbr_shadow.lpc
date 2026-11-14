// /std/player/shadows/frbr_shadow.c  Shadow-Object zur 'Froschbrille'
// 22-09-95  - Mupfel@MorgenGrauen -

#include <language.h>
#include <properties.h>
#include <defines.h>

object pl;

void _frosch_sicht(object player, int on)
{
  pl = player;
  if (!pl || !interactive(pl))
  {
    destruct(ME);
    return;
  }
  if (on)
  {
    if (!shadow(pl, 1)) destruct(ME);
    write("shadow on\n");
  }
  else
  {
    unshadow();
    write("shadow off\n");
    destruct(ME);
  }
}

string name(int casus, int demonst)
{
  string s;
  
  write("*** name called ***");
  
  if(pl->QueryProp(P_INVIS))
  {
    if( casus == RAW ) return "Jemand";
    return ({"Jemand","Jemands","Jemandem","Jemanden"})[casus];
  }
  if (pl->QueryProp(P_FROG) && casus != RAW)
  {
    pl->SetProp(P_ARTICLE,1);
    s=pl->QueryArticle(casus,0)+"Frisch";
    if (casus==WESSEN) s += "es";
    pl->SetProp(P_ARTICLE,0);
    return s;
  }
  return pl->name(casus, demonst);
}
