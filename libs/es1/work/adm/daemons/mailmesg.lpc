#pragma save_binary

#define MONITOR_TIME 5000
#define WHO find_living( "asdfral" )
#define TELL(x) if(WHO) message( "debug", "MSG: " + x+ "\n", WHO );


#include <uid.h>
#include <mailer.h>
#include <net/macros.h>
#include <config.h>
protected void monitor_mesgs();

string  *remain;
string  mesg;
nosave  int idx1, idx2;


protected
void increment_idx() {
   if( ++idx1 > 9 ) idx1 = 0;
   if( ++idx2 > 9 ) idx2 = 0;
}

protected
void refresh() {
  mesg = 0;
  remain = ({ });
}

protected
int restore_mesg( int id ) {
  string file;

  refresh();
  file = mail_mesg_file( id );
  if( !file_exists( file + SAVE_EXTENSION ) ) return 0;
  return restore_object( file );
}

int save_mesg( int id ) {
  int ret;
  string file;

  if( !id ) return 0;
  if( file = mail_mesg_file( id ) ) {
    if( !sizeof( remain ) )
       rm( file + SAVE_EXTENSION );
    else
       ret = save_object( file );
  }
  return ret;
}

int
valid_access( string frm ) {
   string accessor, *owner;

   if( geteuid( previous_object() ) == ROOT_UID )
      return 1;

   accessor = base_name( previous_object() );
   if( member_array( accessor, TRUSTED_MAILERS ) > -1 )
      return 1;

} // valid_access



string
get_mesg( int id ) {
   if( !restore_mesg( id ) )
     printf( "Unable to restore %d.\n", id );
   if( !mesg || mesg == "" ) mesg = "Empty or lost message!\n";
   return mesg;
}


int add_mesg( string *local_to, string msg ) {
   int idx;

   refresh();
   idx = time();

   // We have to have a unique savefile, or else we have problems later.
   while( file_exists( mail_mesg_file( idx ) + SAVE_EXTENSION ) )
      --idx;

   remain = uniq_array( local_to );
   mesg = msg;
   save_mesg( idx );
   return idx;
}


int
delete_mesg( int id, string user ) {
   refresh();

   if( !restore_mesg( id ) ) return 0;
   if( !stringp( user ) || !strlen( user ) ) return -1;

   if( member_array( user, remain ) < 0 ) return -2;
   remain -= ({ user });
   save_mesg( id );
   return 1;
}

void
create() {
   seteuid( ROOT_UID );
   idx1 = 0;
   idx2 = 0;
   call_out( "monitor_mesgs", 100 );
   refresh();
} // create

protected
void monitor_mesgs() {
   int i;
   string *mesgs;

   increment_idx();
   mesgs = get_dir( MESGDIR + idx1 + "/" + idx2 + "/*" SAVE_EXTENSION );
   i = sizeof( mesgs );

TELL( "idx1: " + idx1 + ", idx2: " + idx2 + ", size: " + i );
   while( i-- ) {
      sscanf( mesgs[i], "%s" SAVE_EXTENSION, mesgs[i] );
      call_out( "monitor_mesg2", 5 + (10*i), mesgs[i] );
   }

   call_out( "monitor_mesgs", MONITOR_TIME );
   return;
}

protected
void monitor_mesg2( string mesg ) {
   int i, j, id;
   string *tmp, *tmp2;

   tmp = ({ });
   tmp2 = ({ });
TELL( "Verify: " + mesg );
   restore_mesg( id = to_int( mesg ) );
   remain = uniq_array( remain );
   tmp =  MAILBOX_D -> verify_mbox( copy( remain ), id );

   j = sizeof( tmp );
   while( j-- )
      if( user_exists( tmp[j] ) ) tmp2 += ({ tmp[j] });

   if( sizeof( remain ) == sizeof( tmp2 ) ) return;
   remain = tmp2;
   save_mesg( id );
}

/* EOF */
