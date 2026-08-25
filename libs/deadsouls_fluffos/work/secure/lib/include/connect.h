#ifndef l_connect_h
#define l_connect_h

protected void create(int binary);
varargs protected void logon(mixed foo);
protected void InputName(string name, string kill_me);
protected void InputPassword(string pass, string cap);
protected void eventCreatePlayer(string cap);
protected void ConfirmName(string ans, string cap);
protected void eventReEnterGame(string cap);
protected void ConfirmReconnect(string ans, string cap);
protected int CanLogin();
private void eventEnterGame();
protected void CreatePassword(string pass, string cap);
protected void ConfirmPassword(string control, string cap, string pass);
protected void InputGender(string str, string cap);
protected void InputCapName(string name, string cap);
protected void InputEmail(string email);
protected void InputRealName(string rname);
protected void InputRace(string str);
protected void cmdHelp(string str);
protected void cmdList();
protected void cmdPick(string args);
protected void eventTimeout();
varargs int eventPrint(string msg, mixed arg2, mixed arg3);
private void Destruct();
void eventDestruct();
string GetKeyName();
string GetCapName();
protected void terminal_type(string str);
protected void window_size(int width, int height);
protected void CreateGuest();
protected void GetGuestName(string nom);
int *GetScreen();
void SetLastError(mapping m);
mapping GetLastError();

#endif /* l_connect_h */
