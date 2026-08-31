#ifndef __ITEMSPEC_CL_H__
#define __ITEMSPEC_CL_H__

class ItemSpec {
  // common stuff
  // not including name, since it's always remove_article(short)
  string *id;
  string short;
  string long;
  int weight;

  // max ac/wc/strength/capacity/etc of item
  int max;

  // type for weapons, armour, drinks
  string type;

  int ac; 
  int wc; 

  int strength;
  int servings;

  int capacity;

  // for anything else needed, such as messages for food/drink
  mixed misc;
}

#endif
