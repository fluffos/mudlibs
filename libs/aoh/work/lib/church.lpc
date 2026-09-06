/* This file is meant to be inherited by all churches in the mud.
 * it is NOT neccessary that it is allowed to pray or being resurrect
 * there, you don't have to use the functions, you can do it if you
 * need them.
 * What SHOULD be set in every case is a SetChurch() and a
 * ForbidEnter()
 *
 * [c] created on may13th1995
 *
 * [c] Cadra@Nightfall
 */

#include <moving.h>
#include <config.h>
#include <properties.h>
#include <search.h>

private nosave string deity;
private mixed appearmsg;
private nosave int align, church, sunglasses, torch;
private nosave mapping forbid;

public int SetChurch(int i) { return church=i; }
public int SetTorch(int i) { return torch = i; }
public int SetGlasses(int i) { return sunglasses = i; }
public int SetAlign(int alignment) { return align = alignment; }
public mixed SetPrayMsg(mixed message) { return appearmsg=message; }
public string SetDeity(string str) { return deity = str; }

public int QueryChurch() { return church; }
public int QueryTorch() { return torch; }
public int QueryGlasses() { return sunglasses; }
public int QueryAlign() { return align; }
public string QueryDeity() { return deity; }

public varargs void ForbidEnter(mixed whom, string reason) {
  int i;
  if (!reason) reason = "You are not allowed to enter that place.\n";
  if (!forbid) forbid = m_allocate(0,1);
  i = sizeof(whom-({0}));
  while (i--) forbid[lower_case(whom[i])] = reason;
}

public int allow_enter(int method, mixed extra) {
  object po;
  string race,guild,*idx,*id;
  po=previous_object();
  race = lower_case(({string})po->QueryRace() || "");
  guild = lower_case(({string})po->QueryGuild() || "");
  idx = m_indices(forbid||([]));
  if (sizeof(id = regexp(idx,"^"+race+"|^"+guild+
    "|^race:"+race+"|^guild:"+guild)))
    return notify_fail(
      forbid[id[0]],NOTIFY_NOT_VALID)&&ME_NO_MOVE;
  return ME_OK;
}

public int resurrect_me() {
  mixed msg;
  if (!this_player()) return 0;
  if (({string})this_player()->QueryRace()=="visitor") return notify_fail(
    "You need to get a real body from Dr. Frankenstein.\n");
  if (closurep(appearmsg)) msg = funcall(appearmsg);
    else msg = appearmsg;
  if (stringp(msg)) msg = ({msg,"appears in a solid form.\n"});
  if (({string})this_player()->QueryGhost()) {
    if (!pointerp(msg)) {
      write("You are sucked away by a mighty force.\n");
      show(capitalize(({string})this_player()->QueryName())+" appears in solid form.\n");
      }
     else {
       write("You "+msg[0]);
       show(capitalize(({string})this_player()->QueryName())+msg[1]);
       }
    this_player()->SetGhost(0);
    return 1;
    }
  write("You kneel down and praise the local gods.\n");
  show(capitalize(({string})this_player()->QueryName())+
    " kneels down and wholeheartedly praises the local gods.\n");
  return 1;
}

public int do_get(string str) {
  object obj;
  if (!this_player() || (!str)) return 0;
  if ((str=="glasses")||(str=="sunglasses")) {
    if (!sunglasses) return notify_fail(
      "There are no sunglasses to get.\n");
    write("You take some sun glasses.\n");
    obj=clone_object("/obj/sunglasses");
    obj->Set(P_NOBUY,1);
    if (({int})obj->move(this_player(),M_GET)!=ME_OK) {
      write("They are too heavy for you, so you drop them.\n");
      show(capitalize(({string})this_player()->QueryName())+
        " tries to take some sunglasses, but suddenly drops them.\n",
         this_player());
      }
    return 1;
    }
  if (str=="torch") {
    if (!torch) return notify_fail(
      "There's no torch to get.\n");
    if (!search(this_player(),"torch",SEARCH_INV_ENV|SM_OBJECT|SM_IGNLIGHT)) {
      write("You take a torch.\n");
      obj=clone_object("/obj/torch");
      obj->Set(P_NOBUY,1);
      if (({int})obj->move(this_player(),M_GET)!=ME_OK) {
        write("The torch is much too heavy for you - you drop it.\n");
        show(capitalize(({string})this_player()->QueryName())+
	  " tries to take a torch and drops it again.\n",this_player());
        }
      return 1;
      }
    }
  return 0;
}
