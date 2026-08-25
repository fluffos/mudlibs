inherit CMD;
void main() {
        string *chars;
        set_privilege(1);
        chars=CHAR_D->list_chars();
        foreach(string p_id in chars)
        {
         if (CHAR_D->get_char(p_id,"is_tmp"))
            {printf("%s\n",p_id);
             CHAR_D->set_char(p_id,"area",0);}
        }
return;
}