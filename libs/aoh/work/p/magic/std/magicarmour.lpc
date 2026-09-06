/* made by Joern ! */
// rewritten by softbyte jan97
#include <equipment.h>
#include <magic.h>
#include <properties.h>
#include <moving.h>
#include <secure/wizlevels.h>
#define TP this_player()
#define TO this_object()


inherit "/std/armour";

mapping boni;
object *identifiers;
string *special_ids;
mapping resistance;
int min_level;

#define PL this_player()
#define ME this_object()

// ----------- Functions to be called by the user -----------------
// Add a special resistance when wearing this armour
int AddResistance(mixed type,int value) 
{
  if (!type) return 0;
  if (member(resistance,type)) resistance[type]+=value;
  else resistance[type]=value;
  return resistance[type];
}
mixed QueryResistance() { return resistance; }

// Add a Bonus when wearing the armour
AddBonus(mixed type,int value)
{
  if (!type) return 0;
  if (member(boni,type)) boni[type]+=value;
  else boni[type]=value;
  return boni[type];
}
mapping SetBoni(mapping bon) {
    return boni = bon;
}
mapping QueryBoni() { return boni; }

// Item gets an AddId this
string *SetSpecialIds(string *ids) { return special_ids = ids; }
string *QuerySpecialIds() { return special_ids; }

int SetMinLevel(int lev) { return min_level = lev; }
int QueryMinLevel() { return min_level; }



// outdated functions..do not use
string *SetResistance(string *res) { return 0; }
string SetRealShort(string rs) { return 0; }
string QueryRealShort() { return QueryShort(); }

void create() {
  // Needed for QueryShort() which is called from ::create()...
  identifiers = ({});
  ::create();
  Set(P_MAGIC, 1);
  boni = ([]);
  special_ids = ({});
  resistance = ([]);
  min_level = 19;
}


object *Identify(object who)
{
  if (!who) return identifiers;
  if (member(identifiers, who) > -1)
     tell_object(who, "You already identified it!\n");
  else
  {
    identifiers += ({who});
    tell_object(who, "You identify " + QueryShort() + ".\n");
  }
  if (Query(P_MAGIC) || QueryInfo())
  {
   if (QueryInfo())
    tell_object(who,"There is something special about it:\n"+QueryInfo()+"\n");
   if (stringp(Query(P_MAGIC))) tell_object(who,Query(P_MAGIC)+"\n");
  }
  else 
    tell_object(who, "There is nothing special about it.\n");
  return identifiers;
}

mixed ChkWear (object liv, object obj, int is_armour) {
  if (!liv || liv != this_player() || obj != this_object()) 
    return EQ_FORBID;
  if (liv->QueryLevel() < QueryMinLevel())
     return "You are too low level to use this armour properly.\n";
  return EQ_OK;
}

void NotifyWear (object liv, object obj, int is_armour) {
  int ret, i;
  mixed *keys;
  int *values;

  if (!liv || obj != this_object()) return;
  keys = m_indices(QueryBoni());
  values = m_values(QueryBoni());
  for (i=0; i<sizeof(keys); i++)
  {
      liv->ModifyAttr(capitalize(keys[i]), (int) values[i]);
  }
  if (sizeof(special_ids)) 
     for (i=0; i<sizeof(special_ids); i++) AddId(special_ids[i]);

  keys = m_indices(resistance);
  values = m_values(resistance);
  for (i=0; i<sizeof(keys); i++)
  {
      liv->AddResistance(keys[i], values[i]);
  }
}

void NotifyUnwear (object liv, object obj, int is_armour) 
{
int ret, i;
mixed *keys;
int *values;
mapping res;
  /* liv may be != this_player(), e.g. because the wearer was frogged.  */
  if (!liv || obj != this_object()) return;
  keys = m_indices(boni);
  values = m_values(boni);
  for (i=0; i<sizeof(keys); i++) {
      liv->ModifyAttr(capitalize(keys[i]), -1 * values[i]);
  }
  keys = m_indices(resistance);
  values = m_values(resistance);
  for (i=0; i<sizeof(keys); i++) 
      liv->AddResistance(keys[i], -1 * values[i]);
  if (sizeof(special_ids))
    for (i=0; i<sizeof(special_ids); i++) 
       SetIds(QueryIds() - ({special_ids[i]}) );
}
