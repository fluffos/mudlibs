#include "inven.h"
#include "desc.h"

create() {
   // short = "The Mail Daemon";
   name = "MailDaemon NULL";
   // long = "This is the Mail Daemon. Don't kill it, or bad things will happen.";
   // distant = "the Mail Daemon";
   // look = "This is Mail Daemon. If you don't know what it is, leave it alone.";
   // type = "daemon";
}

query_newmsgs(string whom) {
  object ob;
  int fun;
  int i;
  ob = clone_object("/obj/mailmsg");
  ob->set_folder_name(whom);
  ob->load_mail_folder(whom);

  for( i=0;i<ob->query_num_msgs();i++ ) {
     if( ob->query_im_flag(i) ) {
        msg( "~[150From: ~[140" + ob->query_sender(i) + " " + ctime(ob->query_mtime(i))  + "\n~[090" + ob->query_text(i) + "~[150End Message.~CDEF" );
        //msg( "From: " + ob->query_sender(i) );
        ob->set_im_flag( i, 0 );
        ob->set_read_flag( i, 1 );
        ob->save_mail_folder();
     }
  }

  fun = ob->query_newmsgs();
  destruct(ob);
  return fun;
}

/** Sends an instant message, which is also recorded as a normal message. The
 * message subject will be "Instant Message".
 */

mail_send_im( string to, string sender, string text ) {
   object ob;
   int mtime;
   ob = clone_object( "/obj/mailmsg" );
   ob->set_folder_name( to );
   ob->load_mail_folder( to );
   /*  Again, here is the bit where we get the date/time for the msg */
   mtime = time();
   //ob->add_mailmsg( "Instant Message", sender, text, to, mtime );
   ob->add_instantmsg( sender, text, to, mtime );

   if( find_player(to) ) {
      //ob->set_im_flag( ob->query_num_msgs() - 1, 0 );
      ob->set_read_flag( ob->query_num_msgs() - 1, 1 );
      msg_object( find_player(to), "~[150From: ~[140" + sender + "~[090\n" + text + "~[150End message.~CDEF" );
      //msg_object( find_player(to), "From: " + sender );
   } else {
      //msg( "Setting IM flag" );
      ob->set_im_flag( ob->query_num_msgs() - 1, 1 );
      //ob->set_read_flag( ob->query_num_msgs() - 1, 0 );
      /*if( ob->query_im_flag( ob->query_num_msgs() - 1 ) )
         msg( "IMFlag verify ok" );
      else
         msg( "IMFlag verify fail" );*/
   }

   ob->save_mail_folder();
   destruct( ob );

   if( find_player(to) ) {
      ob = present( "mail_rdr", find_player(to) );
      if( ob )
         ob->load_mail_folder(find_player(to)->query_name());
   }
}


mail_send(string to, string sender, string subject, string text) {
  object ob;
  int mtime;
  ob = clone_object("/obj/mailmsg");
  ob->set_folder_name(to);
  ob->load_mail_folder(to);
  /* This is the bit where the mail daemon calls the callender daemon,
  which has not been written yet, and gets the date/time, and assigns that
  value to 'mtime'. Thank you. Examp: mtime = get_date_time();*/
  //mtime = ({ "not implemented" });
  mtime = time();
  ob->add_mailmsg(subject, sender, text, to, mtime);
  ob->set_newmsgs();
  ob->save_mail_folder();
  if(find_player(to)) {
     //if( subject != "Instant Message" )
     if( !ob->query_im_flag(ob->query_num_msgs() - 1) )
        msg_object(find_player(to), "~[090You have mail.~CDEF");
  }
  destruct( ob );
  if( find_player(to) ) {
      ob = present( "mail_rdr", find_player(to) );
      if( ob )
         ob->load_mail_folder(find_player(to)->query_name());
  }
}

mail_remove(int i) {
  object ob;
  ob = clone_object("/obj/mailmsg");
  ob->set_folder_name(this_player()->query_name());
  ob->load_mail_folder(this_player()->query_name());
  ob->delete_mailmsg(i);
  ob->save_mail_folder();
  destruct(ob);
  if(this_player()) {
    ob = present("mail_rdr",this_player());
    if(ob) {
      ob->load_mail_folder(this_player()->query_name());
    }
  }
}

mail_purge_instants() {
   int c;

   object ob;
   ob = clone_object( "/obj/mailmsg" );
   ob->set_folder_name( this_player()->query_name() );
   ob->load_mail_folder( this_player()->query_name() );

   for( c=(ob->query_num_messages() - 1);c>-1;c-- ) {
      if( ob->query_subject(c) == "Instant Message" )
         ob->delete_mailmsg( c );
   }

   ob->save_mail_folder();
   destruct( ob );
   if( this_player() ) {
      ob = present( "mail_rdr", this_player() );
      if( ob ) {
         ob->load_mail_folder( this_player()->query_name() );
      }
   }
}

respond() {
  msg("The Mail Daemon is Loaded.");
  return 1;
}
