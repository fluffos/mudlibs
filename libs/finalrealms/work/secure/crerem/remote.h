
#ifndef __REMOTE_H__
#define __REMOTE_H__

nosave void create();
nosave void Setup();

nosave void eventRead(int fd, string str);
nosave void eventProcess(int fd, string str);

#endif /* __REMOTE_H__ */

