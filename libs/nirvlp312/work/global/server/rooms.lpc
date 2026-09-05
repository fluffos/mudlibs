#include <closures.h>
#include <kernel.h>
inherit ACCESS;
inherit "/basic/create";
#define SAVE_FILE "/save/rooms"

private mapping rooms;
private int counter;

void
save()
{
  unguarded(1,#'save_object,SAVE_FILE);
}

void
create()
{
  unguarded(1,#'restore_object,SAVE_FILE);
}

int 
query_room_number(object room)
{
  int result;
  string file;
  file = load_name(room);
  if (!rooms)
    rooms = ([file : result = (++counter)]);
  else if (!(result = rooms[file]))
    rooms[file] = result = (++counter);
  else
    return result;
  save();
  return result;
}

string query_room(int number) {
  mixed h;

  if (rooms)
  {
    h = filter_indices(rooms,
                       lambda(({'r}),({#'==,({CL_INDEX,rooms,'r}),number})));
    if (sizeof(h))
      return m_indices(h)[0];
  }
}
