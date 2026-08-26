
inherit COMMAND_BASE;

#define UNIX_FTPD "/secure/handlers/ftp_auth"

mixed cmd(string) {
  mixed *who, *who_unix;
  int i;

  who = FTP_H->query_connections();
  if ((i = sizeof(who))) {
    write("People currently using MUD FTP :\n");
    while (i--)
      write(" - "+who[i]+"\n");
  } else {
    write("Noone is using MUD FTP at the moment.\n");
  }
  who_unix = UNIX_FTPD->query_connections();
  if ((i = sizeof(who_unix))) {
    write("People currently using UNIX FTP :\n");
    while (i--)
      write(" - "+who_unix[i]+"\n");
  } else {
    write("Noone is using UNIX FTP at the moment.\n");
  }
  return 1;
}
