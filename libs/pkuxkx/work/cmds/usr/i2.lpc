//inventory.c

#include <weapon.h>
#include <ansi.h>

inherit F_CLEAN_UP;
string inventory_desc(object ob);
int main(object me, string arg)
{
        int i;
        object *inv, ob;

        if( wizardp(me) && arg ) {
                ob = find_player(arg);
                if( !ob ) ob = find_living(arg);
                if( !ob ) ob = present(arg, environment(me));
        }

        if( !ob ) ob = me;

        inv = all_inventory(ob);
        if( !sizeof(inv) ) {
                write((ob==me)? "目前你身上没有任何东西。\n"
                        : ob->name() + "身上没有携带任何东西。\n");
                return 1;
        }
        printf("%s身上带著下列这些东西(负重 %d%%)：\n%s\n",
                (ob==me)? "你": ob->name(),
                (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance(),
                /*implode(map_array(inv, "inventory_desc", this_object()), "\n")*/
                inventory_desc(ob) );

        return 1;
}

string inventory_desc(object ob)
{
        int i,n,j,flag;
        object *inv;
        string str;
        object* inv_count = ({});
        string keyname;
        mapping count_stat = ([]);

       str ="";
       inv = all_inventory(ob);

        for (i = 0; i < sizeof(inv); i++) 
        {
            keyname = base_name(inv[i])+inv[i]->short();
            if(undefinedp(count_stat[keyname]))
            {
                count_stat[keyname] = 1;
                inv_count += ({inv[i]});
            }
            else
            {
                count_stat[keyname] = count_stat[keyname] + 1;
            }                
        }


        for(i=0; i<sizeof(inv_count); i++) {
             keyname = base_name(inv_count[i])+inv_count[i]->short();

        if(count_stat[keyname]==1)
             str += ""+inv_count[i]->short()+"\n";
         else
            str +=""+chinese_number(count_stat[keyname]) +"" + inv_count[i]->query("unit") +""+ inv_count[i]->short()+"\n";            
        }

        j=0;
        for (i=0;i <sizeof(inv);i++)
        {
            if (inv[i]->query("equipped")=="wielded") 
            {
                                if (inv[i] == ob->query_temp("weapon") ){
                        if (!j) str +=HIY"\n-------------------------------------------\n"NOR;
                                        flag = inv[i]->query("flag");
                                        if( flag & TWO_HANDED )  
                                                str += "你双手握着："+inv[i]->short()+"\n";
                                        else
                                                str += "你右手拿着："+inv[i]->short()+"\n";
                                }
                                else {
                        if (!j) str +=HIY"\n-------------------------------------------\n"NOR;
                            str += "你左手拿着："+inv[i]->short()+"\n";
                                }
                                j=1;   
            }
        }
        if (!j) str +=HIR"-------------------------------------------\n你手里什么也没拿\n"NOR;
        j=0;
        for (i=0;i <sizeof(inv);i++)
        {
            if (inv[i]->query("equipped") && (inv[i]->query("equipped")!="wielded") ) 
            {
                if (!j) str +=HIY"\n-------------------------------------------\n你身上穿着：\n"NOR;
                str += ""+inv[i]->short()+"\n";
                j=1;   
            }
        }
        if (!j) str +=HIR"-------------------------------------------\n你正光着个身子呀！你身上什么也没穿！\n"NOR;
         return str;  
}

int help (object me)
{
        write(@HELP
指令格式: inventory
 
可列出你(你)目前身上所携带的所有物品。
 
注 : 此指令可以 " i " 代替。
 
HELP
);
        return 1;
}

