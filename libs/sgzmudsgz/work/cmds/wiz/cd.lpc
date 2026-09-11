/* Do not remove the headers from this file! see /USAGE for more info. */
inherit CMD;
private void main(mixed *arg)
{
   string fname = arg[0];
    
    if ( !fname )
    {
        fname = wiz_dir(this_user());
        if(!is_directory(fname))
            fname = "/help";
    }
/*    
   if(!is_directory(fname))
   {

printf("%s: 没有这个文件或目录。\n",fname);
    return;
}
*/
    this_body()->query_shell_ob()->set_pwd(fname);
    outf("当前目录: %s\n", fname);
}
