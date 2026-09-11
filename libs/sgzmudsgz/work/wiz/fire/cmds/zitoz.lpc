inherit CMD;
// zitoz
string get_content(string a_id);
void main() {
        string *keys;
        keys=CHAR_D->check_char("type",TYPE_NPC);
        keys=filter_array(keys,(:CHAR_D->get_char($1,"zi")=="":));
        foreach(string k in keys) {
            CHAR_D->set_char(k,"zi",0);
        }
}
