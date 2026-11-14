// MorgenGrauen MUDlib
//
// inpc/boozing.c -- Intelligentes Saufen
//
// $Id: boozing.c,v 3.4 1997/02/05 15:44:09 Rochus Exp $

#define NEED_PROTOTYPES
#include <thing.h>
#include <living.h>
#include <inpc.h>
#include <player/moneyhandler.h>
#include <properties.h>

#define DRINK_IDS 1
#define DRINK_COST 2
#define DRINK_HEAL 3
#define DRINK_ALC 4
#define DRINK_SAT 5

int Drink() {
  mixed drinks;
  object env;
  int heal, heal_max;
  int i,j, max,mon,hdiff;
  heal=0;
  heal_max=0;
  if ((mon=QueryMoney())<=0
      || !(env=environment())
      || !pointerp(drinks=env->query_drink())
      || (hdiff=QueryProp(P_MAX_HP)-QueryProp(P_HP))<=0)
    return 0;
  max=-1;
  for (i=sizeof(drinks)-1;i>=0;i--) {
    if(pointerp(drinks[i][DRINK_HEAL]))
        for(j=sizeof(drinks[i][DRINK_HEAL])-1;j>=0;j--)
           heal+=drinks[i][DRINK_HEAL][j]/sizeof(drinks[i][DRINK_HEAL]);
    else heal=drinks[i][DRINK_HEAL];
   
    if (drinks[i][DRINK_COST]>mon
        || ((drinks[i][DRINK_ALC]+QueryProp(P_ALCOHOL))
	    > (100-QueryProp(P_I_HATE_ALCOHOL)))
        || drinks[i][DRINK_SAT]+QueryProp(P_DRINK)>100
        || heal<=0)
      continue;
   
    if (max<0
        || (heal>heal_max &&
            heal_max<hdiff)
        || (heal>=hdiff &&
            drinks[i][DRINK_COST]<drinks[max][DRINK_COST]))
      max=i;
    if(pointerp(drinks[max][DRINK_HEAL]))
        for(j=sizeof(drinks[max][DRINK_HEAL])-1;j>=0;j--)
           heal_max+=drinks[max][DRINK_HEAL][j]/
                      sizeof(drinks[max][DRINK_HEAL]);
    else heal_max=drinks[max][DRINK_HEAL];
  }
  if (max<0) return 0;
  command("bestell "+drinks[max][DRINK_IDS][0]);
  return 1;
}

void DrinkLoop() {
  while (remove_call_out("DrinkLoop")>=0);
  if (!Drink())
    return;
  call_out("DrinkLoop",0);
}

