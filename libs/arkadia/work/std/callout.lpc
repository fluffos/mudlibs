#pragma save_binary
#pragma strict_types

/*
 * Function name: find_call_out
 * Description:   Locate an existing call_out to a named function
 * Arguments:     func - name of function the call_out should call
 * Returns:       -1 if not found, else time left before triggered
 */
int
find_call_out(string func)
{
    mixed *calls = get_all_alarms();
    int i;
    
    for (i = 0; i < sizeof(calls); i++)
	if (calls[i][1] == func)
	    return ftoi(calls[i][2]);
    return -1;
}

/*
 * Function name: remove_call_out
 * Description:   Locate and remove a call_out to a named function
 * Arguments:     func - name of function the call_out is for
 * Returns:       -1 if not found, time that remained before trigger
 *                would be done if found
 */
int
remove_call_out(string func)
{
    mixed *calls = get_all_alarms();
    int i;
    
    for (i = 0; i < sizeof(calls); i++)
	if (calls[i][1] == func)
	{
	    remove_alarm(calls[i][0]);
	    return ftoi(calls[i][2]);
	}
    return -1;
}

/*
 * Function name: call_out
 * Description:   Add a call_out to the named function
 * Arguments:     func  - function to be called
 *                delay - how long to wait before calling
 *                        the function
 *                arg   - optional argument to pass to the named
 *                        function when the call_out triggers
 * Returns:       The id if the call_out
 */
varargs int
call_out(string func, mixed delay, mixed arg)
{
    float repeat;

    repeat = 0.0;
    if (intp(delay))
	delay = itof(delay);
    if (delay < 0.0)
    {
	repeat = -delay;
	delay = repeat;
    }
    /*
     * Don't pass a 0 argument if no argument were specified
     */
    if (arg)
	return set_alarm(delay, repeat, func, arg);
    return set_alarm(delay, repeat, func);
}
