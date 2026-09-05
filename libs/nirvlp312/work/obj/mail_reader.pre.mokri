/*
 * obj/mail_reader.c
 *
 * This object is used by the post office for the mail functions.
 * Players receive it on entry, and it is destructed when leaving
 * through one of the exits.
 * Wizards can clone/dest at their leisure
 */

#define NAME "post_dir/"

string messages;                 /* The big string of all messages. */
int new_mail,line_length;        /* Flag if there is any new mail. */
int level;
int channel_block;
static string thingone,thingtwo;
static int cc_flag;
static string arr_messages;      /* the result of explode on 'messages' */
static int loaded;               /* Flag if this users mailbox is loaded */
static int curr_mess;            /* Current message number */
static string new_message, new_subject, new_dest, new_cc;
static int is_reading;

id(str) {
  return str == "mailread";
}

get() {
  return 1;
}

init() {
   add_action("read", "read");
   add_action("mail_to", "mail");
   add_action("headers", "from");
}

read(str) {
  if(str == "news")
    return 0;
  is_reading = 1;
  if (!loaded)
    load_player();
  load_player();
  loop();
  return 1;
}

load_player() {
  loaded = 1;
  if (!restore_object(NAME + this_player()->query_real_name()) ||
      messages == "" || messages == 0) {
    arr_messages = 0;
    messages = "";
    if (arr_messages == 0) {
      write("No mail.\n");
      return 1;
    }
    return;
  }
  if (new_mail) {
    new_mail = 0;
    save_object(NAME + this_player()->query_real_name());
  }
  arr_messages = explode(messages, "\n**\n");
}

headers() {
  int i, n;
  string tmp_str, tmp_str2, rest_of_mess, name;

  if (!loaded)
    load_player();
  if (arr_messages == 0) {
    write("No mail.\n");
    return 1;
  }
  for (i=0; i<sizeof(arr_messages); i+=2) {
    name = i/2+1 + " " + arr_messages[i];
    if (strlen(name) < 8)
      name += "\t";
    write(name + "\t");
    n = sscanf(arr_messages[i+1], "%sRe:   %s\n%s",
               tmp_str, tmp_str2, rest_of_mess);
    if (n == 3)
      write(" Re:   " + tmp_str2);
    n = sscanf(arr_messages[i+1], "%sSubj: %s\n%s",
               tmp_str, tmp_str2, rest_of_mess);
    if (n == 3)
      write(" Subj: " + tmp_str2);
    n = sscanf(arr_messages[i+1], "%sDate: %s\n%s",
               tmp_str, tmp_str2, rest_of_mess);
    if (n == 3)
      write(" Date: " + tmp_str2);
    write("\n");
  }
  return 1;
}

loop() {
  string tmp;
   
  if (!loaded)
    load_player();
  if (arr_messages == 0) {
    write("No messages.\n");
    is_reading = 0;
    return;
  }
  if (curr_mess < 1 || curr_mess > sizeof(arr_messages)/2)
    tmp = " (no current) ";
  else
    tmp = " (current: " + curr_mess + ") ";
  write("[1 - " + (sizeof(arr_messages)/2) + " h l d r ra x q b ?]" + tmp);
  input_to("get_cmd");
}

get_cmd(str) {
  int n, new_has_arrived;
  string tmp;
   
  /*
  * First, test all nondestructive commands. The destructive commands
  * will be tested after check if new mail has arrived.
  */
  if (!loaded) {
    load_player();
    new_has_arrived = 1;
  }
  if (str == "r") {
    reply_to_message();
    return;
  }
  if (str == "ra") {
    reply_to_message_all();
    return;
  }
  if (sscanf(str, "r %d", curr_mess) == 1) {
    reply_to_message();
  return;
  }
  if (str == "h") { 
    headers();
    loop();
    return;
  }
  if (str == "n") {
    curr_mess++;
    print_message();
    loop();
    return;
  }
  if (str == ".") {
    print_message();
    loop();
    return;
  }
  if (str == "l") {
    save_message();
    loop();
    return;
  }
  if (str == "b") {
    chan_block();
    loop();
    return;
  }
  if (sscanf(str, "m %s", tmp) == 1) {
    mail_to(tmp);
    return;
  }
  if (str == "?") {
    help_msg();
    loop();
    return;
  }
  if (str == "p" || str == "-") {
    curr_mess--;
    print_message();
    loop();
    return;
  }
  if (sscanf(str, "%d", n) == 1) {
    curr_mess = n;
    print_message();
    loop();
    return;
  }
  if (new_has_arrived) {
    write("New mail has arrived. Command ignored\n");
    loop();
    return;
  }
  if (str == "x") {
    too_many();
    is_reading = 0;
    return;
  }
  if (str == "d") {
    delete();
    loop();
    return;
  }
  if (str == "q") {
    check_delete_all();
    return;
  }
  if (sscanf(str, "d %d", curr_mess) == 1) {
    delete();
    loop();
    return;
  }
  loop();
}

print_message() {
  if (curr_mess > sizeof(arr_messages)/2 || curr_mess < 1) {
    write("Illegal message number " + curr_mess + "\n");
    return;
  }
  write("Message " + curr_mess + ":\n");
  write("From: " + arr_messages[curr_mess*2-2] + "\n");
  write(arr_messages[curr_mess*2-1] + "\n");
}

save_message() {
  string name;
  if(this_player()->query_level() < 20) {
    write("only wizards may write messages to /log.\n");
    return;
  }
  if (curr_mess > sizeof(arr_messages)/2 || curr_mess < 1) {
    write("Illegal message number " + curr_mess + "\n");
    return;
  }
  name = this_player()->query_real_name() + ".mbox";
  log_file(name, "From: " + arr_messages[curr_mess*2-2] + "\n");
  log_file(name, arr_messages[curr_mess*2-1] + "\n");
}

delete() {
  if (curr_mess > sizeof(arr_messages)/2 || curr_mess < 1) {
    write("Illegal message number " + curr_mess + "\n");
    return;
  }
  arr_messages = remove_element(arr_messages, curr_mess*2 - 2);
  arr_messages = remove_element(arr_messages, curr_mess * 2 - 2);
  if (sizeof(arr_messages) < 2)
    messages = "";
  else
    messages = implode(arr_messages, "\n**\n") + "\n**\n";
  new_mail = 0;
  save_object(NAME + this_player()->query_real_name());
  if (messages == "")
    arr_messages = 0;
  else
    arr_messages = explode(messages, "\n**\n");
}

mail_to(str) {
  if (!str || str == "") {
    write("No destination.\n");
    if (is_reading)
      loop();
    return 1;
  }
  load_player();
  new_subject = 0;
  new_cc = "";
  mail_to_continue(str);
  return 1;
}

mail_to_continue(str) {
  str = lower_case(str);
  if (!restore_object("pfiles/" +extract(str,0,0)+"/"+ str)) {
    write("No such player.\n");
    if (is_reading)
      loop();
    return 1;
  }
  if(this_player()) {
    if(this_player()->query_real_name() == "guest") {
      write("You cannot send mail as guest.\n");
      return 1;
    }
    if(this_player()->query_age() < 1800) {
      if(level < 21) {
        write("You may only send mail to wizards when less than 1 hour old.\n");
        return 1;
      }
    }
  }
  level = 0;
  new_dest = str;
  new_message = "";
  if (new_subject)
    write("Return to get '" + new_subject + "'\n");
  write("Subject: ");
  input_to("get_subject");
  return 1;
}

get_subject(str) {
  if (str && str != "") /* Truncate the subject at 60 characters */
    new_subject = "Subj: " + str[0..60] + "\n";
  if (new_subject == 0) {
    write("No subject.\n");
    if (is_reading)
      loop();
    return;
  }
  /* using the universal text editor
  write("Give message.  Finish message with '**', or '~q' to cancel\n");
  write("]");
  input_to("more_mail");
  */
  call_other("/obj/user/text_edit","start_edit",this_object(),"end_edit",50);
  return;
}

end_edit(str) {
  if(!str) {
    write("Aborted.\n");
    if(is_reading)
      loop();
  } else {
    new_message=str;
    if(new_cc)
      if(new_cc && new_cc!="")
        write("Return to get '" + new_cc + "'\n");
    write("Cc:");
    input_to("get_cc");
    return;
  }
}
  
/*
more_mail(str) {
  if (str == "~q") {
    write("Aborted.\n");
    if (is_reading)
      loop();
    return;
  }
  line_length += 1;
  if(line_length > 50) {
    write("Message is too long. Forcing send.\n");
    write("last line will be lost.\n");
    str = "**";
  }
  if (str == "**") {
    line_length = 0;
    if (new_cc)
      if (new_cc && new_cc!="")
        write("Return to get '" + new_cc + "'\n");
    write("Cc:");
    input_to("get_cc");
    return;
  }
  new_message += str + "\n";
  write("]");
  input_to("more_mail");
}
*/

get_cc(cc) {
  int n;
  object ob;
  string cc2, next_pern;
   
  if (sscanf(cc, "%s/%s", thingone,thingtwo) == 2) {
    write("Not a legal name, no carbon copy sent.\n");
    log_file("BAD_PLAYER", ctime(time()) + " " +
             this_player()->query_real_name() + " with mail_reader, file " +
             cc + "\n");
    cc = "";
  }
  if(cc=="admin" || cc=="seniors" || cc=="admins" || cc=="senior")
    cc=read_file("/doc/admin/mail");
  if (!cc || cc=="")
    cc = new_cc;
  send_mail(new_dest, new_subject + "\n", new_message, cc);
  if (cc && cc != "") {
    cc2 = cc;
    cc = lower_case(cc2);
    cc2 = "(To: " + new_dest + ") " + cc;
    while (cc != "") {
      n = sscanf(cc,"%s,%s",next_pern,cc);
      if (n == 0) {
        next_pern = cc; /* cc held remaining line; do last person. */
        cc = "";         /* set cc to "" to leave loop after this    */
      }
      if (restore_object("pfiles/"+extract(next_pern,0,0)+"/"+next_pern))
        send_mail(next_pern, new_subject + "\n", new_message, cc2);
      if (!restore_object("pfiles/"+extract(next_pern,0,0)+"/"+next_pern))
         write("There is no player named "+next_pern+".\n");
    }
  }
  if (is_reading)
    loop();
}

/*
* Send a complete mail. If the receiver is reading mail, be sure to
* tell his mail reader that new mail has arrived.
*/
send_mail(dest, subj, mess, cc) {
  if (cc != "")
    cc = "Cc: " + cc + "\n";
  notify_new_mail(dest, subj, this_player()->query_real_name());
  messages = "";
  restore_object(NAME + dest);
  if (messages == 0)
    messages = "";
  messages += this_player()->query_real_name() + "\n**\n" + subj + cc +
              "Date: " +
              extract(ctime(time()), 4, 15) +
              "\n\n" + mess + "\n**\n";
  new_mail = 1;
  save_object(NAME + dest);
}

notify_new_mail(dest, subj, name) {
  object ob;
  if (ob = find_player(dest)) {
    tell_object(ob,"You have new mail from " + name + ", " + subj + "\n");
    ob = present("mailread", ob);
    if (ob)
      ob->invalidate();
  }
  write("Sending mail to " + capitalize(dest) + ".\n");
}

invalidate() {
  loaded = 0;
}

drop() {
  return 1;
}

reply_to_message() {
  int n;
  string tmp_str, tmp_str2, rest_of_mess, name;

  name = lower_case(arr_messages[curr_mess*2-2]);
  n = sscanf(arr_messages[curr_mess*2-1],"%sRe:   %s\n%s",
             tmp_str, tmp_str2, rest_of_mess);
  new_subject = " Re:   " + tmp_str2;
  n = sscanf(arr_messages[curr_mess*2-1],"%sSubj: %s\n%s",
             tmp_str, tmp_str2, rest_of_mess);
  new_subject = " Re:   " + tmp_str2;
  new_cc = "";
  mail_to_continue(name);
}

reply_to_message_all() {
  int n;
  string tmp_str, tmp_str2, rest_of_mess, name;

  name = lower_case(arr_messages[curr_mess*2-2]);
  n = sscanf(arr_messages[curr_mess*2-1],"%sRe:   %s\n%s",
             tmp_str, tmp_str2, rest_of_mess);
  new_subject = " Re:   " + tmp_str2;
  n = sscanf(arr_messages[curr_mess*2-1],"%sSubj: %s\n%s",
             tmp_str, tmp_str2, rest_of_mess);
  new_subject = " Re:   " + tmp_str2;
  new_cc = "";
  n = sscanf(arr_messages[curr_mess*2-1],"%sCc: %s\n%s",
             tmp_str, tmp_str2, rest_of_mess);
  new_cc = tmp_str2;
  n = 0;
  if(new_cc && new_cc != "")
    n = sscanf(new_cc,"(To: %s) %s",tmp_str,tmp_str2);
  if(n==2)
    new_cc = tmp_str+","+tmp_str2;
  cc_flag = 1;
  mail_to_continue(name);
}

help_msg() {
  write("?        This help message.\n");
  write("h        Print all headers.\n");
  write("p        Print previous message.\n");
  write("n        Print next message.\n");
  write("r        Reply to current message.\n");
  write("r <num>	 Reply to message number 'num'.\n");
  write("ra       Reply to all for current message.\n");
  write("m <name> Mail a message to player 'name'.\n");
  write("d        Delete current message.\n");
  write("d <num>	 Delete message number 'num'.\n");
  if(this_player()->query_level()>20)
    write("l        Append current message to /log/name.mbox\n");
  write("b        Turn on channel block.\n");
  write("x        Exit from mail reading mode.\n");
  write("q        Quit and ask if messages should be erased.\n");
  return 1;
}

check_delete_all() {
  write("Okay to delete all mail? ");
  input_to("check_delete_all2");
}

check_delete_all2(str) {
  int i;

  if (str == "y" || str == "Y") {
  /*
      messages = 0;
      arr_messages = 0;
  */
    i=0;
    while (sizeof(arr_messages) > 0) {
      remove(1);
      i += 1;
    }
  }
  too_many();
  return 1;
}

remove_element(old_array, element) {
  string new_array;
  int index;
   
  new_array = allocate(sizeof(old_array) - 1);
  index = 0;
  while (index < element) {
    new_array[index] = old_array[index];
    index++;
  }
  index = element + 1;
  while (index < sizeof(old_array)) {
    new_array[index - 1] = old_array[index];
    index++;
  }
  return new_array;
}

/*
    fix for deleteing messages while running 3.0 from shadowhawk
    fix to stop blanking out of files from boltar.
*/
too_many() {
  if (sizeof(arr_messages)/2 > 6 &&
      this_player()->query_level() < 21) {
    write("You have too many messages in your file, you can have "+
          " no more than six.\nPlease delete some.\n");
    loop();
  }
  return 1;
}

remove(arg) {
  arr_messages = remove_element(arr_messages, arg*2 - 2);
  arr_messages = remove_element(arr_messages, arg * 2 - 2);
  if (sizeof(arr_messages) < 2)
    messages = "";
  else
    messages = implode(arr_messages, "\n**\n") + "\n**\n";
  new_mail = 0;
  save_object(NAME + this_player()->query_real_name());
  if (messages == "")
    arr_messages = 0;
  else
    arr_messages = explode(messages, "\n**\n");
}

query_block() {
  return channel_block;
}

chan_block() {
  if (!channel_block) {
    channel_block = 1;
    write("Channel Block on.\n");
    save_object(NAME + this_player()->query_real_name());
    return;
  }
  if (channel_block) {
    channel_block = 0;
    write("Channel Block off.\n");
    save_object(NAME + this_player()->query_real_name());
    return ;
  }
}

