string *message;
object call_ob;
object call_func;
int line;
int max_line;

#define pline(x) message ("0", x, THIS);

int
main (mixed str, int lines, object call_object, string call_function)
{
  if (str)
    message = explode(str, "\n");
  max_line = lines;
  call_ob = call_object;
  call_func = call_function;
  line = sizeof(message);

  pline ("Starting editing (\".\" for save and quit, \"h\" for help).\n");
  input_to ("do_line");
  return 1;
}

int
do_line (string str)
{
  message[line] = str;
}
