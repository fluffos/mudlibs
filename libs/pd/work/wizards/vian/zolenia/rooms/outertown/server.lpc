#include <std.h>
#include <zolenia.h>
inherit VIRTUALSERVER;
void create() {
  ::create();
  set_how_long(5);
  set_day_sentances( ({
      "There are no shadows here, simply darkness.",
      "The few scattered dead trees here are of unknown origin and species.",
      "A rock larger than yourself blocks certain directions of the cavernous forest.",
      "A large and sharp stalactite sways, ready to fall to the ground.",
      "Without any sort of path or direction, the only place to go is where the less treacherous rocks allow.",
      "The few remains of a mauled and rotting corpse sit atop a flat rock.",
      "Markings of dragons and elf-looking creatures have been scratched into the walls here.",
      "In the dirty dust on the ground, the tracks of a wolverine seem to be running through the forest.",
      "A rare barely living tree with a pond of murky water surrounding it sits here peacefully.",
      "Blood has permanently stained many of the rocks here.",
      "Here, dead vines which seems to have mineralized over scratch at anything to walk through them.",
      "Hilts of swords and broken bows litter the ground.",
      "A large glowing egg, no doubt that of a dragon, has been destroyed and is surrounded by a reddish silvery liquid.",
      "A swarm of wasps fly through the room at unimaginable speeds, barely able to be seen.",
      "A circle of rocks shows what used to be a campfire in this area.",
      "The roar of a dragon and the scream of a child can be heard in the distance..",
      "The rocks vary in size, sharpness, and color, making it difficult to tell where walking is safe.",
      "The sound of dripping water can be heard in the distance.",
      "A skeleton of what appears to be human is chained to a large boulder.",
      "The sound of commotion can be heard from afar." 

  }) );
  set_night_sentances( ({
      "There are no shadows here, simply darkness.",
      "The few scattered dead trees here are of unknown origin and species.",
      "A rock larger than yourself blocks certain directions of the cavernous forest.",
      "A large and sharp stalactite sways, ready to fall to the ground.",
      "Without any sort of path or direction, the only place to go is where the less treacherous rocks allow.",
      "The few remains of a mauled and rotting corpse sit atop a flat rock.",
      "Markings of dragons and elf-looking creatures have been scratched into the walls here.",
      "In the dirty dust on the ground, the tracks of a wolverine seem to be running through the forest.",
      "A rare barely living tree with a pond of murky water surrounding it sits here peacefully.",
      "Blood has permanently stained many of the rocks here.",
      "Here, dead vines which seems to have mineralized over scratch at anything to walk through them.",
      "Hilts of swords and broken bows litter the ground.",
      "A large glowing egg, no doubt that of a dragon, has been destroyed and is surrounded by a reddish silvery liquid.",
      "A swarm of wasps fly through the room at unimaginable speeds, barely able to be seen.",
      "A circle of rocks shows what used to be a campfire in this area.",
      "The roar of a dragon and the scream of a child can be heard in the distance..",
      "The rocks vary in size, sharpness, and color, making it difficult to tell where walking is safe.",
      "The sound of dripping water can be heard in the distance.",
      "A skeleton of what appears to be human is chained to a large boulder.",
      "The sound of commotion can be heard from afar." 

      
  }) ); 
  set_item_list( ([
      "trees" : "The trees, dead for the most part, are of unknown origin or species.",
      "blood" : "Blood has stained many of the scattered rocks on the ground.",
      "vines" : "A dead and mineralized vine glints on the ground, looking quite sharp.",
      "living tree" : "Quite the sight in such a desolate area, this barely living tree is surrounded by a pond of murky water..",
      "stalactite" : "A large and sharp stalactite sways from the ceiling, caution seems necessary..",
      "skeleton" : "A skeleton chained to a large boulder appears to be human.",
      "wasps" : "The swarm of wasps flew by too quickly for you to actually get a good look at them.",
      "markings" : "Scratched into rocks are markings which show dragons and elf-looking creatures.  Looking closer, the elves have dark skin and appear to be fighting the dragons.",
      "path" : "Although there's not much of a path, some of the rocks seem less treacherous than others.",
      ({"shadow", "darkness" "shadows"}) : "The complete darkness makes for no shadows in this cavernous forest.",
      "forest" : "Although there are a few scattered dead trees, perhaps a forest isn't the best way to describe this area..",
      ({"dust", "tracks"}) : "The ground is covered in a thin layer of dirty dust, showing the tracks of a wolverine running through the land.",
      ({"circle of rocks", "campfire"}) : "A circle of rocks sits to show where a campfire has been.  Judging by a few still red embers in the center, this campfire was used very recently.",
      ({"egg", "dragon egg"}) : "A large glowing dragon egg has been destroyed, with a reddish silvery liquid oozing out of it and surrounding it on the ground.  Hopefully the mother isn't nearby...",
      ({"hilts", "bows"}) : "The ground is scattered with hilts of swords and broken bows.",
      ({"remains", "corpse"}) : "The scattered remains of a corpse have been littered on a large and flat rock, although anything edible is gone.",
      ({"rock", "rocks"}) : "The rocks vary in size, sharpness, and color, making it difficult to tell where walking is safe.",

  ]) );
  set_smell("The dead, rocky forest has been pervaded by a stench of rotting flesh.");
  set_listen("Scattering can be heard throughout the forest, with an occasional scream of a dying animal.");
  set_reset_list( ({
      MOBO"angryspider", MOBO"blackbear", MOBO"blackgiant", MOBO"blackgriffin", MOBO"brownbear", MOBO"burningrat", MOBO"dragon", MOBO"drowchild", MOBO"drowguard", MOBO"drowmother", MOBO"goldengriffin", MOBO"laughingrat", MOBO"magicalwolverine", MOBO"redgiant", MOBO"sneakyspider", MOBO"unicorn", MOBO"angrywolverine", 
  }) );
  set_properties( ([ "light" : 1,
                     "night light" : 1,
                     "cave" : 1
                   ]) );
  set_short("A dead, dark, and rocky underground forest.");
  set_mob_cap(3);
}
