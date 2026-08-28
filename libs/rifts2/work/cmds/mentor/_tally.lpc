/*  /cmds/adm/_tally.c
 *  Made for DarkeMUD
 *  Created by Geldron 031796
 *  Copyright (c) 1996
 *  Do not remove this header
 */


int cmd_tally(string arg) {
    object *arr;
    string *kvotes, tmp;
    int *vvotes, yes, no, i, j;

    if(!TP) return 0;
    if(!archp(TP)) return 0;
    arr = users();
    message("tally", "Tallying up the votes...", users());
    kvotes = keys((mapping)find_object("/std/obj/voter")->query_votes());
    vvotes = values((mapping)find_object("/std/obj/voter")->query_votes());
    for(i = 0; i < sizeof(kvotes); i++) {
	if(vvotes[i] == 1) {
	    tmp = "No";
	    no++;
	} else if(vvotes[i] == 2) {
	    tmp = "Yes";
	    yes++;
	} else tmp = "N/A";
	for(j = 0; j < sizeof(arr); j++) {
	    if(kvotes[i])
		if(find_player(kvotes[i]) ? (int)arr[j]->query_level() >
		  (int)find_player(kvotes[i])->query_level() : 1)
		    message("tally", sprintf("%-25s: %-s", kvotes[i] ?
			CAP(kvotes[i]) : "ERROR", tmp), arr[j]);
	}
    }
    message("tally", sprintf("\nEnd score:\nYes: %-d\nNo: %-d", yes, no), users());
    message("tally", "Done.", TP);
    find_object("/std/obj/voter")->set_votes(([]));
    return 1;
}

void help() {
    message("tally_help", syntax("tally") +
      "\n\nTallies the votes if there is currently a vote on "
      "something.  This is the ending process of voting.", TP);
}
