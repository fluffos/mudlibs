#ifndef __REGISTER_H
#define __REGISTER_H

#define REHASH_TIME     180

#define BANNED_ID_FILE          SYSTEM_CONFIG_DIR "banned_id"
#define BANNED_IP_FILE          SYSTEM_CONFIG_DIR "banned_ip"
#define REGISTED_IP_FILE        SYSTEM_CONFIG_DIR "registed_ip"
#define BANNED_NAME_FILE        SYSTEM_CONFIG_DIR "banned_name"

#define WORNING_TIME

int  CheckUserIp( string );
int  CheckUserId( string );
int  CheckUserName( string );
void RehashQuitedId();
void UserLogin( object );
void UserQuit( object );

nosave void create();

private int IsGuestId( string );
private int IsBannedId( string );
private int IsNewbieId( string );
private int IsQuitedId( string );
private int IsIllegalId( string );
private int IsOverLoad();
private int IsBannedIp( string );
private int IsRegistedIp( string );
private int IsLoginedIp( string );
private int IsIllegalId( string );
private int IsBannedName( string );
private int IsIllegalName( string );
string * read_config_file( string );

#endif /* __REGISTER_H */
