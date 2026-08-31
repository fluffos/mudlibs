#include <std.h>

inherit ARMOUR;

int reading(string str);
void first(object tp);
void second(object tp);
void third(object tp);
void fourth(object tp);
void fifth(object tp);
void sixth(object tp);
void seventh(object tp);
void last(object tp);

void create() {
  ::create();

  set_name("crystal ring");
  set("id", ({ "ring", "crystal ring" }) );
  set("short", "%^BOLD%^%^WHITE%^C%^BLACK%^r%^WHITE%^y%^BLACK%^s%^WHITE%^t%^BLACK%^a%^WHITE%^l %^YELLOW%^ring%^RESET%^");
  set_property( "no steal", 1 );
  set("long", "The ring shimmers beautifully in even the faintest light.  The large crystal is mounted"
    " in a spiral of gold which forms the band of the ring.  It seems as if something has been inscribed on the band.");
  set_type("ring");
  set_ac(0);
  set_limbs( ({ "right hand" }) );
  set("read",(: reading :));
  set_weight(5);
  set("value", 0);
}

int bury() {
  write("You dare not destroy such a thing!");
  return 1;
}

int reading(string str) {
  this_player()->set_paralyzed(22, "You are in an unreal world, and do not know how to do that here.");
  write("As you look over the markings, they begin to glow faintly.");
  call_out("first", 2, this_player());
  return 1;
}

void first(object tp) {
  message("info","%^RESET%^You find yourself elsewhere, unaware of your previous world.\n\n%^CYAN%^A voice speaks to you...%^RESET%^",tp);
  call_out("second", 3, tp);
}

void second(object tp) {
  message("info","\n%^BOLD%^%^WHITE%^This ring has a history...\n\n%^BOLD%^%^RED%^One both of sorrow and of joy.%^RESET%^",tp);
  call_out("third", 3, tp);
}

void third(object tp) {
  message("info","\n%^BOLD%^%^BLUE%^The ring in your possession was not forged from any metal,\nNor brought up from the depths of any mine.%^RESET%^",tp);
  call_out("fourth", 2, tp);
}

void fourth(object tp) {
  message("info","\n%^BOLD%^%^WHITE%^It came to be out of the love for one person from another.  The beauty of this love shines through this diamond, although the diamond could never compare to love's true light.%^RESET%^",tp);
  call_out("fifth", 4, tp);
}

void fifth(object tp) {
  message("info","\n%^RESET%^%^ORANGE%^The gold of the ring symbolizes the value of love, and how sought after it is by every living being.%^RESET%^",tp);
  call_out("sixth", 2, tp);
}

void sixth(object tp) {
  message("info","\n%^RESET%^Love manifested itself into the form of this ring as a reminder...",tp);
  call_out("seventh", 4, tp);
}

void seventh(object tp) {
  message("info","\n%^BOLD%^%^WHITE%^Love brings people together.\n\nAnd when they have love, they can never be separated.",tp);
  call_out("last", 2, tp);
}

void last(object tp) {
  message("info","\n\n%^BOLD%^%^MAGENTA%^They will be together always.%^RESET%^\n\n\nYou finally find yourself back where you were.",tp);
}

int query_auto_load() {
  if(this_player()->query_cap_name() == "Wisp") return 1;
  return 0;
}
