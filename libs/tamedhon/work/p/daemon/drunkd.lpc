
// Tamedhon MUDlib
//
// $Date: 2003/02/23 12:15:00 $
/* $Revision: 1.0 $
 * Implementierung
 */

/*
 * DRUNKD.C -- Der Daemon fuer Betrunkene im Mud
 * Tamedhon Mudlib
 *
 * Author:
 *   Querolin@Tamedhon
 * Zweck:
 *   Betrunkene erhalten entsprechende Sprachausgaben...
 */

#define NEED_PROTOTYPES

#include <thing/properties.h>
#include <daemon.h>
#include <properties.h>
#include <wizlevels.h>
#include <udp.h>
#include <defines.h>
#include <terminal.h>
#include <ansi.h>

#define DEBUG(x)     if(find_player("querolin")) tell_object(find_player("querolin"), sprintf("-> %O\n", x))

string drunkspeach(string whattosay, object player)
{
  string str;
  int alclvl,c;

  alclvl= ( 100 * player->QueryProp(P_ALCOHOL) ) / 
            player->QueryProp(P_MAX_ALCOHOL); 
  str = 0;

//  DEBUG(alclvl);
//  DEBUG("A:"+whattosay+"\n");

  if (alclvl>33)
  {
     switch(alclvl) {
       default:
       case 1..33: return 0;

       case 34..66:
           str="^"+whattosay+"^";
           str=implode(explode(str, "ch"), "h");
           str=implode(explode(str, "ss"), "s");
           str=implode(explode(str, "s"), "sch");
           str=implode(explode(str, "S"), "Sch");
           str=extract(str, 1, sizeof(str)-2);
         break;

       case 67..90:  
           str="^"+whattosay+"^"; 
           str=implode(explode(str, "ch"), "h");
           str=implode(explode(str, "ss"), "s");
           str=implode(explode(str, "s"), "sch");
           str=implode(explode(str, "S"), "Sch");
           str=implode(explode(str, "k"), "k-k");
           str=implode(explode(str, "K"), "K-k");
           str=implode(explode(str, "p"), "b");
           str=implode(explode(str, "er"), "a");
           str=implode(explode(str, "r"), "'");
           str=implode(explode(str, "R"), "'");
           str=extract(str, 1, sizeof(str)-2);
         break;

       case 91..999:
           str="";
           for(c=0;c<sizeof(whattosay);c++) {
              switch(random(10)) {
                 default:
                 case 0..4:
                   str+="l";
                 break;
                 case 5..7:
                   str+="a";
                 break;
                 case 8..9:
                   str+=" ";
              }
           }
         break;

      if (random(100)>85) { str+=" <Hick>"; }

     }
//    DEBUG("E:"+str+"\n");
    return str;
  }
  else { return 0; }
}
