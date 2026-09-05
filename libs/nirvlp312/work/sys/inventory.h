#ifndef _INVENTORY_H
#define _INVENTORY_H

#define INVENTORY(ob,id) ((ob)->get_inventory(id) || all_inventory(ob))
#define ENVIRONMENT(ob)  ((ob)->get_environment() || environment(ob))

#endif /* _INVENTORY_H */
