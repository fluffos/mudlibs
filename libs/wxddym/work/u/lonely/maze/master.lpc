mixed compile_object(string file)
{
        mixed ob;
        if(file[0..1]=="/f") {
                log_file("fb2","master:try to load file "+file+"\n");
                ob =  "/adm/daemons/fuben_d"->query_fuben_ob(file);
                log_file("fb2","master:try to load file "+file+" finish\n");
                if(objectp(ob))
                        ob->setup();
                return ob;
        } else
                return 0;
} 
