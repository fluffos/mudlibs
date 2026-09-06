/* /room/environ
**
** /std/room with additional bookkeeping functions for simulation of
** environmental or similar effects.
**
**  10-Oct-92 [Mateese]
**  20-Oct-92 [Mateese] Adapted for the living's heartbeat hook.
**  13-Jul-95 [Softbyte] Added Environmental Damage
**  10-Aug-96 [Softbyte] Added P_WATERBREATHING
**  17-Feb-97 [Softbyte] Added SetEnvironmentDamage
**  04-Apr-97 [Softbyte] Protect idle players
*/

inherit "/std/room";
#include <combat.h>
#include <properties.h>

#define PL this_player()
#define ME this_object()
#define PO previous_object()

#define TIME_IDLE 300     // 300 secs idle protecgs you from env damage

private mapping environmap;
private mapping envcnt;
private int envdamage;

void Debug(string str)
{
  object ob;
  ob=find_player("softbyte");
  if (ob) tell_object(ob,str);
}

public varargs void create(int noreplace)
{
  ::create(noreplace);
  environmap=([]);
  envcnt=([]);
  envdamage=20;   // default damage
}

// ------------------------------------------------------------------------
// Environment functions
// varargs mixed AddEnvironment(int dam_type,mixed a1,mixed a2)
// mixed RemoveEnvironment(int dam_type)

/* For debugging purpose */
mixed QueryEnvironment() { return environmap; }
mapping QueryEnvCnt() {return envcnt;}

/*--------------------------------------------------------------------------
** This functions have to be overloaded by the inheriting object...
*/
private int updateEnvironment(object ob)
{
  mixed *keys;
  int i;
  mapping emap;

  if (!ob || !living(ob) )
    return 0;
  m_delete(envcnt, ob);
  keys=m_indices(environmap);
  if (sizeof(keys))  // Environment defined ?
  {
    emap=([]);
    for (i=0; i < sizeof(keys); i++)
       emap += ([ keys[i]:environmap[keys[i],0] ]);
    envcnt += ([ ob:emap ]);
    ob->InitHBHook(1);   // Get Heartbeat
    return 1;
  }
  return 0;
}

// ------------------------------------------------------------------------
// Living enters the room
void Enter (object living, mixed oldenv, int method, mixed extra)
{
  updateEnvironment(living);
}

// ------------------------------------------------------------------------
// Living leaves the room
void Exit (object living, mixed dest, int method, mixed extra)
{
  living->SetHBHook(0);  // Is this ok to release Heartbeat?
  m_delete(envcnt, living);
}

// ------------------------------------------------------------------------
/* arguments are "called by reference" and can be changed !!!  */
/* A defence of 20 against the damage type will complete guard */
/* the player and no damage will be done                       */

private void DefendEnvironment(int dam_type,int cnt,object who)
{
  mixed *defences;
  int dam;
  if (dam_type < DT_MAGIC) return; /* Illegal argument ? */
  if (query_idle(who)>TIME_IDLE) return; /* Protect idle players */
  cnt--;
  if (cnt<=0)
  {
    dam=envdamage;         /* 20 or 100 - depends on range of defences */
    dam=dam/4+random(dam/4);  /* we want 10 HP per heartbeat, but adjustable */
    if (({int})who->Query(P_WATERBREATHING) && dam_type==DT_NOAIR) dam=0;
    if (dam>0)
    {
      if (environmap[dam_type,1])
        tell_object(who,environmap[dam_type,1]);
      else
        tell_object(who,"You suffer from environmental damage!\n");
      who->Defend(dam,dam_type,0);
    }
    cnt=environmap[dam_type,0]; /* reset counter */
  }
}

/* players heartbeat */
void player_hb_hook()
{
  object ob;
  ob=previous_object();
  // Hurt no NPCs yet
  if (({int})ob->QueryIsPlayer() && !({int})ob->QueryNetdead() && sizeof(envcnt[ob]))
    walk_mapping(envcnt[ob],#'DefendEnvironment /*'*/,ob);
}

/*--------------------------------------------------------------------------
** Entrance/Exit of livings
*/

varargs void notify_enter (mixed oldenv, int method, mixed extra) {
  mixed rc, flag;
  ::notify_enter (oldenv, method, extra);
  if (living(PO)) Enter(PO, oldenv, method, extra);
}

varargs void notify_leave (mixed dest, int method, mixed extra) {
  mixed rc;
  ::notify_leave (dest, method, extra);
  if (living(PO)) Exit(PO, dest, method, extra);
}

/* ----------------------------------------------------------------- */
/* Sets the amount of HP a Damage should do...this should be the     */
/* simply the max range a defence can block...i.e. 20 or 100         */
int SetEnvironmentDamage(int damage)
{
  envdamage=damage;
  return envdamage;
}
int QueryEnvironmentDamage() {return envdamage;}
/* ----------------------------------------------------------------- */
/* Adds an environment to the current room */
/* More than one environments are possible */
/* dam_Type defined in combat.h (DT_FIRE,..DT_ACID,..) */
/* a1=strenght of damage: 100 means 10HP damage every heartbeat (5HP/sec) */
/*                        1 means 10HP damage every 100 heartbeats(0.05HP/sec) */
/* a2=message to player if he/she is hurt by environment */
/* Both a1 and a2 are optinonal and will be replaced by the defval */
/* values below. */
/* Default damages for DT_TYPES are that a avaerage character (150HP) */
/* will survive for  DT_FIRE=15min, DT_COLD=DT_WATER=30min,DT_GAS=30sec */
/*                   DT_ACID=60sec,DT_NOAIR=4min */

#define DEFAULT_STRENGTH 92 /* 101-9=92 */

varargs mixed AddEnvironment(int dam_type,mixed a1,mixed a2)
{
  string dammesg;
  int strength;
  mixed dummy;
  mapping defval;

  defval=([ DT_FIRE:70;"You are burning.\n",
            DT_COLD:40;"You are freezing",
            DT_WATER:40;0,    /* What can water do ? */
            DT_GAS:100;"You are breathing toxic air.\n",
            DT_ACID:99;"You become burned by acid.\n",
            DT_NOAIR:92;"You cannot breath.\n"]);
  if (dam_type<DT_MAGIC) return 0;
  /* Be a little flexible about the passed arguments */
  if (!a1 && !a2)
  {
    if (!m_contains(&strength,&dammesg,defval,dam_type))
      {dammesg=0;strength=DEFAULT_STRENGTH;}
  }
  else if (!a2 && intp(a1) )
  {
    if (!m_contains(&dummy,&dammesg,defval,dam_type))
      {dammesg=0;}
    strength=a1;
  }
  else if (!a2 && stringp(a1) )
  {
    if (!m_contains(&strength,&dummy,defval,dam_type))
      {strength=DEFAULT_STRENGTH;}
     dammesg=a1;
  }
  else
  {
    dammesg=a2;strength=a1;
  }

  /* Adjust the environemnt */
  environmap-=([dam_type]);
  if (strength>0) environmap+=([dam_type:101-strength;dammesg]);

  /* Update Environment for all livings */
  filter(all_inventory(),#'updateEnvironment);

  return(environmap);
}

// ------------------------------------------------------------------------
/* Remove an environment type from the room */

mixed RemoveEnvironment(int dam_type)
{
  if (dam_type<DT_MAGIC) return 0;

  /* Adjust the environemnt */
  environmap-=([dam_type]);

  /* Update Environment for all livings */
  filter(all_inventory(),#'updateEnvironment);

  return(environmap);
}

/****************************************************************************/
