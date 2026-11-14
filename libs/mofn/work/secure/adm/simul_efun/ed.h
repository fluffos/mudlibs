varargs void ed(string file, string fn_1, mixed fn_2, mixed rest) {
  int n = 4;

  if(!stringp(fn_2)) {
    rest = fn_2;
    fn_2 = 0;
    n = 3;
  } 

  if(!creatorp(PO))
    rest = 1;


  if(n == 3)
    efun::ed(file, fn_1, rest);
  else
    efun::ed(file, fn_1, fn_2, rest);
}

void cat(string file, int start_line, int number) {
  string bing;

  bing = read_file(file, start_line, number);
  if (bing) {                  
    printf("%s", bing[0..5000]);
  }         
}
