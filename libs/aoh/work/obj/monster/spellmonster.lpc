/*
** A spellmonster
** Author: Thragor@Nightfall, 21may96
** Update: Mica@OSB, 23may97
*/

#include <spellmonster.h>
#include <combat.h>
#include <magic.h>
#include <living.h>

#define ME this_object()
#define REGISTER "/obj/lib/register"
#define NMB "/lib/number"
#define STR "/lib/string"
#define SF(x) #'x //'

private nosave mapping Pspells,
                       delayed, // ([id:hbs to wait])
                       chances; // ([id:chance]) a list of all chances
private nosave int Pcastchance; // the chance that the monster casts
                               // a spell at all
private nosave object *victims; // Current victims of the spell.

inherit "/std/npc";

/*
** =========================================
** Setting and Querying the actual victim(s)
** =========================================
*/

public object *SetVictims(object *o)
{
  return victims = o;
}

public object *QueryVictims()
{
  return (victims||({}))+({});
}

/*
** ============================
** Functions for process_string
** ============================
*/

protected string build_list(string *strs)
     // Build a list of strings: a, b and c
     // strs mustn't be empty!
{
  return sizeof(strs)==1?strs[<1]:implode(strs[0..<2],", ")+" and "+strs[<1];
}

public varargs string MyName(string cap)
     // Return the name of the spellmonster.
     // If called with @@MyName|1@@ the name will be
     // inserted capitalized.
     // Example: Harry
{
  string res;
  res = QueryName()||QueryShort()||"someone";
  return cap?capitalize(res):res;
}

public varargs string MyPronoun(string cap)
     // Return the pronoun of the spellmonster.
     // If called with @@MyPronoun|1@@ the pronoun will be
     // inserted capitalized.
     // Example: He
{
  return cap?capitalize(QueryPronoun()):QueryPronoun();
}

public varargs string MyPossessive(string cap)
     // Return the possessive pronoun of the spellmonster.
     // If called with @@MyPossessive|1@@ the poss. pron. will be
     // inserted capitalized.
     // Example: His
{
  return cap?capitalize(QueryPossessive()):QueryPossessive();
}

public varargs string MyObjective(string cap)
     // Return the objective pronoun of the spellmonster.
     // If called with @@MyObjective|1@@ the obj. pron. will be
     // inserted capitalized.
     // Example: Him
{
  return cap?capitalize(QueryObjective()):QueryObjective();
}

public varargs string MyGenitive(string cap)
     // Return the genitive name of the spellmonster.
     // If called with @@MyGenitive|1@@ the name will be
     // inserted capitalized.
     // Example: Harry's
{
  return add_gen(MyName(cap));
}

public varargs string VicName(string cap)
     // Return the name(s) of the victim(s) the spellmonster
     // is currently attacking. Before the spell is cast this
     // will return all names of all victims in a list.
     // During the actual spell, only one victim per time
     // is parsed through VicName.
     // If called with @@VicName|1@@ the name(s) will be
     // inserted capitalized.
     // Example 1: Thragor
     // Example 2: Thragor, Cadra and Tnt
{
  string *names;
  object *vics;
  string res;
  
  if (!sizeof(vics = QueryVictims())) names = ({"noone"});
  else
    names = map_objects(vics,"QueryName");
  res = build_list(names);
  return cap?capitalize(res):res;
}

public varargs string VicPronoun(string cap)
     // Return the pronoun of the victim(s), i. e. if there's
     // more than one victim, 'they' is returned.
     // Other rules same as with VicName.
{
  string res;
  object *vics;
  
  if (sizeof(vics = QueryVictims())>1)
    res = "they";
  else
    res = vics[<1]->QueryPronoun();
  return cap?capitalize(res):res;
}

public varargs string VicPossessive(string cap)
     // Return the possessive pronoun of the victim(s), i. e. if there's
     // more than one victim, 'their' is returned.
     // Other rules same as with VicName.
{
  string res;
  object *vics;
  
  if (sizeof(vics = QueryVictims())>1)
    res = "their";
  else
    res = vics[<1]->QueryPossessive();
  return cap?capitalize(res):res;
}

public varargs string VicObjective(string cap)
     // Return the objtive pronoun of the victim(s), i. e. if there's
     // more than one victim, 'their' is returned.
     // Other rules same as with VicName.
{
  string res;
  object *vics;
  
  if (sizeof(vics = QueryVictims())>1)
    res = "their";
  else
    res = vics[<1]->QueryObjective();
  return cap?capitalize(res):res;
}

public varargs string VicGenitive(string cap)
     // Return the name(s) of the victim(s) appended by the
     // genitive ending.
     // Other rules same as with VicName.
{
  string *names;
  object *vics;
  string res;

  if (!sizeof(vics = QueryVictims())) names = ({"noone"});
  else
    names = map_objects(vics,"QueryName");
  names = map(names,SF(add_gen));
  res = build_list(names);
  return cap?capitalize(res):res;
}

public varargs string VicS(string verb,string cap)
     // Get the right ending of a verb depending on the amount of
     // victims. You should give the plural-form of the verb here.
{
  string res;
  switch(verb)
    {
    case "is":
    case "are":
      res = sizeof(QueryVictims())==1?"is":"are";
      break;
    case "was":
    case "were":
      res = sizeof(QueryVictims())==1?"was":"were";
      break;
    default:
      res = sizeof(QueryVictims())==1
	?verb+(member(({'z','x','s'}),verb[<1])!=-1?"es":"s")
	:verb;
    }
  return cap?capitalize(res):res;
}

protected string parse_string(string str)
{
  string res;
  if (str=="") return "";
  res = process_string(str);
  res = "  "+STR->wrap(res,75,2);
  if (res[<1]!='\n') res+="\n";
  return res;
}

/*
** ==========
** The Spells
** ==========
*/

public mapping SetSpells(mapping m)
{
  mixed *idx;
  int i;
  
  if (mappingp(m))
    {
      i = sizeof(idx = m_indices(m));
      chances = ([]);
      while(i--)
	chances[idx[i]] = (m[idx[i]][S_CHANCE] = m[idx[i]][S_CHANCE]||1);
    }
  return Pspells = m;
}

public mapping QuerySpells()
{
  return (Pspells||([]))+([]);
}

protected int get_free_id()
     // Automatically get the first free id (if the id was not specified
     // in the monster.
{
  int *idx;
  idx = filter(m_indices(QuerySpells()),SF(intp));
  if (!sizeof(idx)) return 0;
  return NMB->max(idx)+1;
}

/*
** AddSpell(id,mindam,maxdam) minimal configuration
** AddSpell(([....])) choose own id
** AddSpell(id,([....]))
** If no VICMSG is given, it will be genererated automatically,
** as the victim has to be informed.
*/

public varargs mapping AddSpell(mixed id_or_properties,
				mixed chance_or_properties,
				int mindam,int maxdam)
{
  mapping spells,props;
  mixed id;
  if (mappingp(id_or_properties))
    {
      id = get_free_id();
      props = id_or_properties;
    }
  else if (mappingp(chance_or_properties))
    {
      id = id_or_properties;
      props = chance_or_properties;
    }
  else
    {
      id = id_or_properties;
      props = ([]);
      props[S_MINDAM] = mindam;
      props[S_MAXDAM] = maxdam;
    }
  if (!props[S_VICMSG]&&props[S_MAXDAM])
    props[S_VICMSG] =
      ([
	MSG_NORMAL:({"@@MyName|1@@ casts "+id+" at you.\n",
	           "Someone casts "+id+" at you.\n"}),
	MSG_DEAD:""
       ]);
  spells = QuerySpells();
  spells[id] = props;
  return SetSpells(spells);
}

/*
** ====================================
** Settings for the spell step by step.
** ====================================
*/

public void SetSpellChance(mixed id,int c)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_CHANCE] = c;
  SetSpells(spells);
}

public void SetSpellCombatDelay(mixed id,int i)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_COMBAT_DELAY] = i;
  SetSpells(spells);
}

public void SetSpellSimult(mixed id,status i)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_SIMULT] = i;
  SetSpells(spells);
}

public void SetSpellEnvMsg(mixed id,mapping msg)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_ENVMSG] = msg;
  SetSpells(spells);
}

public void SetSpellVicMsg(mixed id,mapping msg)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_VICMSG] = msg;
  SetSpells(spells);
}

public void SetSpellDelay(mixed id,int i)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_DELAY] = i;
  SetSpells(spells);
}

public void SetSpellVictims(mixed id,int i)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_VICTIMS] = i;
  SetSpells(spells);
}

public void SetSpellDamType(mixed id,int i)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_DAMTYPE] = i;
  SetSpells(spells);
}

public void SetSpellCheck(mixed id,closure f)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_CHECKFUN] = f;
  SetSpells(spells);
}

public void SetSpellFun(mixed id,closure f)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_FUN] = f;
  SetSpells(spells);
}

public void SetSpellDamFun(mixed id,closure f)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_DAMFUN] = f;
  SetSpells(spells);
}

public void SetSpellMinDam(mixed id,int i)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_MINDAM] = i;
  SetSpells(spells);
}

public void SetSpellMaxDam(mixed id,int i)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_MAXDAM] = i;
  SetSpells(spells);
}

public void SetSpellHP(mixed id,int i)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_HP] = i;
  SetSpells(spells);
}

public void SetSpellSP(mixed id,int i)
{
  mapping spells;
  spells = QuerySpells();
  if (!member(spells,id)) spells[id] = ([]);
  spells[id][S_SP] = i;
  SetSpells(spells);
}

/*
** =============================================
** Chance that the monster casts a spell at all.
** =============================================
*/

public int QueryCastChance()
{
  return Pcastchance;
}

public int SetCastChance(int i)
{
  return Pcastchance = i;
}

/*
** ======================
** Casting of the monster
** ======================
*/

protected status check_cast(mixed id)
{
  mapping sp;
  delayed = delayed||([]);
  if (!member(delayed,id))
    {
      sp = QuerySpells();
      if (QuerySP()-sp[id][S_SP]<0) return 0;
      if (QueryHP()-sp[id][S_HP]<(int)QueryWimpy()) return 0;
      if (closurep(sp[id][S_CHECKFUN]))
	return funcall(sp[id][S_CHECKFUN]);
      return 1;
    }
  delayed[id]--;
  if (delayed[id]<1) m_delete(delayed,id);
  return 0;
}

protected mixed get_spell()
     // Return the spell, which will be cast.
{
  mapping sp;
  mixed *idx,res,false;
  int i,sum,select;
  idx = m_indices(chances||([]));
  i = sizeof(idx = filter(idx,SF(check_cast)));
  sp = QuerySpells();
  sum = 0;
  while(i--) sum+=sp[idx[i]][S_CHANCE];
  select = random(sum)+1;
  sum = 0;
  false = get_free_id();
  res = false;
  i = sizeof(idx);
  while(i--&&res==false)
    {
      sum+=sp[idx[i]][S_CHANCE];
      if (sum>=select) res = idx[i];
    }
  return res;
}

protected int get_damage( object victim, mapping sp ) {
  if ( closurep( sp[S_DAMFUN] ) )
    return apply( sp[S_DAMFUN], victim, & sp );

  return sp[S_MINDAM]+random(sp[S_MAXDAM]-sp[S_MINDAM]);
}

protected status valid_victim(object vic)
{
  return vic
    && !vic->QueryGhost()
    && vic->QueryHP()>=0;
}

public varargs object *GetVictims(int nr_victims,
				  status check_repulse,
				  int damtype,
				  mixed id)
{
  object *en,*vic;
  closure repulse;
  
  en = (QueryEnemies()||({}))+({});
  vic = ({});
  if (nr_victims<0)
    {
      en = filter(all_inventory(environment()),SF(living))-({ME});
      nr_victims = sizeof(en);
    }
  en = filter(en,SF(valid_victim));
  while(nr_victims--&&sizeof(en))
    {
      vic+=({en[random(sizeof(en))]});
      en-=vic;
    }
  if (check_repulse)
    {
      repulse = symbol_function("Repulse",CASTER);
      vic-=filter(vic,repulse,damtype,to_string(id));
    }
  return vic;
}

public status CastSpell(mixed id)
{
  mapping sp;
  object *vic,env;
  int i,*dam;
  mixed msg;
  
  if (!env = environment()) return 0;
  sp = QuerySpells()[id];
  if (member(sp,S_FUN))
    sp = apply(sp[S_FUN],sp,&vic);
  if (!sp) return 0;

  SetCombatDelay(sp[S_COMBAT_DELAY], "You are casting a spell.\n");
  delayed = delayed||([]);
  if (sp[S_DELAY]) delayed[id] = sp[S_DELAY];

  ReduceSP(sp[S_SP], -1);
  ReduceHP(sp[S_HP]);

  if (!vic)
    vic = GetVictims(sp[S_VICTIMS],1,sp[S_DAMTYPE],id);

  if (!sizeof(vic))
    {
      HealSP(sp[S_SP]/2);
      HealHP(sp[S_HP]/2);
    }

  SetVictims(vic);
  if (sp[S_MAXDAM]>=sp[S_MINDAM]&&sp[S_MINDAM]>=0)
    dam = map( vic, SF(get_damage), & sp );

  if (member(sp,S_GLOBAL_ENVMSG))
    {
      if (stringp(msg = sp[S_GLOBAL_ENVMSG])) msg = ({msg,msg});
      show_room(env,map(msg,SF(parse_string)));
    }
  i = sizeof(vic);
  while(i--)
    {
      SetVictims(({vic[i]}));
      if (member(sp,S_VICMSG)&&member(sp[S_VICMSG],MSG_NORMAL))
	{
	  if (stringp(msg = sp[S_VICMSG][MSG_NORMAL])) msg = ({msg,msg});
	  show_object(vic[i],map(msg,SF(parse_string)));
	}
      if (member(sp,S_ENVMSG)&&member(sp[S_ENVMSG],MSG_NORMAL))
	{
	  if (stringp(msg = sp[S_ENVMSG][MSG_NORMAL])) msg = ({msg,msg});
	  show_room(env,map(msg,SF(parse_string)),({vic[i]}));
	}
      if (dam && dam[i] >= 0)
	vic[i]->Defend(dam[i],sp[S_DAMTYPE]||DT_FIRE,DEFEND_F_NOMSG);
      if (!vic[i]||vic[i]->QueryHP()<0)
	{
	  if (vic[i]&&member(sp,S_VICMSG)&&member(sp[S_VICMSG],MSG_DEAD))
	    {
	      if (stringp(msg = sp[S_VICMSG][MSG_DEAD])) msg = ({msg,msg});
	      show_object(vic[i],map(msg,SF(parse_string)));
	    }
	  if (member(sp,S_ENVMSG)&&member(sp[S_ENVMSG],MSG_DEAD))
	    {
	      if (stringp(msg = sp[S_ENVMSG][MSG_DEAD])) msg = ({msg,msg});
	      show_object(env,map(msg,SF(parse_string)),({vic[i]}));
	    }
	}
    }
  SetVictims(0);
  return member(sp,S_SIMULT)?!sp[S_SIMULT]:0;
}

public void Attack()
{
  status done;
  mixed spell;
  int check;
  done = 0;
  check = random(100)+1;
  if (   !QueryCombatDelay()
      && Pcastchance>=check
     )
    if ((spell = get_spell())!=get_free_id())
      done = CastSpell(spell);
  if (!done) (::Attack());
}

/*
** ==========
** The Create
** ==========
*/

public void create()
{
  ::create();
  SetCastChance(20);
  REGISTER->Register(ME,"SPELLMONSTER");
  return 0;
}


/*
** AddSpellQuick
**  use this to add a spell quickly without writing lengthy mappings
**  the syntax is similar to the AddSpell function of the old spellmonster
*/

public varargs void AddSpellQuick( string name,
				   string usermsg,
				   string envmsg,
				   int mindam,
				   int maxdam,
				   int damtype,
				   int spcost,
				   int multi ) {

  AddSpell( name, 
	    ([
	      S_CHANCE : 1,
	      S_COMBAT_DELAY : 0,
	      S_SIMULT: 0,
	      S_VICTIMS : 1,
	      S_DELAY : 2,
	      S_DAMTYPE : damtype,
	      S_MINDAM : mindam,
	      S_MAXDAM : maxdam,
	      S_SP : spcost,
	      S_VICTIMS : ( multi ? 30 : 1 ), 
	      S_ENVMSG : ([
			   MSG_NORMAL : "@@VicName|1@@ "+envmsg+"\n",
			   MSG_DEAD : "@@MyName|1@@ laughs at @@VicName@@.\n"
	      ]),
	      S_VICMSG : ([
			   MSG_NORMAL : "You "+usermsg+"\n",
			   MSG_DEAD: "@@MyName|1@@ laughs at you.\n"
	      ])
	      ]) 
	    );
}
