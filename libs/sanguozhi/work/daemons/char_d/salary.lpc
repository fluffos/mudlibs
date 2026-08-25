// salary.c
#include <char.h>
int get_char_salarylocal(string p_id)
{
   int rl=get_char(p_id,"ranklocal");
   if(!rl) return 0;
   if(get_char(p_id,"ranknation"))  return 0;
   return OFFICER_D->query_salary(rl);
}
int get_char_salarynation(string p_id)
{
   int p_n=get_char(p_id,"ranknation");
   int p_l=get_char(p_id,"ranklocal");
   if(!p_n)  return 0;
   if(p_n==R_KING) return 0;
   p_n=OFFICER_D->query_salary(p_n);
   p_l=OFFICER_D->query_salary(p_l);
   return bmax(p_l, p_n);
}
int get_char_salary(string p_id)
{   int p_n,p_l;
    p_n=get_char_salarynation(p_id);
    p_l=get_char_salarylocal(p_id);
    return bmax(p_n, p_l);
}
