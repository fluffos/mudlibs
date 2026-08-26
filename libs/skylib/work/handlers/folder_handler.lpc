/*
 * History.
 * 30/07/01, Shiannar: Removed the postal frogs from service.
 */
/**
 *  Folder handler for the mailer.
 *  Actually it does a lot more :-)
 * <p>
 *  Thanks to Wodan and Pinkfish for ideas and help. <br>
 *  By Turrican@Discworld, May 1995.
 * @author Turrican
 * @started May 1995
 */

#pragma strict_types

#include <board.h>
#include <comms.h>
#include <mail.h>
#include <network.h>
#include <mime.h>

#define MAIL_PATH "/save/mail/"
/* #define CONVERTER "/handlers/converter" */
#undef CONVERTER

int *mesg_numbers;
class mail_header *info;
int new_thingy;
nosave int link;

class mail_header *get_messages(string pname, string fname);
string load_message(string pname, string fname, int number);
void delete_it(string pname, string fname, int *deleted);
string check_local(string arg);
private int load_counter();
private void save_counter(int counter);
void dest_me();
#ifdef CONVERTER
void convert_mail(string pname);
#endif
private void convert_links(int number);
void delete_account(string player);

void create() {
  seteuid("Mailer");
} /* create() */

private string folder_filename(string name) {
  if(file_size(MAIL_PATH + name) != -1) {
    unguarded((: rename, MAIL_PATH + name,
           MAIL_PATH + name[0..0] + "/" + name :));
  } else if(file_size(MAIL_PATH + name + ".o") != -1) {
    unguarded((: rename, MAIL_PATH + name + ".o",
           MAIL_PATH + name[0..0] + "/" + name + ".o" :));
  }

  return MAIL_PATH+name[0..0] + "/"  + name;
}

private string message_filename(int num, string prefix) {

  if(file_size(MAIL_PATH+"new_mesg/" + (num % 50)) == -1) {
    unguarded((: mkdir, MAIL_PATH+"new_mesg/" + (num % 50) :));
  }
  if(file_size(MAIL_PATH+"new_mesg/"+(num % 50)+"/"+((num / 50) % 50)) == -1) {
    unguarded((: mkdir, MAIL_PATH+"new_mesg/" + (num %50) + "/" +
           ((num / 50) % 50) :));
  }
#ifdef 0
  if(file_size(MAIL_PATH + "mesg/" + prefix + num) != -1) {
    unguarded((: rename, MAIL_PATH + "mesg/" + prefix + num,
       MAIL_PATH+"new_mesg/"+ (num % 50) + "/" + ((num / 50) % 50) +
       "/" + prefix + num :));
  }
#endif

  return MAIL_PATH+"new_mesg/"+  (num % 50) + "/" + ((num / 50) % 50) +
    "/" + prefix + num;
}

private int check() {
    string tmp;

    tmp = base_name(PO);

    if( tmp != "/handlers/mailer" &&
        tmp != "/handlers/folder_handler" &&
        tmp != "/handlers/converter" &&
        tmp != "/net/daemon/pop3") {
        write("Folder handler: Illegal access!\n");
        return 1;
    }

    return 0;

} /* check() */

private void convert_class( string pname, string fname ) {
  class mail_header hdr;
  int i;

  i = sizeof(info);

  while( i-- ) {
    hdr = new( class mail_header );
    hdr->number = ((mapping)info[i])["number"];
    hdr->status = ((mapping)info[i])["status"];
    hdr->subject = ((mapping)info[i])["subject"];
    hdr->from = ((mapping)info[i])["from"];
    info[i] = hdr;
  }

  unguarded( (: save_object, folder_filename(lower_case(pname)+"_"+fname) :) );

} /* convert_class() */

/**
 * This method returns the messages for the player in the specified
 * folder.  The return is an array of messages of type 'class mail_header'.
 * @param pname the players name
 * @param fname the folder name
 * @return a list of messages
 */
class mail_header *get_messages(string pname, string fname) {

  if( check() )
      return ({ });

  mesg_numbers = ({ });
  info = ({ });
  new_thingy = 0;
  unguarded( (: restore_object, folder_filename(lower_case(pname)+"_"+fname) :) );

  if( sizeof(info) && mapp(info[0]) )
      convert_class( pname, fname );

  return info;

} /* get_messages() */

/**
 * This method loads a message for the specified player in the specified
 * folder.
 * @param pname the players name
 * @param fname the folder name
 * @param number the message number to open
 * @return the text of the message
 */
string load_message(string pname, string fname, int number) {
  string message;

  if( check() )
      return " ";

  if( file_size( message_filename( number, "l") ) == -1 )
      convert_links(number);

  message = unguarded( (: read_file, message_filename( number, "") :) );

  if( !message )
      printf("* Failed to load message.\n", number );

  return message;

} /* load_message() */

/**
 * This method will attempt to the delete the specified messages from
 * the folder.  The array deleted must be an array of integers where each
 * number is a message number to be deleted.
 * @param pname the players name
 * @param fname the folder name
 * @param deleted the array of message numbers to delete from the folder
 */
void delete_it( string pname, string fname, int *deleted ) {
  string tmp;
  int i, idx;

  if( check() )
      return;

  if( !PLAYER_H->test_user(pname) )
      return;

  if( sizeof(deleted) > 1 ) {
      deleted = uniq_array( deleted );
      deleted = sort_array( deleted, 1 );
  }

  mesg_numbers = ({ });
  info = ({ });
  new_thingy = 0;

  unguarded( (: restore_object, folder_filename(lower_case(pname)+"_"+fname) :) );
  if( sizeof(info) && mapp(info[0]) )
      convert_class(pname, fname);

  i = sizeof(deleted);
  while (i--) {
    reset_eval_cost();
    if ((idx = member_array(deleted[i], mesg_numbers)) > -1) {
      if (file_size(message_filename(mesg_numbers[idx], "l")) == -1) {
        convert_links(mesg_numbers[idx]);
      }
      if (!(tmp = unguarded((: read_file,
                 message_filename(mesg_numbers[idx], "l")
                             :)))) {
        mesg_numbers = delete(mesg_numbers, idx, 1);
        if (((class mail_header)info[idx])->status == "N")
          new_thingy--;
        info = delete(info, idx, 1);
        continue;
      }
      sscanf(tmp, "%d", link);
      if (link == 1) {
        unguarded((: rm, message_filename(mesg_numbers[idx], "") :));
        unguarded((: rm, message_filename(mesg_numbers[idx], "l") :));
      } else {
        link--;
        unguarded((: rm, message_filename(mesg_numbers[idx], "l") :));
        unguarded((: write_file,
                   message_filename(mesg_numbers[idx], "l"),""+link :));
      }
      mesg_numbers = delete(mesg_numbers, idx, 1);
      if (((class mail_header)info[idx])->status == "N") {
        new_thingy--;
      }
      info = delete(info, idx, 1);
    }
  }

  unguarded((: save_object, folder_filename(lower_case(pname)+"_"+fname) :));

} /* delete_it() */

private void send_notification( string to,
                                string from ) {
    object ob;

    if( ob = find_player(to) ) {
        event( ob, "inform", "You receive mail from "+CAP(from), "mail");
    }
} /* send_notification() */

/**
 * This method adds a message into all the correct folders and stuff.
 * This is the method that is called when a piece of mail is actually
 * sent.
 * @param mesg the message to send
 * @param flag if this is set to a non-zero value then no delivery messages will
 * occur
 * @see delete_it()
 */
void add_it( class mail_message mesg, int flag ) {
  object bing;
  int i, counter, bong, ptpost;
  string *local_to, *remote_to, *fail_to, str;
  class mail_header hdr;

  if( check() )
      return;

  if( sizeof(mesg->cc) )
      mesg->to += mesg->cc;

  mesg->to = MIME->get_email_addrs(implode(mesg->to, ","))[0];
  local_to = ({ });
  remote_to = ({ });
  fail_to = ({ });
  str = "";
  bong = sizeof(mesg->to);
  for (i = 0; i < bong; i++) {
    if ((str = check_local(mesg->to[i]))) {
      if (MAIL_TRACK->query_list(str)) {
        local_to += MAIL_TRACK->query_members(str) - ({ mesg->from });
        if ( str == "playtesters" ) {
          ptpost = 1;
        }
      } else {
        local_to += ({ str });
      }
    } else {
      remote_to += ({ mesg->to[i] });
    }
  }
  local_to = uniq_array(local_to);
  remote_to = uniq_array(remote_to);
  if ((i = sizeof(local_to))) {
    if (!(counter = load_counter())) {
      if (!flag) {
        printf("Aborting send of message...\n");
      }
      return;
    }
    if (file_size(message_filename(counter, "")) != -1 ||
        file_size(message_filename(counter, "l")) != -1) {
      if (!flag) {
        printf("Fatal error when sending message: File %d exists.\n"
               "Please contact Shaydz.\n", counter);
      }
      return;
    }
    for (i = 0; i < sizeof(local_to); i++) {
      if (!flag) {
        printf("Sending to: %s.\n", capitalize(local_to[i]));
      }
      if ((bing = (object)MAIL_TRACK->find_mailer(local_to[i]))) {
        mesg_numbers = ({ });
        info = ({ });
        new_thingy = 0;
#ifdef CONVERTER
        if (CONVERTER->query_busy(local_to[i])) {
          write("Sorry, busy converting mail for "+local_to[i]+".\n");
          mesg->to -= ({ local_to[i] });
          mesg->cc -= ({ local_to[i] });
          local_to = delete(local_to, i--, 1);
          continue;
        }
#endif
        unguarded((: restore_object, folder_filename(local_to[i]+"_inbox") :));
        if (sizeof(info) && mapp(info[0]))
          convert_class(local_to[i], "inbox");
        mesg_numbers += ({ counter });
        new_thingy++;
        hdr = new(class mail_header);
        hdr->number = counter;
        hdr->status = "N";
        hdr->subject = mesg->subject;
        hdr->from = mesg->from;
        info += ({ hdr });
        if (!unguarded((: save_object, folder_filename(local_to[i]+"_inbox") :))) {
          if (!flag) {
            printf("Couldn't save mailbox for %s...\n",
                   capitalize(local_to[i]));
          }
          mesg->to -= ({ local_to[i] });
          mesg->cc -= ({ local_to[i] });
          local_to = delete(local_to, i--, 1);
          continue;
        }
        else if (this_player() && environment(this_player())) {
           send_notification(local_to[i], mesg->from);
        }
      }
      else if( PLAYER_H->test_user( local_to[i] ) ) {
        mesg_numbers = ({ });
        info = ({ });
        new_thingy = 0;
#ifdef CONVERTER
        if (!flag) {
          if (file_size(folder_filename(local_to[i]+"_inbox.o")) == -1 &&
              file_size("/save/post/"+local_to[i]+".o") != -1) {
            convert_mail(local_to[i]);
            write("You cannot send mail to "+local_to[i]+" now.\n"+
                  "Try again later.\n");
            mesg->to -= ({ local_to[i] });
            mesg->cc -= ({ local_to[i] });
            local_to = delete(local_to, i--, 1);
            continue;
          } else if (CONVERTER->query_busy(local_to[i])) {
            write("Sorry, busy converting mail for "+local_to[i]+".\n");
            mesg->to -= ({ local_to[i] });
            mesg->cc -= ({ local_to[i] });
            local_to = delete(local_to, i--, 1);
            continue;
          }
        }
#endif
        unguarded((: restore_object, folder_filename(local_to[i]+"_inbox") :));
        if (sizeof(info) && mapp(info[0]))
          convert_class(local_to[i], "inbox");
        mesg_numbers += ({ counter });
        new_thingy++;
        hdr = new(class mail_header);
        hdr->number = counter;
        hdr->status = "N";
        hdr->subject = mesg->subject;
        hdr->from = mesg->from;
        info += ({ hdr });
        if (!unguarded((: save_object, folder_filename(local_to[i]+"_inbox") :))) {
          if (!flag) {
            printf("Couldn't save mailbox for %s...\n",
                   capitalize(local_to[i]));
          }
          mesg->to -= ({ local_to[i] });
          mesg->cc -= ({ local_to[i] });
          local_to = delete(local_to, i--, 1);
          continue;
        }
        send_notification(local_to[i], mesg->from);
      } else {
        fail_to += ({ local_to[i] });
        mesg->to -= ({ local_to[i] });
        mesg->cc -= ({ local_to[i] });
        local_to = delete(local_to, i--, 1);
      }
    }
    if (i) {
      ++counter;
      save_counter(counter);
      if (!unguarded((: write_file, message_filename(counter-1, ""),
                      mesg->body :)) && !flag)
        printf("*Failed to write message.  Maybe the filesystem is full?\n");
      if (!unguarded((: write_file, message_filename(counter-1, "l"), ""+i :)) &&
          !flag)
        printf("*Failed to write the message linkcount.  Maybe the filesystem "
               "is full?\n");
    }
  }
  if ((i = sizeof(fail_to))) {
    /* ohhhh...the recipient doesn't exist...make it bounce. */
    while (i--)
      MAILER->do_mail_message(mesg->from, "postmaster", "Error! User "+
                              fail_to[i]+" unknown", 0,
                              "Original message included:\n\n> "+
                              replace_string(mesg->body, "\n", "\n> "), 1, 0);
  }
  if (sizeof(remote_to) && !flag) {
    for (i = 0; i < sizeof(remote_to); i++) {
      sscanf(remote_to[i], "%*s@%s", str);
      if (str && INTERMUD_H -> mud_exists(str)) {
        printf("Sorry, Intermud mail is not currently supported.  "
               "Didn't send mail to %s.\n", remote_to[i]);
        remote_to = delete(remote_to, i--, 1);
        continue;
      }
    }
    SMTP->eventSendMail(remote_to, mesg->from, mesg->body);
  }
  if (ptpost) {
    BOARD_HAND->add_message("playtesters", capitalize(mesg->from),
                            "mailing to playtesters", mesg->body);
  }
} /* add_it() */

/**
 * This method marks the messages which are not in the unread array
 * in the specified folder as being read.
 * @param pname the player name
 * @param fname the folder name
 * @param unread the list of messages that are still unread
 */
void mark_read(string pname, string fname, int *unread) {
  int i;

  if( check() )
      return;

  if( !PLAYER_H->test_user(pname) )
      return;

  unread = uniq_array(unread);
  mesg_numbers = ({ });
  info = ({ });
  new_thingy = 0;
  unguarded((: restore_object, folder_filename(lower_case(pname)+"_"+fname) :));
  if (sizeof(info) && mapp(info[0])) {
    convert_class(pname, fname);
  }
  if (new_thingy == sizeof(unread)) {
    return;
  }
  new_thingy = 0;
  i = sizeof(mesg_numbers);
  while (i--) {
    if (member_array(i, unread) > -1) {
      ((class mail_header)info[i])->status = "N";
      new_thingy++;
    }
    else if(i < sizeof(info))
      ((class mail_header)info[i])->status = " ";
    else
      write("\nErk, problems. The arrays don't quite match.\n");
    reset_eval_cost();
  }
  unguarded((: save_object, folder_filename(lower_case(pname)+"_"+fname) :));
  new_thingy = 0;
} /* mark_read() */

/**
 * This method moves the specified message from one folder to another.
 * @param pname the player name
 * @param from the folder to move from
 * @param to the folder to move to
 * @param number the message number to move
 */
int move_it(string pname, string from, string to, int number) {
  int link;
  string tmp;
  class mail_header tmphdr;

  if (check())
    return 1;
  mesg_numbers = ({ });
  info = ({ });
  new_thingy = 0;
  unguarded((: restore_object, folder_filename(lower_case(pname)+"_"+to) :));
  if (sizeof(info) && mapp(info[0]))
    convert_class(pname, to);
  if (member_array(number, mesg_numbers) > -1)
    return 1;
  if (file_size(message_filename(number, "l")) == -1)
    convert_links(number);
  tmp = unguarded((: read_file, message_filename(number, "l") :));
  if (!tmp) {
    printf("Error moving message: File not found.\n");
    return 1;
  }
  sscanf(tmp, "%d", link);
  link++;
  unguarded((: rm, message_filename(number, "l") :));
  unguarded((: write_file, message_filename(number, "l"), ""+link :));
  mesg_numbers = ({ });
  info = ({ });
  new_thingy = 0;
  unguarded((: restore_object, folder_filename(lower_case(pname)+"_"+from) :));
  if (sizeof(info) && mapp(info[0]))
    convert_class(pname, from);
  tmphdr = info[member_array(number, mesg_numbers)];
  mesg_numbers = ({ });
  info = ({ });
  new_thingy = 0;
  unguarded((: restore_object, folder_filename(lower_case(pname)+"_"+to) :));
  mesg_numbers += ({ number });
  info += ({ tmphdr });
  if (tmphdr->status == "N")
    new_thingy++;
  unguarded((: save_object, folder_filename(lower_case(pname)+"_"+to) :));
  return 0;
} /* move_it() */

/**
 * This method checks to see if the specified players folder is empty.
 * @param pname the player name to check
 * @param fname the folder name to check
 */
int check_empty(string pname, string fname) {
  mesg_numbers = ({ });
  info = ({ });
  new_thingy = 0;
  unguarded((: restore_object, folder_filename(lower_case(pname)+"_"+fname) :));
  if (!sizeof(mesg_numbers)) {
    unguarded((: rm, folder_filename(lower_case(pname)+"_"+fname)+".o" :));
    return 1;
  }
  return 0;
} /* check_empty() */

/**
 * This method checks to see if the address is local.
 * @param str the address to check
 * @return local name for local messages, 0 for remote messages
 */
string check_local(string str) {
  string name;

  if (sscanf(lower_case(str),
             "%*([\n \t]*([ \t!-;=?-~]+<)?)%([A-Za-z]+)"
             "%*((.divided-sky(@|$))|$)",
             name) == 3) {
    return name;
  }
  return 0;
} /* check_local() */

/**
 * This method returns the nice string used when fingering a player to
 * determine their mail status.
 * @param pname the player name to finger
 * @return the string associated with the inbox of the player
 */
string finger_mail(string pname) {
  string ret;
  int num;

#ifdef CONVERTER
  if (file_size(folder_filename(pname+"_inbox.o")) == -1)
    convert_mail(pname);
#endif
  mesg_numbers = ({ });
  info = ({ });
  new_thingy = 0;
  unguarded((: restore_object, folder_filename(pname+"_inbox") :));

  if( sizeof(info) && mapp(info[0]) )
      convert_class(pname, "inbox");

  num = sizeof( mesg_numbers );

  if( !mesg_numbers || !num )
      return "No mail.\n";

  if( num == 1 )
      ret = "1 mail message";
  else
      ret = num + " mail messages";

  if( new_thingy <= 0 )
      ret += ".\n";
  else
      ret += ", "+new_thingy+" of them unread.\n";

  return ret;

} /* finger_mail() */

/**
 * This method is called when the player logs on to determine if they have
 * any new mail or not.
 * @param pname the players name to check
 */
string check_mail( string pname ) {
#ifdef CONVERTER
  if( file_size( folder_filename(pname+"_inbox.o") ) == -1 )
      convert_mail(pname);
#endif
  mesg_numbers = ({ });
  info = ({ });
  new_thingy = 0;

  unguarded( (: restore_object, folder_filename(pname+"_inbox") :) );

  if( sizeof(info) && mapp(info[0]) )
      convert_class( pname, "inbox");

  if( new_thingy > 0 )
      return "\nYou have %^YELLOW%^NEW%^RESET%^ mail.  Please use "
             "the 'mail' command to read it.\n\n";

  return "";

} /* check_mail() */

private void save_counter(int counter) {
  if( check() )
      return;

  unguarded( (: rm, MAIL_PATH+"counter.save" :) );
  unguarded( (: rename, MAIL_PATH+"counter", MAIL_PATH+"counter.save" :) );
  unguarded( (: write_file, MAIL_PATH+"counter", ""+counter :) );

} /* save_counter() */

private int load_counter() {
  string bing;
  int ret;

  if( check() )
      return 0;

  if( bing = unguarded( (: read_file, MAIL_PATH+"counter" :) ) ) {
      sscanf( bing, "%d", ret );
  } else {
      printf("The mail counter was lost.  Please contact a creator.\n");
      return 0;
  }

  return ret;

} /* load_counter() */

/**
 * This method sets the current message counter.  This will return a
 * message if the counter was not valid.  This should be called in the
 * event that a recovery is needed if the counter screws up.
 * @param x the new value for the counter
 */
void set_counter(int x) {
  if( file_size( message_filename( x, "") ) != -1 ||
      file_size( message_filename( x, "l") ) != -1 ) {
      printf("Invalid counter value: File exists.\n");
      return;
  }
  save_counter(x);
} /* set_counter() */

/** @ignore yes */
void dest_me() { destruct(TO); }

#ifdef CONVERTER
/** @ignore yes */
void convert_mail(string pname) {
  CONVERTER->convert_it(lower_case(pname));
} /* convert_mail() */
#endif

/**
 * This method converts the links.  Actually I have absolutely no idea
 * what this one does at all.
 * <p>
 */
private void convert_links(int number) {
  string message;
  int tmplink;

  if( ! ( message = unguarded( (: read_file,
      message_filename( number, ""), 1, 1 :) ) ) )
      return;

  sscanf( message, "%d", tmplink );
  message = unguarded( (: read_file, message_filename( number, ""), 2 :) );
  unguarded( (: rm, message_filename( number, "") :) );
  unguarded( (: write_file, message_filename( number, ""), message :) );
  unguarded( (: write_file, message_filename( number, "l"), ""+tmplink :) );

} /* convert_links() */

/**
 * This method totaly removes the account for a particular player.  This
 * will be called when a player is deleted for whatever reason.
 * @param pname the player name to delete
 */
void delete_account(string pname) {
  string tmp, folder, *folders;
  int message, lcount;
  object mailer;

   if( base_name(PO) != BULK_DELETE_H )
       return;

  mailer = clone_object(MAILER);
  folders = (string *)mailer->query_folders(pname);
  destruct(mailer);

  if( !folders && file_size(folder_filename(pname+"_inbox.o")) == -1 )
      return;

  if( !folders )
      folders = ({"inbox"});

  foreach( folder in folders ) {
      mesg_numbers = ({ });
      unguarded( (: restore_object, folder_filename(pname+"_"+folder) :) );
      if( pointerp( mesg_numbers ) ) {
          foreach( message in mesg_numbers ) {
            reset_eval_cost();
            if( file_size( message_filename( message, "l") ) == -1 )
                convert_links(message);

            tmp = unguarded( (: read_file, message_filename( message, "l") :) );

            if( !tmp )
                continue;

            sscanf( tmp, "%d", lcount );

            if( lcount != 1 ) {
                lcount--;
                unguarded( (: rm, message_filename( message, "l") :) );
                unguarded( (: write_file, message_filename( message, "l"), ""+ lcount :) );
            } else {
                unguarded( (: rm, message_filename( message, "") :) );
                unguarded( (: rm, message_filename( message, "") :) );
            }
          }
      }
      unguarded( (: rm, folder_filename( pname + "_"+folder + ".o") :) );
  }

  unguarded( (: rm, folder_filename( pname +".o") :) );

} /* delete_account() */
