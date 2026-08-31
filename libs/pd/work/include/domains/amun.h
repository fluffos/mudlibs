#ifndef __AMUN_H_
#define __AMUN_H_

#define ROOMS "/d/inferi_island/hamenstomb/rooms/"
#define MON "/d/inferi_island/hamenstomb/mobs/"
#define WEP "/d/inferi_island/hamenstomb/weapons/"
#define ARM "/d/inferi_island/hamenstomb/armour/"

#define MARSHROOM "/d/inferi_island/marshes/rooms/"
#define MARSHMON "/d/inferi_island/marshes/mobs/"
#define MARSHWEP "/d/inferi_island/marshes/weapons/"
#define MARSHARM "/d/inferi_island/marshes/armour/"

#define HELLROOM "/d/inferi_island/eyeofhell/rooms/"
#define HELLMON "/d/inferi_island/eyeofhell/mobs/"
#define HELLWEP "/d/inferi_island/eyeofhell/weapons/"
#define HELLARM "/d/inferi_island/eyeofhell/armour/"

#define GUILDROOM "/d/guilds/lastsaints/rooms/"
#define GUILDMOB "/d/guilds/lastsaints/mobs/"
#define GUILDWEP "/d/guilds/lastsaints/weapons/"
#define GUILDARM "/d/guilds/lastsaints/armour/"
#define GUILDOBJ "/d/guilds/lastsaints/objects/"  

#define HEVROOM "/wizards/amun/heaven/rooms/"
#define HEVMOB "/wizards/amun/heaven/mobs/"
#define HEVWEP "/wizards/amun/heaven/weapons/"
#define HEVARM "/wizards/amun/heaven/armour/"
#define HEVOBJ "/wizards/amun/heaven/objects/"  

#define SKYROOM "/wizards/amun/sky/rooms/"
#define SKYMOB "/wizards/amun/sky/mobs/"
#define SKYWEP "/wizards/amun/sky/weapons/"
#define SKYARM "/wizards/amun/sky/armour/"
#define SKYOBJ "/wizards/amun/sky/objects/" 
#define AMUNLIGHTNINGROOM "/wizards/amun/sky/lightningroom"

#define ILLROOM "/wizards/amun/illuminati/rooms/"
#define ILLMOB "/wizards/amun/illuminati/mobs/"
#define ILLWEP "/wizards/amun/illuminati/weapons/"
#define ILLARM "/wizards/amun/illuminati/armour/"
#define ILLOBJ "/wizards/amun/illuminati/objects/" 

#define FR "/wizards/amun/fallenangels/rooms"
#define FM "/wizards/amun/fallenangels/mobs"
#define FW "/wizards/amun/fallenangels/weapons"
#define FA "/wizards/amun/fallenangels/armour"
#define FO "/wizards/amun/fallenangels/objects"

int sp_sap() {
object tp = this_player();
if (tp && !tp->query_riding()) {
tp->add_sp(-50); 
write("You feel weaker as you move through the swamp."); 
}
return 1; }

#endif
