#define TOP_DIR "post_dir/"
string messages;

int move_mailbox(string mailbox)
{
  string msg_to,msg_from,my_subject,my_mess, *arr_messages, *tmp;
  int a, b, c;
  
  if(!mailbox)
  {
    write("Error. No mailbox name specified.\n");
    return 1;
  }
  
  if(!restore_object(TOP_DIR + mailbox))
  {
    write("Cannot restore mailbox: " + mailbox + "\n");
    return 1;
  }
  
  arr_messages = explode(messages, "\n**\n");
  for(a = 0; a+1 < sizeof(arr_messages);a+=2)
  { 
    my_mess = "";
    tmp = explode(arr_messages[a+1],"\n");
    for(b = 4; b < sizeof(tmp); b++)
      my_mess += tmp[b] + "\n";
    my_mess = db_conv_string(my_mess);
    msg_from = capitalize(arr_messages[a]);
    msg_to = lower_case(mailbox);
    my_subject = db_conv_string(extract(tmp[0],6));
    c = (int)"/players/mokri/cmds/funcs/time"->date_to_time(extract(tmp[2],6));
    db_get_rs("insert into mail (msg_to,msg_from,subject,message,mail_time) values('" + msg_to + "','" + msg_from + "','" + my_subject + "','" + my_mess + "'," + c + ")");
  }
  write("Converted: " + mailbox + "\n");  
  return 1;
}
  
cmd_mail_convert(string str)
{
  int x;
  string *all_people;
  
if(this_player()->query_level() < 1000) return 0;
  if(!str)
  {
    all_people = get_dir("/" + TOP_DIR);
    for(x = 0; x < sizeof(all_people); x++)
    {
      if(extract(all_people[x],strlen(all_people[x])-2) == ".o")
        move_mailbox(extract(all_people[x],0,strlen(all_people[x])-3));
    }
    return 1;
  }
  
  move_mailbox(str);
  return 1;
}
