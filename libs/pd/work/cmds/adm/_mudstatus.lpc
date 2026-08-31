//  <mudstatus>
//  Whit

#include <daemons.h>
#define MIN 60
#define HOUR (60 * MIN)
#define DAY  (24 * HOUR)

string query_time(int time);

int cmd_mudstatus() {
    int utime=uptime(), mem=memory_info(), i=0, ct=0;
    object *o;

    if(!archp(this_player())) return 0;
    write("%^BLUE%^+=+=+=+( %^BOLD%^%^WHITE%^Mud Status%^RESET%^%^BLUE%^ )+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=%^RESET%^");

    write("    The mud has been online for "+query_time(uptime())+"");
    write("    The mud will reboot in "+query_time((EVENTS_D->query_next_reboot())-time())+"");
    write("    Number of Objects Loaded:  "+i=sizeof(o=objects()));
    write("    "+add_commas(mem)+" bytes of memory is loaded.");
    while(i--) if(query_heart_beat(o[i])) ct++;
    write("    Number of objects with heartbeats: "+ct+".");
    write("    Number of callouts: "+sizeof(call_out_info())+".");
    write("    Processing "+query_load_average()+".");
    if(find_object("/d/nopk/standard/freezer"))
      write("    Number of link-dead players: "+
         sizeof( all_inventory( find_object( "/d/nopk/standard/freezer" ) ) ) );
    write("    Number of players online: "+(string)sizeof(users()));
    write("%^BLUE%^+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+%^RESET%^\n");
    return 1;
}

string query_time(int time) {
    int tmp;
    string line;

    line = "";
    if(time < 60) return line;
    tmp = time / 86400;
    if(tmp)
	line += tmp + " day" + (tmp>1 ? "s " : " ");
    tmp = (time%86400)/3600;
    if(tmp) 
	line += tmp + " hour"+(tmp>1 ? "s " : " ");
    tmp = (time%3600)/60;
    if(tmp)
	line += tmp+ " minute"+(tmp>1 ? "s " : " ");
    return line;
}

