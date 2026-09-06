/* Adapted and improved by Softbyte 1995 */
#include <guild.h>
#include <magic.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
  object mon;
  int st;
  if (!str || !(mon=present(str,environment(this_player())) ) )
  {
    write("That's not here.\n");
    return CAST_FAIL_NOMSG;
  }
  if (mon->Query("weak")>0)
  {
     write("That one is too weak.\n");
     return CAST_FAIL_NOMSG;
  }
  if (Repulse(mon, this_player())) return CAST_REPULSE;
  mon->Set("weak",1);
  st=this_player()->QueryInt()/4;
  if (mon->QueryStr()-st<1) st=mon->QueryStr()-1;
  mon->ModifyAttr("Str",-st);
  Message( ({ capitalize(mon->QueryName())+ " is a bit weaker now.\n",
              capitalize(mon->QueryName())+ " is a bit weaker now.\n"}) );
  return CAST_SUCCESS;
}

int MyFail() 
{
  if (Repulse(this_player(), this_player())) return CAST_REPULSE;
  if (random(10)>0) return CAST_REPULSE;
  Message(({"You are a bit weaker now.\n",
      this_player()->QueryName()+" is a bit weaker now.\n"}));
  this_player()->MofifyAttr("Str",-1);
  return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("weakness",ST_CHANGE,60,#'MyCast,"weakness",45);
 SetSpellDesc(
"This spell will make a monster a bit weaker by reducing its strength\n\
by Int/4.\n");
 SetSpellUsage("cast weakness <monster>\n");
 SetMemoLevel(GC_CONJURER,9);
 SetMemoLevel(GC_NECROMANCER,9);
 SetMemoLevel(GC_ARCHMAGE,9);
 
 SetFailFn(#'MyFail);

 NoMemorize();
}

