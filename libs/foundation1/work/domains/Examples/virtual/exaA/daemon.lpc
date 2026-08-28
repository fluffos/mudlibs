/*
// File     :  /domains/Examples/virtual/exaA/daemon.c
// Comment  :  This object works out what each .exaA looks like
// 94-05-13 :  Pallando @ Nightmare wrote it
*/
#define PREFIX "/domains/Examples/virtual/exaA/"
#define SUFFIX ".exaA"

mapping get_data( string arg )
{
    mapping data = ([]);

    data["items"] = ([]);
    data["short"] = "A corridor";
    data["prop"] = ([ "indoors" : 1, "light" : 1 ]);

    switch( arg )
    {
	case "one":
	    data["exits"] = ([
		"out" : "/domains/Examples/virtual/start",
                "north" : PREFIX "two" SUFFIX,
	    ]);
	    data["long"] = @EndText
To the north is a dark corridor.  It looks creepy.
EndText
	    ;break;
	case "two":
	    data["exits"] = ([
		"south" : PREFIX "one" SUFFIX,
		"north" : PREFIX "three" SUFFIX,
	    ]);
	    data["long"] = @EndText
You are in a dark corridor.  It continutes to the north but
south looks like it might be the way out.
EndText
	    ;break;
	case "three":
	    data["exits"] = ([
		"south" : PREFIX "two" SUFFIX,
		"north" : PREFIX "four" SUFFIX,
	    ]);
	    data["long"] = @EndText
You are in a dark corridor.  It continues to the north and south.
EndText
	    ;break;
	case "four":
	    data["exits"] = ([
		"south" : PREFIX "three" SUFFIX,
		"northeast" : PREFIX "five" SUFFIX,
	    ]);
	    data["long"] = @EndText
You are in a dark corridor.  It continues to the northeast and south.
EndText
	    ;break;
	case "five":
	    data["exits"] = ([
		"southwest" : PREFIX "four" SUFFIX,
		"east" : PREFIX "six" SUFFIX,
                "north" : PREFIX "seven" SUFFIX,
	    ]);
	    data["prop"]["light"] = 0;
	    data["long"] = @EndText
You are in a very dark corridor.  It continues to the southwest.
The way beyond is shrouded in darkness.
EndText
           ;break;
	default:
	    data["exits"] = ([]);
	    data["long"] = @EndText
Aaaaa
     aaaa
	 rrr
	   rr
	    gg
	      g
	       h
		h
		*
	      SPLAT

You have fallen into a deep, dark, dank hole.  You are trapped!
EndText
	;break;
    }

    return data;
}

/* EOF */
