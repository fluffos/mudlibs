#pragma no_combine_string
#pragma set_code_window
t1() {
  mixed u, t, i, j;
  t = get_eval_cost(); u = rusage()[0];
  for (i = 0; i < 100000; i++)
    j = "foobar";
  return ({ t-get_eval_cost(), rusage()[0]-u });
}
t2() {
  mixed u, t, i, j;
  t = get_eval_cost(); u = rusage()[0];
  for (i = 0; i < 100000; i++)
  j = "foo" "bar";
  return ({ t-get_eval_cost(), rusage()[0]-u });
}
t3() {
  mixed u, t, i, j;
  t = get_eval_cost(); u = rusage()[0];
  for (i = 0; i < 100000; i++)
  j = "foo"+"bar";
  return ({ t-get_eval_cost(), rusage()[0]-u });
}
t4() {
  mixed u, t, i, j;
  t = get_eval_cost(); u = rusage()[0];
  for (i = 0; i < 100000; i++)
j = ("foo")+("bar");
  return ({ t-get_eval_cost(), rusage()[0]-u });
}
t5(){
  mixed u, t, i, j;
  t = get_eval_cost(); u = rusage()[0];
  for (i = 0; i < 100000; i++)
j = ("foooooooooooooooooooooooooooooooooooo")+("baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaar")+("baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaz");
  return ({ t-get_eval_cost(), rusage()[0]-u });
}
#pragma show_code_window
