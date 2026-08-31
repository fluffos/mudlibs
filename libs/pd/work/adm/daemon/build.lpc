string *file_to_array(string file) {
    seteuid(geteuid(previous_object()));
    if(!read_file(file)) return 0;
    return explode(read_file(file), "\n");
}

string *change_name(string *lines, string s) {
    int i;
    int ok;
    i=sizeof(lines);
    while(i--) {
	if(lines[i][0..7] == "set_name") { lines[i]="set_name(\""+s+"\");"; ok=1; }

    }
    if(!ok) { 
	error("Error changing name.\n");
	return 0; 
    }

    return lines;
}

string *change_short(string *lines, string s) {
    int i;
    int ok;
    i=sizeof(lines);
    while(i--) {
	if(lines[i][0..8] == "set_short") { lines[i]="set_short(\""+s+"\");"; ok=1; }

    }
    if(!ok) { 
	error("Error changing short.\n");
	return 0; 
    }
    return lines;
}

string *change_desc(string *lines, string s) {
    int i;
    int ok;
    i=sizeof(lines);
    while(i--) {
	if(lines[i][0..7] == "set_long") { lines[i]="set_long(\""+s+"\");"; ok=1; }     
    }
    if(!ok) { 
	error("Error changing desc.\n");
	return 0; 
    }

    return lines;
}

string *change_exits(string *lines, mapping exits) {
    int i, linnum, x;
    string lin, *ar;
    mapping cur=([]);
    if(!exits || exits == ([])) return lines;
    i=sizeof(lines);
    while(i--) {
	if(lines[i][0..8] == "set_exits") { lin=lines[i]; linnum=i; }
    }
    if(!lin || !linnum) return 0;
    //  Break apart:  set_exits((["":"",]));
    ar=explode(lin[12..sizeof(lin)-6], ",");
    x=sizeof(ar);
    while(x--) {
	cur[explode(ar[x], ":")[0][1..sizeof(explode(ar[x],":"))-1]]=explode(ar[x],":")[1];
    }
    i=sizeof(keys(exits));
    while(i--) cur[keys(exits)[i]]=exits[keys(exits)[i]];
    lines[linnum]="set_exits(([";
    i=sizeof(keys(cur));
    while(i--)
	lines[linnum] += "\""+keys(cur)[i]+"\":\""+cur[keys(cur)[i]]+"\",";
    lines[linnum] += "]));";
    return lines;
}

int is_room(string *lines) {
    int i, ok;
    i=sizeof(lines);
    while(i--) if(lines[i] == "// **(Editor Ok Room)**") ok=1;
    return ok;
}

