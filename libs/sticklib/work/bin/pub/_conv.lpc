// Universal converter :)
// Haw 180397

// 220397 added float type input

#define CONV_TAB ({\
	({ ({25.4, 12.0, 3.0, 1760.0}), ({1.0, 10.0, 100.0, 1000.0}) }),\
	({ ({28.35, 16.0}), ({1.0, 1000.0}) })\
	})
#define CONV_IDX ([\
	"in":({0,0,0}), "ft":({0,0,1}), "yd":({0,0,2}), "mi":({0,0,3}),\
	"mm":({0,1,0}), "cm":({0,1,1}), "m":({0,1,2}), "km":({0,1,3}),\
	"oz":({1,0,0}), "lb":({1,0,1}), "g":({1,1,0}), "kg":({1,1,1}),\
	"f":({-1}), "c":({-1}),\
	])

status
conv_cmd(string s)
{
    string num, from, to;
    int i, idx;
    float x;

    if(!s || sscanf(s, "%s %s %s", num, from, to) != 3)
	return notify_fail("Usage: conv <int_or_float> <from_unit> <to_unit>\n"),0;
    if(from == to) return notify_fail("What's the use?\n"),0;
    if(!CONV_IDX[from] || !CONV_IDX[to] || (idx = CONV_IDX[from][0]) != CONV_IDX[to][0])
	return notify_fail("Illegal units.\n"),0;

    x = to_float(num);

    if(idx == -1) { // temperature conversion
	if(to == "f") x = (x * 9.0 / 5.0) + 32.0;
	else x = (x - 32.0) * 5.0 / 9.0;
    } else {
	i = CONV_IDX[from][2];
	while(i) {
	    x = x * CONV_TAB[CONV_IDX[from][0]][CONV_IDX[from][1]][i];
	    i--;
	}
	if(CONV_IDX[to][1] != CONV_IDX[from][1]) {
	    x = x * CONV_TAB[CONV_IDX[from][0]][CONV_IDX[from][1]][0];
	    x = x / CONV_TAB[CONV_IDX[to][0]][CONV_IDX[to][1]][0];
	}
	i = CONV_IDX[to][2];
	while(i) {
	    x = x / CONV_TAB[CONV_IDX[to][0]][CONV_IDX[to][1]][i];
	    i--;
	}
    }

    this_player()->tell_me("Converted value: "+ x +" "+ to + ".");
    return 1;
}
