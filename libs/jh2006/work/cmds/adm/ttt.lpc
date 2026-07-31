int main(object me, string arg)
{
  object *ob;
  int i;

  if (!arg) return 0;
  ob = children(arg);
  for (i=0;i<sizeof(ob);i++) printf("%O %O %s\n", ob[i], environment(ob[i]), ob[i]->short());
  return 1;
}
