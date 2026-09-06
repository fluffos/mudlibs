/* DomainInfo
**
** Create a database of domain membership out of the /secure/save-files.
**
**    28-Jul-92 [m]
**    11-Apr-95 [m] Added stage _init_01() to prevent too long evaluations.
**                  Added next_delay() to improve call_out() scheduling.
**    27-Jan-96 [m] Added check_state() to ensure reloads if the master-
**                  initiated reload ran into an error.
**    31-Jan-96 [m] Added archwizard information.
**    03-Feb-96 [m] Also scans the /p directories.
**    15-Mar-98 [m] New level system.
**    26-Apr-98 [m] Removed archwizard information.
**
**  [m] Mateese
*/

#include <secure/config.h>
#include <secure/userinfo.h>
#include <secure/wizlevels.h>
#include <secure/domaininfo.h>

#define VERSION "980426"
#define BUNCH 5   /* Nr of files per _init_1() */
#define DELAY 2   /* Delay between two call_out()s */
#define dtell(x) if(find_player("nostradamus")) tell_object(find_player("nostradamus"),x)

/*-------------------------------------------------------------------------
*/

  /* secure save file variables - we need them to load the /secure/save's */
string name, password, shell, *domains;
int level, bRemoved;

  /* My variables */
nosave int state;
nosave mapping ndomain;
/* struct {
**   string *dname;    Domainnames
**   struct {
**     int hasdir;     /d/<dname> there?
**     struct {          Alist with info about members:
**       string *wname;     Wizardnames
**       int    *dstat;     0: Member, 1: Vice, 2: Lord
**     } *wiz;
**   } *ddata;
** }
*/

nosave int w_cnt;  /* No of wizards */
nosave int t_load, t_chg;  /* Time of load/change of domain[] */
nosave int _toread;  /* On loading: dirs left to read */
nosave int lasttime; /* Last time of a scheduled call_out */

int check_state();
void ReloadData();
void _init_2();
void _init_1 (string *sfiles);
void _init_0();
void _init_01(string name);
/*-------------------------------------------------------------------------
*/

void create () {
  if (sizeof(explode(object_name(this_object()),"#")) != 1)
    destruct(this_object());
  state = DI_UNINITED;
  seteuid(getuid());
  ndomain = ([]);
  lasttime = time();
  call_out (#'ReloadData /*'*/, 1);
}

int query_prevent_shadow() { return 1; }

//-------------------------------------------------------------------------
int next_delay()

/* Return a delay for a call_out() such between two call_outs elapse at
** least 5 seconds.
*/

{
  lasttime += DELAY;
  if (time() >= lasttime)
  {
    lasttime = time()+1;
    return 1;
  }
  return lasttime - time();
}

/*-------------------------------------------------------------------------
** Return some information about us:
** - State of database
** - Time of Load
** - Time of last change
** - Number of domains registered
** - Number of wizards registered
** - the version of the object
*/

mapping QueryDomainData() { return ndomain; }
int QueryState()          { return state; }
int QueryLoadTime()       { return t_load; }
int QueryChangeTime()     { return t_chg; }
int QueryDCount()         { return sizeof(ndomain); }
int QueryWCount()         { return w_cnt; }
string QueryVersion()     { return VERSION; }

/*-------------------------------------------------------------------------
** Load the save-File of wizard <name>
** and return the alist of ({ domain_name }), ({ membership })
** If there is no save-file, 0 is returned.
*/

mixed *QueryWizardData (string name) {
  mixed rc;
  string dom;
  int stat, i;

  if (!stringp(name))
    return 0;
  if (sizeof(name) > 2 && name[<2..<1] == ".o")
    name = name[0..sizeof(name)-3];
  rc = explode (name, "/");
  rc = rc[sizeof(rc)-1];
  rc = "/secure/save/"+rc[0..0]+"/"+rc;
  if (file_size(rc+".o") <= 0) return 0;
  bRemoved = 0;
  restore_object (""+rc);
  if (bRemoved) return 0;

  rc = ({ ({}), ({}) });
  for (i = 0; domains && i < sizeof(domains); i++) {
    dom = domains[i]; stat = D_MEMBER;
    if (!dom || dom == "") continue;
    if (dom[0] == '+') dom = dom[1..sizeof(dom)-1], stat = D_VICE;
    else if (dom[0] == '*') dom = dom[1..sizeof(dom)-1], stat = D_LORD;
    rc[0] += ({dom});
    rc[1] += ({stat});
  }
  return rc;
}

/*-------------------------------------------------------------------------
** Get and set the Info 'ddata' for one domain.
*/

void SetDomain (string dname, mixed *ddata) {
  object ob;

  if ((ob=previous_object()) != this_object() &&
      (explode(object_name(ob),"#")[0] != "/obj/tool/domaintool"))
    return 0;
  check_state();
  if (!member(ndomain, dname))
    ndomain += ([ dname: ddata ]);
  else
    ndomain[dname] = ddata;
  t_chg = time();
}

mixed QueryDomain (string dname) {
  if (!check_state())
    return ({});
  if (!member(ndomain, dname))
    return 0;
  return ndomain[dname];
}

string *QueryAllDomains() {
  return m_indices(ndomain);
}

void RemoveDomain (string dname) {
  m_delete(ndomain, dname);
}

/*-------------------------------------------------------------------------
** Set/change or query the membership state of a wizard in a domain.
*/

int SetWizard (string wname, string dname, int stat) {
  mixed *ddata, *wiz;
  int wst;
  object ob;

  if ((ob=previous_object()) != this_object() &&
      (explode(object_name(ob),"#")[0] != "/obj/tool/domaintool"))
    return 0;
  check_state();
  if (!member(ndomain, dname))
    return notify_fail("Illegal domain '"+dname+"'.\n"), 0;
  ddata = ndomain[dname];
  wiz = ddata[1];
  wst = member(wiz[0], wname);
  if (wst == stat)
    return 0;
  if (stat == D_NOMEMBER)
  {
    wiz[0][wst..wst] = ({});
    wiz[1][wst..wst] = ({});
  }
  else if (stat > wst)
  {
    wiz[0] += ({ wname });
    wiz[1] += ({ stat });
  }
  ddata[1] = wiz;
  ndomain[dname] = ddata;
  return t_chg = time();
}

int QueryWizard(string wname, string dname) {
  int i;
  mixed *ddata;
  if (!member(ndomain, dname))
    return write("Illegal domain '"+dname+"'.\n"), D_NOMEMBER;
  ddata = ndomain[dname];
  i = member(ddata[1][0], wname);
  return (i != -1) ? ddata[1][1][i] : D_NOMEMBER;

}

/*-------------------------------------------------------------------------
** ReloadData
**   Rebuild the database.
*/

void ReloadData() {
  state = DI_UNINITED;
  _init_0();
}

void start_dragon() {
  if (state == DI_INITED)
  {
    if (catch(ReloadData()))
      state = DI_UNINITED;
  }
}

int check_state()
{
  if (state != DI_UNINITED)
    return 1;
  ReloadData();
  return 0;
}

/*-------------------------------------------------------------------------
** Init - 0:
**    For each /secure/save/?/ call _init_1().
**    Intersected is another call_out-stage over _init_01() dealing
**    with one of the .secure/save dirs.
*/

void _init_0() {
  string *dir, name;
  int i, len;

  ndomain = ([]);
  t_load = t_chg = time();
  w_cnt = 0;
  state = DI_INITING;

    /* Get domains from /d and /p */
  dir = get_dir_ext (DPATH "*");
  for (i = 0; i < sizeof(dir); i++) {
    name = dir[i]; len = sizeof(name);
    if (len < 2 || name[len-1] != '/' || name[0] == '.') continue;
    SetDomain (lower_case(name[0..len-2]), ({ 1, DW_EMPTY }) );
  }
  dir = get_dir_ext (PPATH "*");
  for (i = 0; i < sizeof(dir); i++) {
    name = dir[i]; len = sizeof(name);
    if (len < 2 || name[len-1] != '/' || name[0] == '.') continue;
    SetDomain (lower_case(name[0..len-2]), ({ 1, DW_EMPTY }) );
  }

    /* Get 'hash'-dirs from /secure/save */
  dir = get_dir ("/secure/save/*");
  _toread = sizeof(dir);
  for (i = 0; i < sizeof(dir); i++) {
    name = dir[i];
    if (sizeof(name) != 1 || name[0] < 'a' || name[0] > 'z') {
      _toread--;
      continue;
    }
    call_out(#'_init_01 /*'*/, next_delay(), name);
  }
}

void _init_01 (string name)
{
  string *sfiles;
  int j;

  sfiles = get_dir("/secure/save/"+name+"/*.o");
  if (!sfiles || !pointerp(sfiles) || !sizeof(sfiles)) {
    _toread--;
    return;
  }
  for (j = 0; j < sizeof(sfiles); j++)
    sfiles[j] = "/secure/save/"+name+"/"+sfiles[j];
  call_out (#'_init_1 /*'*/, next_delay(), sfiles );
}

/*-------------------------------------------------------------------------
** Init - 1:
**   Handle each of the given given save_files in /secure/save.
**   Do this in bunches of BUNCH.
**   If _toread reaches 0, all is done and thus call _init_2().
*/

void _init_1 (string *sfiles) {
  int i, j, todo;
  string dname, wname;
  mixed *wdata;


  if (!sfiles || !pointerp(sfiles) || !sizeof(sfiles)) {
    return;
  }
  todo = sizeof(sfiles);
  if (todo > BUNCH) todo = BUNCH;
  for (i = 0; i < todo; i++) {
      /* /secure/save/<name>.o => <name> */
    wname = sfiles[i];
    if (sizeof(wname) > 2 && wname[<2..<1] == ".o")
      wname = wname[0..sizeof(wname)-3];
    wname = explode (wname, "/")[<1];
      /* Get DomainData for this wizard and parse it */
    wdata = QueryWizardData(sfiles[i]);
    if (!wdata || !sizeof(wdata) || !sizeof(wdata[0])) continue;
    for (j = 0; j < sizeof(wdata[0]); j++) {
      dname = wdata[0][j];
        /* Care for domains not found by the /d-scan */
      if (!member(ndomain, dname))
        SetDomain (dname, ({ (file_size("/d/"+dname)==-2), DW_EMPTY }) );
      SetWizard (wname, dname, wdata[1][j]);
    }
    w_cnt++;
  }

    /* All done ? */
  if (todo != sizeof(sfiles)) {
    sfiles = sfiles[todo..sizeof(sfiles)];
    call_out (#'_init_1 /*'*/, next_delay(), sfiles);
  }
  else {
    if (!--_toread) call_out(#'_init_2 /*'*/, next_delay());
  }
}


/*-------------------------------------------------------------------------
** Init - 2:
**   Do the necessary postprocessing.
*/

void _init_2() {
  state = DI_INITED;
  t_chg = t_load = time();
}

/*************************************************************************/
