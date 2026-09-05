#include <sequence.h>

object *lazy_queue;
mapping busy;

void
receive_sequence (string* commands, object player)
{
  object ob;
  if (!busy) busy = ([]);
  if (!busy[player]) 
  {
    if (!lazy_queue || !sizeof (lazy_queue)) 
      busy[player] = clone_object (SEQUENCER);
    else
    {
      busy[player] = lazy_queue[0];
      lazy_queue = lazy_queue[1..];
    }
    busy[player]->set_owner (player);
  }
  busy[player]->add_sequence (commands);
}

void
stop_sequence (object player)
{
  if (!(player && busy && busy[player])) return;
  busy[player]->set_owner (0);
  busy[player]->heart_beat ();
  busy[player] = 0;
}

void
comeback (object sequencer)
{
  object player;
  if (!lazy_queue) lazy_queue = ({ sequencer });
  else lazy_queue += ({ sequencer });
  if (player = sequencer->query_owner ()) busy[player] = 0;
}

mapping
query_busy_for (object player)
{
  return busy && player && busy[player] && 1;
}

object *
query_lazy ()
{
  return lazy_queue && lazy_queue[0..];
}

void
notify_destruct ()
{
  map (lazy_queue - ({0}), #'destruct);
}
