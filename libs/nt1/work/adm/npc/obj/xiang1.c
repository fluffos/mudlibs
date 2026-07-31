// by Lonely

inherit ITEM;
inherit F_SAVE;

static int load;

string query_save_file() 
{
        string id;

        if (! stringp(id = query("owner")) ) return 0;
        return DATA_DIR + "room/" + id + "/" + id;
}

int is_container() { return 1; }
int no_limit_amount() { return 1; }

/*
void save_autoload()
{
        object *inv;
        int i, j;
        mixed param;
        string *autoload;

        inv = all_inventory();
        autoload = allocate(sizeof(inv));
        for (i = 0, j = 0; i < sizeof(inv); i++)
        {
                if (inv[i]->query("unique")) continue;
                autoload[j] = base_name(inv[i]);
                param = 1;
                autoload[j] += " : " + param;
                j++;
        }
        autoload = autoload[0..j - 1];
        delete("autoload");
        set("autoload", autoload);
}
*/

void save_autoload()
{
        object *inv;
        int i, amount;
        string obs;
        mapping autoload;

        autoload = ([ ]);
        
        inv = all_inventory();
        for (i = 0; i < sizeof(inv); i++)
        {
                if (inv[i]->query("unique")) continue;
                obs = base_name(inv[i]);
                if (! amount = inv[i]->query_amount())
                        amount = 1;
                autoload[obs] += amount;
        }
        delete("autoload");
        set("autoload", autoload);
}

int save()
{
        int res;
        save_autoload();
        res = ::save();
        return res;
}

object make_inventory(string file)
{
        object ob;

        ob = new(file);
        ob->set("startroom", base_name(this_object()));
        ob->move(this_object());
        return ob;
}

void restore_autoload()
{
        mapping ob_list, ob;
        string *list;
        int i,j;

        set("no_clean_up", 1);
        ob_list = query("autoload");
        if (! mapp(ob_list)) return;
        
        ob = allocate_mapping(sizeof(ob_list));
        list = keys(ob_list);
        for (i = 0; i < sizeof(list); i++)
        {
                // Allocate an array if we have multiple same object specified.
                reset_eval_cost(); 
                if (undefinedp(ob[list[i]]) &&
                    intp(ob_list[list[i]]) &&
                    ob_list[list[i]] > 1)
                        ob[list[i]] = allocate(ob_list[list[i]]);

                switch (ob_list[list[i]])
                {
                case 1:
                        reset_eval_cost();
                        if (! ob[list[i]]) 
                                ob[list[i]] = make_inventory(list[i]);
                        break;
                default:
                        for (j = 0; j < ob_list[list[i]]; j++)
                        {
                                // If the object is gone, make another one.
                                reset_eval_cost(); 
                                if (! objectp(ob[list[i]][j]))
                                {
                                        reset_eval_cost(); 
                                        ob[list[i]][j] = make_inventory(list[i]);
                                        continue;
                                }
                        }
                }
        }
        delete("autoload");
        save();
}

void create()
{
        set_name("聚宝箱", ({ "ju baoxiang", "baoxiang", "xiang" }));
        set_weight(1000);
        set_max_encumbrance(1000000000);
        set("owner", "lonely");
        if (clonep())
                set_default_object(__FILE__);
        else {          
                set_max_encumbrance(100000);
                set("long", "一个四周边缘镶嵌着珍珠玛瑙的箱子，好像可以将东西放在里面。\n");
                set("value", 100);              
                set("unit", "个");
                set("no_get", 1);
        }
        setup();
}

void init() 
{
        string owner;
        object env; 
        
        if (! load)
        {
                env = environment(this_object());  
                owner = (string)env->query("room_owner_id"); 
                set("owner", owner);
                restore();
                restore_autoload();
                load = 1;
        }
}

int remove()
{
        save();
}

void mud_shutdown()
{
        save();
}
