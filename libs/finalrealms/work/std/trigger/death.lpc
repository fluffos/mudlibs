int second_life() {
  mixed *bit;
  int i, ret;

  bit = (mixed *)this_object()->query_actions("death");
  for (i=0;i<sizeof(bit);i+=2)
    ret += (int)call_other(bit[i+1][0], bit[i+1][1]);
  return ret;
}
