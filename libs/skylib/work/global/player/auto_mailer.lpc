
/**
 * Allows objects to send mail as if they were from the given player.
 */
#include <mail.h>

/**
 * Allows people to send mail automaticly from the player in question.
 * Thus allows mail to be sent on someone being promoted to creator
 * and stuff.
 * @param to who the mail is to
 * @param from who the mail is from
 * @param cc the people to carbon copy
 * @param body the body of the message
 * @param send_inter should be send it ove the inter mud system?
 * @param only_to ignore the cc fields
 */
void auto_mail(string to, string from, string sub, string cc, string body, 
               int send_inter, string only_to) {
  if ((from != this_player()->query_name()) &&
      "/secure/login"->test_player(from)) {
    write("AUTO_MAILER: Illegal access!\n");
    unguarded((: write_file, "/log/CHEAT", "Illegal access to AUTO_MAILER.\n"
               "Backtrace: "+ back_trace() :));
    return;
  }
  MAILER->do_mail_message(to, from, sub, cc, body, send_inter, only_to);
} /* auto_mail() */
