// kuangshi.h
// by augx@sj  10/22/2001
//

void change_state();
void create()
{
        set_name("矿石", ({ "kuangshi" , "shi" }));
        set_weight(3000+random(5000));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一块普通的矿石。\n");
                set("value", 3000);
                //set("kuangshi",1);
                //set("kuangcai",0);
                set("no_sell","稀奇古怪的一块石头，要来何用？");// add by LinuX@SJ
                set("level",0);
        }
        setup();
        initlvl();
}

int set_level(int i)
{
        switch (i) {
                case 1:
                        set_name(GRN"青铜矿石"NOR, ({"qingtong kuangshi","kuangshi","shi"}));
                        set("long",GRN"普通的青铜矿石。\n"NOR);
                        set("material","qingtong");
                        set("value",500);
                        break;
                case 2:
                        set_name(YEL"生铁矿石"NOR, ({"shengtie kuangshi","kuangshi","shi"}));
                        set("long",YEL"普通的生铁矿石。\n"NOR);
                        set("material","shengtie");
                        set("value",800);
                        break;
                case 3:
                        set_name(YEL"软铁矿石"NOR, ({"ruantie kuangshi","kuangshi","shi"}));
                        set("long",YEL"普通的软铁矿石。\n"NOR);
                        set("material","ruantie");
                        set("value",1200);
                        break;
                case 4:
                        set_name(HIG"绿石矿"NOR, ({"lukuang shi","kuangshi","shi"}));
                        set("long",HIG"少有的绿石矿石。\n"NOR);
                        set("material","lushi");
                        set("value",1800);
                        break;
                case 5:
                        set_name(RED"流花石矿"NOR, ({"liuhuashi kuang","kuangshi","shi"}));
                        set("long",RED"少有的流花石矿石。\n"NOR);
                        set("material","liuhuashi");
                        set("value",2500);
                        break;
                case 6:
                        set_name(HIW"软银矿石"NOR, ({"ruanyin kuangshi","ruanying","kuangshi","shi"}));
                        set("long",HIW"稀有的软银矿石。\n"NOR);
                        set("material","ruanying");
                        set("value",3900);
                        break;
                case 7:
                        set_name(HIY"金铁矿石"NOR, ({"jintie kuangshi","kuangshi","shi"}));
                        set("long",HIY"稀有的金铁矿石。\n"NOR);
                        set("material","jintie");
                        set("value",7000);
                        break;
                case 8:
                        set_name(RED"万年神铁矿石"NOR, ({"shentie kuangshi","kuangshi","shi"}));
                        set("long",RED"极其罕见的万年神铁矿石。\n"NOR);
                        set("material","shentie");
                        set("value",10000);
                        break;
                case 9:
                        set_name(WHT"玄铁矿石"NOR, ({"xuantie kuangshi","kuangshi","shi"}));
                        set("long",WHT"绝无仅有的玄铁矿石。\n"NOR);
                        set("material","xuantie");
                        set("value",20000);
                        break;
                case 10:
                	set_name(HIC"万年寒冰矿石"NOR, ({"hanbing kuangshi","kuangshi","shi"}));
                        set("long",HIC"出产在雪山之巅的冰雪淬炼万年铁。\n"NOR);
                        set("material","hantie");
                        set("value",40000);
                        break;
                case 11:
                        set_name(MAG"未知矿石"NOR, ({"weizhi kuangshi","kuangshi","shi"}));
                        set("long",MAG"这是一块还没有人能够识别的新奇矿石。\n"NOR);
                        set("material","xuantie");
                        set("no_sell",1);
                        set("value",1);
                        set("kuangshi",0);
                        set("kuangcai",0);
                        set("job_kuangshi",1);
                        break;
                 default:
                 	call_out("destroying", 1, this_object());
                 	return 0;                 
        }
        //跳过datie
        set("level",i);
        if(i!=11) change_state();
        return 1;
}

int query_level()
{
        return query("level");
}

void change_state()
{
        //set("kuangshi",0);
        set("kuangcai",1);
        set("value",query("value") * 40/10);

        switch (query_level()) {
                case 1:
                        set_name(GRN"青铜"NOR, ({"qingtong"}));
                        set("long",GRN"斑斑铜锈绿中透着古意，这是一块青铜。\n"NOR);
                        break;
                case 2:
                        set_name(YEL"生铁"NOR, ({"shengtie"}));
                        set("long",YEL"乌亮两色集与一身，这是矿工常用的生铁。\n"NOR);
                        break;
                case 3:
                        set_name(YEL"软铁"NOR, ({"ruantie"}));
                        set("long",YEL"这种产自南方的软铁，质地不如生铁坚硬，但却韧性更足。\n"NOR);
                        break;
                case 4:
                        set_name(HIG"绿石"NOR, ({"lushi"}));
                        set("long",HIG"绿石原产云南，石中带骨，声如洪种，是打造上乘武器的原料。\n"NOR);
                        break;
                case 5:
                        set_name(RED"流花石"NOR, ({"liuhuashi"}));
                        set("long",RED"其色斑斓，其质刚劲，其型瑞合，是为流花石也。\n"NOR);
                        break;
                case 6:
                        set_name(HIW"软银"NOR, ({"ruanyin","ruanying"}));
                        set("long",HIW"这种金属外柔而内刚，卸劲于无形，因为色白，江湖人称软银。\n"NOR);
                        break;
                case 7:
                        set_name(HIY"金铁"NOR, ({"jintie"}));
                        set("long",HIY"有三分金，五分铁，两分黑石，传说中的金铁极其罕见。\n"NOR);
                        break;
                case 8:
                        set_name(RED"万年神铁"NOR, ({"shentie"}));
                        set("long",RED"铁入地母，沉睡百年以上而有魂，人们称赞之为“万年神铁”。\n"NOR);
                        break;
                case 9:
                        set_name(WHT"玄铁"NOR, ({"xuantie"}));
                        set("long",WHT"此铁原产瑶池仙境，随恶煞气洒落人间，内含玄机无数，凡人莫能知其究竟。\n"NOR);
                        break;
                case 10:
                	set_name(HIC"万年寒冰铁"NOR, ({"hantie"}));
                        set("long",HIC"不知出处，铁质冰寒，消魂噬骨，有万年造化之力的一块寒冰铁。\n"NOR);
                        break;
        }
        WORKER_D->get_status(this_object(),1,query_level(),random(5)?1:0);
        //msg = WORKER_D->get_msg(query("material_prop"));
        //if(stringp(msg) && msg!="")  set_temp("apply/long",({short()+"\n"+query("long")+msg}));
}

void destroying(object obj)
{
	if (!obj) return;
	if (userp(obj))
		command("drop "+obj->parse_command_id_list()[0]);
	else
		destruct(obj);
}