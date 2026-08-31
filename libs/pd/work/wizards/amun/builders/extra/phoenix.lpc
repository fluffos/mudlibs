#include <std.h>

inherit MONSTER;

object tp = this_player();

void create() {
  ::create();
  set_name("phoenix");
  set("id", ({"phoenix"}) );
  set_short("%^YELLOW%^Ph%^MAGENTA%^oe%^RED%^ni%^RESET%^%^MAGENTA%^x");
  set_long("%^BOLD%^%^WHITE%^This %^YELLOW%^beaming%^WHITE%^ %^YELLOW%^Ph%^MAGENTA%^oe%^RED%^ni%^RESET%^%^MAGENTA%^x%^BOLD%^%^WHITE%^, whose name is %^GREEN%^Fawkes%^WHITE%^, %^BOLD%^has a royal %^RESET%^%^MAGENTA%^purple body%^BOLD%^%^WHITE%^ and is %^YELLOW%^radiating%^WHITE%^ with%^RED%^ reddish %^YELLOW%^gold %^RED%^f%^YELLOW%^ea%^RED%^th%^YELLOW%^e%^RED%^rs%^WHITE%^.  With a %^YELLOW%^golden neck%^WHITE%^ and a %^YELLOW%^golden head %^WHITE%^and a sweeping tail of %^MAGENTA%^rose%^WHITE%^ and %^CYAN%^azure%^WHITE%^, this bird is fast and ready for whatever calls its Master gives.");
   set_race("phoenix");
   set_body_type("fowl");
   set_level(1);
   add_stat_bonus("constitution", 80, 86400 );
   add_stat_bonus("charisma", 50, 86400);
   set_emotes(3, ({
   "%^BOLD%^%^GREEN%^Fawkes %^WHITE%^flies over head in search for some food.",
   "%^BOLD%^%^GREEN%^Fawkes %^RED%^squawks %^WHITE%^at Carina.",
   "%^BOLD%^%^GREEN%^Fawkes %^BLACK%^pecks %^WHITE%^at Carina^Rs leg in %^MAGENTA%^desire %^WHITE%^for attention.",
   "%^BOLD%^%^GREEN%^Fawkes %^CYAN%^s%^WHITE%^i%^CYAN%^ngs %^WHITE%^her sweet gentle tune bringing %^YELLOW%^peace %^WHITE%^to the room.",
   "%^BOLD%^%^GREEN%^Fawkes %^WHITE%^preens her %^RED%^red %^WHITE%^and %^YELLOW%^golden f%^RED%^ea%^YELLOW%^th%^RED%^e%^YELLOW%^rs%^WHITE%^.",
   "%^BOLD%^%^GREEN%^Fawkes %^WHITE%^takes flight into the %^CYAN%^sky %^WHITE%^to show off her %^CYAN%^b%^WHITE%^eaut%^CYAN%^y%^WHITE%^.",
   "%^BOLD%^%^GREEN%^Fawkes %^CYAN%^s%^WHITE%^i%^CYAN%^ngs %^WHITE%^a song full of %^RED%^s%^BLACK%^o%^RED%^rr%^BLACK%^o%^RED%^w %^WHITE%^across the %^GREEN%^l%^CYAN%^a%^GREEN%^nd%^WHITE%^.",
   }), 0);
}

void heart_beat() {
  ::heart_beat();
  if (tp && this_object()) {
  if (environment(this_object()) != environment(tp)) {
  message("info", "%^BOLD%^%^WHITE%^The %^YELLOW%^Ph%^MAGENTA%^oe%^RED%^ni%^RESET%^%^MAGENTA%^x %^BOLD%^%^WHITE%^spreads their %^CYAN%^w%^YELLOW%^i%^CYAN%^ngs %^WHITE%^and flies to Carina.", environment(tp));
  this_object()->move(environment(tp));
    }
  }
}

int is_invincible() {
  message("info", "%^BOLD%^%^WHITE%^The %^YELLOW%^Ph%^MAGENTA%^oe%^RED%^ni%^RESET%^%^MAGENTA%^x %^BOLD%^%^WHITE%^smites "+this_player()->query_cap_name()+" and flies back onto Carina's back.", environment(this_player()));
  return 1;
}

string query_guild() {
  return "illuminati";
}
