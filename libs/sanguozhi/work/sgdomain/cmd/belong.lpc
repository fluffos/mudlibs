// belong.c 
// by Suicide on July 20, 2001
// used for one dummy claim which id he is belongs.

inherit M_INPUT;

mixed is_valid_owner(string owner_id)
{object owner;
 if (!owner=find_body(owner_id))
    return "为了安全，你所设定的该ID拥有者必须在线！\n";
 if (wizardp(owner))
    return "你所设定的该ID拥有者不能是巫师！\n";
 return 1;
}

void confirm_do(object dummy,string owner,string arg)
{
if (arg=="Y"||arg=="y")
   {
   dummy->set_owner(owner);
   write("%^CYAN%^你将大米ID<"+dummy->query_userid()+">移交给玩家<"+owner+">%^RESET%^\n");
   modal_pop();
   return;
   }
else
   {
   if (arg=="N"||arg=="n")
      {
      write("%^CYAN%^你决定再慎重考虑考虑!%^RESET%^\n");
      modal_pop();
      return;
	}
   else
      {
      modal_pop();
      modal_push((: confirm_do, dummy,owner:), 
      "%^CYAN%^你确定要将大米ID<"+dummy->query_userid()+">移交给玩家<"+owner+">嘛?请输入Y/N?%^RESET%^\n");
      } 
   }


}

void start(string arg)
{string dummy_id,other_owner_id;
 mixed ret;
 if (!arg||arg=="")
    {printf("这个ID的拥有者是%s\n",this_user()->query_owner());
     return;}
 if (sscanf(arg, "%s to %s", dummy_id,other_owner_id)==2)
    {object dummy;
     if (!dummy=find_user(dummy_id))
       {write("进行大米ID移交，大米ID必须在线！\n");
        return;}
     if (dummy->query_owner()!=this_user()->query_userid())
       {write("你不是该大米ID的拥有者，无法移交其给别人！\n");
        return;}
     ret = is_valid_owner(other_owner_id);
     if (stringp(ret))
        write(ret);
     else
        {
         modal_push((: confirm_do, dummy,other_owner_id:), 
        "%^CYAN%^你确定要将大米ID<"+dummy_id+">移交给玩家<"+other_owner_id+">嘛?请输入Y/N?%^RESET%^");

         //dummy->set_owner(other_owner_id);
         //write("%^CYAN%^你将大米ID<"+dummy_id+">移交给玩家<"+other_owner_id+">%^RESET%^\n");
        }
   }
 else
    {
     if (this_user()->query_owner()!="")
       {
        write("只有该ID的拥有者通过命令 %^CYAN%^cmd belong <大米ID> to <移交ID>%^RESET%^才能转换拥有者！\n");
        return;
       }
     if (wizardp(this_body()))
       {
        write("巫师ID不能设定拥有者！\n");
        return;
       }
       
     ret = is_valid_owner(arg);
     if (stringp(ret))
        write(ret);
     else
        {
         modal_push((: confirm_do, this_user(),arg:), 
        "%^CYAN%^你确定要将自己的所有者ID初始设定为<"+arg+">嘛?请输入Y/N?%^RESET%^");

         //this_user()->set_owner(arg);
         //write("%^CYAN%^你将自己的所有者ID初始设定为"+arg+"%^RESET%^\n");
        }
    }

}