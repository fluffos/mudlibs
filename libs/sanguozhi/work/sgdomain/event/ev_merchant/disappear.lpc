// this is used to handle merchant appear
// disappear.c
// by fire on Dec 1998
void disappear()
{
    string *lis;
    object o;
    lis=CHAR_D->check_char("is_merchant",1);
    if(sizeof(lis))
      foreach(string p_id in lis)
      {
        o=CHAR_D->find_char(p_id);
        if(objectp(o))
          o->simple_action("$N离开了。\n");
        CHAR_D->remove_char(p_id);
      }
}
