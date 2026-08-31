//  players command
//    Whit
int cmd_players() {
    int i, count, i2;
    string *dir, *dir2, path;
    path="/adm/save/users/";
    seteuid("UserSave");
    dir = get_dir(path);
    dir -= ({ "rid", "save", "arrest" });
    i=sizeof(dir=get_dir(path));
    write("Statistics for Players existing on PD: \n");
    while(i--) {
	i2=sizeof(get_dir(path+dir[i]+"/"));
	while(i2--) count++;
    }
    write(count+" player files exist.\n");
    dir=get_dir(path+"arrest/");
    i=sizeof(dir);
    count=0;
    while(i--) {
	count++;
    }
    write(count+" arrested players.\n");
    dir=get_dir(path+"rid/");
    i=sizeof(dir);
    count=0;
    while(i--) {
	count++;
    }
    write(count+" dested players.\n");

    return 1;
}
