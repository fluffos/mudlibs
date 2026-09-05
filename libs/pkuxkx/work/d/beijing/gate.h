int valid_leave(object me, string dir)
{
        if (dir == GATE_OUT_DIR1)
        {
        	if(me->query("dart_id") && !userp(me))
		return 0;
        }
        if (stringp(GATE_OUT_DIR2) && dir == GATE_OUT_DIR2)
        {
        	if(me->query("dart_id") && !userp(me))
		return 0;
        }
        return ::valid_leave(me, dir);
}
