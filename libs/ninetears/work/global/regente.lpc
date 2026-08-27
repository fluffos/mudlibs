inherit "/global/creator";

#define  O_TYPE "R"

 string query_gtitle() {
    string regencia;
    regencia = "/secure/regentes"->query_boo(name);
    if(query_female()) return "la Regente de"+regencia;
    else return "el Regente de"+regencia;
    }
	    
 string query_object_type() {
    return O_TYPE;
    }

int query_regente() { return 1; }