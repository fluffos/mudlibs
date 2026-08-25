/*    /daemon/services/error.c
 *    from the Foundation II LPC Library
 *    error handling for the grand Intermud 3 Protocol
 *    created by Descartes of Borg 950715
 *    Modified for Discworld by Turrican 1-11-95
 */

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
	case "unk-dst": case "not-imp": case "unk-type": case "unk-src":
	log_file("errors/intermud", error_code + ": " + msg + "\n");
	return;
	case "unk-type":
	log_file("errors/intermud", error_code + ": " + msg + "\n");
	return;
	case "unk-user":
	if( !ob ) return;
	tell_object(ob, (msg ? msg : "Unknown user reported from " + mud +
			   "."));
	return;
    }
}
