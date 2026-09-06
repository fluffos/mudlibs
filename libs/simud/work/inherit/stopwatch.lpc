int *then;

void stopwatch_start()
{
   then = utime();
}

int stopwatch_read()
{
   int *now = utime();
   int dsec = now[0] - then[0];
   int dusec = now[1] - then[1];

   return dusec + 1000000 * dsec;
}
