/* Death Room
**
** Make death such boring that players learn to avoid it.
** The player now returns to the place where it died.
**
**   26-Aug-92 [m] Adapted for native.
**   25-Nov-93 [p] combine_strings
**   18-May-94 [h] rewrite of functions
**   28-May-94 [l] Small bugfix. Also changed text to give "SHE" for females.
**                 Reformatted some lines to max 80 chars.
**   07-Seb-94 [m] Wizards are expelled from the room.
**   20-Jan-95 [p] Use preprocessor string concatenation instead of line
**                 continuations. Make player mapping private. Use closure.
**   09-Dec-95 [m] Wizards with P_NOWIZ set may die normally.
**   01-Jan-96 [m] Some details added.
**   16-Apr-97 [t] Players who already died before will get an own death-
**                 scene.
**
**  [m] Mateese
**  [p] Pepel
**  [h] Hyp
**  [l] Loco
**  [t] Thragor
*/

#include <properties.h>
#include <moving.h>
#include <rooms.h>
#include <secure/wizlevels.h>
#include <stdrooms.h>

inherit "/std/room";
inherit "/lib/string";

#define TP           this_player()
#define TO           this_object()
#define P_LARS       "CanseeLars"
#define P_CELLAR     "LocationCellar"
#define P_SCENE      "DeathScene"
#define SF(x) #'x //' Emacs-Hack

private void Write(object pl,string text)
{
  tell_object(pl,"\n"+text);
}

private void Speak(object pl,string text)
{
  tell_object(pl,wrap("\nDeath says: "+text,0,3));
}

private string Gender(object who,string neuter,string male,string female)
{
  int gen;
  if (   !who
      || (gen = ({int})who->QueryGender()<0)
      || gen>2
      || gen==GENDER_NEUTER
     )
    return neuter;
  return gen==GENDER_MALE?male:female;
}

private string block(string what)
{
  string *letters;
  letters = map(explode(what,""),SF(capitalize));
  return implode(letters,"");
}

public int cmd_filter(string str)
{
  switch (query_verb())
    {
    default:
      Speak(TP,"THAT IS NOT POSSIBLE IN YOUR IMMATERIAL STATE!\n");
      return 1;
    case "quit":
      Speak(TP,"YOU MAY QUIT NOW, BUT I WILL GET YOU NEXT TIME!\n");
    /* FALL THROUGH */
    case "exa":
    case "l":
    case "look":
    case "take":
    case "typo":
    case "bug":
    case "idea":
      break;
    }
}

private void send_home(object who)
{
  object dmark;
  mixed place;
  int notplace,rc;

  while (dmark = present("death_mark", who))
    {
      place = ({mixed})dmark->QueryPlace();
      dmark->remove();
      if (dmark) destruct(dmark);
    }
  notplace = 0;
  if (!place || !(({int})place->QueryTPort() & TPORT_IN))
    {
      notplace = 1;
      place = ({mixed})who->QueryHome() || STARTROOM;
    }
  SetTPort(TPORT_OUT);
  if (catch(rc = ({int})who->move(place, M_SILENT)) || rc != ME_OK)
    {
      notplace = 1;
      who->move(STARTROOM, M_SILENT);
    }
  if (!notplace)
    Write(who,
    "The shape on the ground seems familiar to you ... very "
    "familiar...\n\n");
  else
    Write(who,
    "There is NO familiar looking shape on the ground...\n\n"
    "But the environment looks familiar to you. Home sweet home.\n");
  SetTPort(TPORT_NO);
}

private void AlignMsg(object who)
{
  switch (({int})who->QueryAlign())
    {
    case -10000..-1000:
      Speak(who,
      "YOUR SINS ARE AS MANY AS THE GRAINS OF SAND IN THE DESERT. "
      "MAYBE YOU'RE WORSE A MONSTER THAN I! HAHAHAHAHA!\n");
      break;
    case -999..-500:
      Speak(who,
      "OH WHAT A DESPISABLE BUG WE HAVE HERE. STEALING CANDY FROM "
      "BABIES AND BEATING OLD LADIES NO DOUBT. WELL NOW THEY CAN "
      "DANCE ON YOUR GRAVE. HAHAHA!\n");
      break;
    case -499..-200:
      Speak(who,
      "HAVE YOU EVER BEEN TOLD ABOUT REPENTANCE AND ATONEMENT? "
      "NO?\n");
      Speak(who,
      "DIDN'T THINK SO EITHER. YOU WILL BE TOLD NOW HOWEVER, FOR "
      "ETERNITY! HAHAHA!\n");
      break;
    case -199..-1:
      Speak(who,
      "SHAME ON YOU MORTAL ONE! STEALING AND KILLING, IS THAT ALL "
      "YOU CAN THINK OF? WELL NOW YOU WILL BE GIVEN TIME TO REGRET "
      "YOUR DEEDS. FOR EVER, HAHA!\n");
      break;
    case 0:
      Speak(who,
      "WHAT A FENCE-CLIMBER WE HAVE HERE! NEVER MADE UP YOUR MIND "
      "IN ALL YOUR LIFE, DID YOU? WELL, DON'T WORRY. YOU WON'T HAVE "
      "TO NOW EITHER! HAHAHA!\n");
      break;
    case 1..199:
      Speak(who,
      "OH WHAT A NICE FELLOW WE HAVE HERE. ALWAYS WALKING THE NARROW "
      "ROAD, DID YOU? WELL, YOU'LL NEVER KNOW WHAT THE OTHER ROAD IS "
      "LIKE NOW! HAHAHA!\n");
      break;
    case 200..499:
      Speak(who,
      "NEVER SAID A DIRTY WORD IN YOUR LIFE DID YOU? WELL, IT'S TOO "
      "LATE TO CHANGE YOUR MIND ABOUT THAT NOW. HAHAHA! NO MR. "
      "NICE-GUY YOU ARE WHAT YOU WERE. HAHAHA!\n");
      break;
    case 500..999:
      Speak(who,
      "I HEARD THEY WERE OUT OF ARCHANGELS IN HEAVEN. PERHAPS YOU "
      "SHOULD APPLY FOR THE JOB? I HOPE YOU KNOW HOW TO PLAY THE "
      "HARP, OR THEY'LL GIVE THE JOB TO SOMEONE ELSE! HAHAHA!\n");
      break;
    case 1000..10000:
      Speak(who,
      "TRYING TO TAKE THE JOB AWAY FROM GOD, ARE YOU? HAHAHA! LET "
      "ME TELL YOU A BIT ABOUT IT BEFORE YOU SIGN ANY PAPERS THOUGH. "
      "BAD HOURS AND NO VACATION. BELIEVE ME, YOU DON'T WANT IT!\n");
      break;
    }
}

private void scene0(object who,int waiting)
{
  switch(waiting)
    {
    case 4:
      // Time to read: 18s = 9 hb
      Speak(who,"LOOKS LIKE YOU DIED.\n");
      Write(who,
      "Death smiles happily.\n");
      break;
    case 8:
      // Time to read: 10s = 5 hb
      Speak(who,"SUCKS TO BE YOU!\n");
      Write(who,
      "Raistlin, Mateese, Tune, Softbyte, Eilan, Sonic, Superj, "
            "MagicTCS, Gorthaur and Mica all magically appear.  They "
            "point at you and start giggling. \n");
      break;
    case 12:
      // Time to read: 4s = 2 hb
      Speak(who,"HOPE TO SEE YOU AGAIN SOON.  HAVE A NICE DAY. \n");

      Write(who,
      "Death laughs at you and does some mystical mumbo jumbo. "
            "You feel a lot better.\n");
      send_home(who);
  }
}
/* I could change this so that its a different message next time */
private void scene1(object who,int waiting)
{
  switch(waiting)
    {
    case 4:
      // Time to read: 18s = 9 hb
      Speak(who,"NICE TO SEE YOU AGAIN.\n");
      Write(who,
      "Death smiles happily.  Its good to see he's still "
            "a happy camper.\n");
      break;
    case 8:
      // Time to read: 10s = 5 hb
      Speak(who,"I GOTTA GO SOON, A LOT OF DEATHS TODAY.\n");
      Write(who,
      "You manage a weak smile, not wanting to hold up "
            "Death's busy appointment schedule.\n");
      break;
    case 12:
      // Time to read: 4s = 2 hb
      Speak(who,"I'LL TAKE YOUR SOUL SOME OTHER TIME, EH? \n");

      Write(who,
      "Death does the usually mystical mumbo jumbo and you "
            "feel a whole lot better.\n");
      send_home(who);
  }
}
/* and again */
private void scene2(object who,int waiting)
{
  switch(waiting)
    {
    case 4:
      // Time to read: 18s = 9 hb
      Speak(who,"HEY YOU!\n");
      Write(who,
      "Death always seems so happy to see visitors.\n");
      break;
    case 8:
      // Time to read: 10s = 5 hb
      Speak(who,"YOUR SKULL WOULD MAKE A NICE CONVERSATION PIECE FOR MY "
                "COFFEE  TABLE.\n");
      Write(who,
      "You didn't realize Death drank coffee.  \n");
      break;
        case 12:
      // Time to read: 4s = 2 hb
      Speak(who,"JUST KIDDING.  MY WIFE HATES WHEN I BRING WORK HOME WITH ME. \n");
      Write(who,
      "Death giggles inanely.  He waves at you happily and a bluish "
            "glow leaves his fingertips.  You feel better.\n");
      send_home(who);
  }
}

private void death_messages(object who)
{
  int scene;
  if (!who||environment(who)!=this_object())
    // Don't talk to someone who is not here.
    return;
  scene = ({int})who->Query(P_SCENE);
  scene++;
  who->Set(P_SCENE,scene);
  switch(({int})who->QueryKills())
    {
    case 1:
      scene0(who,scene);
      break;
    case 2:
      scene1(who,scene);
      break;
    default:
      scene2(who,scene);
      break;
    }
}

public void heart_beat()
{
  object *inv;
  inv = filter(all_inventory(),SF(interactive));
  if (!sizeof(inv))
    set_heart_beat(0);
  map(inv,SF(death_messages));
}

public void PlayerNetdead(int val)
{
  if (!val)
    set_heart_beat(1);
}

public varargs string QueryIntLong(mixed arg)
{
  int i;
  string rc;
  if (TP && ({string})TP->Query(P_CELLAR))
    rc = "You're in the cellar in front of the door labeled 'ETERNITY'.\n";
  else
    rc = (::QueryIntLong(arg));
  if (!arg && TP && ({string})TP->Query(P_LARS))
    return rc + "Lars The Implementor.\n";
  return rc;
}

public varargs void create()
{
  (::create());
  SetIntShort("Death's workroom");
  SetIntLong("A dark room lit with a dark light that seems to defy "
       "darkness not so much by actually illuminating the room as by"
       "being a darkpoint in less dark surroundings. In the strange "
       "light (dark?) you can see a centrally placed desk covered "
       "with books and diagrams. The walls are covered with "
       "bookshelves filled with dark tomes bound in leather that gleam "
       "with strange runes.\n\n");
  SetTPort(TPORT_NO);
  Set(P_CANSEE,1);
  SetMagicProtection(([ST_ALL:"You can't cast spells yet.\n"]));
  SetIndoors(1);

  AddDetail("desk",
      "The desk is made of old oak wood, majestetic in its appearance.\n"
     );
  AddDetail("books",
      "The books on the desk show the same strange runes as the tomes "
      "on the shelves.\n"
     );
  AddDetail("diagrams",
      "The diagrams cover a large part of the desk's surface. They are "
      "covered with circular lines and knots. You can't make any sense "
      "from them.\n"
     );
  AddDetail("tomes",
      "Old-looking books, bound in finest leather. Death must be quite "
      "rich to be able to afford such luxury. The covers gleam with "
      "strange runes.\n"
     );
  AddDetail("runes",
      "The runes appear old and powerful -- too bad you can't read "
      "them.\n"
     );
  AddDetail(({"shelves", "bookshelves", "walls" }),
      "The bookshelves use up most of the available wall space and are "
      "covered with old tomes.\n"
     );

  Set(P_HELP_MSG, "You are beyond any help.\n");
  AddItem("/room/death", REFRESH_REMOVE);
}

public void notify_leave(mixed to,int method,mixed extra)
{
  previous_object()->Set(P_SCENE,0);
  previous_object()->Set(P_LARS,0);
  previous_object()->Set(P_CELLAR,0);
}

public void init()
{
  object death;

  (::init());
  death = present("moot", TO);
  if (TP != death)
  {
    if (IS_IMMORTAL(TP) && !({int})TP->Query(P_NOWIZ))
    {
      Speak(TP,"WHAT ARE YOU DOING HERE? THE MORTALS SUFFERED ENOUGH, "
            "DIDN'T THEY?\n"
      );
      TP->move(TP->QueryHome(), M_TELEPORT);
    }
    else if (({int})TP->QueryGhost())
    {
      add_action("cmd_filter", "", 1);
      set_heart_beat(1);
    }
    else
    {
      Speak(TP,"WHAT ARE YOU DOING HERE? YOUR TIME HAS NOT COME YET. "
            "BEGONE!\n");
      TP->move(({string})TP->QueryHome(), M_TELEPORT);
    }
  }
}
