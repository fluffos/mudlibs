#ifndef l_bait_h
#define l_bait_h

protected void create();

mixed indirect_bait_obj_with_obj();

int SetBaitStrength(int x);
int GetBaitStrength();

mixed eventBait(object who, object pole);

/* virtual functions */

protected mixed AddSave(mixed *vars);
string GetShort();
int eventDestruct();

#endif
