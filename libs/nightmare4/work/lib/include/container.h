#ifndef l_container_h
#define l_container_h

int CanReceive(object ob);
int CanRelease(object ob);

int eventReceiveObject();
int eventReleaseObject();

int GetAmbientLight();
nosave int SetAmbientLight(int x);
string GetInternalLong();
nosave string SetInternalLong(string str);
string GetInternalShort();
nosave string SetInternalShort(string str);
int GetOpacity();
nosave int SetOpacity(int x);
int GetRadiantLight(int ambient);

#endif /* l_container_h */
