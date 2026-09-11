void aut_appear()
{
	string *chars;
	object ob;
	chars=CHAR_D->check_char("is_xianren",1);
        foreach(string who in chars){
           ob=CHAR_D->find_char(who);
           if(!objectp(ob))
	     	   CHAR_D->appear(who);
        }
        return;
}
