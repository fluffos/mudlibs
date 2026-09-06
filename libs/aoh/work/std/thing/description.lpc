//---------------------------------------------------------------------------
// thing/description.c
//
// A general inheritance file for all kinds of descriptions of an object.
//---------------------------------------------------------------------------

#include <secure/wizlevels.h>
#include <properties.h>

#define TO       this_object()
#define TP       this_player()
#define ENV      environment()

#define SUBID  (to_string(this_object())+":subid")

public varargs mixed Query(string name, int sc); // std/base

//--- global variables ------------------------------------------------------

private nosave string *Pids, *Pads, *Pcids, *Pcads;
private nosave string Plastid, Plastverb;
private nosave object Plastpl;
private nosave mapping Pextra, Psubdetails, Psubread;
private nosave mixed Plong, Pmagic, Phelpmsg, Pnobuy, Pnosell;
private nosave string Pshort, Psmell, Pnoise, Preadmsg;
private nosave string Pinfo, Pidpattern, Pclasspattern;
private nosave int Pvalue, Psize;

private nosave string * cSubdetails, * cSubread, * cSuball;

//--- private functions to keep memory use low ------------------------------

private void clear_subcache()
{
  cSubdetails = 0;
  cSubread = 0;
  cSuball = 0;
}

private void make_subcache()
{
  if (!cSuball)
  {
    cSubdetails = m_indices(Psubdetails || ([]));;
    cSubread    = m_indices(Psubread    || ([]));;
    cSuball = cSubdetails + cSubread;
  }
}

//--- flatten the keys of a mapping
private mapping flat_keys(mapping map)
{
  mixed *ind, val;
  int    i, j;
  if (!map)
    return 0;
  ind = m_indices(map);
  for (i = sizeof(ind); i--; )
    if (pointerp(ind[i]))
    {
      val = map[ind[i]];
      m_delete(map, ind[i]);
      for (j = sizeof(ind[i]); j--; )
        map[ind[i][j]] = val;
    }
  return map;
}


private void map_add(mapping map, mixed key, mixed val) {
  if (!map)
    map = ([]);
  if (stringp(val))
    val = to_string(quote(val));
  else if (pointerp(val) && sizeof(val) >= 3 && val[0] == "#call_other")
  {
    val[0] = #'call_other /*'*/;
    val = lambda(({'w}), val+({'w}));
  }
  if (pointerp(key))
  {
    if (pointerp(val))
      val = quote(val);
    map += mkmapping(key, map(key, lambda(0, val)));
  }
  else
    map[key] = val;
}

private void map_rm(mapping map, mixed key) {
  if (map) {
    if (stringp(key))
      m_delete(map, key);
    else
      map -= mkmapping(key);
    if (!sizeof(map))
      map = 0;
  }
}

//--- object identification -------------------------------------------------

public string *QueryIds()          { return Pids; }
public string *SetIds(string *ids) {
  Pidpattern = 0;
  return Pids = sizeof(ids) ? map(ids, #'norm_id /*'*/) : 0;
}

public string *QueryAds()          { return Pads; }
public string *SetAds(string *ads) {
  Pidpattern = 0;
  return Pads = sizeof(ads) ? map(ads, #'norm_id /*'*/) : 0;
}

public string *QueryClassIds()     { return Pcids; }
public string *SetClassIds(string *ids) {
  Pidpattern = 0;
  Pclasspattern = 0;
  return Pcids = sizeof(ids) ? map(ids, #'norm_id /*'*/) : 0;
}

public string *QueryClassAds()     { return Pcads; }
public string *SetClassAds(string *ads) {
  Pidpattern = 0;
  Pclasspattern = 0;
  return Pcads = sizeof(ads) ? map(ads, #'norm_id /*'*/) : 0;
}

protected mixed _add_id(mixed *prop, mixed str) {
  if (pointerp(str))
    str = map(str, #'norm_id /*'*/) + ({});
  else
    str = ({ norm_id(str) });
  return prop
         ? (prop += str - (prop & str))
         : prop = str;
}

protected mixed _del_id(mixed *prop, mixed str) {
  if (pointerp(str))
    str = map(str, #'norm_id /*'*/) + ({});
  else
    str = ({ norm_id(str) });
  return prop && (prop -= str);
}

public string *AddId(mixed str) {
  Pidpattern = 0;
  return Pids = _add_id(Pids, str);
}
public string *AddClassId(mixed str) {
  Pidpattern = 0;
  Pclasspattern = 0;
  return Pcids = _add_id(Pcids, str);
}
public string *AddAdjective(mixed str) {
  Pidpattern = 0;
  return Pads = _add_id(Pads, str);
}
public string *AddClassAdj(mixed str) {
  Pidpattern = 0;
  Pclasspattern = 0;
  return Pcads = _add_id(Pcads, str);
}

public string *RemoveId(mixed str) {
  Pidpattern = 0;
  return Pids = _del_id(Pids, str);
}
public string *RemoveClassId(mixed str) {
  Pidpattern = 0;
  Pclasspattern = 0;
  return Pcids = _del_id(Pcids, str);
}
public string *RemoveAdjective(mixed str) {
  Pidpattern = 0;
  return Pads = _del_id(Pads, str);
}
public string *RemoveClassAdj(mixed str) {
  Pidpattern = 0;
  Pclasspattern = 0;
  return Pcads = _del_id(Pcads,str);
}

// Take a string and check if it matches gen_id_pattern()-generated pattern
// of adjectives and id-strings.

protected int _id(string str, string pattern) {
  int i;
  string work;

  work = str = str && lower_case(str);
  if (str && stringp(pattern))
    {
      make_subcache();

      // Check for a subdetail
      if (sizeof(cSuball)
      &&  (   1 <= (i = strstr(work, " on "))
           || 1 <= (i = strstr(work, " of "))
          )
      &&  -1 != member(cSuball, work[0..i-1])
         )
      {
        if (TP)
          TP->SetCmdData(SUBID, work[0..i-1]);
        work = work[i+4..];
      }
      else if (TP)
        TP->SetCmdData(SUBID, 0);

#if 0
      /* --- The old code - not that slow --- */
      // Is this the right object at all?
      if (!stringp(ids) && sizeof(ads))
      {
        work = " "+work;
        for (i = 0; i < sizeof(ads); i++)
        {
          tmp = " "+ads[i]+" ";
          if (0 <= (pos = strstr(work, tmp)))
            work[pos..pos+strlen(tmp)-2] = "";
        }
        work[0..0] = ""; // Undo the first added space.
      }
      if (stringp(ids) ? match_id(work, ids) : (member(ids, work) >= 0))
      {
        Plastid = str;
        Plastverb = query_verb();
        Plastpl = this_player();
        return 1;
      }
      /* --- --- */
#endif
      // Is this the right object at all?
      if (match_id(work, pattern, ({})))
      {
        Plastid = str;
        Plastverb = query_verb();
        Plastpl = this_player();
        return 1;
      }
    }
  Plastid = 0;
  Plastverb = 0;
  Plastpl = 0;
  if (TP)
    TP->SetCmdData(SUBID, 0);
  return 0;
}

// Take a string and check if it matches on of our ids.
// Consider both the object ids and the class id.

public int id(string str) {
  str = str && lower_case(str);
  if (!Pids && str == "object" && IS_WIZARD(this_player()))
    {
      Plastid = str;
      Plastverb = query_verb();
      Plastpl = this_player();
      if (TP)
        TP->SetCmdData(SUBID, 0);
      return 1;
    }
  if (!Pidpattern)
    Pidpattern = gen_id_pattern( (Pids||({}))+(Pcids||({})), (Pads||({}))+(Pcads||({})) );
  return _id(str, Pidpattern);
}

// Take a string and check if it matches on of our ids.
// First check the object ids, then the class id.

public int class_id(string str) {
  str = str && lower_case(str);
  if (!Pids && str == "object" && IS_WIZARD(this_player()))
    {
      Plastid = str;
      Plastverb = query_verb();
      Plastpl = this_player();
      if (TP)
        TP->SetCmdData(SUBID, 0);
      return 1;
    }
  if (!Pclasspattern)
    Pclasspattern = gen_id_pattern( (Pcids||({})), (Pcads||({})) );
  return _id(str, Pclasspattern);
}

public string QueryLastId()            { return Plastid; }
public string SetLastId(string id)     { return Plastid; }
public string QueryLastVerb()          { return Plastverb; }
public string SetLastVerb(string v)    { return Plastverb; }
public object QueryLastPlayer()        { return Plastpl; }
public object SetLastPlayer(object pl) { return Plastpl; }

public string QueryIdPattern()           { return Pidpattern; }
public string SetIdPattern(string pt)    { return Pidpattern = pt; }
public string QueryClassPattern()        { return Pclasspattern; }
public string SetClassPattern(string pt) { return Pclasspattern = pt; }

//--- basic properties of a thing -------------------------------------------

public varargs int QueryValue()            { return Pvalue; }
public int SetValue(int i)         { return Pvalue = i; }

public mapping QueryExtraDesc()    { return Pextra || ([]); }
public mapping SetExtraDesc(mapping m) { return Pextra = m; }

#if __VERSION__ > "3.5.0"
public varargs mixed QueryLong(string|int what) { return Plong; }
#else
public varargs mixed QueryLong(string what) { return Plong; }
#endif
public mixed SetLong(mixed s)     { return Plong = s; }

public mixed QueryNoBuy()         { return Pnobuy; }
public mixed SetNoBuy(mixed s)   { return Pnobuy = s; }

#if __VERSION__ > "3.5.0"
public varargs string QueryNoise(string|int what) { return Pnoise; }
#else
public varargs string QueryNoise(string what) { return Pnoise; }
#endif
public string SetNoise(string s)   { return Pnoise = s; }

public mixed QueryNoSell()         { return Pnosell; }
public mixed SetNoSell(mixed s)   { return Pnosell = s; }

public string QueryReadMsg()       { return Preadmsg; }
public string SetReadMsg(string s) { return Preadmsg = s; }

#if __VERSION__ > "3.5.0"
public varargs string QueryShort(string|int what) { return Pshort; }
#else
public varargs string QueryShort(string what) { return Pshort; }
#endif
public string SetShort(string s)   { return Pshort = s; }

#if __VERSION__ > "3.5.0"
public varargs string QuerySmell(string|int what) { return Psmell; }
#else
public varargs string QuerySmell(string what) { return Psmell; }
#endif
public string SetSmell(string s)   { return Psmell = s; }

public varargs mapping QuerySubDetails() { return Psubdetails; }
public mapping SetSubDetails(mapping m)  { clear_subcache(); return Psubdetails = flat_keys(m); }

public varargs mapping QuerySubReadMsgs() { return Psubread; }
public mapping SetSubReadMsgs(mapping m)  { clear_subcache(); return Psubread = flat_keys(m); }

public int QuerySize()            { return Psize; }
public int SetSize(int i)         { return Psize = i; }

public string QueryInfo()         { return Pinfo; }
public string SetInfo(string s)   { return Pinfo = s; }

public mixed QueryMagic()         { return Pmagic; }
public mixed SetMagic(mixed s)    { return Pmagic = s; }

public mixed QueryHelpMsg()         { return Phelpmsg; }
public mixed SetHelpMsg(mixed s)    { return Phelpmsg = s; }

//--- adding subdetails -----------------------------------------------------

public varargs void AddSubDetail(mixed det, mixed desc, string exa) {
  if (stringp(desc) && stringp(exa))
    desc = ({ desc, exa });
  map_add(&Psubdetails, det, desc);
  clear_subcache();
}

public void AddSubReadMsg(mixed k, mixed v) { map_add(&Psubread, k, v); clear_subcache(); }

//--- removing subdetails ----------------------------------------------------

public void RemoveSubDetail(mixed k) { map_rm(&Psubdetails, k); clear_subcache(); }
public void RemoveSubReadMsg(mixed k)  { map_rm(&Psubread, k); clear_subcache(); }

//--- searching for a subdetail --------------------------------------------

public mixed GetSubDetail(string str) {
  return Psubdetails && funcall(Psubdetails[str], str);
}

public string GetSubReadMsg(string str) {
  return Psubread && funcall(Psubread[str], str);
}

//--- Actual appearance -----------------------------------------------------

public string * filterExtra (string prop) {
  mixed data, tmp;
  int   i;
  string *rc;

  if (!(data = QueryExtraDesc()))
    return ({});
  data = map(m_values(data), #'funcall /*'*/);
  rc = allocate(sizeof(data));
  for (i = 0; i < sizeof(data); i++) {
    if (mappingp(data[i]) && stringp(tmp = funcall(data[i][prop])))
      rc[i] = tmp;
  }
  return rc - ({ 0, "" });
}

public varargs string Long(string what)  {
  mixed rc;
  string subid;

  subid = 0;
  if (TP && (subid = ({string})TP->QueryCmdData(SUBID)))
  {
    rc = GetSubDetail(subid) || "You see nothing special.\n";
    return (pointerp(rc) ? rc[0] : rc);
  }
  rc = QueryLong(what);
  return (pointerp(rc) ? rc[0] : rc)+implode(filterExtra(P_LONG), "");
}
public varargs string ExaLong(string what)  {
  mixed rc;
  string subid;

  subid = 0;
  if (TP && (subid = ({string})TP->QueryCmdData(SUBID)))
  {
    rc = GetSubDetail(subid) || "You see nothing special.\n";
    return pointerp(rc) ? rc[1] : "You see nothing special.\n"+rc;
  }
  rc = QueryLong(what);
  return (pointerp(rc) ? rc[1] : "You see nothing special.\n"+rc)
         +implode(filterExtra(P_LONG), "");
}
public varargs string Short(string what) {
  string sh;
  if (!(sh = QueryShort(what)) || sh == "")
    return sh;
  return sh+implode(filterExtra(P_SHORT), "");
}
public varargs string InvShort(string what) {
  return capitalize(Short(what)||"");
}

public varargs string Noise(string what) {
  string str;
  str = (QueryNoise()||"")+implode(filterExtra(P_NOISE), "");
  return str != "" ? str : 0;
}
public varargs string Smell(string what) {
  string str;
  str = (QuerySmell()||"")+implode(filterExtra(P_SMELL), "");
  return str != "" ? str : 0;
}

public varargs string Read(string what)  {
  string str;
  string subid;

  subid = 0;
  if (TP && (subid = ({string})TP->QueryCmdData(SUBID)))
    str = GetSubReadMsg(subid);
  else
    str = QueryReadMsg();
  str = funcall(str||"");
  return str != "" ? str : 0;
}

public varargs int CompareSize (mixed with) {
  int size1, size2;
#if 0
  log_file("COMPAT.size"
          , sprintf("%s %O->%O:CompareSize(%O)\n"
                    "    TP: %O, TI: %O\n"
                   , ctime(), previous_object(), this_object(), with
                   , this_player(), this_interactive())
          );
#endif
  return 0; // For now disabled
  if (objectp(with))
    size2 = ({int})with->Query(P_SIZE);
  else if (intp(with))
    size2 = with;
  else
    return 0;
  size1 = Query(P_SIZE);
  if (!size1 || !size2 || (size1 == size2))
    return 0;
  if (size1 < size2)
    return -1;
  return 1;
}

//--- Extra descriptions ---------------------------------------------------

public void SetExtra (mixed name, mixed data) {
  mapping m;
  m = QueryExtraDesc();
  m[name] = data;
  SetExtraDesc(m);
}

public mixed QueryExtra (mixed name) {
  return QueryExtraDesc()[name];
}

public void RemoveExtra (mixed name) {
  mapping data;
  data = QueryExtraDesc();
  m_delete(data, name);
  SetExtraDesc(data);
}

public void SetExtraEntry (mixed name, mixed prop, mixed data) {
  mapping xm, m;
  xm = QueryExtraDesc();
  if (mappingp(m = xm[name]))
    m[prop] = data;
  else
    m = ([ prop:data ]);
  xm[name] = m;
  SetExtraDesc(xm);
}

public mixed QueryExtraEntry (mixed name, mixed prop) {
  mapping xm, m;
  xm = QueryExtraDesc();
  if (mappingp(m = xm[name]))
    return m[prop];
  return 0;
}

public void RemoveExtraEntry (mixed name, mixed prop) {
  mapping xm, m;
  xm = QueryExtraDesc();
  if (mappingp(m = xm[name]))
    m_delete(m, prop);
  if (sizeof(m))
    xm[name] = m;
  else
    m_delete(xm, name);
  SetExtraDesc(xm);
}
