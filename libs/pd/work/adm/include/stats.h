#ifndef __STATS_H__
#define __STATS_H__

// the number is the percentage of normal cost
mapping CLASS_STAT_COST = ([
  "fighter" : ([
    "strength" : 70,
    "constitution" : 70,
    "dexterity" : 70,
  ]),
  "paladin" : ([
    "strength" : 80,
    "dexterity" : 80,
    "constitution" : 70,
    "wisdom" : 80,
  ]),
  "antipaladin" : ([
    "strength" : 70,
    "dexterity" : 80,
    "constitution" : 80,
    "wisdom" : 80,
  ]),
  "berserker" : ([
    "strength" : 65,
    "dexterity" : 80,
    "constitution" : 65,
  ]),
  "warrior" : ([
    "strength" : 70,
    "dexterity" : 65,
    "constitution" : 75,
  ]),
  "ranger" : ([
    "strength" : 75,
    "dexterity" : 65,
    "constitution" : 70,
  ]),

  "rogue" : ([
    "dexterity" : 70,
    "charisma" : 70,
    "intelligence" : 70,
  ]),
  "assassin" : ([
    "dexterity" : 60,
    "charisma" : 70,
    "intelligence" : 80,
  ]),
  "thug" : ([
    "strength" : 80,
    "dexterity" : 70,
    "constitution" : 90,
    "charisma" : 70,
    "intelligence" : 100,
  ]),
  "thief" : ([
    "dexterity" : 70,
    "charisma" : 60,
    "intelligence" : 80,
  ]),
  "scout" : ([
    "dexterity" : 60,
    "charisma" : 70,
    "intelligence" : 80,
  ]),

  "wanderer" : ([
    "charisma" : 70,
    "dexterity" : 70,
    "constitution" : 70,
  ]),
  "bard" : ([
    "dexterity" : 80,
    "constitution" : 70,
    "charisma" : 60,
  ]),
  "jester" : ([
    "dexterity" : 65,
    "constitution" : 80,
    "charisma" : 65,
  ]),
  "gypsy" : ([
    "dexterity" : 80,
    "constitution" : 80,
    "charisma" : 70,
    "wisdom" : 80,
  ]),
  "swashbuckler" : ([
    "strength" : 90,
    "dexterity" : 70,
    "constitution" : 70,
    "charisma" : 80
  ]),

  "clergy" : ([
    "wisdom" : 70,
    "strength" : 70,
    "intelligence" : 70,
  ]),
  "cleric" : ([
    "strength" : 80,
    "intelligence" : 70,
    "wisdom" : 60,
  ]),
  "monk" : ([
    "strength" : 70,
    "dexterity" : 90,
    "constitution" : 80,
    "intelligence" : 100,
    "wisdom" : 70
  ]),
  "druid" : ([
    "strength" : 70,
    "constitution" : 90,
    "intelligence" : 80,
    "wisdom" : 70,
  ]),
  "kataan" : ([
    "strength" : 70,
    "dexterity" : 90,
    "intelligence" : 70,
    "wisdom" : 80
  ]),
  "shaman" : ([
    "strength" : 70,
    "charisma" : 90,
    "intelligence" : 80,
    "wisdom" : 70,
  ]),

  "mage" : ([
    "intelligence" : 70,
    "wisdom" : 70,
    "constitution" : 70,
  ]),
  "necromancer" : ([
    "charisma" : 110,
    "constitution" : 75,
    "intelligence" : 60,
    "wisdom" : 70
  ]),
  "wizard" : ([
    "constitution" : 70,
    "intelligence" : 75,
    "wisdom" : 65,
  ]),
  "sorceror" : ([
    "constitution" : 70,
    "intelligence" : 65,
    "wisdom" : 75,
  ]),
  "illusionist" : ([
    "charisma" : 90,
    "constitution" : 80,
    "intelligence" : 60,
    "wisdom" : 80
  ]),
  "conjurer" : ([
    "strength" : 90,
    "constitution" : 75,
    "intelligence" : 70,
    "wisdom" : 75,
  ]),
  
  "elementalist" : ([
  ]),
  "pyromancer" : ([
    "constitution" : 70,
    "intelligence" : 50,
    "wisdom" : 100,
  ]),
  "aquamancer" : ([
    "constitution" : 70,
    "wisdom" : 50,
  ]),
  "aeromancer" : ([
    "dexterity" : 70,
    "intelligence" : 50,
  ]),
  "geomancer" : ([
    "strength" : 70,
    "wisdom" : 50,
  ]),

  // these class bonuses apply in addition to race bonus!
  "dragon" : ([
    "strength" : 80,
    "dexterity" : 80,
    "wisdom" : 80,
    "intelligence" : 80,
  ]),
  "red" : ([
    "strength" : 60,
    "dexterity" : 70,
    "intelligence" : 90,
    "wisdom" : 100,
  ]),
  "white" : ([
    "strength" : 70,
    "dexterity" : 90,
    "intelligence" : 100,
    "wisdom" : 60,
  ]),
  "blue" : ([
    "strength" : 90,
    "dexterity" : 100,
    "intelligence" : 70,
    "wisdom" : 60,
  ]),
  "black" : ([
    "strength" : 90,
    "dexterity" : 100,
    "intelligence" : 60,
    "wisdom" : 70,
  ]),
  "green" : ([
    // use all default dragon class costs
  ]),

  "animal" : ([
    "strength" : 85,
    "dexterity" : 85,
    "constitution" : 85,
    "charisma" : 95,
    "intelligence" : 110,
    "wisdom" : 110,
  ]),
  "strong" : ([
    "strength" : 65,
    "dexterity" : 90,
    "constitution" : 80,
    "charisma" : 110,
  ]),
  "fast" : ([
    "strength" : 100,
    "dexterity" : 60,
    "constitution" : 105,
    "intelligence" : 95,
  ]),
  "sturdy" : ([
    "strength" : 95,
    "dexterity" : 110,
    "constitution" : 65,
    "wisdom" : 95,
  ]),
]);

#endif
