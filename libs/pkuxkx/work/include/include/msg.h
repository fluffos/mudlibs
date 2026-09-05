varargs void combat_msg(string msg, object me, object you)
{
        string my_gender, your_gender, my_name, your_name;
        string str1, str2, str3;
        object *ob;
        int i;
        ob = all_inventory(environment(me));
        my_name= me->name();
        my_gender = me->query("gender");
        str1 = replace_string(msg,  "$P", gender_self(my_gender));
        str1 = replace_string(str1, "$N", gender_self(my_gender));
        str3 = replace_string(msg,  "$P", my_name);
        str3 = replace_string(str3, "$N", my_name);
        if( you ) {
                your_name= you->name();
                your_gender= you->query("gender");
            str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
            str2 = replace_string(str2, "$p", gender_self(your_gender));
            str2 = replace_string(str2, "$N", my_name);
            str2 = replace_string(str2, "$n", gender_self(your_gender));
    if(!you->query("env/skip_combat"))
            message("vision", str2, you);
            str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
            str1 = replace_string(str1, "$n", your_name);
            str3 = replace_string(str3, "$p", your_name);
            str3 = replace_string(str3, "$n", your_name);
     }
    if(!me->query("env/skip_combat")) message("vision", str1, me);
    for(i=0;i<sizeof(ob);i++){
      if(!ob[i]->query("env/skip_combat"))
{
if( ob[i]==you || ob[i]==me ) continue;
      message("vision", str3,  ob[i], ({ me, you}) );
        }
     }
}
