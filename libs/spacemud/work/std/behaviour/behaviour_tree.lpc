/* Do not remove the headers from this file! see /USAGE for more info. */

#include <behaviour.h>

// Mandatory inherits
inherit NODE_CLASS;
inherit CLUSTERS "base";

// Optional ones as per behaviour.h
#ifdef CLUSTER_ASSOCIATION
inherit CLUSTERS "association";
#endif
#ifdef CLUSTER_NAVIGATION
inherit CLUSTERS "navigation";
#endif
#ifdef CLUSTER_EQUIPMENT
inherit CLUSTERS "equipment";
#endif

int *q = ({});
/*
 * PROTOTYPES
 */
string emotion_string();
string discover_parent(string node);
void debug(mixed s);
int debugging();
int query_observers();
int parses = 0;

string get_extra_long()
{
   return this_object()->short() + " radiates " + emotion_string() + ".\n";
}

varargs int evaluate_node()
{
   class node node, parent;
   node = front();
   parent = parent(node);

   if (!node)
   {
      debug("<161>Queue empty - missing node? Restarting from <069>ROOT<res>.");
      frontpush("root");
      return;
   }

   debug("<214>Evaluating node: <043>" + node.name + "<res> <214>Queue: <043>" + print_queue() + "<res>");
   switch (node.type)
   {
   case NODE_ROOT:
      debug(blackboard);
      debug("<069>ROOT<res> node.");
      reset_tree(); // Reset tree when we see the root node.
      backpush(node.children[0]);
      parses++;
      if (query_observers())
         evaluate_node();
      return;
      break;
   case NODE_SEQUENCE:
      // We're done in the sequence
      debug("<154>SEQUENCE, node: <043>" + node.name + "<res> child: " + node.node_num +
            " status: " + status(node.status) + "<res>");

      // Did child fail or are we done? Then stop.
      if (node.status == EVAL_FAILURE || (node.node_num >= sizeof(node.children) && parent))
      {
         parent.status = node.status;
         frontpush(parent.name);
      }
      else
      { // Run sequence
         debug("<154>SEQUENCE CONTINUE node: <043>" + node.name + " status: " + status(node.status) + "<res>");
         frontpush(node.children[node.node_num]);
         node.status = EVAL_RUNNING;
         node.node_num++;
      }
      break;
   case NODE_LEAF:
      debug("<154>LEAF <043>" + node.name + "<res>");
      parent.status = call_other(this_object(), node.name);
      pop();
      break;
   case NODE_SELECTOR:
      debug("<154>SELECTOR <043>" + node.name + "<154> child: " + node.node_num + " Status: " + status(node.status) +
            "<res>");
      // Did child fail or are we done? Then stop.
      if (node.node_num >= sizeof(node.children) && parent)
      {
         parent.status = node.status;
         frontpush(parent.name);
      }
      else
      { // Run sequence
         if (node.status == EVAL_SUCCESS)
         {
            debug("<154>SELECTOR STOPPED node: <043>" + node.name + " status: " + status(node.status) + "<res> ");
            parent.status = node.status;
            frontpush(parent.name);
         }
         else
         {
            debug("<154>SELECTOR CONTINUES node: <043>" + node.name + " status: " + status(node.status) + "<res> ");
            frontpush(node.children[node.node_num]);
            node.status = EVAL_RUNNING;
            node.node_num++;
         }
      }
      break;

   case NODE_INVERTER:
      if (node.status != EVAL_RUNNING && node.status != EVAL_NONE)
      {
         // Flip 1 to 0, and 0 to 1.
         parent.status = !node.status;
         frontpush(parent.name);
      }
      else
      { // Run sequence
         debug("<154>INVERTER: <043>" + node.name + "<res>");
         frontpush(node.children[0]);
         node.status = EVAL_RUNNING;
         node.node_num++;
      }
      break;

   case NODE_SUCCEEDER:
      if (node.status != EVAL_RUNNING && node.status != EVAL_NONE)
      {
         // Always a success!
         node.status = EVAL_SUCCESS;
         parent.status = EVAL_SUCCESS;
         frontpush(parent.name);
      }
      else
      { // Run sequence
         debug("<154>SUCCEEDER: <043>" + node.name + "<res>");
         frontpush(node.children[0]);
         node.status = EVAL_RUNNING;
      }
      break;

   case NODE_REPEAT_UNTIL_FAIL:
      debug("<154>REPEAT_UNTIL_FAIL: <043>" + node.name + "<res>");
      // ## TODO Not implemented yet.
      break;

   default:
      debug("<161>Don't know what to do with the <043>" + node.name + "<161> node<res>");
      break;
   }

   if (node.delay > 0)
   {
      debug("<077>Queue delay: " + node.delay + " seconds.<res>");
      if (find_call_out("evaluate_node") == -1)
         call_out("evaluate_node", debugging() ? clamp(node.delay, 3, 20) : node.delay);
   }
   else
      evaluate_node(parent);
}

int parses_made()
{
   return parses;
}

int is_smart()
{
   return 1;
}

void start_behaviour()
{
   base::start_behaviour();
   if (find_call_out("evaluate_node") == -1)
      evaluate_node();
}
