judge(str) {         /* Main proc for jugding */
  object ob;
  if(!str) return;
  if(present(LC(str),ENV(TP)))
     ob=present(LC(str),ENV(TP));
  else
     ob=present(LC(str),TP);
  if(!ob)  write("What do you want to judge?\n");
  else {
    write("You concentrate your Force on "+CAP(str)+".\n");
    if(living(ob)) judge_living(ob);
    else judge_object(ob);
  }
  return 1;
}   /* end  judge */
 
judge_living(obj) {
  write(obj->NAME+" is living. "+CAP(obj->PRO)+" is "+ align(obj)+".\n"+
        CAP(obj->NAME)+" is a "+monster(obj)+" "+obj->query_race()+".\n"+
        CAP(obj->PRO)+" is "+shapey(obj)+".\n"+
        CAP(obj->PRO)+" is "+armed(obj)+" armed and "+protect(obj)+
        " protected.\n");
  return 1;
}
 
judge_object(obj) {
  int flag;
  flag=0;
  write(obj->short()+".\n");
  if(obj->query_weapon()) {
    write("It seems to be some kind of weapon.\n");
    write("It is a "+armed(obj)+" weapon.\n");
    flag=1;
  }
  if(obj->query_armour()) {
     write("It seems to be some kind of armour.\n");
     write("It provides "+protect2(obj)+" protection.\n");
     flag=1;
  }
  if(obj->query_container()) {
     write("It seems to be some kind of a container.\n");
     flag=1;
  }
  if(obj->query_food()) {
     write("It seems you can eat it.\n");
     flag=1;
  }
  if(obj->query_drink()) {
     write("It seems you can drink it.\n");
     flag=1;
  }
  if(!flag)
     write("You don't know exactly what it is used for.\n");
  write("It "+weight(obj)+".\n");
  return  1;
}
 
/* some procedures for jugde-command */
shapey(obj) {
  int no;
  no=(sizeof(shape_arr))*(obj->query_hp()+1)/(obj->query_maxhp()+1);
#if 0
  if(no==0 && obj->query_hp()>30) no=1;
#endif
  if(no<=0) no=1;
  else if (no>sizeof(shape_arr)) no=sizeof(shape_arr);
  return shape_arr[sizeof(shape_arr)-no];
}
 
align(obj) {
  return obj->query_al_string();
}
 
armed(obj) {
  int no;
  if(living(obj)) no=obj->query_wc()/3-1;
  else no=obj->weapon_class()/3-1;
  if(no>7) no=7;
  else if(no<0) no=0;
  return wc_arr[no];
}
 
protect(obj) {
  int no;
  no=obj->query_ac()/2-1;
   if(no>7) no=7;
   else if(no<0) no=0;
   return wc_arr[no];
}
 
protect2(obj) {
  int no;
  no=obj->armour_class();
  if(no>7) no=7;
  else if(no<0) no=0;
  return wc_arr[no];
}
 
monster(obj) {
  int no;
  no=obj->query_maxhp()/60-1;
  if(no>7) no=7;
  else if(no<0) no=0;
  return monsters[no];
}
 
weight(obj) {
   int no;
   no=obj->query_weight()+1;
   if(no<0) no=0;
   else if(no>6) no=6;
   return weight_arr[no];
}
