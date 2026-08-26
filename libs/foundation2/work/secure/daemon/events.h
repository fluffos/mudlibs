#ifndef __EVENTS_H__
#define __EVENTS_H__

nosave void create();
varargs nosave int eventSave(int ung);
void eventReboot(int x);
nosave void eventAnnounceReboot(int x);
void eventShutdown();
nosave void eventPollEvents();

int SetRebootInterval(int x);
int GetRebootInterval();
void AddEvent(string c, string s, string f, mixed a, int w, int r);
mapping GetEvents();

#endif /* __EVENTS_H__ */
