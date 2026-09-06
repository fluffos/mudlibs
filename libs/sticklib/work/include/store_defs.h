#ifndef STORE_DEFS_H
#define STORE_DEFS_H

#define DOOR_EAST               0
#define DOOR_NORTHEAST          1
#define DOOR_NORTH              2
#define DOOR_NORTHWEST          3
#define DOOR_WEST               4
#define DOOR_SOUTHWEST          5
#define DOOR_SOUTH              6
#define DOOR_SOUTHEAST          7

#define BUY_AND_SELL            (1 << 3)
#define STORE_ARMOUR            (1 << 4)
#define STORE_WEAPON            (1 << 5)
#define STORE_GENERAL           (1 << 6)
#define STORE_SCROLL            (1 << 7)
#define STORE_POTION            (1 << 8)

#define STORE_FILE              "/lib/store"

#endif /* STORE_DEFS_H */
