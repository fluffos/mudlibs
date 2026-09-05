/* Do not remove the headers from this file! see /USAGE for more info. */

#define MAX_IDLE_TIME	600     // This is really x+60 seconds.  LWI.
#define NEEDS_ARG()     if(!arg){ sesion->cmdPipe->send("500 Sintaxis incorrecta.\n"); return; }
#define FTPLOG(x)	log(LOG_FTP, x)

#define FTP_BLOCK_SIZE  1024

class sesion_FTP {
   int		connected;
   string	user;
   mixed	priv;
   string	pwd;
   object	dataPipe;
   object	cmdPipe;
   int		idleTime;
   int		binary;
   string	targetFile;
   string       command;
   int          filepos;
   string       renamefrom;
}

private void FTP_CMD_user(class sesion_FTP, string);
private void FTP_CMD_pass(class sesion_FTP, string);
private void FTP_CMD_retr(class sesion_FTP, string);
private void FTP_CMD_stor(class sesion_FTP, string);
private void FTP_CMD_nlst(class sesion_FTP, string);
private void FTP_CMD_list(class sesion_FTP, string);
private void FTP_CMD_pwd(class sesion_FTP, string);
private void FTP_CMD_cdup(class sesion_FTP, string);
private void FTP_CMD_cwd(class sesion_FTP, string);
private void FTP_CMD_quit(class sesion_FTP, string);
private void FTP_CMD_type(class sesion_FTP, string);
private void FTP_CMD_mkd(class sesion_FTP, string);
private void FTP_CMD_port(class sesion_FTP, string);
private void FTP_CMD_noop(class sesion_FTP, string);
private void FTP_CMD_dele(class sesion_FTP, string);
private void FTP_CMD_syst(class sesion_FTP, string);
private void FTP_CMD_pasv(class sesion_FTP, string);
string FTP_CMD_retr_callback(object);
