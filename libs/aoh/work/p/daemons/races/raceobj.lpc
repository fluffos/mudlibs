/* /p/daemon/races/raceobj
**
** Parent object for inheritance by the race-objects.
**
**  01-Sep-92 [Mateese]
**  04-Oct-92 [Mateese] Stats are hardcoded now.
**  07-Oct-92 [Mateese] Skills,Spells are 'gone'.
**  08-Oct-92 [Mateese] AT_DESC included.
**  19-Jan-95 [Mateese] RD_SIZE added, small tweaks.
**  06-Feb-95 [Mateese] RD_MAXSTAT added for experiments.
**  14-Dec-95 [Mateese] RD_PORTAL added.
**  14-Jan-96 [Mateese] RD_EQUIP, EquipPlayer() new.
**  28-Oct-97 [Mateese] RD_PLURAL new.
**  18-Dec-97 [Softbyte] RD_INFO, information text new
**  02-nov-98 [Magictcs] added support for legs
*/

#include <races.h>
#include <attributes.h>
#include <moving.h>
#include <secure/wizlevels.h>

/*-------------------------------------------------------------------------*/

nosave mixed *racedata;  /* The array containing the racial data */
nosave string racedesc;  /* The string containing the race description */
#if __VERSION__ > "3.5.0"
varargs void AddEquipment( string key, mixed file, int level, mapping props, string *|string alias);
#else
varargs void AddEquipment( string key, mixed file, int level, mapping props, mixed alias);
#endif
/*-------------------------------------------------------------------------*/

void create() {
  if (clonep()) {
    destruct (this_object());
    return;
  }
  seteuid(getuid());
  racedata = allocate (RD_NO_ITEMS);
  racedata[RD_HANDS]    = ({});
  racedata[RD_LEGS]     = ({});
  racedata[RD_DEFENCES] = ({});
  racedata[RD_STAT]     = ([]);
  racedata[RD_ATTR]     = ([]);
  racedata[RD_MAXSTAT]  = 0;
  racedata[RD_PLURAL]   = 0;
  racedata[RD_EQUIP]    = m_allocate(0,RDE_NO_ITEMS);
  racedata[RD_INFO]    = "There is no information available.\n";

  AddEquipment("qtyper", "/obj/qtyper", 0, 0, "quicktyper");
  AddEquipment("money", "/obj/money", 5, ([ P_MONEY: (["copper":20]) ]) );
  AddEquipment("bag", "/obj/bag", 5, 0, ({ "sack", "bag" }) );
  AddEquipment("knife", "/obj/weapons/knifes/knife", 5, 0, "knife" );
  AddEquipment("water", "/p/newbie/obj/water", 5, 0, "drink" );
  AddEquipment("bread", "/p/newbie/obj/roll", 5, 0, 0 );
}

mixed *RaceData () { return racedata; }
string RaceDescr () { return racedesc; }

/*-------------------------------------------------------------------------*/
int EquipPlayer(object pl)

/* Clone the basic equipment for a player, depending on his race.
 * Return 0 on success, !0 on failure.
 */

{
  int level, i, j;
  mixed * things, *ids, t;
  mapping equip;
  object ob, *given, *dropped;

  level = ({int})RACEMASTER->XPtoLevel(({int})pl->Query(P_XP));
  equip = racedata[RD_EQUIP];
  given = ({});
  dropped = ({});
  things = m_indices(equip);

  for (i = sizeof(things); i--; )
  {
    // Check the level restriction
    j = equip[things[i], RDE_LEVEL];
    if (j > 0 && j < level)
      continue;
    if (!j && IS_IMMORTAL(pl))
      continue;

    // Look for the equipment being present.
    ids = ({ things[i] }) + equip[things[i], RDE_ALIAS]||({});
    ob = 0;
    for (j = sizeof(ids); j-- && !ob;)
      ob = present(ids[j], pl);
    if (ob)
      continue;

    // Not present: clone and give the equipment object.
    t = equip[things[i], RDE_FILE];
    if (closurep(t))
      t = funcall(t, pl);
    if (!t)
      continue;
    if (objectp(t))
      ob = t;
    else
      ob = clone_object(t);
    ob->Set(P_NOSELL, "This item does not represent any value.");
    ob->Set(P_NO_QUITDROP, 1);
    if (mappingp(equip[things[i], RDE_PROPS]))
    {
      ids = m_indices(equip[things[i], RDE_PROPS]);
      for (j = sizeof(ids); j--; )
        ob->Set(ids[j], funcall(equip[things[i], RDE_PROPS][ids[j]], pl));
    }
    if (ME_OK == ({int})ob->move(pl, M_SILENT))
      given += ({ ob });
    else if (ME_OK == ({int})ob->move(environment(pl), M_SILENT))
      dropped += ({ ob });
    else
    {
      log_file("AUTOLOAD", ctime()+sprintf("  %O: Raceequipment %O\n"
                           "  Failed to move.\n", pl, ob));
      ob->remove();
    }
  }

  if (sizeof(given))
  {
    ids = map_objects(given, "Short") - ({ 0, "" });
    if (sizeof(ids))
      tell_object(pl, implode_list(ids, "You are given "));
  }
  if (sizeof(dropped))
  {
    ids = map_objects(dropped, "Short") - ({ 0, "" });
    if (sizeof(ids))
      tell_object(pl, implode_list(ids, "At your feet you find "));
  }
  return 0;
}

/*-------------------------------------------------------------------------*/

void SetAlign (int val) { racedata[RD_ALIGN] = val; }
void SetFood (int val) { racedata[RD_FOOD] = val; }
void SetDrink (int val) { racedata[RD_DRINK] = val; }
void SetAlc (int val) { racedata[RD_ALC] = val; }
void SetWeight (int val) { racedata[RD_WEIGHT] = val; }
void SetHands (mixed *val) { racedata[RD_HANDS] = val; }
void SetLegs (mixed *val) { racedata[RD_LEGS] = val; }
varargs void AddHand (string dsc, int wc, int nohand) {
  racedata[RD_HANDS] += ({ ({ dsc, !!nohand, wc }) });
}
varargs void AddLeg(string dsc, int wc, int noleg) {
  racedata[RD_LEGS] += ({ ({ dsc, !!noleg, wc }) });
}

void SetDef (mixed val) {
  if (!pointerp(val)) val = ({ val });
  racedata[RD_DEFENCES] = val;
}
void AddDef (mixed val) {
  if (!pointerp(val)) val = ({ val });
  racedata[RD_DEFENCES] += val;
}
void SetHome (string val) { racedata[RD_HOME] = val; }
void SetPortal (string val) { racedata[RD_PORTAL] = val; }
void SetLong (string val) { racedata[RD_LONG] = val; }
void SetStat (mapping val) { racedata[RD_STAT] = val; }
void AddStat (string key, mixed val) {
  racedata[RD_STAT] += ([ key: val ]);
}
void SetMaxStat (mapping val) { racedata[RD_MAXSTAT] = val; }
void AddMaxStat (string key, mixed val) {
  if (!mappingp(racedata[RD_MAXSTAT]))
    racedata[RD_MAXSTAT] = ([]);
  racedata[RD_MAXSTAT] += ([ key: val ]);
}
void SetAttr (mapping val) { racedata[RD_ATTR] = val; }
void AddAttr (string key, mixed val) {
  racedata[RD_ATTR] += ([ key: val ]);
}
void SetSize(int val) { racedata[RD_SIZE] = val; }

void SetDesc (string s) { racedesc = s; }
void ReadDesc (string s) { racedesc = read_file(s); }

void SetEquipment (mapping m) { racedata[RD_EQUIP] = m; }
#if __VERSION__ > "3.5.0"
varargs void AddEquipment( string key, mixed file, int level
                         , mapping props, string *|string alias)
#else
varargs void AddEquipment( string key, mixed file, int level
  , mapping props, mixed alias)
#endif
{
  racedata[RD_EQUIP][key,RDE_FILE]  = file;
  racedata[RD_EQUIP][key,RDE_LEVEL] = level;
  racedata[RD_EQUIP][key,RDE_PROPS] = mappingp(props) ? props : 0;
  if (alias)
    racedata[RD_EQUIP][key,RDE_ALIAS] = (pointerp(alias) ? alias : ({ alias })) + ({});
  else
    racedata[RD_EQUIP][key,RDE_ALIAS] = ({});
}

void SetPlural(string val) { racedata[RD_PLURAL] = val; }
void SetInfo(string str) {racedata[RD_INFO]=str;}
void ReadInfo(string str) {racedata[RD_INFO]=read_file(str);}
string RaceInfo() {return racedata[RD_INFO];}


/***************************************************************************/
