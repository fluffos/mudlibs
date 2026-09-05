#define TP this_player()
#define LOWER lower_case
#define CAP capitalize

string subject, message, *recipients;
int mess_num;
mixed *mailbox;

id(str) { return "mailreadthingy"; }
get() { return 1; }
drop() { destruct(this_object()); }

int query_new_mail()
{
    int handle;

    if(!TP) return 0;
    handle = db_connect();
    db_exec(handle,"SELECT id FROM mail where msg_to = '" + LOWER(TP->query_real_name()) + "' AND has_read = 0");
    if(!db_fetch(handle))
    {
	db_close(handle);
	return 0;
    }

    db_close(handle);
    return 1;
}

reader_choice(string str)
{
    int handle, idnum;
    string tmp, *this_mess;
    this_mess = mailbox[mess_num];
    if(str == "1")
    {
	recipients = ({ });
	tmp = this_mess[2];
	write("Input any other recipients, one on each line.\n"+
	  "Type '**' when finished, or '~q' to abort.\n");
	message = "---Begin Original---\n" + this_mess[4] +"\n----End Original----\n\n";
	subject = "RE: " + this_mess[3];
	mail_to(tmp);
	return 1;
    }

    if(str == "2")
    {
	handle = db_connect();
	idnum = (int)this_mess[0];
	db_exec(handle,"delete from mail where id = " + idnum);
	db_close(handle);
	write("Message Deleted.\n");
	list_messages();
	return 1;
    }

    if(str == "3")
    {
	message = this_mess[4];
	write("If you write more to the message, it will be appended to the END of the message.\n\n"+
	  "Input recipients, one on each line.\n"+
	  "Type '**' when finished, or '~q' to abort.\n"+
	  "] ");
	message = "---Begin Original---\n" + this_mess[4] +"\n----End Original----\n\n";
	subject = "FW: " + this_mess[3];
	input_to("mail_to");
	return 1;
    }

    if(str == "4")
    {
	mess_num += 2;
	read_message((string)mess_num);
	return 1;
    }

    if(str == "5")
    {
	list_messages();
	return 1;
    }

    if(str == "6")
    {
	main_menu();
	return 1;
    }

    write("Invalid selection.\n"+
      "] ");
    input_to("reader_choice");
    return 1;
}

read_message(string str)
{
    string *this_message;
    int handle, idnum, datenum;

    mess_num = 0;
    if(str == "m")
    {
	main_menu();
	return 1;
    }

    if(sscanf(str,"%d",mess_num) != 1 || sizeof(mailbox) < mess_num || mess_num < 1)
    {
	write("Invalid message.\n"+
	  "Pick a message number to read, or 'm' to return to the Main Menu.\n"+
	  "] ");
	input_to("read_message");
	return 1;
    }

    mess_num -= 1;
    this_message = mailbox[mess_num];
    datenum = (int)this_message[6];
    write("From   : " + this_message[2] + "\n"+
      "Subject: " + this_message[3] + "\n"+
      "Date   : " + ctime(datenum) + "\n"+
      "------------------------------\n\n"+
      this_message[4] + "\n\n"+
      "------------------------------\n"+
      "End of Message\n\n");

    if(this_message[5] == "0") {
	idnum = (int)this_message[0];
	handle = db_connect();
	db_exec(handle,"update mail set has_read = TRUE where id = " + idnum);
	db_close(handle);
    }

    write("1] Reply\n"+
      "2] Delete\n"+
      "3] Forward\n"+
      "4] Next message\n"+
      "5] Return to Inbox\n"+
      "6] Main Menu\n\n"+
      "Selection: ");
    input_to("reader_choice");
    return 1;
}

list_messages()
{
    int handle, x, datetime;
    string mess_num, unread, *tmp;

    handle = db_connect();
    mailbox = ({ });
    db_exec(handle,"SELECT * FROM mail where msg_to = '" + LOWER(TP->query_real_name()) + "'");

    while(sizeof(tmp = db_fetch(handle)))
	mailbox += ({ tmp });
    db_close(handle);

    if(!sizeof(mailbox))
    {
	write("Inbox empty.\n");
	main_menu();
	return 1;
    }

    write("       Subject                         From              Date\n"+
      "---------------------------------------------------------------------------------\n");
    for(x = 0; x < sizeof(mailbox); x++)
    {
	tmp = mailbox[x];
	unread = " ";
	if(tmp[5] == "0") unread = "*";
	mess_num = (x+1) + ".";
	datetime = (int)tmp[6];
	printf("%-4s %-1s %-31s %-17s %s\n",mess_num,unread, tmp[3],tmp[2],ctime(datetime));
    }
    write("\n\n* == Unread\n"+
      "---------------------------------------------------------------------------------\n"+
      "Pick a message number to read, or 'm' to return to the Main Menu.\n"+
      "] ");
    input_to("read_message");
    return 1;
}

write_message()
{
    int x, handle;

    handle = db_connect();
    write("Message sent to:\n");
    for(x = 0; x < sizeof(recipients); x++)
    {
    subject = db_conv_string(subject);
    message = db_conv_string(message);
	db_exec(handle, "INSERT INTO mail (msg_to,msg_from,subject,message,has_read,mail_time) VALUES ('" + recipients[x] + "','" + CAP(TP->query_real_name()) + "','" + subject + "','" + message + "',FALSE," + time() + ")");
	write("  " + CAP(recipients[x]) + "\n");
	if(find_player(recipients[x]))
	    tell_object(find_player(recipients[x]),"[notify: You have NEW mail.]\n");
    }
    db_close(handle);

    subject = "";
    message = "";
    recipients = ({ });
    main_menu();
    return 1;
}

get_message(string str)
{

    if(str == "~q")
    {
	write("Aborting.\n");
	main_menu();
	return 1;
    }

    if(str == "**")
    {
	if(!strlen(message))
	{
	    write("Empty message.\nAborting.\n");
	    main_menu();
	    return 1;
	}

	write_message();
	return 1;
    }

    message += str + "\n";
    write("] ");
    input_to("get_message");
    return 1;
}

get_subject(string str)
{
    if(subject && subject != "") str = subject;
    if(!strlen(str)) str = "[No Subject]";
    if(strlen(str) > 30) str = extract(str,0,29);
    subject = str;
    write("Input Message.\nEnd with '**' on a blank line. '~q' to abort.\n\n"
      "] ");
    input_to("get_message");
    return 1;
}

mail_to(string str)
{
  mixed *tmp_player_find;
    if(str == "~q") {
	write("Aborting.\n");
	main_menu();
	return 1;
    }

    if(str == "**")
    {
	if(!sizeof(recipients))
	{
	    write("No valid recipients.\n"
	      "Input recipients, one on each line.\n"+
	      "Type '**' when finished, or '~q' to abort.\n"+
	      "] ");
	    input_to("mail_to");
	    return 1;
	}

	if(subject && strlen(subject)) write("Leave blank for: " + subject +"\n");
	write("Subject (max 30 characters): ");
	input_to("get_subject");
	return 1;
    }

    str = LOWER(trim(str));
    if(!TP->valid_name(str))
    {
	write("Invalid name: " + str + "\n] ");
	input_to("mail_to");
	return 1;
    }

  tmp_player_find = db_get_rs("select name from players where name='" + str + "'");
    if(!sizeof(tmp_player_find))
    {
	write("No such player: " + str + "\n] ");
	input_to("mail_to");
	return 1;
    }

    if(member(recipients,str) != -1)
    {
	write(CAP(str) + " is already on the recipients list.\n] ");
	input_to("mail_to");
	return 1;
    }

    recipients += ({ str });
    write("] ");
    input_to("mail_to");
    return 1;
}

main_choice(string str)
{
    switch(str)
    {
    case "1":
	list_messages();
	break;

    case "2":
	write("Input recipients, one on each line.\n"+
	  "Type '**' when finished, or '~q' to abort.\n"+
	  "] ");
	input_to("mail_to");
	break;

    case "3":
	write("Exiting.\n");
	destruct(this_object());
	break;

    default:
	write("Invalid Selection.\n\n");
	main_menu();
	break;
    }

    return 1;
}
main_menu()
{
    recipients = ({ });
    mailbox = ({ });
    message = "";
    subject = "";
    mess_num = -1;

    write("====================\n"+
      "|     MUD MAIL     |\n"+
      "====================\n"+
      "| 1] Inbox         |\n"+
      "| 2] Compose       |\n"+
      "| 3] Exit          |\n"+
      "|                  |\n"+
      "====================\n\n"+
      "Selection: ");
    input_to("main_choice");
    return 1;
}

status main(string str)
{
    if(!str) main_menu();
    recipients = ({ });
    message = "";
    if(str) {
	write("Input any other recipients, one on each line.\n"+
	  "Type '**' when finished, or '~q' to abort.\n");
	mail_to(str);
    }
    return 1;
}
