/************************************************  
** Grabunhold					*  
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
 
}