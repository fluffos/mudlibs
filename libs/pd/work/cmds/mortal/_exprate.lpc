
#include <std.h>

inherit DAEMON;

int display_exprate(object);

void help() {
  message("help",
    "Syntax: <exprate [start / stop]>\n\n"
    "This will let you track how many experience points you gain "
    "per hour. Use 'start' to turn it on and 'stop' to turn it off.\n"
    "With no argument, it will print out your current exp rate.",
    this_player() );
}

int cmd_exprate(string str) {
  object tp = this_player();

  if (str) {
    switch (str) {

    case "start": case "on":
      if (tp->query_exprate_start()) {
        message("info", "Experience point tracking is already turned on.", tp);
        break;
      }
      tp->set_exprate_start(time());
      message("info", "Experience point tracking turned on.", tp);
    break;
    
    case "stop": case "off":
      if (display_exprate(tp))
        message("info", "Experience point tracking turned off.", tp);
      tp->clear_exprate();
    break;

    }
    return 1;
  }

  display_exprate(tp);

  return 1;
}

int display_exprate(object tp) {
  int start, duration, exp, rate;

  if (!tp) return;

  start = tp->query_exprate_start();
  if (!start) {
    message("info", "Experience point tracking has not been turned on.", tp);
    return 0;
  }

  duration = time() - start;
  exp = tp->query_exprate_exp();
  rate = exp / (duration+1);
  rate = rate*60*60; // 60 secs per min, 60 mins per hour


  message("info",
    "Time elapsed: "+duration+ " seconds\n"
    "Experience gained: "+tp->query_exprate_exp()+" points\n"
    "Rate: "+rate+" exp per hour.\n",
    tp);

  return 1;
}

