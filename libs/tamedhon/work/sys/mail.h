// SilberLand MUDlib
//
// sys/mail.h -- Definitionen fuer die Post
//
// $Date: 1997/03/31 13:00:40 $
/* $Revision: 1.1 $
 * $Log: mail.h,v $
 * Revision 1.1  1997/03/31 13:00:40  Woody
 * prepared for revision control
 *
 * 3.2 1997/02/12 13:04:59 Wargon Exp
 *
 */

#ifndef __MAIL_H__
#define __MAIL_H__
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

#include "/mail/post.h"

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

#endif  // __MAIL_H__

