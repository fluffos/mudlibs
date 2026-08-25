//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef settlements_h
#define settlements_h

private mapping Settlements = ([ 
    "settlement 1":([
        "type": "forest",
        "terrain": "/lib/environment/terrain/forest-clearing.lpc",
        "x dimension": 4,
        "y dimension": 3,
        "size": 12,
        "layout": ([
            0:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/shops/blacksmith.lpc",
                    "exits": ([ 
                        "north": ({ 0, 1 }) 
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 0, 0 }), 
                        "north" : ({ 2, 0 }),
                        "east": ({ 1, 1 })
                    ]),
                    "buildings": ([
                        "north": "/lib/environment/buildings/shops/general-shop.lpc",
                        "south": "/lib/environment/buildings/shops/blacksmith.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/shops/general-shop.lpc",
                    "exits": ([ 
                        "south": ({ 0, 1 }), 
                    ])
                ]),
            ]),
            1:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/trades/guild-hall.lpc",
                    "exits": ([ 
                        "north" : ({ 1, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 1, 0 }), 
                        "north" : ({ 1, 2 }),
                        "east": ({ 2, 1 }),
                        "west": ({ 0, 1 })
                    ]),
                    "buildings": ([
                        "north": "/lib/environment/buildings/shops/inn.lpc",
                        "south": "/lib/environment/buildings/trades/guild-hall.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/shops/inn.lpc",
                    "exits": ([ 
                        "south": ({ 1, 1 }), 
                    ])
                ]),
            ]),
            2:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/trades/lumber-mill.lpc",
                    "exits": ([ 
                        "north" : ({ 2, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 2, 0 }), 
                        "north" : ({ 2, 2 }),
                        "east": ({ 3, 1 }),
                        "west": ({ 1, 1 })
                    ]),
                    "buildings": ([
                        "south": "/lib/environment/buildings/trades/lumber-mill.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 2, 1 }), 
                    ]),
                    "buildings": ([
                        "east": "/lib/environment/buildings/trades/stable.lpc",
                        "west": "/lib/environment/buildings/shops/inn.lpc"
                    ]),
                ]),
            ]),
            3:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/religious/church.lpc",
                    "exits": ([ 
                        "north" : ({ 3, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 3, 0 }), 
                        "north" : ({ 3, 2 }),
                        "west": ({ 2, 1 })
                    ]),
                    "buildings": ([
                        "north": "/lib/environment/buildings/trades/stable.lpc",
                        "south": "/lib/environment/buildings/religious/church.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/trades/stable.lpc",
                    "exits": ([ 
                        "south": ({ 3, 1 }), 
                    ]),
                ]),
            ]),
        ]),
    ]),
    "settlement 2":([
        "type": "forest",
        "terrain": "/lib/environment/terrain/forest-clearing.lpc",
        "x dimension": 4,
        "y dimension": 3,
        "size": 12,
        "layout": ([
            0:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/shops/swordsmith.lpc",
                    "exits": ([ 
                        "north": ({ 0, 1 }) 
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 0, 0 }), 
                        "north" : ({ 2, 0 }),
                        "east": ({ 1, 1 })
                    ]),
                    "buildings": ([
                        "north": "/lib/environment/buildings/shops/general-shop.lpc",
                        "south": "/lib/environment/buildings/shops/swordsmith.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/shops/general-shop.lpc",
                    "exits": ([ 
                        "south": ({ 0, 1 }), 
                    ])
                ]),
            ]),
            1:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/trades/guild-hall.lpc",
                    "exits": ([ 
                        "north" : ({ 1, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 1, 0 }), 
                        "north" : ({ 1, 2 }),
                        "east": ({ 2, 1 }),
                        "west": ({ 0, 1 })
                    ]),
                    "buildings": ([
                        "north": "/lib/environment/buildings/shops/inn.lpc",
                        "south": "/lib/environment/buildings/trades/guild-hall.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/shops/inn.lpc",
                    "exits": ([ 
                        "south": ({ 1, 1 }), 
                    ])
                ]),
            ]),
            2:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/trades/lumber-mill.lpc",
                    "exits": ([ 
                        "north" : ({ 2, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 2, 0 }), 
                        "north" : ({ 2, 2 }),
                        "east": ({ 3, 1 }),
                        "west": ({ 1, 1 })
                    ]),
                    "buildings": ([
                        "south": "/lib/environment/buildings/trades/lumber-mill.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 2, 1 }), 
                    ]),
                    "buildings": ([
                        "east": "/lib/environment/buildings/trades/stable.lpc",
                        "west": "/lib/environment/buildings/shops/inn.lpc"
                    ]),
                ]),
            ]),
            3:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/religious/church.lpc",
                    "exits": ([ 
                        "north" : ({ 3, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 3, 0 }), 
                        "north" : ({ 3, 2 }),
                        "west": ({ 2, 1 })
                    ]),
                    "buildings": ([
                        "north": "/lib/environment/buildings/trades/stable.lpc",
                        "south": "/lib/environment/buildings/religious/church.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/trades/stable.lpc",
                    "exits": ([ 
                        "south": ({ 3, 1 }), 
                    ]),
                ]),
            ]),
        ]),
    ]),
    "settlement 3":([
        "type": "forest",
        "terrain": "/lib/environment/terrain/forest-clearing.lpc",
        "x dimension": 3,
        "y dimension": 3,
        "size": 9,
        "layout": ([
            0:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/shops/blacksmith.lpc",
                    "exits": ([ 
                        "north": ({ 0, 1 }) 
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 0, 0 }), 
                        "north" : ({ 2, 0 }),
                        "east": ({ 1, 1 })
                    ]),
                    "buildings": ([
                        "north": "/lib/environment/buildings/shops/general-shop.lpc",
                        "south": "/lib/environment/buildings/shops/blacksmith.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/shops/general-shop.lpc",
                    "exits": ([ 
                        "south": ({ 0, 1 }), 
                    ])
                ]),
            ]),
            1:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/trades/inn.lpc",
                    "exits": ([ 
                        "north" : ({ 1, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 1, 0 }), 
                        "north" : ({ 1, 2 }),
                        "east": ({ 2, 1 }),
                        "west": ({ 0, 1 })
                    ]),
                    "buildings": ([
                        "east": "/lib/environment/buildings/religious/church.lpc",
                        "south": "/lib/environment/buildings/shops/inn.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 1, 1 }),
                        "east": ({ 2, 1 }),
                    ]),
                    "buildings": ([
                        "west": "/lib/environment/buildings/shops/general-shop.lpc",
                        "east": "/lib/environment/buildings/trades/stable.lpc"
                    ]),
                ]),
            ]),
            2:([
                0: ([ 
                    "type": "none", 
                ]),
                1: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/religious/church.lpc",
                    "exits": ([ 
                        "west": ({ 1, 1 }), 
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/trades/stable.lpc",
                    "exits": ([ 
                        "west" : ({ 1, 2 }),
                    ])
                ]),
            ]),
        ]),
    ]),
    "rural settlement 1":([
        "type": "rural",
        "terrain": "/lib/environment/terrain/forest-clearing.lpc",
        "x dimension": 4,
        "y dimension": 3,
        "size": 12,
        "layout": ([
            0:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/shops/blacksmith.lpc",
                    "exits": ([ 
                        "north": ({ 0, 1 }) 
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 0, 0 }), 
                        "north" : ({ 2, 0 }),
                        "east": ({ 1, 1 })
                    ]),
                    "buildings": ([
                        "north": "/lib/environment/buildings/shops/general-shop.lpc",
                        "south": "/lib/environment/buildings/shops/blacksmith.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/shops/general-shop.lpc",
                    "exits": ([ 
                        "south": ({ 0, 1 }), 
                    ])
                ]),
            ]),
            1:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/trades/guild-hall.lpc",
                    "exits": ([ 
                        "north" : ({ 1, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 1, 0 }), 
                        "north" : ({ 1, 2 }),
                        "east": ({ 2, 1 }),
                        "west": ({ 0, 1 })
                    ]),
                    "buildings": ([
                        "north": "/lib/environment/buildings/shops/inn.lpc",
                        "south": "/lib/environment/buildings/trades/guild-hall.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/shops/inn.lpc",
                    "exits": ([ 
                        "south": ({ 1, 1 }), 
                    ])
                ]),
            ]),
            2:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/trades/lumber-mill.lpc",
                    "exits": ([ 
                        "north" : ({ 2, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 2, 0 }), 
                        "north" : ({ 2, 2 }),
                        "east": ({ 3, 1 }),
                        "west": ({ 1, 1 })
                    ]),
                    "buildings": ([
                        "south": "/lib/environment/buildings/trades/lumber-mill.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 2, 1 }), 
                    ]),
                    "buildings": ([
                        "east": "/lib/environment/buildings/trades/stable.lpc",
                        "west": "/lib/environment/buildings/shops/inn.lpc"
                    ]),
                ]),
            ]),
            3:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/religious/church.lpc",
                    "exits": ([ 
                        "north" : ({ 3, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 3, 0 }), 
                        "north" : ({ 3, 2 }),
                        "west": ({ 2, 1 })
                    ]),
                    "buildings": ([
                        "north": "/lib/environment/buildings/trades/stable.lpc",
                        "south": "/lib/environment/buildings/religious/church.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/trades/stable.lpc",
                    "exits": ([ 
                        "south": ({ 3, 1 }), 
                    ]),
                ]),
            ]),
        ]),
    ]),
    "rural settlement 2":([
        "type": "rural",
        "terrain": "/lib/environment/terrain/forest-clearing.lpc",
        "x dimension": 4,
        "y dimension": 3,
        "size": 12,
        "layout": ([
            0:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/shops/swordsmith.lpc",
                    "exits": ([ 
                        "north": ({ 0, 1 }) 
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 0, 0 }), 
                        "north" : ({ 2, 0 }),
                        "east": ({ 1, 1 })
                    ]),
                    "buildings": ([
                        "north": "/lib/environment/buildings/shops/general-shop.lpc",
                        "south": "/lib/environment/buildings/shops/swordsmith.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/shops/general-shop.lpc",
                    "exits": ([ 
                        "south": ({ 0, 1 }), 
                    ])
                ]),
            ]),
            1:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/trades/guild-hall.lpc",
                    "exits": ([ 
                        "north" : ({ 1, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 1, 0 }), 
                        "north" : ({ 1, 2 }),
                        "east": ({ 2, 1 }),
                        "west": ({ 0, 1 })
                    ]),
                    "buildings": ([
                        "north": "/lib/environment/buildings/shops/inn.lpc",
                        "south": "/lib/environment/buildings/trades/guild-hall.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/shops/inn.lpc",
                    "exits": ([ 
                        "south": ({ 1, 1 }), 
                    ])
                ]),
            ]),
            2:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/trades/lumber-mill.lpc",
                    "exits": ([ 
                        "north" : ({ 2, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 2, 0 }), 
                        "north" : ({ 2, 2 }),
                        "east": ({ 3, 1 }),
                        "west": ({ 1, 1 })
                    ]),
                    "buildings": ([
                        "south": "/lib/environment/buildings/trades/lumber-mill.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 2, 1 }), 
                    ]),
                    "buildings": ([
                        "east": "/lib/environment/buildings/trades/stable.lpc",
                        "west": "/lib/environment/buildings/shops/inn.lpc"
                    ]),
                ]),
            ]),
            3:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/religious/church.lpc",
                    "exits": ([ 
                        "north" : ({ 3, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 3, 0 }), 
                        "north" : ({ 3, 2 }),
                        "west": ({ 2, 1 })
                    ]),
                    "buildings": ([
                        "north": "/lib/environment/buildings/trades/stable.lpc",
                        "south": "/lib/environment/buildings/religious/church.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/trades/stable.lpc",
                    "exits": ([ 
                        "south": ({ 3, 1 }), 
                    ]),
                ]),
            ]),
        ]),
    ]),
    "rural settlement 3":([
        "type": "rural",
        "terrain": "/lib/environment/terrain/forest-clearing.lpc",
        "x dimension": 3,
        "y dimension": 3,
        "size": 9,
        "layout": ([
            0:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/shops/blacksmith.lpc",
                    "exits": ([ 
                        "north": ({ 0, 1 }) 
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 0, 0 }), 
                        "north" : ({ 2, 0 }),
                        "east": ({ 1, 1 })
                    ]),
                    "buildings": ([
                        "north": "/lib/environment/buildings/shops/general-shop.lpc",
                        "south": "/lib/environment/buildings/shops/blacksmith.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/shops/general-shop.lpc",
                    "exits": ([ 
                        "south": ({ 0, 1 }), 
                    ])
                ]),
            ]),
            1:([
                0: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/trades/inn.lpc",
                    "exits": ([ 
                        "north" : ({ 1, 1 }),
                    ])
                ]),
                1: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 1, 0 }), 
                        "north" : ({ 1, 2 }),
                        "east": ({ 2, 1 }),
                        "west": ({ 0, 1 })
                    ]),
                    "buildings": ([
                        "east": "/lib/environment/buildings/religious/church.lpc",
                        "south": "/lib/environment/buildings/shops/inn.lpc"
                    ]),
                ]),
                2: ([ 
                    "type": "path", 
                    "path": "/lib/environment/features/paths/road.lpc",
                    "exits": ([ 
                        "south": ({ 1, 1 }),
                        "east": ({ 2, 1 }),
                    ]),
                    "buildings": ([
                        "west": "/lib/environment/buildings/shops/general-shop.lpc",
                        "east": "/lib/environment/buildings/trades/stable.lpc"
                    ]),
                ]),
            ]),
            2:([
                0: ([ 
                    "type": "none", 
                ]),
                1: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/religious/church.lpc",
                    "exits": ([ 
                        "west": ({ 1, 1 }), 
                    ]),
                ]),
                2: ([ 
                    "type": "building", 
                    "path": "/lib/environment/buildings/trades/stable.lpc",
                    "exits": ([ 
                        "west" : ({ 1, 2 }),
                    ])
                ]),
            ]),
        ]),
    ]),

]);

#endif
