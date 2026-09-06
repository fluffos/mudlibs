/*
** A generic scroll
** Spells on such a scroll can be added to spellbooks if they are memorizeable.
**
**         [j] Idea 
** 09jun95 [t] Some technical improvements
** 24jul95 [s] Completly rewritten and adabted to obj/caster
** 12mar96 [s] Added some new Functions concerning Allow/ForbidCast
** 20mar96 [s] Added use of ScrollObject
**
** [j] Joern
** [s] Softbyte
** [t] Thragor
*/

#include <search.h>
#include <properties.h>
#include <config.h>
#include <magic.h>
#define P_SCROLLOBJ "ScrollObject"
#include <guild.h>

#define TP this_player()
#define TO this_object()
#define PO previous_object()

inherit "/obj/caster";
inherit STD_TELEPORT;


private nosave string spellname=0;

private int memo = 1,
            destr = 1,
            castnumber=0,
            castmaxnumber=1;
private nosave closure ffail;

mapping castlevel;
mapping QueryCastlevels() {return castlevel;}
private mapping memolevel;
mapping QueryMemolevels() {return memolevel;}

void ValidSpell(string str);

void NoSell() { Set(P_NOSELL,1); }

/* ----------------- Auxiliary Functions --------------------------- */
/* Draw a random enemy for attack spells (if no target given) */
public varargs object GetEnemy(object caster)
{
object *enem;
   if (!caster) caster=this_player();
   enem = caster->QueryEnemies();
   if (sizeof(enem)) return enem[random(sizeof(enem))];
   return 0;
}

/* Checks whether a ScrollObject is defined and contains a function  */
/* <funname> and the scrollobject is not the previous_object(), this */
/* allows the scrollobject to directly call the function in this ob  */
object ScrollObject(string funname)
{
object s_obj;
  if ( ( TP && s_obj=TP->Query(P_SCROLLOBJ)) && (s_obj!=PO) &&
        function_exists(funname, s_obj) ) return s_obj;
  return 0;
}

/* Checks whether str is one of certain macros, like "all" and       */
/* an array of string containing ({str}) or its proper replacement(s)*/
string *ResolveMacro(string str)
{
  if (!str) return ({});
  switch(str)
  {
    case "all": return GC_APPROVED;
    break;
    case "allmage": return ({GC_ARCHMAGE,GC_CONJURER,GC_SORCERER});
    break;
    case "both": return ({GC_CONJURER,GC_SORCERER}); 
    break;
    default: return ({str});
  }
  return ({str});
}
/* Adds the two mappings toadd and old. If a key is present in both  */
/* the one in toadd will be used. The indices of toadd are also      */
/* processed by ResolveMacro() allowing shortcuts like "all",...     */
varargs mapping ResolveMapping(mapping toadd,mapping old)
{
string *ind;
string *strs;
int i,j,lev;
  if (!toadd) return ([]);
  if (!old) old=([]);
  ind=m_indices(toadd);
  for (i=0;i<sizeof(ind);i++)
  {
    lev=toadd[ind[i]];
    strs=ResolveMacro(ind[i]);
    for (j=0;j<sizeof(strs);j++)
    {
      if (member(old,strs[j])) old[strs[j]]=lev;
      else old+=([strs[j]:lev]);
    }
  }
  return old;
}
/* ----------------- Set Properties of the Scroll ------------------ */
/* From which level can which guild memorize the scroll               */
/* arg1 can either be a level, then guilds="all" or a guild then arg2 */
/* has to be the min. level or it can be a mapping of the type        */
/* (["guild1":level1,"guild2":level2)]                                */
varargs int SetMemoLevel(mixed arg1,int arg2)
{
mapping tmp;
int i;
  if (!memolevel) memolevel=([]);
  if (!arg1) return 0;
  if (intp(arg1)) tmp=(["all":arg1]);
  else if (stringp(arg1)) tmp=([arg1:arg2]);
  else if (mappingp(arg1)) tmp=arg1;
  else return 0;
  i=m_values(tmp)[0]; 
  SetValue(i*10+50);  /* Never overwrite QueryValue ! */
  memolevel=ResolveMapping(tmp,memolevel);
  return 1;
 }
varargs int QueryMemoLevel(string guild)
{
int res;
object s_obj;
  if (!memolevel) memolevel=([]);
  if (s_obj=ScrollObject("QueryMemoLevel")) 
      return s_obj->QueryMemoLevel(guild);
  if (!guild && TP) guild=TP->QueryGuild();
  if (!guild) return 100;
  res=memolevel[guild];
  if (!res) return 100;
  return res;
}
/* Guild(s) given here via "guild" or ({"guild1","guild22",..}) can  */
/* not memorize the scroll                                           */
int ForbidMemo(mixed strs)
{
string *tmp;
int i;
  if (!memolevel) memolevel=([]);
  if (!strs) return 0;
  if (stringp(strs)) strs=({strs});
  tmp=({});
  for (i=0;i<sizeof(strs);i++)
  {
    tmp+=ResolveMacro(strs[i]);
  }
  for (i=0;i<sizeof(tmp);i++)
  {
    m_delete(memolevel,tmp[i]);
  }
  return 1;
}
/* Gives true if TP||who is allowed to memorize this spell. Check    */
/* for Level and Guild are performed                                 */
varargs int CanMemo(object who)
{
int lev,minlevel;
string guild;
object s_obj;
  if (!memolevel) memolevel=([]);
  if (s_obj=ScrollObject("CanMemo")) 
        return s_obj->CanMemo(who);
  if (!who) who=TP;
  if (!who) return 0;
  guild=who->QueryGuild();
  lev=who->QueryLevel();
  if (!guild) return 0;
  minlevel=memolevel[guild];
  if (minlevel<1) return 0;
  if (lev<minlevel) return 0;
  return 1;
}


/* From which level can which guild cast the scroll                   */
/* arg1 can either be a level, then guilds="all" or a guild then arg2 */
/* has to be the min. level or it can be a mapping of the type        */
/* (["guild1":level1,"guild2":level2)]                                */
varargs int SetCastLevel(mixed arg1,int arg2)
{
mapping tmp;
  if (!castlevel) castlevel=([]);
  if (!arg1) return 0;
  if (intp(arg1)) tmp=(["all":arg1]);
  else if (stringp(arg1)) tmp=([arg1:arg2]);
  else if (mappingp(arg1)) tmp=arg1;
  else return 0;
  castlevel=ResolveMapping(tmp,castlevel);
  return 1;
}
/* Returns the level from which a certain guold can cast this scroll  */
/* 0: means no cast at all                                            */
varargs int QueryCastLevel(string guild)
{
object s_obj;
  if (!castlevel) castlevel=([]);
  if (s_obj=ScrollObject("QueryCastLevel")) 
        return s_obj->QueryCastLevel(guild);
  if (!guild && TP) guild=TP->QueryGuild();
  if (!guild) return 0;
  return castlevel[guild];
}
/* Guild(s) given here via "guild" or ({"guild1","guild22",..}) can  */
/* not use the scroll                                                */
int ForbidCast(mixed strs)
{
string *tmp;
int i;
  if (!castlevel) castlevel=([]);
  if (!strs) return 0;
  if (stringp(strs)) strs=({strs});
  tmp=({});
  for (i=0;i<sizeof(strs);i++)
  {
    tmp+=ResolveMacro(strs[i]);
  }
  for (i=0;i<sizeof(tmp);i++)
  {
    m_delete(castlevel,tmp[i]);
  }
  return 1;
}
/* Gives true if TP||who is allowed to cast this spell. Check for    */
/* Level and Guild are performed                                     */
varargs int CanCast(object who)
{
int lev,minlevel;
string guild;
object s_obj;
  if (!castlevel) castlevel=([]);
  if (s_obj=ScrollObject("QueryCastLevel")) 
        return s_obj->QueryCastLevel(guild);
  if (!who) who=TP;
  if (!who) return 0;
  guild=who->QueryGuild();
  lev=who->QueryLevel();
  if (!guild) return 0;
  minlevel=castlevel[guild];
  if (minlevel<1) return 0;
  if (lev<minlevel) return 0;
  return 1;
}

/* scroll will be desctructed after use */
public int SetDestruct(int i) { return destr = i; }
public int QueryDestruct() { return destr; }
public void NoDestruct() { SetDestruct(0); }

/* scroll is memorizable */
public int SetMemorize(int i) { return memo = i; }
public int QueryMemorize() { return memo; }
public void NoMemorize() { SetMemorize(0); }

/* number of times casted , usually 0 or 1 */
public int SetCasted(int i) { return castnumber = i; }
public int QueryCasted() { return castnumber; }

/* max. number of times a scroll can be casted until it becomes useless */
/* usually 1 */
public int SetMaxCasted(int i) { return castmaxnumber = i; }
public int QueryMaxCasted() { return castmaxnumber; }

/* spell name of this_object */
string QueryCastName() { return this_spell(); }

/* -------------- Failcheck Functions -------------------------------- */
mixed CheckCastLevel(string spname)
{
int lev;
  if (!CanCast(TP))
  {
     RestoreSP();
     if ( (lev=QueryCastLevel(TP->QueryGuild()) ) )
        return "You need to be level "+lev+" to use this scroll.\n";
     else return "Your guild can not use this particular scroll.\n";
  }
  return 0;
}
mixed ScrollFailCheck(string spname)
{
  if (TP->Query(P_BLIND))
  {
     RestoreSP();
     return "You are blind.\n";
  }
  if (QueryCasted()>=QueryMaxCasted())
  {
    RestoreSP();
    return "The scroll is useless. Someone already casted the spell!\n";
  }
  if (QuerySpellStrength()!=0)
  {
    RestoreSP();
    return "Lesser and greater casts are not yet supported!\n";
  }
  return 0;
}
/* Action after casting a spell */
void CastOver(int flag,string spname)
{
  if (flag==CAST_SUCCESS || flag==CAST_REPULSE)
  {
       castnumber++;  /* 3==CAST_SUCCESSFUL */
  }
  if ( (QueryCasted()>=QueryMaxCasted()) && QueryDestruct())
  {
      call_out("remove",1);
  }
}
/* Chance that a spell will backfire */
int Backfire(string spname)
{
int res;
  switch(TP->QueryAttribute("Wis"))
  {
    case 0..5: return 66;
    case 6..10: return 45;
    case 11..15: return 25;
    case 16..20: return 15; 
    default: return 5;
  }
  return 5;
}

varargs int AddSpell(string spname,mixed spelltype,mixed SPcost,closure castfun,
                     string longname,mixed failchance,mixed backfire)
{
  if (::AddSpell(spname,spelltype,SPcost,castfun,longname,failchance,#'Backfire /*'*/))
  {
    AddFailCheck(#'ScrollFailCheck /*'*/,spname);
    AddFailCheck(#'CheckCastLevel /*'*/,spname);
    AddFailCheck(#'CheckWisdom /*'*/,spname);
    SetSuccessFunction(#'CastOver /*'*/,spname);
    AddId(spname);
    AddId(longname);
    SetValue(QueryMemoLevel()*10+50);  /* Never overwrite QueryValue ! */
    spellname=spname;
  }
  else  write("Error: Cannot initialize spell !\n");
  return 1; 
}
public closure SetFailFn(mixed fun)
{
  if (stringp(fun))
    {
      if (!function_exists(fun,TO))
        MASTER->runtime_error("Fail-Function "+fun+" not defined.\n",
                              blueprint(TO),object_name(TO),-1);
      fun = symbol_function(fun,TO);
    }
  return ffail = fun;
}
public closure QueryFailFn() {return ffail;}


public varargs string QueryShort()
{
  if (!::QueryShort()) return 0; /* invis */
  if (QueryCasted()<QueryMaxCasted())
     return "a scroll ("+(QueryLongName()||"empty")+")";
  return "a used scroll ("+(QueryLongName()||"empty")+")";
}

public string QueryReadMsg()
{
string res;
string *us;
int i,lev;
  res=QuerySpellMsg(spellname);
  if (!res||res=="") return "The scroll is completely empty.\n";
  lev=QueryCastLevel();
  if (!lev) res+="Unfortunately, you are not able to use this spell.\n";
  else if (!CanCast()) res+="You need to be level "+lev+" to use this spell.\n";
  else
  {
    lev=QueryMemoLevel();
    if (!QueryMemorize()) res+="This scroll is not prepared to be memorized.\n";
    if (!lev || lev>=100) res+="Members of your Guild can not memorize this spell.\n";
    else res+="You need to be level "+lev+" to memorize this spell.\n";
  }
 return res;
}

varargs mixed NotifySpellFail(object enemy,object caster,string spname)
{
mixed res;
  if ( (enemy!=0) || !QueryFailFn() )
       return ::NotifySpellFail(enemy,caster,spname);
  res=funcall(QueryFailFn()); /* >0: success */
  if (intp(res))
  {
    SetCastResult(res);
    if (res>0) CastOver(CAST_REPULSE,spname); /* handle fail here as repulse!*/
    return "";  /* write and say already done! */
  }
  else return res;
}

public void create()
{
  caster::create();
//  if (sizeof(explode(object_name(this_object()),"#"))<2) return;
  castlevel=([]);
  memolevel=([]);
  SetShort("a scroll");
  SetLong("This is a very old parchment. You can read it.\n");
  SetIds(({"scroll","parchment"}));
  SetValue(5);
  SetWeight(15);
  SetMagic(1);
  ForbidDescribe();   /* We have read here */
  IndirectCast();     /* Right now we use "cast <spname> [at] <target>" */
  SetCastLevel("all",1);
  ForbidCast(({GC_DRUID,GC_VAMPIRE,GC_WARRIOR}));
  ForbidMemo("all");
}
/* COMPAT only */
varargs void SetUser(mixed rg)
{
}
