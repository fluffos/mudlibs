// created by labaz
// 宗师装备防具

void wear_armor(object);

void wear_armor(object pl)
{
    object ob, *inv, env, newob, *newob_list, uitem;
    mapping gem_armor_map, dbase;
    string *ids, files, *armor_list, *prop;
    int i, j, num, armor_need_change;

    ob = this_object();
    inv = all_inventory(ob);
    newob_list = ({});

    /* 清除原有复制的autoload装备 */
    for (i=0;i<sizeof(inv);i++)
    {
        if ( objectp(inv[i]) && inv[i]->query("gem_ob_autoloaded") )
        {
            destruct(inv[i]);
        }
    }

    uitem=new(UITEM_OB);
    uitem->set("id", pl->query("id"));
//    if ( uitem->check_save() )
      uitem->restore();
  
    uitem->load_equip(pl, ob, "armor");
    newob_list=ob->query_temp("copy_autoload_list");

    env = environment(ob);
    if ( !env ) return;
    inv = all_inventory(env);

    for (i=0;i<sizeof(inv);i++)
    {
        if (inv[i]->query("armor_type"))
        {
            armor_need_change = 1;
            for(j=0;j<sizeof(newob_list);j++)
            {
                if( newob_list[j]->query("armor_type")==inv[i]->query("armor_type") )
                {
                    if ( ((newob_list[j]->query("forge/material1_level")+newob_list[j]->query("forge/material2_level")+
                          newob_list[j]->query("forge/material3_level")+newob_list[j]->query("forge/material4_level"))*
                          sizeof(newob_list[j]->query("armor_prop")) * (1+sizeof(newob_list[j]->query("suit_prop")))) <
                         ((inv[i]->query("forge/material1_level")+inv[i]->query("forge/material2_level")+
                          inv[i]->query("forge/material3_level")+inv[i]->query("forge/material4_level"))*
                          sizeof(inv[i]->query("armor_prop")) * (1+sizeof(inv[i]->query("suit_prop")))) )
                    {
                        newob_list -= ({newob_list[j]});
                        destruct(newob_list[j]);
                    }
                    else
                    {
                        armor_need_change = 0;
                    }
                }
            }
            if ( armor_need_change ) 
            {
                inv[i]->move(ob);
                inv[i]->wear(ob);
                newob_list += ({inv[i]});
            }
        }
    }
}



