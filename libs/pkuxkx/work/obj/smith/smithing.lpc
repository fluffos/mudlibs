
mapping * all_products()
{
	return ({
(["name":"剑","type":"medium","temperature":70,"heat_require":1000,"hammer_require":25,"product":__DIR__"products/weapon",
"maker_level":0,"fail_possibility":35,]),
(["name":"刀","type":"medium","temperature":60,"heat_require":1000,"hammer_require":30,"product":__DIR__"products/weapon",
"maker_level":0,"fail_possibility":35,]),
(["name":"鞭","type":"medium","temperature":55,"heat_require":1200,"hammer_require":22,"product":__DIR__"products/weapon",
"maker_level":0,"fail_possibility":40,]),
(["name":"杖","type":"long","temperature":70,"heat_require":1500,"hammer_require":28,"product":__DIR__"products/weapon",
"maker_level":0,"fail_possibility":35,]),
(["name":"斧","type":"long","temperature":50,"heat_require":2500,"hammer_require":32,"product":__DIR__"products/weapon",
"maker_level":15,"fail_possibility":35,]),
(["name":"枪","type":"long","temperature":50,"heat_require":2000,"hammer_require":32,"product":__DIR__"products/weapon",
"maker_level":15,"fail_possibility":35,]),
(["name":"锤","type":"long","temperature":55,"heat_require":2800,"hammer_require":30,"product":__DIR__"products/weapon",
"maker_level":15,"fail_possibility":40,]),
(["name":"戟","type":"long","temperature":70,"heat_require":2800,"hammer_require":30,"product":__DIR__"products/weapon",
"maker_level":15,"fail_possibility":35,]),
(["name":"匕","type":"short","temperature":80,"heat_require":600,"hammer_require":15,"product":__DIR__"products/weapon",
"maker_level":20,"fail_possibility":75,]),
(["name":"盔","type":"short","temperature":70,"heat_require":4500,"hammer_require":55,"product":__DIR__"products/armor",
"maker_level":35,"fail_possibility":55,]),
(["name":"铠甲","type":"entire","temperature":65,"heat_require":10000,"hammer_require":75,"product":__DIR__"products/armor",
"maker_level":35,"fail_possibility":60]),
(["name":"盾","type":"entire","temperature":40,"heat_require":5500,"hammer_require":20,"product":__DIR__"products/armor",
"maker_level":35,"fail_possibility":35,]),
});
}

mapping *smith(object me)//返回可用所有打造东西
{
	mapping *products=all_products(),*myOwns;
	if (arrayp(myOwns=me->query("myCastings"))&&sizeof(myOwns)>0)
	for (int i=0;i<sizeof(myOwns);i++)
	products+=({myOwns[i]});
	if (mapp(me->query_temp("myTempCast")))
	products+=({me->query_temp("myTempCast")});
	return products;
}