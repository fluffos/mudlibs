int trick(string str) {
    object tellme;
    string *tellus;
    int i;
    if(str == "all")
      message("info", read_file("/news/ghost"), users(), this_player());
    else {
      tellus = explode(str, ", ");
      i = sizeof(tellus);
      while(i--) {
        if(!tellme = find_player(tellus[i]))
          write("Could not find "+tellus[i]+".");
        else {
          message("info", "You die a horrible death.\n"+read_file("/news/ghost")+"", tellme, );
          write(tellus[i]+": Ok.");
          }
        }
     }
    return 1;
}
