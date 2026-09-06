/*---------------------------------------------------------------------------
** std/thing/combat.c
**
** The basic combat of a thing (which is not much more than getting
** destructed :-).
**
** TODO: Differentiate between several types of damage.
**
**  21-Dec-1993  [Mateese]
**---------------------------------------------------------------------------
*/

#include <thing.h>

#include "/std/object.d"

#define ENV   environment
#define THIS  this_object()
#define PREV  previous_object()
#define TP    this_player()


//---------------------------------------------------------------------------
public int id (string str)

// Identify this object.
//
// Argument:
//   str : the string to be checked for identification.
//
// Result:
//   True if the string identifies this object.
//
// Check the given string against the set ids if it matches
// If we have some adjectives, they first cut all out of the given string.
// The prop P_LastID is set to the given string if it matches, else set
// to 0.
// If the thing has no ids set, the special id 'object' is recognized
// for wizards.

{
  string *ids, *ads;
  ids = Query(P_IDs);
  if (str) str = lower_case(str);
  else {
    Set(P_LastID, 0);
    Set(P_LastVerb, 0);
    Set(P_LastPlayer, 0);
    return 0;
  }
  if (!ids && str == "object" && isWizard(TP)) {
    Set(P_LastID, str);
    Set(P_LastVerb, query_verb());
    Set(P_LastPlayer, TP);
    return 1;
  }
  ads = Query(P_Adjs);
  if (member(ids, ads ? implode(explode(str, " ") - ads, " ") : str) >= 0) {
    Set(P_LastID, str);
    Set(P_LastVerb, query_verb());
    Set(P_LastPlayer, TP);
    return 1;
  }
  Set(P_LastID, 0);
  Set(P_LastVerb, 0);
  Set(P_LastPlayer, 0);
  return 0;
}

//---------------------------------------------------------------------------
public string *SetIDs (string name, string *ids)

// Set the P_IDs property.

{
  if (sizeof(ids))
    ids = map(ids, #'lower_case);
  else ids = 0;
  return funcall(oldSetIDs, P_IDs, ids);
}

//---------------------------------------------------------------------------
public string *SetAdjs (string name, string *ads)

// Set the P_Adjs property.

{
  if (sizeof(ads))
    ads = map(ads, #'lower_case);
  else ads = 0;
  return funcall(oldSetAdjs, P_Adjs, ads);
}

//---------------------------------------------------------------------------
protected void AddLight (int l)

// Change the light emission of the thing by the given amount.

{
  if (l)
  {
    if (ENV())
      ENV()->Apply(M_MoreIntLight, l);
    funcall(oldSetLight, P_Light, Query(P_Light)+l);
  }
}

//---------------------------------------------------------------------------
public int SetLight (string name, int l)

// Set the light emission of the thing.
// This also changes the thing's brightness.

{
  Apply(M_AddLight, l-Query(P_Light));
  Set(P_Bright, Query(P_Bright)+l);
  return Query(P_Light);
}

//---------------------------------------------------------------------------
public int SetBright (string name, int l)

// Set the things inherent brightness.

{
  Apply(M_AddLight, l-Query(P_Bright));
  return funcall(oldSetBright, P_Bright, l);
}

//---------------------------------------------------------------------------
public int SetWeight (string name, int w)

// Set the things weight.

{
  if (ENV() && !(int)(ENV()->Apply(M_AddIntWeight, w - Query(P_Weight)))
    return 0;
  return funcall(oldSetWeight, P_Weight, w);
}

//---------------------------------------------------------------------------
public string *AddID (string str)

// Add another id string.
//
// Argument:
//   str : the new id to add.
//
// Result:
//   An array of all ids already set.

{ string *ids;

  ids = Query(P_IDs);
  if (!ids) ids = ({ str });
  else if (member(ids, str) < 0)
    ids += ({ str});
  return Set(P_IDs, ids);
}

//---------------------------------------------------------------------------
public string *AddAdj (string str)

// Add another adjective string.
//
// Argument:
//   str : the new adjective to add.
//
// Result:
//   An array of all adjectives already set.

{ string *ads;

  ads = Query(P_Adjs);
  if (!ads) ads = ({ str });
  else if (member(ads, str) < 0)
    ads += ({ str});
  return Set(P_Adjs, ads);
}

//---------------------------------------------------------------------------
public varargs string Long ()

// Return the actual long description.

{
  return Query(P_Long);
}

//---------------------------------------------------------------------------
public varargs string Short ()

// Return the actual short description.

{
  return Query(P_Short);
}

//---------------------------------------------------------------------------
public varargs string CapShort ()

// Return the capitalized actual short description.
// If the object is invisible (P_Short == 0), the empty string "" is returned.

{
  return capitalize(Query(P_Short) || "");
}

//---------------------------------------------------------------------------
public varargs string DamageStr ()

// Return a string describing the damage to the object.
// It is not a complete sentence, just a few words.

{
  switch (Query(P_Damage) * 100 / Query(P_DamageCap))
  {
  case  0..  5: return "undamaged";
  case  6.. 25: return "slightly damaged";
  case 26.. 50: return "damaged";
  case 51.. 75: return "heavily damaged";
  case 76.. 95: return "severely battered";
  case 96..100: return "nearly destroyed";
  }
}

//---------------------------------------------------------------------------
public varargs string Noise ()

// Return the actual noise description.

{
  return Query(P_Noise);
}

//---------------------------------------------------------------------------
public varargs string Smell ()

// Return the actual short description.

{
  return Query(P_Smell);
}

//---------------------------------------------------------------------------
public mixed QueryAutoObject (string name)

// Return the data needed for autoloading.

{
  return getProps();
}

//---------------------------------------------------------------------------
public mixed SetAutoObject (string name, mixed p)

// Reset the data needed saved over autoloading.

{
  if (mappingp(p)) putProps(p);
  return Query(P_AutoObject);
}

//---------------------------------------------------------------------------
public void create ()

// Setup the moving stuff

{
  oldSetIDs    = query(P_IDs, F_SET);    set(P_IDs, #'SetIDs, F_SET);
  oldSetAdjs   = query(P_Adjs, F_SET);   set(P_Adjs, #'SetAdjs, F_SET);
  oldSetLight  = query(P_Light, F_SET);  set(P_Light, #'SetLight, F_SET);
  oldSetBright = query(P_Bright, F_SET); set(P_Bright, #'SetBright, F_SET);
  oldSetWeight = query(P_Weight, F_SET); set(P_Weight, #'SetWeight, F_SET);
  set(P_AutoObject, #'SetAutoObject, F_SET);
  set(P_AutoObject, #'QueryAutoObject, F_QUERY);
  set(P_AutoObject, PM_NOSAVE, F_MODE);
  set(M_AddLight, #'AddLight);
  set(M_Long, #'Long);
  set(M_Short, #'Short);
  set(M_CapShort, #'CapShort);
  set(M_Smell, #'Smell);
  set(M_Noise, #'Noise);
  set(M_DamageStr, #'DamageStr);
}

/***************************************************************************/
