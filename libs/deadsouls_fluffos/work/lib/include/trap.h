#ifndef l_trap_h
#define l_trap_h

protected void create();
protected void heart_beat();

mixed CanCapture(object who, object target);
mixed CanFree(object who, object target);

mixed eventCapture(object who, object target);
mixed eventEscape();
mixed eventFree(object who, string target);

object* GetCaptives();
int GetEscapeChance();
int SetEscapeChance(int x);
int GetMaxCapture();
int SetMaxCapture(int x);

#endif /* l_trap_h */
