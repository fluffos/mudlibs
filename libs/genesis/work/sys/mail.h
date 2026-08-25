/*
 * /sys/mail.h
 *
 * This file contains some definitions used in the mail-system.
 */

#ifndef MAIL_DEFINED
#define MAIL_DEFINED

#ifndef FILES_DEFINED
#include "/sys/files.h"
#endif  FILES_DEFINED

/*
 * The format of the personal mail-files is as follows:
 * filename: /data/mail/{first-letter}/{playername}.o
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
 * filename: /data/messages/d{message-date % HASH_SIZE}/m{message-date}.o
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
 * MAIL_DIR   The directory in which the personal mail-files are stored.
 * MSG_DIR    The directory in which all message-files are stored.
 * ALIAS_DIR  The directory in which all aliases are stored.
 */
#define MAIL_DIR  "/data/mail/"
#define MSG_DIR   "/data/messages/"
#define ALIAS_DIR "/config/aliases/"

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

/*
 * CREATE_MAIL(subject, author, to, cc, body)
 *
 * This macro allows you to have mail messages generated and sent from code.
 * The arguments are as follows:
 *   subject - The subject of the note, maximum length of 35 characters
 *   author  - The lower case name of the alleged author of the note. Can
 *             be any name (string) of between 2 and 11 characters.
 *   to      - A comma-separated lower case string of names to receive the
 *             message.
 *   cc      - A comma-separated lower case string of names to receive a
 *             carbon copy of the message, or "" for no CC recipients.
 *   body    - The body text of the message. Lines should be separated with
 *             newlines, and a trailing newline is not necessary. The body
 *             text is automatically prepended with a line saying that this
 *             mail message is automatically generated.
 *
 * It is the responsibility of the author of the code to make sure that the
 * strings for 'to' and 'cc' only contain valid player names. Else, the mail
 * will not be sent.
 *
 * Misuse of this macro, by impersonating another person, or otherwise, be it
 * seriously or as joke will be punished by demotion, deletion or worse.
 *
 * Returns: 1 if the mail is succesfully sent.
 */
#define CREATE_MAIL(subject, author, to, cc, body) \
    (find_object("/secure/mail_reader")->create_mail((subject), \
     (author), (to), (cc), (body)))

#define MAIL_FROM     "from"     /* Index for sendername in message-array   */
#define MAIL_SUBJ     "subj"     /* Index for subject in message-array      */
#define MAIL_DATE     "date"     /* Index for date in message-array         */
#define MAIL_READ     "read"     /* Index for read message in message_array */
#define MAIL_LENGTH   "length"   /* Index for the length of the message     */
#define MAIL_REPLY    "reply"    /* Index for subj/reply in message_array   */

/* Binary encoding. */
#define MSG_UNREAD    0          /* Flag to indicate message was not read   */
#define MSG_READ      1          /* Flag to indicate message was read       */
#define MSG_ANSWERED  2          /* Flag to indicate message was answered   */
#define MSG_STARRED   4          /* Flag to indicate message was starred    */

#define TEXT_READ     "*R*"      /* Header list text for read messages      */
#define TEXT_STARRED  "-*-"      /* Header list text for starred messages   */
#define TEXT_UNREAD   "   "      /* Header list text for unread messages    */
#define TEXT_ANSWERED "*A*"      /* Header list text for answered messages  */
#define TEXT_DELETED  "*D*"      /* Header list text for deleted messages   */

#define MSG_IS_REPLY    1        /* Flag to indicate we are replying        */
#define MSG_IS_FORWARD  2        /* Flag to indicate we are fowarding mail  */
#define MSG_IS_RESEND   4        /* Flag to indicate we are resending mail  */
#define MSG_DO_EDIT     8        /* Flag to indicate we edit before sending */

#define SUBJECT_SHORT ({ "Subj", "Re", "Fwd", "Fwd" })
#define SUBJECT_LONG  ({ "Subject", "Reply", "Forward", "Forward" })

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

#define MAIL_FLAGS ({ "no mail", "already read mail", "NEW mail", "unread messages" })

#define MAX_CYCLE     15         /* Maximum number of mail sent in one loop */
#define READER_ID     "_reader_" /* Id for use with present()               */
#define MAX_NO_MREAD  "++"       /* You cannot read >100 lines without more */
#define MAX_SUBJECT   50         /* Maxmimum subject length                 */
#define GUEST_NAME    "guest"    /* The name of Guest                       */

#define MAKE_DATE(d)  ((ctime(d))[4..9])
#define DATE_YEAR(d)  ((ctime(d))[-4..])
#define MAKE_LONG_DATE(d) \
    ((ctime(d))[4..9] + (ctime(d))[19..23])
#define READER_HELP   "/doc/help/general/mail_"
#define FILE_NAME_MAIL(n) \
    (MAIL_DIR + ((n))[0..0] + "/" + (n))
#define FILE_NAME_MESSAGE(t, h) \
    (MSG_DIR + "d" + ((t) % (h)) + "/m" + (t))

/*
 * Definitions related to export of mail to the web portal.
 */
#define WEB_MAIL_DIR  "/d/Web/content/mail/"
#define WEB_MAIL_PRE  "mail-"
#define WEB_MAIL_POST ".txt"
#define WEB_MAIL_LEN  10
#define WEB_MAIL_ROOT "www.genesismud.org/mail/"
#define WEB_MAIL_TIME 30 /* Minutes the URL remains active. */
#define WEB_MAIL_LOG  "WEB_MAIL"

/*
 * MAIL_ARCHIVE_DIR  The directory in the wizards home directory in which
 *     archived messages are stored.
 */
#define MAIL_ARCHIVE_DIR "mail_archive"

/*
 * NON_DOMAINS
 *
 * It is impossible to send mail to these domains as a whole as they are not
 * 'normal' domains.
 */
#define NON_DOMAINS ( ({ "genesis", "wiz", "debug" }) )

/*
 * HASH_SIZE
 *
 * The number of directories over which we hash all mail files.
 */
#define HASH_SIZE (100)

/*
 * WARNING_TOO_MUCH_IN_BOX
 *
 * This is the maximum number of messages before the limit people are supposed
 * to have in their box before a warning by Postmaster is issued. This does
 * not remove messages. Undefine this if you don't want a warning.
 */
#define WARNING_TOO_MUCH_IN_BOX (25)

/* 
 * MAX_IN_MORTAL_BOX
 * EXTRA_IN_GUILD_BOX
 *
 * Mortals are restricticted to a maximum numbers they can have in their
 * box. Only read messages are count in this sense. If they exceed the limit,
 * messages are removed when they exit mail reader functionality. Players
 * performing a special role in a guild can have a large maximum. Undefine
 * this if you don't want a maximum. 
 */
#define MAX_IN_MORTAL_BOX  (250)
#define EXTRA_IN_GUILD_BOX (150)

/*
 * MAX_ALIASES
 *
 * The maximum number of personal aliases people can have in thier mail
 * folder.
 */
#define MAX_ALIASES (15)

/* Do not add any definitions beyond this line. */
#endif MAIL_DEFINED
