//myarmy.c by fire on Dec 1998
// this is used to be inherited by char_d and
// handle the char's army
mixed new_qb(string p_id,int num)
{
   int oldnum,oldtrain;
   mixed my_army;
   if(!CHAR_D->char_exist(p_id))  return -1; //
   my_army=CHAR_D->get_char(p_id,"myarmy");
   if(!my_army) my_army=([]);
   oldnum=my_army["qbnum"];
   oldtrain=my_army["train"];
   oldtrain=(oldtrain*oldnum)/(oldnum+num);
   my_army["qbnum"]=oldnum+num;
   my_army["train"]=oldtrain;
   CHAR_D->set_char(p_id,"myarmy",my_army);
   return my_army;
}
