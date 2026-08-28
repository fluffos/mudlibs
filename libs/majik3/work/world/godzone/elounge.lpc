#include "godzone.h"

create_room()
{
    set_area("godzone");
    set_light(1);
    set_short("Evil's lounge");
    set_long(
      "Hell for someone, heaven for the other. "+
      "The desing for this room seems to suggest that evil gods might enjoy "+
      "this place. This room has entirely black charred walls, and black "+
      "candles lit the room with eerie glow. you can hear the wails of tortured "+
      "souls echoing through the hall. "+
      "You see a crucified woman here, still alive and moaning, you feel like "+
      "You could 'whip' her a bit and enjoy the screams of the damned.\n");
    add_exit("out", ROOM_PATH + "nlounge");
    set_sounds (60, ({"The crucified woman shakes a bit and lets out a heart-chilling wail.\n","A faint moaning reaches you from somewhere.\n"}));
    add_item(({"walls","black charred walls","charred walls"}),"The walls are black and charred, like this room would have been burned some time ago.\n");
    add_item(({"candles","black candles"}),"Black candles slowly burn lighting the room with steady eerie glow, tallow dripping to the floor from them.\n");
    add_item(({"woman"}), "The crucified woman is still alive, moaning softly. She is totally naked, and blood drips from her wounds.\n"+
      "You see the nails stick out from her perfect legs, and slender hands.\n");
}

init()
{
    ::init();
    add_action("whip", "whip");
}



whip()
{
    tell_room("/home/malekith/dev/elounge", "The crucified woman is being brutally whipped!\n");
    write ("You grab a long, many-tailed whip with small nails tied all\n");
    write ("around it. With a loud bang, you whip the crucified woman with\n");
    write ("all your strenght, and the woman yells in agony, as the nails dig\n");
    write ("into her skin. The woman whimpers quietly as blood drops from her\n");
    write ("wounds.. you wonder how much longer she will live.. but then you\n");
    write ("remember that this is hell... she'll suffer eternally...\n");
    say ("The crucified woman is being brutally whipped!\n");
    return 1;
}

