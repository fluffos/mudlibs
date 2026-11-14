/************************************************  
** dunkler Grabunhold				*  
** 					      	*  
** date: 23-09-97 by Sargola@Silberland     	*  
** Email: a9504778@unet.univie.ac.at         	*  
*************************************************  
** Updates:       :        
** Updates:       :        
** Updates:       :        
**   
*/  
  
inherit "std/npc";  
#include <properties.h>  
#include <language.h>  
#include <combat.h>  
#include <new_skills.h>  
#include <moving.h>

#include "../def.h"  
#include "dead.h"

iss(object a, object b);

create()  
{  
     if (!is_clone(TO)) return;  
     ::create();   
     SetProp(P_SHORT, "Ein Grabunhold");  
     SetProp(P_LONG, BS("."));  

     SetProp(P_GENDER, MALE);  
     SetProp(P_NAME, "Grabunhold");  
     SetProp(P_ARTICLE, 1);  
     AddId (({"unhold", "grabunhold"}));  
     SetProp(P_DIE_MSG, " bricht mit einem lauten Schrei zusammen.\n");  
     SetProp(P_NOCORPSE, 0);
     create_default_npc (25);  
     SetProp(P_HANDS, ({" mit schwieligen Haenden", 250, DT_BLUDGEON}));  
     SetProp(P_AGGRESSIVE, 1);
   
     SetProp(P_HEAL, -20);  
     SetProp(P_RACE, "Mensch");  
     SetProp(P_ALIGN, -400);  
     SetProp(P_SIZE, 173);
     
     
     SetProp(P_RESISTANCE_STRENGTHS, 
     	([DT_MAGIC:-0.6,
     	  DT_ACID:-0.6,
     	  DT_POISON:-0.8,
     	  DT_COLD:-0.2,
     	  DT_TERROR:-0.2,
     	  DT_FIRE: -0.6
     	]) );
     
     SetProp(P_NOMAGIC, 65);
 
     AddSpell(3, 220,
	"Der Grabunhold erschreckt Dich zu Tode.\n",
	"Der Grabunhold erschreckt @WEN zu Tode.\n",
	DT_TERROR,  ([SP_SHOW_DAMAGE:1]) );
 

     AddSpell(8,120,
	"Du riechst den Gestank des Grabunholdes.\n",
	"@WER riecht den Gestankd des Grabunholdes.\n",
	DT_AIR, ([SP_SHOW_DAMAGE:1]) );

     AddSpell(1, 700,
	"Der Grabunhold beschwoert den Tod auf Dich herab.\n",
	"Der Grabunhold beschwoert den Tod fuer @WEN.\n",
	DT_MAGIC, ([SP_SHOW_DAMAGE:1]) );

}


void die(int dead)
{	object ob, geier;						
	object player;
	player = TP;								
	tell_room(environment(player), BS("Von "	
	+"oben kommt ein Aasgeier heruntergestuerzt und schnappt sich "
	+"die Leiche und alle Habseligkeiten!\n"));				
	geier = clone_object(NPC+"aasgeier");				
	geier->move(environment(player), M_GO);				
	::die(dead);
	iss(player,geier);
}
iss(object player, object geier)
{
	object ob;
	ob = present("ueberrest", environment(player));	
	write(ob);
	if(objectp(ob)) ob->remove();
	write(geier);
	geier->command("iss leiche");
	geier->command("nimm alles");
}
	


NotifyPlayerDeath(player)						
{	object ob, geier;						
									
	tell_room(environment(TO), BS("Kaum ist "+player->name(WER)+" verendet, kommt von "	
	+"oben ein Aasgeier heruntergestuerzt und schnappt sich die Leiche "	
	+"und alle Habseligkeiten!\n"));				
	geier = clone_object(NPC+"aasgeier");				
	geier->move(environment(TO), M_GO);				
	ob = present("leiche",environment(TO));				
	if(objectp(ob)) ob->remove();					
	//geier->command("iss leiche");					
	geier->command("nimm alles");					
	return 1;							
}
