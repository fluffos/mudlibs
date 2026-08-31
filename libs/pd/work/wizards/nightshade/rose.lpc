#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_property("no steal", 1);
  set_name("eternal rose");
  set_short("%^BOLD%^%^RED%^Etern%^GREEN%^al%^RED%^ Rose%^RESET%^");
  set_id(({"rose", "eternal rose"}));
  set_long("%^BOLD%^A glowing aura surrounds this rose, protecting it from harm"
           " or decay.  %^RESET%^A red rose represents both love and respect, and "
           "this rose will be there forever to remind it's owner of that certain "
           "someone who will always keep them close to their heart.  The thick, sweet "
           "scent of the rose wafts towards you.");
  set_weight(2);
  set_value(1);
}

void init() {
  ::init();
  add_action("smell", "smell");
  add_action("pluck", "pluck");
  add_action("remember", "remember");
}

int drop() {
  return 1;
}

int smell(string str) {
  if(!str || str != "rose") return 0;
  write("%^BOLD%^%^RED%^The sweet smell of the rose nearly makes you dizzy, it's "
        "scent never fading.");
  say(this_player()->query_cap_name()+" smells the rose.");
  return 1;
}

int pluck(string str) {
  if(!str || str != "rose") return 0;
  write("You begin to pluck the petals off the rose.");
  call_out("pick", 2, 1);
  return 1;
}

void pick(int x) {
  write("You pull off a petal.");
  if(x%2)
    this_player()->force_me("say He loves me!");
  else
    this_player()->force_me("say He loves me not.");
  if(x == 5) {
    write("And that was the last petal.");
    this_player()->force_me("smile");
  }
  else {
    x++;
    call_out("pick", 2 + random(3), x);
  }
}

int remember(string str) {
  if(str) return 0;
  write("%^BOLD%^%^RED%^                              .,,.\n"
"%^BOLD%^%^RED%^                       .,v%;mmmmmmmm;%%vv,.\n"
"%^BOLD%^%^RED%^                    ,vvv%;mmmvv;vvvmmm;%vvvv,    .,,.\n"
"%^BOLD%^%^RED%^             ,, ,vvvnnv%;mmmvv%^RESET%^%^RED%^;%%;%^BOLD%^vvmmm;%vvvv%;mmmmmmm,\n"
"%^BOLD%^%^RED%^           ,mmmmmm;%^RESET%^%^RED%^%%vv%;%^BOLD%^mmmvv%^RESET%^%^RED%^;%%;%^BOLD%^vvmmm;%^RESET%^%^RED%^%v%;%^BOLD%^mmmmmmmmmmm\n"
"%^BOLD%^%^RED%^           mmmmmmmmmmm;%^RESET%^%^RED%^%%;%^BOLD%^mmmvv%^RESET%^%^RED%^%;%^BOLD%^vvmmm;%^RESET%^%^RED%^%%^BOLD%^mmmmmmmmmmmmmm'\n"
"%^BOLD%^%^RED%^           `mmmmmmmmmmmmmm%^RESET%^%^RED%^%;%^BOLD%^mmv%^RESET%^%^RED%^;%^BOLD%^vmmm;mmmmmmm;%%^RESET%^%^RED%^vvvvvv'\n"
"%^BOLD%^%^RED%^               `%%%%%;mmmmmmmm;v%v;mmmmmm;%%^RESET%^%^RED%^vvvnnvv'\n"
"%^RED%^                vvvvvv%^BOLD%^%%%%;mmmm%;mmmmmm;%%^RESET%^%^RED%^vvvnnnnvv\n"
"%^RED%^                `vvnnnnvvv%^BOLD%^%%%;m;mmmmm;%%^RESET%^%^RED%^vvnnmmnnvv'\n"
"%^RED%^                 vvnmmnnnnvvv%^BOLD%^%%mmmm;%%^RESET%^%^RED%^vvnnmmmnnnvv\n"
"%^RED%^                 `vvnmmmnnvvv%^BOLD%^%mmm;%%^RESET%^%^RED%^vvnnmmmmnnnvv'\n"
"%^RED%^                  `vvnmmmmvv%^BOLD%^%mmm;%%^RESET%^%^RED%^vvnnmmmmnnnvv'\n"
"%^RED%^                   `vvnmmmvv%^BOLD%^%mm;%%^RESET%^%^RED%^vvvnnmmmnnvvv'\n"
"%^RED%^                     `vvnmmvv%^BOLD%^%m;%%^RESET%^%^RED%^vvvvnmnvvvv'\n"
"%^BOLD%^%^GREEN%^                      .;;%^RESET%^%^RED%^vvvvvm;%vvvvvvvv'\n"
"%^BOLD%^%^GREEN%^                   .;;;;;;;;;;;;;;;;;;;;,\n"
"%^BOLD%^%^GREEN%^                  ;;;;;;';;;;;;;;;;;'`;;;;;,\n"
"%^BOLD%^%^GREEN%^                 .;;;'    `;;;;;;;;'   `;;;;;.\n"
"%^BOLD%^%^GREEN%^                .;;'        `;;;;;'      `;;;;\n"
"%^BOLD%^%^GREEN%^                ;'     %^RESET%^%^GREEN%^      :%^BOLD%^`;;'         ;;'\n"
"%^BOLD%^%^GREEN%^                ;      %^RESET%^%^GREEN%^      :%^BOLD%^ ;' %^RESET%^%^GREEN%^   , %^BOLD%^   ,'    %^RESET%^%^GREEN%^         .\n"
"%^BOLD%^%^GREEN%^                 `     %^RESET%^%^GREEN%^      :%^BOLD%^'%^RESET%^%^GREEN%^.:   .;;,.        .,;;;;;;'\n"
"%^GREEN%^                             ::::   ;;,;;;,     ;;;,;;;;'\n"
"%^GREEN%^                             ;;;;   `;;;,;;    .,';;;;'\n"
"%^GREEN%^                             ;;;;      `';; ,;;'\n"
"%^GREEN%^                           ,;;;;;         .;',.\n"
"%^GREEN%^                             `;;;;       .;'  ';,.\n"
"%^GREEN%^                              `;;;.     .;'   ,;;,;;,.\n"
"%^GREEN%^                               ;;;;    .;'    `;;;;,;;;\n"
"%^GREEN%^                               ;;;;   .;'       `;;,;;'\n"
"%^GREEN%^                               `;;;,;;'           `;'\n"
"%^GREEN%^                                ;;;;\n"
"%^GREEN%^                                ;;;;.\n"
"%^GREEN%^                                `;;;;;,.\n"
"%^GREEN%^                                 ;;;;'\n"
"%^GREEN%^                                 ;;;;\n"
"%^GREEN%^                                 ;;;;\n");

write("\nYou look over the rose and remember that it was created for you only by someone"
      " who truly cares for you and will always keep you close to their heart.");
  return 1;
}

int query_auto_load() {
  if(this_player()->query_name() == "azire") return 1;
  return 0;
}
