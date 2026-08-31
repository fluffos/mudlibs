#pragma save_binary
#include <std.h>

inherit OBJECT;

void create() {
   :: create();
   set_id( ({"ticket"}) );
   set_name("ticker");
   set_long("ticker: <ticker [#sec]>");
   set_short("a ticker");
}

void init() {
   :: init();
   add_action("ticker", "ticker");
}

int ticker(string s) {
   int time;
   if(!s || s == "") {
     set_heart_beat(0);
     write("Ticker disabled.");
     return 1;
   }
   time=to_int(s);
   write("Ticker set to "+time+" seconds.");
   set_heart_beat(time/2);
   return 1;
}

void heart_beat() {
   if(environment(this_object()))
   message("", ">", environment(this_object()));
}

