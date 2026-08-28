int main(int extra)
{
   int boot, hour, min, sec;

   boot = uptime();
   hour = boot / 3600;
   min = (boot - hour * 3600) / 60;
   sec = (boot - hour * 3600 - min * 60);

   extra = extra ? 1 : 0;
   write (mud_status (extra));
   return 1;
}

