/************************************************  
** Schimmler				*  
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

int fressen ();

create()  
{  
     if (!is_clone(TO)) return;  
     ::create();   
     SetProp(P_SHORT, "Ein Schimmler");  
     SetProp(P_LONG, BS("Die gebueckte Gestalt des gemeinen, stinkenden "
		+"Schimmlers floesst Dir Furcht ein. Nicht nur seine "
		+"Kleidung, auch er selbst scheint zerfetzt und zer"
		+"franst zu sein."));  

     SetProp(P_GENDER, MALE);  
     SetProp(P_NAME, "Schimmler");  
     SetProp(P_ARTICLE, 1);  
     AddId (({"schimmler"}));  
     SetProp(P_DIE_MSG, " zerfranst sich in die Hoelle.\n");  
     SetProp(P_NOCORPSE, 1);
     create_default_npc (18);  
     SetProp(P_HANDS, ({" mit ausgefransten Haenden", 1190, DT_TERROR}));  
     SetProp(P_AGGRESSIVE, 1);
   
     SetProp(P_RACE, "Schimmler");  
     SetProp(P_ALIGN, -350);  
     SetProp(P_SIZE, 167);
     
     
     SetProp(P_RESISTANCE_STRENGTHS, 
     	([DT_MAGIC:-0.3,
     	  DT_ACID:-0.3,
     	  DT_POISON:-0.3,
     	  DT_COLD:-0.2,
     	  DT_TERROR:-0.2,
     	  DT_FIRE: -0.3
     	]) );
     
     SetProp(P_NOMAGIC, 45);
 

     SetAttackChats( ({
	"Der Schimmler wirft Dir ein Stueck seines Fleisches entgegen.\n",
	"Dir wird vom Gestank des Schimmlers uebel.\n",
	"Der Schimmler ruft laut um Hilfe.\n",
	"Der Schimmler trifft Dich extrem hart.\n"}) );   

	AddSpell (1,0,
	"Der Schimmler stuerzt sich auf Dich und nagt an Dir!\n",
	"Der Schimmler stuerzt sich auf @WEN und nagt an ihm!\n",
	DT_MAGIC, ([SP_SHOW_DAMAGE:1]), "fressen" );

}

int fressen()
{
	//blablabla
}