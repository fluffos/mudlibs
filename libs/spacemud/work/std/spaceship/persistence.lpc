/* Do not remove the headers from this file! see /USAGE for more info. */

#include <move.h>
#define SHIP_PERSISTED 1
#define SHIP_DIRTY 2

private
string owner;
private
nosave object possible_owner;
private
nosave int restored = 0;
private
int state = SHIP_PERSISTED;
private
string inventory;

void set_relations();
string query_owner();
varargs string save_things_to_string(int recursep);
void load_from_string(mixed value, int recurse);
int count_objects(string file);
int is_ship_empty();
void add_hook(string tag, function hook);
mixed unguarded(mixed priv, function fp);
nomask protected void set_privilege(mixed priv);

void before_save()
{
   // Things to do before we save.
}

void object_arrived(object ob)
{
   TBUG("Owner: " + owner + " Ob:" + ob);
   if (ob->is_body() && !owner)
   {
      possible_owner = ob;
      owner = lower_case(possible_owner->query_name());
      TBUG("Setting owner: " + owner);
   }
   if (!restored && owner)
   {
      TBUG("Restored: " + restored + " Owner: " + owner);
      SHIP_D->restore_ship_state(this_object());
      this_object()->set_restored(1);
      set_relations();
   }
   state = SHIP_DIRTY;
   TBUG("State: DIRTY");
}

int query_restored()
{
   return restored;
}

void set_restored(int r)
{
   TBUG("set_restored: " + this_object() + " previous ob: " + previous_object() + " r: " + r);
   restored = r;
}

string save_to()
{
   return query_owner() ? SHIP_PATH(query_owner()) + ".o" : 0;
}

int query_state()
{
   return state;
}

string query_owner()
{
   return owner;
}

void set_owner(string o)
{
   owner = o;
}

void unguarded_save()
{
   if (save_to() && query_owner())
   {
      before_save();
      // We use save_things_to_string() to avoid saving players and their inventories.
      unguarded(1, ( : write_file, save_to(), save_things_to_string(), 1 :));
      state = SHIP_PERSISTED;
      TBUG("State: PERSISTED");
   }
}

int restore_ship(string save_str)
{
   load_from_string(save_str, 1);
}

void set_saved_objects(mapping m)
{
   if (!restored)
      return;
   foreach (string file, mixed parameters in m)
   {
      int num = 1;
      mixed *rest = ({});
      int matches = 0;
      file = absolute_path(file, this_object());
      if (intp(parameters))
         num = parameters;
      else if (arrayp(parameters))
      {
         if (intp(parameters[0]))
         {
            num = parameters[0];
            rest = parameters[1..];
         }
         else
            rest = parameters;
      }
      else
         continue;

      matches = count_objects(file);
      while (matches < num)
      {
         int ret;
         object ob = new (absolute_path(file), rest...);
         if (!ob)
            error("Couldn't find file '" + file + "' to clone!\n");
         ret = ob->move(this_object(), "#CLONE#");
         if (ret != MOVE_OK)
            error("Initial clone failed for '" + file + "': " + ret + "\n");

         ob->on_clone(rest...);
         matches++;
      }
   }
}

void object_left(object ob)
{
   if (is_ship_empty() && state == SHIP_DIRTY)
   {
      object *obs = all_inventory();
      if (obs)
         inventory = save_things_to_string();
      SHIP_D->save_ship_state(this_object());
   }
   else
   {
   }
}

void setup_persistence()
{
   add_hook("object_left", ( : object_left:));
   add_hook("object_arrived", ( : object_arrived:));
   set_privilege("Common:ships");
}
