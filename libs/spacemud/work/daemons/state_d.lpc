/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** state_d.c -- Changes states for objects on the MUD
** Tsath 2020-07-10 (Created)
*/

//: MODULE
// This daemon periodically calls objects on the MUD to allow them to change state. This can
// be used to grow crops, make food rot, make critically wounded things die.
//
// This daemon runs on a heartbeat, so is as granular as the heartbeat settings.
// See M_STATEFUL, M_DECAY, LIGHT_OBJECT and ^std/consumable/hamburger.c for some examples of usage.

#define MAX_PROCESSED 10
#define INITIAL_SPREAD 5

int last_time;

mapping queue = ([]);

//: MODULE in_queue
// Checks if ob is in the queue (anywhere in queue).
int in_queue(object ob)
{
   return member_array(ob, flatten_array(values(queue))) != -1;
}

//: FUNCTION add_to_queue
// Adds ob to queue, to be scheduled at NOW + add_to_time in minutes.
// If force=1, the object is added even if already in queue.
varargs void add_to_queue(object ob, int add_to_time, int force, mixed extra)
{
   int update_time;
   if (!extra)
      extra = "scheduled";

   if (ob && ob->query_call_interval() && (force || !in_queue(ob)))
   {
      update_time = (ob->query_call_interval() * 60 + time()) + add_to_time;

      if (!queue[update_time])
         queue[update_time] = ({});

      queue[update_time] += ({({ob, extra})});
   }
}

//: FUNCTION add_to_queue_secs
// Useful for faster testing, should probably not be used in the real mudlib.
// If it's this brief, then use a call_out(). See add_to_queue for documentation.
// This function adds seconds, and not minutes.
varargs void add_to_queue_secs(object ob, int add_to_time, int force, mixed extra)
{
   int update_time;
   if (!extra)
      extra = "scheduled";
   if (ob && ob->query_call_interval() && (force || !in_queue(ob)))
   {
      update_time = (time()) + add_to_time;

      if (!queue[update_time])
         queue[update_time] = ({});

      queue[update_time] += ({({ob, extra})});
   }
}

//: FUNCTION add_to_queue_at_time
// Add to queue at a specific time. No checks, no requirements.
varargs void add_to_queue_at_time(mixed ob, int update_time, mixed extra)
{
   if (!extra)
      extra = "scheduled";

   if (!queue[update_time])
      queue[update_time] = ({});

   foreach (mixed *ar in queue[update_time])
   {
      if (base_name(ar[0]) == base_name(ob) && ar[1] == extra)
         return;
   }

   queue[update_time] += ({({ob, extra})});
}

//: FUNCTION remove_from_queue
// Removes ob from the queue nomatter when scheduled.
varargs void remove_from_queue(object ob, mixed extra)
{
   foreach (int update_time, object * targets in queue)
   {
      foreach (mixed *target in targets)
      {
         if (target[0] == ob)
         {
            if (extra && target[1] != extra)
               continue;
            queue[update_time] -= ({target});
         }
      }
   }
}

private
object *find_targets(string t)
{
   object *t_ar = ({});
   t_ar = filter(objects(), ( : base_name($1) == $(t) :));
   if (sizeof(t_ar) > 1)
      t_ar = filter(t_ar, ( : clonep($1) :));
   return t_ar;
}

private
void process_queue()
{
   int processed;
   int t = time();
   foreach (int update_time, object * targets in queue)
   {
      // If targets array is empty, just delete the entire entry - and on we go.
      if (!sizeof(targets))
      {
         map_delete(queue, update_time);
         continue;
      }
      // Walk through each target in targets and check if they are still stateful and return true on state_update().
      foreach (mixed *target in targets)
      {
         if (stringp(target[0]))
         {
            object *t_ar = find_targets(target[0]);
            if (sizeof(t_ar) > 1)
            {
               foreach (object o in t_ar)
                  queue[update_time] += ({({o, target[1]})});
               continue;
            }
            // If we only have one, handle it now.
            target[0] = t_ar[0];
         }

         // Strip away any objects from the queue that are now 0 (destroyed/removed).
         if (!target[0])
         {
            queue[update_time] -= ({target});
            continue;
         }
         if (target[0] && !target[0]->is_stateful(target[1]))
            continue;
         if (target[0] && update_time < time() && target[0]->state_update(target[1]))
            add_to_queue(target[0], 0, 1, target[1]);
      }

      // Remove old timestamps from the queue
      if (update_time < time())
         map_delete(queue, update_time);

      // We'll be back later for more processing.
      if (processed == MAX_PROCESSED)
         return;
   }
}

private
void capture_all_statefuls()
{
   object *statefuls = filter_array(objects(), ( : clonep($1) && $1->is_stateful() :));
   queue = ([]);
   foreach (object ob in statefuls)
      add_to_queue(ob, random(INITIAL_SPREAD));
}

void heart_beat()
{
   process_queue();
}

void create()
{
   if (clonep())
   {
      destruct(this_object());
      return;
   }
   capture_all_statefuls();
   EVENT_D->run_scheduler();
   set_heart_beat(1);
}

mapping queue()
{
   return queue;
}

string stat_me()
{
   string squeue = "";
   mapping q_out = ([]), q_args = ([]);

   // Need to use some muscle first to get the mappings into a shape where we can print them.
   // Fairly simple transformations thanksfully.
   foreach (int update_time in sort_array(keys(queue), 1))
   {
      object *targets = queue[update_time];
      foreach (mixed *t in targets)
      {
         if (!arrayp(q_out[t[0]]))
            q_out[t[0]] = ({});
         if (!arrayp(q_args[t[0]]))
            q_args[t[0]] = ({});
         q_out[t[0]] += ({update_time});
         q_args[t[0]] += ({t[1]});
      }
   }

   // Now we're ready to iterate over objects instead of timestamps.
   foreach (object ob, int *times in q_out)
   {
      if (sizeof(times) == 1)
         squeue +=
             sprintf("%-55s%-25s%-10s\n", shorten_filename(ob), q_args[ob][0], time_to_string(times[0] - time(), 1));
      else
         squeue += sprintf("%-55s%-25s%-10s\n", shorten_filename(ob),
                           implode(clean_array(q_args[ob]), "/") + " (" + sizeof(times) + ")",
                           time_to_string(times[0] - time(), 1));
   }

   return sprintf("%-55s%-25s%-10s\n", "Object", "Arguments", "Next") + sprintf("%92'-'s\n", "") + squeue +
          "\nThere are " + sizeof(flatten_array(values(STATE_D->queue()))) / 2 + " items in queue.";
}