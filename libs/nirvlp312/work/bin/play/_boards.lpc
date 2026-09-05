int show_help()
{
      write("Syntax: boards [list || view || read || post || remove] [board number] [post number || subject]\n\n"+
          "boards list\n"+
          "  List boards\n\n"+
          "boards view [board number]\n"+
          "  View headers of posts on board [board number]\n\n"+
          "boards read [board number] [post number]\n"+
          "  Read post [post number] on board [board number].\n"+
          "  If no [post number] is given, reads the next unread note.\n\n"+
          "boards post [board number] [subject]\n"+
          "  Create a new note on [board number] with subject [subject].\n\n"+
          "board remove [board number] [post number]\n"+
          "  Remove post number [post number] from board [board number].\n");
  return 1;
}

int cmd_boards(string str)
{
  string short, subj, *rs;
  mixed *all, *tmp;
  int x, board_num;

#ifdef __LDMUD__

  if(!str)
    str = "list";

  if(sscanf(str,"%s %d %s",str,board_num,subj));

  if(str != "list" && str != "read" && str != "post" && str != "remove" && str != "view")
  {
    show_help();
    return 1;
  }

  all = db_get_rs("select board_id,board_path,board_name from boards");
  tmp = all;
  for(x = 0; x < sizeof(all); x++)
  {
    rs = all[x];
    if(!this_player()->valid_board((int)rs[0]))
      tmp -= ({ rs });
  }

  all = tmp;

  if(str == "list")
  {
    for(x = 0; x < sizeof(all); x++)
    {
      rs = all[x];
      short = call_other(rs[1],"short");
      write((x+1) + ". " + short+ "\n");
    }
  return 1;
  }

 if(str == "view")
  {
    if(!board_num || board_num < 1 || board_num > sizeof(all))
    {
      write("Valid board numbers are between 1 and " + sizeof(all) + "\n");
      return 1;
    }
    board_num -= 1;
    rs = all[board_num];
      call_other(rs[1],"long");
    return 1;
  }

  if(str == "read")
  {
    if(!board_num || board_num < 1 || board_num > sizeof(all))
    {
      write("Valid board numbers are between 1 and " + sizeof(all) + "\n");
      return 1;
    }
    board_num -= 1;
    rs = all[board_num];
    if(!subj)
      call_other(rs[1],"read");
    else
      call_other(rs[1],"read",subj);
    return 1;
  }

    if(str == "post")
  {
    if(!board_num || board_num < 1 || board_num > sizeof(all))
    {
      write("Valid board numbers are between 1 and " + sizeof(all) + "\n");
      return 1;
    }
    board_num -= 1;
    if(!subj)
    {
      write("Please supply a subject.\n");
      return 1;
    }

    rs = all[board_num];
    call_other(rs[1],"note",subj);
  }

    if(str == "remove")
  {
    if(!board_num || board_num < 1 || board_num > sizeof(all))
    {
      write("Valid board numbers are between 1 and " + sizeof(all) + "\n");
      return 1;
    }
    board_num -= 1;
    if(!subj)
    {
      write("Please supply a note number.\n");
      return 1;
    }

    rs = all[board_num];
    call_other(rs[1],"remove",subj);
  }

  return 1;
#endif
write("LD only command.\n");
return 1;
}
