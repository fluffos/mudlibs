//新房储物和榷场连动Zine 2013/2/5
#define TRADE "/d/changan/offline_shop1"
int song_room(int pin)
{
	int *rooms=({10,7,5,4,3,2});
	if (pin>6||pin<1)
	return 0;
	return rooms[pin-1];
}
int store_limit(object me)
{ 
	int room=0;//明朝官员额外空间，Zine 26/3/2011
	me=this_player();
	if (me->query("grandmaster")<1)
	room=10;
	else
	room=20;
	if (me->query("song/pro"))
	room+=me->query("song/extra_room_by_gongbu")*5+song_room(DASONG_D->get_my_pin(me));	
	if(me->is_realuser()) 
	room += 10;
	if (undefinedp(me->query("myroom")))
	return 0;
	return room;
}

int trade_limit(object me)
{
	return store_limit(me)-sizeof(me->query("store_ob"));
}

int room_limit(object me)
{
	return store_limit(me)-TRADE->my_goods_number(me);
}
