// mcp.c  to copy all files in one directory to another
// writen by lipson

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string src, dst, fsrc, fdst;
        int i;
        mixed *file;

        seteuid(geteuid(me));
       if( !arg || sscanf(arg, "%s %s", src, dst) != 2 )
               return notify_fail("mcp <directory a> <directory b> \n");
       
        src = resolve_path(me->query("cwd"), src);
       dst = resolve_path(me->query("cwd"), dst);

        if( src[strlen(src)-1] != '/' ) src += "/";
        if( file_size(src) != -2 )
               return notify_fail("we do not have directory " + src + "\n");
        
       file = get_dir(src);
       if( !sizeof(file) )
                return notify_fail(src + " is empty \n");

       if( dst[strlen(dst)-1] != '/' ) dst += "/";
        if( file_size(dst) != -2 )
               return notify_fail("we do not have directory " + dst + "\n");

        for( i = 0; i < sizeof(file); i++ ) {
                fsrc = src + file[i];

                if( file_size(fsrc) == -2 ) continue;

                fdst = dst + file[i];
                if( cp(fsrc, fdst) )
                        write("ok. for file: " + fdst + "\n");
                else {  write("you do not have the right to copy this file\n");                        break;}
                }

        return 1;
}

