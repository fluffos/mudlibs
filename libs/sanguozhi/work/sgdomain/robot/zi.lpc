// queitem.c by fire@lima in Nov 1998
// this is used to test if this is a robot by item test
private mapping m_class;
nosave protected string *p_ids=({});
int init_class();
string* init_ids() {
	if(sizeof(p_ids)>20) return p_ids;
	p_ids=CHAR_D->check_char("type",TYPE_NPC);
   	p_ids=filter_array(p_ids,(: CHAR_D->get_char($1,"zi")  :));
   	p_ids=filter_array(p_ids,(: CHAR_D->get_char($1,"is_tmp")==0  :));
	return p_ids;
	
}
string q1(string p_id)
{
   string *ids;
   string id1,id2,id3,id4;
   string z1,z2,z3,z4;
   string question,ret;
   ids=init_ids();

   id1=ids[random(sizeof(ids))];z1=CHAR_D->get_char(id1,"zi");
   ids-=({id1});   

   id2=ids[random(sizeof(ids))];z2=CHAR_D->get_char(id2,"zi");
   ids-=({id2});
   while(z2==z1) {
      id2=ids[random(sizeof(ids))];z2=CHAR_D->get_char(id2,"zi");
      ids-=({id2});
   }

   id3=ids[random(sizeof(ids))];z3=CHAR_D->get_char(id3,"zi");
   ids-=({id3});

   while((z3==z1)||(z3==z2)) {
       id3=ids[random(sizeof(ids))];z3=CHAR_D->get_char(id3,"zi");
       ids-=({id3});
   }

   id4=ids[random(sizeof(ids))];z4=CHAR_D->get_char(id4,"zi");
   ids-=({id4});

   while((z4==z1)||(z4==z2)||(z4==z3)) {
      id4=ids[random(sizeof(ids))];z4=CHAR_D->get_char(id4,"zi");
      ids-=({id4});
   }
z4=HZK2ASC_D->hzk2asc(z4);
   question="\n"+CHAR_D->get_char(id1,"name")+"("+id1+")的字是:\n";
   switch(random(4)) {
       case 0:
         ret="1";
         question+="1 "+z1+"\n2 "+z2+"\n3 "+z3+"\n4 "+z4+"\n";
	break;
       case 1:
         ret="2";
         question+="1 "+z2+"\n2 "+z1+"\n3 "+z3+"\n4 "+z4+"\n";
	break;
       case 2:
         ret="3";
         question+="1 "+z3+"\n2 "+z2+"\n3 "+z1+"\n4 "+z4+"\n";
	break;
       default:
         ret="4";
         question+="1 "+z4+"\n2 "+z2+"\n3 "+z3+"\n4 "+z1+"\n";
	break;
   }
   question+="不知道请用 < %^H_RED%^!info c id%^RESET%^  >查询\n如用ZMUD，请先用Ctrl-R关闭parse\n";
//	question+="====答案为："+HZK2ASC_D->hzk2asc(z1);
   tell_user(p_id,question);
   return ret;
}
string q2(string p_id)
{
   string *ids;
   string id1,id2,id3,id4;
   string z1,z2,z3,z4,r_zi;
   string question,ret;
   ids=init_ids();

   id1=ids[random(sizeof(ids))];z1=CHAR_D->get_char(id1,"name")+"("+id1+")";
   ids-=({id1});
   r_zi=CHAR_D->get_char(id1,"zi");

   id2=ids[random(sizeof(ids))];z2=CHAR_D->get_char(id2,"name")+"("+id2+")";
   ids-=({id2});
   while(CHAR_D->get_char(id2,"zi")==r_zi) {
      id2=ids[random(sizeof(ids))];z2=CHAR_D->get_char(id2,"name")+"("+id2+")";
      ids-=({id2});
   }

   id3=ids[random(sizeof(ids))];z3=CHAR_D->get_char(id3,"name")+"("+id3+")";
   ids-=({id3});
   while(CHAR_D->get_char(id3,"zi")==r_zi) {
      id3=ids[random(sizeof(ids))];z3=CHAR_D->get_char(id3,"name")+"("+id3+")";
      ids-=({id3});
   }

   id4=ids[random(sizeof(ids))];z4=CHAR_D->get_char(id4,"name")+"("+id4+")";
   ids-=({id4});
   while(CHAR_D->get_char(id4,"zi")==r_zi) {
      id4=ids[random(sizeof(ids))];z4=CHAR_D->get_char(id4,"name")+"("+id4+")";
      ids-=({id4});
   }


   question=""+HZK2ASC_D->hzk2asc(CHAR_D->get_char(id1,"zi"))+"是谁的字:  ";
   switch(random(4)) {
       case 0:
         ret="1";
         question+="1 "+z1+";  2 "+z2+";  3 "+z3+";  4 "+z4+"\n";
	break;
       case 1:
         ret="2";
         question+="1 "+z2+";  2 "+z1+";  3 "+z3+";  4 "+z4+"\n";
	break;
       case 2:
         ret="3";
         question+="1 "+z3+";  2 "+z2+";  3 "+z1+";  4 "+z4+"\n";
	break;
       default:
         ret="4";
         question+="1 "+z4+";  2 "+z2+";  3 "+z3+";  4 "+z1+"\n";
	break;
   }
   question+="不知道请用 <%^RED%^ !info c id %^RESET%^ >查询\n如用ZMUD，请先用Ctrl-R关闭parse\n";
//   question+="====答案为："+HZK2ASC_D->hzk2asc(terminal_colour(z1, (previous_object()->query_translations())[1]));
   tell_user(p_id,question);
   return ret;
}
string test(string p_id)
{
   string ret;
   switch(random(2))
   {
      case 0:  // 哪一类
        ret=q1(p_id);
        return ret;
      case 1: 
        ret=q2(p_id);
        return ret;
   }
}
