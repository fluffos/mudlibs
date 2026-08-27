/* 
    drink_eat.h

    Formulas and constants related to food and drinks
*/

#ifndef DRINKFOOD_DEF
#define DRINKFOOD_DEF

#define CAN_DRINK_ALCO(curtox, mintox, maxtox, strength) 	\
     (								\
      (strength >= 0) ? (((curtox + strength) <= maxtox) &&  	\
			 (strength <= (maxtox / 3)))  		\
                      :  (((curtox + strength) >= mintox) && 	\
			  (strength >= (mintox / 2)))		\
    )

#define CAN_EAT_FOOD(curam, maxam, amount)				   \
  (									   \
   (amount >= 0) ? (((curam + amount) <= maxam) && (amount <= maxam / 2))  \
		 : ((curam + amount) >= 0)				   \
  )

#include "/config/sys/drink_eat2.h"

#endif DRINKFOOD_DEF
