/* The "Restaurant in the Middle of Nowhere"
 * former "Restaurant at the End of the Universum"
 * first suggested by Terminator
 * brought into existence by Organimedes (with the aid of Pepel)
 * THIS OBJECT SHOULD EXIST ONLY ONCE IN THE GAME!
 * TODO: Keep this? If not, move Douglas swhere else and update /sys/stdrooms.h
 */
inherit "/room/pub";
#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include <stdrooms.h>

#undef DISABLE_GIVE

#define P_RITMON	"RitMoN"
#define P_RITMON_ND	"RitMoN_ND"
#define SEPAREE         "/room/restseparee"

string show_void(string window);
int leave(string str);

void PlayerNetdead(int dead)
{
  if (dead)
    previous_object()->Set(P_RITMON_ND, previous_object()->Query(P_RITMON));
  else
    previous_object()->Set(P_RITMON, previous_object()->Query(P_RITMON_ND));
}

varargs void create() {
    /* disable illegal use of object */
    if (object_name(this_object()) != RESTROOM) {
      log_file("ILLEGAL", ctime(time())
         +":illegal clone/inherit of /room/restroom in "
         +object_name(this_object())+" from "+getuid(this_interactive())
         +".\n");
      destruct(this_object());
      throw("illegal use of /room/restroom");
      /* this will produce an intended error */
    }

    pub::create();
    SetIntShort("The Restaurant in the Middle of Nowhere");
    SetIntLong(
"You have entered the Restaurant in the Middle of Nowhere (some prefer to\n"
"call it the Restaurant at the End of the Universe, after some story which\n"
"is famous in another world). Here you can meet people from all around\n"
"the World and share your experiences. Through the windows you can see the void.\n"
"From the east you hear strange murmur out of a separee.\n");
    Set(P_HELP_MSG,
"You can 'leave' the restaurant, back to the place you came from,\n"
"and you can 'show' another person an item in your inventory.\n"
#ifdef DISABLE_GIVE
"The commands 'get', 'give' and 'drop' are disabled.\n"
#endif
"To read the menu, type 'read menu'.\n"
       );
    AddDetail("barkeeper","The barkeeper seems to be used to all kinds of strangers.\n");
    AddDrink("Coke",0,0,40,0);
    AddDrink("Clausthaler",2,0,20,0);
    AddDrink("Pangalactic Gargle Blaster",202,0,1,0);
    AddDetail(({"window","windows"}), #'show_void);
    AddExit("leave",#'leave);
    AddRoomCmd("show","fshow");
    AddExit("east", SEPAREE);
#ifdef DISABLE_GIVE
    AddRoomCmd("give","disable");
    AddRoomCmd("drop","disable");
    AddRoomCmd("get","disable");
#endif
    SetMenuStr(
"Since this is a restaurant for ALL, there is no discount for certain groups.\n");
  Set(P_TPORT, TPORT_IN);
    AddItem("/std/board",REFRESH_HOME,
      ([P_SHORT:"The Central Player Board",
  P_LONG: "This is the Central Player Board of " MUDNAME ".\n"
            "It carries the group 'players' and some other important stuff.\n",
  P_ADS: ({"wooden","bulletin","old"}),
   "Groups": ({"players","ideas.theme","ideas.newbie","ideas.general"}),
      ]));
}

int fshow(string str) {
    string plname, obname;
    object pl, ob;

    if (!str || "?" == str) {
        write("If you want to show an object to somebody  : show [obj] to [person] \n"
              "If you want to show an object to all guests: show [obj]\n");
        return 1;
    }

    if (sscanf(str,"%s to %s",obname,plname) != 2) {
      obname = str; plname = "all";
    }

    if (!(ob = present(obname,this_player()))) {
  write("But you don't have "+obname+".\n");
  return 1;
    }

    if (plname == "all") {
        write("You show "+({string})ob->QueryShort()+" around.\n");
  say(({string})this_player()->QueryName()+" shows "+({string})ob->QueryShort()
      +" around. You see:\n");
        say(({string})ob->QueryLong());
        write("The barkeeper doesn't seem to be very impressed.\n");
        return 1;
    }

    plname = lower_case(plname);
    if (plname == "barkeeper") {
  write("You show "+({string})ob->QueryShort()+" to the barkeeper.\n");
  say(({string})this_player()->QueryName()+" shows "+({string})ob->QueryShort()+
      " to the barkeeper.\n");
        write("The barkeeper doesn't seem to be very impressed.\n");
  return 1;
    }
    pl = present(plname,this_object());
    if (!pl) {
  write("But "+plname+" isn't here!\n");
  return 1;
    }
    if (!living(pl)) {
  write("It doesn't make sense to show "+({string})ob->QueryShort()+
        " to a non-living object, does it?\n");
  return 1;
    }

    write("You show "+({string})ob->QueryShort()+" to "+({string})pl->QueryName()+".\n");
    say(({string})this_player()->QueryName()+" shows "+({string})ob->QueryShort()+" to "+
  ({string})pl->QueryName()+".\n",pl);
    tell_object(pl,({string})this_player()->QueryName()+" shows "+({string})ob->QueryShort()+
  " to you. You see:\n");
    tell_object(pl,({string})ob->QueryLong());
    return 1;
}

/*
 * Another gimmick function shows the void
 */
string show_void(string window) {
    object ob, *inv;
    string s, sh;
    int i;
    s =
"Outside the "+window+" you can see the void. This is where\n"
"wizards arrive when their experiments have failed.\n";

    call_other(VOID,"???");

    /* inventory of void */
    ob = find_object(VOID);
    if (ob && (inv = all_inventory(ob)) && sizeof(inv)) {
      s += "You see:\n";
      for (i = 0; i < sizeof(inv); i++)
  if (sh = ({string})inv[i]->QueryShort())
          s += "  "+capitalize(sh+"\n");
    }
    else s += "But currently there is nothing to see.\n";
    return s;
}

#ifdef DISABLE_GIVE
/*
 * disabling commands
 */
int disable(string str) {
    write("Sorry, but this command is disabled here.\n");
    return 1;
}
#endif

/*
 * This one is called if someone wants to leave the restaurant
 */
int leave(string str) {

  if (str) {       /* probably wanted to call another object */
    notify_fail("Just type 'leave' to return to the place where you came from.\n");
    return 0;
  }

  this_player()->move(   ({string})this_player()->Query(P_RITMON)
    || ({string})this_player()->QueryHome()
    || STARTROOM, M_GO, "the Restaurant in the Middle of Nowhere");
  if (find_call_out("clean") == -1)
    call_out("clean", 20);
  return 1;
}

/* notify_enter() is called for every thing that is moved into us.
 * It is a builtin function in /std/thing/moving. We just overload it.
 */
void notify_enter(mixed oldenv, int method, mixed extra) {
  mixed s;

  switch(method) {
    case M_GO:
    case M_TELEPORT:
    case M_SPECIAL:
  /* for players and monsters store their point-of-return as
   * property (suggested by Pepel).
   * take special care for dynamic roms, we won't be able to
   * return to those after they are cleanup()ed. For dynamic rooms
   * we store the objectpointer, so it will automagically be 0
   * after cleanup. Non-dynamic rooms (i.e. the normal case) can
   * be reloaded after cleanup(), so we store the object_name.
   */
      if (living(previous_object())
          && (s = objectp(oldenv) ? object_name(oldenv) : oldenv) != SEPAREE)
      {
        if (sizeof(explode(s, "#")) < 2)
          previous_object()->Set(P_RITMON, s); /* not a dynamic room */
        else
          previous_object()->Set(P_RITMON, find_object(s));
      }
    }
    pub::notify_enter(oldenv, method, extra);
}

/*
 * clean up the restaurant:
 * all non-living objects are destructed
 */
void clean() {
  int    i, n;
  object ob, oldob;

  ::reset();
  tell_room(this_object(),"The barkeeper sweeps the floor.\n");

    /* destruct non-livings, keep the board */
  ob = first_inventory(this_object());
  while (ob) {
    oldob = ob;
    ob    = next_inventory(oldob);
    if (!living(oldob) && !({int})oldob->id("board"))
      oldob->remove();
  }
}

void reset() {
  ::reset();
  clean();
}
