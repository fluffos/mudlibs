#include <std.h>
#include <diran.h>

inherit ROOM;

void create() {
    ::create();

}

mapping _Descs = ([
	"First" : ({
		"The icy tundra is completely covered in a bright %^BOLD%^white%^RESET%^ sheet of ice.",
		"The icy tundra hopelessly continues in many different directions.",
		"The icy tundra seems to go on forever, as there is such limited visibility."
	}),
	"Rest" : ({
		"A gust of wind blows snow through the room.",
		"There are large stalagmites and boulders made from ice, spread throughout the land.",
		"The air is composed of a fresh mixture of %^BOLD%^cold%^RESET%^ and clean.",
		"Large %^BOLD%^snowflakes%^RESET%^ float around in the air.",
		"A small, mostly dried pool of %^BOLD%^%^RED%^blood %^RESET%^can be seen on the ground.",
		"There is a burning torch sticking up from the ground, a sign of civility.",
		"A frosty skeleton is propped up against a rock, perhaps it was just too cold for him.",
		"A %^BOLD%^steaming%^RESET%^ pool of water is visible here, perhaps a hotspring in the ground.",
		"There are footprints visible moving in every direction, animal and humanoid alike.",
		"A slippery patch of ice threatens to trip any unexpecting travelers.",
		"A %^BOLD%^%^BLACK%^charred%^RESET%^ firepit surrounded by a circle of stones is here, slowly pushing smoke into the sky.",
		"There are many rocks on the tundra, suggesting a mountain nearby."
	})
]);


string desc_long() {
	string strRet;
	
    int rand1, rand2, rand3, rand4;
	
	rand1 = random(sizeof(_Descs["Rest"]));
	rand2 = rand1;
	rand3 = rand2;
	rand4 = rand3;
	
	while (rand2 == rand1 || rand2 == rand3 || rand2 == rand4) 
		rand2 = random(sizeof(_Descs["Rest"]));
	while (rand3 == rand1 || rand3 == rand2 || rand3 == rand4) 
		rand3 = random(sizeof(_Descs["Rest"]));
	while (rand4 == rand1 || rand4 == rand2 || rand4 == rand3) 
		rand4 = random(sizeof(_Descs["Rest"]));	
		
    strRet = _Descs["First"][random(sizeof(_Descs["First"]))] + " ";
	strRet += _Descs["Rest"][rand1] + " ";
	strRet += _Descs["Rest"][rand2] + " ";
	strRet += _Descs["Rest"][rand3] + " ";
	
	return strRet;
}
mapping desc_items() {
    mapping mRet;
    mRet = ([
        ({"pool","blood", "pool of blood"}) : "The pool of blood seems to be making steam, a sign that it is still warm.",
        ({"pool", "steaming pool"}) : "This must be a natural hot spot in the tundra.  It looks quite warm and inviting.",
        ({"ice"}) : "Ice covers the entire tundra.",
        ({"snow"}) : "Snow is visible everywhere from the sky to the ground.",
        ({"stalagmites"}) : "Stalagmites of pure ice have somehow formed over time.",
        ({"boulders"}) : "Large boulders of ice have somehow been formed over time.",
        ({"snowflakes"}) : "Unique snowflakes float around in the air.",
        ({"torch"}) : "A thick wooden pole only 2 feet tall has a lit torch wrapped to it.",
        ({"skeleton"}) : "The entire skeleton is covered in a thick layer of frost.",
        ({"rock"}) : "A large stone made of some frozen substance.",
        ({"firepit"}) : "The small amount of smoke trailing off the middle of the firepit suggests recent campers.",
        ({"slipper patch of ice"}) : "If you hadn't seen it, you'd probably be on the ground.",
        ({"rocks"}) : "Rocks that had fallen from the mountain litter the ground.",
        ]);
    return mRet;
}
void reset(){
::reset();
if(random(100) > 60){
     if( random(100) > 65){
        if(!present("arcticwolf"))
          new(MOB "arcticwolf")->move(this_object());
}
     if( random(100) > 65){
        if(!present("polarbear"))
          new(MOB "polarbear")->move(this_object());
}
     if( random(100) > 65){
        if(!present("arcticfox"))
          new(MOB "arcticfox")->move(this_object());
}
     if( random(100) > 65){
        if(!present("snowyowl"))
          new(MOB "snowyowl")->move(this_object());
}
     if( random(100) > 65){
        if(!present("largecaribou"))
          new(MOB "largecaribou")->move(this_object());
}
     if( random(100) > 50){
        if(!present("mdscout"))
          new(MOB "mdscout")->move(this_object());
}
     if( random(100) > 50){
        if(!present("dscout"))
          new(MOB "dscout")->move(this_object());
}
}
}
