// Last edited by deforce on 10-05-2009
// Allows an object to receive buffs.
// Note that not all objects have the functions
// needed for buffs to work properly
// for example rooms don't have heartbeats.

private nosave mixed buffs = ({ });

// Add a buff to this buffable object,
// if it's not a /std/buff.c derived object, this will break a bit.
void add_buff(object ob)
{
   buffs += ({ ({ ob, time() }) });
   ob->apply_buff(this_object());
}

mixed query_buffs()
{
   return buffs;
}

void buff_heartbeat()
{
   int curtime, duration, numbuffs, index;
   mixed buff;

   curtime = time();
   numbuffs = sizeof(buffs);
   index = 0;

   foreach (buff in buffs)
   {
      // Check if the buff has expired
      duration = buff[0]->query_buff_duration();
      //tell(this_object(), sprintf("curtime: %d, buff1: %d, duration: %d\n", curtime, buff[1], duration));

      if ((curtime - buff[1]) >= duration)
      {
         // Remove the buff from the array
         buffs = buffs[0..index-1] + buffs[index+1..numbuffs];
         // call its removal function.
         buff[0]->remove_buff(this_object());
      }
      else
      {
         buff[0]->buff_heartbeat();
      }

      index++;
   }
}

int has_buff(string filename)
{
   foreach (mixed buff in buffs)
   {
      if (base_name(buff[0]) == filename)
      {
         return 1;
      }
   }

   return 0;
}

void cancel_buff(string filename)
{
   foreach (mixed buff in buffs)
   {
      if (base_name(buff[0]) == filename)
      {
         buff[0]->set_buff_duration(0);
      }
   }
}

void clear_buffs()
{
   foreach (mixed buff in buffs)
   {
      buff[0]->remove_buff(this_object());
   }
}