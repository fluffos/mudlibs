#define WEAPON(name,m) \
  if (!present(name,m))\
    move_object(clone_object(WEAPONS+name),m);\
  command ("wield "+name,m)

#define ARMOUR(name,filename,m) \
  if (!present(name,m))\
    move_object(clone_object(ARMOURS+filename),m);\
  command("wear "+name,m)

#define ARMOUR_CONFIG(name,filename,m) \
  if (!present(name,m))\
    move_object(clone_object(ARMOURS+filename)->config(m),m);\
  command("wear "+name,m)
