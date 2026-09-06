/*
** /std/unit.c
** Extension for the description of a thing to be a unit.
**
** ??????? [?] Creation
** 24jun95 [t] Debugged
** 16aug95 [t] JoinWith/SplitOff debugged
**
** [t] Thragor
*/

#include <moving.h>
#include <classes.h>
#include <properties.h>

#define TP this_player()
#define ME this_object()
#define SF(x) #'x //'

inherit "/std/thing";

//--- global variables ------------------------------------------------------

private nosave string *Ppids;
private nosave int Pamount, Pvaluepu, Pbrightpu, Pweightpu, Pplurallg;
private nosave string Ppluralpattern;
private nosave mixed Ppluralsh;
private nosave int Plastamount;
private nosave int lasttime;
private nosave object lastpl;

public void create()
{
  (::create());
  lasttime = time()-2;
  seteuid(getuid());
  AddClassAdj(CA_SPLITABLE);
}

//--- query and set functions for the properties ----------------------------

public int QueryBrightPerUnit(); // forward
public int QueryValuePerUnit();  // forward
public int QueryWeightPerUnit(); // forward

public int QueryAmount() { return Pamount; }
public int SetAmount(int a)
{
  int expected;
  expected = a * QueryWeightPerUnit();
  if (expected == (::SetWeight(expected)))
    {
      (::SetValue(a * QueryValuePerUnit()));
      (::SetBright(a * QueryBrightPerUnit()));
      return Pamount = a;
    }
}

public int QueryValuePerUnit() { return Pvaluepu; }
public int SetValuePerUnit(int v)
{
  (::SetValue(QueryAmount() * v));
  return Pvaluepu = v;
}

public int QueryBrightPerUnit() { return Pbrightpu; }
public int SetBrightPerUnit(int v)
{
  (::SetBright(QueryAmount() * v));
  return Pbrightpu = v;
}

public int QueryWeightPerUnit()    { return Pweightpu; }
public int SetWeightPerUnit(int w)
{
  int expected;
  expected = QueryAmount() * w;
  if (expected == (::SetWeight(expected)))
    {
      Pweightpu = w;
      return 1;
    }
}

public varargs mixed QueryPluralShort(string what) { return Ppluralsh; }
public mixed SetPluralShort(mixed s) { return Ppluralsh = s; }

public varargs mixed QueryPluralLong(string what) { return Pplurallg; }
public mixed SetPluralLong(mixed l) { return Pplurallg = l; }

public int QueryLastAmount()    { return Plastamount; }
public int SetLastAmount(int i) { return Plastamount = i; }

//--- light and weight redefinition of a unit object ------------------------

public int SetLight(int l)
{
  SetBrightPerUnit((l - QueryLight()) / (QueryAmount() || 1));
  return QueryLight();
}

public int QueryLight()
{
  int amount;
  if (!QueryLastId())
    SetLastAmount(QueryAmount());
  return QueryBrightPerUnit()*QueryLastAmount();
}

public int SetBright(int l)
{
  SetBrightPerUnit(l / (QueryAmount() || 1));
  return QueryBright();
}

public int QueryBright()
{
  int amount;
  if (!QueryLastId())
    SetLastAmount(QueryAmount());
  return QueryBrightPerUnit()*QueryLastAmount();
}

public int SetWeight(int w)
{
  int amount;
  amount = QueryAmount() || 1;
  return amount * SetWeightPerUnit(w / amount);
}

public varargs int QueryWeight()
{
  int amount;
  if (!QueryLastId())
    SetLastAmount(QueryAmount());
  return QueryWeightPerUnit()*QueryLastAmount();
}

public int SetValue(int v)
{
  int amount;
  amount = QueryAmount() || 1;
  return amount * SetValuePerUnit(v / amount);
}

public varargs int QueryValue()
{
  int amount;
  if (!QueryLastId())
    SetLastAmount(QueryAmount());
  return QueryValuePerUnit()*QueryLastAmount();
}

//--- testing if we are equal to a specific unit ----------------------------

public int IsEqualUnit(int vpu, int bpu, int wpu, string psh, string sh,
                       string plg,string lg)
{
  return (   vpu == QueryValuePerUnit()
          && bpu == QueryBrightPerUnit()
          && wpu == QueryWeightPerUnit()
          && psh == QueryPluralShort()
          && sh == QueryShort()
          && plg == QueryPluralLong()
          && lg == QueryLong()
         );
}

public int IsEqualTo(object ob)
{
  return (   ({int})ob->QueryValuePerUnit() == QueryValuePerUnit()
          && ({int})ob->QueryBrightPerUnit() == QueryBrightPerUnit()
          && ({int})ob->QueryWeightPerUnit() == QueryWeightPerUnit()
          && ({mixed})ob->QueryPluralShort() == QueryPluralShort()
          && ({string})ob->QueryShort() == QueryShort()
          && ({mixed})ob->QueryPluralLong() == QueryPluralLong()
          && ({string})ob->QueryLong() == QueryLong()
         );
}

//--- id handling for units -------------------------------------------------

public string *QueryPluralIds() { return Ppids; }
public string *SetPluralIds(string *ids)
{
  Ppluralpattern = 0;
  return Ppids = sizeof(ids) ? map(ids, SF(norm_id)) : 0;
}
public string *AddPluralId(mixed str) {
  Ppluralpattern = 0;
  return Ppids = _add_id(Ppids, str);
}
public string *RemovePluralId(mixed str) {
  Ppluralpattern = 0;
  return Ppids = _del_id(Ppids, str);
}

public int id(string str)
{
  int a, last, diff;
  string *s;
  if (   time() > lasttime
      || TP != lastpl
     )
    {
      lasttime = time();
      lastpl = TP;
      SetLastAmount(0);
      last = 0;
    }
  else
    last = QueryLastAmount();
  diff = QueryAmount()-last;
  if (::id(str))
  // If the unit identifies to the string as /std/thing only one
  // item of the unit is meant.
    {
      SetLastAmount(last+1);
      // We need to raise the amount if someone wants to identify
      // the unit with 'thing, thing and thing' where 'thing' is
      // always the unit.
      return 1;
    }
  if (!Ppluralpattern)
    Ppluralpattern = gen_id_pattern(QueryPluralIds(), QueryAds());
  if (_id(str, Ppluralpattern))
  // Check if the unit identifies to <str>. If yes, the whole unit
  // is meant.
    {
      SetLastAmount(last+diff);
      return 1;
    }

  if (!str)
    return lasttime = 0;

  // Up to now the unit didn't identify to <str>, so <str> contains
  // a part describing the amount.

  if (sizeof(s = explode(str, " ") - ({ "" })) < 2)
  // <str> is only one part. So there's no amount given.
    return lasttime = 0;

  if (lower_case(s[0]) == "every" && (::id(implode(s[1..], " "))))
  // 'every thing'
    {
      SetLastAmount(last+diff);
      return 1;
    }

  if (lower_case(s[0]) == "all")
  // 'all [the] things'
    {
      if (lower_case(s[1]) == "the")
        str = implode(s[2..], "");
      else
        str = implode(s[1..], "");
      if (_id(str, gen_id_pattern(QueryPluralIds(), QueryAds())))
        {
          SetLastAmount(last+diff);
          return 1;
        }
      s[0..0] = ({});
    }

  if (   intp(a = atoi(s[0]))
      && a <= diff
      && _id( implode(s[1..], " "), a == 1 ? gen_id_pattern(QueryIds(), QueryAds())
                                           : gen_id_pattern(QueryPluralIds(), QueryAds()))
    )
  // '[all] <n> things'
  {
    SetLastAmount(a+last);
    return 1;
  }

  // Every test failed here.
  return lasttime = 0;
}

//--- short description of a unit -------------------------------------------

public string PluralShort (mixed what, int amount)
{
//  return itoa(amount)+" "+(QueryPluralShort(what) || (QueryShort(what)+"s"));
  string str;
  str=QueryShort(what);
  if (str[sizeof(str)-1]!='y')
    return itoa(amount)+" "+(QueryPluralShort(what) || (QueryShort(what)+"s"));
  else {
    str[sizeof(str)-1]='i';
    return itoa(amount)+" "+(QueryPluralShort(what) || (str+"es"));
  }
}

public varargs string Short(mixed what)
{
  int lamount;
  string sh;

  sh = (::Short(what));
  if (!sh)  // Takes care of invisibility
    return sh;

  if (!QueryLastId()||query_verb()&&query_verb()!=QueryLastVerb())
  // Set the amount if not already done by id
    {
      SetLastAmount(QueryAmount());
      SetLastVerb(query_verb());
    }
  lamount = QueryLastAmount();
  return (lamount == 1 ? "one "+sh
                       : PluralShort(what, lamount)
         );
}

//--- long description of a unit -------------------------------------------

public string PluralLong (mixed what, int amount)
{
  return QueryPluralLong(what)||QueryLong(what);
}

public varargs string Long(mixed what)
{
  int lamount;
  string lg;

  lg = (::Long(what));

  if (!QueryLastId())
  // Set the amount if not already done by id
      SetLastAmount(QueryAmount());
  lamount = QueryLastAmount();

  return (lamount == 1 ? lg : PluralLong(what, lamount) );
}


//--- moving parts or the whole unit ----------------------------------------

public int ReduceAmount(int amount)
{
  if (amount>QueryAmount()) return 0;
  SetAmount(QueryAmount()-amount);
  if (!QueryAmount())
    remove();
  return 1;
}

public object SplitOff (int amount)
{
  object ob;
  mapping prop;

  if (amount < 1 || amount > QueryAmount())
    return 0;

  if (QueryAmount() == amount)
    return ME;

  // clone another instance
  ob = clone_object(blueprint());
  prop = QueryProperties();
  prop = m_delete(prop,P_AMOUNT);
  prop = m_delete(prop,P_VALUE);
  prop = m_delete(prop,P_BRIGHT);
  prop = m_delete(prop,P_WEIGHT);
  prop = m_delete(prop,P_LIGHT);
  // Configure it to the rest amount of units
  ob->SetProperties(prop);
  ob->SetAmount(amount);
  ReduceAmount(amount);
  lasttime--;
  return ob;
}

public int JoinWith (object ob)
{
  if (ob != ME && IsEqualTo(ob))
  {
    SetAmount(QueryAmount()+({int})ob->QueryAmount());
    ob->remove();
    return 1;
  }
  return 0;
}

//--- moving parts or the whole unit ----------------------------------------

public varargs int move(mixed dest, int method, mixed extra)
{
  object otherob;
  int old_amount;
  int ret, i;
  object *inv, env;

  if (!QueryLastId())
  // If 'id' wasn't called up to now (e. g. when something is
  // cloning us.
    SetLastAmount(QueryAmount());

  if (method != M_NOCHECK && query_verb() && query_verb() != QueryLastVerb())
    {
      SetLastVerb(query_verb());
      SetLastAmount(QueryAmount());
    }

  if (   method == M_NOCHECK
      || !environment()
      || QueryLastAmount() == QueryAmount())
    ret = (::move (dest, method, extra));
  else
    {
      // backup old value
      old_amount = QueryAmount();

      // clone another instance
      // Configure it to the rest amount of units
      otherob = SplitOff(QueryAmount()-QueryLastAmount());

      // move me to the new destination
      env = environment();
      ret = (::move(dest, method, extra));

      // If failed, restore me and destruct other instance
      if ((ret != ME_OK) && (ME != otherob))
        {
          SetAmount(old_amount);
          if (otherob)
            destruct(otherob);  // Do it the hard way.
          return ret;
        }
      // our move succeeded, now move new ob (if there is one)
      // into old environ
      if (otherob)
        otherob->move(env,M_SILENT);
      // This moved with M_NOCHECK before! This way the weight
      // didn't get updated.
    }

  if (ret == ME_OK)
    filter(all_inventory(environment()),SF(JoinWith));

  return ret;
}
