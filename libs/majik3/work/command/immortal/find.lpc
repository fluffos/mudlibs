#define DOCS "/doc/"

string Finds = "";
string Search;
int Count = 0;

recurse_subdir(string);
string get_man_info(string);

int main(string arg){
    mixed *junk;
    int i;
    string text;

    if (!arg){
	write("Find similar functions of what?\n");
	return 1;
    }
    Search = arg;
    junk = get_dir(DOCS, -1);
    for (i=0; i<sizeof(junk); i++){
	if (junk[i][1] != -2){
	    text = get_man_info(DOCS+junk[i][0]);
	    write(DOCS+junk[i][0]+"\n");
	    if (strsrch(text, arg) != -1){
		Finds += text+"\n";
		Count++;
	    }
	}
	else {
	    write("Recursing ["+DOCS+junk[i][0]+"]\n");
	    recurse_subdir(DOCS+junk[i][0]+"/");
	}
    }
    if (Count > 0){
	write(Finds+"\n");
    }
    else write("No matches found.\n");
    return 1;
}

recurse_subdir(string dir){
    mixed *junk;
    int i;
    string text;

    junk = get_dir(dir, -1);
    for (i=0; i<sizeof(junk); i++){
	if (junk[i][1] != -2){
	    write(dir+junk[i][0]+"\n");
	    text = get_man_info(dir+junk[i][0]);
	    if (strsrch(text, Search) != -1){
		Finds += text + "\n";
		Count++;
	    }
	}
	else {
	    write("Recursing ["+dir+junk[i][0]+"]\n");
	    recurse_subdir(dir+junk[i][0]+"/");
	}
    }
    return ;
}

string get_man_info (string fn){
    string ret = "";

    if (explode(read_file(fn), "\n")){
	ret = explode(read_file(fn), "\n")[0];
	ret += explode(read_file(fn), "\n")[1];
    }
    return ret;
}

