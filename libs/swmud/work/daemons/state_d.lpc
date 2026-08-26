/*
** state_d.c -- Changes states for objects on the MUD
**
** This daemon periodically calls objects on the MUD to allow them to change state. This can
** be used to grow crops, make food rot, make critically wounded things die.
**
** Tsath 2020-07-10 (Created)
*/

#define MAX_PROCESSED 10
#define INITIAL_SPREAD 20

int last_time;

mapping queue = ([]);

varargs void add_to_queue(object ob, int add_to_time)
{
   int update_time;
   if (ob && ob->query_call_interval())
   {
      // If the object is already in here, don't add it.
      /*        if (member_array(ob, flatten_array(values(queue))) != -1)
                  return;
      */
      update_time = (ob->query_call_interval() * 60 + time()) + add_to_time;

      if (!queue[update_time])
         queue[update_time] = ({});

      queue[update_time] += ({ob});
   }
}

void process_queue()
{
   int processed;
   int t = time();
   foreach (int update_time, object * targets in queue)
   {
      foreach (object target in targets)
      {
         if (target && update_time < time() && target->state_update())
         {
            add_to_queue(target);
         }
      }
      if (update_time < time())
         map_delete(queue, update_time);
      processed++;
      if (processed == MAX_PROCESSED)
         return;
   }
}

mapping queue()
{
   return queue;
}

void heart_beat()
{
   process_queue();
}

void capture_all_statefuls()
{
   object *statefuls = filter_array(objects(), ( : clonep($1) && $1->is_stateful() :));
   queue = ([]);
   foreach (object ob in statefuls)
      add_to_queue(ob, random(INITIAL_SPREAD));
}

void create()
{
   if (clonep())
   {
      destruct(this_object());
      return;
   }
   capture_all_statefuls();
   set_heart_beat(1);
}

string stat_me()
{
   return "STAT_D:\n-------\n" + "Queue Length: " + sizeof(keys(queue)) +
          "\n"
          "\n";
}