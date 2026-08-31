/* Do not remove the headers from this file! see /USAGE for more info. */

//: MODULE
// Damage daemon
//
// To store list of valid damage types,
// so weapons and armours check against the list
// (from M_DAMAGE_SOURCE and M_DAMAGE_SINK)
//
// Currently, this daemon reads the config file ``/data/config/damage-types`` at
// start up, so modify this file to add/remove data from this daemon permanently.
//
// This daemon handles special attacks from weapons as well. It needs more documentation.
//
// .. TAGS: RST

inherit M_DAEMON_DATA;

#define DAMAGE_CONFIG_FILE "/data/config/damage-types"

private
string *damage = ({});

// Aggregated values from the magical attack values
// 128, then 192 (128+64), 224 (192+32), etc. These are connected to the array in add_special_attks().
// Make sure to update these sums if you change the array. These are used for random selection of power level.
// random(229), and then the number has to be 0..128 or 129..192 etc. Hence only 1:229 chance for level 5 item.
private
nosave int *special_sums = ({128, 192, 224, 228, 229});

private
mapping short_names = ([]);

private
mapping special_attk = ([]);

mixed *query_special_attk()
{
   return ({special_attk, special_sums});
}

//: FUNCTION add_damage_type
// Add a damage type to the known damage types.
void add_damage_type(string t)
{
   if (member_array(t, damage) == -1)
   {
      damage += ({t});
      save_me();
   }
}

//: FUNCTION add_damage_type
// Add a short name for a damage type to the known damage types.
// This is used in the ``equip`` command e.g.
void add_short_name(string type, string s)
{
   if (member_array(type, damage) != -1)
   {
      short_names[type] = s;
      save_me();
   }
   else
      write("Failed to find damage type " + type + "\n");
}

//: FUNCTION remove_short_name
// Removed a short name.
void remove_short_name(string type)
{
   map_delete(short_names, type);
}

//: FUNCTION query_short_names
// Returns a mapping of all known short names.
mapping query_short_names()
{
   return short_names;
}

//: FUNCTION query_special_damage_types
// Returns a string array of special damage types
string *query_special_damage_types()
{
   return keys(query_special_attk()[0]);
}

//: FUNCTION remove_damage_type
// Removes a damage type.
void remove_damage_type(string t)
{
   if (member_array(t, damage) != -1)
   {
      damage -= ({t});
      save_me();
      write("Damage type " + t + " removed\n");
   }
}

//: FUNCTION clear_damage_types
// Removed all damage types from the daemon.
void clear_damage_types()
{
   damage = ({});
   save_me();
   write("Damage types cleared\n");
}

//: FUNCTION query_damage_types
// Returns a string array copy of all known damage types.
string *query_damage_types()
{
   return copy(damage);
}

//: FUNCTION query_valid_damage_type
// Returns 1 if the type is a valid damage type.
int query_valid_damage_type(string str)
{
   if (member_array(str, damage) == -1)
      return 0;
   return 1;
}

//: FUNCTION add_special_attks
// Add special attacks of type t with a string array specs.
void add_special_attks(string t, string *specs)
{
   int *values = ({128, 64, 32, 4, 1});
   int v;
   if (member_array(t, damage) != -1)
   {
      special_attk[t] = ([]);
      v = 0;
      foreach (string s in specs)
      {
         special_attk[t][values[v]] = s;
         v++;
      }
   }
   else
      write("Failed to find damage type " + t + "\n");
}

//: FUNCTION load_config_from_file
// Loads the config from ``/data/config/damage-types``.
// Saves the daemon after load.
void load_config_from_file()
{
   string *input;
   damage = ({});

   if (!sizeof(stat(DAMAGE_CONFIG_FILE)))
   {
      write("Error: Missing config file '" + DAMAGE_CONFIG_FILE + "'.");
      return;
   }

   input = explode(read_file(DAMAGE_CONFIG_FILE), "\n");

   foreach (string line in input)
   {
      string dmg, short, magics, *tmpar;

      // Skip comments.
      if (line[0] == '#')
         continue;

      if (line[0..7] == "standard")
      {
         tmpar = explode(line[9..], ",");
         foreach (string s in tmpar)
         {
            if (sscanf(s, "%s:%s", dmg, short) == 2)
            {
               dmg = trim(dmg);
               short = trim(short);
               add_damage_type(dmg);
               add_short_name(dmg, short);
            }
         }
      }
      else if (sscanf(line, "%s:%s:%s", dmg, short, magics) == 3)
      {
         tmpar = explode(magics, ",");
         tmpar -= ({""});
         tmpar = map(tmpar, ( : trim($1) :));
         add_damage_type(dmg);
         add_short_name(dmg, short);
         add_special_attks(dmg, tmpar);
      }
   }

   write(__FILE__ + ": " + DAMAGE_CONFIG_FILE + " loaded.");
   write("Saved.");
   save_me();
}

void create()
{
   ::create();
   if (damage == ({}))
      load_config_from_file();
}