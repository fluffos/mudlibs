#include <saveload.h>

/** This is the inventory inheritance.  Inherit this object if you want this
 * object to remember all the objects that are inside of it, and to restore
 * them whenever it is created/save them when it is destroyed.  This assumes
 * that your object's environment is also using the save_self/load_self rules.
 *
 * (A note: Only objects which cannot have things inserted into them should
 *  not inherit this file.  The world is an inventory based object, except
 *  that it loads itself.)
 */

/// Inheritable object which makes their inheritor capable of saving its inventory.

private nosave int loaded = 0;

void load_one_object( string str );
void sub_save( object ob );

//#define DEBUG

/// A list of object full_name references (see saveload), used when loading.
string *contents_list;

/**
 * Overrides the save_self in saveload to also save inventory.
 */
void save_self() {
   object ob;

#ifdef DEBUG
   msg_all("obj/inven: save_self() called in "+object_name(this_object())+".");
#endif
   // Saves a list of file names and unique id's.
   contents_list = ({ });
   foreach( ob : all_inventory(this_object()) ) {
      if(ob->query_full_id()) {
         contents_list += ({ ob->query_full_id() });
         catch(sub_save(ob));
      }
   }

   ::save_self();
}

/**
 * Saves this object properly, but inventory is left in its old state.
 */
void save_self_only() {
   object ob;

#ifdef DEBUG
   msg_all("obj/inven: save_self() called in "+object_name(this_object())+".");
#endif
   // Saves a list of file names and unique id's.
   contents_list = ({ });
   foreach( ob : all_inventory(this_object()) ) {
      if(ob->query_full_id()) {
         contents_list += ({ ob->query_full_id() });
      }
   }

   ::save_self();
}

/** Overrides the load_self in saveload to also load the inventory
 * of this object.
 * \todo Change from a call_out implementation to an immediate one.
 */
void load_self(int id) {
   int i;

   ::load_self(id);
   if( loaded ) return; // Do not load inventory a second time.
   loaded = 1;

#ifdef DEBUG
   msg_all("obj/inven: load_self("+id+") called.");
#endif
   if(sizeof(contents_list) != 0) {
   /* Load the inventory here (stored in contents_list) */
      for(i=0; i<sizeof(contents_list); i++)
      catch(load_one_object( contents_list[i] ));
   }
}

/** Restore the object specified by str.  To restore all the objects, use
 * a call_each.  This also moves the object inside of this_object()
 */
void load_one_object(string str) {
   object ob;
   string base;
   int id;

#ifdef DEBUG
   msg_all("obj/inven: load_one_object("+str+") called.");
#endif
   /* Note: dec_load_count comes before the load_self, which means you
    * could occasionally drop the load_count to 0 before all objects are
    * loaded. However, if the object fails to load for some reason, the
    * count will still be correct [because it was already counted] so
    * don't change the order or you lose that benefit :).
    */
   if(sscanf(str, "%s:%d", base, id) != 2) return 0;
   ob = clone_object(base);
   if(!ob) return;
   ob->load_self(id);
   ob->move(this_object(), 1);
}

void sub_save(object ob) {
   if(!ob) return;  // Just in case the object was dested somehow

#ifdef DEBUG
   msg_all("obj/inven: sub_save('"+ob->query_name()+"') called.");
#endif
   ob->save_self();
}
