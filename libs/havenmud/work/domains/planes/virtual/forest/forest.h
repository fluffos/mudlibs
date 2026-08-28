#define FOREST_PLANE "/domains/planes/virtual/forest/"

string *Longs = ({
  "The forest continues endlessly onward in all directions.",
  "The trees list around lazily, seeming to soak up the light.",
  "The ground seems to be amazingly clear of debris.",
  "The trees reach for the heavens as if to defy the gods themselves.",
  "There is an intangible aura of evil to this forest.",
  "The trees seem slightly less dense to the east.",
  "The trees seem slightly less dense to the north.",
  "The trees seem slightly less dense to the south.",
  "The trees seem slightly less dense to the west.",
  "The trees seem slightly more dense to the north.",
  "The trees seem slightly more dense to the south.",
  "The trees seem slightly more dense to the east.",
  "The trees seem slightly more dense to the west.",
  "The sky seems hidden by the trees.",
  "What little view of the sky can be seen is oddly blank of clouds "
  "or sights.",
});


string *Smells = ({
  "The scent of fresh wood hangs in the air.",
  "The scents of forest life drift into the air.",
  "The air is crisp and fresh.",
  "There is a light and fresh breeze.",
});

string *Listens = ({
  "The sounds of forest life seem quiet and subdued.",
  "The sounds of the forest are vibrant and alive.",
  "The sounds of forest life come clearly from the north.",
  "The forest seems deathly quiet.",
  "The forest seems to abound with the sounds of life.",
  "The quiet on the air is disturbing.",
});

mapping NPCs = ([
  PLANE_NPC + "pf": 250,
  PLANE_NPC + "planeswalker": 150,
  PLANE_NPC + "thing": 3,
  PLANE_NPC + "maralith": 250,
  PLANE_NPC + "bane": 150,
  PLANE_NPC + "harpy": 20,
  PLANE_NPC + "girlnymph": 10,
  PLANE_NPC + "barbed": 100,
  PLANE_NPC + "lemure": 25,
  PLANE_NPC + "biglizard": 50,
]);

mapping Objects = ([
]);
