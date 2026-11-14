#include <properties.h>
#include <equipment.h>

inherit "/std/armour";

mapping boni;
string real_short;
object *identifiers;
string *special_ids, *resistance;
int min_level;

#define PL this_player()
#define ME this_object()

void create() {
  // Needed for QueryShort() which is called from ::create()...
  real_short = "";
  identifiers = ({});
  ::create();
  Set(P_MAGIC, 1);
  boni = ([]);
  special_ids = ({});
  resistance = ({});
  min_level = 19;
  "/obj/lib/register"->RegisterCreator(this_object(),"Magic_Remove");
}

string *SetResistance(string *res) { return resistance = res; }

string *QueryResistance() { return resistance; }

string SetRealShort(string rs) { return real_short = rs; }

string QueryRealShort() { return real_short; }

mapping SetBoni(mapping bon) {
    return boni = bon;
}

string *SetSpecialIds(string *ids) { return special_ids = ids; }

int SetMinLevel(int lev) { return min_level = lev; }

string *QuerySpecialIds() { return special_ids; }

mapping QueryBoni() { return boni; }

string QueryShort() {
   if (!this_player()) return ::QueryShort();
   if (member(identifiers, this_player()) > -1) return real_short;
   return ::QueryShort();
}

object *Identify(object who) {
  if (!who) return identifiers;
  if (member(identifiers, who) > -1) {
     tell_object(who, "You already identified it!\n");
     return identifiers;
  }
  identifiers += ({who});
  tell_object(who, "You have identified " + real_short + ".\n");
  if (QueryInfo()) tell_object(who, "There's something special about it: " +
     QueryInfo() + "\n");
  return identifiers;
}

mixed ChkWear (object liv, object obj, int is_armour) {
  if (!liv || liv != this_player() || obj != this_object()) 
    return EQ_FORBID;
  if (liv->QueryLevel() < min_level)
     return "You feel that the magic of this armour has no effect on you.\n";
  return EQ_OK;
}

void NotifyWear (object liv, object obj, int is_armour) {
  int ret, i;
  string *keys;
  int *values;
  mapping res;

  if (!liv || obj != this_object())
    return;
   keys = m_indices(boni);
   values = m_values(boni);
   for (i=0; i<sizeof(keys); i++) {
       liv->ModifyAttr(capitalize(keys[i]), (int) values[i]);
   }
   if (sizeof(special_ids)) 
      for (i=0; i<sizeof(special_ids); i++) AddId(special_ids[i]);
  if (liv && sizeof(resistance))
    {
      if (!liv->Query("Resistance")) liv->Set("Resistance",([]));
      res = liv->Query("Resistance");
      for (i=0; i<sizeof(resistance); i++)
        res[resistance[i]] = res[resistance[i]]+100;
      liv->Set("Resistance",res);
    }
}

void NotifyUnwear (object liv, object obj, int is_armour) {
  int ret, i;
  string *keys;
  int *values;
  mapping res;
  
  /* liv may be != this_player(), e.g. because the wearer was frogged.
   */
  if (!liv || obj != this_object())
    return;
  keys = m_indices(boni);
  values = m_values(boni);
  for (i=0; i<sizeof(keys); i++) {
      liv->ModifyAttr(capitalize(keys[i]), -1 * values[i]);
  }
  if (sizeof(special_ids))
    for (i=0; i<sizeof(special_ids); i++) 
       SetIds(QueryIds() - ({special_ids[i]}) );
  if (liv && sizeof(resistance))
    {
      if (!liv->Query("Resistance")) liv->Set("Resistance",([]));
      res = liv->Query("Resistance");
      for (i=0; i<sizeof(resistance); i++)
	{
	  res[resistance[i]] = res[resistance[i]]-100;
	  if (res[resistance[i]]<=0) m_delete(res,resistance[i]);
	}
      liv->Set("Resistance",res);
    }
}
