status
cmd_monitor(string str)
{
    if(str == "off")
    {
      write("Combat Monitor OFF.\n");
      this_player()->set_mon(0);
      return 1;
    }
    if(str == "on")
    {
      write("Combat Monitor ON.\n");
      this_player()->set_mon(1);
    }

    if(str == "default")
    {
      write("Combat Monitor set to DEFAULT.\n");
      this_player()->set_mon(1);
      this_player()->set_monitor_string(0);
    }
    if(str == "ansi")
    {
      write("Combat Monitor toggled to Default ANSI.\n");
      this_player()->set_mon(2);
      this_player()->set_monitor_string(0);
    }
    if(str == "auto")
    {
      if( (int) this_player()->query_mon() == 3 ) {
        write("Combat Monitor AUTO turned off, set to normal mode.\n");
        this_player()->set_mon(1);
	return 1;
      }
      this_player()->set_mon(3);
      write("Combat Monitor set to AUTO.\n");
    }
    this_player()->print_monitor();
    return 1;
}
