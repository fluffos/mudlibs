   if (sscanf(str, "%s says 'attack %s'", master, kohde) == (2)) {
       if (!present(aijys,environment(elain))) { return; }
       if (master != aijys->query_name()) { return; }
       ahaa = present(lower_case(kohde),environment(elain)); 
       puuh = present(lower_case(kohde),environment(aijys)); 
       if (!ahaa) { return; }
       tell_room(environment(aijys), elain->short()+
            " is ordered to attack "+ahaa->query_name()+"\n");
       elain->attack_object(ahaa);
       return 1;

