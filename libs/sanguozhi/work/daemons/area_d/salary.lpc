// salary.c by fire on Dec 1998
int get_areasalary(string p_id)
{  int p_ret=0;
   int p_tmp;
   string *list;
   list=CHAR_D->check_char("area",p_id);
   foreach(string c_id in list)
   {
       p_tmp=CHAR_D->get_char_salarylocal(c_id);
       p_ret+=p_tmp;
   }
   return p_ret;
}
