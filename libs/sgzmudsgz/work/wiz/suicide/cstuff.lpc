// to create basic stuff for all new areas
inherit CMD;

void main() {
        string *keys;
        string f_name,p_con;
        mapping st;
        set_privilege(1);
        keys=AREA_D->list_areas();
        foreach(string a_id in keys)
        {
         st=AREA_D->get_area(a_id,"st");
         if (!st||!sizeof(st)) continue;
         //AREA_D->set_area(a_id,"st",0);
         foreach(string s in keys(st))
         {
         if (mapp(st[s])) continue;
         AREA_D->set_area_st(a_id,s,"num",st[s]);
         AREA_D->set_area_st(a_id,s,"price",0);
         //AREA_D->set_area_st(a_id,s,"maxstock",0);
         
         }
           
        }
        write("地区的stuff参数数据格式更新完毕!\n");
        return;
}
