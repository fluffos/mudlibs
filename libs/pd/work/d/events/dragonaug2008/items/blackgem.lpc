
#include <std.h>
#include <dragonevent.h>

inherit DRAG_ITEMS+"geminherit";

int query_charged();

int chargelevel = 0;
// it has to be charged in these rooms, in this order
string *chargerooms = ({
  DRAG_ROOMS+"dragnorth37",
  DRAG_ROOMS+"dragnorth39",
  DRAG_ROOMS+"bluelake",
  DRAG_ROOMS+"whitecave",
});

void create() {
  ::create();
  set_id( ({ "gem", "black gem", "dragon_event_gem_black" }) );
  set_short("a %^BOLD%^%^BLACK%^black%^RESET%^ gem");
  set_long("%^BOLD%^%^BLACK%^This gem is a dull black color. It seems to absorb the light.%^RESET%^");
  chargelevel = 0;
}

void init() {
  ::init();
  add_action("do_charge", ({ "recharge", "imbue", "fill", "charge" }));
}

int do_charge(string str) {
  object tp = this_player();
  object to = this_object();
  object env = environment(tp);
  int idx;
  string msg;

  if (!str || present(str, tp) != to) return 0;

  if (query_charged())
    return notify_fail("You try to recharge the gem, but it seems to be full.\n");

  if (chargelevel < 0)
    return notify_fail("The gem suddenly changes colors very rapidly.\n");

  if (!env || (idx = member_array(base_name(env), chargerooms)) == -1 ||
      idx < chargelevel)
        return notify_fail("The gem refuses to recharge here.\n");

  if (base_name(env) != chargerooms[chargelevel] ||
      (DRAG_D->query_data("canchargegem") != 1 ||
       DRAG_D->query_data("winnergemogrekilled") == tp->query_name()) )
    return notify_fail("The gem begins to recharge, but something prevents it.\n");

  if (tp->query_mp() < 200)
    return notify_fail("The gem tugs at your magical power, "
      "but there is not enough to feed it.\n");
  msg = "The gem drains some of your magic to recharge itself.";

  message("magic", "%^BOLD%^%^BLACK%^Darkness fills the room.%^RESET%^", env);
  message("magic", "%^BOLD%^%^BLACK%^"+msg+"%^RESET%^", tp);
  tp->add_mp(-(100+random(tp->query_mp()/2)));
  chargelevel++;

  if (query_charged() && DRAG_D->query_data("canchargegem") == 1) {
    DRAG_D->set_data("winnerchargedgem", tp->query_name());
    DRAG_D->set_data("canchargegem", 0);
    message("info", "%^BOLD%^%^WHITE%^The gem suddenly brightens "
      "and begins to glow.%^RESET%^", env);
    message("info", "A powerful magic takes hold of your mind and strengthens it.", tp);
    tp->set_stats("intelligence", tp->query_base_stats("intelligence")+4);
    tp->set_stats("wisdom", tp->query_base_stats("wisdom")+2);
    tp->add_experience(500000);
  }
  else
    tp->set_paralyzed(2, msg);

  return 1;
}

int query_charged() { return chargelevel >= sizeof(chargerooms); }

