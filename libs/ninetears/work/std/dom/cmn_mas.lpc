inherit "/std/room";

string dom_name;

int do_list(string);
int add_creator(string);
int delete_creator(string);
int add_project(string);

void init() {
   	::init();
   	add_action("do_list", "listar");
   	add_action("add_creator", "anyadir");
   	add_action("delete_creator", "eliminar");
   	add_action("set_project", "proyecto");
	}

string query_dom() { return dom_name; }
void set_dom(string str) { dom_name = str; }

int do_list(string arg) {
	string *members, *domains, mem_list;
	mixed mast;
	int i, j;

	if(arg == "todos") domains = get_dir("/d/");
	else if(!arg) domains = ({ dom_name });
	else return notify_fail("Uso: listar\n     listar todos\n");

   	if(sizeof(domains) > 1) write("Todos los Dominios:\n");
   	else write("Este Dominio:\n");
   	for(i=0; i<sizeof(domains); i++) {
      		mast = "/d/" + domains[i] + "/master";
      		members = (string *)mast->query_members(arg);
      		printf("%8s tiene %2d miembros y pertenece a %s.\n", domains[i],sizeof((string *)mast->query_members()), capitalize((string)mast->query_dom_lord()));
      		mem_list = "";
      		for(j=0; j<sizeof(members); j++) mem_list+=capitalize(members[j])+(j==sizeof(members)-1?".":",");
      		write(mem_list + "\n\n");
   		}
   	return 1;
	}

int add_creator(string arg) {
   	mixed mast;

   	if(!arg) return notify_fail("Uso: anyadir <creador>\n");

	arg = (string)this_player()->expand_nickname(arg);
   	mast = "/d/" + dom_name + "/master";
   	if((string)mast->query_dom_lord() != geteuid(this_player())) return notify_fail("No eres el Thane de este Dominio.\n");
	if(!mast->add_member(arg)) return notify_fail("No se pudo anyadir a "+capitalize(arg)+" a la lista de miembros de "+dom_name + ".\n");

      	write("Creador "+capitalize(arg)+" anyadido a "+dom_name+".\n");
   	return 1;
	}

int delete_creator(string arg) {
   	mixed mast;

   	if(!arg) return notify_fail("Uso: eliminar <creador>\n");

   	arg = (string)this_player()->expand_nickname(arg);
   	mast = "d/"+dom_name+"/master";
   	if((string)mast->query_dom_lord() != geteuid(this_player())) return notify_fail("No eres el Thane de este Dominio.\n");
	if(!mast->remove_member(arg)) return notify_fail("No se pudo eliminar a "+capitalize(arg)+" de la lista de miembros de "+dom_name + ".\n");

   	write("Miembro "+capitalize(arg)+" borrado de "+dom_name+".\n");
   	return 1;
	}

int set_project(string arg) {
   	mixed mast;
   	string proj;
   	if(!arg || sscanf(arg,"%s %s", arg, proj) != 2) return notify_fail("Uso: proyecto <creador> <proyecto>\n");

   	arg = (string)this_player()->expand_nickname(arg);
   	mast = "d/"+dom_name+"/master";
   	if((string)mast->query_dom_lord() != geteuid(this_player())) return notify_fail("No eres el Thane de este Dominio.\n");
	if(!mast->set_project(arg, proj)) return notify_fail("Error al establecer el proyecto de "+capitalize(arg)+" en "+dom_name+".\n");

	write("Proyecto de "+capitalize(arg)+" establecido en "+dom_name+".\n");
   	return 1;
	}

varargs void add_cartel(string cartel) {
	if(!cartel) cartel="cartel";
	add_sign("Un "+cartel+" con algo escrito.\n",TO->query_short()+"\nLos comandos que puedes usar son:\n\n<%^GREEN%^listar%^RESET%^> para ver informacion sobre el dominio.\n<%^GREEN%^anyadir \"creador\"%^RESET%^> para anyadir un creador al dominio.\n<%^GREEN%^eliminar \"creador\"%^RESET%^> para borrar un creador del dominio.\n<%^GREEN%^proyecto \"creador\" \"proyecto\"%^RESET%^> para decir a que se dedica un creador del dominio.\n",cartel,cartel);
	}