//
// Wunderland Mudlib
//
// secure/sefun/bytes.c -- read/write_bytes etc. mit string fuer ldmud 3.6
//
// $Log: bytes.c,v $
// Revision 1.1  2021/03/25 16:07:06  Fuchur
// Update auf ldmud 3.6.3
//

#if __EFUN_DEFINED__(to_bytes)

#define ENCODING "UTF-8"

varargs string read_bytes(string file, int start, int number)
{
    extern_call() && set_this_object(previous_object());
    bytes res = efun::read_bytes(file, start, number);
    return res && to_text(res, ENCODING);
}

int write_bytes(string file, int start, string str)
{
    extern_call() && set_this_object(previous_object());
    return efun::write_bytes(file, start, to_bytes(str, ENCODING));
}

#if __EFUN_DEFINED__(send_erq)
varargs int send_erq(int request, string|int * data, closure callback)
{
    extern_call() && set_this_object(previous_object());
    return efun::send_erq(
        request, stringp(data) ? to_bytes(data, ENCODING) : data, callback);
}
#endif

#if __EFUN_DEFINED__(send_udp)
int send_udp(string host, int port, string|int * data)
{
    extern_call() && set_this_object(previous_object());
    return efun::send_udp(
        host, port, stringp(data) ? to_bytes(data, ENCODING) : data);
}
#endif

#endif
