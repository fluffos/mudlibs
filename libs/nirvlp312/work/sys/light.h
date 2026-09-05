#ifndef _sys_light_h
#define _sys_light_h

#define LIGHT_CANDLE       1000
#define LIGHT_TORCH        5000
#define LIGHT_LAMP        15000

#define LIGHT_DARKNESS_THRESHOLD        1000

#define LIGHT_BRIGHTNESS_THRESHOLD      140000000

/* These two values are used at adaptation of eyes to surrounding light levels
 * if a living is adapted perfectly to a room with light level X, then it
 * will be able to see in rooms with light level
 * X/LIGHT_DARKNESS_TOLERANCE .. X*LIGHT_BRIGHTNESS_TOLERANCE
 */
#define LIGHT_DARKNESS_TOLERANCE 10
#define LIGHT_BRIGHTNESS_TOLERANCE 20

/* below X/LIGHT_DARKNESS_MARGIN and above X*LIGHT_BRIGHTNESS_MARGIN
 * a living will not see _everything_ but just a part of the things
 */
#define LIGHT_DARKNESS_MARGIN 9
#define LIGHT_BRIGHTNESS_MARGIN 18

/* the next values are permille values
 * example: a dense forest would receive 200 permille of that at noon
 */
#define LIGHT_F_INSIDE         500
#define LIGHT_F_FOREST_LIGHT   800
#define LIGHT_F_FOREST_NORMAL  600
#define LIGHT_F_FOREST_DENSE   400
#define LIGHT_F_DESERT_ICE    1600
#define LIGHT_F_DESERT_SAND   1300
#define LIGHT_F_DESERT_ROCK   1100
#define LIGHT_F_UNDERGROUND    100
#define LIGHT_F_MOUNTAIN      1100
#define LIGHT_F_UNDER_WATER    500
#define LIGHT_F_VILLAGE       1200 /* only used at night */

#endif /* _sys_light_h */
