//gamer,20060523
string *banned_cast=({"chuqiao","qimen","qiankun","zhuang","huanying","townportal","escape","tuoqiao",
        "tudun","shuidun","huodun","ygbh","yundun","jile","huadun","wuxing","fengshi","move","seal"});
string *banned_action=({"practice","xiudao","move","mark","learn","study","read","bian","recall","accept","ji"});
        
int do_quit() 
{
  write("进了万仙阵  有来无回！ \n");
  return 1;
}
        
int do_sleep() 
{
  write("算你狠，这里也敢睡大觉！ \n");
  return 1;
}
int do_ji() 
{
  write("你突然发现什么都没有发生！ \n");
  return 1;
}
int do_pfm(string arg) 
{
         while(sscanf(arg,"%s %*s",arg)==2);
         if(arg != "dodge.xukong") return 0;
  write("你突然发现什么都没有发生！ \n");
  return 1;
}
int do_cast(string arg) 
{
   if(!arg) return 0;
   while(sscanf(arg,"%s %*s",arg)==2);
   if(member_array(arg,banned_cast)==-1) 
        return 0;
    write("这里不可以"+arg+",不可以临阵脱逃，要与同伴通力合作! \n");
    return 1;
}
int check_wxz()
{
        object *inv;
        int count;
        object where = this_object();
        inv = all_inventory(where);
        for(int i =0;i<sizeof(inv);i++)
        {
                if(inv[i]->is_character()&&(inv[i]->query("id") == "mo jiang"))
                {       
                        if(living(inv[i]))
                                count++;
                }
        }
        return count;
        
}
void choose_master()
{
                int i;
	object *inv;
                object where = this_object();
         if(query("wxz_master"))
         {
                        inv = all_inventory(where);
                        for(i =0;i<sizeof(inv);i++)
                        {
                                if(inv[i]->is_character()&&inv[i]->query("id") == "mo jiang")
                                                {
                                                        printf("%d ......%O\n",i,inv[i]);
                                                        if(!random(query("wxz_level")))
                                                        {
                                                             inv[i]->set("master_wxz",1);
                                                             inv[i]->powerup(query("wxz_level"));
                                                             set("wxzmaster",inv[i]);
                                                             printf("master %O\n",inv[i]);
                                                             break;
                                                        }
                                        }
                        }
                        if (i == sizeof(inv)&&i)
                        {
            if(!userp(inv[0]))
                                {
                                        inv[0]->set("master_wxz",1);
                                        inv[0]->powerup(query("wxz_level"));
                                 set("wxzmaster",inv[0]);
                                }
                        }
                        delete("wxz_master");
        }       
        
        
}
void reset()
{
        if(query("wxz_level"))
        {
                delete("exits");
                delete("true_exit");
                set("wxz_master",1);
                if(objectp(query("wxzmaster")))
                        {
                                query("wxzmaster")->delete("master_wxz");
                                delete("wxzmaster");
                        }
        }
        if(query("wxz_entr"))
        {
                 set("set_exit",1);
        }
        ::reset();
}

