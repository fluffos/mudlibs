#include <dquest.h>
#include <std.h>
inherit MONSTER;
int KillMe();

void create() {
::create();
set_name("demon");
set_short("chaos demon");
set_long("%^GREEN%^The chaos demon appears as a swirling mass of colors in the form of a four-armed demon.  It's face is featurless except for three voids that seem to serve as eyes near its forehead and forming in the shape of a triangle pointed down.  While the demon is comprised of many colors, the majority of the creature is a swirling royal blue.%^RESET%^");
set_id(({"demon", "chaos demon"}));
set_level(55);
set("aggressive", 666);
set_alignment(-450);
set_skill("blade", 250);
set_skill("attack", 250);
set_skill("defense", 300);
set_skill("magic attack", 250);
set_skill("faith", 250);
set_skill("healing", 250);
set_race("demon");
set_body_type("artrell");
set_gender("neuter");
set_class("fighter");
set_emotes(10, ({"The demon swirls into a dark %^MAGENTA%^violet%^RESET%^.", "The demon swirls into a %^BLUE%^royal blue%^RESET%^.", "The demon swirls into a %^BLUE%^royal blue%^RESET%^.", "The demon swirls into a %^BLUE%^royal blue%^RESET%^.", "The demon swirls into an eerie %^GREEN%^green%^RESET%^.", "The demon seems to %^BOLD%^BLACK%^darken%^RESET%^."}), 1);
set_spell_chance(50);
set_spells(({"slash", "rush", "stun"}));
set_die((: KillMe() :));
new(DQUEST "csword")->move(this_object());
new(DQUEST "csword")->move(this_object());
new(DQUEST "sword")->move(this_object());
new(DQUEST "sword")->move(this_object());
command("wield sword");
command("wield sword 2");
command("wield sword 3");
command("wield sword 4");
}

int KillMe() {
   object ob;
object *inv;
int i;

inv = all_inventory(this_object());
i = sizeof(inv);
while(i--)
 inv[i]->remove();
   tell_room(environment(this_object()),
   "%^BLUE%^The demon melts into the surrounding chaos.", ({ }));
  if (present("sword", this_object())) {
      ob = present("sword", this_object());
      catch ( ob->remove() );
   }
   catch ( this_object()->remove() );
return 0;
}
