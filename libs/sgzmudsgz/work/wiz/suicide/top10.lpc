void get_top10()
{string *ids;
 ids = CHAR_D->check_char("type",1);
 ids = filter_array(ids, (: !wizardp($1) :));
 ids= sort_array(ids, (: (( CHAR_D->get_char($1,"reputation") >
                CHAR_D->get_char($2,"reputation") ) ? -1 : 1):));
 for (int i=0;i<10;i++)
printf("%s(%s)   %d\n",CHAR_D->get_char(ids[i],"name"),ids[i],CHAR_D->get_char(ids[i],"reputation"));
}
 
