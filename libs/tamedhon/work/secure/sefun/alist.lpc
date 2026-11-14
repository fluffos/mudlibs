//
// Wunderland Mudlib
//
// secure/sefun/alist.c -- alist-Funktionen fuer ldmud 3.5
//
// $Log: alist.c,v $
// Revision 1.1  2021/03/25 16:07:06  Fuchur
// Update auf ldmud 3.6.3
//

#if !__EFUN_DEFINED__(order_alist)

mixed *order_alist(mixed *keys, varargs mixed **data)
{
    return efun::transpose_array(
        efun::sort_array(
            efun::transpose_array(
                sizeof(keys)>0 && pointerp(keys[0]) ? keys : ({keys}) + data),
            function int(mixed *a, mixed *b) { return a[0] > b[0]; }
        )
    );
}

#endif
