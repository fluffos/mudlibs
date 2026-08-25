#ifndef l_post_office_h
#define l_post_office_h

protected void create();
mixed CanMail(object who, string args);
mixed eventMail(object who, string args);
int CanReceive(object ob);
int eventReleaseObject();

#endif /* l_post_office_h */
