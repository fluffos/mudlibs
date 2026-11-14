#ifndef HULL_MOVING_D
#define HULL_MOVING_D 1

public int QueryTPort ();
public int PreventLeave(mixed dest, int method, mixed extra);
public int AllowEnter(int method, mixed extra);
public void NotifyLeave(mixed to, int method, mixed extra);
public void NotifyEnter(mixed from, int method, mixed extra);
public int clean_up (int ref);
public void create ();

#endif
