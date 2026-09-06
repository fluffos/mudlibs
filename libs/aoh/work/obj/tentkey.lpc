/* /obj/tentkey
**
** The autoloading 'key' for players sleeping in a tent.
** Code and command parsing is quite crufty...
**
** 21-Feb-94 [Mateese]
*/

#include <secure/wizlevels.h>
#include <moving.h>
#include <stdrooms.h>

inherit "/std/thing";

#define TP this_player()
#define THIS this_object()
#define ENV environment

#define TENT  "/obj/tent"

nosave string envname, tentname, oldhome;

/*-------------------------------------------------------------------------
** Initialize us.
*/

varargs void create () {
  ::create();
  // Short/Longs are builtin.
  SetValue(0);
  SetWeight(0);
  AddId("tentkey");
  seteuid(getuid(THIS));
}

/*-------------------------------------------------------------------------*/

int id (string str) {
  if (!TP || !IS_IMMORTAL(TP))
    return 0;
  return ::id(str);
}

varargs string QueryShort() {
  if (!TP || !IS_IMMORTAL(TP))
    return 0;
  return "a tentkey (invisible)";
}

varargs string QueryLong() {
  if (!TP || !IS_IMMORTAL(TP))
    return 0;
  return
 "This is the autoloading keyobject for persons sleeping in a tent.\n";
}

/*-------------------------------------------------------------------------*/

void Setup(object tent, object player) {
  tentname = explode(object_name(tent), "#")[0];
  envname = explode(object_name(ENV(tent)), "#")[0];
  oldhome = player->QueryHome();
}

mixed QueryAutoObject() {
  if (tentname)
    return ({ tentname, envname, oldhome });
  return 0;
}

/*-------------------------------------------------------------------------*/
void SetAutoObject (mixed args) {
  object env, tent;
  object *inv;
  int i, newtent, ok;
  string defaulthome;

  if (IS_IMMORTAL(TP))
    defaulthome = STARTROOM;
  else 
    defaulthome = STARTROOM;
  TP->SetHome(defaulthome);

  ok = 0;
  while (pointerp(args) && sizeof(args) >= 3) {
    tentname = args[0];
    envname = args[1];
    oldhome = args[2];
    TP->SetHome(oldhome);
    if (catch(env = load_object(envname)))
      break;
    tent = 0;
    inv = filter_objects(all_inventory(env), "id", "tent");
    for (i = 0; i < sizeof(inv); i++)
      if (inv[i]->Query("TentIsUsed") == TP->QueryName()) {
        tent = inv[i];
        break;
      }
    if (!tent) {
      tent = clone_object(TENT);
      tent->SetBuildup(1);
      if (catch(i = tent->move(env)) || i != ME_OK)
        break;
      show_room(env, "You suddenly notice a tent standing here.\n");
      newtent = 1;
    }
    map_objects( filter_objects(all_inventory(tent), "id", TP->QueryName())
               , "remove");
    tent->Set("TentIsUsed", 0);
    if (catch(i = TP->move( tent
                          , M_SPECIAL
                          , ({ ""
                             , "opens "+TP->QueryObjective()+" eyes"
                             , "open your eyes and look around" 
                            })))
        || i != ME_OK)
      break;
    show_room(tent, TP->QueryName()+" opens "+TP->QueryObjective()
                    +" eyes and looks around.\n", ({ TP }));
    if (newtent)
      write("But this is not the same tent in which you fell asleep...\n");
    ok = 1;
    break;
  }

  if (!ok)
    if (catch(i = TP->move(oldhome||defaulthome, M_TELEPORT)) || i != ME_OK)
      TP->move(defaulthome, M_TELEPORT);

  // Success or failure: in both cases we are no longer needed
  call_out("remove", 1);
}

/*************************************************************************/
