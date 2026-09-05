status
cmd_liblog(string arg)
{
    if (!arg || (int)this_player()->query_level() < 1000)
    {
      return (tail("/log/WR/LIB_REPORT"), 1);
    }

/*
    write_file("/log/WR/LIB_REPORT", pad("",69,'-')+"\n");
*/
    write_file("/log/WR/LIB_REPORT",
/* Rumplemintz - changed to include year
ctime()[4..15]+" "+capitalize((string)this_player()->query_real_name())
*/
               ctime()[4..15] + " " + ctime()[20..23] + " " +
               capitalize((string)this_player()->query_real_name())
+"\n");
    write_file("/log/WR/LIB_REPORT",
      format(arg, 69));
    write_file("/log/WR/LIB_REPORT", pad("",69,'-')+"\n");

    write("Recorded.\n");
    return 1;
}
