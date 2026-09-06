#ifndef _MAIL_
#define _MAIL_
/*
 *------------------------------------------------------------
 * Definitions of fields used in mail messages
 *------------------------------------------------------------
 *
 *	A message is represented as an array with the following fields:
 */
#define MSG_FROM 0
#define MSG_SENDER 1
#define MSG_RECIPIENT 2
#define MSG_CC 3
#define MSG_BCC 4
#define MSG_SUBJECT 5
#define MSG_DATE 6
#define MSG_ID 7
#define MSG_BODY 8
#define MSG_STATUS 9

#define MSG_STATUS_NEW 0
#define MSG_STATUS_READ 1
#define MSG_STATUS_ANSWERED 2

#define MAILER "/mail/mailer"
/*
 *	DeliverMail(mixed *message)
 *	  Hand a mail message over to the mailer demon. The mailer
 *	  demon extracts recipients from the recipient, cc and bcc
 *	  fields and removes the bcc information. It then deposits
 *	  the message to the mail files of all recipients. A valid
 *	  message is shown above.
 *
 *	int FingerMail(string user)
 *	  Gives the number of unread messages a user has.
 */
#endif


