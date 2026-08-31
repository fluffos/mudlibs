//  Convert

#include <daemons.h>

mapping master;
string *member, *council, *leader, *squire;

void finish();

int cmd_convert(string str) {
    int i, x;
    string *dir, name, tmp;
    mapping m;

    if(!str || str != "ok") return 0;
    if(!GUILD_D->valid_master(this_player()->query_name())) return 0;
    m=([]);
    write("Converting .o files to master.o\n");
    dir=get_dir("/d/guilds/save/");
    i=sizeof(dir);
    while(i--) {
	if(file_exists("/d/guilds/save/"+dir[i])) {
	    restore_object("/d/guilds/save/"+dir[i]);
	    name=lower_case(dir[i][0..sizeof(dir[i])-3]);
	    x=sizeof(member);
	    while(x--) {
		m[member[x]]=name;
	    }
	    x=sizeof(squire);
	    while(x--) {
		m[squire[x]]=name;
	    }
	    x=sizeof(council);
	    while(x--) {
		m[council[x]]=name;
	    }
	    x=sizeof(leader);
	    while(x--) {
		m[leader[x]]=name;
	    }
	}
    }
    write("Done.\n");
    master=m;
    finish();
}

void finish() {
    member=council=leader=squire=0;
    save_object("/d/guilds/save/master");
}

