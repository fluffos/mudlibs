// NOTE: this file is needed for any of these rooms to work!
// Nightshade.

string do_descript() {
    int x, max;
    string ret;
    int *flag;

    flag = ({0,0,0,0,0,0,0,0,0,0});
    max = 3;

    ret = "The sewers of Tirun snake beneath the city in dizzying patterns.  ";

    for(int i=0;i < max;i++) {
        x = random(100);
        if((x < 10) && (flag[0] == 0)) {
            ret += "This place looks unsettlingly familiar.  ";
            flag[0] = 1;
            }
        else if((x < 20) && (flag[1] == 0)) {
            ret += "A lump of %^GREEN%^slime%^RESET%^ slowly slides down the wall.  ";
            flag[1] = 1;
            }
        else if((x < 30) && (flag[2] == 0)) {
            ret += "A few drops of water from above land in the muck.  ";
            flag[2] = 1;
            }
        else if((x < 40) && (flag[3] == 0)) {
            ret += "The stone walls of the tunnel seem old and in disrepair.  ";
            flag[3] = 1;
            }
        else if((x < 50) && (flag[4] == 0)) {
            ret += "Junk litters the sewer from people carelessly leaving things on the road.  ";
            flag[4] = 1;
            }
        else if((x < 60) && (flag[5] == 0)) {
            ret += "The air here in the sewer is stifling.  ";
            flag[5] = 1;
            }
        else if((x < 70) && (flag[6] == 0)) {
            ret += "A rat skitters across the ground and scurries into a small hole in the wall.  ";
            flag[6] = 1;
            }
        else if((x < 80) && (flag[7] == 0)) {
            ret += "The muck underfoot makes sucking sounds as it is walked through.  ";
            flag[7] = 1;
            }
        else if((x < 90) && (flag[8] == 0)) {
            ret += "An old rusty grating sits in a corner, nearly fallen to pieces.  ";
            flag[8] = 1;
            }
        else if((x < 100) && (flag[9] == 0)) {
            ret += "A strange liquid splashes down from above as someone tosses out their dirty water.  ";
            flag[9] = 1;
            }
    }
    return ret;
}
