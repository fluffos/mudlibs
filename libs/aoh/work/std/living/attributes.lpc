/*---------------------------------------------------------------------------
** std/living/attributes
**
** Here are all basic attribute-modifying functions defined.
**
**              [Hyp]
** 14-Jun-1993  [Mateese]
** 15-Mar-1998  [Mateese] Extended Boni-System to non-numeric attributes
**---------------------------------------------------------------------------
*/

#include <secure/wizlevels.h>
#include <properties.h>
#include <attributes.h>

#define THIS this_object()

/*===========================================================================
 * The mapping with all attributes and the variables for some of the
 * hardcoded attributes.
 */
private mapping pAttrs;
private mapping pAttrBoni;

/*===========================================================================*/
// Internal purposes

public mapping QueryBoni()        { return pAttrBoni||([]); }
public mapping SetBoni(mapping m) { return pAttrBoni = copy(m||([])); }

public mixed QueryBonus(string aname) { return pAttrBoni && pAttrBoni[aname]; }
public mixed SetBonus(string aname, mixed val)
{
  if (!aname)
    raise_error("SetBonus(): 0 passed as attribute name.\n");
  if (!pAttrBoni)
    pAttrBoni = ([]);
  if (!val)
  {
    pAttrBoni -= ([ aname ]);
    return 0;
  }
  return pAttrBoni[aname] = val;
}

public mixed AddBonus(string aname, int delta)
{
  if (!aname)
    raise_error("AddBonus(): 0 passed as attribute name.\n");
  if (delta && intp(delta))
    return SetBonus(aname, QueryBonus(aname)+delta);
  return SetBonus(aname, delta);
}

/*===========================================================================
 * The querying and setting functions for the attributes.
 * NOTE: when a softcoded attribute is set, several checks are made to keep
 *       memory usage of the attribute mapping low.
 *       If you KNOW that you are dealing with a softcoded attribute call
 *       the functions with additional last argument = SOFTCODED.
 */

public varargs mixed QueryAttr(string aname, int sc)
{
  mixed ret;

  if (!aname)
    raise_error("QueryAttr(): 0 passed as attribute name.\n");
  if (!sc && call_resolved(&ret, THIS, "Query" + aname))
    return ret;
  if (!pAttrs)
    return 0;
  return pAttrs[aname];
}

public varargs mixed SetAttr(string aname, mixed arg, int sc)
{
  mixed ret;

  if (!aname)
    raise_error("SetAttr(): 0 passed as attribute name.\n");
  if (!sc && call_resolved(&ret, THIS, "Set" + aname, arg))
    return ret;
  if (!pAttrs)
    pAttrs = ([]);
  if (arg)
    return pAttrs[aname] = arg;
  pAttrs -= ([ aname ]);
  return 0;
}

private varargs int _mod_attr(string aname, int sc, int bonus, mixed delta,
			      int min, int max)
{
  mixed val;

  val = QueryAttr(aname, sc);
  if (intp(val) && intp(delta) && intp(QueryBonus(aname)))
  {
    val += delta;
    if (min < max)
    {
      if ((val > max) && (delta > 0))
      {
        delta -= (val-max);
        val = max;
      }
      else if ((val < min) && (delta < 0))
      {
        delta += (min-val);
        val = min;
      }
    }
    if (bonus && delta)
      AddBonus(aname, delta);
  }
  else
  {
    if (delta)
    {
      mixed tmp;

      tmp = delta;
      delta = QueryBonus(aname) || val;
      val = tmp;
    }
    else
      val = QueryBonus(aname);

    if (bonus)
      AddBonus(aname, delta);
  }
  return SetAttr(aname, val, sc);
}

public void RemoveAttr(string aname)
{
  mixed tmp;

  if (tmp = QueryBonus(aname))
    _mod_attr(aname, 0, 1, (intp(tmp) ? -tmp : 0));
  if (pAttrs)
    pAttrs -= ([ aname ]);
}

public varargs mixed ChangeAttr(string aname, mixed delta, int min, int max)
{
  return _mod_attr(aname, 0, 0, delta, min, max);
}

public varargs mixed ModifyAttr(string aname, mixed delta, int min, int max)
{
  return _mod_attr(aname, 0, 1, delta, min, max);
}

/*===========================================================================
 * The querying and setting functions for all default (soft- and hardcoded)
 * attributes.
 * NOTE: we do not know, if the actual object has turned some softcoded
 *       attributes into hardcoded attributes. So we HAVE to use
 *       the Query- and SetAttr() function to get/set the correct
 *       values. So these functions have a VERY high evaluation cost.
 */

public varargs mapping QueryAttrs(int sc)
{
  mapping map;
  mixed ret;
  int s;
  string *ind;

  map = pAttrs || ([]);
  if (!sc)
  {
    ind = LIVING_ATTRS;
    for (s = sizeof(ind); s--; )
      map[ind[s]] = call_resolved(&ret, THIS, "Query" + ind[s], 1)
		    ? ret : pAttrs[ind[s]];
  }
  return map;
}

// Copy the given attrs mapping into the hardcoded attrs or pAttrs.

public varargs mapping SetAttrs(mapping attrs, int sc)
{
  int s;
  string *ind;

  if (sc)
  {
    pAttrs = copy(attrs || ([ ]));
    return attrs;
  }
  pAttrs = ([ ]);
  ind = m_indices(attrs||([]));
  for (s = sizeof(ind); s--; )
    attrs[ind[s]] = SetAttr(ind[s],attrs[ind[s]]);
  return attrs;
}

// Undo any remembered modification.

public void RestoreAttrs()
{
  string *ind;
  int i, asize;
  mixed tmp, ret;
  string aname;

  if (!pAttrBoni)
    pAttrBoni = ([ ]);
  ind = m_indices(pAttrBoni);
  for (i = sizeof(ind); i--; )
  {
    tmp = pAttrBoni[ind[i]];
    _mod_attr(ind[i], 0, 1, (intp(tmp)&&intp(QueryAttr(ind[i])) ? -tmp : 0));
  }
  // Fix to remove non-soft attributes from pAttrs
  if (!pAttrs)
    pAttrs = ([ ]);
  ind = LIVING_ATTRS;
  asize = sizeof(pAttrs);
  for (i = sizeof(ind); i--;)
  {
    aname = ind[i];
    if (call_resolved(&ret, THIS, "Query" + aname, 1))
    {
      if (sizeof(pAttrs = m_delete(pAttrs, aname)) < asize)
      {
        log_file("ATTRFIX", "removed "+object_name(THIS)+":"+aname+"\n");
        if ((asize = sizeof(pAttrs)) == 0)
          break;
      }
    }
  }
}

/*===========================================================================
* Shortcuts to handle just the softcoded attributes.
*/

public mixed QueryAttribute(mixed attr)
{
  return QueryAttr(attr, 1);
}

public mixed SetAttribute(mixed attr, mixed val)
{
  return SetAttr(attr, val, 1);
}

public void RemoveAttribute(string aname)
{
  RemoveAttr(aname);
}

public varargs int ChangeAttribute(string aname, int delta, int min, int max)
{
  return _mod_attr(aname, 1, 0, delta, min, max);
}

public varargs int ModifyAttribute(string aname, int delta, int min, int max)
{
  return _mod_attr(aname, 1, 1, delta, min, max);
}

public mapping QueryAttributes() { return QueryAttrs(1); }

public mapping SetAttributes(mixed a)
{
  if (pointerp(a))
    return SetAttrs(mkmapping(a[0], a[1]), 1);
  return SetAttrs(a, 1);
}

/*===========================================================================*/

public varargs mixed QueryBaseAttr(string aname, int sc)
{
  mixed val, bonus;

  val = QueryAttr(aname, sc);
  bonus = QueryBonus(aname);

  if (!bonus)
    return val;
  if (intp(bonus))
    return val - bonus;
  return bonus;
}

public varargs mixed QueryBaseAttribute(string aname)
{
  return QueryBaseAttr(aname, 1);
}

/*===========================================================================*/


public mapping QueryStats()
{
  mapping rc;
  string *statlist;
  int i;

  statlist = STATS;
  rc = ([]);
  for (i = 0; i < sizeof(statlist); i++)
    rc[statlist[i]] = QueryAttr(statlist[i]);
  return rc;
}

public mapping SetStats(mixed stats)
{
  string *statlist;
  int i, val;

  statlist = STATS;
  if (pointerp(stats))
  {
    for (i = 0; i < sizeof(stats[0]); i++)
      SetAttr(stats[0][i], stats[1][i]);
  }
  else if (mappingp(stats))
  {
    for (i = 0; i < sizeof(statlist); i++)
      if (m_contains(&val, stats, statlist[i]))
        SetAttr(statlist[i], val);
  }
  return QueryStats();
}

/* ----------------------------------------------------------------------
** CheckStat()  [Softbyte]  V1.0 22april1999
**              used [Thragor]s CheckSkill() as basis
**
** Works for all Attributes, build in and not, ie. Dex, Con ,... +Wis,
** Sta,...
** attr (Con, Int, ...): Name of the stat to be checked
** chance 0..1000: The higher teh chance is the easier is the statcheck
** percent will be returned as the percentage of fail/success (0..100)
**         you need not evaluate it if you just need a CheckStat() result
**         of 0:failed or 1:succeeded
** Example: TP->CheckStat(A_DEX,500,&percent);
** ----------------------------------------------------------------------
*/
public int CheckStat(string attr,int chance,int percent)
{
  int dice;
  int value;

  percent=0;
  value=QueryAttr(attr);       // QueryAttr() needs to be in the same module
  if (!intp(value)) return 0;
  // Map a stat of 30 to 100 ... change that if you like
  value=value*333/100;

  if (chance<1) return 0;
  if (value>100) value = 100;
  if (value<0) value = 0;
  if (chance>1000) chance = 1000;

  value = value*chance;
  // Calculate the chance for the player to be successful.

  dice = random(100001);  // Throw the dice (0..100000).
  // If the dice throws a higher number than the chance, the player
  // failed. Now calculate how much (s)he failed.
  if (value-dice<0)
  {
      percent = (dice-value)*100/(100000-value);
      return 0;
  }
  // The player was successful. Now check how successful (s)he was.
  if (value>0) percent = (value-dice)*100/value;
  else percent = 0;
  return 1;
}
