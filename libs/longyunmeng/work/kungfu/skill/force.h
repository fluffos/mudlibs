int valid_public(object me)
{
  mapping skl = me->query_skills();
  string *sk;
  int i;
  string skl_name = explode(file_name(this_object()), "/")[<1];

  if (!mapp(skl)) return 1;
  sk = keys(skl);
  i = sizeof(sk);
  while (i--) {
    if (sk[i] != skl_name && SKILL_D(sk[i])->valid_enable("force"))
      return notify_fail("你不散掉"+to_chinese(sk[i])
        +"，如何能修习"+to_chinese(skl_name)+"。\n");
  }
  return 1;
}

