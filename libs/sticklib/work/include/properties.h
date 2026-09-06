/*
 * properties.h
 *
 * (Most of these just design. Do change)
 */
 
#ifndef PROPERTIES_H
#define PROPERTIES_H
 
/* *********************************************************
 * Special properties
 */
#define LOCK_OBJECT             -2
#define NO_CLEAN_UP             -1

/* *********************************************************
 * Basic properties
 */
#define SHORT_DESC              4
#define LONG_DESC               6
 
#define LIGHTS_IN               10
#define LIGHTS_OUT              11
 
#define ITEMS                   20      /* pseudo items */

/* *********************************************************
 * Object properties
 */
#define ID_LIST                 1
#define PID_LIST                2
#define ADJ_LIST                3

#define OBJ_SHORT               4
#define OBJ_PSHORT              5
#define OBJ_LONG                6

#define OBJ_WEIGHT              100
#define OBJ_VOLUME              101

#define OBJ_VALUE               110
#define OBJ_VISIBILITY          111

#define OBJ_NO_GET              120
#define OBJ_NO_DROP             121

/* *********************************************************
 * Container properties
 */
#define CONT_LIGHT              10
#define CONT_WEIGHT             200
#define CONT_VOLUME             201
#define CONT_TRANSP             202
#define CONT_CLOSED             203
#define CONT_LOCK               204
#define CONT_MAX_WEIGHT         205
#define CONT_MAX_VOLUME         206
#define CONT_RIGID              207

/* *********************************************************
 * Room properties
 */
#define SHORT_EXITS		7
#define ROOM_LIGHT              10
#define ROOM_OUTDOORS           300
#define WD_TYPE                 300
#define ROOM_TYPE               301

#define ROOM_NO_MAGIC           350
#define ROOM_NO_TELEPORT	351
#define ROOM_NO_ATTACK          353
#define ROOM_NO_PLAYER_KILLING	354

/* *********************************************************
 * Weapon properties
 */
#define WPN_TYPE                400
#define WPN_CLASS               401
#define WPN_CONDITION           402
#define WPN_SHARPNESS           403
 
/* *********************************************************
 * Armour properties
 */
#define ARM_TYPE                500
#define ARM_CLASS               501
#define ARM_RESIST              502

/* *********************************************************
 * Living properties
 */
#define LIV_REAL_NAME           601
#define LIV_NAME                602
#define LIV_RACE                605
#define LIV_TMP_RACE            606

/* *********************************************************
 * Heap properties
 */
#define HEAP_UNIT_COUNT         700
#define HEAP_ID                 701
#define HEAP_UNIT_WEIGHT        702
#define HEAP_UNIT_VOLUME        703
#define HEAP_UNIT_VALUE         704


/* IDEAS:
   VALUE_GP, VALUE_SP, etc..
   WEIGHT_G (in grams or pounds or something.. current ones suck)
   TMP_SHORT TMP_LONG ???
*/

#endif

