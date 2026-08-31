#ifndef __ACT_H__
#define __ACT_H__

public int act(string action, float delay, mixed *cb);
public async int async_act(string action, float delay);
public mixed find_act(mixed id);          // Returns class Act, but cannot specify in a header file
public varargs mixed pop_act(mixed id);   // Returns class Act, but cannot specify in a header file
public void finish_act(string uuid);
public void cancel_acts();
public int cancel_act(mixed action);
public mapping query_acts();
public varargs int is_acting(string action);

#endif // __ACT_H__
