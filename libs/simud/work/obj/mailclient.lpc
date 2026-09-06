/**
 * The mail client object for the new system. Cloned up and inserted into
 * the inventory of anyone actually playing with their mail.
 */
#include <object.h>

#define MAIL_DAEMON  ("/secure/mail/daemon")
#define MAIL_PROMPT  "mail> "
#define EDIT_PROMPT  "> "

string buf;	// editor buffer (clear before any use, eh?)
string subject;	// subject of message
int _cmd;       // last command
string _arg;    // argument to the last command
int quit;	// whether or not to quit after the current operation
int uid;	// uid of the sender

mixed mail;	// mail messages in the current folder

void set_quit(int x) { quit = (x?1:0); }

/// Display an error message
void do_error(string cmd) {
   msg("~CWRNOops! ~[060"+cmd+"~CDEF is not a valid mail command. Type ~[060h~CDEF for help.");
}

/// Display mailer help (general or on a topic if one is specified)
void do_help() {
   string buf = "~CBRTSIMud Mail System v2 Help~CDEF\n"+
                "  ~[060h~CDEF  display help\n"+
                "  ~[060l~CDEF  list messages\n"+
                "  ~[060m~CDEF  send mail\n"+
                "  ~[060r~CDEF  read a message\n"+
//                "  ~[060a~CDEF  answer a message (reply)\n"+
//                "  ~[060d~CDEF  delete a message\n"+
//                "  ~[060v~CDEF  move a message\n"+
//                "  ~[060c~CDEF  change folders\n"+
//                "  ~[060i~CDEF  send an instant message\n"+
//                "  ~[060s~CDEF  subscribe to a list\n"+
//                "  ~[060u~CDEF  unsubscribe from a list\n"+
                "  ~[060q~CDEF  quit\n";
   msg(buf);
}

/// Display messages in the current folder
void do_list() {
   string buf = "~CTITYou have "+sizeof(mail)+" message(s):";
   int x;

   for (x = 0; x < sizeof(mail); x++) {
     string flag, sender = MAIL_DAEMON->query_username(mail[x][4]);
     switch (mail[x][3]) { // status
       case "new":     flag = "~[020N~CDEF"; break;
       case "unread":  flag = "~CDEFU"; break;
       case "replied": flag = "~[060A~CDEF"; break;
       case "deleted": flag = "~CWRND~CDEF"; break;
       case "read":
           default:    flag = " ";
     }
     buf += "\n "+flag+" ~CBRT"+pad(x+1,3,2)+"~CDEF ~[100"+
            pad(sender,15,2)+" ~[030"+mail[x][6];
   }

   msg(buf+"~CDEF");
}

/// Display help on the mailer
void do_mail() {
   if (MAIL_DAEMON->query_valid_address(_arg)) {
      msg("~[130Composing mail to: ~CDEF"+capitalize(_arg));
      msg("~CBRTTo finish your message, put ~[060.~CBRT on a blank line.\n"+
          "To cancel, put ~[060*Q~CBRT on a blank line.~CDEF");
      shift_interface( "do_edit", EDIT_PROMPT );
   } else
      msg("~CWRNOops!~CDEF Can't deliver mail to ~[060"+_arg+"~CDEF, no such player or list.");
}

/// Exit the mailer cleanly, warning the user.
void do_quit() {
   msg("~[130Exiting mailer.~CDEF");
   drop_interface();
   destruct(this_object());
}

/// Display a message
void do_read() {
   int num;
   if (!sscanf(_arg, "%d", num)) {
      msg("~CWRNOops!~CDEF You must specify the number of the message you "+
          "want to read.");
   } else {
      string sender, buf;
      if (num < 1 || num > sizeof(mail)) {
         msg("~CWRNOops!~CDEF There is no message number ~[060"+num+"~CDEF.");
         return;
      }
      num--;
      sender = MAIL_DAEMON->query_username(mail[num][4]);
      buf = "~CTITMessage "+num+"~CDEF\n"+
            "~CBRTFrom: ~CDEF"+sender+"\n"+
            "~CBRTDate: ~CDEF"+mail[num][5]+"\n"+
            "~CBRTSubject: ~CDEF"+mail[num][6]+"\n"+
            mail[num][7];
      msg(buf);
      // flag as read
   }
}

/// Load messages and stuff from the current folder
void reload() {
   uid = MAIL_DAEMON->query_uid(environment(this_object())->query_name());
   mail = MAIL_DAEMON->query_messages(uid,"inbox");
}

/// Initialize the mailer and kickstart the interface
void init() {
   if (!quit) {
     reload();
     do_list();
     add_interface( "do_command", MAIL_PROMPT );
   } else
     add_interface( "do_edit", EDIT_PROMPT );
   ::init();
}

/// Parse an execute a player's command input
void do_command(string str) {
   _cmd = str[0];
   _arg = str[2..];
   buf = "";

   if (_cmd && _cmd != '\n') {
      switch (_cmd) {
         case 'h': do_help(); break;
         case 'm': do_mail(); break;
         case 'l': do_list(); break;
         case 'q': do_quit(); break;
         case 'r': do_read(); break;
//         case 'd': do_delete(); break;
	
         default:  do_error( to_string( ({_cmd}) ) );
                   do_list();
      }
   }
}

/// Do something with the buffer
void send_buffer() {
   string from = environment(this_object())->query_name();
   // temporary fix
   subject = explode(buf,"\n")[0];
   subject = trim(subject[..20]);
   if (_cmd == 'm')
     MAIL_DAEMON->send_message(from,_arg,subject,buf);
   if (_cmd == 'i')
     MAIL_DAEMON->send_instant_message(from,_arg,subject,buf);

   if (quit)
      do_quit();
}

/// Edit the buffer
void do_edit(string line) {
   if (line == ".") {
      msg("~[130Done editing.~CDEF");
      if (buf != "")
         send_buffer();
      else
         msg("~CWRNOops!~CDEF Not sending empty mail.");
      shift_interface("do_command", MAIL_PROMPT);
   } else if (line == "*Q") {
      msg("~[130Message cancelled.~CDEF");
      shift_interface("do_command", MAIL_PROMPT);
   } else
      buf += line+"\n";
}
