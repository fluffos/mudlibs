int main(object me, string arg)
{
  object *ob;
  int i;

  if (!arg) return 0;
  ob = users();
  for (i=0;i<sizeof(ob);i++) if (ob[i]->query(arg)) printf("%O %O %s\n", ob[i], ob[i]->query(arg), ob[i]->short());
  return 1;
}
