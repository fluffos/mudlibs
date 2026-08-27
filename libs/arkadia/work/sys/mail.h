/*
 * /sys/mail.h
 *
 * This file contains some definitions used in the mail-system.
 */

#ifndef MAIL_DEFINED
#define MAIL_DEFINED

#include "/config/sys/mail2.h"

/*
 * The format of the personal mail-files is as follows:
 * filename: /players/mail/{first-letter}/{playername}.o
 *
 * (mixed)   player_mail
 *              ({ ([ "from"  : (string)  message_from,
 *                    "subj"  : (string)  message_subject,
 *                    "date"  : (int)     message_date == time(),
 *                    "read"  : (int)     message_read,
 *                    "length": (string)  message_length,
 *                    "reply" : (int)     message_is_reply
 *                 ]),  ....
 *              })
 *
 * (mapping) player_aliasses
 *              ([ "alias" : ({ alias_names }), ...
 *              ])
 *
 * (int)     player_new_mail
 * (int)     player_automatic_cc
 *
 * Using the efuns restore_map() and save_map(), we can save the players
 * message file as it were a mapping:
 *
 * ([ "mail"     : (mixed)   player_mail,
 *    "aliases"  : (mapping) player_aliasses,
 *    "new_mail" : (int)     player_new_mail,
 *    "autocc"   : (int)     player_automatic_cc
 * ])
 *
 * The message-files are formatted like:
 * filename: /players/messages/d{message-date % HASH_SIZE}/m{message-date}.o
 * In this, the directories are named d0 - d[HASH_SIZE-1].
 *
 * ([ "to"       : (string)  message_to,
 *    "cc"       : (string)  message_cc,
 *    "address"  : (string)  message_addressees,
 *    "body"     : (string)  message_body
 * ])
 *
 * Alias_names, message_to, message_cc and message_addressees are a
 * single string with the (player-)names, separated by commas.
 * The names in message_from, message_to and message_cc and
 * message_addressees are capitalized, where player_aliases is in
 * lower case.
 */

/*
 * IS_MAIL_ALIAS(a)
 *
 * This returns true if a global mail alias with the name 'a' exists and
 * false if no such global alias exists.
 */
#define IS_MAIL_ALIAS(a)     (file_size(ALIAS_DIR + (a)) > 0)

/*
 * EXPAND_MAIL_ALIAS(a)
 *
 * This returns an array of all player-names (in lower case) that are
 * in the global mail alias 'a'. Notice that you _must_ check whether the
 * alias exists before you use this alias. You can use IS_MAIL_ALIAS(a)
 * for that. If you use this macro and the alias does not exist, you are
 * bound to get a runtime error.
 */
#define EXPAND_MAIL_ALIAS(a) (explode(read_file(ALIAS_DIR + (a)), "\n"))

#define MAIL_FROM     "from"     /* Index for sendername in message-array   */
#define MAIL_FROMDOP  "fromdop"	 /* Index for sendername's dopelniacz	    */
#define MAIL_SUBJ     "subj"     /* Index for subject in message-array      */
#define MAIL_DATE     "date"     /* Index for date in message-array         */
#define MAIL_READ     "read"     /* Index for read message in message_array */
#define MAIL_LENGTH   "length"   /* Index for the length of the message     */
#define MAIL_REPLY    "reply"    /* Index for subj/reply in message_array   */

#define MSG_UNREAD    0          /* Flag to indicate message was not read   */
#define MSG_READ      1          /* Flag to indicate message was read       */
#define MSG_ANSWERED  2          /* Flag to indicate message was answered   */

#define TEXT_READ     "*R*"      /* Header list text for read messages      */
#define TEXT_UNREAD   "   "      /* Header list text for unread messages    */
#define TEXT_ANSWERED "*A*"      /* Header list text for answered messages  */
#define TEXT_DELETED  "*D*"      /* Header list text for deleted messages   */
#define TEXT_ARRAY    ({ TEXT_UNREAD, TEXT_READ, TEXT_ANSWERED })

#define MAIL_MAIL     "mail"     /* Index for messages in mail-save-file    */
#define MAIL_ALIASES  "aliases"  /* Index for aliases in mail-save-file     */
#define MAIL_NEW_MAIL "new_mail" /* Index for new mail flag mail-save-file  */
#define MAIL_AUTO_CC  "auto_cc"  /* Index for autocc flag in mail-save-file */
#define M_SIZEOF_MAIL 4          /* The number of indiced in the mail-file  */

#define MSG_TO        "to"       /* Index for to in message-file            */
#define MSG_CC        "cc"       /* Index for cc in message-file            */
#define MSG_ADDRESS   "address"  /* Index for addressees in message-file    */
#define MSG_BODY      "body"     /* Index for message body in message-file  */
#define M_SIZEOF_MSG  4          /* The number of indices in the msg-file   */

#define FLAG_NO       0          /* Flag to indicate you have no mail       */
#define FLAG_READ     1          /* Flag to indicate you read all your mail */
#define FLAG_NEW      2          /* Flag to indicate that there is new mail */
#define FLAG_UNREAD   3          /* Flag to indicate you have unread mail   */

#define MAIL_FLAGS ({ "no mail", "mail, but all read", "NEW mail", \
    "unread mail, but no new mail" })

#define MAX_CYCLE     15         /* Maximum number of mail sent in one loop */
#define READER_ID     "_reader_" /* Id for use with present()               */
#define MAX_NO_MREAD  "++"       /* You cannot read >100 lines without more */
#define MAX_SUBJECT   50         /* Maxmimum subject length                 */
#define GUEST_NAME    "gosc"     /* The name of Guest                       */

#define MAKE_DATE(d)  (extract(ctime(d), 4, 10))
#define DATE_YEAR(d)  (extract(ctime(d), 12, 15))
#define MAKE_LONG_DATE(d)  (extract(ctime(d, 1), 3, -11))
#define READER_HELP   "/doc/help/general/mail_"
#define FILE_NAME_MAIL(n) \
    (MAIL_DIR + extract((n), 0, 0) + "/" + (n))
#define FILE_NAME_MESSAGE(t, h) \
    (MSG_DIR + "d" + ((t) % (h)) + "/m" + (t))

/* Do not add any definitions beyond this line. */
#endif MAIL_DEFINED
