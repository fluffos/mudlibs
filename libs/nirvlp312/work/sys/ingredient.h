/*
 * sys/ingredient.h
 *
 * this is a collection of possible ingredients for items which can be
 * mixed into mixtures.
 *
 * 
 */

#ifndef _sys_ingredient_h
#define _sys_ingredient_h

#define ING_FENNEL     "fennel"
#define ING_SULFUR     "sulfur"
#define ING_MUSHROOM   "mushroom"
#define ING_CHAMPIGNON "champignon"
#define ING_FLY_AGARIC "fly_agaric"

#define ING_PROD_SCRAPE  "scrape"     /* rub on the material to
                                       * split off a powder
                                       */
#define ING_PROD_SQUELCH "squelch"    /* stomp the material to convert
                                       * it into a powder
                                       */
#define ING_PROD_CHOP    "chop"       /* cut the material in very fine
                                       * bits to convert it into a paste
                                       */
#define ING_PROD_MELT    "melt"       /* heat up the material until
                                       * it gets liquid
                                       */
#define ING_PROD_DISSOLVE "dissolve"  /* put into a liquid which takes
                                       * off material from the surface
                                       */

#endif
