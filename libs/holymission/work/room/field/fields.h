#ifndef __FIELDS_H__

#define __FIELDS_H__

#include <room_defs.h>

#define CROPS ({ "corn", "wheat", "barley", "oats" })

#define SIZE_OF_CROPS  4

// PROTOTYPES
string crops_look();
string extra_long_north();
string extra_look_east();
string extra_look_west();
string extra_look_center();
string extra_look_forest();

string crops_look() {
  return "The people are growing " + (FIELDS + "crop01")->query_croptype() +
    " and the fields are full of it";
}

string extra_long_north() {
  switch(random(5)) {
    case 1..2 : return "the crops are flattened beside the road";
    case 3..4 : return "flowers have been trampled beside the road";
    default   : return "you hear the sound of galloping "+
                  "in the distance";
  }
}

string extra_look_east() {
  switch(random(5)) {
    case 1..2 : return "dust in the air, which makes you wonder "+
      "who just passed by.";
    case 3..4 : return "hear the sound of horses getting softer "+
      "to the south.";
    default   : return "and dust in the air. Your eyes may be "+
      "playing tricks on you, but was that a carriage hurrying "+
      "away south?";
  }
}

string extra_look_center() {
  switch(random(5)) {
    case 1..2 : return "You turn toward a breeze and notice the "+
      "crops swaying in the wind.";
    case 3..4 : return "You are refreshed by the coolness of the "+
      "air here.";
    default   : return "You feel very peaceful among the crops.";
  }
}

string extra_look_forest() {
  switch(random(5)) {
    case 1..2 : return "You pause at the sight of a deer as it darts "+
      "through some mysterious opening into the forest.";
    case 3..4 : return "Movement in a nearby tree draws your "+
      "attention to it, and you barely catch the tail of a "+
      "squirrel running away.";
    default   : return "A bird flies out of the forest as you "+
      "approach.";
  }
}

string extra_look_west() {
  switch(random(5)) {
    case 1..2 : return "You hear carousing and singing in the distance, "+
      "whichs piques your curiosity. However, the wall prevents you "+
      "from heading towards the sound.";
    case 3..4 : return "You hear some screams and the sounds of loud "+
      "people from the beyond the wall.";
    default   : return "You see the shadow of a guard walking along the "+
      "wall above you.";
  }
}

#endif // __FIELDS_H__

