/* Do not remove the headers from this file! see /USAGE for more info. */

// CLUSTER_NAVIGATION

#include <behaviour.h>

inherit M_SMARTMOVE;

void add_child(string node, string child);
varargs void create_node(int type, string name, mixed offspring);
void set_blackboard(string key, mixed value);
mixed blackboard(string key);
void do_game_command(string str);
int has_room_changed();
void room_checked();
void do_wander();
int player_did_arrive(string dir);
void moving();
int query_emotion(mixed emotion);
void mod_emotion(mixed emotion, int mod);
object *worst_threats_present();

private
string *wander_area = ({});
private
int move_allowed = 0;

void init_navigation_cluster()
{
   // If any of these ones return true we stop here, and navigate somewhere else
   create_node(NODE_SELECTOR, "navigation_seq", ({"wimpy", "bored"}));
   add_child("root_sequence", "navigation_seq");
   create_node(NODE_LEAF, "wimpy");
   create_node(NODE_LEAF, "bored");
}

void set_can_move()
{
   move_allowed = 1;
}

//: FUNCTION set_wander_area
// Set the area(s) that an NPC can wander in.  If this is not set
// the NPC cannot move. Use set_can_move() to make the NPC move
// across all areas.
void set_wander_area(mixed areas)
{
   if (arrayp(areas))
   {
      wander_area = clean_array(areas);
   }

   if (stringp(areas))
   {
      wander_area = clean_array(({areas}));
   }
}

//: FUNCTION add_wander_area
// Add area(s) which an NPC can wander in.  See set_wander_area(),
// and set_can_move().
void add_wander_area(mixed areas)
{
   if (arrayp(areas))
   {
      wander_area = clean_array(wander_area + areas);
   }

   if (stringp(areas))
   {
      wander_area = clean_array(wander_area + ({areas}));
   }
}

//: FUNCTION remove_wander_area
// Remove area(s) which an NPC can wander in.  See set_wander_area()
void remove_wander_area(string *area...)
{
   if (member_array(area, wander_area))
      wander_area -= ({area});
}

//: FUNCTION clear_wander_area
// Clear the area(s) in which an NPC can wander in.  Effectively
// this allows the NPC to wander anywhere.  See set_wander_area()
void clear_wander_area()
{
   wander_area = ({});
}

//: FUNCTION query_wander_area
// Returns an array of areas in which may wander.
// See set_wander_area()
string *query_wander_area()
{
   return wander_area;
}

void move_me(string direction)
{
   do_game_command(sprintf("go %s", direction));
}

int do_wander()
{
   string *directions;
   int i;
   string chosen_dir;
   string file;
   object dest;

   if (environment(this_object()))
      directions = environment(this_object())->query_exit_directions();

   /* Stop if there are no directions (this takes care of blue prints*/
   if (!directions || !i = sizeof(directions))
      return;

   chosen_dir = directions[random(i)];

   file = environment(this_object())->query_exit_destination(chosen_dir);
   /* If the destination is not loaded, do so */
   dest = find_object(file);

   if (!dest)
      dest = load_object(file);

   /* Check if the npc has wander restrictions */
   if (dest && sizeof(wander_area))
   {
      if (arrayp(wander_area) && arrayp(dest->query_area()))
      {
         if (sizeof(wander_area & dest->query_area()))
         {
            move_me(chosen_dir);
            return EVAL_SUCCESS;
         }
         return EVAL_FAILURE;
      }
   }
   else if (move_allowed)
   {
      move_me(chosen_dir);
      return EVAL_SUCCESS;
   }
   return EVAL_FAILURE;
}

int wimpy()
{
   string badly_wounded = this_object()->badly_wounded();
   int threats = sizeof(worst_threats_present());
   int result = EVAL_FAILURE;

   if (threats && badly_wounded)
   {
      result = do_wander();
      // Two attempts to find an exit.
      if (result == EVAL_FAILURE)
         result = do_wander();
      if (result == EVAL_SUCCESS)
         this_object()->try_heal();
   }
   return result;
}

int bored()
{
   string wounded = this_object()->badly_wounded() || this_object()->very_wounded();
   int threats = sizeof(worst_threats_present());

   if (!threats && random(4) == 0)
      this_object()->try_heal();

   if (!wounded && query_emotion(LOATHING))
      if (do_wander() == EVAL_SUCCESS)
      {
         mod_emotion(LOATHING, -1);
         return EVAL_SUCCESS;
      }
   return EVAL_SUCCESS;
}

string navigation_features()
{
   return "<039>Navigation:\n<res>" + "\t- Leave room if badly injured\n" + "\t- Leave the room if bored\n\n";
}