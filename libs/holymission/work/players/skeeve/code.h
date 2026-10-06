#define WEAPON(name,m) \
  if (!present(name,m))\
    move_object(clone_object(WEAPONS+name),m);\
  (m)->force_me("wield "+name)

#define ARMOUR(name,filename,m) \
  if (!present(name,m))\
    move_object(clone_object(ARMOURS+filename),m);\
  (m)->force_me("wear "+name)

#define ARMOUR_CONFIG(name,filename,m) \
  if (!present(name,m))\
    move_object(clone_object(ARMOURS+filename)->config(m),m);\
  (m)->force_me("wear "+name)
