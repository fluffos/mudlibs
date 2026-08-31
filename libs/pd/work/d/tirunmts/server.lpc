#include <std.h>
#include <tirunmts.h>
inherit VIRTUALSERVER;
void create() {
    ::create();
    set_how_long(5);
    set_day_sentances( ({
	"The path running through the mountains is well worn from the tracks of many animals, birds and people.",
	"The Tak'dar Mountain Pass cuts through the tall mountain range like a stone gorge littered with foliage.",
	"Many caves, large and small, are scattered throughout the mountains above the path, though most are unreachable.",
	"Sparse weeds and shrubs grow scattered throught the mountains along and above the path.",
	"A large boulder sits next to the path, appearing to have fallen down from the mountain above.",
	"Rocks of all shapes and sizes litter the mountains and the path making the footing treacherous in places.",
	"A large rock overhangs the path, shading the pass from the sun.",
	"Tracks of a large feline run along the path for a ways then veer off up into the mountains.",
	"A stack of rocks on a nearby plateau looks to be laid out for a long extinguished campfire.",
	"A large bird nest is set into a nearby cliff. From this vantage point it is clear there are young present.",
	"The moutainside near the path is a sheer cliff going straight up.",
	"Gravel and small rocks make moving quietly through the pass almost impossible.",
	"A bird's nest in a nearby tree looks like it has weathered with age and is probably abandoned.",
	"The ground is uneven causing the path to be treacherous in places.",
	"The remains of some kind of animal are decaying near the path.",
	"Dirt and rocks tumble down the mountain side nearby.",
	"A mound of dirt near the path looks to be freshly dug.",
	"Goblin footprints run next to the path for a ways then vear off into one of the small caves.",
	"Great gouges in a nearby rock look like they were made from a large animals claws.",
	"Nearby, rocks slide off the path down into a deep gorge.",
	"A far-away column of smoke rising into the sky betrays a campfire some distance away.",
	"There are signs of a scuffle here, with the occasional broken weapon or drop of blood found along the path.",
	"A large, forked tree has fallen over the path here, likely the product of a recent storm.",
	"Some bright blue flowers appear to be growing on the edge of the path here.",
	"A mold-covered rock lies near the path here, playing host to a number of lizards and insects.",
	"High up the slope of one of the mountains, a family of goats grazes on shoots of grass.",
	"The body of an orc lies not far from here, the shafts of goblin spears protruding from his body.",
	"The path dips down here, then rises back up, following a natural depression in the earth.",
	"A rockslide occurred here recently, damaging the path substantially and making progress difficult.",
	"Underneath one of the many trees here lies a scattering of black feathers, possibly the remains of a a goblin ritual.",
	"A few of the trees by the roadside appear to have been felled recently.",
      }) );
    set_night_sentances( ({
	"Darkness makes travelling the path dangerous at night.",
	"The Tak'dar Mountain Pass cuts through the tall mountain range in pitch blackness.",
	"Dark shapes in the distance are rather ominous in the night.",
	"The lack of light down the path gives a distinct feeling of danger and trepidation",
	"Shadowy movements along the path lend themselves to very sinister and evil feelings.",
	"Rocks of all shapes and sizes litter the mountains and the path making the footing treacherous in places.",
	"Tracks of a large feline run along the path for a ways then veer off into the darkness.",
	"A nearby plateau is almost complete submerged in the shadows.",
	"Large shadows hide the details of a nearby cliff.",
	"The moutainside near the path is a sheer cliff going straight up.",
	"Gravel and small rocks make moving quietly through the pass almost impossible.",
	"A bird's nest in a nearby tree looks like it has weathered with age.",
	"The ground is uneven in places causing the path to be treacherous.",
	"The remains of some kind of animal are decaying near the path.",
	"Something out in the darkness moves down the mountain side nearby.",
	"Footprints run next to the path for a ways then vear off into the darkness.",
	"Great black shapes out in the darkness reveal nothing more about themselves.",
	"Shadowy forms out in the darkness seem to creep closer to the path.",
	"The crunching of the gravel underfoot echo off into the darkness.",
	"Darkness closes in around the area absorbing the light.",
	"Rough uneven ground makes traveling at night treacherous.",
	"Nearby, rocks slide off the path down into a deep gorge.",
	"A far-away flicker of light betrays a campfire some distance away.",
	"There are signs of a scuffle here, with the occasional broken weapon or drop of blood found along the path.",
	"A large, forked tree has fallen over the path here, likely the product of a recent storm.",
	"Some bright blue flowers appear to be growing on the edge of the path here.",
	"A mold-covered rock lies near the path here.",
	"High up the slope of one of the mountains, a family of goats sleeps huddled in a pile.",
	"The body of an orc lies not far from here, the shafts of goblin spears protruding from his body.",
	"The path dips down here, then rises back up, following a natural depression in the earth.",
	"A rockslide occurred here recently, damaging the path substantially and making progress difficult.",
	"Underneath one of the many trees here lies a scattering of black feathers, possibly the remains of a a goblin ritual.",
	"A few of the trees by the roadside appear to have been felled recently.",
      }) ); 
    set_item_list( ([
	"rocks" : "Stones on the ground.",
	"path" : "A worn trail in the mountainside.",
	({"shadow", "shadows"}) : "Dark forms out in the night.",
	"mound" : "A pile of dirt.",
	"nest" : "Twigs and grass formed together.",
	"foliage" : "Branches and leaves on the on the shrubs.",
	"remains" : "A rotting corpse of an animal.",
	"path" : "An animal track through the underbrush.",
	"tracks" : "Large tracks.",
	"foliage" : "Branches and leaves on the trees.",
	"shapes" : "Shadowy shapes in the darkened areas of the forest.",
	({"broken weapon", "weapon", "blood", "signs of scuffle"}) : "This fight was over quickly and the bodies were dragged away. There is nothing of value remaining.",
	({"smoke", "campfire"}) : "This campfire is a fair distance away.",
	({"forked tree", "fallen tree"}) : "This tree appears to have been blown down in the wind.",
	({"flowers", "blue flowers"}) : "These bright blue flowers are small and pretty.",
	({"rock", "mold covered", "mold-covered", "mold covered rock", "mold-covered rock"}) : "This rock is covered in a thick layer of moss and slime. It has clearly been here a while.",
	({"goats", "goat family"}) : "This small family of goats stands out rather starkly against the backdrop of the mountains.",
	({"body", "orc body", "dead orc"}) : "It would appear this orc was killed by goblins. For what reason, nobody can say.",
	({"feathers", "black feathers"}) : "These feathers appear to be laid out at random, although there is an underlying pattern here which betrays their purpose.",

      ]) );

    set_smell("The smell of dust and ozone are strong in the air.");
    set_listen("The wind moans and whistles through the mountains.");
    set_reset_list( ({MOB"balrog", MOB"balrogc", MOB"balrogcf", MOB"balrogf", MOB"goblinfemale", MOB"goblinfighter", MOB"goblinhunter", MOB"takdarguard", MOB"goblinchild", MOB"orc", MOB"orchunter", MOB"orcshaman", MOB"takdar", MOB"takdarchild", MOB"takdarelder", MOB"takdarhunter", MOB"orcchild"}) );
    set_properties( ([ "light" : 1,
	"night light" : 0,
	"mountain" : 1
      ]) );
    set_short("A mountain path.");
    set_mob_cap(2);
}
