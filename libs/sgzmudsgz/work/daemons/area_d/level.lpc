// level.c by fire on Dec 1998
int *get_area_product_level(string p_id)
{
   int p_zhi=0,p_mei=0,p_levelnum=0,*list_title,i,j;
   string *list_char, *a_tmp;
   list_title=OFFICER_D->query_area_officer_title_all
        (AREA_D->get_area(p_id,"level"));
   list_char=CHAR_D->check_char("area",p_id);
   for(i=0;i<sizeof(list_title);++i)
   {   if(list_title[i]>99) // this is wen guan
       {  int p_zhitmp=0,p_meitmp=0, p_num, v_left;
          mapping m;
          p_levelnum++;
          a_tmp=filter_array(list_char,
              (:CHAR_D->get_char($1,"ranklocal")==$(list_title[i]):));
          for(j=0;j<sizeof(a_tmp);++j)
          {   m=CHAR_D->get_char(a_tmp[j],"skills");
              p_zhitmp+=m["sk_zhimou"];
              p_meitmp+=m["sk_meili"];
          }
          p_num=OFFICER_D->query_max_officer_number(list_title[i]);
          p_zhitmp/=p_num;
          p_meitmp/=p_num;
          p_zhi+=p_zhitmp;
          p_mei+=p_meitmp;
      }
  }
  p_zhi/=p_levelnum;p_zhi*=2;
  p_mei/=p_levelnum;p_mei*=2; // to make the development level high
  return ({p_zhi+random(3),p_mei+random(3),(p_zhi+p_mei)/2+random(3) });
}
int *get_area_safe_level(string p_id)
{   int p_zhi=0,p_mei=0,p_levelnum=0,p_wu=0,*list_title,i,j,p_ret;
    string *list_char, *a_tmp;
    list_title=OFFICER_D->query_area_officer_title_all
       (AREA_D->get_area(p_id,"level"),0,0);
    list_char=CHAR_D->check_char("area",p_id);
    for(i=0;i<sizeof(list_title);++i)
    {  int p_zhitmp=0,p_meitmp=0,p_wutmp=0, p_num, v_left;
       mapping m;
       p_levelnum++;
       a_tmp=filter_array(list_char,
            (:CHAR_D->get_char($1,"ranklocal")==$(list_title[i]):));
       for(j=0;j<sizeof(a_tmp);++j)
       {    m=CHAR_D->get_char(a_tmp[j],"skills");
            p_zhitmp+=m["sk_zhimou"];
            p_meitmp+=m["sk_meili"];
            p_wutmp+=m["sk_wuli"];
       }
       p_num=OFFICER_D->query_max_officer_number(list_title[i]);
       v_left=p_num-sizeof(a_tmp);
       p_zhitmp/=p_num;
       p_meitmp/=p_num;
       p_wutmp/=p_num;
       p_zhi+=p_zhitmp;
       p_mei+=p_meitmp;
       p_wu+=p_wutmp;
    }
    p_zhi/=p_levelnum;
    p_mei/=p_levelnum;
    p_wu/=p_levelnum;
    p_ret=(p_mei*70+p_wu*10+p_zhi*20)/100;
    p_ret=p_ret+40+10-
      AREA_D->get_area(p_id,"taxlocal")-
      AREA_D->get_area(p_id,"taxnation");
    return ({p_ret+random(3)});
}
int *get_area_military_level(string p_id)
{  int p_zhi=0,p_mei=0,p_wu=0,p_levelnum=0, *list_title,leader_title;
   string *list_char, *a_tmp;
   int i,j, p_train,p_morale;
   list_title=OFFICER_D->query_area_officer_title
      (AREA_D->get_area(p_id,"level"),0,0);
   leader_title=list_title[0];
   list_title=OFFICER_D->query_area_officer_title_all
      (AREA_D->get_area(p_id,"level"));
   list_char=CHAR_D->check_char("area",p_id);
   for(i=0;i<sizeof(list_title);++i)
   {  if((list_title[i]<100)||(list_title[i]==leader_title)) 
      {  int p_zhitmp=0,p_meitmp=0,p_wutmp,p_num, v_left;
         mapping m;
         p_levelnum++;
         a_tmp=filter_array(list_char,
             (:CHAR_D->get_char($1,"ranklocal")==$(list_title[i]):));
         for(j=0;j<sizeof(a_tmp);++j)
         {    m=CHAR_D->get_char(a_tmp[j],"skills");
              p_zhitmp+=m["sk_zhimou"];
              p_meitmp+=m["sk_meili"];
              p_wutmp+=m["sk_wuli"];
         }
         p_num=OFFICER_D->query_max_officer_number(list_title[i]);
         v_left=p_num-sizeof(a_tmp);
         p_zhitmp/=p_num;
         p_meitmp/=p_num;
         p_wutmp/=p_num;
         p_zhi+=p_zhitmp;
         p_mei+=p_meitmp;
         p_wu+=p_wutmp;
      }
  }
  p_zhi/=p_levelnum;
  p_mei/=p_levelnum;
  p_wu/=p_levelnum;
  p_train=(p_wu+p_zhi)/2;
  p_morale=(p_wu+p_mei)/2;
  return ({p_train+random(3),p_morale+random(3),});
}
