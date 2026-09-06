#include <battle.h>

int potency, max_potency, hp;
object victim;

string query_name() { return "shield_object"; }

void set_potency(int x) {
  if (x > 100)
    x = 100;
  potency = max_potency = x;
}
void set_hp(int x) { hp = x; }

void show_shield() {
  string color, buf;
  int x = (int)floor(7 * potency / max_potency);
  set_actor(victim);

  if (potency < -10) {
    remove_call_out("on_tick");
    call_out("on_tick",1);
    return;
  }

  debug("hp = "+hp+", potency = "+potency+", x = "+x, "combat");

  switch (x) {
    case 0: color = "~CDRKblack"; break;
    case 1: color = "violet"; break;
    case 2: color = "blue"; break;
    case 3: color = "green"; break;
    case 4: color = "yellow"; break;
    case 5: color = "orange"; break;
    case 6: color = "red"; break;
    default: buf = "The air around ~name flashes briefly and fades back into invisibility.";
  }
  if (color)
    buf = "The air around ~name pulses "+color+"~CBRT for a moment.";
  victim->msg_local("~CBRT"+buf+"~CDEF");
}

void protect(object who) {
  object ob;
  while (ob = present_clone("/magic/obj/shield_object", who)) {
    ob->set_hp(0);
    ob->on_tick();
  }
  debug("shield activated on "+who->query_cap_name()+" with "+hp+" hp and "+potency+"% potency","combat");
  victim = who;
  move_object(this_object(),who);
  call_out("on_tick",10);
}

void on_tick() {
  int op = potency;
  remove_call_out("on_tick");
  hp--;
  if (hp < 0) {
    if (potency > 0) {
      set_actor(this_player());
      victim->msg_local("~CBRTThere is a soft popping sound and the air around ~name stops shimmering.~CDEF");
    } else {
      victim->msg_local("~CBRTThere is a loud ~CTITcrack~CBRT as ~npos shield is broken!~CDEF");
    }
    msg_object(victim,"~CWRNYour magic shield has broken.~CDEF");
    destruct(this_object());
    return;
  }
  potency ++;
  if (potency > max_potency)
    potency = max_potency;
  if ((floor(potency / 7) != floor(op / 7)) ||
      (potency == max_potency && op != max_potency))
    show_shield();
  call_out("on_tick",10);
}

int on_damage(string type, int damage) {
  int mod = 4;
  if (type == "blunt" || type == "edged" || type == "piercing")
    mod = 6;
  else if (type == "electricity" || type == "fire" || type == "energy")
    mod = 2;
  debug( "In the shield object, damage is " + as_lpc(damage), "combat" );
  potency -= max( damage / mod, 1);
  hp -= damage; // shield takes all of the damage
  damage = potency * damage / 100;
  show_shield();
  return damage;
}

void on_death(object victim) {
   destruct( this_object() );
}
