#include "/net/intermud3/intermud_cfg.h"

void eventReceiveError(mixed *packet) {
    object ob;
    string error_code, mud, target, msg;

    if( packet[5] ) {
        target = (string)packet[5];
        if( !(ob = find_player(target)) ) return;
    }
    mud = packet[2];
    error_code = packet[6];
    msg = packet[7];
    packet = packet[8];
    switch(error_code) {
        case "unk-user":
          if( !ob ) return;
          tell_object(ob, (msg ? (msg + "\n") : 
                          "Unknown user reported from " + mud + ".\n"));
        default:
          log_file(LOGFILE, "Error:\n"+ error_code +" - "+ msg +"\n"+
                         "Packet: "+packet[0]+" "+
                         sprintf("%O\n", packet[6..]));
          return;
    }
}
