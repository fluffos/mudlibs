
/* -------------------------------------------------------------------------
 * G-LIB v0.0-alpha0                        GENERIC OBJECT LIBRARY FOR LPMUD
 * (see /doc/license before altering the code)
 * -------------------------------------------------------------------------
 * file name   : callouts.c
 * description : shows a complete list of all callouts
 * coder(s)    : Mordoc
 * -------------------------------------------------------------------------
  * amendment   : modified Aug 14, 1997 to sort by time to callout
		  - Mordoc
 */


int main (string arg) {
    mixed *data = call_out_info();
    int i;
    string text = "";
    string ob;

    if (arg == "-size") {
	write("Callouts: "+sizeof(data)+"\n");
	return 1;
    }
    data = sort_array(data, "filter_times", this_object());

    message("write", sprintf("%-40s %-20s %-10s\n", "Object", "Function", "Delay to Go"), this_player());
    message("write", sprintf("^bb%-78s^c0", ""), this_player());
    write("\n");
    if (!sizeof(data)){
	write("There are no callouts active at the moment.\n");
	return 1;
    }
    for (i=0; i<sizeof(data); i++) {
	catch (ob = file_name(data[i][0]));
	text += sprintf("%-40s %-20s %-10d", ob, data[i][1], data[i][2]);
	message("write", text+"\n", this_player());
	text = "";
    }
    return 1;
}

filter_times (mixed one, mixed two) {
    if (one[2] < two[2]) return 1;
    return -1;
}
