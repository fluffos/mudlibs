//  Scary command by whit

int cmd_scareplayers() {
    string file;
    string *dir;
    int i;

    dir = get_dir("/news/death/");
    i=random(sizeof(dir));
    file = read_file("/news/death/"+dir[i]);
    if(!archp(this_player())) return 0;
    write("You scary person you!\n");
    seteuid(geteuid(previous_object()));
    message("scary", "Boo.!\n\n"+file+"\nYou just thought you died didnt you?", users());
    return 1;
}

