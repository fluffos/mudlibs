/* /obj/tent
**
** A simple portable 'hotel'.
** Code and command parsing is quite crufty...
** Note that the blueprint is the 'home' for players logging in.a
**
** 21-Feb-94 [Mateese]
** 01-Mar-94 [Mateese] P_TPORT is now piped through.
*/

#include <properties.h>
#include <moving.h>
#include <rooms.h>

inherit "/std/container";

#define TP this_player()
#define THIS this_object()
#define ENV environment

#define TENT  "/obj/tent"
#define TENTKEY  "/obj/tentkey"

nosave int blueprint;
nosave int buildup;
nosave int be_opaque;

/*-------------------------------------------------------------------------
** Initialize us.
*/

varargs void create () {
  ::create();
  // Short/Longs are builtin.
  SetValue(15000);
  SetWeight(3000);
  SetMaxWeight (203000);
  AddId("tent");
  SetTransparent(500);
  buildup = 0;
  be_opaque = 0;
  blueprint = member(object_name(THIS), '#') == -1;
  seteuid(getuid(THIS));
  Set(P_HELP_MSG, "Read the manual printed on the packs side.\n");
}

/*-------------------------------------------------------------------------*/

varargs string QueryShort() {
  if (buildup) return "a tent";
  return "a packed tent";
}

varargs string QueryIntShort() {
  return "inside a tent";
}

varargs string QueryLong() {
  if (buildup)
    return
 "The tent is a typical, green colored adventurer's tent, big enough to\n"
+"hold one person and its belongings.\n";
  return
 "This is a packed adventurer's tent, which, when put up, could give\n"
+"shelter for one person and its belongings.\n"
+"There is a manual printed on the packs side.\n";
}

varargs string QueryIntLong() {
  if (blueprint)
    return "Slowly you wake up after a long refreshing sleep..\n";

  return
 "There is not much room inside the tent, and the light is dim green,\n"
+"but the floor plane is cosy warm and there is enough place to relax.\n";
}

// Be opaque for looks.

int SetOpaque(int i) { return be_opaque = i; }
int QueryOpaque() { return be_opaque; }

// Remember if packed or not.

int SetBuildup(int i) { return buildup = i; }
int QueryBuildup() { return buildup; }

int QueryTransparent() {
  if (   be_opaque
      || TP && member(({"look", "exa", "l"}), query_verb()) != -1) {
    if (be_opaque)
      be_opaque = 0;
    return 0;
  }
  return ::QueryTransparent();
}

// leave is not allowed for put/get/drop.

int prevent_leave (mixed dest, int method, mixed extra) {
  if (member(({M_PUT, M_DROP, M_GET, M_GIVE}), method) != -1) {
    write("You can't reach it.\n");
    return ME_NO_LEAVE;
  }
  return ME_NO_PREVENT;
}

int allow_enter(mixed method, mixed extra) {
  if (!buildup)
    return ME_TOO_HEAVY;
  return ::allow_enter(method, extra);
}

void notify_enter (object oldenv, mixed method, mixed extra) {
  if (member(({M_GO, M_TELEPORT, M_SPECIAL, M_SILENT}), method) != -1)
    be_opaque = 1;
  return ::notify_enter(oldenv, method, extra);
}

// The P_TPORT of the environment must be piped through

int QueryTPort() {
  if (!buildup || !ENV())
    return TPORT_NO;
  return ENV()->Query(P_TPORT);
}

// Be autoloading.

mixed QueryAutoObject() {
  return 1;
}

// Don't clean up.

varargs int clean_up(int i) { return !blueprint; }

// On remove, also remove the sleeper in here.

varargs int remove() {
  string name;
  if (name = Query("TentIsUsed")) {
    map_objects(filter_objects(all_inventory(THIS), "id", name), "remove");
    Set("TentIsUsed", 0);
  }
  return ::remove();
}

/*-------------------------------------------------------------------------*/

void init () {
  container::init();
  add_action("flook", "look");
  add_action("flook", "l");
  add_action("fenter", "enter");
  add_action("fleave", "leave");
  add_action("fsleep", "sleep");
  add_action("fbuild", "put");
  add_action("fbuild", "build");
  add_action("fbuild", "pack");
  add_action("fbuild", "unpack");
  add_action("fread", "read");
}

/*-------------------------------------------------------------------------
** Look into or out of the tent.
*/

int flook (string arg) {
  int i;
  string str;
  object *inv;

  if (!arg || !ENV(THIS)) return 0;

  if ((   sscanf(arg, "into %s", str) == 1
        || sscanf(arg, "in %s", str) == 1
        || sscanf(arg, "inside %s", str) == 1
      )
      && present(str, ENV(TP)) == THIS
     )
  {
    if (!buildup) {
      notify_fail("You can't look inside a packed tent.\n");
      return 0;
    }
    i = TP->CantSee(THIS);
    if (i < 0)
      write("You see nothing, it's too dark inside.\n");
    else if (i > 0)
      write("Blinded you close your eyes.\n");
    else {
      write(QueryIntLong());
      inv = all_inventory(THIS);
      if (sizeof(inv))
        write("You also see:\n"
              +implode(map_objects(inv, "QueryShort"), "\n")+"\n");
      return 1;
    }
  }

  if ((    sscanf(arg, "out of %s", str) == 1
        || sscanf(arg, "out %s", str) == 1
        || (arg == "outside" && (str = "tent"))
      )
      && id(str)
      && ENV(TP) == THIS
     )
  {
    i = TP->CantSee(ENV(THIS));
    if (!ENV(THIS)->Query("Indoors"))
      write(ENV(THIS)->Query("DayDescr"));
    write(ENV(THIS)->QueryIntLong()||"Nothing special to see.\n");
    write(ENV(THIS)->GetExits()||"");
    write(ENV(THIS)->GetDoors()||"");
    inv = all_inventory(ENV(THIS));
    if (sizeof(inv) > 1) {
      inv -= ({ THIS });
      write(implode(map_objects(inv, "QueryShort"), "\n")+"\n");
    }
    return 1;
  }

  return 0;
}

/*-------------------------------------------------------------------------
** Print out the manual for the tent.
*/

int fread (string arg) {
  if (!arg || member(({"manual", "tent"}), arg) == -1)
    return 0;

  write(
 "Congratulations for purchasing the newest model of\n\n"
+"                Adventurer's Tent\n\n"
+"This tent will accompany you in all situations and provide you with\n"
+"a comfortable retreat from the weirdnesses of life.\n"
+"To build the tent, drop the pack and put it up. Likewise, you can\n"
+"pack the tent back together to carry it away.\n"
+"If you sleep in your tent, you will wake up at that place again, but\n"
+"you may be missing some of your properties (thieves are everywhere!).\n"
       );
  return 1;
}

/*-------------------------------------------------------------------------
** Build or unbuild the tent.
*/

int fbuild (string arg) {
  int up;
  string str;

  if (!arg || ENV(THIS) != ENV(TP))
    return 0;

  switch (query_verb()) {
  case "put":
    if (   arg == "up"
        || (sscanf(arg, "up %s", str) == 1 && present(str, ENV(TP)) == THIS)
       )
      up = 1;
    else if (   arg == "down"
             || (sscanf(arg, "down %s", str) == 1
                 && present(str, ENV(TP)) == THIS)
            )
      up = 0;
    else
      return 0;
    break;
  case "build":
    if (present(arg, ENV(TP)) != THIS)
      return 0;
    up = 1;
    break;
  case "pack":
    if (present(arg, ENV(TP)) != THIS)
      return 0;
    up = 0;
    break;
  case "unpack":
    if (present(arg, ENV(TP)) != THIS)
      return 0;
    up = 1;
    break;
  default:
    return 0;
  }

  if (!up) {
    if (!buildup) {
      notify_fail("It is already packed.\n");
      return 0;
    }
    if (ENV(TP) == THIS) {
      notify_fail("You're still in it!\n");
      return 0;
    }
    if (sizeof(all_inventory(THIS))) {
      notify_fail("It must be empty to be packable.\n");
      return 0;
    }
    buildup = 0;
    write("You put down the tent and pack it.\n");
    show(TP->QueryName()+" puts down a tent and makes a nice pack of it.\n");
    return 1;
  }

  if (buildup) {
    notify_fail("It is already put up.\n");
    return 0;
  }

  // Catch cloned rooms
  if (member(object_name(ENV(TP)), '#') != -1) {
    write("You don't dare to put up your tent here - it is much to unsecure.\n");
    return 1;
  }

  buildup = 1;

  write("After a few minutes of work, you put up a nice tent.\n");
  show(TP->QueryName()+" fiddles with planes, sticks and ropes and finally "
       +"puts up a nice tent.\n");
  return 1;
}

/*-------------------------------------------------------------------------
** Enter the tent
*/

int fenter (string arg) {
  if (!arg || present(arg, ENV(TP)) != THIS)
    return 0;

  if (!buildup) {
    notify_fail("You can't enter a packed tent.\n");
    return 0;
  }

  if (TP->move(THIS, M_SPECIAL, ({"leaves into a tent", "enters from outside", "enter the tent"})) != ME_OK)
  {
    notify_fail("You fail to enter the tent.\n");
    return 0;
  }
  show_room(THIS, TP->QueryName()+" enters from outside.\n", ({ TP }));
  return 1;
}

/*-------------------------------------------------------------------------
** Leave the tent
*/

int fleave (string arg) {
  if (arg && !id(arg))
    return 0;

  if (TP->move(ENV(THIS), M_SPECIAL, ({"leaves the tent", "emerges from a tent", "leave the tent"})) != ME_OK)
  {
    notify_fail("You fail to leave the tent.\n");
    return 0;
  }
  show_room(THIS, TP->QueryName()+" leaves the tent.\n");
  return 1;
}

/*-------------------------------------------------------------------------
** Sleep and quit.
*/

int fsleep (string arg) {
  object key, body, *inv;

  if (arg || ENV(TP) != THIS)
    return 0;

  if (Query("TentIsUsed")) {
    write("There is not enough room for more than one sleeper here.\n");
    return 1;
  }
  key = clone_object(TENTKEY);
  key->move(TP);
  key->Setup(THIS, TP);
  inv = all_inventory(THIS)-({TP});
  body = clone_object("/std/thing");
  body->Set("Name", TP->QueryName());
  body->Set("Weight", TP->QueryWeight()-TP->QueryWeightContents());
  body->Set("Short", TP->QueryName()+", deep asleep");
  body->Set("Long",
 "This is "+TP->QueryName()+" "+TP->QueryName()+" "+TP->QueryTitle()
+", obviously asleep.\n"
               );
  body->AddId(TP->QueryName());
  body->AddId("body");
  Set("TentIsUsed", TP->QueryName());
  write(
"As you lie down and close your eyes, your conscience quickly fades away...\n"
       );
  say(TP->QueryName()+" lies down and closes "+TP->QueryObjective()+" eyes.\n"
      "Soon you hear the regular breath of a person deeply asleep.\n");
  TP->SetHome(TENT);
  TP->quit();
  body->move(THIS);
  return 1;
}

/*************************************************************************/
