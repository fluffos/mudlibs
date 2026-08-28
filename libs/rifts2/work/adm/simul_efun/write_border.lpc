varargs string write_border(int cols, string what)
   {
   int i,j=0;
   string *no_really_what;
   string booga= "";
   no_really_what = explode(what, "");
   for (i=0; i < cols / sizeof(no_really_what) + 1; i++)
      for (j=0; j < sizeof(no_really_what); j++)
         booga += no_really_what[j];
   booga = booga[0..(cols-1)];
   booga += "\n";
   return booga;
   }
