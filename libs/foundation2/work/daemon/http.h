#ifndef __HTTP_H__
#define __HTTP_H__

protected void create();
void Setup();
protected void eventRead(int fd, string str);
private void eventGetFile(int fd, string file);

#endif /* __HTTP_H__ */
