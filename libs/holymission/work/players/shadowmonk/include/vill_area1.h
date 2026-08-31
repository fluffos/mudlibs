void clone_villagers() {
    int a,b,c;

    c=random(4)+1;
    b=random(c);
    c-=b;
    switch(b+c) {
	case 1 :
	    if(!random(4)) a=1;
	    break;
	case 2 :
	    if(!random(3)) a=1;
	    break;
	case 3 :
	    if(!random(2)) a=1;
	    break;
	default :
	    a = 1;
	    break;
    }
    clone_list = ({ 
	 1, a, "guard", MONS+"guard", 0,
	 2, b, "child", MONS+"child_f", 0,
	 3, b+c, "child", MONS+"child_m", 0,
    });
}
