/* The rails of the O.E.R. */

inherit "/std/room";

string trainmaster;

varargs void create()
{
  ::create();
  SetIndoors(0);
  trainmaster = "/d/avalon/common/railway/trainmaster";
}
string
SetDestination(int number, string dest)
{
    return Set("destination" + number, dest);
}

string
QueryDestination(int direction)
{
    return Query("destination" + direction);
}

string SetTrainMaster(string str)
{
  return trainmaster = str;
}

string QueryTrainMaster()
{
  return trainmaster;
}

void notify_enter(mixed dest, int method, mixed extra) {
  if(interactive(previous_object()))
    trainmaster->notify_enter(previous_object());
  return ::notify_enter(dest, method, extra);
}

void notify_leave(mixed dest, int method, mixed extra) {
  if(interactive(previous_object()))
    trainmaster->notify_leave(previous_object());
  return ::notify_leave(dest, method, extra);
}
