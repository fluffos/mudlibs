/*---------------------------------------------------------------------------
** std/npc/skills.c
**
** Simple handling of skills in an NPC.
** This is mostly a clearable cache of the effective values.
**---------------------------------------------------------------------------
*/


inherit "/std/living/stats";

#define THIS this_object()

public varargs mixed QueryAttr(string name, int sc);  // std/living/attributes
public varargs mixed SetAttr(string name, mixed arg, int sc);

//---------------------------------------------------------------------------

private static mapping skillcache;

//---------------------------------------------------------------------------

public void RecomputeStats() { skillcache = 0; }

//---------------------------------------------------------------------------
public int SetSkill(string name, int value)

// Set attribute 'name' to the value a pc would have for that skill.

{
  int rc, val;
  rc = SetAttr(name, value);
  val = SKILLMASTER->ComputeSkill(name);
  if (!skillcache)
    skillcache = ([ name: val ]);
  else
    skillcache[name] = val;
  return rc;
}

//---------------------------------------------------------------------------
public int EffectiveSkill (string name) 

// Return the effective value for skill 'name'.

{
  if (!skillcache || !skillcache[name])
    SetSkill(name, 0);
  return skillcache[name];
}

//---------------------------------------------------------------------------

public int ApplySkill(string name, int diff) { 
  return ApplyValue(EffectiveSkill(name), diff);
}

public int UseSkill(string name, int diff) { 
  return ApplySkill(name, diff);
}

//---------------------------------------------------------------------------

public void reset() {
  RecomputeStats();
}

/***************************************************************************/
