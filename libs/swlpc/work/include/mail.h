/*
 * mail daemon header file
 *
 * Hunter of Shattered Worlds
 */

#define MAIL_DIR "room/post_dir/"
#define DELIMITER "***\n"
#define ALIASES "std/mail.alias"

#define MDAEMON		"std/mail_daemon"

#define	EDMODE (in_editor(this_player()))
#define EDFILE ("open/mail/"+this_player()->query_real_name()+".ed")

#define FROM	0
#undef DATE
#define DATE	1
#define SUBJECT	2
#define TO	3
#define CC	4
#define STATUS  5	
#define NUMHEADERS	STATUS + 1

#define BLANKHEADER "From: \nDate: \nSubject: \nTo: \nCc: \nStatus: \n"

#define STATUS_READ	"Read"
#define STATUS_UNREAD	"Unread"
#define STATUS_DELETED	"Deleted"

