status
cmd_liblog(string arg)
{
    if(!arg)
    {
      return (tail("/log/WR/LIB_REPORT"), 1);
    }

/*
    write_file("/log/WR/LIB_REPORT", pad("",69,'-')+"\n");
*/
    write_file("/log/WR/LIB_REPORT",
ctime()[4..15]+" "+capitalize((string)this_player()->query_real_name())
+"\n");
    write_file("/log/WR/LIB_REPORT",
      format(arg, 69));
    write_file("/log/WR/LIB_REPORT", pad("",69,'-')+"\n");

    write("Recorded.\n");
    return 1;
}
