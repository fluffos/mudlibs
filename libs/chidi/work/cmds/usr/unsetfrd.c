// unsetfrd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if( !arg || arg=="" ) return notify_fail("²ÎÊý´íÎó£¡\n");

        me->delete("friends/" + arg);
        write("Ok.\n");
        return 1;
}

