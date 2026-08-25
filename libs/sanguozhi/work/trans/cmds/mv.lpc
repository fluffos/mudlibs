// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Rust
#include <mudlib.h>
inherit CMD;

private void move_one(string src, string dst, int force)
{
    string contents;

    if ( is_file(dst) && !force )
    {
        //outf("%s already exists.  Move failed.\n", dst);
        outf("%s 早已存在了，Move 失败。\n", dst);
    }
    else if ( !(contents = read_file(src)) )
    {
        //outf("Could not read %s.  Move failed.\n", src);
        outf("无法读取 %s。Move 失败。\n", src);
    }
    else if ( !write_file(dst, contents, 1) )
    {
        //outf("%s could not be written to.  Move failed.\n", dst);
        outf("%s 无法写入，Move 失败。\n", dst);
    }
    else if ( !rm(src) )
    {
        //outf("%s couldn't be removed.\n", src);
        outf("无法删除 %s。\n", src);
    }
    else
    {
        outf("%s moved to %s.\n", src, dst);
    }
}

private void main(mixed argv, mapping flags)
{
    string dst, src;
  
    if(arrayp(argv[0]) && sizeof(argv[0]) > 1 && !is_directory(argv[1]))
    {
        //outf("mv: files dir, not mv files file\n");
        outf("用法：mv <文件群> <目录> 而不是 mv <文件群> <文件>\n");
        return;
    }
    if(sizeof(argv[0]) > 1)
    {
        if(argv[1][<1] != '/')
            argv[1] += "/";

        foreach ( src in argv[0] )
            {
                dst = argv[1] + split_path(src)[1];
                move_one(src, dst, flags["f"]);
            }
    }
    else 
    {
        dst = argv[1];
        src = argv[0][0];
        if(is_directory(dst))
        {
            if(dst[<1] != '/')
                dst += "/";
            dst += depath(src);
        }
        move_one(src, dst, flags["f"]);
    }
}
