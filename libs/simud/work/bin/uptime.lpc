string colour(float f) {
   if (f <= 0.1)
     return "~[150";
   if (f <= 0.25)
     return "~[120";
   if (f <= 0.5)
     return "~[100";
   if (f <= 1.0)
     return "~[110";
   return "~[090";
}

int p(int x, int y) {
   float t = (float)x / (float)y;
   return (int)(100 * t);
}

string meter(int x, int y) {
   string buf = "~CDEF[";
   int k, t = p(x,y);
   for (k = 0; k < 24; k++) {
      if (t/4 > k) {
         if (k < 6)
            buf += "~[120=";
         else if (k < 12)
            buf += "~[100=";
         else if (k < 18)
            buf += "~[110=";
         else
            buf += "~[090=";
      } else
         buf += "~CDEF-";
   }
   buf += "~CDEF] ("+t+"%)";
   return buf;
}

float cpu_load(string topfile) {
   string *data = explode(topfile, "CPU states:")[1..];
   string line;
   float total = 0.0, one, two;
   int count = 0;
   foreach (line : data) {
      count++;
      /* Uncomment the following lines if your top command outputs comma
       * separated cpu state %'s
       */
      // line = explode(explode(line,"\n")[0],",")[3];
      // sscanf(line, "%d.%d", one, two);

      /* Uncomment the following lines if your top command outputs space
       * separated cpu state %'s (and has an 'iowait' section between nice
       * and idle).
       */
      // line = explode(explode(line,"\n")[0],"iowait")[1];
      // sscanf(line, "%t%d.%d", one, two);
      // total += (float)(one + "." + two);
   }
   total /= (float)count;
   return 100.0 - total;
}

int main() {
   int uptime;
   string buf, file;
   int time, x;
   int mem, tmem, bmem, cmem, swap, tswap, junk;
   float mpercent, spercent, cpercent, lag;
   string *times, now, five, ten;
   string *data;

   uptime = time() - "/daemon/time"->query_boot_time();

   buf = "~[140"+MUD_TITLE+" has been up for ~CBRT" + int_to_time(uptime) + "~CDEF.";

   // if ( file_exists("/proc/uptime") ) {
     // file = read_file("/proc/uptime");

     /*  Uncomment the following section if you're reading from
      *  /proc/uptime on your server:
      */
     // sscanf(file,"%d",time);
     // buf += "\n~[060"+SERVER_NAME+" has been up for ~CBRT" +
     //        int_to_time(time) + "~CDEF.";

     /*  Uncomment the following section if you're reading the output of
      *  the uptime shell command:
      */
     //sscanf(explode(file,"up")[1],"%t%s,%t%d user",now,junk);
     //buf += "\n~[060"+SERVER_NAME+" has been up for ~CBRT" + now +  "~CDEF, ";
     //sscanf(explode(file,"average: ")[1],"%s, %s, %s\n",now,five,ten);
     //lag = ((float)now * 10 + (float)five * 3 + (float)ten) / 14.0;
     //now = colour((float)now)+now;
     //five = colour((float)five)+five;
     //ten = colour((float)ten)+ten;
     //buf += "~[060Load~CDEF: "+now+"~CDEF, "+five+"~CDEF, "+ten+"~CDEF.";
   // }

   // if ( file_exists("/proc/meminfo") ) {
      /*  Uncomment this section if you're reading from /proc/meminfo on
       *  your server, or if you are taking the output from the console
       *  command 'free':
       */
     // data = explode(read_file("/proc/meminfo"),"\n")[1..2];
     // sscanf(data[0],"Mem:%t%d%t%d%t%d%t%d%t%d%t%d",
     //        tmem,mem,junk,junk,bmem,cmem);
     // mpercent = (float)(mem - cmem) / (float)tmem;
     // sscanf(data[1],"Swap: %d %d",tswap,swap);
     // spercent = (tswap?(float)swap / (float)tswap:0);
     // buf += "\n~[060Memory~CDEF: "+colour(mpercent)+(int)(mpercent *  100)+"~CDEF%, ";
     // buf += "~[060Swap~CDEF: "+colour(spercent)+(int)(spercent * 100)+"~CDEF%, ";
   // }

   // if ( file_exists("/proc/loadavg") ) {
     /*  Uncomment this particular section if you're reading from
      *  /proc/loadavg on your server. Remember that you don't need this
      *  section if you are getting system uptime from the 'uptime'
      *  command:
      */
     // sscanf(read_file("/proc/loadavg"),"%s %s %s ",now,five,ten);
     // lag = ((float)now * 10 + (float)five * 3 + (float)ten) / 14.0;
     // now = colour((float)now)+now;
     // five = colour((float)five)+five;
     // ten = colour((float)ten)+ten;
     // buf += "~[060Load~CDEF: "+now+"~CDEF, "+five+"~CDEF, "+ten+"~CDEF.";
   // }

   // report time until next world save
   buf += "\n~[060Next world save in ~CBRT"+int_to_time("/world/world"->query_world_timed_save())+"~CDEF.";

   if ( file_exists("/proc/top") ) {
     string top_file = read_file("/proc/top");
     cpercent = cpu_load(top_file);
     buf += "\n~[060CPU~CDEF: "+meter((int)cpercent,100);
   }

   msg("\n"+buf);

   return 1;
}
