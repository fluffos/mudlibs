#ifndef l_passwd_h
#define l_passwd_h

mixed cmd(string args);
nosave void OldPass(string pass, object who);
nosave void NewPass(string pass, mixed who);
nosave void ConfirmPass(string str, mixed who, string newpass);
string GetHelp(string str);

#endif /* l_passwd_h */
