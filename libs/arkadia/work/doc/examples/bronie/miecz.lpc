/* miecz dowodczyni strazy (/doc/examples/npce/dowodczyni.c)
 * Napisal Rasputin
 */

inherit "/std/weapon";

#include <stdproperties.h>
#include <wa_types.h>
#include <pl.h>

void
create_weapon() 
{
     ustaw_nazwe(({ "miecz", "miecza", "mieczowi", "miecz", "mieczem", "mieczu" }),
                 ({ "miecze", "mieczy", "mieczom", "miecze", "mieczami", 
                    "mieczach" }), PL_MESKI_NOS_NZYW);
                    
     dodaj_przym( "dlugi", "dludzy" );
                    
     set_long("Dlugi miecz wykonany z mocnej, hartowanej stali.\n");

     set_hit(25);
     set_pen(30);

     set_wt(W_SWORD);
     set_dt(W_SLASH);

     set_hands(W_ANYH);
     
     add_prop(OBJ_I_VALUE, 800);
     add_prop(OBJ_I_WEIGHT, 2500);
     add_prop(OBJ_I_VOLUME, query_prop(OBJ_I_WEIGHT)/5);
 }
   
