#include <std.h>
#include <daemons.h>

inherit DAEMON;

string* lines_off();
void lines_on(object tp);

int cmd_silence(string str) {
  int time = 600;
  string* blockedLines;
  if(str && sscanf(str, "%d", time) != 1)
    return notify_fail("Syntax: <silence [time in seconds]>\n");
  blockedLines = lines_off();
  call_out("lines_on", time, this_player(), blockedLines);
  return 1;
}

string* lines_off() {
  object tp = this_player();
  string* tryBlock = ({ "OOC","angel","auction","clergy","colosseum","darksoul","demon","dragon","dw","elite","fighter","forsaken","gossip","guild","hm","lastsaints","legend","lich","mage","mature","newbie","rogue","trivia","unholy","vampire","vorticon","wanderer" });
  string* blocked = ({ });

  foreach(string block in tryBlock) {
    if(!tp->query_blocked(block)) {
      tp->set_blocked(block);
      blocked += ({ block });
    }
  }

  write("Player lines silenced.");
  return blocked;
}

void lines_on(object tp, string* toUnblock) {
  if(!tp) return;
  
  foreach(string unblock in toUnblock) {
    if(tp->query_blocked(unblock))
      tp->set_blocked(unblock);
  }

  message("info", "Player lines unsilenced.", tp);
}

void help() {
  write("Syntax: <silence [time in seconds]>\n\n"
    "Turns off all player lines for a certain amount of time."
  );
}

int cancel() {
  return remove_call_out("lines_on");
}
