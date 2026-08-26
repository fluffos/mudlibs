#include <mailer.h>
#define NUKE_FILE    "/adm/etc/purged_characters"

mapping	my_groups;
mapping	*mailbox;


void nuke_mailboxes(string* names);

create(){
  mixed names;
  seteuid(getuid());
  if( file_exists( NUKE_FILE ) )
    catch(names = explode(read_file(NUKE_FILE),"\n"));
  if(names)
    nuke_mailboxes(names);
}

void nuke_mailboxes(string* names){
  int i,j;
  string mbox;

  i = sizeof(names);
  while(i--){
    reset_eval_cost();
    mbox = user_mbox_file(names[i]) + __SAVE_EXTENSION__;
    j = sizeof(mailbox);
    while(j--){
      MAILMESG_D->delete_mesg(mailbox[j]["idx"], names[i]);
      reset_eval_cost();
    }
    rm(mbox);
  }
  rm(NUKE_FILE);
}




