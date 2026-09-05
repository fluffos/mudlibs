/*Polymorph RedDwarf Style*/

#include "/players/wren/ansi.h";
inherit "/obj/monster";

reset(arg){ 
    if(arg) return;
	::reset(arg);
			change_shape();
		set_name("polymorph");
		set_alias("poly");
		set_short("A massive homicidal polymorph");
		set_race("gelf");
		set_long("This is a genetically engineered killing machine. Built for war     \n"+
			"these beast were to be tough, mobil, and efficient. The geneticists \n"+
			"made one major flaw in that these beasts are INSANE. The mutant     \n"+
			"monsters feed on intense emotions. Shapechangers able to read the   \n"+
			"brain of their victims and pick a form able to draw the strongest   \n"+
			"emotional response makes them dangerous foes. Do to the unwieldy    \n"+
			"nature of the creatures the project was scrapped and they were      \n"+
		"dumped. Like many GELFS they ended up in the hostile wild space.    \n");
		set_level(20);
		set_ac(18);
		set_wc(32);
		set_hp(random(100)+420);
		set_al(-1000); 			 /*alignment*/
		set_aggressive(0);		 /*0 not, 1 is*/
		set_chance(10);
		set_spell_dam(20);
		set_spell_mess1("The Polymorph visciously attacks its opponent with its toothy maw. \n");    /*others*/
		set_spell_mess2("The Polymorph and leers down at you, saliva drips from its double jaws.\n"+
		"                      >>  It CHOMPS YOU!  <<   \n");    /*attacker*/
}


heart_beat(){
 ::heart_beat();
	if(!random(5) && attacker_ob) big_special();
   if(!random(20)) change_shape();  
    }


change_shape() {

	switch(random(10)) {
	
		case 9:
		set_short("a bouncing rubber ball");
		set_long("This looks like a normal beach ball caught in the air flow\n");
		set_alt_name("ball");
		break;
		
		case 8:
		set_short("a remote controlled race car");
		set_long("This is a sharp looking RC car rolling around the room.\n"+
			"You don't see anyone around operating it though. Thats \n"+
		"kind of odd. Ah well, this ship is full of odd.\n");
		set_alt_name("car");
		break;
		
		case 7:
		set_short("a paper airplane gliding by");
		set_long("A piece of typing paper folded into a nice paper airplane. \n"+
			"Its in the traditional triangular jet. Its getting nice \n"+
		"distance right now. Who threw it? \n");
		set_alt_name("airplane");
		break;
		
		case 6:
		set_short("a slinky rolling down the stairs");
		set_long("A standard metal slinky. You know the toy that is made of \n"+
			"a long metal coil that can 'walk' down stairs when tipped.\n"+
		"Doesn't look to threatening.\n");
		set_alt_name("slinky");
		break;
		
		case 5:
		set_short("a pair of boxer shorts");
		set_long("A pair of pokka dotted boxer shorts. These have the rough look\n"+
			"of something that escaped from Lister's locker. Probably \n"+
		"shouldn't touch them without a hazardous materials suit.\n");
		set_alt_name("shorts");
		break;
		
		case 4: set_short("a spicey kabob on a lettuce leaf");
		set_long("A spicey kabob the way Lister likes them. Perhaps a bit too \n"+
		"spicey. You almost could swear you saw it twitch. Thats gross\n");
		set_alt_name("kabob");
		break;
		
		case 3:
		set_short("a cute little bunny");
		set_long("A long earred bunny rabbit. Sits twitching its nose and \n"+
			"looking all nervous at the big people clomping around.\n"+
		"It seems to be the cutest thing you've seen on this ship.\n");
		set_alt_name("bunny");
		break;
		case 2:
		set_short("a beautiful young lady");
		set_long("This fine looking lady in evening wear is in need of a \n"+
			"knight in shining armor. She has become lost in the cargo \n"+
			"bay and has heard that some mean creature is lurking about\n"+
		"Maybe as a brave adventurer you can offer to help her out.\n");
		set_alt_name("lady");
		break;
		case 1:
		set_short("a long boa constricter");
		set_long("A large African boa constricter. How it got loose on the ship \n"+
			"is unclear but it doesn't pose much of a threat provided you \n"+
		"are bigger than a rabbit and don't lie down next to it. \n");
		set_alt_name("boa");
		break;
		case 0:
		set_short("Rimmer's mom");
		set_long("Rimmer's mom isn't looking so good. She's in a coffee stained\n"+
			"nightgown, several teeth are missing or decayed, her hair is \n"+
			"ratted and she is wearing no make up. Even more disgusting she \n"+
			"is bragging about Lister and her 'getting it on' all over the \n"+
			"Medibay.  You are almost to disgusted to vomit. Rimmer must be \n"+
		"just furious at this behavior.\n");
		set_alt_name("mom");
		break;
	}
	if(environment())
	tell_room(environment(),"Polymorph changes into "+alt_name+".\n");
}



big_special() {
	if(environment())
	tell_room(environment(),
       "The Polymorph rears up in its true form. It's double jaws \n"+
		"         open revealing a probiscus which slimily attaches to \n"+
	   "               your forehead with a wet slap!\n");
	
	switch(random(5))  {
		
		case 4:
		tell_room(environment(),"The Polymorph slurps noisily on "+attacker_ob->query_name()+"'s "+RED+"ANGER"+NORM+".\n");    /*others*/
		attacker_ob->hit_player(30,"other|mental");
		break;
		
		case 3:
		tell_room(environment(),"The Polymorph slurps noisily on "+attacker_ob->query_name()+"'s "+CYN+"COOL"+NORM+".\n");    /*others*/
		attacker_ob->hit_player(30,"other|mental");
		break;
		
		case 2:
		tell_room(environment(),"The Polymorph slurps noisily on "+attacker_ob->query_name()+"'s "+BLU+"GUILT"+NORM+".\n");    /*others*/
		attacker_ob->hit_player(30,"other|mental");
		break;
		
		case 1:
		tell_room(environment(),"The Polymorph slurps noisily on "+attacker_ob->query_name()+"'s "+YEL+"FEAR"+NORM+".\n");    /*others*/
		attacker_ob->hit_player(30,"other|mental");
		break;
		
		case 0:
		tell_room(environment(),"The Polymorph slurps noisily on "+attacker_ob->query_name()+"'s "+MAG+"LUST"+NORM+".\n");    /*others*/
		attacker_ob->hit_player(30,"other|mental");
		break;
		
	}
}
