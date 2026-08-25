#include <mudlib.h>
#include <ansi.h>

#define H_SIZE 16
#define W_SIZE 20

private mapping amap;

void init_map();
void make_bulk(string type, int size, int style);
void make_map(string type, int city);

void init_map()
{
	int i, j;
	string kk;

	amap = ([ ]);
	for( i=0; i<H_SIZE; i++ ){
		for( j=0; j<W_SIZE; j++ ){
			kk = ""+i+"/"+j+"";
			amap[kk] = "";
		}
	}
}
mixed make_map(string type, int city)
{
	int i, j;
	string kk;
	mixed tmp;

	if( city!=0 ){
		i = to_int(H_SIZE/4)+random(1+H_SIZE/4)+1;
		j = to_int(W_SIZE/4)+random(1+W_SIZE/4)+1;
		amap[""+(i-1)+"/"+(j-1)+""] = "┌";
		amap[""+(i)+"/"+(j-1)+""]   = "│";
		amap[""+(i+1)+"/"+(j-1)+""] = "└";
		amap[""+(i-1)+"/"+(j)+""]   = "─"; 
		amap[""+(i)+"/"+(j)+""]     = "◎";
		amap[""+(i+1)+"/"+(j)+""]   = "─";
		amap[""+(i-1)+"/"+(j+1)+""] = "┐";
		amap[""+(i)+"/"+(j+1)+""]   = "│";
		amap[""+(i+1)+"/"+(j+1)+""] = "┘";
	}
	tmp = ({ });
	for( i=0; i<H_SIZE; i++ ){
		tmp+=({ "" });
		tmp[i]=({ });
		for( j=0; j<W_SIZE; j++ ){
			kk = ""+i+"/"+j+"";
			if( stringp(amap[kk])&&amap[kk]!="" )
				tmp[i]+=({ amap[kk] });
			else
				tmp[i]+=({ type });
		};
	};
	return tmp;
}
mixed main(mapping *info, string main, int city)
{
        init_map();
	if( !info||!arrayp(info)||!sizeof(info) ) info = ({ });
	foreach(mapping m in info) {
		if( !m["type"]||!stringp(m["type"]) ) m["type"] = "．";
		if( !m["size"]||!intp(m["size"])    ) m["size"] = 20;
		if( !m["shape"]||!intp(m["shape"])  ) m["shape"]= 3;
		make_bulk(m["type"], m["size"], m["shape"]);
	}
	if( !main||main==""||!stringp(main) ) main = "．";
	if( !city||!intp(city) ) city = 0;

        return make_map(main, city);
}
void make_bulk(string type, int size, int style)
{
	int i, j, y, x, *t1, *t2;
	string *tt, *pp, *nn, *total;

	i = random(H_SIZE);
	j = random(W_SIZE);
	nn = ({ i+"/"+j });
	total = ({ });

	while( sizeof(nn)>0&&sizeof(total)<size ){
		pp = nn;
		nn = ({ });
		foreach(string ss in pp){
			tt = explode(ss, "/");
			if( sizeof(tt)!=2 )continue;
			y = to_int(tt[0]);
			x = to_int(tt[1]);
			tt = ({ });

			if( y>i ) t1 = ({y, y+1 });
			else if( y<i) t1 = ({y-1, y});
			else t1 = ({y-1,y,y+1});
			if( x>j ) t2 = ({x, x+1});
			else if( x<j ) t2 = ({x-1,x});
			else t2 = ({x-1,x,x+1});

			t1 = filter_array(t1, (: $1>=0&&$1<H_SIZE:));
                        t2 = filter_array(t2, (: $1>=0&&$1<W_SIZE:));

			foreach(y in t1){
				foreach(x in t2) tt+=({ y+"/"+x });
			};
			if( style<0 )tt = filter_array(tt , (: !random(3) : ));
			else if( style==0) tt = filter_array(tt , (: !random(2) : ));
			else if( style<5 ) tt = filter_array(tt , (: random(3) : ));
			else if( style<10 ) tt = filter_array(tt , (: random(5) : ));
			else tt = filter_array(tt , (: random(7) : ));
			foreach(ss in tt){
				if( stringp(amap[ss])&&amap[ss]!="" )
					tt-=({ ss });
				else amap[ss] = type;
			}

			nn+=tt;
			total+=tt;
		}
	}
}
