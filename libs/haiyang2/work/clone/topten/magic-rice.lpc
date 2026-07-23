// magic-rice.c
//
// 1998/12/16 Modified by Winder
//
// 2000/7/6 add del by idea@yqyl

#define TOPTEN DATA_DIR + "topten"

inherit ITEM;
inherit F_SAVE;

int nowdel(mapping *which_chart,int chart_size,string me);

mapping *exp_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
        (["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *richman_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
        (["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *oldman_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
        (["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});

mapping *pks_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
});
mapping *force_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),});
mapping *literate_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),});
mapping *unarmed_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),});
mapping *dodge_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),});
mapping *thief_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),});
mapping *axe_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),});
mapping *blade_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),});
mapping *throwing_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),});
mapping *fork_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),});
mapping *hammer_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
        (["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),});
mapping *staff_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),});
mapping *sword_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),});
mapping *whip_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),});
mapping *club_topten =
({
        (["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),
});
int savetopten(object);
mapping *restore_exp_topten();

int simple_sort( mapping *,string,int,object );
int simple_sort_skill( mapping *,string,int,object );

int create()
{
        set_name("排行", ({ "hero-board","board"}) );
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        set("long", "");
        set("unit", "本");
        set("value", 0);
        setup();

        if( restore() )
        {
                exp_topten=query("exp_topten");
                richman_topten=query("richman_topten");
                oldman_topten=query("oldman_topten");
                thief_topten=query("thief_topten");
                force_topten=query("force_topten");
                literate_topten=query("literate_topten");
                axe_topten=query("axe_topten");
                blade_topten=query("blade_topten");
                throwing_topten=query("throwing_topten");
                whip_topten=query("whip_topten");
                staff_topten=query("staff_topten");
                hammer_topten=query("hammer_topten");
                sword_topten=query("sword_topten");
                unarmed_topten=query("unarmed_topten");
                dodge_topten=query("dodge_topten");
                fork_topten=query("fork_topten");
        club_topten=query("club_topten");
        pks_topten=query("pks_topten");
        }
        return 1;
}

string query_save_file() { return TOPTEN; }

int savetopten( object me )
{
        object obj;
        int exist,i;

        simple_sort( exp_topten,"combat_exp",10,me );
        simple_sort( richman_topten,"balance",10,me );
        simple_sort( oldman_topten,"mud_age",10,me );
        simple_sort( force_topten,"max_neili",5,me );
        simple_sort_skill( thief_topten,"stealing",3,me );
        simple_sort_skill( literate_topten,"literate",5,me );
        simple_sort_skill( axe_topten,"axe",3,me );
        simple_sort_skill( blade_topten,"blade",3,me );
        simple_sort_skill( throwing_topten,"throwing",3,me );
        simple_sort_skill( whip_topten,"whip",3,me );
        simple_sort_skill( staff_topten,"staff",3,me );
        simple_sort_skill( hammer_topten,"hammer",3,me );
        simple_sort_skill( sword_topten,"sword",3,me );
        simple_sort_skill( unarmed_topten,"unarmed",5,me );
        simple_sort_skill( dodge_topten,"dodge",5,me );
        simple_sort_skill( fork_topten,"fork",3,me );
        simple_sort_skill( pks_topten,"pks",5,me );
        simple_sort_skill( club_topten,"club",3,me );

        set("exp_topten",exp_topten);
        set("richman_topten",richman_topten);
        set("oldman_topten",oldman_topten);
        set("thief_topten",thief_topten );
        set("force_topten",force_topten );
        set("literate_topten",literate_topten );
        set("axe_topten",axe_topten );
        set("blade_topten",blade_topten );
        set("throwing_topten",throwing_topten );
        set("whip_topten",whip_topten );
        set("staff_topten",staff_topten );
        set("hammer_topten",hammer_topten );
        set("sword_topten",sword_topten );
        set("unarmed_topten",unarmed_topten );
        set("dodge_topten",dodge_topten );
        set("fork_topten",fork_topten );
        set("pks_topten",pks_topten );
        set("club_topten",club_topten );

        save();
        return 1;
}

int simple_sort( mapping *which_chart,string chart_type,int chart_size,object me )
{
        int i,exist;
        string *c_id=({"空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺",});
        string *c_short=({"空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺",});
        int *c_type=({11,10,9,8,7,6,5,4,3,2,1,0});
        string si;

        si="名次";
        c_id[chart_size] = me->query("id");
        c_short[chart_size] = RANK_D->query_rank(me)+me->short(1);
        c_type[chart_size] = me->query(chart_type);
        exist = 0;
        for( i = 0; i < chart_size; i++ )
        {
                si=sprintf("第%d名",i+1 );
                sscanf( which_chart[i][si],"%s\n%s\n%d\n",c_id[i],c_short[i],c_type[i] );
                if( c_id[i] == c_id[chart_size] )
                {
                        c_short[i] = c_short[chart_size];
                        c_type[i]  = c_type[chart_size] ;
                        exist = 1;
                        continue;
                }
//              if( !(FINGER_D->acquire_login_ob(c_id[i])) )
//                      c_type[i]= 0;
        }


        for( i = 0; i < chart_size - exist; i++ )
        {
                if( c_type[i] < c_type[i+1] )
                {
                        c_id[chart_size+1]    = c_id[i];
                        c_short[chart_size+1] = c_short[i];
                        c_type[chart_size+1]  = c_type[i];
                        c_id[i]    = c_id[i+1];
                        c_short[i] = c_short[i+1];
                        c_type[i]  = c_type[i+1];
                        c_id[i+1]    = c_id[chart_size+1];
                        c_short[i+1] = c_short[chart_size+1];
                        c_type[i+1]  = c_type[chart_size+1];
                }

        }

        for( i = chart_size - exist; i > 0; i-- )
                if( c_type[i] > c_type[i-1] )
                {
                        c_id[chart_size+1]    = c_id[i-1];
                        c_short[chart_size+1] = c_short[i-1];
                        c_type[chart_size+1]  = c_type[i-1];
                        c_id[i-1]    = c_id[i];
                        c_short[i-1] = c_short[i];
                        c_type[i-1]  = c_type[i];
                        c_id[i]    = c_id[chart_size+1];
                        c_short[i] = c_short[chart_size+1];
                        c_type[i]  = c_type[chart_size+1];
                }

        for( i = 0; i < chart_size; i++ )
        {
                si=sprintf( "第%d名",i+1 );
                which_chart[i][si]=sprintf( "%s\n%s\n%d\n",c_id[i],c_short[i],c_type[i] );
        }

        return 1;
}

int simple_sort_skill( mapping *which_chart,string chart_type,int chart_size,object me )
{
        int i,exist;
        string *c_id=({"空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺",});
        string *c_short=({"空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺",});
        int *c_type=({11,10,9,8,7,6,5,4,3,2,1,0});
        string si;

        si="名次";
        c_id[chart_size] = me->query("id");
        c_short[chart_size] = RANK_D->query_rank(me)+me->short(1);
        c_type[chart_size] = me->query_skill(chart_type);
        exist = 0;
        for( i = 0; i < chart_size; i++ )
        {
                si=sprintf("第%d名",i+1 );
                sscanf( which_chart[i][si],"%s\n%s\n%d\n",c_id[i],c_short[i],c_type[i] );
                if( c_id[i] == c_id[chart_size] )
                {
                        c_short[i] = c_short[chart_size];
                        c_type[i]  = c_type[chart_size] ;
                        exist = 1;
                        continue;
                }
//              if( !(FINGER_D->acquire_login_ob(c_id[i])) )
//                      c_type[i]= 0;
        }


        for( i = 0; i < chart_size - exist; i++ )
        {
                if( c_type[i] < c_type[i+1] )
                {
                        c_id[chart_size+1]    = c_id[i];
                        c_short[chart_size+1] = c_short[i];
                        c_type[chart_size+1]  = c_type[i];
                        c_id[i]    = c_id[i+1];
                        c_short[i] = c_short[i+1];
                        c_type[i]  = c_type[i+1];
                        c_id[i+1]    = c_id[chart_size+1];
                        c_short[i+1] = c_short[chart_size+1];
                        c_type[i+1]  = c_type[chart_size+1];
                }

        }

        for( i = chart_size - exist; i > 0; i-- )
                if( c_type[i] > c_type[i-1] )
                {
                        c_id[chart_size+1]    = c_id[i-1];
                        c_short[chart_size+1] = c_short[i-1];
                        c_type[chart_size+1]  = c_type[i-1];
                        c_id[i-1]    = c_id[i];
                        c_short[i-1] = c_short[i];
                        c_type[i-1]  = c_type[i];
                        c_id[i]    = c_id[chart_size+1];
                        c_short[i] = c_short[chart_size+1];
                        c_type[i]  = c_type[chart_size+1];
                }

        for( i = 0; i < chart_size; i++ )
        {
                si=sprintf( "第%d名",i+1 );
                which_chart[i][si]=sprintf( "%s\n%s\n%d\n",c_id[i],c_short[i],c_type[i] );
        }

        return 1;

}

int movein(object me)
{
        move_object(me);
        return 1;
}

int del_one(string me,string type)
{
	switch(type)
	{
		case "B1":
			nowdel(exp_topten,10,me);
			break;
		case "B2":
			nowdel(richman_topten,10,me);
			break;
		case "B3":
			nowdel(oldman_topten,10,me);
			break;
		case "B4":
			nowdel(force_topten,5,me);
			break;
		case "B5":
			nowdel(literate_topten,5,me);
			break;
		case "B6":
			return notify_fail("无杀手榜\n");
		case "B7":
			nowdel(thief_topten,3,me);
			break;
		case "B8":
			nowdel(sword_topten,3,me);
			break;
		case "B9":
			nowdel(blade_topten,3,me);
			break;
		case "B10":
			nowdel(unarmed_topten,5,me);
			break;
		case "B11":
			nowdel(dodge_topten,5,me);
			break;
		case "B12":
			nowdel(throwing_topten,3,me);
			break;
		case "B13":
			nowdel(whip_topten,3,me);
			break;
		case "B14":
			nowdel(hammer_topten,3,me);
			break;
		case "B15":
			nowdel(staff_topten,3,me);
			break;
		default:
			write("没有"+type+"这种排行榜！\n");
			return 1;
	}
	
	set("exp_topten",exp_topten);
        set("richman_topten",richman_topten);
        set("oldman_topten",oldman_topten);
        set("thief_topten",thief_topten );
        set("force_topten",force_topten );
        set("literate_topten",literate_topten );
        set("axe_topten",axe_topten );
        set("blade_topten",blade_topten );
        set("throwing_topten",throwing_topten );
        set("whip_topten",whip_topten );
        set("staff_topten",staff_topten );
        set("hammer_topten",hammer_topten );
        set("sword_topten",sword_topten );
        set("unarmed_topten",unarmed_topten );
        set("dodge_topten",dodge_topten );
        set("fork_topten",fork_topten );

        save();
}

int nowdel(mapping *which_chart,int chart_size,string me)
{
	int i,j;
	string si,ssi,delid,ds,dp;

	for( i=0; i<chart_size; i++)
	{
		si=sprintf("第%d名",i+1 );
		sscanf( which_chart[i][si],"%s\n%s\n%d\n",delid,ds,dp);
		if (delid==me) break;
	}
	
	if (i==chart_size) {write("榜中无此人!\n");return 1;}
		else write("去掉第"+(i+1)+"名...\n");
	for( j=i; j<chart_size; j++)
	{
		si=sprintf( "第%d名",j+1 );
		ssi=sprintf( "第%d名",j+2);
		if (j==chart_size-1)
		which_chart[j][si]="空缺";
		else which_chart[j][si]=which_chart[j+1][ssi];
	}
	
	return 1;
}