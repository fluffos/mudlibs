int valid_public(object me)
{
  mapping skl = me->query_skills();
   string *sk;
int i,j;
  string skl_name = explode(__FILE__, "/")[<1][0..<3];
  if (!mapp(skl)) return 1;
  sk = keys(skl);
  i = sizeof(sk);
  while (i--) {
  if (sk[i] != skl_name && SKILL_D(sk[i])->valid_enable("force"))
   { 
  if(skl_name=="huagong-dafa")
     return notify_fail("你不散掉"+to_chinese(sk[i])
    +"，如何能修习"+to_chinese(skl_name)+"。\n");
if(me->query_skill(skl_name,1)>=100)
     return notify_fail("你体内不同的真气，相互激荡无法融合为一。\n");
}
  }
  return 1;
  }
