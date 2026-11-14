/************************************************  
** Skelett				*  
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


create()  
{  
     if (!is_clone(TO)) return;  
     ::create();   
     SetProp(P_SHORT, "Ein Skelett");  
     SetProp(P_LONG, BS("Tja, da muss mir noch was einfallen..."));  

     SetProp(P_GENDER, NEUTER);  
     SetProp(P_NAME, "Skelett");  
     SetProp(P_ARTICLE, 1);  
     AddId (({"skelett"}));  
     SetProp(P_DIE_MSG, " zerfaellt in tausend Knochen.\n");  
     SetProp(P_NOCORPSE, 1);
     create_default_npc (20);  
     SetProp(P_HANDS, ({" mit schwieligen Haenden", 210, DT_BLUDGEON}));  
     SetProp(P_AGGRESSIVE, 1);
   
     SetProp(P_RACE, "Skelett");  
     SetProp(P_ALIGN, -300);  
     SetProp(P_SIZE, 153);
     
     
     SetProp(P_RESISTANCE_STRENGTHS, 
     	([DT_MAGIC:-0.7,
     	  DT_ACID:-0.7,
     	  DT_POISON:-0.9,
     	  DT_COLD:-0.3,
     	  DT_TERROR:-0.3,
     	  DT_FIRE: -0.7
     	]) );
     
     SetProp(P_NOMAGIC, 75);
 

     SetAttackChats( ({
	"Der Skeletton wirft Dir einen Knochen genau ins Aug!\n",
	"Der Skeletton wuergt Dich mit seiner knochrigen Hand.\n",
	"Der Skeletton weicht Deinem Schlag geschickt aus.\n" }) );   

}