/* Castobject for all magic spells,scrolls  and objects   */
/* Written by Softbyte [s] August 1995                              */
/* 12mar96 [s] Small changes in connection with obj/scroll.c        */
/* 10may96 [s] Lesser/Greater <spells>                              */
/* 29mar97 [s] Slight changes and support of M_RESISTANCE           */
/* 15apr97 [s] Slight changes in WIS handling                       */


#include <magic.h>
#include <properties.h>
#include <secure/wizlevels.h>
#include <config.h>

inherit "/std/thing";
inherit M_RESISTANCE;

#define P_MODIFYMAGIC "ModifyMagic"

#define M_MAXWIS 25      // maximum Wisdom

#define TP this_player()
#define TO this_object()
#define PO previous_object()
#define VERB query_verb()

/* Actuall we have a bug if the following is ever used */
#define ERROR_MESG "Error: Message called with wrong parameters.\n"

#define DEFAULT_SPCOST 150  
#define DEFAULT_FAILCHANCE 3  

#define _SPMAP_COST 0
#define _SPMAP_TYPE 1
#define _SPMAP_CASTFUN 2
#define _SPMAP_FAILCHANCE 3
#define _SPMAP_BACKFIRE 4
#define _SPMAP_LONG 5
#define _SPMAP_DESC 0
#define _SPMAP_USAGE 1

#define DEFAULT_DAMAGE 0  /* Default damage type for QueryCastDamage */

private nosave mapping spells;  /* spelldata */
private nosave mapping success; /* success functions */
private nosave mapping fails;   /* fail functions */
private nosave mapping description;/* spell descriptions */
private nosave int oldSP;       /* save the SP before the cast */
private nosave object oldmagicobj;  /* save the old magicobj */
private nosave string actualspell; /* actual spell->default spell */
private nosave int allowdescribe;  /* descroibe enabled or not */
private nosave int castmode;    /* forbid casts and select castmode */
private nosave int c_success;   /* return value of castfun */
private nosave int Strength;    /* Spell strength: -1:lesser, 0:normal, 1:greater */
private nosave string castverb,spellnoun; /* use this instead of "cast" and "spell" */
private nosave string spelltarget;   /* the spell is castet at that */

int do_cast(string str);

string QuerySpellTarget() {return spelltarget;}
int SetSpellTarget(string s) {spelltarget=s;return 1;}

string this_spell() {return actualspell;}

void Debug(string str)
{
  object ob;
  ob=find_player("softbyte");
  if (ob) tell_object(ob,str);
}

varargs void LogCast(object caster,object target,string str)
{
string spname;
string c_level,t_level;
int i;
  spname=str||this_spell()||"a spell";
  if (!caster) caster=TP;
  if (!target || (target==caster)) return;
  if (!query_once_interactive(target)) return;

  if (i=query_user_level(caster)) c_level = "w"+i;
  else c_level = caster->QueryLevel()+
         "/"+(RACEMASTER->XPtoLevel(caster->QueryXP()));
  if (i=query_user_level(target)) t_level = "w"+i;
  else t_level = target->QueryLevel()+

  log_file("AGGRESSORS",ctime()+": "+
     (caster->QueryRealName()||getuid(caster))+" ("+c_level+")"+
     " attacked "+(target->QueryRealName()||getuid(target)||"something")+
     " ("+t_level+")"+
     " using '"+spname+"'.\n");
}


/* This function allows to decrease (increase) the effect/damage */
/* a spell does. It should be used very rarely and only when     */
/* allowed by the Departement of Magic                           */
/* It queries the property P_MODIFYMAGIC in this_object,         */
/* this_player and the room the player is in and uses is as      */
/* percentage value, i.e. 75 reduces the effect of magic by 25%  */
int ModifyMagic(int effect)
{
int i;
object env;

int old;
old=effect;
  if (!TP) return effect;
  env=environment(TP);
  if (i=Query(P_MODIFYMAGIC)) effect=effect*i/100;
  if (i=TP->Query(P_MODIFYMAGIC)) effect=effect*i/100;
  if (env && i=env->Query(P_MODIFYMAGIC)) effect=effect*i/100;
  return effect;
}

/* sets this_spell() and returns the old this_spell() */
string SetThisSpell(string str) 
{
string s;
  s=actualspell;
  actualspell=str;
  return s;
}

/* returns 1 if spname is a spell in our spelllist */
int IsSpell(string spname)
{
  if (!spname) return 0;
  if (0==member(spells,spname)) return 0;
  return 1; 
}
/* returns the number of spells stored in this object */
int QueryNumberOfSpells()
{
 return sizeof(m_indices(spells)||({}));
}
/* returns all spnames */
string *QueryAllSpells()
{
 return m_indices(spells)||({});
}

/* Switches the castmode: DisableCast does not allow the commandn */
/* cast. IndirectCast() uses "cast <spname> <target>" and        */
/* DirectCast() uses "<spname> <target>"                         */
/* Default is IndirectCast()                                     */
int DisableCast() {castmode=1; return 1;}
int IndirectCast() {castmode=0; return 1;}
int DirectCast() {castmode=2; return 1;}

/* Enable or disable describe function */
int AllowDescribe() {allowdescribe=0;return 1;}
int ForbidDescribe() {allowdescribe=1;return 1;}

/* Allow to Query the result of a cast , i.e. CAST_XXX */
int SetCastResult(int i) {c_success=i; return i;}
int QueryCastResult() {return c_success;}

/* Allows to Query the 'Strength' of a spell given by */
/* "lesser/greater <spell>"                           */
int QuerySpellStrength() {return Strength;}
int SetSpellStrength(int i) {Strength=i; return i;}

/* Output a MESSAGE to TP (and its environment) */
/* MESSAGE: - string: write string to player    */
/*          - ({string1,string2}) : write string1 to player and string2 */
/*                                  to room                             */
/*          - ({sa,sb,({o1,o2,..}),({s1,s2,...})                        */
void Message(mixed res)
{ 
object *obp;
string *strp;
int i;
  if (!res) return;  /* no output if no message */
  if (stringp(res)) write(capitalize(res));
  else if (pointerp(res))
  {
    if (sizeof(res)==1) write(capitalize(res[0]));
    else if (sizeof(res)==2)
    {
      if (TP) write(capitalize(res[0]));
     say(capitalize(res[1]||""));
    }
    else if (sizeof(res)==4)
    {
      obp=res[2];
      strp=res[3]; 
      if (TP) write(capitalize(res[0]));
      say(capitalize(res[1]),obp+({TP}));
      for (i=0;i<sizeof(obp);i++)
      {
        if (obp[i]==TP) continue; /* Omit TP */
        if (i<sizeof(strp)) tell_object(obp[i],capitalize(strp[i]));
        else tell_object(obp[i],capitalize(strp[sizeof(strp)-1]));
      }
    }
    else write(ERROR_MESG);
  }
  else write(ERROR_MESG);
}
 
/* returns the long name of a spell                */
varargs string QueryLongName(string spname) 
{
  if (!spname) spname=this_spell();
  if (!IsSpell(spname)) return 0;
  return spells[spname,_SPMAP_LONG]; 
}
varargs string SetLongName(string long,string spname)
{
  if (!spname) spname=this_spell();
  if (!IsSpell(spname)) return 0;
  spells[spname,_SPMAP_LONG]=long;
  return long;
}

/* returns the cost of the spell (spname) in SP    */
varargs int QueryCastCost(string spname)
{
mixed SPcost;
  if (!spname) spname=this_spell();
  if (!IsSpell(spname)) return 0;
  SPcost=spells[spname,_SPMAP_COST];
  if (!SPcost) return 0;
  if (closurep(SPcost)) return funcall(SPcost,spname);
  else if (intp(SPcost)) return SPcost;
  else return DEFAULT_SPCOST;
}
varargs int SetCastCost(mixed cost,string spname)
{
  if (!spname) spname=this_spell();
  if (!IsSpell(spname)) return 0;
  if ( !intp(cost) && !closurep(cost) ) return 0;
  spells[spname,_SPMAP_COST]=cost;
  return 1;
}

/* returns the backfire chance of the spell (spname) in %    */
varargs int QueryBackfireChance(string spname)
{
mixed back;
  if (!spname) spname=this_spell();
  if (!IsSpell(spname)) return 0;
  back=spells[spname,_SPMAP_BACKFIRE];
  if (!back) return 0;
  if (closurep(back)) return funcall(back,spname);
  else if (intp(back)) return back;
  else return 0;
}
varargs int SetBackfireChance(mixed back,string spname)
{
  if (!spname) spname=this_spell();
  if (!IsSpell(spname)) return 0;
  if ( !intp(back) && !closurep(back) ) return 0;
  spells[spname,_SPMAP_BACKFIRE]=back;
  return 1;
}

/* returns the type of the spell as defined in magic.h */
varargs mixed QuerySpellType(string spname)
{
  if (!spname) spname=this_spell();
  if (!IsSpell(spname)) return 0;
  return spells[spname,_SPMAP_TYPE];
}
varargs mixed SetSpellType(mixed type,string spname)
{
  if (!spname) spname=this_spell();
  if (!IsSpell(spname)) return 0;
  spells[spname,_SPMAP_TYPE]=type;
  return type;
}

/* returns the function which does the actual cast */
varargs closure QueryCastFunction(string spname)
{
  if (!spname) spname=this_spell();
  if (!IsSpell(spname)) return 0;
  return spells[spname,_SPMAP_CASTFUN];
}
varargs int SetCastFunction(closure fun,string spname)
{
  if (!spname) spname=this_spell();
  if (!IsSpell(spname)) return 0;
  spells[spname,_SPMAP_CASTFUN]=fun;
  return 1;
}

varargs int QueryFailChance(string spname)
{
mixed failchance;
  if (!spname) spname=this_spell();
  if (!IsSpell(spname)) return 0;
  failchance=spells[spname,_SPMAP_FAILCHANCE];
  if (closurep(failchance)) return funcall(failchance,spname);
  else if (intp(failchance)) return failchance;
  else return DEFAULT_FAILCHANCE; 
}
varargs int QueryDifficulty(string spname) {return QueryFailChance(spname);}
string DifficultyToString(int difficulty)
{
  switch(difficulty/5)   /* old failchance was 0..20 */
  {
    case 0:     return "extremly easy";
    case 1..3:  return "very easy";
    case 4..7:  return "easy";
    case 8..11: return "slightly difficult";
    case 12..16: return "difficult";
    case 17..20: return "very difficult";
    default: return "impossible";
  }
  return "impossible";
}

/* returns the failchance of a spell               */
varargs int SetFailChance(mixed fch,string spname)
{
  if (!spname) spname=this_spell();
  if (!IsSpell(spname)) return 0;
  if ( !intp(fch) && !closurep(fch) ) return 0;
  spells[spname,_SPMAP_FAILCHANCE]=fch;
  return 1;
}
varargs int SetDifficulty(mixed fch,string spname) {return SetFailChance(fch,spname);}

/* returns the success function for a spell (spname) */
varargs closure QuerySuccessFunction(string spname)
{
  if (!spname) spname=this_spell();
  if (!spname) return 0;
  if (0==member(success,spname)) return 0;
  return success[spname];
}
varargs int SetSuccessFunction(closure fun,string spname)
{
closure *old;
  if (!spname) spname=this_spell();
  if (!spname) return 0;
  success-=([spname]);
  success+=([spname:fun]);
  return 1;
}

/* Will be called when the spell failed due to lack of ability of */
/* the caster, i.e. Wisdom or when the spell got repulsed         */
/* In the former case enemy will be 0                             */
/* Return 0 for printing the default message to the player and    */
/* the environment, return a string for writing to the player and */
/* return ({s1,s2}) for writing to the player and its environment */
varargs mixed NotifySpellFail(object enemy,object caster,string spname)
{
int i;
string s1,s2,s3;
  if (enemy==0)   /* Failed */
  {
    s1="You "+castverb+" "+add_a(QueryLongName(spname))+" "+spellnoun+".\nFizzle!\n";
    s2=TP->QueryName()+" "+castverb+"s "+add_a(QueryLongName(spname))+
       " "+spellnoun+".\nFizzle!\n";
    return ({s1,s2});
  }
  else if (enemy==TP)  /* backfired and repulsed by ourself */
  {
     s1="Luckily you are protected against backfiring "+spellnoun+"s.\n";
     s2=TP->QueryName()+" is not affected by "+add_a(QueryLongName(spname))+
       " "+spellnoun+".\n";
     return ({s1,s2});
  }
  else  /* backfired */
  {
     s1=(enemy->QueryName()||enemy->QueryShort())+
        " is protected against your "+spellnoun+".\n";
     s2=(enemy->QueryName()||enemy->QueryShort())+" is not affected by "+
         add_gen(TP->QueryName())+" "+spellnoun+".\n";
    s3="Luckily you are protected against "+add_gen(TP->QueryName())+
      " "+spellnoun+".\n";
    Message( ({ s1,s2,({enemy}),({s3}) }) );
    if (random(100)<QueryBackfireChance(spname))  
    {
      i=Query(P_MODIFYMAGIC);
      if (i) Set(P_MODIFYMAGIC,i/2);
      else Set(P_MODIFYMAGIC,50);
      s1="The "+spellnoun+" backfires!\n";
      s2="The "+spellnoun+" backfires at "+TP->QueryName()+".\n";
      Message( ({ s1,s2 }) );
      funcall(QueryCastFunction(spname),TP->QueryName(),spname,1);
      if (i) Set(P_MODIFYMAGIC,i);
      else Set(P_MODIFYMAGIC,0);
     }
     return "";
  }
  return 0;
}

/* Checks whether the cast has enough wisdom to cast the spell   */
/* Calls SpellFail(spellname,TP) and returns a text for printing */
/* This is also an examle for a fail function !                  */
/*
  Wis  :  F=01 F=04 F=07 F=10 F=13 F=16 F=19  F=failchance/5
  W= 0 :   300  235  175  115   55    0    0
  W= 3 :   400  340  280  220  160  100   40
  W= 6 :   500  445  385  325  265  205  150
  W= 9 :   610  550  495  430  370  310  250
  W=12 :   715  650  595  535  475  365  350
  W=15 :   820  760  700  640  580  520  460
  W=18 :   925  865  800  750  685  620  565
  W=21 :  1030  970  910  850  790  730  670
*/
varargs mixed CheckWisdom(string spname)
{
int failchance;
int wis;
int chan;
string s1,s2;
mixed tmp;
  if (!spname) spname=this_spell();
  if (!spname) return 0;
  failchance=QueryFailChance(spname);
  if (failchance==0) return 0;  /* Always works with failchance ==0 */
  wis=TP->QueryAttr("Wis");
  if (wis>M_MAXWIS) wis=M_MAXWIS;

  /* Magic formula ! */
  chan=MAGIC_WISDOM(wis,failchance);     // 0-1000
  if (chan>1200) chan=1200;              //hmmm, why 1200 ?
  if (chan<0) chan=0;
  if (random(1000)<chan) return 0;   /* Success */

  s1="You fail to "+castverb+" a "+spellnoun+" named "+
      (QueryLongName(spname)||spname)+".\n";
  s2=TP->QueryName()+" fails to "+castverb+" a "+spellnoun+" named "+
      (QueryLongName(spname)||spname)+".\n";
  tmp=NotifySpellFail(0,TP,spname);
  if (tmp) return tmp;
  return ({s1,s2});
}
/* returns all fail check functions for a spell */
varargs closure *QueryFailChecks(string spname)
{
  if (!spname) spname=this_spell();
  if (!spname) return ({});
  if (0==member(fails,spname)) return ({});
  return fails[spname];
}
/* Add a failcheckfunction for a spell         */
varargs int AddFailCheck(closure failfun,string spname)
{
closure *old;
  if (!spname) spname=this_spell();
  if (!spname) return 0;
  old=fails[spname]||({});
  old+=({failfun});
  fails-=([spname]);
  fails+=([spname:old]);
  return 1;
}
/* Set all failcheckfunctions for a spell      */
varargs int SetFailChecks(closure *failfuns,string spname)
{
closure *old;
  if (!spname) spname=this_spell();
  if (!spname) return 0;
  fails-=([spname]);
  fails+=([spname:failfuns]);
  return 1;
}

varargs string QuerySpellDescription(string spname) 
{
  if (!spname) spname=this_spell();
  if (!spname) return 0;
  if (0==member(description,spname)) return 0;
  return description[spname,_SPMAP_DESC];
}
varargs string QuerySpellDesc(string spname)
 {return QuerySpellDescription(spname);}
varargs int SetSpellDescription(string desc,string spname)
{
  if (!spname) spname=this_spell();
  if (!spname) return 0;
  /* do we already have an entry, i.e. a usage string ? */
  if (0==member(description,spname)) description+=([spname:desc;0]);
  else description[spname,_SPMAP_DESC]=desc;
  return 1;
}
varargs int SetSpellDesc(string desc,string spname) 
{return SetSpellDescription(desc,spname);}
varargs string QuerySpellUsage(string spname) 
{
mixed usage;
  if (!spname) spname=this_spell();
  if (!spname) return 0;
  if (0==member(description,spname)) return 0;
  usage=description[spname,_SPMAP_USAGE];
  if (stringp(usage)) return usage;
  else if (closurep(usage)) return funcall(usage,spname);
  else return 0;
}
/* Usage is either string or closure returning string */
varargs int SetSpellUsage(mixed usage,string spname)
{
  if (!spname) spname=this_spell();
  if (!spname) return 0;
  if (stringp(usage))  /* remove CR */
  {
    if (usage && sizeof(usage)>1 && usage[<1..<1]=="\n" )
      usage=usage[0..<2];
  }
  else if (!closurep(usage)) return 0; /* error */

  /* do we already have an entry, i.e. a desc string ? */
  if (0==member(description,spname)) description+=([spname:0;usage]);
  else description[spname,_SPMAP_USAGE]=usage;
  return 1;
}
varargs int AddSpell(string spname,mixed spelltype,mixed SPcost,closure castfun,string longname,mixed failchance,mixed backfire)
{
  if (!spname) return 0;
  actualspell=spname;   /* set this_spell...is a little dangerous but do it anyway */
  /* Argument check */
  if ( !spelltype || (!intp(spelltype)&& !stringp(spelltype)) ) return 0;
  if ( !SPcost || (!intp(SPcost)&& !closurep(SPcost)) ) return 0;
  if (!castfun) return 0;
  if (!failchance) failchance=0;
  else if ( !intp(failchance)&& !closurep(failchance) ) return 0;
  if (!backfire) backfire=0;
  else if ( !intp(backfire)&& !closurep(backfire) ) return 0;
  if (!longname) longname=spname;
  if (!spells) spells=([]);
  if (!success) success=([]);
  if (!fails) fails=([]);
  if (!description) description=([]);
  if (!castverb) castverb="cast";
  if (!spellnoun) spellnoun="spell"; 


  spells-=([spname]);
  spells+=([spname:SPcost;spelltype;castfun;failchance;backfire;longname]);
  return 1;
}

/* restores the SP of a player to its value before the cast   */
/* if argument is given restore amount of SP by adding amount */
/* to players SP                                              */
varargs int RestoreSP(int amount)
{
int sp;
  if (amount) sp=TP->QuerySP()+amount;
  else if (!oldSP) return 0;
  else sp=oldSP;
  return TP->SetSP(sp);
}
/* compatibility only */
int ReduceSP() { return TP->ReduceSP(QueryCastCost()); }

/* Returns a string that is the description and usage of a   */
/* spell (spname). Can be used into QueryReadMsg() too !     */
varargs string QuerySpellMsg(string spname)
{
string res;
string desc;
mixed usage;
  if (!spname) spname=this_spell();
  if (!spname) return "";
  if (0==member(description,spname)) return "";
  desc=QuerySpellDescription(spname);
  usage=description[spname,_SPMAP_USAGE];
  res="";
  if (desc) res+=desc;
  if (usage)
  {
    if (stringp(usage))
    res+="Usage: "+usage+"\n"+
         "It will cost you "+to_string(QueryCastCost(spname))+
         " spellpoints to "+castverb+" this "+spellnoun+"\n"+
         "and the "+spellnoun+" is "+DifficultyToString(QueryDifficulty(spname))+
         " to use.\n";
   else res+=funcall(usage,spname)||"";
  }
  return res;
}

/* The verb and noun used for the cast command and descriptions */
int SetCastVerb(string str) {castverb=str;return 1;}
string QueryCastVerb() {return castverb;}
int SetSpellNoun(string str) {spellnoun=str;return 1;}
string QuerySpellNoun() {return spellnoun;}

/* Write the MESSAGE that a spell had been casted */
/* This can be changed if you use some other way to invoke magic like */
/* singing ... */
varargs mixed QueryCastActionMessage(string spname,string longname,object who)
{
  if (!spname) return 0;
  if (!who) who=TP;
  if (!longname) longname=QueryLongName(spname)||spname;
  if (who->QueryInvis())
      return ("You prepare "+add_a(longname)+ " spell.\n");
  return (({"You prepare "+add_a(longname)+ " spell.\n",
            who->QueryName()+" prepares "+add_a(longname)+" spell.\n"}));
}


varargs mixed QueryCastDamage(int damage,object enemy,mixed damtype,string spname,object me)
{
string s1,s2,s3;
string vicmsg,plmsg,envmsg;
string name,names,cname;
string lname;
string noun;
  if (!me) me=TO;
  if (!spname) spname=this_spell();
  if (!enemy) enemy=TP;
  if (spname) lname=add_a(me->QueryLongName(spname)||spname);
  else lname="";
  if (spname && !damtype) damtype=me->QuerySpellType(spname);
  if (!damtype) damtype=DEFAULT_DAMAGE;
  noun=me->QuerySpellNoun();

  if (enemy==TP)
  {
     name=TP->QueryObjective()+"self";
     names=TP->QueryPossessive();
  }
  else
  {
    name=capitalize(enemy->QueryName()||enemy->QueryShort()||"someone");
    names=add_gen(name);
  }
  cname=capitalize(TP->QueryName()||TP->QueryShort()||"someone");
  
  switch(damtype)
  {
    case DT_FIRE:
    switch(damage)
    {
     case 0: vicmsg = "You are not hurt";
             plmsg  = name+" is not hurt";
             envmsg = cname+" doesn't hurt "+name; break;
     case 1..5: vicmsg = "Some of your hairs are burned";
             plmsg  = "You burn some of "+names+" hairs";
             envmsg = cname+" burns some of "+names+" hairs"; break;
     case 6..10: vicmsg = "Your skin is slightly burned";
                plmsg  = "You slightly burn "+names+" skin";
                envmsg = cname+" slightly burns "+names+" skin"; break;
     case 11..20: vicmsg = "You are burned";
                plmsg  = "You burn "+name; 
                envmsg = cname+" burns "+name; break;
     case 21..30: vicmsg = "You are burned hot";
                 plmsg  = "You burn "+name+" hot";
                 envmsg = cname+" burns "+name+" hot"; break;
     case 31..40: vicmsg = "You are burned very hot";
                  plmsg  = "You burn "+name+" very hot";
                  envmsg = cname+" burns "+name+" very hot"; break;
     case 41..55: vicmsg = "You are carbonized";
                  plmsg  = "You carbonize "+name;
                  envmsg = cname+" carbonizes "+name; break;
     case 56..70: vicmsg = "You are carbonized to small ashes";
              plmsg  = "You carbonize "+name+" to small ashes";
              envmsg = cname+" carbonizes "+name+" to small ashes";
     default: vicmsg = "You are varporized to ashes";
              plmsg  = "You varporized "+name+" to ashes";
              envmsg = cname+" varporizes "+name+" to ashes";
    } /* end fire */
    break;
    case DT_COLD:
    switch(damage)
    {
     case 0: vicmsg = "You are not hurt";
             plmsg  = name+" is not hurt";
             envmsg = cname+" doesn't hurt "+name; break;
     case 1..5: vicmsg = "Your skin is made creeping";;
             plmsg  = "You make "+names+" skin creeping";
             envmsg = cname+" makes "+names+" skin creeping"; break;
     case 6..10: vicmsg = "Your skin is made freezing";
                 plmsg  = "You freeze "+names+" skin";
                 envmsg = cname+" freezes "+names+" skin"; break;
     case 11..20: vicmsg = "You are freezed";
                  plmsg  = "You freeze "+name; 
                  envmsg = cname+" freezes "+name; break;
     case 21..30: vicmsg = "You are freezed cold";
                  plmsg  = "You freeze "+name+" cold";
                  envmsg = cname+" freezes "+name+" cold"; break;
     case 31..40: vicmsg = "You are freezed very cold";
                  plmsg  = "You freeze "+name+" very cold"; 
                  envmsg = cname+" freezes "+name+" very cold"; break;
     case 41..55: vicmsg = "You are completely freezed";
                  plmsg  = "You freeze "+name+" completely";
                  envmsg = cname+" freezes "+name+" completely"; break;
     case 56..70: vicmsg = "You are freezed to ice ";
                  plmsg  = "You freezed "+name+" to ice";
                  envmsg = cname+" freezes "+name+" to ice"; break;
     default: vicmsg = "You are freezed to an icecube";
              plmsg  = "You freezes "+name+" to an icecube";
              envmsg = cname+" freezes "+name+" to an icecube";
    }
    break;
    case DT_PSYCHO:
    switch(damage)
    {
     case 0: vicmsg = "You are not hurt";
             plmsg  = name+" is not hurt";
             envmsg = cname+" doesn't hurt "+name; break;
     case 1..5: vicmsg = "Your skin is made creeping";;
             plmsg  = "You make "+names+" skin creeping";
             envmsg = cname+" makes "+names+" skin creeping"; break;
     case 6..10: vicmsg = "Your are slightly shocked";
                 plmsg  = "You shock "+name+" slightly";
                 envmsg = cname+" shocks "+name+" slighly"; break;
     case 11..20: vicmsg = "You are shocked";
                  plmsg  = "You shock "+name; 
                  envmsg = cname+" shocks "+name; break;
     case 21..30: vicmsg = "You feel dizzy";
                  plmsg  = "You make "+name+" feel dizzy";
                  envmsg = cname+" makes "+name+" feel dizzy"; break;
     case 31..40: vicmsg = "You feel very dizzy";
                  plmsg  = "You make "+name+" feel very dizzy"; 
                  envmsg = cname+" makes "+name+" feel very dizzy"; break;
     case 41..55: vicmsg = "You have a brain shock";
                  plmsg  = "You give "+name+" a brain shock";
                  envmsg = cname+" gives "+name+" a brain shock"; break;
     case 56..70: vicmsg = "Your brain is scrambled";
                  plmsg  = "You scramble "+names+" brain";
                  envmsg = cname+" scrambles "+names+" brain"; break;
     default: vicmsg = "Your brain is thouroughly scrambled";
              plmsg  = "You scramble "+names+" brain thouroughly";
              envmsg = cname+" scrambles "+names+" brain thouroughly";
    }
    break;
    default:
    switch(damage)
    {
     case 0: vicmsg = "You are not hurt";
             plmsg  = name+" is not hurt";
             envmsg = cname+" doesn't hurt "+name; break;
     case 1..5: vicmsg = "You are slightly hurt";
                plmsg  = "You hurt "+name+" slightly";
                envmsg = cname+" hurts "+name+" slightly"; break;
     case 6..10: vicmsg = "You are hurt";
                 plmsg  = "You hurt "+name;
                 envmsg = cname+" hurts "+name; break;
     case 11..20: vicmsg = "You are badly hurt";
                  plmsg  = "You hurt "+name+" badly";
                  envmsg = cname+" hurts "+name+" badly"; break;
     case 21..30: vicmsg = "You are severely hurt";
                  plmsg  = "You hurt "+name+" severely";
                  envmsg = cname+" hurts "+name+" severely"; break;
     case 31..40: vicmsg = "You are extremely hurt";
                  plmsg  = "You hurt "+name+" extremely";
                  envmsg = cname+" hurts "+name+" extremely"; break;
     case 41..55: vicmsg = "You are massacred";
                  plmsg  = "You massacre "+name;
                  envmsg = cname+" massacres "+name; break;
     case 56..70: vicmsg = "You are massacred to fragments";
                  plmsg  = "You massacre "+name+" to fragments";
                  envmsg = cname+" massacres "+name+" to fragments"; break;
     case 71..95: vicmsg = "You are massacred to bones and dust";
                  plmsg  = "You massacre "+name+" to bones and dust";
                  envmsg = cname+" massacres "+name+" to bones and dust"; break;
     default: vicmsg = "You are totally and thouroughly massacred";
              plmsg  = "You massacre "+name+" totally and thourougly";
              envmsg = cname+" massacres "+name+" totally and touroughly"; break;
    } /* end default damage */
    break;
  } /* end switch damtype */
  if (enemy==TP) 
  {
    if (noun) s1=vicmsg+" by your "+noun+".\n";
    else s1=vicmsg+".\n";
    s2=envmsg;
    if (noun) s2+=" by "+lname+" "+noun+".\n";
    else s2+=".\n";
    return ({ s1,s2 });
  }
  else
  {
    s1=plmsg;
    if (noun) s1+=" by your "+noun+".\n";
    else s1+=".\n";
    s2=envmsg;
    if (noun) s2+=" by "+lname+" "+noun+".\n";
    else s2+=".\n";
    s3=vicmsg;
    if (noun) s3+=" by "+lname+" "+noun+".\n";
    else s3+=".\n";
    return ({ s1,s2,({enemy}),({s3}) });
  }
  return 0;
}

/* me allows calls without inherting this object */
varargs int Repulse(object enemy,object caster,mixed sptype,string spname,object me)
{
int res;
int resistance;
mixed tmp;
string s1,s2,s3;
  if (!me) me=TO;
  if (!enemy) enemy=TP;
  if (!caster) caster=TP;
  if (!spname) spname=me->this_spell();
  if (!caster || !enemy || !spname) return 0;
  if (!sptype) sptype=me->QuerySpellType(spname);
  if (!sptype) sptype=ST_ALL;   /* default */

  res=IsResistant(sptype,enemy);  

  if (res)  // repulsed ... maybe we want some action now
  {
    /* maybe the user wants to do something other then the default */
    tmp=me->NotifySpellFail(enemy,caster,spname);
    if (tmp) Message(tmp);
    else if (caster==enemy)
      Message("Luckily you are protected against backfiring "+
         spellnoun+"s.\n");
    else 
    {
      s1=(enemy->QueryName()||enemy->QueryShort())+
         " is not affected by your "+spellnoun+".\n";
      s2=(enemy->QueryName()||enemy->QueryShort())+" is not affected by "+
         add_gen(TP->QueryName())+" "+spellnoun+".\n";
      s3="Luckily you are protected against "+add_gen(TP->QueryName())+
         " "+spellnoun+".\n";
      Message( ({ s1,s2,({enemy}),({s3}) }) );
    }
  }
  return res;
}

/* --------------------------------------------------------------- */
int do_describe(string spname)
{
  if (allowdescribe==1) return 0;   /* function not defined */
  if (sizeof(spells)==0) return 0;  /* No spells defined */
  if (!spname||!TP)                 /* No spell addressed */
    return notify_fail("Describe what?\n",NOTIFY_NOT_OBJ),0;
  if (0==member(spells,spname))
    return notify_fail("Nothing known about that.\n",NOTIFY_NOT_OBJ),0;
  if (0==member(description,spname))
    return notify_fail("There is no further information about that spell available.\n",
      NOTIFY_NOT_VALID),0;
  actualspell=spname;        /* Set this_spell */
  write(QuerySpellMsg(spname));
  return 1;
}

/* will be called in heartbeat of std/living/combat */
int CastOn() 
{
  if (PO->QueryCombatDelay()<1) 
  {
    PO->SetCastObj(oldmagicobj);
    return 1;  /* drop Heart */
  }
  return 0;
}
/* direct casting i.e. "<spname> [at] [<target>]" instead of */
/* "cast <spname> [at] [<target>]"                           */
int ind_cast(string str)
{
  if (str) return do_cast(VERB+" "+str);
  else return do_cast(VERB);
}
int do_cast(string str)
{
string spname,target,tmpstr;
closure castsuccess;    /* This function is called after the cast */
closure *failfuns;  /* test for failing when casted, they can do appropriate damage as well... */
int i,tmp;
mixed res;
  SetCastResult(CAST_ALLOW_FAIL);
  if (castmode==1) return 0;       /* No cast allowed */
  if (sizeof(spells)==0) return 0;  /* No spells defined */
  if (!str||!TP)                    /* No spell addressed */
    return notify_fail(capitalize(castverb)+" what?\n",NOTIFY_NOT_OBJ),0;
  /* flexibel argument handling */
  str=lower_case(str);
  /* Allower lesser/greater <spells> */
  if (1==sscanf(str,"lesser %s",tmpstr)) {str=tmpstr;SetSpellStrength(-1);}
  else if (1==sscanf(str,"greater %s",tmpstr)) {str=tmpstr;SetSpellStrength(1);}
  else SetSpellStrength(0);

  if ( (2!=sscanf(str,"%s at %s",spname,target)) &&
       (2!=sscanf(str,"%s on %s",spname,target)) &&
       (2!=sscanf(str,"%s %s",spname,target)) ) 
  {spname=str;target=0;}
  SetSpellTarget(target);
  if (0==member(spells,spname))
    return notify_fail("You can't "+QueryCastVerb()+" that.\n",NOTIFY_ILL_ARG),0;
  actualspell=spname;        /* Set this_spell */

/* Hardcoded Check whether magic is allowed - a fail here will not cost any SP */ 
  if (tmpstr=CannotCast(QuerySpellType(spname),TP,0))
    return notify_fail(tmpstr, NOTIFY_NOT_VALID),0;

  /* Cost can be derived from a function or be fixed */
  oldSP=TP->QuerySP();
   if (QueryCastCost(spname) && !TP->ReduceSP(QueryCastCost(spname)))
  {
    return notify_fail("You don't have enough spellpoints to "+QueryCastVerb()+
             " "+add_a(QueryLongName(spname))+" "+spellnoun+".\n",
                        NOTIFY_NOT_VALID),0;
  }
  /* Run through all functions which check whether we CAN cast that spell */
  /* A fail here will cost SP or the function has to do a RestoreSP()     */
  SetCastResult(CAST_CHECK_FAIL);
  failfuns=QueryFailChecks(spname);
  for (i=0;i<sizeof(failfuns);i++)
  {
    res=funcall(failfuns[i],spname);
    if (res)
    { 
      Message(res);
      castsuccess=QuerySuccessFunction(spname);
      if (castsuccess) funcall(castsuccess,CAST_CHECK_FAIL,spname); /* failed */
      oldSP=0;
      GL_SPELLMASTER->RecordSpell(spname,"check_fail");
      return 1;
    }
  }  
  /* write you cast a xxx spell */
  Message(QueryCastActionMessage(spname,QueryLongName(spname)));
  /* Now do the actual cast ! */
  oldmagicobj=TP->QueryCastObj();  /* save old object */
  TP->SetCastObj(TO);
  tmp=funcall(QueryCastFunction(spname),target,spname,0);
  SetCastResult(tmp);
  if (tmp<0)  /* <0: failed */
  {
        RestoreSP();    /* tmp=not casted */
        GL_SPELLMASTER->RecordSpell(spname,"failed");
  }
  else if (tmp==CAST_REPULSE)
        GL_SPELLMASTER->RecordSpell(spname,"repulsed");
  else
        GL_SPELLMASTER->RecordSpell(spname,"success");

  if (tmp==CAST_FAIL_MSG) 
     Message(({"Failed!\n",TP->QueryName()+" failed!\n"}));
  /* Any action after the cast, like remove the scroll */
  castsuccess=QuerySuccessFunction(spname);
  if (castsuccess) funcall(castsuccess,tmp,spname);
  oldSP=0;
  return 1;
}

void init()
{
string *sp;
int i;
 ::init();
  if (castmode==0) add_action("do_cast", castverb); /* use case <spname> */
  else if (castmode==2)        /* use <spname> */
  {
     sp=QueryAllSpells();
     for (i=0;i<sizeof(sp);i++) add_action("ind_cast",sp[i]);
  }
  add_action("do_describe", "describe");
}
void create()
{
  ::create(); 
  seteuid(getuid());
  AddId("caster");
  spells=([]);
  success=([]);
  fails=([]);
  description=([]);
  allowdescribe=0;
  castmode=0;
  castverb="cast";
  spellnoun="spell"; 
  c_success=0;
  "obj/lib/register"->RegisterCreator(TO,"CASTER");
}

/* Debug */
mapping QuerySpellMap() {return spells;}
mapping QuerySucessMap() {return success;}
mapping QueryFailMap() {return fails;}
mapping QueryDescMap() {return description;}

