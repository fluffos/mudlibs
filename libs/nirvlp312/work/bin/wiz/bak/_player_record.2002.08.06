#include <security.h>

#define DIR "/open/player_records/"

string get_it(string nm) {
  return (DIR+nm[0..0]+"/"+nm);
}

status cmd_player_record(string arg) {
/* testing */
  if((string)this_player()->query_real_name() != "vertebraker") return 0;
  if(!arg) {
    write("Usage: 'player_record [read|add|clear] <who> [what]'\n");
    return 1;
  }
  else {
    string x, y;
    if(sscanf(arg, "read %s")) {
      if(file_size(get_it(x)) <= 0)
        write("\n\tThat player does not have a record.\n\n");
      else
       write(read_file(get_it(x)) + "\n");
      write("Ok.\n");
      return 1;
    }
    if(sscanf(arg, "add %s %s", x, y)) {
      string file, tm;
      int    z;
      if(file_size(file=get_it(x)) <= 0) {
        write("\n\tStarting new record...\n\n");
        z=1;
        log_file("PLAY_REC",
         ctime() + " " + (string)this_player()->query_real_name()
         + " [NEW] ["+x+"]\n");
      }
      else {
        log_file("PLAY_REC",
         ctime() + " " + (string)this_player()->query_real_name()
         + " [add] ["+x+"]\n");
        z=sizeof(explode(file,"\n"));
      }
      write_file(file, "" + z + ": " + (tm=ctime())[4..15] + " " + 
       tm[20..23] + " " + 
       pad(capitalize((string)this_player()->query_real_name()), 15)
       +": " + y + "\n");
      write("Ok.\n");
      return 1;
    }
    if(sscanf(arg, "clear %s", x)) {
      if((int)this_player()->query_level() < SENIOR)
        return 0;
      if(file_size(get_it(x)) <= 0)
        return cmd_player_record(crypt("heh", "x"));  /* rand seed */
      rm(get_it(x));
      log_file("PLAY_REC",
       ctime() + " " + (string)this_player()->query_real_name()
       + " [clear] ["+x+"]\n");
      write("Ok.\n");
      return 1;
    }
    else
      return cmd_player_record(0);
  }
}
