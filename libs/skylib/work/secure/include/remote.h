#ifndef __REMOTE_H__
#define __REMOTE_H__

void create();
void Setup();

void eventRead(int fd, string str);
void eventProcess(int fd, string str);

#endif /* __REMOTE_H__ */
