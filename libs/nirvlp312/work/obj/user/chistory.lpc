/******************************************
File: chistory.c
Purpose: Storage object for channel histories
Author: Feldegast
Mud: Nirvana
Date: 7-2-99
******************************************/
#define HISTSIZE 25

mapping history;

void reset(int arg)
{
if(arg) return;
  history=([ ]);
}


void add_history(string chan,string msg)
{
  msg = "["+ctime()[11..15]+"] "+msg;
  if(!(history[chan]))
    history[chan]=({ msg });
  else
  {
    if(sizeof(history[chan]) > HISTSIZE)
      history[chan] = history[chan][1..HISTSIZE];
    history[chan] += ({ msg });
  }
}

string query_history(string chan)
{
  string *msgs;
  string msg;
  int i, siz;
  msgs=history[chan];
  if(!msgs) return "None";
  msg=capitalize(chan)+" History\n";
  msg+="--------------\n";
  for (i = 0, siz = sizeof(msgs); i < siz; i++)
    msg+=msgs[i];
  return msg;
}
