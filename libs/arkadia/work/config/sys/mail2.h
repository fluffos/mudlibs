/*
 * /config/sys/mail2.h
 *
 * This is the mud-specific part of the mail.h file. It should be included
 * by /sys/mail.h.
 */

/*
 * MAIL_DIR   The directory in which the personal mail-files are stored.
 * MSG_DIR    The directory in which all message-files are stored.
 * ALIAS_DIR  The directory in which all aliases are stored.
 *
 * When DEBUG has been defined (in the object including mail.h), other
 * directories are used in order not to test with the real mail directories.
 */
#ifdef DEBUG
#define MAIL_DIR  "/players/tmp_mail/"
#define MSG_DIR   "/players/tmp_messages/"
#else
#define MAIL_DIR  "/players/mail/"
#define MSG_DIR   "/players/messages/"
#endif DEBUG

#define ALIAS_DIR "/config/aliases/"

/*
 * NON_DOMAINS
 *
 * It is impossible to send mail to these domains as a whole as they are not
 * 'normal' domains.
 */
#define NON_DOMAINS ( ({ "arkadia", "wiz", "debug" }) )

/*
 * HASH_SIZE
 *
 * The number of directories over which we hash all mail files.
 */
#define HASH_SIZE (30)

/*
 * WARNING_TOO_MUCH_IN_BOX
 *
 * This is the maximum number of messages people are supposed to have in
 * their box before a warning by Postmaster is issued. This does not remove
 * messages. Undefine this if you don't want a warning.
 */
#define WARNING_TOO_MUCH_IN_BOX (50)

/* 
 * MAX_IN_MORTAL_BOX
 *
 * Mortals are restricticted to a maximum numbers they can have in their
 * box. Only read messages are count in this sense. If they exceed the limit,
 * messages are removed when they exit mail reader functionality. Undefine
 * this if you don't want a maximum.
 */
#define MAX_IN_MORTAL_BOX (50)

/*
 * MAX_ALIASES
 *
 * The maximum number of personal aliases people can have in thier mail
 * folder.
 */
#define MAX_ALIASES (15)
