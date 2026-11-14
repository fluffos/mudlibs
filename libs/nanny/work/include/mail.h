#define FLAG 0
#define FROM 1
#define SUBJ 2
#define TIME 3
#define CC   4
#define MESS 5

#define DATE		ctime(time())[0..15]
#define CHAR_SAVE(x)	"/players/" + x + ".o"
#define MAILD           "/obj/daemon/maild"
#define MAILDIR		"/mail/newmail"
#define MBOX_NEW	"new"
#define MBOX_DEF	"mbox"
#define SCREEN_LENGTH	20
#define MAILSAVE(x)	"mail/newmail/" + x
#define MAIL_ALIAS_FILE "/etc/aliases"
#define TMP_ED_FILE(x)	"/tmp/" + x
#define WIZ_DIR(y)	"/players/" +this_player()->query_real_name()+ "/" +y
#define WIZ_LEVEL	20
