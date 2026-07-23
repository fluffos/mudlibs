int main()
{
      mapping info;
      int utime, stime;

      info = rusage();
      utime = info["utime"];
      stime = info["stime"];
      write(sprintf("rusage = %O\n", info));
      write("user time   = " + utime + "ms\n");
      write("system time = " + stime + "ms\n");
      write(sprintf("CPU usage   = %d%%\n", utime/((utime+stime)/100)));
      return 1;
}
