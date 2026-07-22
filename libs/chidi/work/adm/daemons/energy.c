//重算属性
//edit by rock
//2008.10.9

#define MAX_EQUIP 11   //最大可装备空间 头、肩、手、铠、衬衫、腿、鞋、左手武器、右手武器、左手戒指、右手戒指


//函数声明
object* get_all_equip(object me);

//找出身上已装备的所有的装备
object* get_all_equip(object me)
{
	object* items = ({ }),*inv;
	int i,size;

	if(!objectp(me)) return 0;
	inv = all_inventory(me);

	size = sizeof(inv);
	for(i=0;i<size;i++)
	{
		if(inv[i]->query("embedded") || inv[i]->query("equipped"))
		{
			items += ({ inv[i] });
		}
	}
	return items;
}

//重算气血
void count_hp(object me)
{
	int add,i,p,size;
	object *equip;

	me->init_temp_hp_dbase(); //初始化
/******************************************装备影响**************************************/
	equip = get_all_equip(me);
	size = sizeof(equip);	
	if(MAX_EQUIP < size) size = MAX_EQUIP;

	add = 0;
	for( i = 0; i < size; i ++ )
        {
		if(p = equip[i]->query("hp")) add += p;
        }
        me->set_temp_hp( "equip", add );
/******************************************其他影响**************************************/

}

//重算精力
void count_jingli(object me)
{
	int add,i,p,size;
	object *equip;

	me->init_temp_jl_dbase(); //初始化
/******************************************装备影响**************************************/
	equip = get_all_equip(me);
	size = sizeof(equip);	
	if(MAX_EQUIP < size) size = MAX_EQUIP;

	for( i = 0; i < size; i ++ )
        {
                if (p = equip[i]->query("jingli")) add += p;
        }
        me->set_temp_jl( "equip", add );
/******************************************其他影响**************************************/

}

//重算精气
void count_jing(object me)
{
	int add,i,p,size;
	object *equip;

	me->init_temp_j_dbase(); //初始化
/******************************************装备影响**************************************/
	equip = get_all_equip(me);
	size = sizeof(equip);	
	if(MAX_EQUIP < size) size = MAX_EQUIP;

	for( i = 0; i < size; i ++ )
        {
                if (p = equip[i]->query("jing")) add += p;
        }
        me->set_temp_j( "equip", add );
/******************************************其他影响**************************************/

}

//重算魔法攻击
void count_ap(object me)
{
	int add,i,p,size;
	object *equip;

	me->init_temp_ap_dbase(); //初始化
/******************************************装备影响**************************************/
	equip = get_all_equip(me);
	size = sizeof(equip);	
	if(MAX_EQUIP < size) size = MAX_EQUIP;

	for( i = 0; i < size; i ++ )
        {
                if (p = equip[i]->query("ap")) add += p;
        }
        me->set_temp_ap( "equip", add );
/******************************************其他影响**************************************/

}

//重算物理防御
void count_dp(object me)
{
	int add,i,p,size;
	object *equip;

	me->init_temp_dp_dbase(); //初始化
/******************************************装备影响**************************************/
	equip = get_all_equip(me);
	size = sizeof(equip);	
	if(MAX_EQUIP < size) size = MAX_EQUIP;

	for( i = 0; i < size; i ++ )
        {
                if (p = equip[i]->query("dp")) add += p;
        }
        me->set_temp_dp( "equip", add );
/******************************************其他影响**************************************/

}

//重算魔法防御
void count_pp(object me)
{
	int add,i,p,size;
	object *equip;

	me->init_temp_pp_dbase(); //初始化
/******************************************装备影响**************************************/
	equip = get_all_equip(me);
	size = sizeof(equip);	
	if(MAX_EQUIP < size) size = MAX_EQUIP;

	for( i = 0; i < size; i ++ )
        {
                if (p = equip[i]->query("pp")) add += p;
        }
        me->set_temp_pp( "equip", add );
/******************************************其他影响**************************************/

}

//重算物理攻击
void count_cp(object me)
{
	int add,i,p,size;
	object *equip;

	me->init_temp_cp_dbase(); //初始化
/******************************************装备影响**************************************/
	equip = get_all_equip(me);
	size = sizeof(equip);	
	if(MAX_EQUIP < size) size = MAX_EQUIP;

	for( i = 0; i < size; i ++ )
        {
                if (p = equip[i]->query("cp")) add += p;
        }
        me->set_temp_cp( "equip", add );
/******************************************其他影响**************************************/

}

//重算内力
void count_neili(object me)
{
	int add,i,p,size;
	object *equip;

	me->init_temp_nl_dbase(); //初始化
/******************************************装备影响**************************************/
	equip = get_all_equip(me);
	size = sizeof(equip);	
	if(MAX_EQUIP < size) size = MAX_EQUIP;

	for( i = 0; i < size; i ++ )
        {
                if ((p = equip[i]->query("neili")) || (p = equip[i]->query("mp"))) add += p;
        }
        me->set_temp_nl( "equip", add );
/******************************************其他影响**************************************/

}