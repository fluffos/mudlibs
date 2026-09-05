int cmd_wimpy(string arg){
    int per;
    string ttt,dir;
    if(!arg) {
    write("Wimpy set at "+(int)this_player()->query_whimpy()
    +"% in "+(int)this_player()->query_whimpy_dir()+" direction.\n");
    write("To turn wimpy off use 'wimpy off'\n");
       return 1;
    }
    if(arg=="off") {
      this_player()->set_whimpy(0);
      this_player()->set_whimpy_dir("random");
      write("Brave mode.\n");
      say((string)this_player()->query_name()
      +" looks brave.\n");
      return 1;
    }
    if(sscanf(arg, "%d %s",per,dir) !=2) {
       write("Usage: 'wimpy <hp%> <direction>'\n");
       write("Direction can be \"random\" or any valid exit command.\n\n");
       return 1;
    }
    if(sscanf(dir,"do%s",ttt) && ttt != "wn") {
      write("No you don't.\n");
      return 1;
    }
    if(per > 99) {
      write("Now that is a rather silly value to set wimpy to.\n");
      write("Try a lower number.\n");
      return 1;
    }
    this_player()->set_whimpy(per);
    this_player()->set_whimpy_dir(dir);
    write("Wimpy set at "+per+"% in "+dir+" direction.\n");
    say((string)this_player()->query_name()
     +" looks a little more frightened.\n");
    return 1;
}