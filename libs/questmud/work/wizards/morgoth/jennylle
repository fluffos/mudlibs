inherit "room/room";
int picked, taken;

reset(arg) {
  add_exit("south", "/wizards/ahma/orc/forest/for36");
  short_desc = "On a path behind a wooden hut";
  long_desc = "The path leads behind the hut and ends there into a thick barricade\n" + 
              "of trees. Seems almost like the sturdy trees has been summoned to\n" + 
              "block the way where the path once had led. The hut prevents the\n" + 
              "the meadow to be seen from here, but some flowers are still growing\n" + 
              "in the bank of the hut. A note has been attached to one of the trees\n" + 
              "blocking the path to north.\n";

  items = allocate(12);
  items[0] = "note";
  items[1] = "Respected G'ralt,\n" + 
             "Me and my men could not do anything to these trees. When looking at them,\n" +
             "you can see that we really tried our best, but no matter how much did we\n" + 
             "sweat or curse, the trees did not fall.\n" + 
             "When I was cutting one of these trees hour after hour I really begun to\n" + 
             "believe in your story about the ugly Dwarven hag who summoned these trees\n" + 
             "to separate the Orcish and Dwarven territories. Awhile pondering more, I\n" + 
             "realized that maybe the hag was not so stupid after all. Or at least I\n" + 
             "prefer to live in peaceful lands.\n" + 
             "- Sendarh, the leader of Nehelam's lumberjacks";
  items[2] = "tree";
  items[3] = "Try looking at 'trees'";
  items[4] = "trees";
  items[5] = "Half a dozen sturdy oaks stand on the path, blocking its way to north.\n" + 
             "On the trunks of the trees can be seen some traces of blows from axes,\n" + 
             "but the trees seem to be very sturdy, like magical, because not much\n" + 
             "damage can be seen on the trunks. There are several broken axes lying\n" + 
             "on the roots of the trees. A grayish toe of some poor lumberjack is\n" + 
             "lying near one of the broken axes. It must have been cut off by cracked\n" + 
             "edge of an axe";
  items[6] = "flower";
  items[7] = "Try looking at 'flowers'";
  items[8] = "flowers";
  items[9] = "Beautiful yellow and pink orchids are growing in the bank of the wooden\n" + 
             "hut. They are growing alone in the fertile soil, giving them a possibility\n" + 
             "to flourish even more than normal orchids which are rarely seen in the\n" + 
             "forests";
 items[10] = "toe";
 items[11] = "A toe has been cut off from an Orcish lumberjack probably by a loose edge\n" + 
             "of a broken axe. Originally greenish toe has already started decaying and\n" + 
             "turning into grey. The toe is lying in a small pool of blood and some bloody\n" +
             "footprints lead towards the meadow";

  picked = 0;
}

init() {
  ::init();
  add_action("hep", "pick");
  add_action("hap", "take");
  if(!random(250)) {
    tell_room(this_object(), "An Orcish ranger jumps out from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/ranger"), this_object());
  }
}

hep(str) {
  if(str == "flowers" || str == "flower" || str == "orchid") {
  if(picked != 2) {
    write("You pick a beautiful orchid from the ground.\n");
    say(this_player()->query_name() + " picks a flower from the ground");
    move_object(clone_object("/wizards/ahma/orc/eq/orchid"), this_player());
    picked++;
    return 1;
  }
  else {
    write("Someone has already picked some flowers from the ground. You do not\n" + 
          "want to ruin the whole bunch by picking the rest of the orchids away.\n" + 
          "You will have to wait for a moment that some new orchids grow up.\n");
    return 1;
  }
  }
  else {
    write("Pick what?\n");
    return 1;
  }
}

hap(str) {
  if(str == "toe") {
  if(!taken) {
    write("You take a grayish toe from the ground.\n");
    say(this_player()->query_name() + " takes a grayish toe from the ground.\n");
    move_object(clone_object("/wizards/ahma/orc/eq/toe"), this_player());
    taken = 1;
    items[5] = "Half a dozen sturdy oaks stand on the path, blocking its way to north.\n" + 
               "On the trunks of the trees can be seen some traces of blows from axes,\n" + 
               "but the trees seem to be very sturdy, like magical, because not much\n" + 
               "damage can be seen on the trunks. There are even several broken axes\n" + 
               "lying on the roots of the trees";
    items[11] = "You see nothing special";    
    return 1;
  }
  else { 
    write("You don't see a toe around here.\n");
    return 1;
  }
  }
  else {
    return;
  }
}