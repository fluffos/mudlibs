#include <std.h>

inherit FOOD;

void create() {
  ::create();
  set_name("pumpkin");
  set_my_mess("You chow down on some pumpkin. Hmm, stringy.\n");
  set_your_mess("chows down on a pumpkin.\n");
  switch (random(random(5))) {
  case 0:
    set_id( ({ "pumpkin", "small pumpkin" }) );
    set_short("a small %^RESET%^%^ORANGE%^pumpkin%^RESET%^");
    set_long("A miniature orange pumpkin. It is squat rather than round, "
      "and might make a good decoration.");
    set_weight(1);
    set_strength(4);
  break;

  case 1:
    set_id( ({ "pumpkin", "round pumpkin" }) );
    set_short("a round %^RESET%^%^ORANGE%^pumpkin%^RESET%^");
    set_long("This pumpkin is extremely round, and the lightest push sends it rolling. "
      "The stem is still soft and pliable and the ridged skin is a deep orange.");
    set_weight(4);
    set_strength(12);
  break;

  case 2:
    set_id( ({ "pumpkin", "large pumpkin" }) );
    set_short("a large %^RESET%^%^ORANGE%^pumpkin%^RESET%^");
    set_long("Quite large by most standards, this pumpkin is wide enough to seat two or three "
      "people at once. The stem is still attached to the ground, but looks a little dry.");
    set_weight(15);
    set_strength(30);
  break;

  case 3:
    set_id( ({ "pumpkin", "giant pumpkin" }) );
    set_short("a giant %^RESET%^%^ORANGE%^pumpkin%^RESET%^");
    set_long("Truly a gigantic pumpkin, this thing towers over nearly everyone. It lies on its "
      "side, the stem still holding it to the ground. Looking up from the base, nothing but "
      "an orange pumpkin sky fills your vision."+
      (query_night() ? "" : " The pumpkin's shadow creates a large shady area.") );
    set_weight(75);
    set_strength(60);
    set_prevent_get("The giant pumpkin is FAR too heavy for you to carry.");
  break;
  }
}
