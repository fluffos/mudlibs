/*---------------------------------------------------------------------------
** std/living/attributes
**
** Here are all basic attribute-modifying functions defined.
**
**              [Hyp]
** 14-Jun-1993  [Mateese]
**---------------------------------------------------------------------------
*/

#include "/neu/secure/wizlevels.h"
#include "/neu/sys/properties.h"
#include "/neu/sys/attributes.h"

#define THIS this_object()

/*===========================================================================
 * The mapping with all attributes and the variables for some of the
 * hardcoded attributes.
 */
private mapping p_attrs;

/*===========================================================================
 * The querying and setting functions for the attributes.
 * NOTE: when an softcoded attribute is set, several checks are made to keep
 *       memory usage of the attribute mapping low. This means attributes set
 *       to zero will automatically be removed and if the mapping is empty,
 *       the mapping will be set to zero.
 *       If you KNOW that you are dealing with a softcoded attribute call
 *       the functions with additional last argument = SOFTCODED.
 */
public varargs mixed QueryAttr(string aname, int sc) {
  mixed ret;

  return (!sc && call_resolved(&ret, THIS, "Query" + aname)) ?
    ret : (p_attrs ? p_attrs[aname] : 0);
}

public varargs mixed SetAttr(string aname, mixed arg, int sc) {
  mixed ret;

  if(!sc && call_resolved(&ret, THIS, "Set" + aname, arg)) return ret;
  if(p_attrs) {
    if(arg) return p_attrs[aname] = arg;
    if(sizeof(p_attrs = m_delete(p_attrs, aname)) == 0) p_attrs = 0;
  } else if(arg) {
    p_attrs = ([ aname : arg ]);
    return arg;
  }
}

/*===========================================================================
 * The querying and setting functions for all default (soft- and hardcoded)
 * attributes.
 * NOTE: we do not know, if the actual object has turned some softcoded
 *       attributes into hardcoded attributes. So we HAVE to use
 *       the Query- and SetAttr() function to get/set the correct
 *       values. So these functions have a VERY high evaluation cost.
 */

public mapping QueryAttrs() {
  mapping map;
  mixed ret;
  int s;
  string aname, *ind;

  map = p_attrs || ([]);
  ind = LIVING_ATTRS;
  for(s = sizeof(ind); s--;)
  {
    // "Cryptic" you think? Yes, but we must be sure to get the
    // true values.
    aname = ind[s];
    map[aname] = call_resolved(&ret, THIS, "Query" + aname, 1)
                 ? ret : (p_attrs ? p_attrs[aname] : 0);
  }
  return map;
}

// Copy the given attrs mapping into the hardcoded attrs or p_attrs.

public mapping SetAttrs(mapping attrs) {
  mixed *ind, *val;
  int s;

  p_attrs = 0;
  ind = m_indices(attrs);
  val = m_values(attrs);
  for(s = sizeof(attrs); s--; val[s] = SetAttr(ind[s], val[s]));
  return mkmapping(ind, val);
}

/*===========================================================================
 * Increasing/decreasing attributes in a natural, non-linear way.
 *
 * This is done by a special formula:
 *
 * y0 : start value for the iteration
 * y  : resulting attribute value
 * app: the value to which the attribute will iterate
 *      app = maximum of attr => we learn / app = minimum of attr => we forget
 * dcc: the decceleration of the iteration (must be >0)
 *      high value => slow / low value => fast
 *
 * y = y0
 * y = y + (app - y + dcc + 1) / dcc
 *
 * This iteration with respect to integer arithmetic can be described by:
 *
 * y = (app + dcc / 2) * (1 - exp(-x / dcc - log(1 - y0 / (app + dcc / 2))))
 *
 * but only untill y reaches app because the iteration will stay constant
 * at this point, the function not.
 */
public varargs int LearnAttr(string aname, int app, int dcc, int sc) {
  int i;

  i = QueryAttr(aname, sc);
  i += (app - i + dcc + 1) / dcc;
  return SetAttr(aname, i, sc);
}

/* A help function which can be used to calculate the approximative value
 * of an attribute. Therefore we have to call this function with the amount
 * of iteration steps we want to extrapolate, the current value, the min or max
 * value and the decceleration value.
 */
public int ApproxValue(int x, int y0, int app, int dcc) {
  float fx, fapp, fdcc, fy0, t;

  if(y0 == app) return x;
  fx   = to_float(x);
  fapp = to_float(app);
  fdcc = to_float(dcc);
  t    = fapp + fdcc / 2.0;
  t    = t - t * exp(fx / dcc - log(1.0 - y0 / t));
  if(y0 < app) return t < fapp ? to_int(t) : app;
  else         return t > fapp ? to_int(t) : app;
}

/*==========================================================================*/
