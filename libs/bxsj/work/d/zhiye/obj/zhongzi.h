// zhongzi.h
// by augx@sj 10/22/2001

void create()
{
        set_name("种子", ({ "zhongzi" }));
        set_weight(100+random(500));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗种子。\n");
                set("value", 300);
                set("zhongzi",1);
                set("canzi",0);
        }
        setup();
        initlvl();
}

int set_level(int i)
{
        switch (i) {
                case 1: 
                        set_name(HIW"棉花种子"NOR, ({"mianhua zhongzi","zhongzi","zi"}));
                        set("long",HIW"棉花的种子。\n"NOR);
                        set("material","mianhua");
                        set("value",100);
                        break;
                case 2: 
                        set_name(YEL"亚麻种子"NOR, ({"yama zhongzi","zhongzi","zi"}));
                        set("long",YEL"亚麻的种子。\n"NOR);
                        set("material","yama");
                        set("value",160);
                        break;
                case 3: 
                        set_name(YEL"大麻种子"NOR, ({"dama zhongzi","zhongzi","zi"}));
                        set("long",YEL"大麻的种子。\n"NOR);
                        set("material","dama");
                        set("value",240);
                        break;
                case 4: 
                        set_name(HIY"苎麻种子"NOR, ({"zhuma zhongzi","zhongzi","zi"}));
                        set("long",HIY"苎麻的种子。\n"NOR);
                        set("material","zhuma");
                        set("value",360);
                        break;
                case 5: 
                        set_name(HIW"蚕子"NOR, ({"can zi","zi" }));
                        set("long",HIW"蚕的卵。\n"NOR);
                        set("material","cansi");
                        set("value",500);
                        set("zhongzi",0);
                        set("canzi",1);
                        break;
                case 6: 
                        set_name(HIY"木棉种子"NOR, ({"mumian zhongzi","zhongzi","zi"}));
                        set("long",HIY"木棉花的种子。\n"NOR);
                        set("material","mumianhua");
                        set("value",800);
                        break;
                        
                case 7: 
                        set_name(GRN"玉蚕子"NOR, ({"yucan zi","zi"}));
                        set("long",GRN"玉蚕的卵。\n"NOR);
                        set("material","yucansi");
                        set("value",1400);
                        set("zhongzi",0);
                        set("canzi",1);
                        break;
                case 8: 
                        set_name(HIW"冰蚕子"NOR, ({"bingcan zi","zi"}));
                        set("long",HIW"冰蚕的卵。\n"NOR);
                        set("material","bingcansi");
                        set("value",2000);
                        set("zhongzi",0);
                        set("canzi",1);
                        break;
                case 9: 
                        set_name(WHT"天蚕子"NOR, ({"tiancan zi","zi"}));
                        set("long",WHT"天蚕的卵。\n"NOR);
                        set("material","tiancansi");
                        set("value",4000);
                        set("zhongzi",0);
                        set("canzi",1);
                        break;
                case 10:
                	set_name(HIY"龙茧蚕"NOR,({"longcan zi","si"}));
                	set("long",HIY"一种形如盘龙的毒蚕的卵。\n"NOR);
                	set("material","longcansi");
                	set("value",8000);
                	set("zhongzi",0);
                        set("canzi",1);
                	break;
                 default:
			call_out("destroying", 1, this_object());
                 	return 0;     
        }
        set("level",i);
        return 1;
}

int query_level()
{
        return query("level");
}
void destroying(object obj)
{
	if (!obj) return;
	if (userp(obj))
		command("drop "+obj->parse_command_id_list()[0]);
	else
		destruct(obj);
}