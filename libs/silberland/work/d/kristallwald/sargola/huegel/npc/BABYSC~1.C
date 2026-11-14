/************************************************  
** Schimmlerbaby				*  
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

int rufe();


create()  
{  
     if (!is_clone(TO)) return;  
     ::create();   
     SetProp(P_SHORT, "Ein Schimmlerbaby");  
     SetProp(P_LONG, BS("Wenn es nicht so fuerchterlich zerfranst und "
	+"dreckig waere, waere es ja ein niedliches Baby. So aber hast "
	+"Du sogar vor ihm Angst."));  

     SetProp(P_GENDER, NEUTER);  
     SetProp(P_NAME, "Schimmlerbaby");  
     SetProp(P_ARTICLE, 1);  
     AddId (({"schimmler", "schimmlerbaby", "baby"}));  
     SetProp(P_DIE_MSG, " zerfranst sich in die Hoelle.\n");  
     SetProp(P_NOCORPSE, 1);
     create_default_npc (10);  
     SetProp(P_HANDS, ({" mit ausgefransten Kinderhaenden", 90, DT_BLUDGEON}));  
     SetProp(P_AGGRESSIVE, 0);
   
     SetProp(P_RACE, "Schimmler");  
     SetProp(P_ALIGN, -150);  
     SetProp(P_SIZE, 60);
     
     
     SetProp(P_RESISTANCE_STRENGTHS, 
     	([DT_MAGIC:-0.3,
     	  DT_ACID:-0.3,
     	  DT_POISON:-0.3,
     	  DT_COLD:-0.2,
     	  DT_TERROR:-0.2,
     	  DT_FIRE: -0.3
     	]) );
     
     SetProp(P_NOMAGIC, 35);
 

     SetAttackChats( ({
	"Das Schimmlerbaby rasselt mit seiner Rassel.\n",
	"Dir wird vom Gestank des Babies uebel.\n",
	"Das Schimmlerbaby schlaegt wild um sich.\n"}) );   

	AddSpell (1,0,
	"Das Schimmlerbaby brabbelt einen Vernichtungszauber!\n",
	"Das Schimmlerbaby brabbelt einen Vernichtungszauber!\n",
	DT_MAGIC, ([SP_SHOW_DAMAGE:1]) );

	AddSpell(1,0,
	"Das Schimmlerbaby ruft nach seinem Papi!\n",
	"Das Schimmlerbaby ruft nach seinem Papi!\n",
	DT_MAGIC, "rufe");

}


int rufe()
{
	object ob;
	if(!present("schimmlerpapa"))
	{
	   ob = clone_object(NPC+"spapa");
	   ob->move(environment(TO));
	   ob->Kill(TP);
	   TP->AddPursuer(ob);
	}
}	