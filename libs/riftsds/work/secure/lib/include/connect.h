#ifndef l_connect_h
#define l_connect_h

nosave void create(int binary);
varargs nosave void logon(mixed foo);
nosave void InputName(string name, string kill_me);
nosave void InputPassword(string pass, string cap);
nosave void eventCreatePlayer(string cap);
nosave void ConfirmName(string ans, string cap);
nosave void eventReEnterGame(string cap);
nosave void ConfirmReconnect(string ans, string cap);
nosave int CanLogin();
nosave private void eventEnterGame();
nosave void CreatePassword(string pass, string cap);
nosave void ConfirmPassword(string control, string cap, string pass);
nosave void InputGender(string str, string cap);
nosave void InputCapName(string name, string cap);
nosave void InputEmail(string email);
nosave void InputRealName(string rname);
nosave void InputRace(string str);
nosave void cmdHelp(string str);
nosave void cmdList();
nosave void cmdPick(string args);
nosave void eventTimeout();
varargs int eventPrint(string msg, mixed arg2, mixed arg3);
nosave private void Destruct();
void eventDestruct();
string GetKeyName();
string GetCapName();
nosave void terminal_type(string str);
nosave void window_size(int width, int height);
nosave void CreateGuest();
nosave void GetGuestName(string nom);
int *GetScreen();
void SetLastError(mapping m);
mapping GetLastError();

#endif /* l_connect_h */
