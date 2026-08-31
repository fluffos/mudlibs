mapping _Descs = ([
	"First" : ({
		"The %^BOLD%^mountain pass%^RESET%^ is blanketed under a sheet of %^BOLD%^white%^RESET%^ snow.",
		"The %^BOLD%^mountain pass%^RESET%^ continues in just one direction.",
		"The %^BOLD%^mountain pass%^RESET%^ is covered in sporadic spots of weed and grass."
	}),
	"Rest" : ({
		"A gust of wind blows snow through the room.",
		"There are large stalagmites and boulders made from ice, spread throughout the land.",
		"The air is composed of a fresh mixture of %^BOLD%^cold%^RESET%^ and clean.",
		"Large %^BOLD%^snowflakes%^RESET%^ float around in the air.",
		"There is a steep cliff here, it would be a deadly fall.",
		"Burning torches line the sides of the mountain pass.",
		"Corpses of mountain dwarf scouts litter inaccessable areas near the pass.",
		"A %^BOLD%^steaming%^RESET%^ spot on the ground can be seen farther on the pass",
		"There are footprints visible moving in every direction, animal and humanoid alike.",
		"A slippery patch of ice threatens to trip any unexpecting travelers.",
		"The mountain can be seen more clearly as it gets closer.",
		"There are many rocks on the mountain pass, growing in quantity as the mountain draws nearer."
	})
]);


string desc_long() {
	string strRet;
	
    int rand1, rand2, rand3, rand4;
	
	rand1 = random(sizeof(_Descs["Rest"]));
	rand2 = rand1;
	rand3 = rand2;
	rand4 = rand3;
	
	while (rand2 == rand1 || rand2 == rand3 || rand2 == rand4) 
		rand2 = random(sizeof(_Descs["Rest"]));
	while (rand3 == rand1 || rand3 == rand2 || rand3 == rand4) 
		rand3 = random(sizeof(_Descs["Rest"]));
	while (rand4 == rand1 || rand4 == rand2 || rand4 == rand3) 
		rand4 = random(sizeof(_Descs["Rest"]));	
		
    strRet = _Descs["First"][random(sizeof(_Descs["First"]))] + " ";
	strRet += _Descs["Rest"][rand1] + " ";
	strRet += _Descs["Rest"][rand2] + " ";
	strRet += _Descs["Rest"][rand3] + " ";
	
	return strRet;
}
mapping desc_items() {
    mapping mRet;
    mRet = ([
        ({"snow"}) : "Snow is visible everywhere from the sky to the ground.",
        ({"snowflakes"}) : "Unique snowflakes float around in the air.",
        ({"torch"}) : "A thick wooden pole only 2 feet tall has a lit torch wrapped to it.  They are spread every few feet along the pass",
        ({"slipper patch of ice"}) : "If you hadn't seen it, you'd probably be on the ground.",
        ({"stalagmites"}) : "Stalagmites of pure ice have somehow formed over time.",
        ({"boulders"}) : "Large boulders of ice have somehow been formed over time.",
        ({"cliff", "steep cliff"}) : "Although the steep cliff can be seen, it is inaccessible.",
        ({"corpses"}) : "The corpses are torn apart, the work of a weapon and not an animal.",
        ({"steaming spot"}) : "Steam rises from the ground eerily.",
        ({"mountain"}) : "The mountain is huge, and appears to be completely snowless.",
        ({"rocks"}) : "Rocks that had fallen from the mountain litter the ground.",
        ]);
    return mRet;
}
