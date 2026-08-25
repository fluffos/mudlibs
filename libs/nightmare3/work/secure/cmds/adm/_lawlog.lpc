/*    /cmds/admin/_lawlog.c
 *    from Nightmare IV
 *    a command for keeping track of law matters
 *    based on _changelog.c by Descartes of Borg
 *    by Gregon@Nightmare
 */
 
#include <std.h>
#include <dirs.h>
#include <objects.h>
#include <security.h>
 
#define LAWLOG "LawLog"
#define TMP_FILE DIR_TMP + "/" + (string)this_player()->query_name() + ".lawlog"
 
inherit DAEMON;
 
void post_change(mixed *args);
void abort();

int cmd_lawlog(string str) {
    string *tmp;
    string who;
    int i;
 
    if(!str) 
      return notify_fail("Correct syntax: lawlog [ha] player\n");
 
    if(!archp(this_player()))
      return notify_fail("No, no, no...arches only.\n");
 
    if(sscanf(str,"ha %s",who)==1) {
      if(member_group((string)this_player()->query_name(),"SECURE")) {
        message("system","Head arch option utilized.  Editing law file on "+
                         who+" in /log/law/adm",this_player());
        this_player()->edit(TMP_FILE, (:post_change:), (:abort:), 
                      ({lower_case(who), "/log/law/adm/"+lower_case(who)}));
        return 1;
      }
      else {
        message("system","Head arch option invalid.  Editing law file on "
                         +who+"in /log/law",this_player());
        this_player()->edit(TMP_FILE, (:post_change:),(:abort:), 
                           ({lower_case(who), "/log/law/"+lower_case(who) }) );
        return 1;
      }
    }
 
    message("system","Editing law file on "+str+" in /log/law",this_player());
    this_player()->edit(TMP_FILE, (:post_change:),(:abort:),
                   ({ lower_case(str), "/log/law/"+lower_case(str) }) );
    return 1;
}
 
void post_change(mixed *args) {
    string *tmp;
    string who, str, str2, filename;
    int i, maxi;
 
    who=args[0];
    filename=args[1];
    if(!userp(previous_object())) return;
    if(!(str = read_file(TMP_FILE)))
      return;
    str = replace_string(str, "\n", " ");
    maxi = sizeof(tmp = explode(wrap(str, 60), "\n"));
    str = "-  Log on "+capitalize(who)+"\n";
    str += "   "+ctime(time())+" by "
           +(string)previous_object()->query_CapName()+":\n";
    for(i=0; i<maxi; i++) str += "     * "+tmp[i]+"\n";
    if(str2 = read_file(filename)) str2 = str+"\n\n"+str2;
    else str2 = str;
    rm(filename);
    rm(TMP_FILE);
    write_file(filename, str2);
    message("system", "Writing file "+filename,this_player());
}
 
void help() {
    message("help","Syntax: lawlog [ha] player\n\nThis will place you in edit "
            "so that you can record law transgressions by or disciplinary "
            "action against a player.  Files will be written to /log/law "
            "unless the ha option is specified, in which case if you are a "
            "head arch, the output will be written to /log/law/adm (a dir "
            "read/writable only by those with superuser access.)", 
            this_player());
}
