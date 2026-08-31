// User Authentication Protocols
//  Created by Nightshade, Modded by Whit

#include <socket.h>
#include <network.h>
#include <daemons.h>
#include <security.h>
#define SMTP_IP "217.160.230.51"
//#define SMTP_IP "127.0.0.1"

mapping mail;

void create() {
   mail=([]);
}

void send_mail(string from, string to, string subject, string body) { 
   int error, s; 
   if(geteuid(previous_object()) != "Mail") {
     CHAT_D->do_raw_chat("system", "Mail <system> Permission denied "
        "to send_mail() from "+identify(previous_object()));
     return;
   }
   s = socket_create(STREAM, "read_callback"); 
   if( s < 0 ) { 
       CHAT_D->do_raw_chat("system", " <email> "+socket_error(s)); 
       return; 
   } 
   error = socket_bind(s, 0); 
   if (error != EESUCCESS) { 
       CHAT_D->do_raw_chat("system", " <email> ("+error+") socket " 
         "bind failed: "+socket_error(s)); 
       socket_close(s); 
       return; 
   } 
   error = socket_connect(s, SMTP_IP+" 25", "read_callback", "write_callback"); 
   if (error != EESUCCESS) { 
       CHAT_D->do_raw_chat("system", " <email> ("+error+") socket " 
         "connect failed: "+socket_error(s)); 
       socket_close(s); 
       return; 
   } 
   mail[s]=(["to":to, "from":from, "subject":subject, "body":body ]);
} 

void read_callback(int fd, mixed message) { 
   string crlf = "  "; 
   int s = fd;
   crlf[0] = 13;
   crlf[1] = 10; 
   CHAT_D->do_raw_chat("system", "Mail <system> ");
   if(!mail[fd]) {
     CHAT_D->do_raw_chat("system", "Mail <system> Invalid mail information.");
     socket_close(fd);
     return;
   }
   if(message[0..2] == "220") { 
       message("","1", users());
       socket_write(s, "helo primaldarkness.com"+crlf);
   } else
   if(message[0..5] == "250 mr") { 
       socket_write(s, "mail from: "+mail[fd]["from"]+crlf+""); 
   } else
   if(message[0..13] == "250 mail from:") { 
       socket_write(s, "rcpt to: "+mail[fd]["to"]+crlf+""); 
   } else
   if(message[0..4] == "250 <") { 
       socket_write(s, "data"+crlf+""); 
   } else
   if(message[0..2] == "354") {
       socket_write(s, 
"from: "+mail[fd]["from"]+crlf+
"to: "+mail[fd]["to"]+crlf+
"subject: "+mail[fd]["subject"]+crlf+crlf+mail[fd]["body"]+crlf+crlf+"."+crlf); 
   } else
   if(message[0..2] == "550") {
     CHAT_D->do_raw_chat("system", "Mail <system> Mailer returned a bad domain error for "+mail[fd]["to"]);
   } else
   if(message[0..2] == "501") {
     CHAT_D->do_raw_chat("system", "Mail <system> Mailer returned a bad syntax error for "+mail[fd]["to"]);
   } else
   if(message[0..10] == "250 Message") { 
       socket_write(s, "QUIT"+crlf+""); 
   } else
   if(message[0..2] == "221") {
     CHAT_D->do_raw_chat("system", "Mail <system> Link closed to smpt server");
     socket_close(fd);
     map_delete(mail, fd);
   } else 
   if(message[0..2] == "421") {
     CHAT_D->do_raw_chat("system", "Mail <system> Mail connection timed out");
     socket_close(fd);
     map_delete(mail, fd);
   } else {
      CHAT_D->do_raw_chat("system", "Mail <system> Mailer returned an unknown error of "+message+"");
      CHAT_D->do_raw_chat("system", "Mail <system> Trying to close link gently");
      socket_write(s, "QUIT"+crlf);
   }
} 


