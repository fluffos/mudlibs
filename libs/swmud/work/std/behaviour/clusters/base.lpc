/* Do not remove the headers from this file! see /USAGE for more info. */

// Base functionality for behavior_tree
// Emotions inspired by Plitchik's Wheel of Emotions
// https://en.wikipedia.org/wiki/Robert_Plutchik

#include <behaviour.h>
#include <commands.h>

inherit NODE_CLASS;

#ifdef CLUSTER_ASSOCIATION
void init_association_cluster();
string association_features();
#endif
#ifdef CLUSTER_NAVIGATION
void init_navigation_cluster();
string navigation_features();
#endif
#ifdef CLUSTER_EQUIPMENT
void init_equipment_cluster();
string equipment_features();
#endif

void add_hook(string, function);
void remove_hook(string, function);
object query_target();
object query_link();
varargs int evaluate_node();
void calm_emotions();

void action_arrival(object);
void action_departure(object);

mapping emotions = ([0:0, 1:0, 2:0, 3:0, 4:0, 5:0, 6:0, 7:0]);
mapping blackboard = ([]);
mapping node_list, parents;

private
function arrival_fn = ( : action_arrival:);
private
function departure_fn = ( : action_departure:);

private
function my_hook;

private
object env;

private
int delay_time = 5; // Default delay time for leaves.
private
object debugee = 0; // The body of the person debugging us.
private
string *queue = ({}); // Queue of nodes that must be processed.

private
object *arrived = ({});
private
object *left = ({});
private
int behaviour_call_out;

private
int room_has_changed = 1;

int has_room_changed()
{
   return room_has_changed;
}

void room_checked()
{
   room_has_changed = 0;
}

mixed need_hooks()
{
   return 1;
}

object query_body()
{
   return this_object();
}

object query_shell_ob()
{
   return this_object();
}

string status(int s)
{
   switch (s)
   {
   case -1:
      return "<135>NONE<res>";
   case 0:
      return "<135>FAILURE<res>";
   case 1:
      return "<135>SUCCESS<res>";
   case 2:
      return "<135>RUNNING<res>";
   }
}

void backpush(mixed node)
{
   if (arrayp(node))
      queue += node;
   else
      queue += ({node});
}

void frontpush(string node)
{
   queue = ({node}) + queue;
}

string print_queue()
{
   string out = "";
   int i = 1;
   return format_list(queue);
}

mapping query_nodes()
{
   return node_list;
}

mapping query_parents()
{
   return parents;
}

// Reset the tree states as well as the queue.
void reset_tree()
{
   foreach (string name, class node node in node_list)
   {
      node.status = EVAL_NONE;
      node.node_num = 0;
   }
   queue = ({});
}

class node front()
{
   return sizeof(queue) ? node_list[queue[0]] : 0;
}

class node parent(class node node)
{
   return node && parents[node.name] ? node_list[parents[node.name]] : 0;
}

class node pop()
{
   class node n = front();
   queue = sizeof(queue) ? queue[1..] : ({});
   return n;
}

string discover_parent(string node)
{
   string parent;
   string *names = keys(node_list);
   int i = 0;
   while (!parent && i < sizeof(names))
   {
      if (member_array(node, node_list[names[i]].children) != -1)
         parent = names[i];
      i++;
   }
   return parent;
}

// Accepts offstring as a single string or as an array of strings.
// If offspring is 0, the array is set to ({}).
varargs void create_node(int type, string name, mixed offspring)
{
   node_list[name] = new (class node, type
                          : type, name
                          : name, children
                          : arrayp(offspring) ? offspring
                            : offspring       ? ({offspring})
                                              : ({}),
                            delay
                          : type == NODE_LEAF ? LEAF_NODE_PAUSE : 0);
   parents[name] = discover_parent(name);
}

void do_game_command(string str)
{
   object save_tu;
   mixed *winner;
   string verb, argument;

   save_tu = this_user();
   set_this_user(this_object());

   verb = str;
   sscanf(verb, "%s %s", verb, argument);

   winner = CMD_D->find_cmd_in_path(verb, ({CMD_DIR_PLAYER "/"}));
   if (arrayp(winner))
      winner[0]->call_main("", "", "", "", "", "", argument);
   else if (environment())
   {
      mixed result = parse_sentence(str);

      if (stringp(result))
         write(result);
   }

   set_this_user(save_tu);
}

// Return the number of listeners (player in room)
int query_observers()
{
   object *inv;
   if (!env)
      return 0;
   if (inv = all_inventory(env))
      return sizeof(filter(inv, ( : $1->query_link() :)));
   return 0;
}

// The periodic action call_out
void behaviour_call()
{
   if (query_observers() && behaviour_call_out == 0)
      behaviour_call_out = call_out("behaviour_call", delay_time);
   evaluate_node();
   behaviour_call_out = 0;
}

object *arrived()
{
   return arrived;
}

object *left()
{
   return left;
}

void something_arrived(object ob)
{
   // Ignore if I spot myself arriving.
   if (ob == this_object())
      return;
   left -= ({ob});
   arrived += ({ob});
}

void something_left(object ob)
{
   // Ignore if I spot myself leaving.
   if (ob == this_object())
      return;
   left += ({ob});
   arrived -= ({ob});
}

// If last player leaves, remove call_out
void action_departure(object who)
{
   room_has_changed = 1;
   something_left(who);
}

// If first player arrives, add call_out
void action_arrival(object who)
{
   room_has_changed = 1;
   something_arrived(who);
   if (who->query_link())
   {
      if (query_observers() == 1 && behaviour_call_out == 0)
         behaviour_call_out = call_out("behaviour_call", delay_time);
   }
}

// It moves the "object_arrived/left" hooks (which are associated with a room)
// when the action monster moves
void action_movement()
{
   if (env)
   {
      env->remove_hook("object_arrived", arrival_fn);
      env->remove_hook("object_left", departure_fn);
   }

   env = environment();
   env->add_hook("object_arrived", arrival_fn);
   env->add_hook("object_left", departure_fn);
   if (behaviour_call_out == 0 && query_observers())
      behaviour_call_out = call_out("behaviour_call", delay_time);
}

int debugging()
{
   return objectp(debugee);
}

void debug(mixed s)
{
   if (debugee && debugee->is_body())
      tell(debugee, sprintf("%s: %O\n", __FILE__, (s)));
}

void debug_me(int i)
{
   debugee = i ? this_body() : 0;
}

void set_blackboard(string key, mixed value)
{
   blackboard[key] = value;
}

void del_blackboard(string key)
{
   map_delete(blackboard, key);
}

mixed blackboard(string key)
{
   return blackboard[key];
}

mapping query_blackboard()
{
   return blackboard;
}

mapping query_emotions()
{
   return emotions;
}

string emotion_string()
{
   string *ems = ({});
   foreach (int emotion, int level in emotions)
   {
      if (level > 0)
         ems += ({EMOTION_NAMES[emotion][level - 1]});
   }
   if (!sizeof(ems))
      ems = ({"indifference"});
   return (sizeof(ems) > 1 ? "a mixture of " : "") + format_list(ems);
}

mapping emotion_names()
{
   return EMOTION_NAMES;
}

private
void raw_mod_emotion(int emotion, int mod)
{
   emotions[emotion] = CLAMP(emotions[emotion] + mod, 0, 3);
}

int emotion_to_int(string s)
{
   s = lower_case(s)[0..2];
   switch (s)
   {
   case "ecs":
      return 0;
   case "adm":
      return 1;
   case "ter":
      return 2;
   case "amu":
      return 3;
   case "gri":
      return 4;
   case "loa":
      return 5;
   case "rag":
      return 6;
   case "vig":
      return 7;
   default:
      return -1;
   }
}

//: FUNCTION mod_emotion
// Function for modifying the behavior of the brainee.
// Examples::
//    orc->mod_emotion("rage",3);
//    orc->mod_emotion("ter",2);
//
// Are valid examples. Emotion names can be abbreviated to first 3 letters, or you
// can use integers as per defined in behaviour.h.
void mod_emotion(mixed emotion, int mod)
{
   if (stringp(emotion))
      emotion = emotion_to_int(emotion);
   // Just a block.
   {
      int opposite_emotion = (emotion + 4) % 8;
      int opposite_left = (opposite_emotion + 9) % 8;
      int opposite_right = (opposite_emotion + 7) % 8;
      // Some guard rails
      if (emotion < 0 || emotion > 7)
         error("Unknown emotion state '" + emotion + "'. States defined in /include/behaviour.h.\n" +
               "ecstasy 0, admiration 1, terror 2, amuzement 3, grief 4, loathing 5, rage 6, vigilance 7");
      if (mod < -3 || mod > 3)
         error("Can only modify emotions -3 - 3 points.");

      raw_mod_emotion(emotion, mod);
      raw_mod_emotion(opposite_emotion, -mod);

      if (mod > 1 || mod < -1)
      {
         raw_mod_emotion(opposite_right, -1 * (mod - 1));
         raw_mod_emotion(opposite_left, -1 * (mod - 1));
      }
   }
}

//: FUNCTION set_emotion
// Function for setting a specific emotion. This sets the emotion to this value and doesn't raise it above
// the given value.
// Examples::
//    orc->set_emotion("rage",3);
//    orc->set_emotion("ter",2);
//
// Are valid examples. Emotion names can be abbreviated to first 3 letters, or you
// can use integers as per defined in behaviour.h.
void set_emotion(mixed emotion, int value)
{
   if (stringp(emotion))
      emotion = emotion_to_int(emotion);
   {
      int current_val = emotions[emotion];
      value = value - current_val;
      mod_emotion(emotion, value);
   }
}

int query_emotion(mixed emotion)
{
   if (stringp(emotion))
      emotion = emotion_to_int(emotion);
   return emotions[emotion];
}

void calm_emotions()
{
   for (int i = 0; i < 8; i++)
      raw_mod_emotion(i, -1);
}

void add_child(string node, string child)
{
   if (!child)
      error("Cannot add empty child.");
   if (!arrayp(node_list[node].children))
      node_list[node].children = ({child});
   else
      node_list[node].children += ({child});
   parents[child] = node;
}

private
void init_tree()
{
   node_list = ([]);
   parents = ([]);
   create_node(NODE_ROOT, "root", "root_sequence");
   create_node(NODE_SEQUENCE, "root_sequence");
#ifdef CLUSTER_ASSOCIATION
   init_association_cluster();
#endif
#ifdef CLUSTER_NAVIGATION
   init_navigation_cluster();
#endif
#ifdef CLUSTER_EQUIPMENT
   init_equipment_cluster();
#endif
}

void start_behaviour()
{
   if (!node_list)
      init_tree();
   add_hook("move", ( : action_movement:));
   if (env = environment(this_object()))
   {
      env->add_hook("object_arrived", arrival_fn);
      env->add_hook("object_left", departure_fn);
   }

   if (query_observers())
      behaviour_call_out = call_out("behaviour_call", delay_time);
}

void stop_behaviour_call()
{
   remove_call_out(behaviour_call_out);
}

string base_features()
{
   return "<051>Base functionality: \n<res>" + "\t- Emotions\n" + "\t- Basic call out\n" +
          "\t- Establish root sequence\n\n";
}

string features()
{
   return "<bld>Behaviour tree functionality loaded.<res>\n\n" + base_features() +
#ifdef CLUSTER_ASSOCIATION
          association_features() +
#endif
#ifdef CLUSTER_NAVIGATION
          navigation_features() +
#endif
#ifdef CLUSTER_EQUIPMENT
          equipment_features() +
#endif
          "";
}
