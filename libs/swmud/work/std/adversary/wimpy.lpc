// Last edited by deforce on 06-07-2008
private int wimpy = 0;
private string wimpy_dir = "out";

void set_wimpy(int value)
{
   if ((value >= 0) && (value <= 100))
   {
      wimpy = value;
   }
}

int query_wimpy()
{
   return wimpy;
}

int query_wimpy_threshold()
{
   if (wimpy == 0) { return 0; }

   return to_int(floor((this_object()->query_max_health() * wimpy) / 100.0));
}

void set_wimpy_dir(string value)
{
   if (strlen(value))
   {
      wimpy_dir = value;
   }
}

string query_wimpy_dir()
{
   return wimpy_dir;
}