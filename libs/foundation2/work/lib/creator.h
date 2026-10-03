#ifndef __CREATOR_H__
#define __CREATOR_H__

protected void create();
protected void net_dead();
void restart_heart();

int eventForce(string cmd);
void eventDescribeEnvironment(int verbose);

int CanCarry(int amount);

int Setup();

int GetCreatorAge();
string SetGender(string gender);
string GetGender();
int GetCreatorBirth();

#endif /* __CREATOR_H__ */
