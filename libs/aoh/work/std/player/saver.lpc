/* Quick and dirty object to make the player safefiles correct. 
 * It reads a players savefile and patches the player object.
 */

#include <properties.h>
#include <attributes.h>

#define THIS this_object()
#define TI   this_interactive()
#define PREV previous_object()

//---------------------------------------------------------------------------

/* /std/living/attributes */

mixed *attra;

/* /std/living/life */

mixed corpse;
int level;
int hit_point;
int spell_points;
int max_hp, max_sp;
int experience;
int ghost;
int invis;
int whimpy;
int alignment;
int gender;
string race;
int ivision, uvision;
mixed msgout;
mixed msgin;
mixed mmsgout;
mixed mmsgin;
int soaked;
int stuffed;
int intoxicated;
int max_alcohol;
int max_drink;
int max_food;

/* /std/player */

string home;

//---------------------------------------------------------------------------

void create() {
  if (!is_clone(THIS))
    return;
  seteuid(getuid(THIS));
}

void clean_up(int ref) {
  destruct(THIS);
}

void remove() {
  destruct(THIS);
}

//---------------------------------------------------------------------------

int convert_savefile(string name) 

// Convert the savefile for player <name> which must be the interactive.
// Results:
//   -1: The player is a new one.
//    0: Conversion failed.
//    1: Conversion succeeded, nothing needed to be converted.
//    2: Conversion succeeded, at least one attribute was converted.

{
  int newflag, rc, i, j;
  string tmp;

  call_out("remove", 5);
    
  if (!stringp(name) || getuid(TI) != ROOTID || getuid(PREV) != name
      || !is_clone(THIS)
     )
  {
    log_file("CONVERTED", sprintf("%s: %O->%O::convert(%O) by %O\n"
            , ctime(), PREV, THIS, name, TI));
    return 0;
  }
  rc = -1;

  if (catch(newflag = !restore_object("/"+SAVEPATH+name[0..0]+"/"+name)))
    return 0;
  if (newflag)
    return rc;

#define AVAL(attr,var) PREV->SetAttr(attr, var)
#define PVAL(attr,var) PREV->Set(attr, var)

  rc = 1;

  // std/living/attributes
  if (pointerp(attra))
  {
    TI->SetAttributes(mkmapping(attra[0], attra[1]));
    attra = 0;
    rc = 2;
  }

  if (ghost)
  {
    rc = 2;
    PVAL(P_GHOST, ghost);
  }

  if (corpse)
  {
    rc = 2;

    // std/living/body
    AVAL(A_CORPSE, corpse);
    AVAL(A_HP, hit_point);
    AVAL(A_SP, spell_points);
    AVAL(A_MAX_HP, max_hp);
    AVAL(A_MAX_SP, max_sp);
    AVAL(A_XP, experience);
    AVAL(A_WIMPY, whimpy);
    AVAL(A_DRINK, soaked);
    AVAL(A_FOOD, stuffed);
    AVAL(A_ALCOHOL, intoxicated);
    AVAL(A_MAX_ALCOHOL, max_alcohol);
    AVAL(A_MAX_DRINK, max_drink);
    AVAL(A_MAX_FOOD, max_food);

    // std/living/description
    AVAL(A_LEVEL, level);
    AVAL(A_INVIS, invis);
    AVAL(A_ALIGN, alignment);
    AVAL(A_GENDER, gender);
    AVAL(A_RACE, race);
    AVAL(A_IVISION, ivision);
    AVAL(A_UVISION, uvision);
    AVAL(A_MSGOUT, msgout);
    AVAL(A_MSGIN, msgin);
    AVAL(A_MMSGOUT, mmsgout);
    AVAL(A_MMSGIN, mmsgin);
  }

  if (!TI->QueryAttr(A_MAGIC_DEFENCE))
  {
    AVAL(A_MAGIC_DEFENCE, TI->QueryAttr("MagicDefense"));
    TI->RemoveAttr("MagicDefense");
    rc = 2;
  }
    
  // /std/player
  tmp = "/d/halfling/common/hobbiton/";
  if (home[0..strlen(tmp)-1] == tmp)
  {
    PVAL(P_HOME, "/d/halfling/common/room/hobbiton/"+home[strlen(tmp)..]);
    rc = 2;
  }
    
  if (rc > 1)
    log_file("CONVERTED", sprintf("%s: %s\n", ctime(), name));

#undef AVAL
#undef PVAL

  return rc;
}

//---------------------------------------------------------------------------
