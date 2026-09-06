/* The trainmaster, watching the traffic */

#include <moving.h>
#define  TRAIN        "/d/avalon/common/railway/train"

object *present_persons;
int     stopped;
mixed  *trains;
string *rangrails;
mixed  *lines;
int     traincount;
int     to_stop;

void start_all_trains();
void adjust_trains();

void create()
{
  seteuid(getuid());
  trains = ({});
  stopped = 0;
  traincount = 0;
  call_out("start_all_trains",0);
}

int notify_leave(object player)
{
  int i, j;

  if (!(j = sizeof(present_persons)) ||
      (i = member_array(player, present_persons)) == -1)
    return 0;
  if(j == 1)
    present_persons = ({});
  else if(!i) present_persons = present_persons[1..];
  else if(i == j-1) present_persons = present_persons[0..<2];
  else 
    present_persons = present_persons[0..i-1] + present_persons[i+1..];
  if(!sizeof(present_persons)) {
    call_out("stop_all_trains",0);
    to_stop = 1;
  }
  return 1;
}

int notify_enter(object player)
{
  if (!player)
    return 0;
  if(!present_persons) present_persons = ({player});
  else {
    if(member_array(player,present_persons) != -1) return 0;
    present_persons += ({player});
  }
  if(sizeof(trains) != traincount) adjust_trains();
  if (stopped)
    start_all_trains();
  to_stop = 0;
  return 1;
}

int notify_destruct(object train)
{
  int    line;
  string sign;
  object new_train;
  object rail;

  if(member_array(train,trains) == -1) return 0;
  line = (int)train->QueryLine();
  sign = (string)train->QueryReadMsg();
  rail = load_object(assoc(line,lines)[0]);
  if (!present("train", rail))
    rail->reset(1);
  new_train = present("train", rail);
  new_train->SetLine(line);
  new_train->SetReadMsg(sign);
  if (!stopped)
    new_train->silent_start_train();
  return 1;
}

void stop_all_trains()
{
  int j;

  if(!to_stop) return;
  trains -= ({0});
  trains -= ({0});
  j = sizeof(trains);
  while(j--)
    trains[j]->stop_train();
  stopped = 1;
}

void start_all_trains()
{
  int j;

  trains -= ({0});
  j = sizeof(trains);
  while(j--)
    trains[j]->silent_start_train();
  stopped = 0;
}

mixed SetLine(int line, string rail, int count, string sign)
{
  int j;

  if(!lines) lines = ({({line}),({({rail,count,sign})})});
  else lines = insert_alist(line, ({rail,count,sign}), lines);
  j = sizeof(lines[1]);
  traincount = 0;
  while(j--)
    traincount += lines[1][j][1];
  return lines;
}

void adjust_trains()
{
  int    i,j,k;
  int    *linecount;
  string sign;
  object train, rail;
  mixed  *line;
    
  trains -= ({0});
  linecount = allocate(sizeof(lines[0]));
  j = sizeof(trains);
  while(j--) {
    ++linecount[assoc((int)trains[j]->QueryLine(),lines[0])];
    tell_object(find_player("sique")||this_object(),"/lib/string"->mixed_to_string(linecount) + "\n");
  }
  j = sizeof(linecount);
  while(j--) {
    line = ({}) + lines[1][j];
    call_other(line[0],"???");
    rail = find_object(line[0]);
    sign = line[2];
    for(k = line[1]; linecount[j] < k; linecount[j]++) {
      rail->reset(1);
      train = present("train",rail);
      if(member_array(train,trains) != -1) {
	train = clone_object(TRAIN);
	train->move(rail,M_SILENT);
      }
      trains += ({train});
      train->SetLine(lines[0][j]);
      train->SetReadMsg(sign);
    }
  }
}

mixed QueryLines() { return lines; }

mixed QueryTrains() { return trains; }

mixed QueryPlayers() { return present_persons; }

int QueryStopped() { return stopped; }

int QueryTrainCount() { return traincount; }
