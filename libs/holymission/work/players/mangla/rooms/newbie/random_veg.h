#define FOOD\
   ({"grass","lettuce","carrot","cucumber","radish","raddicchio",\
     "melon","pumpkin","dandelion","cloverleaf"})
//   ({"grass","carrot","cucumber","radish","raddicchio",\
//     "melon","pumpkin","squash","beans"})

string rndveg() {

    string fail,*farray;
    object obj;
    int    i;

    farray = FOOD;
    i=random(sizeof(farray))+1;
//    if ((i=random(sizeof(farray)+1)==sizeof(farray)) ||
    if (i == sizeof(farray) ||
        ((obj=clone_object(OBJS+farray[i]))==0))
          return "nothing";

//    i++;
    MOVE(obj,ENV(TP));
    return farray[i];
}


int DUG,DONE;

int _search(string arg) {

    if (!arg && (arg != "garden")) return 0;

    if (DUG && !DONE) {
        printf("You bend down and rummage through the loose garden soil until you find\n");
        printf("\t%s\n",rndveg());
    }
    else {
        printf("This area has already been searched.\n");
        if (DUG < 5) DUG++;
        else {
            DONE = 1;
        }
    }
    DUG--;
    return 1;
}

