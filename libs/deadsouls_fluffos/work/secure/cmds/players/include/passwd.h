#ifndef l_passwd_h
#define l_passwd_h

mixed cmd(string args);
protected void OldPass(string pass, object who);
protected void NewPass(string pass, mixed who);
protected void ConfirmPass(string str, mixed who, string newpass);
string GetHelp(string str);

#endif /* l_passwd_h */
