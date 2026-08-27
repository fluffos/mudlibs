// This is the virtual server of *.mob.c in /d/std/mob
// By Ruby@Eastern.Stories 12/26 , 1994

#include <daemons.h>
#include <mudlib.h>

#define MOB_FILE "/d/std/monster/monster.body"
#define TEMPLATE MONSTER

inherit REF_D;

mapping mobs;

void create()
{
	int i, j;
	string *f, str, str2, mob;

	seteuid(getuid());
	mobs = ([]);
	f = explode( read_file(MOB_FILE), "\n" );
	mob = "";
	for(i=0; i<sizeof(f); ++i) {
		if( !f[i] || f[i]=="" || f[i][0]=='#' ) continue;
		if( sscanf(f[i], "%s %s", str, str2)!= 2)
			str = f[i];
		while( (i+1)<sizeof(f) && (f[i+1][0]==' ' || f[i+1][0]=='>' ) )
			str2 += (f[i+1][0]=='>'?"\n":"") + extract( f[++i], 1 );
		switch(str)
		{
			case "mob:":
				mob = str2;
				mobs += ([ mob:([]) ]);
				break;
			default :
				if ( mob ) 
					mobs[mob][str] = str2 ;
				break ;
		}
	}
}

// This function is called when the driver try to compile an object of
// the name *.mob.c
object compile_object(string s)
{
	object obj;
	string *fname, index, *d,type,tmp;
	int i,j;

	seteuid(getuid(this_object()));
	fname = explode(s, "/");
	index = fname[sizeof(fname)-1];
	d = keys(mobs[index]);
	if ( ! d ) 
		error("File not exist: "+s+"\n");
	obj = new(TEMPLATE);
	for( i=0; i<sizeof(d); ++i ) {
		sscanf(mobs[index][d[i]],"%s %s",type,tmp);
		switch (type) {
			case "I" : 
				sscanf(tmp,"%d",j);
				obj->set(d[i],j);
				break;
//			case "ID" :
//				obj->add("id",(mixed)tmp);
//				break;
			case "SET" :
				obj->sprintf("%s",tmp);
				break;
			default :
				obj->set( d[i],mobs[index][d[i]]);
				break;
		}
	}
	return obj;
}

