/*---------------------------------------------------------------------------
** std/living/restrictions
**
** Entering and leaving of objects is handled here.
**
** 14-Jan-1994  [Mateese]
**---------------------------------------------------------------------------
*/

#include <config.h>
#include <properties.h>
#include <moving.h>
#include <attributes.h>
#include <living.h>

inherit "/std/container/restrictions";

// Define this for a log of weight limit violations in /log/WEIGHT
/* #define CHECKWEIGHT 1 */

#define THIS         this_object()
#define ENV          environment

public mixed QueryAttr(string at, int sc);  // std/living/attributes
public string QueryName();                  // std/living/description
public int QueryLState();                   // std/living/description
public string QueryPossessive();            // std/living/description
public int QueryInvis();                    // std/living/description
public void AddHeart(mixed hook);          // std/living/heart
public int QueryStr();                      // std/living/stats
#ifdef NF
public int UseStat(string name, int diff);  // std/living/stats
#endif

//---------------------------------------------------------------------------
public int QueryMaxContent () {
  int maxload, state;

  // Load ranges given for STR 0..20..50
  maxload = 20000 + 400 * STAT_SCALE * QueryStr();  // 20..60..120 kg load
  state = QueryLState();
  if (state == LSTATE_GHOST)
    maxload /= 2500;                  // Ghosts: 8..24..48 g load
  if (state == LSTATE_FROG)
    maxload /= 3;                      // Frogs: 6..20..40 kg load
  return maxload;
}
public int SetMaxContent (int i) { return QueryMaxContent(); }

public int QueryLoad ()
{
  int content, max, limit;
  max = QueryMaxContent();
  limit = LOAD_LIMIT(max) || 1;
  if ((content = QueryWeightContent()) <= limit)
    return (100 * content) / limit;
  return 100+((content-limit)*100)/((max-limit)||1);
}
public int SetLoad (int i) { return QueryLoad(); }

public varargs int QueryWeight (int flag) {
  int weight, state;
#ifdef CHECKWEIGHT
  int maxweight; /* DEBUG */
#endif
  // Get the Bodyweight+Contentweight, irregarding LSTATE, first.
  weight = "restrictions"::QueryWeight(flag);
#ifdef CHECKWEIGHT
  /* DEBUG BEGIN */
  maxweight = weight-"restrictions"::QueryWeightContent()+QueryMaxContent();
  if (weight > maxweight)
  {
    string msg;
    int tmp;
    msg = sprintf("%s %O (state %d) carries %d max %d in QueryWeight()\n"
		 , ctime(), this_object(), state, weight
		 , maxweight);
    msg += sprintf("  MaxContent %d WeightContent %d\n"
		  , QueryMaxContent(), QueryWeightContent());
    tmp = 0;
    while(previous_object(tmp))
    {
      msg += sprintf("  %O\n", previous_object(tmp));
      tmp++;
    }
    log_file("WEIGHT", msg);
  }
  /* DEBUG END */
#endif
  if (flag)
    return weight;
  state = QueryLState();
  if (state == LSTATE_GHOST)  // No own body weight
    return QueryWeightContent();
  if (state == LSTATE_FROG)   // Half the normal bodyweight
    return (QueryWeightContent() + weight)/2;
  return weight;
}

public int SetWeight (int new) {
  int state;
#ifdef CHECKWEIGHT
  int tmp;
  tmp = new;
#endif
  state = QueryLState();
  if (state == LSTATE_GHOST)
    // No own body weight, 'new' ist just load.
    // => Add the normal bodyweight to it.
    new = new + "restrictions"::QueryWeight() - QueryWeightContent();
  if (state == LSTATE_FROG)
    // Half the normal bodyweight, 'new' is load + half the bodyweight.
    // => Add the missing half bodyweight to it.
    new = new + ("restrictions"::QueryWeight() - QueryWeightContent())/2;
  "restrictions"::SetWeight(new);
  if (QueryWeightContent() > QueryMaxContent() >> 1)
    AddHeart(HEART_BODY);
#ifdef CHECKWEIGHT
  /* DEBUG BEGIN */
  if (QueryWeight() > QueryMaxWeight())
  {
    string msg;
    msg = sprintf("%s %O (state %d) carries %d max %d in SetWeight(%d)\n"
		 , ctime(), this_object(), state, QueryWeight()
		 , QueryMaxWeight(), tmp);
    msg += sprintf("  MaxContent %d WeightContent %d\n"
		  , QueryMaxContent(), QueryWeightContent());
    tmp = 0;
    while(previous_object(tmp))
    {
      msg += sprintf("  %O\n", previous_object(tmp));
      tmp++;
    }
    log_file("WEIGHT", msg);
  }
  /* DEBUG END */
#endif
  return QueryWeight();
}

#ifdef CHECKWEIGHT
/* DEBUG BEGIN */
public void AddIntWeight (int w) {
  ::AddIntWeight(w);
  if (QueryWeight() > QueryMaxWeight())
  {
    string msg;
    int tmp;
    msg = sprintf("%s %O (state %d) carries %d max %d in AddIntWeight(%d)\n"
		 , ctime(), this_object(), QueryLState(), QueryWeight()
		 , QueryMaxWeight(), w);
    msg += sprintf("  MaxContent %d WeightContent %d\n"
		  , QueryMaxContent(), QueryWeightContent());
    tmp = 0;
    while(previous_object(tmp))
    {
      msg += sprintf("  %O\n", previous_object(tmp));
      tmp++;
    }
    log_file("WEIGHT", msg);
  }
}
/* DEBUG END */
#endif

public int QueryMaxWeight()
{
  return QueryWeight()-"restrictions"::QueryWeightContent()+QueryMaxContent();
}

public int SetMaxWeight (int i)
{
  return QueryMaxWeight();
}

//---------------------------------------------------------------------------
private int _overload_droppable (object ob)
{
  return    !({int})ob->Query(P_NODROP)
         && (({object})ob->QueryMoneyObject() || !({mixed})ob->Query(P_AUTOOBJECT))
        ;
}

public varargs void DropOverload (int howmuch)
{
  object *inv, *dropped;
  string *dropped_msg;
  int max, ix;

  inv = filter(all_inventory(), #'_overload_droppable /*'*/);

  if (!ENV() || !sizeof(inv)) return;

  if (howmuch < 0) {
    tell_object(THIS, "You lose hold of all your possessions.\n");
    if (!QueryInvis())
      show_room( ENV(THIS)
               , ({ QueryName()+" loses hold of all "+QueryPossessive()
                               +" possessions.\n"
                  , "Things fall to the ground.\n" })
               , ({ THIS }));
    else
      show_room( ENV(THIS)
               , ({ "A heap of things clatter to the ground.\n"
                  , "Things fall to the ground.\n" })
               , ({ THIS }));
    filter_objects(inv, "move", ENV(), M_DROP);
    return;
  }
  inv = filter_objects(all_inventory(), "QueryWeight");
  max = QueryMaxContent() / 2;
  if (howmuch > 0)
    max = (max + 1) / 2;

  dropped = ({});
  while (sizeof(inv) && QueryWeightContent() > max) {
    ix = random(sizeof(inv));
    if (ME_OK == ({int})inv[ix]->move(ENV(), M_DROP))
      dropped += ({ inv[ix] });
    if (sizeof(inv) == 1)
      inv -= ({ inv[0] });
    else
      inv = inv[0..ix-1] + inv[ix+1..];
  }

  if (sizeof(dropped))
  {
    dropped_msg = fold_objlist(dropped);
    tell_object( THIS
               , implode_list(dropped_msg, "", " slip from you hold."));
    if (!QueryInvis())
      show_room( ENV(THIS)
               , ({ capitalize(implode_list(dropped_msg, QueryName()+" loses hold of "))
                  , "Things fall to the ground.\n" })
               , ({ THIS }) + dropped
               );
    else
      show_room( ENV(THIS)
               , ({ capitalize(implode_list(dropped_msg, "", " and", " are here."))
                  , "Things fall to the ground.\n" })
               , ({ THIS }) + dropped
               );
   }
}

//---------------------------------------------------------------------------
public varargs void notify_leave(mixed dest, mixed method, mixed extra)
{
  object pre;
  int load;
  string sh2, who;
  string mLoad, mLoadO;

  pre = previous_object();
  who = QueryName();
  load = ({int})pre->QueryWeight() * 50 / QueryMaxContent();

  "restrictions"::notify_leave(dest,method,extra);

  if (living(pre)) {
    mLoad = mLoadO = "";
    if (member(({ M_DROP, M_PUT, M_GIVE }), method) != -1)
      if (load > LOAD_DTHRESH) {
        mLoad = " and feel relieved";
        mLoadO = " and looks relieved";
      }
      else if (load < -LOAD_DTHRESH) {
        mLoad = ", but feel more burdened now";
        mLoadO = ", but looks more burdened now";
      }

    switch(method) {
    case M_DROP:
      if (extra)
        return;
      tell_object(pre, who+" drops you"+mLoadO+".\n");
      break;
    case M_PUT:
      sh2 = ({string})dest->Short();
      tell_object(pre, who+" puts you into "+sh2+mLoadO+".\n");
      break;
    case M_GIVE:
      sh2 = ({string})dest->QueryName();
      tell_object(pre, who+" gives you to "+sh2+mLoadO+".\n");
      break;
    }
  }

  mLoad = mLoadO = "";
  if (load > LOAD_DTHRESH) {
    mLoad = "You feel relieved.\n";
    mLoadO = who+" looks relieved.\n";
  }
  else if (load < -LOAD_DTHRESH) {
    mLoad = "You feel more burdened.\n";
    mLoadO = who+" looks more burdened.\n";
  }
  if (mLoad != "") {
    tell_object(THIS, mLoad);
    if (living(pre))
      tell_object(pre, mLoadO);
    show_room(ENV(), mLoadO, ({THIS, pre}));
  }
}

//---------------------------------------------------------------------------
public varargs void notify_enter(object source, mixed method, mixed extra)
{
  object what;
  int load;
  string who;
  string mLoad, mLoadO;

  what = previous_object();
  who  = QueryName();
  load = ({int})what->QueryWeight() * 50 / QueryMaxContent();

  "restrictions"::notify_enter(source,method,extra);

#ifdef NF
  if (QueryLoad() > 100)
    UseStat(A_STR, 0);
#endif

  mLoad = mLoadO = "";
  if (living(what) && M_GET == method) {
    if (load > LOAD_DTHRESH) {
      mLoad = " and struggle under the weight";
      mLoadO = " with some difficulties";
    }
    else if (load < -LOAD_DTHRESH) {
      mLoad = ", but feel even lighter now";
      mLoadO = ", but doesn't look that loaded now";
    }
    tell_object(what, who+" takes you"+mLoadO+".\n");
  }

  mLoad = mLoadO = "";
  if (load > LOAD_DTHRESH) {
    mLoad = "You struggle under the weight.\n";
    mLoadO = who+" fights with "+QueryPossessive()+" load.\n";
  }
  else if (load < -LOAD_DTHRESH) {
    mLoad = "You feel much lighter.\n";
    mLoadO = who+" doesn't look as much loaded as before.\n";
  }
  if (mLoad != "") {
    tell_object(THIS, mLoad);
    if (living(what))
      tell_object(what, mLoadO);
    show_room(ENV(), mLoadO, ({THIS,what}));
  }
}

//---------------------------------------------------------------------------
public int prevent_leave(mixed dest, int method, mixed extra)
{
  return (method == M_GET) ? ME_NO_LEAVE : ::prevent_leave(dest, method,extra);
}

//---------------------------------------------------------------------------
public int allow_enter(int method, mixed extra)
{
  return (method == M_PUT) ? ME_NO_ENTER : ::allow_enter(method, extra);
}

/***************************************************************************/
