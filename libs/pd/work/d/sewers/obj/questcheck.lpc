#include <sewer.h>

void help_angel(object tp);
void help_demons(object tp);

void do_death_check(object tp) {
  if (!tp) return;
  if(sizeof(children(base_name(previous_object()))) == 2) {
    if(!tp->set_manual_quest("Holy War", 2))
      return;
    tp->add_exp(10000);
    if(previous_object()->query_race() == "demon")
      help_angel(tp);
    else
      help_demons(tp);
  }
}

void help_angel(object tp) {
  message("info", "%^RESET%^%^BOLD%^As the last demon falls to you, the angels around finally take a breath of relief.", tp);
  message("info", "\n%^RESET%^%^BOLD%^The demons have been defeated, thanks to your help.  You feel a holy presense surround you.", tp);
  tp->set_alignment(1500);
  new(OBJ"goodmark")->move(tp);
}

void help_demons(object tp) {
  message("info", "%^BOLD%^%^RED%^After smiting the holyness of the angels, you cackle demonically.", tp);
  message("info", "\n%^BOLD%^%^RED%^The angels have been defeated, thanks to your help.  Chaos and destruction will now enter the world.  You grin mercilessly at the thought.", tp);
  tp->set_alignment(-1500);
  new(OBJ"badmark")->move(tp);
}
