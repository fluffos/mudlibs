#ifndef THING_MOVING_D
#define THING_MOVING_D 1

public object *AddFollower (object f);
public object *RemoveFollower (object f);
public varargs int move (mixed dest, int method, mixed extra);
public void follow (mixed dest, int method, mixed extra);
public int clean_up (int ref);

#endif
