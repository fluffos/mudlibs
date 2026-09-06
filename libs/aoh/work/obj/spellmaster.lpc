/* ob/spellmaster
*
*  Records the use of spells (number of times casted and failed)
*
*   28-Aug-95 [Softbyte]
*
*/



#define SPELLLIST "/log/magic/spelluse"
#define MAXSAVECNT 10

mapping spellmap;

private nosave int savecnt;

void create()
{
  if (member(object_name(this_object()), '#') != -1) 
  {
    destruct (this_object());
    return;
  }
  seteuid(getuid());
  if (file_size(SPELLLIST+".o")>=0) restore_object(SPELLLIST);
  else spellmap=([]);
  savecnt=0;
}

int SaveData()
{
  savecnt=0;
  save_object(SPELLLIST);
  return(1);
}

/* Records the use of a spell in the SPELLMASTER                     */
/* increases usage count and if reason=="failed" increases failcount */
int RecordSpell(string spellname,string reason)
{
int cnt;
mapping arg;
  if (!reason) return 0;
  reason=lower_case(reason);
  if (!spellmap) spellmap=([]);
  if (member(spellmap,spellname))
  {
    cnt=spellmap[spellname,0];   /* not really needed */
    arg=spellmap[spellname,1];
    if (member(arg,reason)) arg[reason]++;
    else arg+=([reason:1]);
    spellmap[spellname,0]=cnt+1;
    spellmap[spellname,1]=arg;
  }
  else
  {
    spellmap+=([spellname:1;([reason:1]) ]);
  }
  savecnt++;
  if (savecnt>MAXSAVECNT) SaveData();
  return 1;
}

/* Returns properties of the spell "Spellname" as array with contents */
/* ({string spellname, int no of calls, mapping properties})          */
mixed *QuerySpell(string spellname)
{
  if (!spellname) return 0;
  if (!spellmap) spellmap=([]);
  if (member(spellmap,spellname))
  {
    return( ({spellname,spellmap[spellname,0],spellmap[spellname,1]}) );
  }
  else
  {
    return 0;
  }
}
/* Return number of times (or 0) that spellproperty prop had been used */
int QuerySpellProp(string spellname,string prop)
{
mixed *arg;
mapping props;
  if (!spellmap) spellmap=([]);
  arg=QuerySpell(spellname);
  if (!arg) return 0;
  props=arg[2];
  return props[prop];
}

/* Rerturns array of all recorded Spells */
string *QuerySpellNames()
{
  if (!spellmap) spellmap=([]);
  return(m_indices(spellmap));
}
int ResetSpells()
{
  spellmap=([]);
  SaveData();
  write("Resetting spell counters.\n");
  return 1;
}
int RemoveSpell(string spellname)
{
  if (!spellmap) spellmap=([]);
  if (!spellname) return 0;  
  m_delete(spellmap,spellname);
  return 1;
}

string Spell2String(string spellname)
{
mixed *arg;
mapping props;
string *ind;
string s;
int i;
  if (!spellmap) spellmap=([]);
  if (!spellname) return "";  
  arg=QuerySpell(spellname);
  if (!arg) return "";
  props=arg[2];
  ind=m_indices(props);
  ind=sort_array(ind||({}),#'>);
  s=spellname+": ";
  for (i=0;i<sizeof(ind);i++)
  {
    s+=ind[i]+"="+props[ind[i]];
    if (i<sizeof(ind)-1) s+=", ";
  }
  s+="\n"; 
  return s;
}
int WriteSpells()
{
string *sps;
string s;
int i;
  if (!spellmap) spellmap=([]);
  sps=QuerySpellNames();
sps=sort_array(sps||({}),#'>);
  write(sizeof(sps)+" spells known:\n");
  for (i=0;i<sizeof(sps);i++)
  {
    s="/lib/string"->wrap(Spell2String(sps[i]),75,6);
    write(s);
  }
  write("Done.\n");
  return 1;
}



