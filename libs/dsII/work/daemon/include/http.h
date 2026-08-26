#ifndef __HTTP_H__
#define __HTTP_H__

nosave void create();
nosave void Setup();
nosave void eventRead(int fd, string str);
private nosave void eventGetFile(int fd, string file);

#endif /* __HTTP_H__ */
