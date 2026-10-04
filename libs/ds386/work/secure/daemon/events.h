#ifndef __EVENTS_H__
#define __EVENTS_H__

protected void create();
varargs protected int eventSave(int ung);
void eventReboot(int x);
protected void eventAnnounceReboot(int x);
void eventShutdown();
protected void Shutdown();
protected void eventPollEvents();

int SetRebootInterval(int x);
int GetRebootInterval();
void AddEvent(string c, string s, string f, mixed a, int w, int r);
mapping GetEvents();

#endif /* __EVENTS_H__ */
